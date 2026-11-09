#include "common.h"

#include "hob.h"

#include "main/bss_80139020.h"
#include "main/3F160.h"
#include "main/5AD20.h"

struct vertex D_main_8009ECC0[] = {
    {0xFF80, 0x0000, 0xFF80, 0x0000},
    {0x0080, 0x0000, 0xFF80, 0x0000},
    {0x0080, 0x0000, 0x0080, 0x0000},
    {0xFF80, 0x0000, 0x0080, 0x0000},
};

f32 D_main_8009ECE0[] = {
    5.0f,
    -5.0f,
    21.0f,
    -21.0f,
};

INCLUDE_ASM("asm/nonmatchings/main/5AD20", loadTopCloudsAsset);

INCLUDE_ASM("asm/nonmatchings/main/5AD20", updateWalkerParticlePositions);

INCLUDE_RODATA("asm/nonmatchings/main/5AD20", D_main_8003AE10);

INCLUDE_ASM("asm/nonmatchings/main/5AD20", loadSkyHorizonHob);

INCLUDE_ASM("asm/nonmatchings/main/5AD20", linkDirectionalTrailSegments);

INCLUDE_ASM("asm/nonmatchings/main/5AD20", setupWalkerSpriteTileQuad);

INCLUDE_ASM("asm/nonmatchings/main/5AD20", cinematicSplineWalkerNpcHandler);

void allocAllInitialNpcSlots(void) {
    s32 var_s1;

    for (var_s1 = 0; var_s1 < 0x20; var_s1++) {
        D_main_bss_80139560[var_s1] = allocateNpcSlot(NULL);
    }
}

INCLUDE_ASM("asm/nonmatchings/main/5AD20", fake_func_8005C61C);
