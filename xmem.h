/* xmem.h: Extended memory interface for Jam */

#ifndef JAM_XMEM_H
#define JAM_XMEM_H 1

#include "ansi.h"
#include "bool.h"

_BEGIN_EXTERNS_

boolT fMemoryAllocate       _ARG_((voidT **ppMemory, sizeT mBytesC));
void   memoryAllocateOrFail _ARG_((voidT **ppMemory, sizeT mBytesC));
void   memoryRelease        _ARG_((voidT **ppMemory));

boolT fValidPointer         _ARG_((voidT *pMemory));

void   xmemTerminate        _ARG_((void));

_END_EXTERNS_

#endif /* JAM_XMEM_H */
