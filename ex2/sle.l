%{
#include "lps_tab.h"
#include <string.h>
#define NEXT_LEXEMA column+=yyleng;



int line = 1;
int column = 1;
extern const char * src;

void printError(const char * fmt, ...);

int yylex();

 

%}
LETTER          [a-zA-Z]
DIGIT           [0-9]
ID              {LETTER}({LETTER}|{DIGIT})*
NUM             ({DIGIT}+)|({DIGIT}*("."{DIGIT}+))
LINE 			\n
RELOP           <|>|<>|=
LOGOP			\&|~|\!
ADDOP			\+|\-
MULOP			\*|\/|mod
ASSIGNOP		<\=
WS			    [ \t]+
%x comment
%%
"/*"		BEGIN comment;
<comment>"*/"	BEGIN INITIAL;
<comment>.|\n	;
start		{ECHO;NEXT_LEXEMA;return START;}
do			{ECHO;NEXT_LEXEMA;return DO;}
else		{ECHO;NEXT_LEXEMA;return ELSE;}
if			{ECHO;NEXT_LEXEMA;return IF;}
endi		{ECHO;NEXT_LEXEMA;return ENDI;}
int			{ECHO;NEXT_LEXEMA;return INT;}
put			{ECHO;NEXT_LEXEMA;return PUT;}
prog 		{ECHO;NEXT_LEXEMA;return PROG;}
get			{ECHO;NEXT_LEXEMA;return GET;}
real		{ECHO;NEXT_LEXEMA;return REAL;}
then		{ECHO;NEXT_LEXEMA;return THEN;}
var			{ECHO;NEXT_LEXEMA;return VAR;}
loop		{ECHO;NEXT_LEXEMA;return LOOP;}
endl		{ECHO;NEXT_LEXEMA;return ENDL;}
until		{ECHO;NEXT_LEXEMA;return UNTIL;}
endp		{ECHO;NEXT_LEXEMA;return ENDP;}
"."			{ECHO;NEXT_LEXEMA;return DOT;}
";"			{ECHO;NEXT_LEXEMA;return SEMICOLON;}
":"			{ECHO;NEXT_LEXEMA;return COLON;}
","			{ECHO;NEXT_LEXEMA;return COMMA;}
")"			{ECHO;NEXT_LEXEMA;return RPAR;}
"("			{ECHO;NEXT_LEXEMA;return LPAR;}
"<"			{ECHO;NEXT_LEXEMA; return RELOP;}
">"			{ECHO;NEXT_LEXEMA; return RELOP;}
"<>"		{ECHO;NEXT_LEXEMA; return RELOP;}
"="			{ECHO;NEXT_LEXEMA; return RELOP;}
"&"			{ECHO;NEXT_LEXEMA; return LOGOP;}
"~"	 		{ECHO;NEXT_LEXEMA; return LOGOP;}
"!"			{ECHO;NEXT_LEXEMA; return LOGOP;}
"+"			{ECHO;NEXT_LEXEMA; return ADDOP;}
"-"			{ECHO;NEXT_LEXEMA; return ADDOP;}
"*"			{ECHO;NEXT_LEXEMA; return MULOP;}
"/"			{ECHO;NEXT_LEXEMA; return MULOP;}
"%"			{ECHO;NEXT_LEXEMA; return MULOP;}
"<="		{ECHO;NEXT_LEXEMA;return ASSIGNOP;}
{ID}		{ECHO;NEXT_LEXEMA;return ID;}
{NUM} 		{ECHO;NEXT_LEXEMA;return NUM;}
{WS}		{ECHO;NEXT_LEXEMA;}
\n 			{column=1;line++; fprintf(yyout,"\n%d ", line);}
. 			{NEXT_LEXEMA printError("\n%s:%d:%d syntax error: '%s' was not expected.\n",src,line,column-yyleng,yytext); exit(1);}
%%

int yywrap(){return 1;}