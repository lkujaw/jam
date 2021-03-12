/*
 * hash.h - simple in-memory hashing routines
 *
 */

#ifndef JAM_HASH_H
#define JAM_HASH_H 1

#include "ansi.h"

#define       hashenter(hp, data) !hashitem(hp, data, !0)
#define       hashcheck(hp, data)  hashitem(hp, data,  0)

typedef struct hashdata HASHDATA;

_BEGIN_EXTERNS_

struct hash  *hashinit _ARG_((int datalen, const char *name));
int           hashitem _ARG_((struct hash *hp, HASHDATA **data, int enter));
void          hashdone _ARG_((struct hash *hp));

_END_EXTERNS_

#endif /* JAM_HASH_H */
