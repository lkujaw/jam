/*
 * Copyright 1993, 1995 Christopher Seiwald.
 *
 * This file is part of Jam - see jam.c for Copyright information.
 */

/*
 * hash.h - simple in-memory hashing routines
 *
 * 11/04/02 (seiwald) - const-ing for string literals
 */

#ifndef HASH_H
#define HASH_H

#include "ansi.h"

typedef struct hashdata HASHDATA;

struct hash *hashinit PROTO(( int datalen, const char *name ));
int          hashitem PROTO(( struct hash *hp, HASHDATA **data, int enter ));
void         hashdone PROTO(( struct hash *hp ));

# define        hashenter( hp, data ) !hashitem( hp, data, !0 )
# define        hashcheck( hp, data ) hashitem( hp, data, 0 )

#endif /* HASH_H */
