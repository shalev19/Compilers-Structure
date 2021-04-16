%{
#include <stdio.h>
#include <stdlib.h>

void printTok(int token);
typedef enum{OP=1, SEP, NUMBER, ID, WS, RES} tok; 
 
%}

NUM		[1-9][0-9]*
ID    		[a-zA-Z]+
WS		[ \t]+
%x comment
%%

"/*"		BEGIN comment;
<comment>"*/"	BEGIN INITIAL;
<comment>.|\n	;
while		return RES;
if		return RES;
else		return RES;
print		return RES;
int 		return RES;
{NUM}		return NUMBER;
{ID}		return ID;
{WS}		return WS;
">"|"<"|">="|"<="|"!="|"=="|"*"|"/"|"+"|"-"	return OP ;
","|";"|"."|"("|")"|"{"|"}"			return SEP;

\n        	;
.		{printf("find Error"); return 0;}

%%

int main(int argc, char** argv)
{
  int token;
  if(argc > 1)
	yyin = fopen(argv[1],"r");
  if(argc > 2)
	yyout = fopen(argv[2],"w");
  while( token = yylex())
	printTok(token);
  return 0;
}

void printTok(int token)
{
  switch(token)
  {
	case ID:
		fprintf(yyout,"find token ID with lexeme %s\n",yytext);
		break;
    	case NUMBER:
		fprintf(yyout,"find token NUMBER with lexeme %s\n",yytext);
		break;
	case WS:
		fprintf(yyout,"find token WS\n");
		break;
	case OP:
		fprintf(yyout,"find token OP with lexeme %s\n",yytext);
		break;
	case SEP:
		fprintf(yyout,"find token SEP with lexeme %s\n",yytext);
		break;
	case RES:
		fprintf(yyout,"find token RES with lexeme %s\n",yytext);
		break;
	}
}

int yywrap()
{
	return 1;
}