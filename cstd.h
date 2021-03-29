/* CSTD.H
 *
 * Creates a C environment that tries its best to smooth out the
 * various incompatibilities between traditional K&R and ISO C compilers.
 */

#ifndef JAM_CSTD_H
#define JAM_CSTD_H 1

#if defined(_lint)
# include <assert.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# define CSTD 1
# define EXITFAIL EXIT_FAILURE
# define SIZET_CHR 10
# define sizeT size_t
#else
# include "jam.h"
#endif

/* Attempt to detect whether the compiler is ISO C compatible. */
#if !defined(CSTD) && !defined(TRADALL)
# if defined(__STDC__) || defined(__cplusplus) || defined(c_plusplus)
#  define CSTD 1
# endif
#endif

/* Remove function prototypes in K&R environments. */
#if defined(CSTD)
# define PARAM(x) x
#else
# define PARAM(x) ()
#endif

/* Rework function definitions for either ISO or K&R compatibility. */
/* TRADFDEF is useful for running GCC with -Wtraditional. */
#if defined(CSTD) && !defined(TRADFDEF)
# define NULLARY (void)
# define DECLARE(x) (
# define NP ,
# define EP )
#else
# define NULLARY ()
# define DECLARE(x) x
# define NP ;
# define EP ;
#endif

#if defined(CSTD)
# ifndef UNUSED
#  define UNUSED(x) (void)(x)
# endif
# ifndef voidT
#  define voidT void
# endif
#else
# ifndef UNUSED
#  define UNUSED(x) (x)
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

#define BEGIN {
#define END_FUNCTION(x) }

#ifndef BEGIN_EXTERNS
# if defined(__cplusplus) || defined(c_plusplus)
#  define BEGIN_EXTERNS extern "C" {
#  define END_EXTERNS }
# else
#  define BEGIN_EXTERNS
#  define END_EXTERNS
# endif
#endif

#ifndef FOREVER
# define FOREVER while(TRUE)
#endif

#ifndef NIL
# define NIL(x) ((x)0)
#endif

#define mAdd(sum,augend,addend) do {\
    assert((augend)+(addend)>(augend));\
    (sum)=(augend)+(addend);\
    } while(0)

#define mSubtract(difference,minuend,subtrahend) do {\
    assert((minuend)>=(subtrahend));\
    (difference)=(minuend)-(subtrahend);\
    } while(0)

#endif /* JAM_CSTD_H */
