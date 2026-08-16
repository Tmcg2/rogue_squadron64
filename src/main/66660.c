#include "common.h"

#include "main/66660.h"

INCLUDE_ASM("asm/nonmatchings/main/66660", buildPositionAndCallTransformHelper);

INCLUDE_ASM("asm/nonmatchings/main/66660", projectModelBoundsToScreen);

INCLUDE_ASM("asm/nonmatchings/main/66660", applyDatItemWorldOffset);

INCLUDE_ASM("asm/nonmatchings/main/66660", setupActorAnchorTransformType1);

f32 quadraticEaseInOut(f32 arg0) {
    f32 temp_fv1;

    if (arg0 < 0.0f) {
        arg0 = 0.0f;
    } else if (arg0 > 1.0f) {
        arg0 = 1.0f;
    }
    if (!(arg0 <= 0.5f)) {
        temp_fv1 = 1.0f - arg0;
        return 1.0f - (2.0f * temp_fv1 * temp_fv1);
    } else {
        return 2.0f * arg0 * arg0;
    }
}

void lerpVec3(Vec3f arg0, Vec3f arg1, Vec3f arg2, f32 arg3) {
    arg0[0] = (arg1[0] * (1.0f - arg3)) + (arg2[0] * arg3);
    arg0[1] = (arg1[1] * (1.0f - arg3)) + (arg2[1] * arg3);
    arg0[2] = (arg1[2] * (1.0f - arg3)) + (arg2[2] * arg3);
}

// DO NOT DELTE ME I'M REQUIRED FOR MATCHING
static const u32 rodata_padding[] = {
    0xAFA2001C,
    0x0C011409,
    0xA02000C0,
};

INCLUDE_ASM("asm/nonmatchings/main/66660", fake_func_800663AC);
