# define _BANG_t 257
# define _BANG_EQUALS_t 258
# define _AMPER_t 259
# define _AMPERAMPER_t 260
# define _LPAREN_t 261
# define _RPAREN_t 262
# define _PLUS_EQUALS_t 263
# define _COLON_t 264
# define _SEMIC_t 265
# define _LANGLE_t 266
# define _LANGLE_EQUALS_t 267
# define _EQUALS_t 268
# define _RANGLE_t 269
# define _RANGLE_EQUALS_t 270
# define _QUESTION_EQUALS_t 271
# define _LBRACKET_t 272
# define _RBRACKET_t 273
# define ACTIONS_t 274
# define BIND_t 275
# define BREAK_t 276
# define CASE_t 277
# define CONTINUE_t 278
# define DEFAULT_t 279
# define ELSE_t 280
# define EXISTING_t 281
# define FOR_t 282
# define IF_t 283
# define IGNORE_t 284
# define IN_t 285
# define INCLUDE_t 286
# define LOCAL_t 287
# define MAXLINE_t 288
# define ON_t 289
# define PIECEMEAL_t 290
# define QUIETLY_t 291
# define RETURN_t 292
# define RULE_t 293
# define SWITCH_t 294
# define TOGETHER_t 295
# define UPDATED_t 296
# define WHILE_t 297
# define _LBRACE_t 298
# define _BAR_t 299
# define _BARBAR_t 300
# define _RBRACE_t 301
# define ARG 302
# define STRING 303
#include "jam.h"

#include "ansi.h"
#include "compile.h"
#include "lists.h"
#include "parse.h"
#include "rules.h"
#include "scan.h"
#include "str.h"
#include "variable.h"

#define YYMAXDEPTH 10000  /* increase depth for OSF and similar system */

#if __STD_C
# define F0 (LIST *(*)(PARSE *, LOL *, int *))0
#else
# define F0 (LIST *(*)())0
#endif
#define P0 (PARSE *)0
#define S0 (char *)0

# define pappend( l,r )         parse_make( compile_append,l,r,P0,S0,S0,0 )
# define pbreak( l,f )          parse_make( compile_break,l,P0,P0,S0,S0,f )
# define peval( c,l,r )         parse_make( compile_eval,l,r,P0,S0,S0,c )
# define pfor( s,l,r )          parse_make( compile_foreach,l,r,P0,s,S0,0 )
# define pif( l,r,t )           parse_make( compile_if,l,r,t,S0,S0,0 )
# define pincl( l )             parse_make( compile_include,l,P0,P0,S0,S0,0 )
# define plist( s )             parse_make( compile_list,P0,P0,P0,s,S0,0 )
# define plocal( l,r,t )        parse_make( compile_local,l,r,t,S0,S0,0 )
# define pnull()                parse_make( compile_null,P0,P0,P0,S0,S0,0 )
# define pon( l,r )             parse_make( compile_on,l,r,P0,S0,S0,0 )
# define prule( a,p )           parse_make( compile_rule,a,p,P0,S0,S0,0 )
# define prules( l,r )          parse_make( compile_rules,l,r,P0,S0,S0,0 )
# define pset( l,r,a )          parse_make( compile_set,l,r,P0,S0,S0,a )
# define pset1( l,r,t,a )       parse_make( compile_settings,l,r,t,S0,S0,a )
# define psetc( s,l,r )         parse_make( compile_setcomp,l,r,P0,s,S0,0 )
# define psete( s,l,s1,f )      parse_make( compile_setexec,l,P0,P0,s,s1,f )
# define pswitch( l,r )         parse_make( compile_switch,l,r,P0,S0,S0,0 )
# define pwhile( l,r )          parse_make( compile_while,l,r,P0,S0,S0,0 )

# define pnode( l,r )           parse_make( F0,l,r,P0,S0,S0,0 )
# define psnode( s,l )          parse_make( F0,l,P0,P0,s,S0,0 )


#ifdef __STDC__
#include <stdlib.h>
#include <string.h>
#define	YYCONST	const
#else
#include <malloc.h>
#include <memory.h>
#define	YYCONST
#endif

#if defined(__cplusplus) || defined(__STDC__)

#if defined(__cplusplus) && defined(__EXTERN_C__)
extern "C" {
#endif
#ifndef yyerror
#if defined(__cplusplus)
	void yyerror(YYCONST char *);
#endif
#endif
#ifndef yylex
	int yylex(void);
#endif
	int yyparse(void);
#if defined(__cplusplus) && defined(__EXTERN_C__)
}
#endif

#endif

#define yyclearin yychar = -1
#define yyerrok yyerrflag = 0
extern int yychar;
extern int yyerrflag;
#ifndef YYSTYPE
#define YYSTYPE int
#endif
YYSTYPE yylval;
YYSTYPE yyval;
typedef int yytabelem;
#ifndef YYMAXDEPTH
#define YYMAXDEPTH 150
#endif
#if YYMAXDEPTH > 0
int yy_yys[YYMAXDEPTH], *yys = yy_yys;
YYSTYPE yy_yyv[YYMAXDEPTH], *yyv = yy_yyv;
#else	/* user does initial allocation */
int *yys;
YYSTYPE *yyv;
#endif
static int yymaxdepth = YYMAXDEPTH;
# define YYERRCODE 256
static YYCONST yytabelem yyexca[] ={
-1, 1,
	0, -1,
	-2, 0,
	};
# define YYNPROD 73
# define YYLAST 315
static YYCONST yytabelem yyact[]={

    19,    41,    17,   150,     8,    42,     9,    79,   129,    19,
    11,    13,    19,   120,     6,     4,    19,    16,    44,    37,
    10,    15,    12,   152,   147,    14,     5,    19,   143,    17,
    18,     8,   137,     9,   131,   130,   127,    11,    13,    18,
    51,     6,    18,   134,    16,   126,    18,    10,    15,    12,
   116,    62,    14,     5,    65,    70,    71,    18,   114,    65,
    70,    71,    66,    67,    64,    68,    69,    66,    67,    64,
    68,    69,    65,    70,    71,    19,    74,    61,   142,   101,
    66,    67,    64,    68,    69,   119,    31,    48,   121,    57,
    49,    30,    92,   139,    32,    72,    73,   124,    95,    77,
    72,    73,    33,    66,    67,    18,    68,    69,    88,    60,
    59,    85,    63,    72,    73,    89,    31,    87,    86,    58,
    53,    30,    84,    83,    32,    65,    70,    71,    52,    81,
   141,    23,    33,    66,    67,    64,    68,    69,    65,   117,
    56,     3,    28,    78,    26,    99,    66,    67,    64,    68,
    69,    40,     7,    82,    90,     7,    27,     7,    24,     2,
    29,    47,    20,    22,   100,    21,   151,    25,    45,    34,
    35,    36,   144,    38,    50,   118,    46,     1,     0,     0,
    93,     0,     0,     0,     0,     0,     0,    80,    54,    55,
     0,     0,     0,     0,     0,   102,     0,     7,     0,    91,
     7,    97,     0,     0,     0,     0,     0,     0,     0,   115,
    94,     0,    96,     0,     0,     7,     0,     0,     0,     0,
     0,     0,    98,     0,     0,     0,     0,     0,     0,     7,
     0,     0,     0,     0,     0,   113,   122,     0,     0,     0,
    39,     0,     0,     0,   123,     0,   128,     0,   132,     0,
     0,     0,     0,     0,     0,    43,   138,   125,   140,     0,
     0,   133,     0,     0,     0,     0,     0,     0,     7,     0,
     0,     0,     0,   148,     0,   136,     7,     0,     7,     0,
   135,   145,    75,    76,   149,     0,     0,     0,     0,     0,
     0,     0,     0,     7,     7,     0,     0,     0,   146,     0,
     0,     0,     0,     0,     0,   103,   104,   105,   106,   107,
   108,   109,   110,   111,   112 };
static YYCONST yytabelem yypact[]={

  -272,-10000000,-10000000,  -272,-10000000,  -272,-10000000,  -147,-10000000,-10000000,
-10000000,  -283,-10000000,  -256,  -256,  -284,  -263,-10000000,-10000000,-10000000,
-10000000,  -178,  -263,  -261,-10000000,  -137,  -145,-10000000,-10000000,  -124,
-10000000,-10000000,-10000000,  -179,  -146,  -155,  -156,  -208,  -247,  -186,
  -209,  -256,  -256,  -199,  -295,  -245,  -173,  -197,  -272,-10000000,
-10000000,-10000000,-10000000,-10000000,  -167,  -177,-10000000,-10000000,-10000000,-10000000,
-10000000,-10000000,  -198,  -272,  -256,  -256,  -256,  -256,  -256,  -256,
  -256,  -256,  -256,  -256,-10000000,-10000000,  -204,  -272,  -248,  -125,
-10000000,  -190,-10000000,-10000000,-10000000,-10000000,-10000000,-10000000,-10000000,  -289,
  -185,-10000000,  -263,-10000000,  -168,-10000000,-10000000,-10000000,  -253,  -265,
  -198,  -294,  -266,  -163,  -163,-10000000,-10000000,-10000000,-10000000,  -120,
  -120,  -133,  -133,-10000000,-10000000,  -267,  -272,  -295,  -255,-10000000,
-10000000,-10000000,-10000000,  -260,  -272,  -172,  -272,-10000000,-10000000,  -134,
  -202,-10000000,  -273,-10000000,-10000000,-10000000,-10000000,-10000000,-10000000,-10000000,
  -277,  -272,  -245,-10000000,  -300,-10000000,-10000000,-10000000,-10000000,-10000000,
-10000000,  -278,-10000000 };
static YYCONST yytabelem yypgo[]={

     0,   177,   158,   131,   141,   160,   151,   144,   156,   145,
   240,   143,   176,   175,   172,   166,   164,   163,   161,   154,
   153 };
static YYCONST yytabelem yyr1[]={

     0,     1,     1,     3,     3,     2,     2,     2,     2,     4,
     4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
     4,     4,     4,     4,    14,    15,     4,     8,     8,     8,
     8,    10,    10,    10,    10,    10,    10,    10,    10,    10,
    10,    10,    10,    10,    10,     9,     9,    16,    11,    11,
    11,     7,     7,     5,    17,    17,     6,    18,     6,    19,
    19,    19,    12,    12,    20,    20,    20,    20,    20,    20,
    20,    13,    13 };
static YYCONST yytabelem yyr2[]={

     0,     0,     3,     1,     3,     3,     5,     9,    13,     7,
     7,     7,     9,    13,     7,     7,     7,    15,    11,    11,
    15,    11,    13,     7,     1,     1,    19,     3,     3,     3,
     5,     3,     7,     7,     7,     7,     7,     7,     7,     7,
     7,     7,     7,     5,     7,     1,     5,     9,     1,     7,
     3,     3,     7,     3,     1,     5,     3,     1,     9,     5,
     9,     9,     1,     5,     3,     3,     3,     3,     3,     3,
     5,     1,     5 };
static YYCONST yytabelem yychk[]={

-10000000,    -1,    -2,    -4,   287,   298,   286,    -6,   276,   278,
   292,   282,   294,   283,   297,   293,   289,   274,   302,   272,
    -2,    -5,   -17,    -3,    -2,    -5,    -7,    -8,   289,    -5,
   268,   263,   271,   279,    -5,    -5,    -5,   302,    -5,   -10,
    -6,   257,   261,   -10,   302,    -6,   -12,   -18,   265,   268,
    -6,   301,   265,   265,    -5,    -5,   264,   268,   265,   265,
   265,   285,   298,   298,   268,   258,   266,   267,   269,   270,
   259,   260,   299,   300,   285,   -10,   -10,   298,   -11,   302,
    -4,   302,   -20,   296,   295,   284,   291,   290,   281,   288,
   -19,    -6,   289,    -3,    -5,   265,    -8,    -7,    -5,    -9,
   -16,   277,    -3,   -10,   -10,   -10,   -10,   -10,   -10,   -10,
   -10,   -10,   -10,    -5,   262,    -3,   298,   264,   -13,   275,
   302,   273,    -7,    -6,   265,    -5,   298,   301,    -9,   302,
   301,   301,    -3,   -11,   298,    -5,    -6,   292,    -3,   265,
    -3,   264,   280,   301,   -14,    -7,    -5,   301,    -3,    -4,
   303,   -15,   301 };
static YYCONST yytabelem yydef[]={

     1,    -2,     2,     5,    54,     3,    54,    54,    54,    54,
    54,     0,    54,     0,     0,     0,     0,    62,    56,    57,
     6,     0,    53,     0,     4,     0,     0,    54,    54,    51,
    27,    28,    29,     0,     0,     0,     0,     0,     0,     0,
    31,     0,     0,     0,    48,     0,     0,     0,     3,    54,
    55,     9,    10,    11,     0,     0,    54,    30,    14,    15,
    16,    54,    45,     3,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,    54,    43,     0,     3,     0,    50,
    23,    71,    63,    64,    65,    66,    67,    68,    69,     0,
     0,    54,     0,     7,     0,    12,    54,    52,     0,     0,
    45,     0,     0,    32,    33,    34,    35,    36,    37,    38,
    39,    40,    41,    42,    44,     0,     3,    48,     0,    54,
    70,    58,    59,     0,     3,     0,     3,    18,    46,     0,
    19,    21,     0,    49,    24,    72,    54,    54,     8,    13,
     0,     3,     0,    22,     0,    60,    61,    17,    47,    20,
    25,     0,    26 };
typedef struct
#ifdef __cplusplus
	yytoktype
#endif
{
#ifdef __cplusplus
const
#endif
char *t_name; int t_val; } yytoktype;
#ifndef YYDEBUG
#	define YYDEBUG	0	/* don't allow debugging */
#endif

#if YYDEBUG

yytoktype yytoks[] =
{
	"_BANG_t",	257,
	"_BANG_EQUALS_t",	258,
	"_AMPER_t",	259,
	"_AMPERAMPER_t",	260,
	"_LPAREN_t",	261,
	"_RPAREN_t",	262,
	"_PLUS_EQUALS_t",	263,
	"_COLON_t",	264,
	"_SEMIC_t",	265,
	"_LANGLE_t",	266,
	"_LANGLE_EQUALS_t",	267,
	"_EQUALS_t",	268,
	"_RANGLE_t",	269,
	"_RANGLE_EQUALS_t",	270,
	"_QUESTION_EQUALS_t",	271,
	"_LBRACKET_t",	272,
	"_RBRACKET_t",	273,
	"ACTIONS_t",	274,
	"BIND_t",	275,
	"BREAK_t",	276,
	"CASE_t",	277,
	"CONTINUE_t",	278,
	"DEFAULT_t",	279,
	"ELSE_t",	280,
	"EXISTING_t",	281,
	"FOR_t",	282,
	"IF_t",	283,
	"IGNORE_t",	284,
	"IN_t",	285,
	"INCLUDE_t",	286,
	"LOCAL_t",	287,
	"MAXLINE_t",	288,
	"ON_t",	289,
	"PIECEMEAL_t",	290,
	"QUIETLY_t",	291,
	"RETURN_t",	292,
	"RULE_t",	293,
	"SWITCH_t",	294,
	"TOGETHER_t",	295,
	"UPDATED_t",	296,
	"WHILE_t",	297,
	"_LBRACE_t",	298,
	"_BAR_t",	299,
	"_BARBAR_t",	300,
	"_RBRACE_t",	301,
	"ARG",	302,
	"STRING",	303,
	"-unknown-",	-1	/* ends search */
};

#ifdef __cplusplus
const
#endif
char * yyreds[] =
{
	"-no such reduction-",
	"run : /* empty */",
	"run : rules",
	"block : /* empty */",
	"block : rules",
	"rules : rule",
	"rules : rule rules",
	"rules : LOCAL_t list _SEMIC_t block",
	"rules : LOCAL_t list _EQUALS_t list _SEMIC_t block",
	"rule : _LBRACE_t block _RBRACE_t",
	"rule : INCLUDE_t list _SEMIC_t",
	"rule : arg lol _SEMIC_t",
	"rule : arg assign list _SEMIC_t",
	"rule : arg ON_t list assign list _SEMIC_t",
	"rule : BREAK_t list _SEMIC_t",
	"rule : CONTINUE_t list _SEMIC_t",
	"rule : RETURN_t list _SEMIC_t",
	"rule : FOR_t ARG IN_t list _LBRACE_t block _RBRACE_t",
	"rule : SWITCH_t list _LBRACE_t cases _RBRACE_t",
	"rule : IF_t expr _LBRACE_t block _RBRACE_t",
	"rule : IF_t expr _LBRACE_t block _RBRACE_t ELSE_t rule",
	"rule : WHILE_t expr _LBRACE_t block _RBRACE_t",
	"rule : RULE_t ARG params _LBRACE_t block _RBRACE_t",
	"rule : ON_t arg rule",
	"rule : ACTIONS_t eflags ARG bindlist _LBRACE_t",
	"rule : ACTIONS_t eflags ARG bindlist _LBRACE_t STRING",
	"rule : ACTIONS_t eflags ARG bindlist _LBRACE_t STRING _RBRACE_t",
	"assign : _EQUALS_t",
	"assign : _PLUS_EQUALS_t",
	"assign : _QUESTION_EQUALS_t",
	"assign : DEFAULT_t _EQUALS_t",
	"expr : arg",
	"expr : expr _EQUALS_t expr",
	"expr : expr _BANG_EQUALS_t expr",
	"expr : expr _LANGLE_t expr",
	"expr : expr _LANGLE_EQUALS_t expr",
	"expr : expr _RANGLE_t expr",
	"expr : expr _RANGLE_EQUALS_t expr",
	"expr : expr _AMPER_t expr",
	"expr : expr _AMPERAMPER_t expr",
	"expr : expr _BAR_t expr",
	"expr : expr _BARBAR_t expr",
	"expr : arg IN_t list",
	"expr : _BANG_t expr",
	"expr : _LPAREN_t expr _RPAREN_t",
	"cases : /* empty */",
	"cases : case cases",
	"case : CASE_t ARG _COLON_t block",
	"params : /* empty */",
	"params : ARG _COLON_t params",
	"params : ARG",
	"lol : list",
	"lol : list _COLON_t lol",
	"list : listp",
	"listp : /* empty */",
	"listp : listp arg",
	"arg : ARG",
	"arg : _LBRACKET_t",
	"arg : _LBRACKET_t func _RBRACKET_t",
	"func : arg lol",
	"func : ON_t arg arg lol",
	"func : ON_t arg RETURN_t list",
	"eflags : /* empty */",
	"eflags : eflags eflag",
	"eflag : UPDATED_t",
	"eflag : TOGETHER_t",
	"eflag : IGNORE_t",
	"eflag : QUIETLY_t",
	"eflag : PIECEMEAL_t",
	"eflag : EXISTING_t",
	"eflag : MAXLINE_t ARG",
	"bindlist : /* empty */",
	"bindlist : BIND_t list",
};
#endif /* YYDEBUG */
/*
 * CDDL HEADER START
 *
 * The contents of this file are subject to the terms of the
 * Common Development and Distribution License, Version 1.0 only
 * (the "License").  You may not use this file except in compliance
 * with the License.
 *
 * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE
 * or http://www.opensolaris.org/os/licensing.
 * See the License for the specific language governing permissions
 * and limitations under the License.
 *
 * When distributing Covered Code, include this CDDL HEADER in each
 * file and include the License file at usr/src/OPENSOLARIS.LICENSE.
 * If applicable, add the following below this CDDL HEADER, with the
 * fields enclosed by brackets "[]" replaced with your own identifying
 * information: Portions Copyright [yyyy] [name of copyright owner]
 *
 * CDDL HEADER END
 */
/*
 * Copyright 1993 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

/* Copyright (c) 1988 AT&T */
/* All Rights Reserved */

/*	from OpenSolaris "yaccpar	6.18	05/06/08 SMI"	*/

/*
 * Portions Copyright (c) 2005 Gunnar Ritter, Freiburg i. Br., Germany
 *
 * Sccsid @(#)yaccpar	1.5 (gritter) 11/26/05
 */

/*
** Skeleton parser driver for yacc output
*/

/*
** yacc user known macros and defines
*/
#define YYERROR		goto yyerrlab
#define YYACCEPT	return(0)
#define YYABORT		return(1)
#define YYBACKUP( newtoken, newvalue )\
{\
	if ( yychar >= 0 || ( yyr2[ yytmp ] >> 1 ) != 1 )\
	{\
		yyerror( "syntax error - cannot backup" );\
		goto yyerrlab;\
	}\
	yychar = newtoken;\
	yystate = *yyps;\
	yylval = newvalue;\
	goto yynewstate;\
}
#define YYRECOVERING()	(!!yyerrflag)
#define YYNEW(type)	malloc(sizeof(type) * yynewmax)
#define YYCOPY(to, from, type) \
	(type *) memcpy(to, (char *) from, yymaxdepth * sizeof (type))
#define YYENLARGE( from, type) \
	(type *) realloc((char *) from, yynewmax * sizeof(type))
#ifndef YYDEBUG
#	define YYDEBUG	1	/* make debugging available */
#endif

/*
** user known globals
*/
int yydebug;			/* set to 1 to get debugging */

/*
** driver internal defines
*/
#define YYFLAG		(-10000000)

/*
** global variables used by the parser
*/
YYSTYPE *yypv;			/* top of value stack */
int *yyps;			/* top of state stack */

int yystate;			/* current state */
int yytmp;			/* extra var (lasts between blocks) */

int yynerrs;			/* number of errors */
int yyerrflag;			/* error recovery flag */
int yychar;			/* current input token number */



#ifdef YYNMBCHARS
#define YYLEX()		yycvtok(yylex())
/*
** yycvtok - return a token if i is a wchar_t value that exceeds 255.
**	If i<255, i itself is the token.  If i>255 but the neither
**	of the 30th or 31st bit is on, i is already a token.
*/
#if defined(__STDC__) || defined(__cplusplus)
int yycvtok(int i)
#else
int yycvtok(i) int i;
#endif
{
	int first = 0;
	int last = YYNMBCHARS - 1;
	int mid;
	wchar_t j;

	if(i&0x60000000){/*Must convert to a token. */
		if( yymbchars[last].character < i ){
			return i;/*Giving up*/
		}
		while ((last>=first)&&(first>=0)) {/*Binary search loop*/
			mid = (first+last)/2;
			j = yymbchars[mid].character;
			if( j==i ){/*Found*/
				return yymbchars[mid].tvalue;
			}else if( j<i ){
				first = mid + 1;
			}else{
				last = mid -1;
			}
		}
		/*No entry in the table.*/
		return i;/* Giving up.*/
	}else{/* i is already a token. */
		return i;
	}
}
#else/*!YYNMBCHARS*/
#define YYLEX()		yylex()
#endif/*!YYNMBCHARS*/

/*
** yyparse - return 0 if worked, 1 if syntax error not recovered from
*/
#if defined(__STDC__) || defined(__cplusplus)
int yyparse(void)
#else
int yyparse()
#endif
{
	register YYSTYPE *yypvt = 0;	/* top of value stack for $vars */

#if defined(__cplusplus) || defined(lint) || defined(__GNUC__)
/*
	hacks to please C++, lint, and gcc - goto's inside
	switch should never be executed
*/
	static int _yaccpar_lint_hack = -1;
	switch (_yaccpar_lint_hack)
	{
		case 1: goto yyerrlab;
		case 2: goto yynewstate;
	}
#endif

	/*
	** Initialize externals - yyparse may be called more than once
	*/
	yypv = &yyv[-1];
	yyps = &yys[-1];
	yystate = 0;
	yytmp = 0;
	yynerrs = 0;
	yyerrflag = 0;
	yychar = -1;

#if YYMAXDEPTH <= 0
	if (yymaxdepth <= 0)
	{
		if ((yymaxdepth = YYEXPAND(0)) <= 0)
		{
			yyerror("yacc initialization error");
			YYABORT;
		}
	}
#endif

	{
		register YYSTYPE *yy_pv;	/* top of value stack */
		register int *yy_ps;		/* top of state stack */
		register int yy_state;		/* current state */
		register int  yy_n;		/* internal state number info */
	goto yystack;	/* moved from 6 lines above to here to please C++ */

		/*
		** get globals into registers.
		** branch to here only if YYBACKUP was called.
		*/
	yynewstate:
		yy_pv = yypv;
		yy_ps = yyps;
		yy_state = yystate;
		goto yy_newstate;

		/*
		** get globals into registers.
		** either we just started, or we just finished a reduction
		*/
	yystack:
		yy_pv = yypv;
		yy_ps = yyps;
		yy_state = yystate;

		/*
		** top of for (;;) loop while no reductions done
		*/
	yy_stack:
		/*
		** put a state and value onto the stacks
		*/
#if YYDEBUG
		/*
		** if debugging, look up token value in list of value vs.
		** name pairs.  0 and negative (-1) are special values.
		** Note: linear search is used since time is not a real
		** consideration while debugging.
		*/
		if ( yydebug )
		{
			register int yy_i;

			printf( "State %d, token ", yy_state );
			if ( yychar == 0 )
				printf( "end-of-file\n" );
			else if ( yychar < 0 )
				printf( "-none-\n" );
			else
			{
				for ( yy_i = 0; yytoks[yy_i].t_val >= 0;
					yy_i++ )
				{
					if ( yytoks[yy_i].t_val == yychar )
						break;
				}
				printf( "%s\n", yytoks[yy_i].t_name );
			}
		}
#endif /* YYDEBUG */
		if ( ++yy_ps >= &yys[ yymaxdepth ] )	/* room on stack? */
		{
			/*
			** reallocate and recover.  Note that pointers
			** have to be reset, or bad things will happen
			*/
			long yyps_index = (yy_ps - yys);
			long yypv_index = (yy_pv - yyv);
			long yypvt_index = (yypvt - yyv);
			int yynewmax;
#ifdef YYEXPAND
			yynewmax = YYEXPAND(yymaxdepth);
#else
			yynewmax = 2 * yymaxdepth;	/* double table size */
			if (yymaxdepth == YYMAXDEPTH)	/* first time growth */
			{
				char *newyys = (char *)YYNEW(int);
				char *newyyv = (char *)YYNEW(YYSTYPE);
				if (newyys != 0 && newyyv != 0)
				{
					yys = YYCOPY(newyys, yys, int);
					yyv = YYCOPY(newyyv, yyv, YYSTYPE);
				}
				else
					yynewmax = 0;	/* failed */
			}
			else				/* not first time */
			{
				yys = YYENLARGE(yys, int);
				yyv = YYENLARGE(yyv, YYSTYPE);
				if (yys == 0 || yyv == 0)
					yynewmax = 0;	/* failed */
			}
#endif
			if (yynewmax <= yymaxdepth)	/* tables not expanded */
			{
				yyerror( "yacc stack overflow" );
				YYABORT;
			}
			yymaxdepth = yynewmax;

			yy_ps = yys + yyps_index;
			yy_pv = yyv + yypv_index;
			yypvt = yyv + yypvt_index;
		}
		*yy_ps = yy_state;
		*++yy_pv = yyval;

		/*
		** we have a new state - find out what to do
		*/
	yy_newstate:
		if ( ( yy_n = yypact[ yy_state ] ) <= YYFLAG )
			goto yydefault;		/* simple state */
#if YYDEBUG
		/*
		** if debugging, need to mark whether new token grabbed
		*/
		yytmp = yychar < 0;
#endif
		if ( ( yychar < 0 ) && ( ( yychar = YYLEX() ) < 0 ) )
			yychar = 0;		/* reached EOF */
#if YYDEBUG
		if ( yydebug && yytmp )
		{
			register int yy_i;

			printf( "Received token " );
			if ( yychar == 0 )
				printf( "end-of-file\n" );
			else if ( yychar < 0 )
				printf( "-none-\n" );
			else
			{
				for ( yy_i = 0; yytoks[yy_i].t_val >= 0;
					yy_i++ )
				{
					if ( yytoks[yy_i].t_val == yychar )
						break;
				}
				printf( "%s\n", yytoks[yy_i].t_name );
			}
		}
#endif /* YYDEBUG */
		if ( ( ( yy_n += yychar ) < 0 ) || ( yy_n >= YYLAST ) )
			goto yydefault;
		if ( yychk[ yy_n = yyact[ yy_n ] ] == yychar )	/*valid shift*/
		{
			yychar = -1;
			yyval = yylval;
			yy_state = yy_n;
			if ( yyerrflag > 0 )
				yyerrflag--;
			goto yy_stack;
		}

	yydefault:
		if ( ( yy_n = yydef[ yy_state ] ) == -2 )
		{
#if YYDEBUG
			yytmp = yychar < 0;
#endif
			if ( ( yychar < 0 ) && ( ( yychar = YYLEX() ) < 0 ) )
				yychar = 0;		/* reached EOF */
#if YYDEBUG
			if ( yydebug && yytmp )
			{
				register int yy_i;

				printf( "Received token " );
				if ( yychar == 0 )
					printf( "end-of-file\n" );
				else if ( yychar < 0 )
					printf( "-none-\n" );
				else
				{
					for ( yy_i = 0;
						yytoks[yy_i].t_val >= 0;
						yy_i++ )
					{
						if ( yytoks[yy_i].t_val
							== yychar )
						{
							break;
						}
					}
					printf( "%s\n", yytoks[yy_i].t_name );
				}
			}
#endif /* YYDEBUG */
			/*
			** look through exception table
			*/
			{
				register YYCONST int *yyxi = yyexca;

				while ( ( *yyxi != -1 ) ||
					( yyxi[1] != yy_state ) )
				{
					yyxi += 2;
				}
				while ( ( *(yyxi += 2) >= 0 ) &&
					( *yyxi != yychar ) )
					;
				if ( ( yy_n = yyxi[1] ) < 0 )
					YYACCEPT;
			}
		}

		/*
		** check for syntax error
		*/
		if ( yy_n == 0 )	/* have an error */
		{
			/* no worry about speed here! */
			switch ( yyerrflag )
			{
			case 0:		/* new error */
				yyerror( "syntax error" );
				goto skip_init;
			yyerrlab:
				/*
				** get globals into registers.
				** we have a user generated syntax type error
				*/
				yy_pv = yypv;
				yy_ps = yyps;
				yy_state = yystate;
			skip_init:
				yynerrs++;
				/* FALLTHRU */
			case 1:
			case 2:		/* incompletely recovered error */
					/* try again... */
				yyerrflag = 3;
				/*
				** find state where "error" is a legal
				** shift action
				*/
				while ( yy_ps >= yys )
				{
					yy_n = yypact[ *yy_ps ] + YYERRCODE;
					if ( yy_n >= 0 && yy_n < YYLAST &&
						yychk[yyact[yy_n]] == YYERRCODE)					{
						/*
						** simulate shift of "error"
						*/
						yy_state = yyact[ yy_n ];
						goto yy_stack;
					}
					/*
					** current state has no shift on
					** "error", pop stack
					*/
#if YYDEBUG
#	define _POP_ "Error recovery pops state %d, uncovers state %d\n"
					if ( yydebug )
						printf( _POP_, *yy_ps,
							yy_ps[-1] );
#	undef _POP_
#endif
					yy_ps--;
					yy_pv--;
				}
				/*
				** there is no state on stack with "error" as
				** a valid shift.  give up.
				*/
				YYABORT;
			case 3:		/* no shift yet; eat a token */
#if YYDEBUG
				/*
				** if debugging, look up token in list of
				** pairs.  0 and negative shouldn't occur,
				** but since timing doesn't matter when
				** debugging, it doesn't hurt to leave the
				** tests here.
				*/
				if ( yydebug )
				{
					register int yy_i;

					printf( "Error recovery discards " );
					if ( yychar == 0 )
						printf( "token end-of-file\n" );
					else if ( yychar < 0 )
						printf( "token -none-\n" );
					else
					{
						for ( yy_i = 0;
							yytoks[yy_i].t_val >= 0;
							yy_i++ )
						{
							if ( yytoks[yy_i].t_val
								== yychar )
							{
								break;
							}
						}
						printf( "token %s\n",
							yytoks[yy_i].t_name );
					}
				}
#endif /* YYDEBUG */
				if ( yychar == 0 )	/* reached EOF. quit */
					YYABORT;
				yychar = -1;
				goto yy_newstate;
			}
		}/* end if ( yy_n == 0 ) */
		/*
		** reduction by production yy_n
		** put stack tops, etc. so things right after switch
		*/
#if YYDEBUG
		/*
		** if debugging, print the string that is the user's
		** specification of the reduction which is just about
		** to be done.
		*/
		if ( yydebug )
			printf( "Reduce by (%d) \"%s\"\n",
				yy_n, yyreds[ yy_n ] );
#endif
		yytmp = yy_n;			/* value to switch over */
		yypvt = yy_pv;			/* $vars top of value stack */
		/*
		** Look in goto table for next state
		** Sorry about using yy_state here as temporary
		** register variable, but why not, if it works...
		** If yyr2[ yy_n ] doesn't have the low order bit
		** set, then there is no action to be done for
		** this reduction.  So, no saving & unsaving of
		** registers done.  The only difference between the
		** code just after the if and the body of the if is
		** the goto yy_stack in the body.  This way the test
		** can be made before the choice of what to do is needed.
		*/
		{
			/* length of production doubled with extra bit */
			register int yy_len = yyr2[ yy_n ];

			if ( !( yy_len & 01 ) )
			{
				yy_len >>= 1;
				yyval = ( yy_pv -= yy_len )[1];	/* $$ = $1 */
				yy_state = yypgo[ yy_n = yyr1[ yy_n ] ] +
					*( yy_ps -= yy_len ) + 1;
				if ( yy_state >= YYLAST ||
					yychk[ yy_state =
					yyact[ yy_state ] ] != -yy_n )
				{
					yy_state = yyact[ yypgo[ yy_n ] ];
				}
				goto yy_stack;
			}
			yy_len >>= 1;
			yyval = ( yy_pv -= yy_len )[1];	/* $$ = $1 */
			yy_state = yypgo[ yy_n = yyr1[ yy_n ] ] +
				*( yy_ps -= yy_len ) + 1;
			if ( yy_state >= YYLAST ||
				yychk[ yy_state = yyact[ yy_state ] ] != -yy_n )
			{
				yy_state = yyact[ yypgo[ yy_n ] ];
			}
		}
					/* save until reenter driver code */
		yystate = yy_state;
		yyps = yy_ps;
		yypv = yy_pv;
	}
	/*
	** code supplied by user is placed in this switch
	*/
	switch( yytmp )
	{

case 2:{ parse_save( yypvt[-0].parse ); } break;
case 3:{ yyval.parse = pnull(); } break;
case 4:{ yyval.parse = yypvt[-0].parse; } break;
case 5:{ yyval.parse = yypvt[-0].parse; } break;
case 6:{ yyval.parse = prules( yypvt[-1].parse, yypvt[-0].parse ); } break;
case 7:{ yyval.parse = plocal( yypvt[-2].parse, pnull(), yypvt[-0].parse ); } break;
case 8:{ yyval.parse = plocal( yypvt[-4].parse, yypvt[-2].parse, yypvt[-0].parse ); } break;
case 9:{ yyval.parse = yypvt[-1].parse; } break;
case 10:{ yyval.parse = pincl( yypvt[-1].parse ); } break;
case 11:{ yyval.parse = prule( yypvt[-2].parse, yypvt[-1].parse ); } break;
case 12:{ yyval.parse = pset( yypvt[-3].parse, yypvt[-1].parse, yypvt[-2].number ); } break;
case 13:{ yyval.parse = pset1( yypvt[-5].parse, yypvt[-3].parse, yypvt[-1].parse, yypvt[-2].number ); } break;
case 14:{ yyval.parse = pbreak( yypvt[-1].parse, JMP_BREAK ); } break;
case 15:{ yyval.parse = pbreak( yypvt[-1].parse, JMP_CONTINUE ); } break;
case 16:{ yyval.parse = pbreak( yypvt[-1].parse, JMP_RETURN ); } break;
case 17:{ yyval.parse = pfor( yypvt[-5].string, yypvt[-3].parse, yypvt[-1].parse ); } break;
case 18:{ yyval.parse = pswitch( yypvt[-3].parse, yypvt[-1].parse ); } break;
case 19:{ yyval.parse = pif( yypvt[-3].parse, yypvt[-1].parse, pnull() ); } break;
case 20:{ yyval.parse = pif( yypvt[-5].parse, yypvt[-3].parse, yypvt[-0].parse ); } break;
case 21:{ yyval.parse = pwhile( yypvt[-3].parse, yypvt[-1].parse ); } break;
case 22:{ yyval.parse = psetc( yypvt[-4].string, yypvt[-3].parse, yypvt[-1].parse ); } break;
case 23:{ yyval.parse = pon( yypvt[-1].parse, yypvt[-0].parse ); } break;
case 24:{ yymode( SCAN_STRING ); } break;
case 25:{ yymode( SCAN_NORMAL ); } break;
case 26:{ yyval.parse = psete( yypvt[-6].string,yypvt[-5].parse,yypvt[-2].string,yypvt[-7].number ); } break;
case 27:{ yyval.number = VAR_SET; } break;
case 28:{ yyval.number = VAR_APPEND; } break;
case 29:{ yyval.number = VAR_DEFAULT; } break;
case 30:{ yyval.number = VAR_DEFAULT; } break;
case 31:{ yyval.parse = peval( EXPR_EXISTS, yypvt[-0].parse, pnull() ); } break;
case 32:{ yyval.parse = peval( EXPR_EQUALS, yypvt[-2].parse, yypvt[-0].parse ); } break;
case 33:{ yyval.parse = peval( EXPR_NOTEQ, yypvt[-2].parse, yypvt[-0].parse ); } break;
case 34:{ yyval.parse = peval( EXPR_LESS, yypvt[-2].parse, yypvt[-0].parse ); } break;
case 35:{ yyval.parse = peval( EXPR_LESSEQ, yypvt[-2].parse, yypvt[-0].parse ); } break;
case 36:{ yyval.parse = peval( EXPR_MORE, yypvt[-2].parse, yypvt[-0].parse ); } break;
case 37:{ yyval.parse = peval( EXPR_MOREEQ, yypvt[-2].parse, yypvt[-0].parse ); } break;
case 38:{ yyval.parse = peval( EXPR_AND, yypvt[-2].parse, yypvt[-0].parse ); } break;
case 39:{ yyval.parse = peval( EXPR_AND, yypvt[-2].parse, yypvt[-0].parse ); } break;
case 40:{ yyval.parse = peval( EXPR_OR, yypvt[-2].parse, yypvt[-0].parse ); } break;
case 41:{ yyval.parse = peval( EXPR_OR, yypvt[-2].parse, yypvt[-0].parse ); } break;
case 42:{ yyval.parse = peval( EXPR_IN, yypvt[-2].parse, yypvt[-0].parse ); } break;
case 43:{ yyval.parse = peval( EXPR_NOT, yypvt[-0].parse, pnull() ); } break;
case 44:{ yyval.parse = yypvt[-1].parse; } break;
case 45:{ yyval.parse = P0; } break;
case 46:{ yyval.parse = pnode( yypvt[-1].parse, yypvt[-0].parse ); } break;
case 47:{ yyval.parse = psnode( yypvt[-2].string, yypvt[-0].parse ); } break;
case 48:{ yyval.parse = P0; } break;
case 49:{ yyval.parse = psnode( yypvt[-2].string, yypvt[-0].parse ); } break;
case 50:{ yyval.parse = psnode( yypvt[-0].string, P0 ); } break;
case 51:{ yyval.parse = pnode( P0, yypvt[-0].parse ); } break;
case 52:{ yyval.parse = pnode( yypvt[-0].parse, yypvt[-2].parse ); } break;
case 53:{ yyval.parse = yypvt[-0].parse; yymode( SCAN_NORMAL ); } break;
case 54:{ yyval.parse = pnull(); yymode( SCAN_PUNCT ); } break;
case 55:{ yyval.parse = pappend( yypvt[-1].parse, yypvt[-0].parse ); } break;
case 56:{ yyval.parse = plist( yypvt[-0].string ); } break;
case 57:{ yymode( SCAN_NORMAL ); } break;
case 58:{ yyval.parse = yypvt[-1].parse; } break;
case 59:{ yyval.parse = prule( yypvt[-1].parse, yypvt[-0].parse ); } break;
case 60:{ yyval.parse = pon( yypvt[-2].parse, prule( yypvt[-1].parse, yypvt[-0].parse ) ); } break;
case 61:{ yyval.parse = pon( yypvt[-2].parse, yypvt[-0].parse ); } break;
case 62:{ yyval.number = 0; } break;
case 63:{ yyval.number = yypvt[-1].number | yypvt[-0].number; } break;
case 64:{ yyval.number = RULE_UPDATED; } break;
case 65:{ yyval.number = RULE_TOGETHER; } break;
case 66:{ yyval.number = RULE_IGNORE; } break;
case 67:{ yyval.number = RULE_QUIETLY; } break;
case 68:{ yyval.number = RULE_PIECEMEAL; } break;
case 69:{ yyval.number = RULE_EXISTING; } break;
case 70:{ yyval.number = atoi( yypvt[-0].string ) * RULE_MAXLINE; } break;
case 71:{ yyval.parse = pnull(); } break;
case 72:{ yyval.parse = yypvt[-0].parse; } break;
	}
	goto yystack;		/* reset registers in driver code */
}

