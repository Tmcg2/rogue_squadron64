#include "common.h"

#include "main/3F160.h"
#include "main/40F10.h"

INCLUDE_ASM("asm/nonmatchings/main/40F10", allocAndInitParticlePool);

INCLUDE_ASM("asm/nonmatchings/main/40F10", randomBurstNpcHandlerVariant);

INCLUDE_ASM("asm/nonmatchings/main/40F10", spawnNpcFormationWithRandomOrientation);

INCLUDE_ASM("asm/nonmatchings/main/40F10", computeNpcGroupCentroidAndCull);

INCLUDE_ASM("asm/nonmatchings/main/40F10", spawnRandomBurstNpc);

INCLUDE_ASM("asm/nonmatchings/main/40F10", freeNpcBurstSpawnerTables);

INCLUDE_ASM("asm/nonmatchings/main/40F10", initNpcContextFromTransform);

INCLUDE_ASM("asm/nonmatchings/main/40F10", spawnRandomBurstNpcVariantWrapper);

void destroyNpcSlotByIndexU16(s32 arg0) {
    destroyNpcSlotByIndex(arg0);
}

INCLUDE_ASM("asm/nonmatchings/main/40F10", attachChildNpcByIndex);

INCLUDE_ASM("asm/nonmatchings/main/40F10", assignNpcTargetAndPosition);

INCLUDE_ASM("asm/nonmatchings/main/40F10", setNpcForwardVectorByIndex);

INCLUDE_ASM("asm/nonmatchings/main/40F10", resolveNpcContextByIndex);

INCLUDE_ASM("asm/nonmatchings/main/40F10", fake_func_80041EEC);
