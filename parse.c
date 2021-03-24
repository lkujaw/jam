/*
 * parse.c - make and destroy parse trees as driven by the parser
 *
 * 09/07/00 (seiwald) - ref count on PARSE to avoid freeing when used,
 *              as per Matt Armstrong.
 * 09/11/00 (seiwald) - structure reworked to reflect that (*func)()
 *              returns a LIST *.
 * 10/22/02 (seiwald) - working return/break/continue statements
 * 11/04/02 (seiwald) - const-ing for string literals
 */

#include "jam.h"  /* Includes system headers */

#include "bool.h"
#include "lists.h"
#include "parse.h"
#include "scan.h"
#include "str.h"
#include "xmem.h"

static PARSE *yypsave;

void
parse_file DECLARE((f))
    const char  *f  EP
BEGIN
    /* Suspend scan of current file */
    /* and push this new file in the stream */
    yyfparse(f);

    /* Now parse each block of rules and execute it. */
    /* Execute it outside of the parser so that recursive */
    /* calls to yyrun() work (no recursive yyparse's). */

    while(TRUE) {
        LOL     l;
        PARSE  *p;
        int     jmp = 0; /* JMP_NONE */

        /* $(<) and $(>) empty in outer scope. */
        lol_init(&l);

        /* Filled by yyparse() calling parse_save() */
        yypsave = 0;

        /* If parse error or empty parse, outta here */
        if(yyparse() || !(p = yypsave)) {
            break;
        }

        /* Run the parse tree. */
        list_free((*(p->func))(p, &l, &jmp));

        parse_free(p);
    }
END_FUNCTION(parse_file)


void
parse_save DECLARE((p))
    PARSE  *p  EP
BEGIN
    yypsave = p;
END_FUNCTION(parse_save)


PARSE *
parse_make DECLARE((func, left, right, third, string, string1, num))
    LIST       *(*func)PARAM((PARSE *p, LOL *args, int *jmp))  NP
    PARSE        *left                                         NP
    PARSE        *right                                        NP
    PARSE        *third                                        NP
    const char   *string                                       NP
    const char   *string1                                      NP
    int           num                                          EP
BEGIN
    PARSE *p = NIL(PARSE *);

    memoryAllocateOrFail((voidT **)&p, sizeof(PARSE));

    p->func    = func;
    p->left    = left;
    p->right   = right;
    p->third   = third;
    p->string  = string;
    p->string1 = string1;
    p->num     = num;
    p->refs    = 1;

    return(p);
END_FUNCTION(parse_make)


void
parse_refer DECLARE((p))
    PARSE  *p  EP
BEGIN
    ++p->refs;
END_FUNCTION(parse_refer)


void
parse_free DECLARE((p))
    PARSE  *p  EP
BEGIN
    if(--p->refs) {
        return;
    }

    if(p->string) {
        freestr(p->string);
    }
    if(p->string1) {
        freestr(p->string1);
    }
    if(p->left) {
        parse_free(p->left);
    }
    if(p->right) {
        parse_free(p->right);
    }
    if(p->third) {
        parse_free(p->third);
    }

    memoryRelease((voidT **)&p);
END_FUNCTION(parse_free)
