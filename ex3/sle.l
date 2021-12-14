%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef enum { FALSE,TRUE} bool;
typedef enum {INTEGER ,FLOAT ,PROGNAME ,ERROR} Type;
typedef struct {
  int intNum;
  float floatNum;
  Type type;	
} number;
#include "lps_tab.h"

int line = 1;
 int yyparse(),yyleng;
 char * yytext;
 FILE *yyin,*yyout;
 const char * src;

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
start		{ECHO;return START;}
do			{ECHO;return DO;}
else		{ECHO;return ELSE;}
if			{ECHO;return IF;}
endi		{ECHO;return ENDI;}
int			{ECHO;return INT;}
put			{ECHO;return PUT;}
prog 		{ECHO;return PROG;}
get			{ECHO;return GET;}
real		{ECHO;return REAL;}
then		{ECHO;return THEN;}
var			{ECHO;return VAR;}
loop		{ECHO;return LOOP;}
endl		{ECHO;return ENDL;}
until		{ECHO;return UNTIL;}
endp		{ECHO;return ENDP;}
"."			{ECHO;return DOT;}
";"			{ECHO;return SEMICOLON;}
":"			{ECHO;return COLON;}
","			{ECHO;return COMMA;}
")"			{ECHO;return RPAR;}
"("			{ECHO;return LPAR;}
"<"			{ECHO; yylval.opr =*yytext ;return RELOP;}
">"			{ECHO; yylval.opr =*yytext ;return RELOP;}
"<>"		{ECHO; yylval.opr ='!'; return RELOP;}
"="			{ECHO; yylval.opr =*yytext ; return RELOP;}
"&"			{ECHO; yylval.opr =*yytext ; return LOGOP;}
"~"	 		{ECHO; yylval.opr =*yytext ; return LOGOP;}
"!"			{ECHO; yylval.opr =*yytext ; return LOGOP;}
"+"			{ECHO; yylval.opr =*yytext ; return ADDOP;}
"-"			{ECHO; yylval.opr =*yytext ; return ADDOP;}
"*"			{ECHO; yylval.opr =*yytext ; return MULOP;}
"/"			{ECHO; yylval.opr =*yytext ; return MULOP;}
"mod"		{ECHO; yylval.opr = '%'; return MULOP;}
"<="		{ECHO;return ASSIGNOP;}
{ID}		{ECHO;strcpy(yylval.id,yytext); return ID;}
{NUM} 		{ECHO;
                    if(strchr(yytext,'.')){
                        yylval.num.floatNum = atof(yytext);
					    yylval.num.type = FLOAT;
				    }else{
					    yylval.num.intNum = atoi(yytext);
					    yylval.num.type = INTEGER;
				}
                    return NUM;}
{WS}		{ECHO;}
\n 			{line++; fprintf(yyout,"\n%d ", line);}
. 			{fprintf(yyout,"\n syntax error: '%s' was not expected.\n",yytext); exit(1);}
%%

int yywrap(){return 1;}