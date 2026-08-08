#include "common.h"

INCLUDE_ASM("asm/nonmatchings/main/04080", submitDmaSlot);

INCLUDE_ASM("asm/nonmatchings/main/04080", waitDmaSlotComplete);

INCLUDE_ASM("asm/nonmatchings/main/04080", pollDmaSlotStep);

INCLUDE_ASM("asm/nonmatchings/main/04080", find_manifest_entry);

INCLUDE_ASM("asm/nonmatchings/main/04080", pushEventToRingBuffer);

INCLUDE_ASM("asm/nonmatchings/main/04080", subscribeEventHandler);

INCLUDE_ASM("asm/nonmatchings/main/04080", processAssetLoadStep);

INCLUDE_ASM("asm/nonmatchings/main/04080", mainEventQueueWorker);

INCLUDE_ASM("asm/nonmatchings/main/04080", initDmaSlots);

INCLUDE_ASM("asm/nonmatchings/main/04080", findManifestEntryByName);

INCLUDE_ASM("asm/nonmatchings/main/04080", freeManifestSegmentAssets);

INCLUDE_ASM("asm/nonmatchings/main/04080", findAssetAcrossSegments);

INCLUDE_ASM("asm/nonmatchings/main/04080", teardownAssetDma);

INCLUDE_ASM("asm/nonmatchings/main/04080", get_asset_size_extra);

INCLUDE_ASM("asm/nonmatchings/main/04080", setupAssetDma);

INCLUDE_ASM("asm/nonmatchings/main/04080", spillArgsNoopHandler);

void noopHandler_80004FC8(void) {
}

void noopHandler_80004FD0(void) {
}

INCLUDE_ASM("asm/nonmatchings/main/04080", teardownAssetManifestService);

INCLUDE_ASM("asm/nonmatchings/main/04080", setManifestEntryName);

INCLUDE_ASM("asm/nonmatchings/main/04080", get_manifest_entry_type);

INCLUDE_ASM("asm/nonmatchings/main/04080", get_asset_size_simple);

INCLUDE_ASM("asm/nonmatchings/main/04080", zlibReturnZeroStub);

INCLUDE_ASM("asm/nonmatchings/main/04080", synchronousDmaTransfer);

INCLUDE_ASM("asm/nonmatchings/main/04080", mallocWithFallbackStrategy);

INCLUDE_ASM("asm/nonmatchings/main/04080", rs_zcfree);

INCLUDE_ASM("asm/nonmatchings/main/04080", rs_zcalloc);

INCLUDE_ASM("asm/nonmatchings/main/04080", returnNegativeOneStub);

INCLUDE_ASM("asm/nonmatchings/main/04080", returnZeroStubZlib);

INCLUDE_ASM("asm/nonmatchings/main/04080", resolveAssetRamAddress);

INCLUDE_ASM("asm/nonmatchings/main/04080", getDmaSlotMutex);

INCLUDE_ASM("asm/nonmatchings/main/04080", setDmaWorkerPriority);

INCLUDE_ASM("asm/nonmatchings/main/04080", fake_func_8000537C);
