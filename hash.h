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

#ifndef JAM_HASH_H
#define JAM_HASH_H 1

#include "ansi.h"

#define        hashenter( hp, data ) !hashitem( hp, data, !0 )
#define        hashcheck( hp, data )  hashitem( hp, data,  0 )

typedef struct hashdata HASHDATA;

_BEGIN_EXTERNS_

struct hash *hashinit _ARG_((int datalen, const char *name));
int          hashitem _ARG_((struct hash *hp, HASHDATA **data, int enter));
void         hashdone _ARG_((struct hash *hp));

_END_EXTERNS_

#endif /* JAM_HASH_H */
