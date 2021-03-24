/*
 * Copyright 1993, 2000 Christopher Seiwald.
 *
 * This file is part of Jam - see jam.c for Copyright information.
 */

/*
 * parse.h - make and destroy parse trees as driven by the parser
 *
 * 10/22/02 (seiwald) - working return/break/continue statements
 * 11/04/02 (seiwald) - const-ing for string literals
 */

/*
 * parse tree node
 */

#ifndef JAM_PARSE_H
#define JAM_PARSE_H 1

typedef struct _PARSE PARSE;

struct _PARSE {
    LIST       *(*func)PARAM((PARSE *p, LOL *args, int *jmp));
    PARSE        *left;
    PARSE        *right;
    PARSE        *third;
    const char   *string;
    const char   *string1;
    int           num;
    int           refs;
};

BEGIN_EXTERNS

void    parse_file PARAM((const char *f));
void    parse_save PARAM((PARSE *p));

PARSE * parse_make PARAM((
        LIST            *(*func)PARAM((PARSE *p, LOL *args, int *jmp)),
        PARSE           *left,
        PARSE           *right,
        PARSE           *third,
        const char      *string,
        const char      *string1,
        int              num));

void    parse_refer PARAM((PARSE *p));
void    parse_free  PARAM((PARSE *p));

END_EXTERNS

#endif /* JAM_PARSE_H */
