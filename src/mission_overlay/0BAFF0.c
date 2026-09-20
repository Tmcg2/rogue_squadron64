#include "common.h"

#include "mission_overlay/0BAFF0.h"

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0BAFF0", playerFalconInit);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0BAFF0", computeFalconFlightTransform);

INCLUDE_RODATA("asm/nonmatchings/mission_overlay/0BAFF0", D_mission_overlay_800A5E00);

INCLUDE_RODATA("asm/nonmatchings/mission_overlay/0BAFF0", D_mission_overlay_800A5E04);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0BAFF0", triggerFalconEngineEffect);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0BAFF0", bindFalconSubmodelMaterials);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0BAFF0", playerFalconMainUpdate);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0BAFF0", spawnFalconEngineParticles);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0BAFF0", playerFalconUpdate);

#if 0
// https://decomp.me/scratch/yyxM0
f32 integrateFalconFlightPhysics(f32 arg0, f32 arg1, f32 arg2) {
    f32 temp_fa0;
    f32 var_fv0;

    if (!(fabsf(arg1 - arg0) > 0.35f)) {
        return arg1;
    }
    if (!(arg0 < arg1)) {
        if (!((arg0 - arg1) > 180.0f)) {
            var_fv0 = -70.0f;
        } else {
            var_fv0 = 70.0f;
        }
    } else {
        if (!(arg1 - arg0 > 180.0f)) {
            var_fv0 = 70.0f;
        } else {
            var_fv0 = -70.0f;
        }
    }
    arg0 += (arg2 * var_fv0);
    if (arg0 < 0.0f) {
        arg0 += 360.0f;
    } else if (360.0f < arg0) {
        arg0 -= 360.0f;
    }
    return arg0;
}

// DO NOT DELETE ME I AM REQUIRED FOR MATCHING
const u32 rodata_pad_0BAFF0[2] = {
    0x03A0F021,
    0x24040014,
};
#else
INCLUDE_ASM("asm/nonmatchings/mission_overlay/0BAFF0", integrateFalconFlightPhysics);

INCLUDE_RODATA("asm/nonmatchings/mission_overlay/0BAFF0", D_mission_overlay_800A5ED4);
#endif
