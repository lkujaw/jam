/*
 * lists.c - maintain lists of strings
 *
 * This implementation essentially uses a singly linked list, but
 * guarantees that the head element of every list has a valid pointer
 * to the tail of the list, so the new elements can efficiently and
 * properly be appended to the end of a list.
 *
 * To avoid massive allocation, list_free() just tacks the whole freed
 * chain onto freelist and list_new() looks on freelist first for an
 * available list struct.  list_free() does not free the strings in the
 * chain: it lazily lets list_new() do so.
 *
 * 08/23/94 (seiwald) - new list_append()
 * 09/07/00 (seiwald) - documented lol_*() functions
 * 10/22/02 (seiwald) - list_new() now does its own newstr()/copystr()
 * 11/04/02 (seiwald) - const-ing for string literals
 * 12/09/02 (seiwald) - new list_printq() for writing lists to Jambase
 */

#include "jam.h"  /* Includes system headers */

#include "lists.h"
#include "str.h"
#include "xmem.h"

static LIST *freelist = NIL(LIST*);  /* junkpile for list_free() */

/*
 * list_append() - append a list onto another one, returning total
 */
LIST *
list_append DECLARE((l, nl))
    LIST  *l   NP
    LIST  *nl  EP
BEGIN
    if(!nl) {
        /* Just return l */
    } else if(!l) {
        l = nl;
    } else   {
        /* Graft two non-empty lists. */
        l->tail->next = nl;
        l->tail       = nl->tail;
    }

    return(l);
END_FUNCTION(list_append)


/*
 * list_new() - tack a string onto the end of a list of strings
 */
LIST *
list_new DECLARE((head, string, copy))
    LIST        *head    NP
    const char  *string  NP
    int          copy    EP
BEGIN
    LIST        *l = NIL(LIST *);

    if(DEBUG_LISTS) {
        printf("list > %s <\n", string);
    }

    /* Copy/newstr as needed */
    string = copy ? copystr(string) : newstr(string);

    /* Get list struct from freelist, if one available.  */
    /* Otherwise allocate. */
    /* If from freelist, must free string first */

    if(freelist) {
        l = freelist;
        freestr(l->string);
        freelist = freelist->next;
    } else   {
        memoryAllocateOrFail((voidT **)&l, sizeof(*l));
    }

    /* If first on chain, head points here. */
    /* If adding to chain, tack us on. */
    /* Tail must point to this new, last element. */

    if(!head) {
        head = l;
    } else {
        head->tail->next = l;
    }
    head->tail = l;
    l->next    = 0;

    l->string = string;

    return(head);
END_FUNCTION(list_new)


/*
 * list_copy() - copy a whole list of strings (nl) onto end of another (l)
 */
LIST *
list_copy DECLARE((l, nl))
    LIST  *l   NP
    LIST  *nl  EP
BEGIN
    for(; nl; nl = list_next(nl)) {
        l = list_new(l, nl->string, 1);
    }

    return(l);
END_FUNCTION(list_copy)


/*
 * list_sublist() - copy a subset of a list of strings
 */
LIST *
list_sublist DECLARE((l, start, count))
    LIST  *l      NP
    int    start  NP
    int    count  EP
BEGIN
    LIST  *nl = NIL(LIST*);

    for(; l && start--; l = list_next(l)) {
        ;
    }

    for(; l && count--; l = list_next(l)) {
        nl = list_new(nl, l->string, 1);
    }

    return(nl);
END_FUNCTION(list_sublist)


/*
 * list_free() - free a list of strings
 */
void
list_free DECLARE((head))
    LIST  *head  EP
BEGIN
    /* Just tack onto freelist. */
    if(head) {
        head->tail->next = freelist;
        freelist         = head;
    }
END_FUNCTION(list_free)


/*
 * list_print() - print a list of strings to stdout
 */
void
list_print DECLARE((l))
    LIST  *l  EP
BEGIN
    for(; l; l = list_next(l)) {
        printf("%s ", l->string);
    }
END_FUNCTION(list_print)


/*
 * list_length() - return the number of items in the list
 */
int
list_length DECLARE((l))
    LIST  *l  EP
BEGIN
    int    n = 0;

    for(; l; l = list_next(l), ++n) {
        ;
    }

    return(n);
END_FUNCTION(list_length)


/*
 * lol_init() - initialize a LOL (list of lists)
 */
void
lol_init DECLARE((lol))
    LOL  *lol  EP
BEGIN
    lol->count = 0;
END_FUNCTION(lol_init)


/*
 * lol_add() - append a LIST onto an LOL
 */
void
lol_add DECLARE((lol, l))
    LOL    *lol  NP
    LIST   *l    EP
BEGIN
    if(lol->count < LOL_MAX) {
        lol->list[lol->count++] = l;
    }
END_FUNCTION(lol_add)


/*
 * lol_free() - free the LOL and its LISTs
 */
void
lol_free DECLARE((lol))
    LOL  *lol  EP
BEGIN
    int   i;

    for(i = 0; i < lol->count; i++) {
        list_free(lol->list[i]);
    }

    lol->count = 0;
END_FUNCTION(lol_free)


/*
 * lol_get() - return one of the LISTs in the LOL
 */
LIST *
lol_get DECLARE((lol, i))
    LOL  *lol  NP
    int   i    EP
BEGIN
    return(i < lol->count ? lol->list[i] : 0);
END_FUNCTION(lol_get)


/*
 * lol_print() - debug print LISTS separated by ":"
 */
void
lol_print DECLARE((lol))
    LOL  *lol  EP
BEGIN
    int  i;

    for(i = 0; i < lol->count; i++) {
        if(i) {
            printf(" : ");
        }
        list_print(lol->list[i]);
    }
END_FUNCTION(lol_print)
