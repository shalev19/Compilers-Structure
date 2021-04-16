%{
#include <stdio.h>
#include <stdlib.h>

 int countC = 0, countWord = 0, countLine = 0, countNum = 0;
 
%}

NUM		[1-9][0-9]*("."[0-9]+)?
WORD		[a-zA-Z]+
WS		[ \t]+
%%
^{NUM}		{fprintf(yyout,"%d: ",countLine); countNum++ ; countC+=yyleng; ECHO;}
{NUM}		{countNum++ ; countC+=yyleng; ECHO;}
^{WORD}		{fprintf(yyout,"%d: ",countLine); countWord++; countC+=yyleng; ECHO;}
{WORD}		{countWord++; countC+=yyleng; ECHO;}
^{WS}		{fprintf(yyout,"%d: ",countLine); countC+=yyleng; ECHO;}
{WS}		{countC+=yyleng; ECHO;}
^\n        	{fprintf(yyout,"%d: ",countLine);countLine++; countC++; ECHO;}
\n        	{countLine++; countC++; ECHO;}
^.			{fprintf(yyout,"%d: ",countLine); countC+=yyleng; ECHO;}
.			{countC+=yyleng; ECHO;}

%%

int main(int argc, char** argv)
{
  if(argc > 1)
	yyin = fopen(argv[1],"r");
  if(argc > 2)
	yyout = fopen(argv[2],"w");
  yylex();
  return 0;
}

int yywrap()
{
	printf("number of char %d\nnumber of word %d\nnumber of num's %d\nnumber oflines %d\n",countC,countWord,countNum,countLine );
	return 1;
}