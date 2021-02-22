/* A Bison parser, made by GNU Bison 3.7.5.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30705

/* Bison version string.  */
#define YYBISON_VERSION "3.7.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 84 "jamgram.y"

#include "jam.h"

#include "lists.h"
#include "variable.h"
#include "parse.h"
#include "scan.h"
#include "compile.h"
#include "newstr.h"
#include "rules.h"

# define YYMAXDEPTH 10000       /* for OSF and other less endowed yaccs */

# define F0 (LIST *(*)(PARSE *, LOL *, int *))0
# define P0 (PARSE *)0
# define S0 (char *)0

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


#line 112 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    _BANG_t = 258,                 /* _BANG_t  */
    _BANG_EQUALS_t = 259,          /* _BANG_EQUALS_t  */
    _AMPER_t = 260,                /* _AMPER_t  */
    _AMPERAMPER_t = 261,           /* _AMPERAMPER_t  */
    _LPAREN_t = 262,               /* _LPAREN_t  */
    _RPAREN_t = 263,               /* _RPAREN_t  */
    _PLUS_EQUALS_t = 264,          /* _PLUS_EQUALS_t  */
    _COLON_t = 265,                /* _COLON_t  */
    _SEMIC_t = 266,                /* _SEMIC_t  */
    _LANGLE_t = 267,               /* _LANGLE_t  */
    _LANGLE_EQUALS_t = 268,        /* _LANGLE_EQUALS_t  */
    _EQUALS_t = 269,               /* _EQUALS_t  */
    _RANGLE_t = 270,               /* _RANGLE_t  */
    _RANGLE_EQUALS_t = 271,        /* _RANGLE_EQUALS_t  */
    _QUESTION_EQUALS_t = 272,      /* _QUESTION_EQUALS_t  */
    _LBRACKET_t = 273,             /* _LBRACKET_t  */
    _RBRACKET_t = 274,             /* _RBRACKET_t  */
    ACTIONS_t = 275,               /* ACTIONS_t  */
    BIND_t = 276,                  /* BIND_t  */
    BREAK_t = 277,                 /* BREAK_t  */
    CASE_t = 278,                  /* CASE_t  */
    CONTINUE_t = 279,              /* CONTINUE_t  */
    DEFAULT_t = 280,               /* DEFAULT_t  */
    ELSE_t = 281,                  /* ELSE_t  */
    EXISTING_t = 282,              /* EXISTING_t  */
    FOR_t = 283,                   /* FOR_t  */
    IF_t = 284,                    /* IF_t  */
    IGNORE_t = 285,                /* IGNORE_t  */
    IN_t = 286,                    /* IN_t  */
    INCLUDE_t = 287,               /* INCLUDE_t  */
    LOCAL_t = 288,                 /* LOCAL_t  */
    MAXLINE_t = 289,               /* MAXLINE_t  */
    ON_t = 290,                    /* ON_t  */
    PIECEMEAL_t = 291,             /* PIECEMEAL_t  */
    QUIETLY_t = 292,               /* QUIETLY_t  */
    RETURN_t = 293,                /* RETURN_t  */
    RULE_t = 294,                  /* RULE_t  */
    SWITCH_t = 295,                /* SWITCH_t  */
    TOGETHER_t = 296,              /* TOGETHER_t  */
    UPDATED_t = 297,               /* UPDATED_t  */
    WHILE_t = 298,                 /* WHILE_t  */
    _LBRACE_t = 299,               /* _LBRACE_t  */
    _BAR_t = 300,                  /* _BAR_t  */
    _BARBAR_t = 301,               /* _BARBAR_t  */
    _RBRACE_t = 302,               /* _RBRACE_t  */
    ARG = 303,                     /* ARG  */
    STRING = 304                   /* STRING  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define _BANG_t 258
#define _BANG_EQUALS_t 259
#define _AMPER_t 260
#define _AMPERAMPER_t 261
#define _LPAREN_t 262
#define _RPAREN_t 263
#define _PLUS_EQUALS_t 264
#define _COLON_t 265
#define _SEMIC_t 266
#define _LANGLE_t 267
#define _LANGLE_EQUALS_t 268
#define _EQUALS_t 269
#define _RANGLE_t 270
#define _RANGLE_EQUALS_t 271
#define _QUESTION_EQUALS_t 272
#define _LBRACKET_t 273
#define _RBRACKET_t 274
#define ACTIONS_t 275
#define BIND_t 276
#define BREAK_t 277
#define CASE_t 278
#define CONTINUE_t 279
#define DEFAULT_t 280
#define ELSE_t 281
#define EXISTING_t 282
#define FOR_t 283
#define IF_t 284
#define IGNORE_t 285
#define IN_t 286
#define INCLUDE_t 287
#define LOCAL_t 288
#define MAXLINE_t 289
#define ON_t 290
#define PIECEMEAL_t 291
#define QUIETLY_t 292
#define RETURN_t 293
#define RULE_t 294
#define SWITCH_t 295
#define TOGETHER_t 296
#define UPDATED_t 297
#define WHILE_t 298
#define _LBRACE_t 299
#define _BAR_t 300
#define _BARBAR_t 301
#define _RBRACE_t 302
#define ARG 303
#define STRING 304

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL__BANG_t = 3,                    /* _BANG_t  */
  YYSYMBOL__BANG_EQUALS_t = 4,             /* _BANG_EQUALS_t  */
  YYSYMBOL__AMPER_t = 5,                   /* _AMPER_t  */
  YYSYMBOL__AMPERAMPER_t = 6,              /* _AMPERAMPER_t  */
  YYSYMBOL__LPAREN_t = 7,                  /* _LPAREN_t  */
  YYSYMBOL__RPAREN_t = 8,                  /* _RPAREN_t  */
  YYSYMBOL__PLUS_EQUALS_t = 9,             /* _PLUS_EQUALS_t  */
  YYSYMBOL__COLON_t = 10,                  /* _COLON_t  */
  YYSYMBOL__SEMIC_t = 11,                  /* _SEMIC_t  */
  YYSYMBOL__LANGLE_t = 12,                 /* _LANGLE_t  */
  YYSYMBOL__LANGLE_EQUALS_t = 13,          /* _LANGLE_EQUALS_t  */
  YYSYMBOL__EQUALS_t = 14,                 /* _EQUALS_t  */
  YYSYMBOL__RANGLE_t = 15,                 /* _RANGLE_t  */
  YYSYMBOL__RANGLE_EQUALS_t = 16,          /* _RANGLE_EQUALS_t  */
  YYSYMBOL__QUESTION_EQUALS_t = 17,        /* _QUESTION_EQUALS_t  */
  YYSYMBOL__LBRACKET_t = 18,               /* _LBRACKET_t  */
  YYSYMBOL__RBRACKET_t = 19,               /* _RBRACKET_t  */
  YYSYMBOL_ACTIONS_t = 20,                 /* ACTIONS_t  */
  YYSYMBOL_BIND_t = 21,                    /* BIND_t  */
  YYSYMBOL_BREAK_t = 22,                   /* BREAK_t  */
  YYSYMBOL_CASE_t = 23,                    /* CASE_t  */
  YYSYMBOL_CONTINUE_t = 24,                /* CONTINUE_t  */
  YYSYMBOL_DEFAULT_t = 25,                 /* DEFAULT_t  */
  YYSYMBOL_ELSE_t = 26,                    /* ELSE_t  */
  YYSYMBOL_EXISTING_t = 27,                /* EXISTING_t  */
  YYSYMBOL_FOR_t = 28,                     /* FOR_t  */
  YYSYMBOL_IF_t = 29,                      /* IF_t  */
  YYSYMBOL_IGNORE_t = 30,                  /* IGNORE_t  */
  YYSYMBOL_IN_t = 31,                      /* IN_t  */
  YYSYMBOL_INCLUDE_t = 32,                 /* INCLUDE_t  */
  YYSYMBOL_LOCAL_t = 33,                   /* LOCAL_t  */
  YYSYMBOL_MAXLINE_t = 34,                 /* MAXLINE_t  */
  YYSYMBOL_ON_t = 35,                      /* ON_t  */
  YYSYMBOL_PIECEMEAL_t = 36,               /* PIECEMEAL_t  */
  YYSYMBOL_QUIETLY_t = 37,                 /* QUIETLY_t  */
  YYSYMBOL_RETURN_t = 38,                  /* RETURN_t  */
  YYSYMBOL_RULE_t = 39,                    /* RULE_t  */
  YYSYMBOL_SWITCH_t = 40,                  /* SWITCH_t  */
  YYSYMBOL_TOGETHER_t = 41,                /* TOGETHER_t  */
  YYSYMBOL_UPDATED_t = 42,                 /* UPDATED_t  */
  YYSYMBOL_WHILE_t = 43,                   /* WHILE_t  */
  YYSYMBOL__LBRACE_t = 44,                 /* _LBRACE_t  */
  YYSYMBOL__BAR_t = 45,                    /* _BAR_t  */
  YYSYMBOL__BARBAR_t = 46,                 /* _BARBAR_t  */
  YYSYMBOL__RBRACE_t = 47,                 /* _RBRACE_t  */
  YYSYMBOL_ARG = 48,                       /* ARG  */
  YYSYMBOL_STRING = 49,                    /* STRING  */
  YYSYMBOL_YYACCEPT = 50,                  /* $accept  */
  YYSYMBOL_run = 51,                       /* run  */
  YYSYMBOL_block = 52,                     /* block  */
  YYSYMBOL_rules = 53,                     /* rules  */
  YYSYMBOL_rule = 54,                      /* rule  */
  YYSYMBOL_55_1 = 55,                      /* $@1  */
  YYSYMBOL_56_2 = 56,                      /* $@2  */
  YYSYMBOL_assign = 57,                    /* assign  */
  YYSYMBOL_expr = 58,                      /* expr  */
  YYSYMBOL_cases = 59,                     /* cases  */
  YYSYMBOL_case = 60,                      /* case  */
  YYSYMBOL_params = 61,                    /* params  */
  YYSYMBOL_lol = 62,                       /* lol  */
  YYSYMBOL_list = 63,                      /* list  */
  YYSYMBOL_listp = 64,                     /* listp  */
  YYSYMBOL_arg = 65,                       /* arg  */
  YYSYMBOL_66_3 = 66,                      /* $@3  */
  YYSYMBOL_func = 67,                      /* func  */
  YYSYMBOL_eflags = 68,                    /* eflags  */
  YYSYMBOL_eflag = 69,                     /* eflag  */
  YYSYMBOL_bindlist = 70                   /* bindlist  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  39
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   255

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  50
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  21
/* YYNRULES -- Number of rules.  */
#define YYNRULES  73
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  154

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   304


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   127,   127,   129,   141,   142,   146,   148,   150,   152,
     156,   158,   160,   162,   164,   166,   168,   170,   172,   174,
     176,   178,   180,   182,   184,   187,   189,   186,   198,   200,
     202,   204,   212,   214,   216,   218,   220,   222,   224,   226,
     228,   230,   232,   234,   236,   238,   249,   250,   254,   264,
     265,   267,   276,   278,   288,   293,   294,   298,   300,   300,
     309,   311,   313,   323,   324,   328,   330,   332,   334,   336,
     338,   340,   350,   351
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "_BANG_t",
  "_BANG_EQUALS_t", "_AMPER_t", "_AMPERAMPER_t", "_LPAREN_t", "_RPAREN_t",
  "_PLUS_EQUALS_t", "_COLON_t", "_SEMIC_t", "_LANGLE_t",
  "_LANGLE_EQUALS_t", "_EQUALS_t", "_RANGLE_t", "_RANGLE_EQUALS_t",
  "_QUESTION_EQUALS_t", "_LBRACKET_t", "_RBRACKET_t", "ACTIONS_t",
  "BIND_t", "BREAK_t", "CASE_t", "CONTINUE_t", "DEFAULT_t", "ELSE_t",
  "EXISTING_t", "FOR_t", "IF_t", "IGNORE_t", "IN_t", "INCLUDE_t",
  "LOCAL_t", "MAXLINE_t", "ON_t", "PIECEMEAL_t", "QUIETLY_t", "RETURN_t",
  "RULE_t", "SWITCH_t", "TOGETHER_t", "UPDATED_t", "WHILE_t", "_LBRACE_t",
  "_BAR_t", "_BARBAR_t", "_RBRACE_t", "ARG", "STRING", "$accept", "run",
  "block", "rules", "rule", "$@1", "$@2", "assign", "expr", "cases",
  "case", "params", "lol", "list", "listp", "arg", "$@3", "func", "eflags",
  "eflag", "bindlist", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304
};
#endif

#define YYPACT_NINF (-59)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     154,   -59,   -59,   -59,   -59,   -32,     8,   -59,   -59,    -6,
     -59,    -7,   -59,     8,   154,   -59,    46,   -59,   154,    49,
     -14,   200,    37,    -6,    40,    21,     8,     8,   120,    22,
      43,    19,   185,    58,     9,    26,   135,    25,   -59,   -59,
     -59,   -59,   -59,   -59,    63,   -59,   -59,    67,    71,    -6,
     -59,    66,   -59,   -59,    38,   -59,   -59,   -59,   -59,    61,
     -59,   -59,   -59,   -59,   -59,   -59,   155,     8,     8,     8,
       8,     8,     8,     8,     8,   154,     8,     8,   -59,   -59,
     154,   -59,   -59,   -59,    79,    47,    69,   154,   -59,   -59,
      10,    82,   -59,   -59,     7,   -59,   -59,   -59,   -59,    51,
      53,   -59,    52,    24,    24,   -59,   -59,    52,   -59,   -59,
      62,   239,   239,   -59,   -59,    87,     9,   154,    42,    65,
      69,    68,   -59,   -59,   -59,   -59,   -59,   -59,   -59,   154,
      73,   154,   -59,    72,    90,   -59,   -59,   -59,   102,   -59,
     -59,    78,    74,   185,   -59,   -59,   154,   -59,   -59,   -59,
     -59,   -59,    75,   -59
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,    58,    63,    55,    55,     0,     0,    55,    55,     0,
      55,     0,    55,     0,     4,    57,     0,     3,     6,    55,
       0,     0,     0,    54,     0,     0,     0,     0,     0,    32,
       0,     0,     0,     0,    49,     0,     0,     0,     5,     1,
       7,    29,    28,    30,     0,    55,    55,     0,    52,     0,
      55,     0,    70,    67,     0,    69,    68,    66,    65,    72,
      64,    15,    56,    16,    55,    44,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     4,     0,     0,    55,    11,
       4,    55,    24,    17,    51,     0,    46,     4,    10,    31,
       0,     0,    12,    55,     0,    60,    59,    71,    55,     0,
       0,    45,    34,    39,    40,    35,    36,    33,    37,    38,
       0,    41,    42,    43,     8,     0,    49,     4,     0,     0,
      46,     0,    55,    13,    53,    55,    55,    73,    25,     4,
      20,     4,    50,     0,     0,    19,    47,    22,     0,    62,
      61,     0,     0,     0,     9,    23,     4,    14,    26,    18,
      21,    48,     0,    27
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -59,   -59,   -58,    13,   -29,   -59,   -59,    28,    34,    -4,
     -59,    12,   -43,    -2,   -59,     0,   -59,   -59,   -59,   -59,
     -59
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    16,    37,    38,    18,   141,   152,    46,    28,   119,
     120,    85,    47,    48,    23,    29,    20,    51,    21,    60,
      99
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      19,    22,    24,    82,     1,    30,    31,    95,    33,    32,
      35,    26,     1,    17,    19,    27,    25,   110,    19,    41,
      50,    49,   114,    62,    42,     1,     1,    43,    67,   121,
      80,    40,    19,    81,    15,    44,    70,    71,    72,    73,
      74,    34,    15,    90,    91,   125,    39,    36,    61,    94,
     124,    63,    64,    78,    79,    15,    15,    84,    41,   133,
      65,    66,   100,    42,    70,    71,    43,    73,    74,    83,
      86,   142,    88,   144,    44,    19,   113,    89,    92,   115,
      19,    93,    98,   140,    45,    96,    97,    19,   151,   116,
     134,   117,   118,   123,   126,   128,   127,   129,   131,   143,
     146,   102,   103,   104,   105,   106,   107,   108,   109,   130,
     111,   112,   135,   147,   150,   137,   136,    19,   122,   145,
     138,   149,   153,   139,    67,    68,    69,   148,   132,    19,
       0,    19,    70,    71,    72,    73,    74,     0,     0,    67,
      68,    69,     0,    19,     0,     0,    19,    70,    71,    72,
      73,    74,     0,     0,     0,     0,     0,     0,     0,    67,
      68,    69,     0,   101,    75,    76,    77,    70,    71,    72,
      73,    74,     1,     0,     2,     0,     3,     0,     4,    87,
      76,    77,     5,     6,     0,     0,     7,     8,     0,     9,
       0,     0,    10,    11,    12,     0,     0,    13,    14,     0,
      76,    77,    15,     1,     0,     2,     0,     3,     0,     4,
       0,     0,     0,     5,     6,     0,     0,     7,     0,     0,
       9,     0,     0,    10,    11,    12,     0,    52,    13,    14,
      53,     0,     0,    15,    54,     0,    55,    56,     0,     0,
       0,    57,    58,    67,    68,    69,     0,     0,    59,     0,
       0,    70,    71,    72,    73,    74
};

static const yytype_int16 yycheck[] =
{
       0,     3,     4,    32,    18,     7,     8,    50,    10,     9,
      12,     3,    18,     0,    14,     7,    48,    75,    18,     9,
      20,    35,    80,    23,    14,    18,    18,    17,     4,    87,
      11,    18,    32,    14,    48,    25,    12,    13,    14,    15,
      16,    48,    48,    45,    46,    38,     0,    13,    11,    49,
      93,    11,    31,    31,    11,    48,    48,    48,     9,   117,
      26,    27,    64,    14,    12,    13,    17,    15,    16,    11,
      44,   129,    47,   131,    25,    75,    78,    14,    11,    81,
      80,    10,    21,   126,    35,    19,    48,    87,   146,    10,
      48,    44,    23,    11,    94,    44,    98,    44,    11,    26,
      10,    67,    68,    69,    70,    71,    72,    73,    74,    47,
      76,    77,    47,    11,   143,    47,   120,   117,    90,    47,
     122,    47,    47,   125,     4,     5,     6,    49,   116,   129,
      -1,   131,    12,    13,    14,    15,    16,    -1,    -1,     4,
       5,     6,    -1,   143,    -1,    -1,   146,    12,    13,    14,
      15,    16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     4,
       5,     6,    -1,     8,    44,    45,    46,    12,    13,    14,
      15,    16,    18,    -1,    20,    -1,    22,    -1,    24,    44,
      45,    46,    28,    29,    -1,    -1,    32,    33,    -1,    35,
      -1,    -1,    38,    39,    40,    -1,    -1,    43,    44,    -1,
      45,    46,    48,    18,    -1,    20,    -1,    22,    -1,    24,
      -1,    -1,    -1,    28,    29,    -1,    -1,    32,    -1,    -1,
      35,    -1,    -1,    38,    39,    40,    -1,    27,    43,    44,
      30,    -1,    -1,    48,    34,    -1,    36,    37,    -1,    -1,
      -1,    41,    42,     4,     5,     6,    -1,    -1,    48,    -1,
      -1,    12,    13,    14,    15,    16
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    18,    20,    22,    24,    28,    29,    32,    33,    35,
      38,    39,    40,    43,    44,    48,    51,    53,    54,    65,
      66,    68,    63,    64,    63,    48,     3,     7,    58,    65,
      63,    63,    65,    63,    48,    63,    58,    52,    53,     0,
      53,     9,    14,    17,    25,    35,    57,    62,    63,    35,
      65,    67,    27,    30,    34,    36,    37,    41,    42,    48,
      69,    11,    65,    11,    31,    58,    58,     4,     5,     6,
      12,    13,    14,    15,    16,    44,    45,    46,    31,    11,
      11,    14,    54,    11,    48,    61,    44,    44,    47,    14,
      63,    63,    11,    10,    65,    62,    19,    48,    21,    70,
      63,     8,    58,    58,    58,    58,    58,    58,    58,    58,
      52,    58,    58,    63,    52,    63,    10,    44,    23,    59,
      60,    52,    57,    11,    62,    38,    65,    63,    44,    44,
      47,    11,    61,    52,    48,    47,    59,    47,    63,    63,
      62,    55,    52,    26,    52,    47,    10,    11,    49,    47,
      54,    52,    56,    47
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    50,    51,    51,    52,    52,    53,    53,    53,    53,
      54,    54,    54,    54,    54,    54,    54,    54,    54,    54,
      54,    54,    54,    54,    54,    55,    56,    54,    57,    57,
      57,    57,    58,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    58,    59,    59,    60,    61,
      61,    61,    62,    62,    63,    64,    64,    65,    66,    65,
      67,    67,    67,    68,    68,    69,    69,    69,    69,    69,
      69,    69,    70,    70
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     1,     0,     1,     1,     2,     4,     6,
       3,     3,     3,     4,     6,     3,     3,     3,     7,     5,
       5,     7,     5,     6,     3,     0,     0,     9,     1,     1,
       1,     2,     1,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     3,     0,     2,     4,     0,
       3,     1,     1,     3,     1,     0,     2,     1,     0,     4,
       2,     4,     4,     0,     2,     1,     1,     1,     1,     1,
       1,     2,     0,     2
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 3: /* run: rules  */
#line 130 "jamgram.y"
                { parse_save( yyvsp[0].parse ); }
#line 1438 "y.tab.c"
    break;

  case 4: /* block: %empty  */
#line 141 "jamgram.y"
                { yyval.parse = pnull(); }
#line 1444 "y.tab.c"
    break;

  case 5: /* block: rules  */
#line 143 "jamgram.y"
                { yyval.parse = yyvsp[0].parse; }
#line 1450 "y.tab.c"
    break;

  case 6: /* rules: rule  */
#line 147 "jamgram.y"
                { yyval.parse = yyvsp[0].parse; }
#line 1456 "y.tab.c"
    break;

  case 7: /* rules: rule rules  */
#line 149 "jamgram.y"
                { yyval.parse = prules( yyvsp[-1].parse, yyvsp[0].parse ); }
#line 1462 "y.tab.c"
    break;

  case 8: /* rules: LOCAL_t list _SEMIC_t block  */
#line 151 "jamgram.y"
                { yyval.parse = plocal( yyvsp[-2].parse, pnull(), yyvsp[0].parse ); }
#line 1468 "y.tab.c"
    break;

  case 9: /* rules: LOCAL_t list _EQUALS_t list _SEMIC_t block  */
#line 153 "jamgram.y"
                { yyval.parse = plocal( yyvsp[-4].parse, yyvsp[-2].parse, yyvsp[0].parse ); }
#line 1474 "y.tab.c"
    break;

  case 10: /* rule: _LBRACE_t block _RBRACE_t  */
#line 157 "jamgram.y"
                { yyval.parse = yyvsp[-1].parse; }
#line 1480 "y.tab.c"
    break;

  case 11: /* rule: INCLUDE_t list _SEMIC_t  */
#line 159 "jamgram.y"
                { yyval.parse = pincl( yyvsp[-1].parse ); }
#line 1486 "y.tab.c"
    break;

  case 12: /* rule: arg lol _SEMIC_t  */
#line 161 "jamgram.y"
                { yyval.parse = prule( yyvsp[-2].parse, yyvsp[-1].parse ); }
#line 1492 "y.tab.c"
    break;

  case 13: /* rule: arg assign list _SEMIC_t  */
#line 163 "jamgram.y"
                { yyval.parse = pset( yyvsp[-3].parse, yyvsp[-1].parse, yyvsp[-2].number ); }
#line 1498 "y.tab.c"
    break;

  case 14: /* rule: arg ON_t list assign list _SEMIC_t  */
#line 165 "jamgram.y"
                { yyval.parse = pset1( yyvsp[-5].parse, yyvsp[-3].parse, yyvsp[-1].parse, yyvsp[-2].number ); }
#line 1504 "y.tab.c"
    break;

  case 15: /* rule: BREAK_t list _SEMIC_t  */
#line 167 "jamgram.y"
                { yyval.parse = pbreak( yyvsp[-1].parse, JMP_BREAK ); }
#line 1510 "y.tab.c"
    break;

  case 16: /* rule: CONTINUE_t list _SEMIC_t  */
#line 169 "jamgram.y"
                { yyval.parse = pbreak( yyvsp[-1].parse, JMP_CONTINUE ); }
#line 1516 "y.tab.c"
    break;

  case 17: /* rule: RETURN_t list _SEMIC_t  */
#line 171 "jamgram.y"
                { yyval.parse = pbreak( yyvsp[-1].parse, JMP_RETURN ); }
#line 1522 "y.tab.c"
    break;

  case 18: /* rule: FOR_t ARG IN_t list _LBRACE_t block _RBRACE_t  */
#line 173 "jamgram.y"
                { yyval.parse = pfor( yyvsp[-5].string, yyvsp[-3].parse, yyvsp[-1].parse ); }
#line 1528 "y.tab.c"
    break;

  case 19: /* rule: SWITCH_t list _LBRACE_t cases _RBRACE_t  */
#line 175 "jamgram.y"
                { yyval.parse = pswitch( yyvsp[-3].parse, yyvsp[-1].parse ); }
#line 1534 "y.tab.c"
    break;

  case 20: /* rule: IF_t expr _LBRACE_t block _RBRACE_t  */
#line 177 "jamgram.y"
                { yyval.parse = pif( yyvsp[-3].parse, yyvsp[-1].parse, pnull() ); }
#line 1540 "y.tab.c"
    break;

  case 21: /* rule: IF_t expr _LBRACE_t block _RBRACE_t ELSE_t rule  */
#line 179 "jamgram.y"
                { yyval.parse = pif( yyvsp[-5].parse, yyvsp[-3].parse, yyvsp[0].parse ); }
#line 1546 "y.tab.c"
    break;

  case 22: /* rule: WHILE_t expr _LBRACE_t block _RBRACE_t  */
#line 181 "jamgram.y"
                { yyval.parse = pwhile( yyvsp[-3].parse, yyvsp[-1].parse ); }
#line 1552 "y.tab.c"
    break;

  case 23: /* rule: RULE_t ARG params _LBRACE_t block _RBRACE_t  */
#line 183 "jamgram.y"
                { yyval.parse = psetc( yyvsp[-4].string, yyvsp[-3].parse, yyvsp[-1].parse ); }
#line 1558 "y.tab.c"
    break;

  case 24: /* rule: ON_t arg rule  */
#line 185 "jamgram.y"
                { yyval.parse = pon( yyvsp[-1].parse, yyvsp[0].parse ); }
#line 1564 "y.tab.c"
    break;

  case 25: /* $@1: %empty  */
#line 187 "jamgram.y"
                { yymode( SCAN_STRING ); }
#line 1570 "y.tab.c"
    break;

  case 26: /* $@2: %empty  */
#line 189 "jamgram.y"
                { yymode( SCAN_NORMAL ); }
#line 1576 "y.tab.c"
    break;

  case 27: /* rule: ACTIONS_t eflags ARG bindlist _LBRACE_t $@1 STRING $@2 _RBRACE_t  */
#line 191 "jamgram.y"
                { yyval.parse = psete( yyvsp[-6].string,yyvsp[-5].parse,yyvsp[-2].string,yyvsp[-7].number ); }
#line 1582 "y.tab.c"
    break;

  case 28: /* assign: _EQUALS_t  */
#line 199 "jamgram.y"
                { yyval.number = VAR_SET; }
#line 1588 "y.tab.c"
    break;

  case 29: /* assign: _PLUS_EQUALS_t  */
#line 201 "jamgram.y"
                { yyval.number = VAR_APPEND; }
#line 1594 "y.tab.c"
    break;

  case 30: /* assign: _QUESTION_EQUALS_t  */
#line 203 "jamgram.y"
                { yyval.number = VAR_DEFAULT; }
#line 1600 "y.tab.c"
    break;

  case 31: /* assign: DEFAULT_t _EQUALS_t  */
#line 205 "jamgram.y"
                { yyval.number = VAR_DEFAULT; }
#line 1606 "y.tab.c"
    break;

  case 32: /* expr: arg  */
#line 213 "jamgram.y"
                { yyval.parse = peval( EXPR_EXISTS, yyvsp[0].parse, pnull() ); }
#line 1612 "y.tab.c"
    break;

  case 33: /* expr: expr _EQUALS_t expr  */
#line 215 "jamgram.y"
                { yyval.parse = peval( EXPR_EQUALS, yyvsp[-2].parse, yyvsp[0].parse ); }
#line 1618 "y.tab.c"
    break;

  case 34: /* expr: expr _BANG_EQUALS_t expr  */
#line 217 "jamgram.y"
                { yyval.parse = peval( EXPR_NOTEQ, yyvsp[-2].parse, yyvsp[0].parse ); }
#line 1624 "y.tab.c"
    break;

  case 35: /* expr: expr _LANGLE_t expr  */
#line 219 "jamgram.y"
                { yyval.parse = peval( EXPR_LESS, yyvsp[-2].parse, yyvsp[0].parse ); }
#line 1630 "y.tab.c"
    break;

  case 36: /* expr: expr _LANGLE_EQUALS_t expr  */
#line 221 "jamgram.y"
                { yyval.parse = peval( EXPR_LESSEQ, yyvsp[-2].parse, yyvsp[0].parse ); }
#line 1636 "y.tab.c"
    break;

  case 37: /* expr: expr _RANGLE_t expr  */
#line 223 "jamgram.y"
                { yyval.parse = peval( EXPR_MORE, yyvsp[-2].parse, yyvsp[0].parse ); }
#line 1642 "y.tab.c"
    break;

  case 38: /* expr: expr _RANGLE_EQUALS_t expr  */
#line 225 "jamgram.y"
                { yyval.parse = peval( EXPR_MOREEQ, yyvsp[-2].parse, yyvsp[0].parse ); }
#line 1648 "y.tab.c"
    break;

  case 39: /* expr: expr _AMPER_t expr  */
#line 227 "jamgram.y"
                { yyval.parse = peval( EXPR_AND, yyvsp[-2].parse, yyvsp[0].parse ); }
#line 1654 "y.tab.c"
    break;

  case 40: /* expr: expr _AMPERAMPER_t expr  */
#line 229 "jamgram.y"
                { yyval.parse = peval( EXPR_AND, yyvsp[-2].parse, yyvsp[0].parse ); }
#line 1660 "y.tab.c"
    break;

  case 41: /* expr: expr _BAR_t expr  */
#line 231 "jamgram.y"
                { yyval.parse = peval( EXPR_OR, yyvsp[-2].parse, yyvsp[0].parse ); }
#line 1666 "y.tab.c"
    break;

  case 42: /* expr: expr _BARBAR_t expr  */
#line 233 "jamgram.y"
                { yyval.parse = peval( EXPR_OR, yyvsp[-2].parse, yyvsp[0].parse ); }
#line 1672 "y.tab.c"
    break;

  case 43: /* expr: arg IN_t list  */
#line 235 "jamgram.y"
                { yyval.parse = peval( EXPR_IN, yyvsp[-2].parse, yyvsp[0].parse ); }
#line 1678 "y.tab.c"
    break;

  case 44: /* expr: _BANG_t expr  */
#line 237 "jamgram.y"
                { yyval.parse = peval( EXPR_NOT, yyvsp[0].parse, pnull() ); }
#line 1684 "y.tab.c"
    break;

  case 45: /* expr: _LPAREN_t expr _RPAREN_t  */
#line 239 "jamgram.y"
                { yyval.parse = yyvsp[-1].parse; }
#line 1690 "y.tab.c"
    break;

  case 46: /* cases: %empty  */
#line 249 "jamgram.y"
                { yyval.parse = P0; }
#line 1696 "y.tab.c"
    break;

  case 47: /* cases: case cases  */
#line 251 "jamgram.y"
                { yyval.parse = pnode( yyvsp[-1].parse, yyvsp[0].parse ); }
#line 1702 "y.tab.c"
    break;

  case 48: /* case: CASE_t ARG _COLON_t block  */
#line 255 "jamgram.y"
                { yyval.parse = psnode( yyvsp[-2].string, yyvsp[0].parse ); }
#line 1708 "y.tab.c"
    break;

  case 49: /* params: %empty  */
#line 264 "jamgram.y"
                { yyval.parse = P0; }
#line 1714 "y.tab.c"
    break;

  case 50: /* params: ARG _COLON_t params  */
#line 266 "jamgram.y"
                { yyval.parse = psnode( yyvsp[-2].string, yyvsp[0].parse ); }
#line 1720 "y.tab.c"
    break;

  case 51: /* params: ARG  */
#line 268 "jamgram.y"
                { yyval.parse = psnode( yyvsp[0].string, P0 ); }
#line 1726 "y.tab.c"
    break;

  case 52: /* lol: list  */
#line 277 "jamgram.y"
                { yyval.parse = pnode( P0, yyvsp[0].parse ); }
#line 1732 "y.tab.c"
    break;

  case 53: /* lol: list _COLON_t lol  */
#line 279 "jamgram.y"
                { yyval.parse = pnode( yyvsp[0].parse, yyvsp[-2].parse ); }
#line 1738 "y.tab.c"
    break;

  case 54: /* list: listp  */
#line 289 "jamgram.y"
                { yyval.parse = yyvsp[0].parse; yymode( SCAN_NORMAL ); }
#line 1744 "y.tab.c"
    break;

  case 55: /* listp: %empty  */
#line 293 "jamgram.y"
                { yyval.parse = pnull(); yymode( SCAN_PUNCT ); }
#line 1750 "y.tab.c"
    break;

  case 56: /* listp: listp arg  */
#line 295 "jamgram.y"
                { yyval.parse = pappend( yyvsp[-1].parse, yyvsp[0].parse ); }
#line 1756 "y.tab.c"
    break;

  case 57: /* arg: ARG  */
#line 299 "jamgram.y"
                { yyval.parse = plist( yyvsp[0].string ); }
#line 1762 "y.tab.c"
    break;

  case 58: /* $@3: %empty  */
#line 300 "jamgram.y"
                      { yymode( SCAN_NORMAL ); }
#line 1768 "y.tab.c"
    break;

  case 59: /* arg: _LBRACKET_t $@3 func _RBRACKET_t  */
#line 301 "jamgram.y"
                { yyval.parse = yyvsp[-1].parse; }
#line 1774 "y.tab.c"
    break;

  case 60: /* func: arg lol  */
#line 310 "jamgram.y"
                { yyval.parse = prule( yyvsp[-1].parse, yyvsp[0].parse ); }
#line 1780 "y.tab.c"
    break;

  case 61: /* func: ON_t arg arg lol  */
#line 312 "jamgram.y"
                { yyval.parse = pon( yyvsp[-2].parse, prule( yyvsp[-1].parse, yyvsp[0].parse ) ); }
#line 1786 "y.tab.c"
    break;

  case 62: /* func: ON_t arg RETURN_t list  */
#line 314 "jamgram.y"
                { yyval.parse = pon( yyvsp[-2].parse, yyvsp[0].parse ); }
#line 1792 "y.tab.c"
    break;

  case 63: /* eflags: %empty  */
#line 323 "jamgram.y"
                { yyval.number = 0; }
#line 1798 "y.tab.c"
    break;

  case 64: /* eflags: eflags eflag  */
#line 325 "jamgram.y"
                { yyval.number = yyvsp[-1].number | yyvsp[0].number; }
#line 1804 "y.tab.c"
    break;

  case 65: /* eflag: UPDATED_t  */
#line 329 "jamgram.y"
                { yyval.number = RULE_UPDATED; }
#line 1810 "y.tab.c"
    break;

  case 66: /* eflag: TOGETHER_t  */
#line 331 "jamgram.y"
                { yyval.number = RULE_TOGETHER; }
#line 1816 "y.tab.c"
    break;

  case 67: /* eflag: IGNORE_t  */
#line 333 "jamgram.y"
                { yyval.number = RULE_IGNORE; }
#line 1822 "y.tab.c"
    break;

  case 68: /* eflag: QUIETLY_t  */
#line 335 "jamgram.y"
                { yyval.number = RULE_QUIETLY; }
#line 1828 "y.tab.c"
    break;

  case 69: /* eflag: PIECEMEAL_t  */
#line 337 "jamgram.y"
                { yyval.number = RULE_PIECEMEAL; }
#line 1834 "y.tab.c"
    break;

  case 70: /* eflag: EXISTING_t  */
#line 339 "jamgram.y"
                { yyval.number = RULE_EXISTING; }
#line 1840 "y.tab.c"
    break;

  case 71: /* eflag: MAXLINE_t ARG  */
#line 341 "jamgram.y"
                { yyval.number = atoi( yyvsp[0].string ) * RULE_MAXLINE; }
#line 1846 "y.tab.c"
    break;

  case 72: /* bindlist: %empty  */
#line 350 "jamgram.y"
                { yyval.parse = pnull(); }
#line 1852 "y.tab.c"
    break;

  case 73: /* bindlist: BIND_t list  */
#line 352 "jamgram.y"
                { yyval.parse = yyvsp[0].parse; }
#line 1858 "y.tab.c"
    break;


#line 1862 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

