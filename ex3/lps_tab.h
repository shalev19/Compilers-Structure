typedef union {
 number num;
 char id[16];
 char opr;
 bool boolean;
} YYSTYPE;
#define	ID	258
#define	NUM	259
#define	ADDOP	260
#define	MULOP	261
#define	RELOP	262
#define	LOGOP	263
#define	ASSIGNOP	264
#define	START	265
#define	DO	266
#define	ELSE	267
#define	IF	268
#define	ENDI	269
#define	INT	270
#define	PUT	271
#define	PROG	272
#define	GET	273
#define	REAL	274
#define	THEN	275
#define	VAR	276
#define	LOOP	277
#define	ENDL	278
#define	UNTIL	279
#define	ENDP	280
#define	DOT	281
#define	SEMICOLON	282
#define	COLON	283
#define	COMMA	284
#define	RPAR	285
#define	LPAR	286


extern YYSTYPE yylval;
