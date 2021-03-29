/*
 * variable.c - handle jam multi-element variables
 *
 * External routines:
 *
 *      var_defines() - load a bunch of variable=value settings
 *      var_string()  - expand a string with variables in it
 *      var_get()     - get value of a user defined symbol
 *      var_set()     - set a variable in jam's user defined symbol table
 *      var_swap()    - swap a variable's value with the given one
 *      var_done()    - free variable tables
 *
 * Internal routines:
 *
 *      var_enter() - make new var symbol table entry, returning var ptr
 *      var_dump()  - dump a variable to stdout
 *
 * 04/13/94 (seiwald) - added shorthand L0 for null list pointer
 * 08/23/94 (seiwald) - Support for '+=' (append to variable)
 * 01/22/95 (seiwald) - split environment variables at blanks or :'s
 * 05/10/95 (seiwald) - split path variables at SPLITPATH (not :)
 * 09/11/00 (seiwald) - defunct var_list() removed
 * 10/22/02 (seiwald) - list_new() now does its own newstr()/copystr()
 * 11/04/02 (seiwald) - const-ing for string literals
 * 06/11/03 (seiwald) - fix var_string mem leak found by Matt Armstrong
 */

#include "jam.h"  /* Includes system headers */

#include "expand.h"
#include "hash.h"
#include "lists.h"
#include "parse.h"
#include "str.h"
#include "variable.h"

static struct hash *varhash = NIL(struct hash *);

/*
 * VARIABLE - a user defined multi-value variable
 */

typedef struct _variable VARIABLE;

struct _variable {
    const char *symbol;
    LIST       *value;
};

static VARIABLE *var_enter PARAM((const char *symbol));
static void var_dump PARAM((const char *symbol, LIST *value,
                            const char *what));

/*
 * var_defines() - load a bunch of variable=value settings
 *
 * If variable name ends in PATH, split value at :'s.
 * Otherwise, split at blanks.
 */
void
var_defines DECLARE((e))
    const char  **e  EP
BEGIN
    for(; *e; e++) {
        const char *val;

        /* Just say "no": windows defines this in the env, but we
         * don't want it to override our notion of OS.
         */
        if(!strcmp(*e, "OS=Windows_NT")) {
            continue;
        }

        /* Just say "no": on Unix, variables can contain function
         * definitions. their value begins with "()"
         */
        if((val = strchr(*e, '=')) && val[1] == '(' && val[2] == ')') {
            continue;
        }

#ifdef OS_MAC
        /* On the mac (MPW), the var=val is actually var\0val */
        if((val = strchr(*e, '=')) || (val = *e + strlen(*e)))
#else
        if((val = strchr(*e, '=')))
#endif
        {
            LIST       *l = L0;
            const char *pp, *p;
#ifdef OS_MAC
            char  split = ',';
#else
            char  split = ' ';
#endif
            char  buf[MAXSYM];

            /* Split *PATH at :'s, not spaces */

            if(val - 4 >= *e) {
                if(!strncmp(val - 4, "PATH", 4) ||
                   !strncmp(val - 4, "Path", 4) ||
                   !strncmp(val - 4, "path", 4)) {
                    split = SPLITPATH;
                }
            }

            /* Do the split */

            for(pp = val + 1; (p = strchr(pp, split)); pp = p + 1) {
                int  len = p - pp;

                if(len >= sizeof(buf)) {
                    len = sizeof(buf) - 1;
                }

                strncpy(buf, pp, len);
                buf[ len ] = '\0';
                l          = list_new(l, buf, 0);
            }

            l = list_new(l, pp, 0);

            /* Get name */

            strncpy(buf, *e, val - *e);
            buf[val - *e] = '\0';

            var_set(buf, l, VAR_SET);
        }
    }
END_FUNCTION(var_defines)


/*
 * var_string() - expand a string with variables in it
 *
 * Copies in to out; doesn't modify targets & sources.
 */
int
var_string DECLARE((in, out, outsize, lol))
    const char  *in       NP
          char  *out      NP
           int   outsize  NP
           LOL  *lol      EP
BEGIN
    char        *out0 = out;
    char        *oute = out + outsize - 1;

    while(*in) {
        char *lastword;
        int   dollar = 0;

        /* Copy white space */

        while(isspace(*in)) {
            if(out >= oute) {
                return(-1);
            }

            *out++ = *in++;
        }

        lastword = out;

        /* Copy non-white space, watching for variables */
        while(*in && !isspace(*in)) {
            if(out >= oute) {
                return(-1);
            }

            if(in[0] == '$' && in[1] == '(') {
                dollar++;
            }

            *out++ = *in++;
        }

        /* If a variable encountered, expand it and and embed the */
        /* space-separated members of the list in the output. */
        if(dollar) {
            LIST *l = var_expand(L0, lastword, out, lol, 0);
            LIST *h = l;

            out = lastword;

            while(l) {
                int  so = strlen(l->string);

                if(out + so >= oute) {
                    return(-1);
                }

                strcpy(out, l->string);
                out += so;

                /* Separate with space */
                if((l = list_next(l))) {
                    *out++ = ' ';
                }
            }

            if(h != NIL(LIST*)) {
                list_free(h);
            }
        }
    }
    if(out >= oute) {
        return(-1);
    }

    *out++ = '\0';

    return(out - out0);
END_FUNCTION(var_string)


/*
 * var_get() - get value of a user defined symbol
 *
 * Returns NULL if symbol unset.
 */
LIST *
var_get DECLARE((symbol))
    const char  *symbol  EP
BEGIN
    VARIABLE     var, *v = &var;

    v->symbol = symbol;

    if(varhash && hashcheck(varhash, (HASHDATA **)&v)) {
        if(DEBUG_VARGET) {
            var_dump(v->symbol, v->value, "get");
        }
        return(v->value);
    }

    return(0);
END_FUNCTION(var_get)


/*
 * var_set() - set a variable in jam's user defined symbol table
 *
 * 'flag' controls the relationship between new and old values of
 * the variable: SET replaces the old with the new; APPEND appends
 * the new to the old; DEFAULT only uses the new if the variable
 * was previously unset.
 *
 * Copies symbol.  Takes ownership of value.
 */
void
var_set DECLARE((symbol, value, flag))
    const char  *symbol  NP
          LIST  *value   NP
           int   flag    EP
BEGIN
    VARIABLE    *v = var_enter(symbol);

    if(DEBUG_VARSET) {
        var_dump(symbol, value, "set");
    }

    switch(flag) {
    case VAR_SET:
        /* Replace value */
        if(v->value != NIL(LIST*)) {
            list_free(v->value);
        }
        v->value = value;
        break;
    case VAR_APPEND:
        /* Append value */
        v->value = list_append(v->value, value);
        break;
    case VAR_DEFAULT:
        /* Set only if unset */
        if(!v->value) {
            v->value = value;
        } else {
            if(value != NIL(LIST*)) {
                list_free(value);
            }
        }
        break;
    }
END_FUNCTION(var_set)


/*
 * var_swap() - swap a variable's value with the given one
 */
LIST *
var_swap DECLARE((symbol, value))
    const char  *symbol  NP
          LIST  *value   EP
BEGIN
    VARIABLE    *v        = var_enter(symbol);
    LIST        *oldvalue = v->value;

    if(DEBUG_VARSET) {
        var_dump(symbol, value, "set");
    }

    v->value = value;

    return(oldvalue);
END_FUNCTION(var_swap)


/*
 * var_enter() - make new var symbol table entry, returning var ptr
 */
static VARIABLE *
var_enter DECLARE((symbol))
    const char *symbol  EP
BEGIN
    VARIABLE    var, *v = &var;

    if(!varhash) {
        varhash = hashinit(sizeof(VARIABLE), "variables");
    }

    v->symbol = symbol;
    v->value  = 0;

    if(hashenter(varhash, (HASHDATA **)&v)) {
        v->symbol = newstr(symbol);             /* never freed */
    }
    return(v);
END_FUNCTION(var_enter)


/*
 * var_dump() - dump a variable to stdout
 */
static void
var_dump DECLARE((symbol, value, what))
    const char  *symbol  NP
          LIST  *value   NP
    const char  *what    EP
BEGIN
    printf("%s %s = ", what, symbol);
    list_print(value);
    printf("\n");
END_FUNCTION(var_dump)


/*
 * var_done() - free variable tables
 */
void
var_done NULLARY
BEGIN
    hashdone(varhash);
END_FUNCTION(var_done)
