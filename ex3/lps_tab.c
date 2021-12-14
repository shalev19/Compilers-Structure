
/*  A Bison parser, made from lps.y with Bison version GNU Bison version 1.24
  */

#define YYBISON 1  /* Identify Bison output.  */

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

#line 1 "lps.y"

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


#line 34 "lps.y"
typedef union {
 number num;
 char id[16];
 char opr;
 bool boolean;
} YYSTYPE;

#ifndef YYLTYPE
typedef
  struct yyltype
    {
      int timestamp;
      int first_line;
      int first_column;
      int last_line;
      int last_column;
      char *text;
   }
  yyltype;

#define YYLTYPE yyltype
#endif

#include <stdio.h>

#ifndef __cplusplus
#ifndef __STDC__
#define const
#endif
#endif



#define	YYFINAL		93
#define	YYFLAG		-32768
#define	YYNTBASE	32

#define YYTRANSLATE(x) ((unsigned)(x) <= 286 ? yytranslate[x] : 43)

static const char yytranslate[] = {     0,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     1,     2,     3,     4,     5,
     6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
    16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
    26,    27,    28,    29,    30,    31
};

#if YYDEBUG != 0
static const short yyprhs[] = {     0,
     0,     9,    18,    26,    32,    36,    39,    41,    45,    49,
    51,    57,    62,    66,    69,    73,    76,    78,    80,    82,
    84,    88,    92,    93,    97,   100,   103,   106,   109,   117,
   125,   131,   137,   141,   147,   153,   157,   163,   169,   173,
   175,   179,   181,   183,   187,   190,   192,   196,   199,   201,
   203,   205,   209,   213
};

static const short yyrhs[] = {    17,
     3,    27,    33,    10,    36,    25,    26,     0,    17,     3,
    27,    33,    10,    36,    25,     1,     0,    17,     3,    27,
    33,    10,    36,     1,     0,    17,     3,    27,    33,     1,
     0,    17,     3,     1,     0,    17,     1,     0,     1,     0,
    21,    34,    27,     0,    21,    34,     1,     0,     1,     0,
    34,    29,     3,    28,    35,     0,    34,    29,     3,     1,
     0,    34,    29,     1,     0,    34,     1,     0,     3,    28,
    35,     0,     3,     1,     0,     1,     0,    15,     0,    19,
     0,     1,     0,    36,    37,    27,     0,    36,    37,     1,
     0,     0,     3,     9,    40,     0,     3,     1,     0,    16,
    40,     0,    18,     3,     0,    18,     1,     0,    13,    38,
    20,    36,    12,    36,    14,     0,    13,    38,    20,    36,
    12,    36,     1,     0,    13,    38,    20,    36,    14,     0,
    13,    38,    20,    36,     1,     0,    13,    38,     1,     0,
    22,    38,    11,    36,    23,     0,    22,    38,    11,    36,
     1,     0,    22,    38,     1,     0,    11,    36,    24,    38,
    23,     0,    11,    36,    24,    38,     1,     0,    11,    36,
     1,     0,     1,     0,    40,    39,    40,     0,     7,     0,
     8,     0,    40,     5,    41,     0,    40,     1,     0,    41,
     0,    41,     6,    42,     0,    41,     1,     0,    42,     0,
     3,     0,     4,     0,    31,    40,    30,     0,    31,    40,
     1,     0,     1,     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
    58,    59,    60,    61,    62,    63,    64,    66,    67,    68,
    70,    71,    72,    73,    74,    75,    76,    78,    79,    80,
    82,    83,    84,    86,    87,    88,    89,    90,    91,    92,
    93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
   104,   106,   107,   109,   110,   111,   113,   114,   115,   117,
   118,   119,   120,   121
};

static const char * const yytname[] = {   "$","error","$undefined.","ID","NUM",
"ADDOP","MULOP","RELOP","LOGOP","ASSIGNOP","START","DO","ELSE","IF","ENDI","INT",
"PUT","PROG","GET","REAL","THEN","VAR","LOOP","ENDL","UNTIL","ENDP","DOT","SEMICOLON",
"COLON","COMMA","RPAR","LPAR","Program","Declarations","DecList","Type","StmtList",
"Statment","BoolExp","Case","Expression","Term","Factor",""
};
#endif

static const short yyr1[] = {     0,
    32,    32,    32,    32,    32,    32,    32,    33,    33,    33,
    34,    34,    34,    34,    34,    34,    34,    35,    35,    35,
    36,    36,    36,    37,    37,    37,    37,    37,    37,    37,
    37,    37,    37,    37,    37,    37,    37,    37,    37,    37,
    38,    39,    39,    40,    40,    40,    41,    41,    41,    42,
    42,    42,    42,    42
};

static const short yyr2[] = {     0,
     8,     8,     7,     5,     3,     2,     1,     3,     3,     1,
     5,     4,     3,     2,     3,     2,     1,     1,     1,     1,
     3,     3,     0,     3,     2,     2,     2,     2,     7,     7,
     5,     5,     3,     5,     5,     3,     5,     5,     3,     1,
     3,     1,     1,     3,     2,     1,     3,     2,     1,     1,
     1,     3,     3,     1
};

static const short yydefact[] = {     0,
     7,     0,     6,     0,     5,     0,    10,     0,     0,    17,
     0,     0,     4,    23,    16,     0,     9,     8,     0,     0,
    20,    18,    19,    15,    13,     0,    40,     0,    23,     0,
     0,     0,     0,     0,     0,    12,     0,    25,     0,     0,
    54,    50,    51,     0,     0,     0,     0,    49,     0,    28,
    27,     0,     2,     1,    22,    21,    11,     0,    39,     0,
     0,    33,    23,    45,     0,    42,    43,     0,    48,     0,
    36,    23,     0,    53,    52,     0,     0,     0,    47,     0,
    38,    37,    32,    23,    31,    35,    34,     0,    30,    29,
     0,     0,     0
};

static const short yydefgoto[] = {    91,
     9,    12,    24,    20,    35,    45,    68,    46,    47,    48
};

static const short yypact[] = {    58,
-32768,    97,-32768,    35,-32768,     6,-32768,   106,    95,-32768,
    11,     2,-32768,-32768,-32768,     7,    85,-32768,   118,    70,
-32768,-32768,-32768,-32768,-32768,    22,    13,    60,-32768,     1,
     1,   132,     1,    18,    41,-32768,     7,-32768,     1,    86,
-32768,-32768,-32768,     1,    64,   144,    10,-32768,    52,-32768,
-32768,    63,-32768,-32768,-32768,-32768,-32768,    53,-32768,     1,
     5,-32768,-32768,-32768,     1,-32768,-32768,     1,-32768,     1,
-32768,-32768,    55,    19,-32768,   114,    40,    71,-32768,   100,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,   128,-32768,-32768,
    28,    66,-32768
};

static const short yypgoto[] = {-32768,
-32768,-32768,    48,   -29,-32768,    -8,-32768,   -30,    12,    20
};


#define	YYLAST		152


static const short yytable[] = {    40,
    49,    41,    17,    42,    43,    74,     7,    21,    58,    65,
    69,    15,    -3,    61,   -46,    70,   -46,   -46,    53,   -45,
   -46,    22,    36,   -45,    52,    23,     8,    92,    18,   -46,
    19,    44,   -46,    76,    75,     5,   -46,    78,    16,   -46,
    69,    55,    80,    54,   -44,    70,   -44,   -44,   -45,    37,
   -44,    73,    64,    64,    88,    81,    65,    65,     1,   -44,
    38,     6,   -44,    71,    62,    93,   -44,    56,    39,   -44,
    27,    64,    28,    72,     2,    65,    77,    82,   -26,   -24,
    29,   -41,    30,    63,    57,    31,    59,    32,    28,    79,
   -41,    33,     0,   -41,    34,    13,    29,     3,    30,     4,
    86,    31,    28,    32,    14,     0,    10,    33,    11,    60,
    29,   -14,    30,   -14,    83,    31,    28,    32,    25,     0,
    26,    33,    87,     0,    29,    84,    30,    85,    89,    31,
    28,    32,    50,     0,    51,    33,     0,     0,    29,     0,
    30,    90,     0,    31,    64,    32,     0,     0,    65,    33,
    66,    67
};

static const short yycheck[] = {    29,
    31,     1,     1,     3,     4,     1,     1,     1,    39,     5,
     1,     1,     0,    44,     5,     6,     7,     8,     1,     1,
    11,    15,     1,     5,    33,    19,    21,     0,    27,    20,
    29,    31,    23,    63,    30,     1,    27,    68,    28,    30,
     1,     1,    72,    26,     5,     6,     7,     8,    30,    28,
    11,    60,     1,     1,    84,     1,     5,     5,     1,    20,
     1,    27,    23,     1,     1,     0,    27,    27,     9,    30,
     1,     1,     3,    11,    17,     5,    65,    23,    27,    27,
    11,    11,    13,    20,    37,    16,     1,    18,     3,    70,
    20,    22,    -1,    23,    25,     1,    11,     1,    13,     3,
     1,    16,     3,    18,    10,    -1,     1,    22,     3,    24,
    11,    27,    13,    29,     1,    16,     3,    18,     1,    -1,
     3,    22,    23,    -1,    11,    12,    13,    14,     1,    16,
     3,    18,     1,    -1,     3,    22,    -1,    -1,    11,    -1,
    13,    14,    -1,    16,     1,    18,    -1,    -1,     5,    22,
     7,     8
};
/* -*-C-*-  Note some compilers choke on comments on `#line' lines.  */
#line 3 "bison.simple"

/* Skeleton output parser for bison,
   Copyright (C) 1984, 1989, 1990 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

#ifndef alloca
#ifdef __GNUC__
#define alloca __builtin_alloca
#else /* not GNU C.  */
#if (!defined (__STDC__) && defined (sparc)) || defined (__sparc__) || defined (__sparc) || defined (__sgi)
#include <alloca.h>
#else /* not sparc */
#if defined (MSDOS) && !defined (__TURBOC__)
#include <malloc.h>
#else /* not MSDOS, or __TURBOC__ */
#if defined(_AIX)
#include <malloc.h>
 #pragma alloca
#else /* not MSDOS, __TURBOC__, or _AIX */
#ifdef __hpux
#ifdef __cplusplus
extern "C" {
void *alloca (unsigned int);
};
#else /* not __cplusplus */
void *alloca ();
#endif /* not __cplusplus */
#endif /* __hpux */
#endif /* not _AIX */
#endif /* not MSDOS, or __TURBOC__ */
#endif /* not sparc.  */
#endif /* not GNU C.  */
#endif /* alloca not defined.  */

/* This is the parser code that is written into each bison parser
  when the %semantic_parser declaration is not specified in the grammar.
  It was written by Richard Stallman by simplifying the hairy parser
  used when %semantic_parser is specified.  */

/* Note: there must be only one dollar sign in this file.
   It is replaced by the list of actions, each action
   as one case of the switch.  */

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		-2
#define YYEOF		0
#define YYACCEPT	return(0)
#define YYABORT 	return(1)
#define YYERROR		goto yyerrlab1
/* Like YYERROR except do call yyerror.
   This remains here temporarily to ease the
   transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */
#define YYFAIL		goto yyerrlab
#define YYRECOVERING()  (!!yyerrstatus)
#define YYBACKUP(token, value) \
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    { yychar = (token), yylval = (value);			\
      yychar1 = YYTRANSLATE (yychar);				\
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    { yyerror ("syntax error: cannot back up"); YYERROR; }	\
while (0)

#define YYTERROR	1
#define YYERRCODE	256

#ifndef YYPURE
#define YYLEX		yylex()
#endif

#ifdef YYPURE
#ifdef YYLSP_NEEDED
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, &yylloc, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval, &yylloc)
#endif
#else /* not YYLSP_NEEDED */
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval)
#endif
#endif /* not YYLSP_NEEDED */
#endif

/* If nonreentrant, generate the variables here */

#ifndef YYPURE

int	yychar;			/*  the lookahead symbol		*/
YYSTYPE	yylval;			/*  the semantic value of the		*/
				/*  lookahead symbol			*/

#ifdef YYLSP_NEEDED
YYLTYPE yylloc;			/*  location data for the lookahead	*/
				/*  symbol				*/
#endif

int yynerrs;			/*  number of parse errors so far       */
#endif  /* not YYPURE */

#if YYDEBUG != 0
int yydebug;			/*  nonzero means print parse trace	*/
/* Since this is uninitialized, it does not stop multiple parsers
   from coexisting.  */
#endif

/*  YYINITDEPTH indicates the initial size of the parser's stacks	*/

#ifndef	YYINITDEPTH
#define YYINITDEPTH 200
#endif

/*  YYMAXDEPTH is the maximum size the stacks can grow to
    (effective only if the built-in stack extension method is used).  */

#if YYMAXDEPTH == 0
#undef YYMAXDEPTH
#endif

#ifndef YYMAXDEPTH
#define YYMAXDEPTH 10000
#endif

/* Prevent warning if -Wstrict-prototypes.  */
#ifdef __GNUC__
int yyparse (void);
#endif

#if __GNUC__ > 1		/* GNU C and GNU C++ define this.  */
#define __yy_memcpy(FROM,TO,COUNT)	__builtin_memcpy(TO,FROM,COUNT)
#else				/* not GNU C or C++ */
#ifndef __cplusplus

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (from, to, count)
     char *from;
     char *to;
     int count;
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#else /* __cplusplus */

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (char *from, char *to, int count)
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#endif
#endif

#line 192 "bison.simple"

/* The user can define YYPARSE_PARAM as the name of an argument to be passed
   into yyparse.  The argument should have type void *.
   It should actually point to an object.
   Grammar actions can access the variable by casting it
   to the proper pointer type.  */

#ifdef YYPARSE_PARAM
#define YYPARSE_PARAM_DECL void *YYPARSE_PARAM;
#else
#define YYPARSE_PARAM
#define YYPARSE_PARAM_DECL
#endif

int
yyparse(YYPARSE_PARAM)
     YYPARSE_PARAM_DECL
{
  register int yystate;
  register int yyn;
  register short *yyssp;
  register YYSTYPE *yyvsp;
  int yyerrstatus;	/*  number of tokens to shift before error messages enabled */
  int yychar1 = 0;		/*  lookahead token as an internal (translated) token number */

  short	yyssa[YYINITDEPTH];	/*  the state stack			*/
  YYSTYPE yyvsa[YYINITDEPTH];	/*  the semantic value stack		*/

  short *yyss = yyssa;		/*  refer to the stacks thru separate pointers */
  YYSTYPE *yyvs = yyvsa;	/*  to allow yyoverflow to reallocate them elsewhere */

#ifdef YYLSP_NEEDED
  YYLTYPE yylsa[YYINITDEPTH];	/*  the location stack			*/
  YYLTYPE *yyls = yylsa;
  YYLTYPE *yylsp;

#define YYPOPSTACK   (yyvsp--, yyssp--, yylsp--)
#else
#define YYPOPSTACK   (yyvsp--, yyssp--)
#endif

  int yystacksize = YYINITDEPTH;

#ifdef YYPURE
  int yychar;
  YYSTYPE yylval;
  int yynerrs;
#ifdef YYLSP_NEEDED
  YYLTYPE yylloc;
#endif
#endif

  YYSTYPE yyval;		/*  the variable used to return		*/
				/*  semantic values from the action	*/
				/*  routines				*/

  int yylen;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Starting parse\n");
#endif

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss - 1;
  yyvsp = yyvs;
#ifdef YYLSP_NEEDED
  yylsp = yyls;
#endif

/* Push a new state, which is found in  yystate  .  */
/* In all cases, when you get here, the value and location stacks
   have just been pushed. so pushing a state here evens the stacks.  */
yynewstate:

  *++yyssp = yystate;

  if (yyssp >= yyss + yystacksize - 1)
    {
      /* Give user a chance to reallocate the stack */
      /* Use copies of these so that the &'s don't force the real ones into memory. */
      YYSTYPE *yyvs1 = yyvs;
      short *yyss1 = yyss;
#ifdef YYLSP_NEEDED
      YYLTYPE *yyls1 = yyls;
#endif

      /* Get the current used size of the three stacks, in elements.  */
      int size = yyssp - yyss + 1;

#ifdef yyoverflow
      /* Each stack pointer address is followed by the size of
	 the data in use in that stack, in bytes.  */
#ifdef YYLSP_NEEDED
      /* This used to be a conditional around just the two extra args,
	 but that might be undefined if yyoverflow is a macro.  */
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yyls1, size * sizeof (*yylsp),
		 &yystacksize);
#else
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yystacksize);
#endif

      yyss = yyss1; yyvs = yyvs1;
#ifdef YYLSP_NEEDED
      yyls = yyls1;
#endif
#else /* no yyoverflow */
      /* Extend the stack our own way.  */
      if (yystacksize >= YYMAXDEPTH)
	{
	  yyerror("parser stack overflow");
	  return 2;
	}
      yystacksize *= 2;
      if (yystacksize > YYMAXDEPTH)
	yystacksize = YYMAXDEPTH;
      yyss = (short *) alloca (yystacksize * sizeof (*yyssp));
      __yy_memcpy ((char *)yyss1, (char *)yyss, size * sizeof (*yyssp));
      yyvs = (YYSTYPE *) alloca (yystacksize * sizeof (*yyvsp));
      __yy_memcpy ((char *)yyvs1, (char *)yyvs, size * sizeof (*yyvsp));
#ifdef YYLSP_NEEDED
      yyls = (YYLTYPE *) alloca (yystacksize * sizeof (*yylsp));
      __yy_memcpy ((char *)yyls1, (char *)yyls, size * sizeof (*yylsp));
#endif
#endif /* no yyoverflow */

      yyssp = yyss + size - 1;
      yyvsp = yyvs + size - 1;
#ifdef YYLSP_NEEDED
      yylsp = yyls + size - 1;
#endif

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Stack size increased to %d\n", yystacksize);
#endif

      if (yyssp >= yyss + yystacksize - 1)
	YYABORT;
    }

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Entering state %d\n", yystate);
#endif

  goto yybackup;
 yybackup:

/* Do appropriate processing given the current state.  */
/* Read a lookahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to lookahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* yychar is either YYEMPTY or YYEOF
     or a valid token in external form.  */

  if (yychar == YYEMPTY)
    {
#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Reading a token: ");
#endif
      yychar = YYLEX;
    }

  /* Convert token to internal form (in yychar1) for indexing tables with */

  if (yychar <= 0)		/* This means end of input. */
    {
      yychar1 = 0;
      yychar = YYEOF;		/* Don't call YYLEX any more */

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Now at end of input.\n");
#endif
    }
  else
    {
      yychar1 = YYTRANSLATE(yychar);

#if YYDEBUG != 0
      if (yydebug)
	{
	  fprintf (stderr, "Next token is %d (%s", yychar, yytname[yychar1]);
	  /* Give the individual parser a way to print the precise meaning
	     of a token, for further debugging info.  */
#ifdef YYPRINT
	  YYPRINT (stderr, yychar, yylval);
#endif
	  fprintf (stderr, ")\n");
	}
#endif
    }

  yyn += yychar1;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != yychar1)
    goto yydefault;

  yyn = yytable[yyn];

  /* yyn is what to do for this token type in this state.
     Negative => reduce, -yyn is rule number.
     Positive => shift, yyn is new state.
       New state is final state => don't bother to shift,
       just return success.
     0, or most negative number => error.  */

  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrlab;

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the lookahead token.  */

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting token %d (%s), ", yychar, yytname[yychar1]);
#endif

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  /* count tokens shifted since error; after three, turn off error status.  */
  if (yyerrstatus) yyerrstatus--;

  yystate = yyn;
  goto yynewstate;

/* Do the default action for the current state.  */
yydefault:

  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;

/* Do a reduction.  yyn is the number of a rule to reduce with.  */
yyreduce:
  yylen = yyr2[yyn];
  if (yylen > 0)
    yyval = yyvsp[1-yylen]; /* implement default value of the action */

#if YYDEBUG != 0
  if (yydebug)
    {
      int i;

      fprintf (stderr, "Reducing via rule %d (line %d), ",
	       yyn, yyrline[yyn]);

      /* Print the symbols being reduced, and their result.  */
      for (i = yyprhs[yyn]; yyrhs[i] > 0; i++)
	fprintf (stderr, "%s ", yytname[yyrhs[i]]);
      fprintf (stderr, " -> %s\n", yytname[yyr1[yyn]]);
    }
#endif


  switch (yyn) {

case 1:
#line 58 "lps.y"
{number prog; prog.type = PROGNAME; insertSymbol(yyvsp[-6].id, prog);;
    break;}
case 2:
#line 59 "lps.y"
{fprintf(stderr,"missing '.' at the end of program.");;
    break;}
case 3:
#line 60 "lps.y"
{fprintf(stderr,"missing 'endp' at end of program.");;
    break;}
case 4:
#line 61 "lps.y"
{fprintf(stderr,"undefined reference to 'start'.");;
    break;}
case 5:
#line 62 "lps.y"
{fprintf(stderr,"missing semi colon after program name.");;
    break;}
case 6:
#line 63 "lps.y"
{fprintf(stderr,"programe name is ilegal.");;
    break;}
case 7:
#line 64 "lps.y"
{fprintf(stderr,"program always start with 'prog'.");;
    break;}
case 9:
#line 67 "lps.y"
{yyerror("missing semi colon after program name.");;
    break;}
case 10:
#line 68 "lps.y"
{yyerror("expected var decleration.");;
    break;}
case 11:
#line 70 "lps.y"
{insertSymbol(yyvsp[-2].id, yyvsp[0].num);;
    break;}
case 12:
#line 71 "lps.y"
{yyerror("missing ':' after variable name.");;
    break;}
case 13:
#line 72 "lps.y"
{yyerror("after ',' need to come variable name.");;
    break;}
case 14:
#line 73 "lps.y"
{yyerror("expected ',' after decleration.");;
    break;}
case 15:
#line 74 "lps.y"
{insertSymbol(yyvsp[-2].id, yyvsp[0].num);;
    break;}
case 16:
#line 75 "lps.y"
{yyerror("after variable needs to come ','.");;
    break;}
case 17:
#line 76 "lps.y"
{yyerror("after 'var' nneds to come variable.");;
    break;}
case 18:
#line 78 "lps.y"
{yyval.num.type = INTEGER;;
    break;}
case 19:
#line 79 "lps.y"
{yyval.num.type = FLOAT;;
    break;}
case 20:
#line 80 "lps.y"
{yyerror("ilegal type");;
    break;}
case 21:
#line 82 "lps.y"
{;
    break;}
case 22:
#line 83 "lps.y"
{yyerror("after statment needs to come ';'.");;
    break;}
case 23:
#line 84 "lps.y"
{;
    break;}
case 24:
#line 86 "lps.y"
{insertAssignOp(yyvsp[-2].id, yyvsp[0].num);;
    break;}
case 25:
#line 87 "lps.y"
{yyerror("after variable needs to come '<='.");;
    break;}
case 26:
#line 88 "lps.y"
{printNumber(yyvsp[0].num);;
    break;}
case 27:
#line 89 "lps.y"
{;
    break;}
case 28:
#line 90 "lps.y"
{yyerror("after 'GET' needs to come variable.");;
    break;}
case 29:
#line 91 "lps.y"
{;
    break;}
case 30:
#line 92 "lps.y"
{yyerror("after statment needs to come 'ENDI'.");;
    break;}
case 31:
#line 93 "lps.y"
{;
    break;}
case 32:
#line 94 "lps.y"
{yyerror("after if statment needs to come 'ENDI' or 'ELSE'.");;
    break;}
case 33:
#line 95 "lps.y"
{yyerror("after boolean expration needs to come 'THEN'.");;
    break;}
case 34:
#line 96 "lps.y"
{;
    break;}
case 35:
#line 97 "lps.y"
{yyerror("after statment needs to come 'ENDI'.");;
    break;}
case 36:
#line 98 "lps.y"
{yyerror("after the LOOP needs to come 'DO'.");;
    break;}
case 37:
#line 99 "lps.y"
{;
    break;}
case 38:
#line 100 "lps.y"
{yyerror("after 'DO UNTIL' needs to come 'ENDL'.");;
    break;}
case 39:
#line 101 "lps.y"
{yyerror("after 'DO' needs to come 'UNTILE'.");;
    break;}
case 40:
#line 102 "lps.y"
{yyerror("undifinded statment");;
    break;}
case 41:
#line 104 "lps.y"
{yyval.boolean = booleanExpration(yyvsp[-2].num, yyvsp[-1].opr, yyvsp[0].num);;
    break;}
case 42:
#line 106 "lps.y"
{yyval.opr=yyvsp[0].opr;;
    break;}
case 43:
#line 107 "lps.y"
{yyval.opr=yyvsp[0].opr;;
    break;}
case 44:
#line 109 "lps.y"
{yyval.num = addOperator(yyvsp[-2].num, yyvsp[-1].opr, yyvsp[0].num);;
    break;}
case 45:
#line 110 "lps.y"
{yyerror("expected 'ADDOP' opearation");;
    break;}
case 46:
#line 111 "lps.y"
{yyval.num=yyvsp[0].num;;
    break;}
case 47:
#line 113 "lps.y"
{yyval.num = mulOperator(yyvsp[-2].num, yyvsp[-1].opr, yyvsp[0].num);;
    break;}
case 48:
#line 114 "lps.y"
{yyerror("expected 'MUL' operation after 'Term'.");;
    break;}
case 49:
#line 115 "lps.y"
{yyval.num = yyvsp[0].num;;
    break;}
case 50:
#line 117 "lps.y"
{yyval.num = searchSymbol(yyvsp[0].id);;
    break;}
case 51:
#line 118 "lps.y"
{yyval.num = yyvsp[0].num;;
    break;}
case 52:
#line 119 "lps.y"
{yyval.num = yyvsp[-1].num;;
    break;}
case 53:
#line 120 "lps.y"
{yyerror("missing ')'.");;
    break;}
case 54:
#line 121 "lps.y"
{yyerror("expected an ID or number.");;
    break;}
}
   /* the action file gets copied in in place of this dollarsign */
#line 487 "bison.simple"

  yyvsp -= yylen;
  yyssp -= yylen;
#ifdef YYLSP_NEEDED
  yylsp -= yylen;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

  *++yyvsp = yyval;

#ifdef YYLSP_NEEDED
  yylsp++;
  if (yylen == 0)
    {
      yylsp->first_line = yylloc.first_line;
      yylsp->first_column = yylloc.first_column;
      yylsp->last_line = (yylsp-1)->last_line;
      yylsp->last_column = (yylsp-1)->last_column;
      yylsp->text = 0;
    }
  else
    {
      yylsp->last_line = (yylsp+yylen-1)->last_line;
      yylsp->last_column = (yylsp+yylen-1)->last_column;
    }
#endif

  /* Now "shift" the result of the reduction.
     Determine what state that goes to,
     based on the state we popped back to
     and the rule number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTBASE] + *yyssp;
  if (yystate >= 0 && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTBASE];

  goto yynewstate;

yyerrlab:   /* here on detecting error */

  if (! yyerrstatus)
    /* If not already recovering from an error, report this error.  */
    {
      ++yynerrs;

#ifdef YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (yyn > YYFLAG && yyn < YYLAST)
	{
	  int size = 0;
	  char *msg;
	  int x, count;

	  count = 0;
	  /* Start X at -yyn if nec to avoid negative indexes in yycheck.  */
	  for (x = (yyn < 0 ? -yyn : 0);
	       x < (sizeof(yytname) / sizeof(char *)); x++)
	    if (yycheck[x + yyn] == x)
	      size += strlen(yytname[x]) + 15, count++;
	  msg = (char *) malloc(size + 15);
	  if (msg != 0)
	    {
	      strcpy(msg, "parse error");

	      if (count < 5)
		{
		  count = 0;
		  for (x = (yyn < 0 ? -yyn : 0);
		       x < (sizeof(yytname) / sizeof(char *)); x++)
		    if (yycheck[x + yyn] == x)
		      {
			strcat(msg, count == 0 ? ", expecting `" : " or `");
			strcat(msg, yytname[x]);
			strcat(msg, "'");
			count++;
		      }
		}
	      yyerror(msg);
	      free(msg);
	    }
	  else
	    yyerror ("parse error; also virtual memory exceeded");
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror("parse error");
    }

  goto yyerrlab1;
yyerrlab1:   /* here on error raised explicitly by an action */

  if (yyerrstatus == 3)
    {
      /* if just tried and failed to reuse lookahead token after an error, discard it.  */

      /* return failure if at end of input */
      if (yychar == YYEOF)
	YYABORT;

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Discarding token %d (%s).\n", yychar, yytname[yychar1]);
#endif

      yychar = YYEMPTY;
    }

  /* Else will try to reuse lookahead token
     after shifting the error token.  */

  yyerrstatus = 3;		/* Each real token shifted decrements this */

  goto yyerrhandle;

yyerrdefault:  /* current state does not do anything special for the error token. */

#if 0
  /* This is wrong; only states that explicitly want error tokens
     should shift them.  */
  yyn = yydefact[yystate];  /* If its default is to accept any token, ok.  Otherwise pop it.*/
  if (yyn) goto yydefault;
#endif

yyerrpop:   /* pop the current state because it cannot handle the error token */

  if (yyssp == yyss) YYABORT;
  yyvsp--;
  yystate = *--yyssp;
#ifdef YYLSP_NEEDED
  yylsp--;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "Error: state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

yyerrhandle:

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yyerrdefault;

  yyn += YYTERROR;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != YYTERROR)
    goto yyerrdefault;

  yyn = yytable[yyn];
  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrpop;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrpop;

  if (yyn == YYFINAL)
    YYACCEPT;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting error token, ");
#endif

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  yystate = yyn;
  goto yynewstate;
}

#line 124 "lps.y"


void yyerror(const char * err){
	fprintf(stderr,"\n%s.sle:%d::parser error: unexpected token %s \n",src,line,yytext);
}

