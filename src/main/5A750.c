#include "common.h"

#include "rs_math.h"
#include "main/1D000.h"
#include "main/5A750.h"

void mat34CrossRowsAndCopyPos(Mat4x3 arg0, Mat4x3 arg1, f32 arg2) {
    arg0[0][0] = ((arg1[2][1] * arg1[1][2]) - (arg1[2][2] * arg1[1][1])) * arg2;
    arg0[1][0] = ((arg1[2][2] * arg1[1][0]) - (arg1[2][0] * arg1[1][2])) * arg2;
    arg0[2][0] = ((arg1[2][0] * arg1[1][1]) - (arg1[2][1] * arg1[1][0])) * arg2;
    arg0[0][1] = arg1[2][0] * arg2;
    arg0[1][1] = arg1[2][1] * arg2;
    arg0[2][1] = arg1[2][2] * arg2;
    arg0[0][2] = arg1[1][0] * arg2;
    arg0[1][2] = arg1[1][1] * arg2;
    arg0[2][2] = arg1[1][2] * arg2;
    arg0[3][0] = arg1[0][0];
    arg0[3][1] = arg1[0][1];
    arg0[3][2] = arg1[0][2];
}

void mat34CrossRowsAndCopyPosPtr(Mat4x3 arg0, Mat4x3 arg1, Vec3f arg2) {
    arg0[0][0] = ((arg1[2][1] * arg1[1][2]) - (arg1[2][2] * arg1[1][1])) * arg2[0];
    arg0[1][0] = ((arg1[2][2] * arg1[1][0]) - (arg1[2][0] * arg1[1][2])) * arg2[0];
    arg0[2][0] = ((arg1[2][0] * arg1[1][1]) - (arg1[2][1] * arg1[1][0])) * arg2[0];
    arg0[0][1] = arg1[2][0] * arg2[1];
    arg0[1][1] = arg1[2][1] * arg2[1];
    arg0[2][1] = arg1[2][2] * arg2[1];
    arg0[0][2] = arg1[1][0] * arg2[2];
    arg0[1][2] = arg1[1][1] * arg2[2];
    arg0[2][2] = arg1[1][2] * arg2[2];
    arg0[3][0] = arg1[0][0];
    arg0[3][1] = arg1[0][1];
    arg0[3][2] = arg1[0][2];
}

// The type of arg1 might be wrong, can't say for certain at the moment...
void extractOrthonormalFrameFromStruct(Mat4x3 arg0, Mat4x3 arg1) {
    arg0[0][0] = arg1[3][0];
    arg0[0][1] = arg1[3][1];
    arg0[0][2] = arg1[3][2];
    arg0[1][0] = arg1[0][2];
    arg0[1][1] = arg1[1][2];
    arg0[1][2] = arg1[2][2];
    arg0[2][0] = arg1[0][1];
    arg0[2][1] = arg1[1][1];
    arg0[2][2] = arg1[2][1];
    orthonormalizeFrame(arg0);
}

void composeEulerRotationXYZ(Mat4x3 arg0, f32 arg1, f32 arg2, f32 arg3) {
    Mat4x3 sp10;
    buildRotationMatrixSlot0(sp10, arg1);
    composeRotationMatrixSlot1(sp10, arg2);
    composeRotationMatrixSlot2(sp10, arg3);
    arg0[1][0] = sp10[0][2];
    arg0[1][1] = sp10[1][2];
    arg0[1][2] = sp10[2][2];
    arg0[2][0] = sp10[0][1];
    arg0[2][1] = sp10[1][1];
    arg0[2][2] = sp10[2][1];
}

void computeBillboardFacingVector(Mat4x3 arg0, Vec3f arg1) {
    Vec3f sp10;
    Vec3f sp20;
    Mat4x3 sp30;

    arg1[1] = RADIAN_TO_DEGREE_F(atan2Approx(arg0[1][0], arg0[1][2]));
    buildRotationMatrixSlot1(sp30, -arg1[1]);
    transformVec3ByMat34(sp30, arg0[1], sp10);
    transformVec3ByMat34(sp30, arg0[2], sp20);
    sp10[0] = 0.0f;
    arg1[0] = RADIAN_TO_DEGREE_F(-atan2Approx(sp10[1], sp10[2]));
    buildRotationMatrixSlot0(sp30, -arg1[0]);
    transformVec3ByMat34(sp30, sp20, sp10);
    if (sp10[1] >= 0.0f) {
        arg1[2] = 0.0f;
    } else {
        arg1[2] = 180.0f;
        arg1[0] = -arg1[0];
        arg1[1] = -arg1[1];
    }
}

void orthonormalizeFrame(Mat4x3 arg0) {
    Vec3f sp10;

    normalize_vector(arg0[1]);
    vec3Cross(sp10, arg0[2], arg0[1]);
    normalize_vector(sp10);
    vec3Cross(arg0[2], arg0[1], sp10);
}

#if 0
void orthonormalizeFrameAndSnapToZero(Mat4x3 arg0) {
    Vec3f sp10;
    f32 val;

    normalize_vector(arg0[1]);
    vec3Cross(sp10, arg0[2], arg0[1]);
    normalize_vector(sp10);
    vec3Cross(arg0[2], arg0[1], sp10);
    if (fabsf(arg0[1][0]) < 1e-7f) {
        arg0[1][0] = 0.0f;
    }
    if (fabsf(arg0[1][1]) < 1e-7f) {
        arg0[1][1] = 0.0f;
    }
    if (fabsf(arg0[1][2]) < 1e-7f) {
        arg0[1][2] = 0.0f;
    }
    if (fabsf(arg0[2][0]) < 1e-7f) {
        arg0[2][0] = 0.0f;
    }
    if (fabsf(arg0[2][1]) < 1e-7f) {
        arg0[2][1] = 0.0f;
    }
    if (fabsf(arg0[2][2]) < 1e-7f) {
        arg0[2][2] = 0.0f;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/main/5A750", orthonormalizeFrameAndSnapToZero);
#endif

INCLUDE_ASM("asm/nonmatchings/main/5A750", isPointWithinBoundingBox);

INCLUDE_ASM("asm/nonmatchings/main/5A750", fake_func_8005A11C);
