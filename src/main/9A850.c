#include "common.h"

#include "main/832A0.h"
#include "main/9A850.h"

void transformVec3ByAffineMatrix(Mat4x3 arg0, Vec3f arg1, Vec3f arg2) {
    arg2[0] = (arg0[0][0] * arg1[0]) + (arg0[0][1] * arg1[1]) + (arg0[0][2] * arg1[2]) + arg0[3][0];
    arg2[1] = (arg0[1][0] * arg1[0]) + (arg0[1][1] * arg1[1]) + (arg0[1][2] * arg1[2]) + arg0[3][1];
    arg2[2] = (arg0[2][0] * arg1[0]) + (arg0[2][1] * arg1[1]) + (arg0[2][2] * arg1[2]) + arg0[3][2];
}

#if 0
void normalizeVec3(Vec3f arg0) {
    f32 temp_fa0;
    f32 temp_fv0;
    f32 temp_fv0_2;
    f32 temp_fv1;

    temp_fv0_2 = sqrtf_recomp((arg0[0] * arg0[0]) + (arg0[1] * arg0[1]) + (arg0[2] * arg0[2]));
    arg0[0] /= temp_fv0_2;
    arg0[1] /= temp_fv0_2;
    arg0[2] /= temp_fv0_2;
}
#else
INCLUDE_ASM("asm/nonmatchings/main/9A850", normalizeVec3);
#endif

void crossProductVec3(Vec3f arg0, Vec3f arg1, Vec3f arg2) {
    arg0[0] = (arg1[1] * arg2[2]) - (arg1[2] * arg2[1]);
    arg0[1] = (arg1[2] * arg2[0]) - (arg1[0] * arg2[2]);
    arg0[2] = (arg1[0] * arg2[1]) - (arg1[1] * arg2[0]);
}

#if 0
void invertOrientationMatrix(Mat4x3 arg0, Mat4x3 arg1) {
    f32 temp_fa0;
    f32 temp_ft1_2;
    f32 temp_ft2_2;
    f32 temp_ft3_2;
    f32 determinat;

    temp_fa0   =   (arg1[1][1] * arg1[2][2]) - (arg1[2][1] * arg1[1][2]);
    temp_ft1_2 = -((arg1[1][0] * arg1[2][2]) - (arg1[2][0] * arg1[1][2]));
    temp_ft2_2 =   (arg1[1][0] * arg1[2][1]) - (arg1[2][0] * arg1[1][1]);
    determinat = (arg1[0][0] * temp_fa0) + (arg1[0][1] * temp_ft1_2) + (arg1[0][2] * temp_ft2_2);
    temp_ft3_2 = 1.0f / determinat;
    arg0[0][0] =  temp_ft3_2 * temp_fa0;
    arg0[1][0] =  temp_ft3_2 * temp_ft1_2;
    arg0[2][0] =  temp_ft3_2 * temp_ft2_2;
    arg0[0][1] = -temp_ft3_2 * ((arg1[0][1] * arg1[2][2]) - (arg1[2][1] * arg1[0][2]));
    arg0[1][1] =  temp_ft3_2 * ((arg1[0][0] * arg1[2][2]) - (arg1[2][0] * arg1[0][2]));
    arg0[2][1] = -temp_ft3_2 * ((arg1[0][0] * arg1[2][1]) - (arg1[2][0] * arg1[0][1]));
    arg0[0][2] =  temp_ft3_2 * ((arg1[0][1] * arg1[1][2]) - (arg1[1][1] * arg1[0][2]));
    arg0[1][2] = -temp_ft3_2 * ((arg1[0][0] * arg1[1][2]) - (arg1[1][0] * arg1[0][2]));
    arg0[2][2] =  temp_ft3_2 * ((arg1[0][0] * arg1[1][1]) - (arg1[1][0] * arg1[0][1]));
    arg0[3][0] = (-arg1[3][0] * arg0[0][0]) - (arg1[3][1] * arg0[0][1]) - (arg1[3][2] * arg0[0][2]);
    arg0[3][1] = (-arg1[3][0] * arg0[1][0]) - (arg1[3][1] * arg0[1][1]) - (arg1[3][2] * arg0[1][2]);
    arg0[3][2] = (-arg1[3][0] * arg0[2][0]) - (arg1[3][1] * arg0[2][1]) - (arg1[3][2] * arg0[2][2]);
}

// DO NOT DELETE ME I AM REQUIRED FOR MATCHING
const u32 rodata_junk[] = {
    0x00000000,
    0x8FA9002C,
    0x8DAB0008,
};
#else
INCLUDE_ASM("asm/nonmatchings/main/9A850", invertOrientationMatrix);
#endif

INCLUDE_ASM("asm/nonmatchings/main/9A850", fake_func_80099FDC);

INCLUDE_RODATA("asm/nonmatchings/main/9A850", D_main_8003DEF0); // Can be removed when invertOrientationMatrix is matched
