/* Attempt to set up a reasonable ANSI C environment. */

#ifndef JAM_ANSI_H
#define JAM_ANSI_H 1

#if defined(_lint)
# include <assert.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# define __STD_C 1
# define EXITFAIL EXIT_FAILURE
# define SIZET_CHR 10
# define sizeT size_t
#else
# include "jam.h"
#endif

/* Attempt to detect whether the compiler is ISO C compatible: */
#ifndef __STD_C
# if defined(__STDC__) || defined(__cplusplus) || defined(c_plusplus)
#  define __STD_C 1
# endif
#endif

#ifdef __STD_C
# ifndef _ARG_
#  define _ARG_(x) x
# endif
# ifndef voidT
#  define voidT void
# endif
#else
# ifndef _ARG_
#  define _ARG_(x) ()
# endif
# if !_ptr_void
#  ifndef voidT
#   define voidT char
#  endif
#  ifndef void
#   define void
#  endif
# endif
# ifndef const
#  define const
#  ifndef NO_CONST
#   define NO_CONST
#  endif
# endif
#endif

#ifndef _BEGIN_EXTERNS_
# if defined(__cplusplus) || defined(c_plusplus)
#  define _BEGIN_EXTERNS_ extern "C" {
#  define _END_EXTERNS_ }
# else
#  define _BEGIN_EXTERNS_
#  define _END_EXTERNS_
# endif
#endif

#ifndef _NIL_
# define _NIL_(x) ((x)0)
#endif

#define mAdd(sum,augend,addend) do {\
    assert((augend)+(addend)>(augend));\
    (sum)=(augend)+(addend);\
    } while(0)

#define mSubtract(difference,minuend,subtrahend) do {\
    assert((minuend)>=(subtrahend));\
    (difference)=(minuend)-(subtrahend);\
    } while(0)

#endif /* JAM_ANSI_H */
