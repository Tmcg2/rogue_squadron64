#include "common.h"

#include "player.h"

#include "main/6C310.h"

// Interim BSS externs
extern u16 D_main_bss_8013A528[14];

INCLUDE_ASM("asm/nonmatchings/main/6C310", loadCraftShadowTextures);

INCLUDE_ASM("asm/nonmatchings/main/6C310", applyCentripetalBankingToNpcCorners);

INCLUDE_ASM("asm/nonmatchings/main/6C310", allocateAndInitCraftNpcContext);

INCLUDE_ASM("asm/nonmatchings/main/6C310", advanceNpcOnCurvedPath);

INCLUDE_ASM("asm/nonmatchings/main/6C310", splineWalkerCraftNpcHandler);

INCLUDE_ASM("asm/nonmatchings/main/6C310", stubNpcHandler);

INCLUDE_ASM("asm/nonmatchings/main/6C310", clearTrackedNpcSlots);

INCLUDE_ASM("asm/nonmatchings/main/6C310", spawnSplineWalkerCraft);

INCLUDE_ASM("asm/nonmatchings/main/6C310", spawnStubMarkerNpc);

INCLUDE_ASM("asm/nonmatchings/main/6C310", load_naboo_starfighter);

#if 0
void *getCraftRecordByIdx(s32 arg0) {
    return &gPlayers[arg0].inner.posX; // While this matches its obviously wrong, there's another struct inside player.inner (most likely)
}
#else
INCLUDE_ASM("asm/nonmatchings/main/6C310", getCraftRecordByIdx);
#endif

INCLUDE_ASM("asm/nonmatchings/main/6C310", getPlayerCraftRecordByIdx);

enum PlayerCraft getPlayerVehicleId(s32 playerId) {
    return gPlayers[playerId].inner.vehicleId;
}

INCLUDE_ASM("asm/nonmatchings/main/6C310", getPlayerRecordTargetBuffer);

u16 getPlayerField2(s32 arg0) {
    return gPlayers[arg0].unk002;
}

INCLUDE_ASM("asm/nonmatchings/main/6C310", attachDebrisModelVariant);

INCLUDE_ASM("asm/nonmatchings/main/6C310", updateDestructionDebrisNpc);

INCLUDE_ASM("asm/nonmatchings/main/6C310", fake_func_8006D8FC);
