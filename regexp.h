/*
 * Definitions etc. for regexp(3) routines.
 *
 * Caveat:  this is V8 regexp(3) [actually, a reimplementation thereof],
 * not the System V one.
 *
 * 11/04/02 (seiwald) - const-ing for string literals
 */

#ifndef REGEXP_H
#define REGEXP_H

#include "ansi.h"

#define NSUBEXP  10
typedef struct regexp {
    const char *startp[NSUBEXP];
    const char *endp[NSUBEXP];
    char  regstart;         /* Internal use only. */
    char  reganch;          /* Internal use only. */
    char *regmust;          /* Internal use only. */
    int   regmlen;          /* Internal use only. */
    char  program[1];       /* Unwarranted chumminess with compiler. */
} regexp;

regexp *regcomp PROTO(( const char *exp ));
int     regexec PROTO(( regexp *prog, const char *string ));
void   regerror PROTO(( const char *s ));

/*
 * The first byte of the regexp internal "program" is actually this magic
 * number; the start node begins in the second byte.
 */
#define MAGIC   0234

#endif /* REGEXP_H */
