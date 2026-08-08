#include "common.h"

INCLUDE_ASM("asm/nonmatchings/main/05F80", initRsMallocHeap);

INCLUDE_ASM("asm/nonmatchings/main/05F80", getRsHeapMaxAllocSize);

INCLUDE_ASM("asm/nonmatchings/main/05F80", allocRsHeapBlock);

INCLUDE_ASM("asm/nonmatchings/main/05F80", freeRsHeapBlock);

void noopHandler_80005560(void) {
}

INCLUDE_ASM("asm/nonmatchings/main/05F80", fake_func_80005568);
