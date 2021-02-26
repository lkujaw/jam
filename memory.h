#ifndef JAM_MEMORY_H
#define JAM_MEMORY_H 1

#include "ansi.h"

_BEGIN_EXTERNS_

Void_t* xmalloc _ARG_((int size));
void    xfree   _ARG_((Void_t *ptr));

_END_EXTERNS_

#endif /* JAM_MEMORY_H */
