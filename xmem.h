/* xmem.h: Extended memory interface for Jam */

#ifndef JAM_XMEM_H
#define JAM_XMEM_H 1

#include "bool.h"
#include "cstd.h"

BEGIN_EXTERNS

boolT  fMemoryAllocate        PARAM((voidT **ppMemory, sizeT mBytesC));
void    memoryAllocateOrFail  PARAM((voidT **ppMemory, sizeT mBytesC));
void    memoryRelease         PARAM((voidT **ppMemory));

boolT  fValidPointer          PARAM((voidT *pMemory));

void    xmemTerminate         PARAM((void));

END_EXTERNS

#endif /* JAM_XMEM_H */
