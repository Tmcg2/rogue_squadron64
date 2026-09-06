#ifndef MAIN_02490_H
#define MAIN_02490_H

#include "PR/ultratypes.h"

void  ensureHeapInitialized(void);
u32   getTotalFreeHeapSize(void);
u32   findLargestFreeHeapChunk(void);
void *rs_malloc(u32, u16);
void  rs_free(void*);

#endif
