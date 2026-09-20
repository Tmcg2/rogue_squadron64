#include "common.h"

#include "PR/gu.h"

#include "rs_math.h"
#include "main/1D000.h"
#include "mission_overlay/0AA780.h"

INCLUDE_RODATA("asm/nonmatchings/mission_overlay/0AA780", D_mission_overlay_800A5130);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0AA780", computeAngleToTargetFromTransform);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0AA780", buildOrientationFromPosAndAngles);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0AA780", stepAngleTowardTarget);

void clampVec3ToUnitIfLongerThan(Vec3f arg0) {
    f32 temp_fv0;

    temp_fv0 = vec3Length(arg0);
    if (temp_fv0 >= 0.0001f) {
        arg0[0] /= temp_fv0;
        arg0[1] /= temp_fv0;
        arg0[2] /= temp_fv0;
    }
}

void scaleVec3ByScalar(Vec3f arg0, f32 arg1, Vec3f arg2) {
    arg0[0] = arg2[0] * arg1;
    arg0[1] = arg2[1] * arg1;
    arg0[2] = arg2[2] * arg1;
}

void addScaledVec3ToVec3(Vec3f arg0, Vec3f arg1, f32 arg2, Vec3f arg3) {
    arg0[0] = arg1[0] + (arg3[0] * arg2);
    arg0[1] = arg1[1] + (arg3[1] * arg2);
    arg0[2] = arg1[2] + (arg3[2] * arg2);
}

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0AA780", buildRotationMatrixFromEulerAngles);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0AA780", buildTransformMatrixFromEulerAngles);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0AA780", fake_func_800AA6CC);

INCLUDE_RODATA("asm/nonmatchings/mission_overlay/0AA780", D_mission_overlay_800A51D8);
