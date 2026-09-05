#include "common.h"

#include "main/02490.h"

INCLUDE_ASM("asm/nonmatchings/main/02490", ensureHeapInitialized);

INCLUDE_ASM("asm/nonmatchings/main/02490", getTotalFreeHeapSize);

INCLUDE_ASM("asm/nonmatchings/main/02490", findLargestFreeHeapChunk);

INCLUDE_ASM("asm/nonmatchings/main/02490", rs_malloc);

INCLUDE_ASM("asm/nonmatchings/main/02490", rs_free);

INCLUDE_ASM("asm/nonmatchings/main/02490", buildHeapFreeList);

INCLUDE_ASM("asm/nonmatchings/main/02490", initMainHeap);

INCLUDE_ASM("asm/nonmatchings/main/02490", coalesceFreeHeapBlocks);
