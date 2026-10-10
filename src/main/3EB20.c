#include "common.h"

#include "main/02420.h"
#include "main/3EB20.h"

INCLUDE_ASM("asm/nonmatchings/main/3EB20", clearSceneBssRegion);

void clearDeferredClearRequest(void) {
    queueDeferredClearRequest(NULL, 0);
}

INCLUDE_ASM("asm/nonmatchings/main/3EB20", fake_func_8003DF98);
