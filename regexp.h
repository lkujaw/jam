/*
 * Definitions etc. for regexp(3) routines.
 *
 * Caveat:  this is V8 regexp(3) [actually, a reimplementation thereof],
 * not the System V one.
 *
 * 11/04/02 (seiwald) - const-ing for string literals
 */

#ifndef JAM_REGEXP_H
#define JAM_REGEXP_H 1

#include "ansi.h"

#define NSUBEXP  10

/*
 * The first byte of the regexp internal "program" is actually this magic
 * number; the start node begins in the second byte.
 */
#define MAGIC   0234

typedef struct regexp {
    const char *startp[NSUBEXP];
    const char *endp[NSUBEXP];
    char  regstart;         /* Internal use only. */
    char  reganch;          /* Internal use only. */
    char *regmust;          /* Internal use only. */
    int   regmlen;          /* Internal use only. */
    char  program[1];       /* Unwarranted chumminess with compiler. */
} regexp;

_BEGIN_EXTERNS_

regexp *regcomp  _ARG_((const char *exp));
int     regexec  _ARG_((regexp *prog, const char *string));
void    regerror _ARG_((const char *s));

_END_EXTERNS_

#endif /* JAM_REGEXP_H */
