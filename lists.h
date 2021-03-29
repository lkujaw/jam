/*
 * lists.h - the LIST structure and routines to manipulate them
 *
 * The whole of jam relies on lists of strings as a datatype.  This
 * module, in conjunction with newstr.c, handles these relatively
 * efficiently.
 *
 * Structures defined:
 *
 *      LIST - list of strings
 *      LOL - list of LISTs
 *
 * External routines:
 *
 *      list_append() - append a list onto another one, returning total
 *      list_new() - tack a string onto the end of a list of strings
 *      list_copy() - copy a whole list of strings
 *      list_sublist() - copy a subset of a list of strings
 *      list_free() - free a list of strings
 *      list_print() - print a list of strings to stdout
 *      list_printq() - print a list of safely quoted strings to a file
 *      list_length() - return the number of items in the list
 *
 *      lol_init() - initialize a LOL (list of lists)
 *      lol_add() - append a LIST onto an LOL
 *      lol_free() - free the LOL and its LISTs
 *      lol_get() - return one of the LISTs in the LOL
 *      lol_print() - debug print LISTS separated by ":"
 *
 * 04/13/94 (seiwald) - added shorthand L0 for null list pointer
 * 08/23/94 (seiwald) - new list_append()
 * 10/22/02 (seiwald) - list_new() now does its own newstr()/copystr()
 * 11/04/02 (seiwald) - const-ing for string literals
 * 12/09/02 (seiwald) - new list_printq() for writing lists to Jambase
 */

/*
 * LIST - list of strings
 */

#ifndef JAM_LISTS_H
#define JAM_LISTS_H 1

#include "cstd.h"

#define LOL_MAX      9
#define list_next(l) ((l)->next)
#define L0           NIL(LIST*)

typedef struct _list LIST;

struct _list {
    LIST       *next;
    LIST       *tail;           /* only valid in head node */
    const char *string;         /* private copy */
};

/*
 * LOL - list of LISTs
 */

typedef struct _lol LOL;

struct _lol {
    int   count;
    LIST *list[LOL_MAX];
};

BEGIN_EXTERNS

LIST *  list_append   PARAM((LIST *l, LIST *nl));
LIST *  list_copy     PARAM((LIST *l, LIST  *nl));
void    list_free     PARAM((LIST *head));
LIST *  list_new      PARAM((LIST *head, const char *string, int copy));
void    list_print    PARAM((LIST *l));
int     list_length   PARAM((LIST *l));
LIST *  list_sublist  PARAM((LIST *l, int start, int count));

void    lol_add    PARAM((LOL *lol, LIST *l));
void    lol_init   PARAM((LOL *lol));
void    lol_free   PARAM((LOL *lol));
LIST *  lol_get    PARAM((LOL *lol, int i));
void    lol_print  PARAM((LOL *lol));

END_EXTERNS

#endif /* JAM_LISTS_H */
