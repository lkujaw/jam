#ifndef JAM_ANSI_H
#define JAM_ANSI_H 1

#include "jam.h"

#if defined(__STDC__) || defined(__cplusplus) || defined(c_plusplus)
# ifndef __STD_C
#  define __STD_C 1
# endif
# ifndef _ARG_
#  define _ARG_(x) x
# endif
# ifndef Void_t
#  define Void_t void
# endif
#else
# ifndef __STD_C
#  define __STD_C 0
# endif
# ifndef _ARG_
#  define _ARG_(x) ()
# endif
# if !_ptr_void
#  ifndef Void_t
#   define Void_t char
#  endif
#  ifndef void
#   define void
#  endif
# endif
# ifndef const
#  define const
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

#endif /* JAM_ANSI_H */
