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

typedef struct _PARSE PARSE;

struct _PARSE {
        LIST            *(*func)PROTO(( PARSE *p, LOL *args, int *jmp ));
        PARSE   *left;
        PARSE   *right;
        PARSE   *third;
        const char      *string;
        const char      *string1;
        int     num;
        int     refs;
} ;

void    parse_file PROTO(( const char *f ));
void    parse_save PROTO(( PARSE *p ));

PARSE * parse_make PROTO((
        LIST            *(*func)PROTO(( PARSE *p, LOL *args, int *jmp )),
        PARSE           *left,
        PARSE           *right,
        PARSE           *third,
        const char      *string,
        const char      *string1,
        int              num ));

void    parse_refer PROTO(( PARSE *p ));
void    parse_free  PROTO(( PARSE *p ));
