%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>

typedef enum { FALSE,TRUE} bool;
typedef enum {INTEGER ,FLOAT ,PROGNAME ,ERROR} Type;
typedef struct {
  int intNum;
  float floatNum;
  Type type;	
} number;

extern int yylex();
extern int yyparse(),line,yyleng;
extern char * yytext;
extern FILE *yyin,*yyout;
extern const char * src;
extern void yyerror(const char* err);
extern void insertSymbol(const char* id, number insert_num);
extern void insertAssignOp(const char* id, number insert_num);
extern int searchInUndefined(const char* id);
extern void insertUndefinedSymbol(const char* id);	
extern void printNumber(number print_num);
extern number searchSymbol(const char* id);
extern int booleanExpration(number left_num, char sign, number right_num);
extern number addOperator(number left_num, char sign, number right_num);
extern number mulOperator(number left_num, char sign, number right_num);

%}


%union {
 number num;
 char id[16];
 char opr;
 bool boolean;
}

%token <id> ID
%token <num> NUM
%left <opr> ADDOP MULOP RELOP LOGOP ASSIGNOP
%type <num> Type
%type <num> Expression
%type <num> Term
%type <num> Factor
%type <opr> Case
%type <boolean> BoolExp

%token START DO ELSE IF ENDI INT PUT PROG GET
%token REAL THEN VAR LOOP ENDL UNTIL ENDP DOT
%token SEMICOLON COLON COMMA RPAR LPAR  
%start Program

%%

Program: PROG ID SEMICOLON Declarations START StmtList ENDP DOT		{number prog; prog.type = PROGNAME; insertSymbol($2, prog);}
		| PROG ID SEMICOLON Declarations START StmtList ENDP error 	{fprintf(stderr,"missing '.' at the end of program.");}
      	| PROG ID SEMICOLON Declarations START StmtList error  		{fprintf(stderr,"missing 'endp' at end of program.");}
      	| PROG ID SEMICOLON Declarations error 						{fprintf(stderr,"undefined reference to 'start'.");}
      	| PROG ID error 											{fprintf(stderr,"missing semi colon after program name.");}
      	| PROG error 												{fprintf(stderr,"programe name is ilegal.");}
      	| error 													{fprintf(stderr,"program always start with 'prog'.");}
;
Declarations: VAR DecList SEMICOLON	 								
		|VAR DecList error											{yyerror("missing semi colon after program name.");}
		|error														{yyerror("expected var decleration.");}
;
DecList: DecList COMMA ID COLON Type								{insertSymbol($3, $5);}
		|DecList COMMA ID error										{yyerror("missing ':' after variable name.");}
		|DecList COMMA error										{yyerror("after ',' need to come variable name.");}
		|DecList error												{yyerror("expected ',' after decleration.");}
		|ID COLON Type												{insertSymbol($1, $3);}
		|ID error 													{yyerror("after variable needs to come ','.");}
    	|error 														{yyerror("after 'var' nneds to come variable.");}
;
Type: INT 															{$$.type = INTEGER;}
	|REAL															{$$.type = FLOAT;}
	|error															{yyerror("ilegal type");}
;
StmtList: StmtList Statment SEMICOLON 								{}
	|StmtList Statment error										{yyerror("after statment needs to come ';'.");}
	| 																{}
;
Statment: ID ASSIGNOP Expression									{insertAssignOp($1, $3);}
	|ID error 														{yyerror("after variable needs to come '<='.");}
	|PUT Expression													{printNumber($2);}
	|GET ID															{}
	|GET error														{yyerror("after 'GET' needs to come variable.");}
	|IF BoolExp THEN StmtList ELSE StmtList ENDI					{}
	|IF BoolExp THEN StmtList ELSE StmtList error					{yyerror("after statment needs to come 'ENDI'.");}
	|IF BoolExp THEN StmtList ENDI									{}
	|IF BoolExp THEN StmtList error									{yyerror("after if statment needs to come 'ENDI' or 'ELSE'.");}
	|IF BoolExp error												{yyerror("after boolean expration needs to come 'THEN'.");}
	|LOOP BoolExp DO StmtList ENDL									{}
	|LOOP BoolExp DO StmtList error									{yyerror("after statment needs to come 'ENDI'.");}
	|LOOP BoolExp error												{yyerror("after the LOOP needs to come 'DO'.");}
	|DO StmtList UNTIL BoolExp ENDL									{}
	|DO StmtList UNTIL BoolExp error								{yyerror("after 'DO UNTIL' needs to come 'ENDL'.");}
	|DO StmtList error												{yyerror("after 'DO' needs to come 'UNTILE'.");}
	|error															{yyerror("undifinded statment");}
;
BoolExp: Expression Case Expression									{$$ = booleanExpration($1, $2, $3);}
;
Case: RELOP 														{$$=$1;}
	|LOGOP															{$$=$1;}
;
Expression: Expression ADDOP Term 									{$$ = addOperator($1, $2, $3);}
	|Expression error												{yyerror("expected 'ADDOP' opearation");}
	|Term															{$$=$1;}
;
Term: Term MULOP Factor												{$$ = mulOperator($1, $2, $3);}
	|Term error														{yyerror("expected 'MUL' operation after 'Term'.");}
	|Factor															{$$ = $1;}
;
Factor: ID 															{$$ = searchSymbol($1);}
	|NUM 															{$$ = $1;}
	|LPAR Expression RPAR											{$$ = $2;}
	|LPAR Expression error											{yyerror("missing ')'.");}
	|error 															{yyerror("expected an ID or number.");}
;

%%

void yyerror(const char * err){
	fprintf(stderr,"\n%s.sle:%d::parser error: unexpected token %s \n",src,line,yytext);
}

