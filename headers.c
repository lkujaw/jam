/*
 * headers.c - handle #includes in source files
 *
 * Using regular expressions provided as the variable $(HDRSCAN),
 * headers() searches a file for #include files and phonies up a
 * rule invocation:
 *
 *      $(HDRRULE) <target> : <include files> ;
 *
 * External routines:
 *    headers() - scan a target for include files and call HDRRULE
 *
 * Internal routines:
 *    headers1() - using regexp, scan a file and build include LIST
 *
 * 04/13/94 (seiwald) - added shorthand L0 for null list pointer
 * 09/10/00 (seiwald) - replaced call to compile_rule with evaluate_rule,
 *              so that headers() doesn't have to mock up a parse structure
 *              just to invoke a rule.
 * 03/02/02 (seiwald) - rules can be invoked via variable names
 * 10/22/02 (seiwald) - list_new() now does its own newstr()/copystr()
 * 11/04/02 (seiwald) - const-ing for string literals
 * 12/09/02 (seiwald) - push regexp creation down to headers1().
 */

#include "jam.h"  /* Includes system headers */

#include "compile.h"
#include "hdrmacro.h"
#include "headers.h"
#include "lists.h"
#include "parse.h"
#include "regexp.h"
#include "rules.h"
#include "str.h"
#include "variable.h"
#include "xmem.h"


static LIST *headers1 PARAM((const char *file, LIST *hdrscan));

/*
 * headers() - scan a target for include files and call HDRRULE
 */

#define MAXINC 10

void
headers DECLARE((t))
    TARGET  *t  EP
BEGIN
    LIST    *hdrscan;
    LIST    *hdrrule;
    LOL      lol;

    if(!(hdrscan = var_get("HDRSCAN")) ||
       !(hdrrule = var_get("HDRRULE")))
    {
        return;
    }

    /* Doctor up call to HDRRULE rule */
    /* Call headers1() to get LIST of included files. */

    if(DEBUG_HEADER) {
        printf("header scan %s\n", t->name);
    }

    lol_init(&lol);

    lol_add(&lol, list_new(L0, t->name, 1));
    lol_add(&lol, headers1(t->boundname, hdrscan));

    if(lol_get(&lol, 1)) {
        LIST *rvalue = evaluate_rule(hdrrule->string, &lol, L0);
        if(rvalue != NIL(LIST*)) {
            list_free(rvalue);
        }
    }

    /* Clean up */
    lol_free(&lol);
END_FUNCTION(headers)


/*
 * headers1() - using regexp, scan a file and build include LIST
 */
static LIST *
headers1 DECLARE((file, hdrscan))
    const char  *file     NP
    LIST        *hdrscan  EP
BEGIN
    FILE   *f;
    int     i;
    int     rec    = 0;
    LIST   *result = NIL(LIST*);
    regexp *re[MAXINC];
    regexp *re_macros;
    char    buf[1024];

    if(!(f = fopen(file, "r"))) {
        return(result);
    }

    while(rec < MAXINC && hdrscan) {
        re[rec++] = regcomp(hdrscan->string);
        hdrscan   = list_next(hdrscan);
    }

    /* the following regexp is used to detect cases where a  */
    /* file is included through a line line "#include MACRO" */
    re_macros = regcomp(
        "^[  ]*#[    ]*include[      ]*([A-Za-z][A-Za-z0-9_]*).*$");

    while(fgets(buf, sizeof(buf), f)) {
        for(i = 0; i < rec; i++) {
            if(regexec(re[i], buf) && re[i]->startp[1]) {
                /* Copy and terminate extracted string. */
                char  buf2[ MAXSYM ];
                int   l;

                assert(re[i]->endp[1] - re[i]->startp[1] < MAXSYM);
                l = (int)(re[i]->endp[1] - re[i]->startp[1]);
                memcpy(buf2, re[i]->startp[1], l);
                buf2[l] = '\0';

                result = list_new(result, buf2, 0);

                if(DEBUG_HEADER) {
                    printf("header found: %s\n", buf2);
                }
            }
        }

        /* special treatment for #include MACRO */
        if(regexec(re_macros, buf) && re_macros->startp[1]) {
            const char *header_filename;
            char        buf2[ MAXSYM ];
            int         l = re_macros->endp[1] - re_macros->startp[1];

            memcpy(buf2, re_macros->startp[1], l);
            buf2[ l ] = 0;

            if(DEBUG_HEADER) {
                printf("macro header found: %s", buf2);
            }

            header_filename = macro_header_get(buf2);
            if(header_filename) {
                if(DEBUG_HEADER) {
                    printf(" resolved to '%s'\n", header_filename);
                }
                result = list_new(result, header_filename, 0);
            } else {
                if(DEBUG_HEADER) {
                    printf(" ignored !!\n");
                }
            }
        }
    }

    memoryRelease((voidT **)&re_macros);

    while(rec) {
        memoryRelease((voidT **)&re[--rec]);
    }

    fclose(f);
    return(result);
END_FUNCTION(headers1)
