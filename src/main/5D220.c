#include "common.h"

#include "main/5D220.h"

u8 D_main_8009ECF0[] = {
    0x20,
    0x20,
    0x10,
    0x20,
    0x10,
    0x20,
    0x20,
    0x00,
    0x30,
    0x30,
    0x50,
    0x40,
    0x30,
    0x60,
    0x20,
    0x00,
};

char *D_main_8009ED00[] = {
    "red_laser",
    "red_laser",
    "green_laser",
    "red_laser",
    "green_laser",
    "red_laser",
    "red_laser",
    NULL,
    NULL,
    NULL,
    "i_missile",
    "i_missile",
    "ion_laser",
    "ph_torp",
    "i_missile",
};

f32 D_main_8009ED3C[] ={
    0.7f,
    1.2f,
    2.0f,
    4.0f,
    0.0f,
    1.0f,
    0.0f,
};

// DO NOT DELTE ME I AM REQUIRED FOR MATCHING
u32 data_pad_5D220[] = {
    0xC4400000,
    0xC4620000,
};

INCLUDE_ASM("asm/nonmatchings/main/5D220", checkTrackedNpcProximityForCue);

INCLUDE_ASM("asm/nonmatchings/main/5D220", audioCueDispatcherNpcHandler);

INCLUDE_ASM("asm/nonmatchings/main/5D220", collectNearbyNpcsForEffect);

INCLUDE_ASM("asm/nonmatchings/main/5D220", sprayEffectEmitterNpcHandler);

INCLUDE_ASM("asm/nonmatchings/main/5D220", dispatchCueByCategory);

INCLUDE_RODATA("asm/nonmatchings/main/5D220", D_main_8003B168);

INCLUDE_ASM("asm/nonmatchings/main/5D220", loadWeaponsHobObjects);

INCLUDE_ASM("asm/nonmatchings/main/5D220", findNpcInScaledBoxRegion);

INCLUDE_ASM("asm/nonmatchings/main/5D220", findNpcInScaledBoxRegionExcludingPair);

INCLUDE_ASM("asm/nonmatchings/main/5D220", freeEffectAssetBuffers);

INCLUDE_ASM("asm/nonmatchings/main/5D220", spawnByteAnimDebrisDefault);

INCLUDE_ASM("asm/nonmatchings/main/5D220", spawnByteAnimDebrisWithParam);

INCLUDE_ASM("asm/nonmatchings/main/5D220", loadTieBomberSprite);

INCLUDE_ASM("asm/nonmatchings/main/5D220", findNpcAlongDirectionRay);

INCLUDE_ASM("asm/nonmatchings/main/5D220", fake_func_8005EE64);
