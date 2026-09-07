#include "common.h"

#include "main/04080.h"
#include "main/06170.h"

INCLUDE_ASM("asm/nonmatchings/main/06170", piDmaWorker);

INCLUDE_ASM("asm/nonmatchings/main/06170", submitDmaRequestBatch);

INCLUDE_ASM("asm/nonmatchings/main/06170", initPiDmaWorker);

INCLUDE_ASM("asm/nonmatchings/main/06170", dispatchPendingPiDmaToWorker);

void getAssetRamAddress(s32 arg0) {
    resolveAssetRamAddress(arg0);
}

s32 setDmaSlotMaxTxStepSize(s32 arg0) {
    s32 temp_v0;
    s32 var_a0;

    var_a0 = (arg0 + 0xF) & ~0xF;
    temp_v0 = dmaSlotMaxTxStepSize;
    if (var_a0 == 0) {
        var_a0 = 0x10;
    }
    dmaSlotMaxTxStepSize = var_a0;
    return temp_v0;
}

INCLUDE_ASM("asm/nonmatchings/main/06170", fake_func_8000595C);
