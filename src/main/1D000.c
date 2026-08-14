#include "common.h"

#include "main/1D000.h"

INCLUDE_ASM("asm/nonmatchings/main/1D000", sinfApprox);

INCLUDE_ASM("asm/nonmatchings/main/1D000", constMinusSinfApprox);

INCLUDE_ASM("asm/nonmatchings/main/1D000", atan2Approx);

INCLUDE_ASM("asm/nonmatchings/main/1D000", mat3x3InverseInto);

INCLUDE_ASM("asm/nonmatchings/main/1D000", floatMatrixToFixed);

INCLUDE_ASM("asm/nonmatchings/main/1D000", clearVec4QuadStruct);

INCLUDE_ASM("asm/nonmatchings/main/1D000", addVec3At0x24);

INCLUDE_ASM("asm/nonmatchings/main/1D000", setVec3At0x24);

INCLUDE_ASM("asm/nonmatchings/main/1D000", applyScaleToMat3x4);

void initVec4TripletFromArgs(Mat4x3 arg0, f32 arg1, f32 arg2, f32 arg3) {
    f32 zero = 0.0f;
    arg0[0][0] = arg1;
    arg0[1][1] = arg2;
    arg0[2][2] = arg3;
    arg0[3][0] = zero;
    arg0[0][2] = zero;
    arg0[0][1] = zero;
    arg0[3][1] = zero;
    arg0[1][2] = zero;
    arg0[1][0] = zero;
    arg0[3][2] = zero;
    arg0[2][1] = zero;
    arg0[2][0] = zero;
}

INCLUDE_ASM("asm/nonmatchings/main/1D000", composeRotationMatrixSlot0);

INCLUDE_ASM("asm/nonmatchings/main/1D000", buildRotationMatrixSlot0);

INCLUDE_ASM("asm/nonmatchings/main/1D000", composeRotationMatrixSlot1);

INCLUDE_ASM("asm/nonmatchings/main/1D000", buildRotationMatrixSlot1);

INCLUDE_ASM("asm/nonmatchings/main/1D000", composeRotationMatrixSlot2);

INCLUDE_ASM("asm/nonmatchings/main/1D000", buildRotationMatrixSlot2);

#if 0
f32 vec3Length(Vec3f arg0) {
    return sqrtf((arg0[0] * arg0[0]) + (arg0[1] * arg0[1]) + (arg0[2] * arg0[2]));
}
#else
INCLUDE_ASM("asm/nonmatchings/main/1D000", vec3Length);
#endif

INCLUDE_ASM("asm/nonmatchings/main/1D000", normalize_vector);

INCLUDE_ASM("asm/nonmatchings/main/1D000", vec3NormalizeInto);

f32 vec3Dot(Vec3f arg0, Vec3f arg1) {
    return (arg0[0] * arg1[0]) + (arg0[1] * arg1[1]) + (arg0[2] * arg1[2]);
}

f32 vec2Cross2D(Vec3f arg0, Vec3f arg1) {
    return (arg0[0] * arg1[1]) - (arg0[1] * arg1[0]);
}

INCLUDE_ASM("asm/nonmatchings/main/1D000", quatFromCardinalAxis);

INCLUDE_ASM("asm/nonmatchings/main/1D000", quatFromAxisAngleSafe);

INCLUDE_ASM("asm/nonmatchings/main/1D000", quatFromAxisAngle);

INCLUDE_ASM("asm/nonmatchings/main/1D000", quatMultiply);

void rotateVec3ByQuat(Vec4f arg0, Vec3f arg1, Vec3f arg2) {
    Vec4f temp;

    temp[0] = -((arg0[1] * arg1[0]) + (arg0[2] * arg1[1]) + (arg0[3] * arg1[2]));
    temp[1] =   (arg0[0] * arg1[0]) + (arg0[2] * arg1[2]) - (arg0[3] * arg1[1]);
    temp[2] =   (arg0[0] * arg1[1]) + (arg0[3] * arg1[0]) - (arg0[1] * arg1[2]);
    temp[3] =   (arg0[0] * arg1[2]) + (arg0[1] * arg1[1]) - (arg0[2] * arg1[0]);
    arg2[0] =   (arg0[0] * temp[1]) - (temp[0] * arg0[1]) + (temp[3] * arg0[2]) - (temp[2] * arg0[3]);
    arg2[1] =   (arg0[0] * temp[2]) - (temp[0] * arg0[2]) + (temp[1] * arg0[3]) - (temp[3] * arg0[1]);
    arg2[2] =   (arg0[0] * temp[3]) - (temp[0] * arg0[3]) + (temp[2] * arg0[1]) - (temp[1] * arg0[2]);
}

INCLUDE_ASM("asm/nonmatchings/main/1D000", quatToRotationMatrix);

INCLUDE_ASM("asm/nonmatchings/main/1D000", convertMat3x4ToQuat);

INCLUDE_ASM("asm/nonmatchings/main/1D000", slerpQuaternions);

INCLUDE_ASM("asm/nonmatchings/main/1D000", composeQuatToMat3x4);

INCLUDE_ASM("asm/nonmatchings/main/1D000", transformVec3ToNpcLocalWithScale);

f32 floatModulo(f32 arg0, f32 arg1) {
    f32 temp_fv0;

    temp_fv0 = arg0 / arg1;
    return (temp_fv0 - (s32) temp_fv0) * arg1;
}

INCLUDE_RODATA("asm/nonmatchings/main/1D000", D_main_80000984);
