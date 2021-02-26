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
    LIST       *(*func)_ARG_((PARSE *p, LOL *args, int *jmp));
    PARSE        *left;
    PARSE        *right;
    PARSE        *third;
    const char   *string;
    const char   *string1;
    int           num;
    int           refs;
};

_BEGIN_EXTERNS_

void    parse_file _ARG_((const char *f));
void    parse_save _ARG_((PARSE *p));

PARSE * parse_make _ARG_((
        LIST            *(*func)_ARG_((PARSE *p, LOL *args, int *jmp)),
        PARSE           *left,
        PARSE           *right,
        PARSE           *third,
        const char      *string,
        const char      *string1,
        int              num ));

void    parse_refer _ARG_((PARSE *p));
void    parse_free  _ARG_((PARSE *p));

_END_EXTERNS_

#endif /* JAM_PARSE_H */
