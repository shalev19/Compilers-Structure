%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printTok(int token, FILE* yyout2);
char* changeEnding(char* filename,char* newend);
int sleTypeCheck(const char* str);
int checkNumType(const char* str);

int countLine = 0;
typedef enum{START=1, DO, ELSE, IF, ENDI, INT,PUT, PROG, 
            GET, REAL, THEN, VAR, LOOP ,ENDL, UNTIL, ENDP,
			ID, NUM, RELOP, LOGOP, ADDOP, MULOP, ASSIGNOP,
            LETTER, DIGIT, DOT, SEMICOL, COL, COMMA, LBAR, RBAR} tok; 

%}
LETTER          [a-zA-Z]
DIGIT           [0-9]
ID              [{LETTER}][{LETTER}|{DIGIT}]*
NUM             [{DIGIT}]+|[{DIGIT}]*("."[{DIGIT}]+)
LINE 			\n
%x comment
%%

"/*"		                BEGIN comment;
<comment>"*/"	            BEGIN INITIAL;
<comment>.|\n	            ;
start                       {ECHO;return START;}
do                          {ECHO;return DO;}
else                        {ECHO;return ELSE;}
if                          {ECHO;return IF;}
endi                        {ECHO;return ENDI;}
int                         {ECHO;return INT;}
put                         {ECHO;return PUT;}
prog                        {ECHO;return PROG;}
get                         {ECHO;return GET;}
real                        {ECHO;return REAL;}
then                        {ECHO;return THEN;}
var                         {ECHO;return VAR;}
loop                        {ECHO;return LOOP;}
endl                        {ECHO;return ENDL;}
until                       {ECHO;return UNTIL;}
endp                        {ECHO;return ENDP;}
"<"|">"|"<>"|"="            {ECHO;return RELOP;}
"&"|"~"|"!"                 {ECHO;return LOGOP;}
"+"|"-"                     {ECHO;return ADDOP;}
"*"|"/"|"mod"               {ECHO;return MULOP;}
"<="                        {ECHO;return ASSIGNOP;}
{LETTER}                    {ECHO;return LETTER;}
{DIGIT}                     {ECHO;return DIGIT;}
{ID}                        {ECHO;return ID;}
{NUM}                       {ECHO;return NUM;}
"."                         {ECHO;return DOT;}
";"                         {ECHO;return SEMICOL;}
":"		                    {ECHO;return COL;}
","                         {ECHO;return COMMA;}
"("                         {ECHO;return LBAR;}
")"                         {ECHO;return RBAR;}
{LINE}						{ ECHO;fprintf(yyout,"%d ",++countLine);}
" "|\t						{ECHO;}
.							{fprintf(yyout,"Error: %s not defined\n",yytext);}

%%

int main(int argc, char** argv)
{
  int token;
  FILE* yyout2;
    if(argc < 2){
      fprintf(stderr, "%s", "No file received!\n");
      exit(0);
    }

    if(sleTypeCheck(argv[1])){
        yyin = fopen(argv[1],"r");
        if(yyin == NULL){
          fprintf(stderr, "%s", "File open failed!\n");
          exit(1);
        }
        yyout = fopen(changeEnding(argv[1],"lst"),"w");
		fprintf(yyout,"%d ",++countLine);
        yyout2 = fopen(changeEnding(argv[1], "tok"),"w");
    }
    else{
      fprintf(stderr, "%s", "The file type needs to be .sle!\n");
      exit(2);
    }

    while( token = yylex()){
      printTok(token, yyout2);
    }
  return 0;
}

void printTok(int token, FILE* yyout2) 
{
  switch(token)
  {
  case START:
		fprintf(yyout2,"%s\t\tSTART\n",yytext);
		break;
  case DO:
		fprintf(yyout2,"%s\t\tDO\n",yytext);
		break;
	case ELSE:
		fprintf(yyout2,"%s\t\tELSE\n",yytext);
		break;
	case IF:
		fprintf(yyout2,"%s\t\tIF\n",yytext);
		break;
	case ENDI:
		fprintf(yyout2,"%s\t\tENDI\n",yytext);
		break;
	case INT:
		fprintf(yyout2,"%s\t\tINT\n",yytext);
		break;
  	case PUT:
		fprintf(yyout2,"%s\t\tPUT\n",yytext);
		break;
	case PROG:
		fprintf(yyout2,"%s\t\tPROG\n",yytext);
		break;
  	case GET:
		fprintf(yyout2,"%s\t\tGET\n",yytext);
		break;
  	case REAL:
		fprintf(yyout2,"%s\t\tREAL\n",yytext);
		break;
	case THEN:
		fprintf(yyout2,"%s\t\tTHEN\n",yytext);
		break;
	case VAR:
		fprintf(yyout2,"%s\t\tVAR\n",yytext);
		break;
	case LOOP:
		fprintf(yyout2,"%s\t\tLOOP\n",yytext);
		break;
	case ENDL:
		fprintf(yyout2,"%s\t\tENDL\n",yytext);
		break;
  	case UNTIL:
		fprintf(yyout2,"%s\t\tUNTIL\n",yytext);
		break;
	case ENDP:
		fprintf(yyout2,"%s\t\tENDP\n",yytext);
		break;
	case ID:
		fprintf(yyout2,"%s\t\tID\n",yytext);
		break;
  	case NUM:
		fprintf(yyout2,"%s\t\tNUM\t\ttype=%s\n",yytext, checkNumType(yytext)==0? "INTEGER":"FLOAT");
		break;
  	case RELOP:
		if(!strcmp(yytext,">")){
			fprintf(yyout2,"%s\t\tRELOP\t\tGT\n",yytext);
		}
		else if(!strcmp(yytext,"<")){
			fprintf(yyout2,"%s\t\tRELOP\t\tLT\n",yytext);
		}
		else if(!strcmp(yytext,"<>")){
			fprintf(yyout2,"%s\t\tRELOP\t\tNE\n",yytext);
		}
		else if(!strcmp(yytext,"=")){
			fprintf(yyout2,"%s\t\tRELOP\t\EQ\n",yytext);
		}
		break;
	case LOGOP:
		if(!strcmp(yytext,"&")){
			fprintf(yyout2,"%s\t\tRELOP\t\tAND\n",yytext);
		}
		else if(!strcmp(yytext,"~")){
			fprintf(yyout2,"%s\t\tRELOP\t\tOR\n",yytext);
		}
		else if(!strcmp(yytext,"!")){
			fprintf(yyout2,"%s\t\tRELOP\t\tNOT\n",yytext);
		}
		break;
	case ADDOP:
		if(!strcmp(yytext,"+")){
			fprintf(yyout2,"%s\t\tRELOP\t\tADD\n",yytext);
		}
		else if(!strcmp(yytext,"-")){
			fprintf(yyout2,"%s\t\tRELOP\t\tSUB\n",yytext);
		}
		break;
	case MULOP:
		if(!strcmp(yytext,"*")){
			fprintf(yyout2,"%s\t\tRELOP\t\tMUL\n",yytext);
		}
		else if(!strcmp(yytext,"/")){
			fprintf(yyout2,"%s\t\tRELOP\t\tDEV\n",yytext);
		}
		else if(!strcmp(yytext,"mod")){
			fprintf(yyout2,"%s\t\tRELOP\t\tMOD\n",yytext);
		}
		break;
	case ASSIGNOP:
		fprintf(yyout2,"%s\t\tASSIGNOP\n",yytext);
		break;
  	case LETTER:
		fprintf(yyout2,"%s\t\tLETTER\n",yytext);
		break;
	case DIGIT:
		fprintf(yyout2,"%s\t\tDIGIT\n",yytext);
		break;
	case DOT:
		fprintf(yyout2,"%s\t\tDOT\n",yytext);
		break;
	case SEMICOL:
		fprintf(yyout2,"%s\t\tSEMICOL\n",yytext);
		break;
	case COL:
		fprintf(yyout2,"%s\t\tCOLON\n",yytext);
		break;
  	case COMMA:
		fprintf(yyout2,"%s\t\tCOMMA\n",yytext);
		break;
	case LBAR:
		fprintf(yyout2,"%s\t\tLBAR\n",yytext);
		break;
	case RBAR:
		fprintf(yyout2,"%s\t\tRBAR\n",yytext);
		break;
	
  }

}

/*Change the ending to new ending */
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

/*check if the ending of the file is ".sle*/
int sleTypeCheck(const char* str)
{
    char *dot = strrchr(str, '.');
    return strlen(str)>4 && !strcmp(dot,".sle")||!strcmp(dot,".SLE");
}

/*Check if the number is Float or Integer*/
int checkNumType(const char* str)
{
	char *dot = strrchr(str, '.');
    return dot!=NULL? 1:0;
}

int yywrap()
{
	return 1;
}
