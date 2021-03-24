/*
 * hash.h - simple in-memory hashing routines
 *
 */

#ifndef JAM_HASH_H
#define JAM_HASH_H 1

#include "cstd.h"

#define       hashenter(hp, data) !hashitem(hp, data, !0)
#define       hashcheck(hp, data)  hashitem(hp, data,  0)

typedef struct hashdata HASHDATA;

BEGIN_EXTERNS

struct hash  *hashinit PARAM((int datalen, const char *name));
int           hashitem PARAM((struct hash *hp, HASHDATA **data, int enter));
void          hashdone PARAM((struct hash *hp));

END_EXTERNS

#endif /* JAM_HASH_H */
