/*
 * hash.c - simple in-memory hashing routines
 *
 * External routines:
 *
 *     hashinit() - initialize a hash table, returning a handle
 *     hashitem() - find a record in the table, and optionally enter a new one
 *     hashdone() - free a hash table, given its handle
 *
 * Internal routines:
 *
 *     hashrehash() - resize and rebuild hp->tab, the hash table
 *
 * 4/29/93 - ensure ITEM's are aligned
 * 11/04/02 (seiwald) - const-ing for string literals
 * 01/31/02 (seiwald) - keyval now unsigned (cray-ziness)
 */

#include "jam.h"  /* Includes system headers */

#include "hash.h"
#include "xmem.h"

/* Header attached to all data items entered into a hash table. */

struct hashhdr {
    struct item  *next;
    unsigned int  keyval;            /* for quick comparisons */
};

/* This structure overlays the one handed to hashenter(). */
/* It's actual size is given to hashinit(). */

struct hashdata {
    char  *key;
    /* rest of user data */
};

typedef struct item {
    struct hashhdr   hdr;
    struct hashdata  data;
} ITEM;

#define MAX_LISTS 32

struct hash
{
    /*
     * the hash table, just an array of item pointers
     */
    struct {
        int    nel;
        ITEM **base;
    } tab;

    int bloat;      /* tab.nel / items.nel */
    int inel;       /* initial number of elements */

    /*
     * the array of records, maintained by these routines
     * essentially a microallocator
     */
    struct {
        int   more;      /* how many more ITEMs fit in lists[ list ] */
        char *next;      /* where to put more ITEMs in lists[ list ] */
        int   datalen;   /* length of records in this hash table */
        int   size;      /* sizeof( ITEM ) + aligned datalen */
        int   nel;       /* total ITEMs held by all lists[] */
        int   list;      /* index into lists[] */

        struct {
            int   nel;   /* total ITEMs held by this list */
            char *base;  /* base of ITEMs array */
        } lists[MAX_LISTS];
    } items;

    const char *name;    /* just for hashstats() */
};

static void hashrehash   PARAM((struct hash *hp));
static void hashstat     PARAM((struct hash *hp));
static void hashvalidate PARAM((struct hash *hp));

static void
hashvalidate DECLARE((hp))
    struct hash  *hp  EP
BEGIN
    assert(hp);
END_FUNCTION(hashvalidate)


/*
 * hashitem() - find a record in the table, and optionally enter a new one
 */
int
hashitem DECLARE((hp, data, enter))
    struct hash    *hp     NP
    HASHDATA      **data   NP
    int             enter  EP
BEGIN
    ITEM          **base;
    ITEM           *i;
    unsigned char  *b;
    unsigned int    keyval;

    hashvalidate(hp);
    assert(data);

    b = (unsigned char *)(*data)->key;

    if(enter && !hp->items.more) {
        hashrehash(hp);
    }

    if(!enter && !hp->items.nel) {
        return(0);
    }

    keyval = *b;

    while(*b) {
        keyval = keyval * 2147059363 + *b++;
    }

    base = hp->tab.base + (keyval % hp->tab.nel);

    for(i = *base; i; i = i->hdr.next) {
        if(keyval == i->hdr.keyval && !strcmp(i->data.key, (*data)->key)) {
            *data = &i->data;
            return(!0);
        }
    }

    if(enter) {
        i               = (ITEM *)hp->items.next;
        hp->items.next += hp->items.size;
        hp->items.more--;
        memcpy((char *)&i->data, (char *)*data, hp->items.datalen);
        i->hdr.keyval = keyval;
        i->hdr.next   = *base;
        *base         = i;
        *data         = &i->data;
    }

    return(0);
END_FUNCTION(hashitem)


/*
 * hashrehash() - resize and rebuild hp->tab, the hash table
 */
static void
hashrehash DECLARE((hp))
    struct hash  *hp  EP
BEGIN
    int           i;

    hashvalidate(hp);

    i = ++hp->items.list;

    assert(!hp->items.more);

    hp->items.more = i ? 2 * hp->items.nel : hp->inel;

    hp->items.lists[i].base = NIL(char *);

    memoryAllocateOrFail((voidT **)&hp->items.lists[i].base,
                         hp->items.more * hp->items.size);

    hp->items.lists[i].nel = hp->items.more;
    hp->items.nel         += hp->items.more;
    hp->items.next         = hp->items.lists[i].base;

    if(hp->tab.base) {
        memoryRelease((voidT **)&hp->tab.base);
    }

    hp->tab.nel = hp->items.nel * hp->bloat;
    memoryAllocateOrFail((voidT **)&hp->tab.base,
                         hp->tab.nel * sizeof(ITEM *));
    /* We need to zero the memory because nel only specifies the number of
     * elements, not their validity [indicated by tab.base[x] == NULL]. */
    memset((char *)hp->tab.base, '\0', hp->tab.nel * sizeof(ITEM *));

    for(i = 0; i < hp->items.list; i++) {
        int   nel  = hp->items.lists[i].nel;
        char *next = hp->items.lists[i].base;

        for( ; nel--; next += hp->items.size) {
            register ITEM *i  = (ITEM *)next;
            ITEM         **ip = hp->tab.base + i->hdr.keyval % hp->tab.nel;

            i->hdr.next = *ip;
            *ip         = i;
        }
    }
END_FUNCTION(hash_rehash)


/* --- */
#define ALIGNED(x) ((x + sizeof(ITEM) - 1) & ~(sizeof(ITEM) - 1))


/*
 * hashinit() - initialize a hash table, returning a handle
 */
struct hash *
hashinit DECLARE((datalen, name))
    int          datalen  NP
    const char  *name     EP
BEGIN
    struct hash  *hp = NIL(struct hash *);

    assert(datalen >= 0);
    assert(name);

    memoryAllocateOrFail((voidT **)&hp, sizeof(struct hash));

    hp->tab.nel       = 0;
    hp->tab.base      = NIL(ITEM **);
    hp->bloat         = 3;
    hp->inel          = 11;
    hp->items.more    = 0;
    hp->items.datalen = datalen;
    hp->items.size    = sizeof(struct hashhdr) + ALIGNED(datalen);
    hp->items.nel     = 0;
    hp->items.list    = -1;
    hp->name          = name;

    return(hp);
END_FUNCTION(hashinit)


/*
 * hashdone() - free a hash table, given its handle
 */
void
hashdone DECLARE((hp))
    struct hash  *hp  EP
BEGIN
    int           i;

    hashvalidate(hp);

    if(DEBUG_MEM) {
        hashstat(hp);
    }

    if(hp->tab.base) {
        memoryRelease((voidT **)&hp->tab.base);
    }
    for(i = 0; i <= hp->items.list; ++i) {
        memoryRelease((voidT **)&hp->items.lists[i].base);
    }
    memoryRelease((voidT **)&hp);
END_FUNCTION(hashdone)


/* ---- */
static void
hashstat DECLARE((hp))
    struct hash  *hp  EP
BEGIN
    ITEM        **tab = hp->tab.base;
    int           nel = hp->tab.nel;
    int           count = 0;
    int           sets = 0;
    int           run = (tab[nel - 1] != NIL(ITEM *));
    int           i, here;

    hashvalidate(hp);

    for(i = nel; i > 0; i--) {
        if((here = (*tab++ != NIL(ITEM *)))) {
            count++;
        }
        if(here && !run) {
            sets++;
        }
        run = here;
    }

    assert(sets > 0);

    printf(
"%s table: %d+%d+%d (%dKiB+%dKiB) items+table+hash, %d.%04d density\n",
           hp->name,
           count,
           hp->items.nel,
           hp->tab.nel,
           hp->items.nel * hp->items.size / 1024,
           hp->tab.nel * (int)sizeof(ITEM **) / 1024,
           count, 10000 * (count % sets) / sets);
END_FUNCTION(hashstat)
