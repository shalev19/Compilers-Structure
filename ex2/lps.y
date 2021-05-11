%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>


FILE *stx;
int sleTypeCheck(const char* str);
char* changeEnding(char* filename,char* newend);
int yyparse(),line,column,yyleng;
char * yytext;
FILE *yyin,*yyout,*stx;
const char * src;
void yyerror(const char* err);
int yylex();
%}


%token START DO ELSE IF ENDI INT PUT PROG GET
%token REAL THEN VAR LOOP ENDL UNTIL ENDP DOT
%token SEMICOLON COLON COMMA RPAR LPAR ID NUM
%token RELOP LOGOP ADDOP MULOP ASSIGNOP

%start Program

%%
Program: PROG ID SEMICOLON Declarations START StmtList ENDP DOT		{fprintf(stx,"Program: PROG ID SEMICOLON Declarations START StmtList ENDP DOT\n"); return 0;}
		|error 														{return 0;}
;
Declarations: VAR DecList SEMICOLON	 								{fprintf(stx,"Declarations: VAR DecList SEMICOLON\n");}
		|error														{return 0;}
;
DecList: DecList COMMA ID COLON Type								{fprintf(stx,"DecList: DecList COMMA ID COLON Type\n");}
		|ID COLON Type												{fprintf(stx,"DecList: ID COLON Type\n");}
		|error														{return 0;}
;
Type: INT 							        						{fprintf(stx,"Type: INT\n");}
	|REAL							        						{fprintf(stx,"Type: REAL\n");}
	|error							        						{return 0;}
;
StmtList: StmtList Statment SEMICOLON 								{fprintf(stx,"StmtList: StmtList Statment SEMICOLON\n");}
		| 															{fprintf(stx,"StmtList: \'epsilon\'\n");}
;
Statment: ID ASSIGNOP Expression									{fprintf(stx,"Statment: ID ASSIGNOP Expression\n");}
		|PUT Expression												{fprintf(stx,"Statment: PUT Expression\n");}
		|GET ID														{fprintf(stx,"Statment: GET ID\n");}
		|IF BoolExp THEN StmtList ELSE StmtList ENDI				{fprintf(stx,"Statment: IF BoolExp THEN StmtList ELSE StmtList ENDI\n");}
		|IF BoolExp THEN StmtList ENDI								{fprintf(stx,"Statment: IF BoolExp THEN StmtList ENDI\n");}
		|LOOP BoolExp DO StmtList ENDL								{fprintf(stx,"Statment: LOOP BoolExp DO StmtList ENDL\n");}
		|DO StmtList UNTIL BoolExp ENDL								{fprintf(stx,"Statment: DO StmtList UNTIL BoolExp ENDL\n");}
		|error														{return 0;}
;
BoolExp: Expression Case Expression									{fprintf(stx,"BoolExp: Expression Case Expression\n");}
;
Case: RELOP 														{fprintf(stx,"Case: RELOP\n");}
	|LOGOP															{fprintf(stx,"Case: LOGOP\n");}
	|error 							        						{return 0;}
;
Expression: Expression ADDOP Term 									{fprintf(stx,"Expression: Expression ADDOP Term\n");}
	|Term															{fprintf(stx,"Expression: Term\n");}
;
Term: Term MULOP Factor												{fprintf(stx,"Term: Term MULOP Factor\n");}
	|Factor															{fprintf(stx,"Term: Factor\n");}
;
Factor: ID 															{fprintf(stx,"Factor: ID\n");}
	|NUM 															{fprintf(stx,"Factor: NUM\n");}
	|LPAR Expression RPAR											{fprintf(stx,"Factor: LPAR Expression RPAR\n");}
	|error 															{return 0;}
;
%%

int main(int argc, char** argv){
	src = argv[1];
	char lstFile[20] = "";
	char stxFile[20] = "";
	int result;

	if(argc >= 2){
		if(strchr(argv[1],'.') != NULL){
			char * ext = strchr(argv[1],'.')+1;
			if(!sleTypeCheck(ext))
			{
				perror("The file type needs to be .sle!\n");
				exit(1);
			}
		}
		else {
			perror("File must be of type '.sle' or '.SLE'\n");
			exit(1);
		}

		if((yyin = fopen(argv[1],"r")) == NULL){
			perror("Error openning file!");
			exit(1);
		}
		strcat(lstFile,changeEnding(argv[1],".lst"));
		strcat(stxFile,changeEnding(argv[1],".stx"));
		if(!(yyout = fopen(lstFile,"w")) || !(stx = fopen(stxFile, "w"))){
			perror("File was not open");
		}
		if(yyparse()){
			fprintf(stdout,"parse was not successful\n",line);
		}else{
			fprintf(stdout,"parse was successful\n");
		}
		fclose(stx);
		fclose(yyin);
		fclose(yyout);
	}else{
		perror("arguments not valid");
	}
	return 0;
}

void printError(const char * fmt, ...){
	va_list arglist;
	va_start( arglist, fmt );
	vfprintf(yyout,fmt,arglist);
	vfprintf(stdout,fmt,arglist);
}

void yyerror(const char * err){
	fprintf(yyout,"\n%s.sle:%d:%d:parser error: unexpected token %s \n",src,line,column-yyleng,yytext);
	fprintf(stdout,"\n%s.sle:%d:%d:parser error: unexpected token %s \n",src,line,column-yyleng,yytext);
	exit(1);
}

int sleTypeCheck(const char* str){
    return !strcmp(str,"sle")||!strcmp(str,"SLE");
}

char* changeEnding(char* filename,char* newend)
{
 int i;
  int length = strlen(filename);
  char* str = strdup(filename);
  int newendLength = strlen(newend);
  for(i = 0; i < strlen(newend); i++){
	  str[length + i - newendLength] = newend[i];
  }

  return str;
}