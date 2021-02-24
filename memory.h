#ifndef MEMORY_H
#define MEMORY_H

#include "ansi.h"

void *xmalloc PROTO((int size));
void xfree    PROTO((void *ptr));

#endif /* MEMORY_H */
