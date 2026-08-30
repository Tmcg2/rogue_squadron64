#include "common.h"

#include "PR/gu.h"
#include "rs_math.h"
#include "main/192E0.h"
#include "main/1D000.h"

INCLUDE_ASM("asm/nonmatchings/main/1D000", sinfApprox);

f32 constMinusSinfApprox(f32 arg0) {
    return M_HALF_PI_F - sinfApprox(arg0);
}

#if 0
f32 atan2Approx(f32 arg0, f32 arg1) {
    f32 temp_fa0;
    f32 temp_fa0_2;
    f32 temp_fa0_3;
    f32 temp_fa1;

    temp_fa0_2 = (arg0 * arg0) + (arg1 * arg1);
    if (temp_fa0_2 > 0.0f) {
        temp_fa0_3 = sqrtf(temp_fa0_2);
        temp_fa1 = arg1 / temp_fa0_3;
        temp_fa0 = arg0 / temp_fa0_3;
        if (fabs((f64) temp_fa0) < fabs((f64) temp_fa1)) {
            if (temp_fa0 >= 0.0f) {
                if (temp_fa1 >= 0.0f) {
                    return sinfApprox(temp_fa0);
                }
                return 3.1415927f - sinfApprox(temp_fa0);
            }
            if (temp_fa1 >= 0.0f) {
                return 6.2831855f - sinfApprox(-temp_fa0);
            }
            return 3.1415927f + sinfApprox(-temp_fa0);
        }
        if (temp_fa0 >= 0.0f) {
            if (temp_fa1 >= 0.0f) {
                return 1.5707964f - sinfApprox(temp_fa1);
            }
            return 1.5707964f + sinfApprox(-temp_fa1);
        }
        if (temp_fa1 >= 0.0f) {
            return 4.712389f + sinfApprox(temp_fa1);
        }
        return 4.712389f - sinfApprox(-temp_fa1);
    }
    return 0.0f;
}
#else
INCLUDE_ASM("asm/nonmatchings/main/1D000", atan2Approx);
#endif

#if 0
void mat3x3InverseInto(Mat4x3 arg0, Mat4x3 arg1) {
    f32 temp_fa0;
    f32 temp_fa1;
    f32 temp_ft1;
    f32 temp_ft1_2;
    f32 temp_ft1_3;
    f32 temp_ft2;
    f32 temp_ft2_2;
    f32 temp_ft3;
    f32 temp_ft3_2;
    f32 temp_fv0;
    f32 temp_fv1;

    temp_fa1 = arg1[1][1];
    temp_ft1 = arg1[2][2];
    temp_fv1 = arg1[2][1];
    temp_fv0 = arg1[1][2];
    temp_ft2 = arg1[1][0];
    temp_ft3 = arg1[2][0];
    temp_fa0   =   (temp_fa1 * temp_ft1) - (temp_fv1 * temp_fv0);
    // If you change the `-` here to a `+` you get REALLY close to match, but its obviously wrong.
    temp_ft1_2 = -((temp_ft2 * temp_ft1) - (temp_ft3 * temp_fv0));
    temp_ft2_2 =   (temp_ft2 * temp_fv1) - (temp_ft3 * temp_fa1);
    temp_ft3_2 = 1.0f / ((arg1[0][0] * temp_fa0) + (arg1[0][1] * temp_ft1_2) + (arg1[0][2] * temp_ft2_2));
    arg0[0][0] =  temp_ft3_2 * temp_fa0;
    arg0[1][0] =  temp_ft3_2 * temp_ft1_2;
    arg0[2][0] =  temp_ft3_2 * temp_ft2_2;
    arg0[0][1] = -temp_ft3_2 * ((arg1[0][1] * arg1[2][2]) - (arg1[2][1] * arg1[0][2]));
    arg0[1][1] =  temp_ft3_2 * ((arg1[0][0] * arg1[2][2]) - (arg1[2][0] * arg1[0][2]));
    arg0[2][1] = -temp_ft3_2 * ((arg1[0][0] * arg1[2][1]) - (arg1[2][0] * arg1[0][1]));
    arg0[0][2] =  temp_ft3_2 * ((arg1[0][1] * arg1[1][2]) - (arg1[1][1] * arg1[0][2]));
    arg0[1][2] = -temp_ft3_2 * ((arg1[0][0] * arg1[1][2]) - (arg1[1][0] * arg1[0][2]));
    arg0[2][2] =  temp_ft3_2 * ((arg1[0][0] * arg1[1][1]) - (arg1[1][0] * arg1[0][1]));
    arg0[3][0] = ((-arg1[3][0] * arg0[0][0]) - (arg1[3][1] * arg0[0][1])) - (arg1[3][2] * arg0[0][2]);
    arg0[3][1] = ((-arg1[3][0] * arg0[1][0]) - (arg1[3][1] * arg0[1][1])) - (arg1[3][2] * arg0[1][2]);
    arg0[3][2] = ((-arg1[3][0] * arg0[2][0]) - (arg1[3][1] * arg0[2][1])) - (arg1[3][2] * arg0[2][2]);
}
#else
INCLUDE_ASM("asm/nonmatchings/main/1D000", mat3x3InverseInto);
#endif

INCLUDE_ASM("asm/nonmatchings/main/1D000", floatMatrixToFixed);

void clearVec4QuadStruct(Mat4x3 arg0) {
    arg0[2][0] = arg0[2][1] = arg0[3][2] = arg0[1][0] = arg0[1][2] = arg0[3][1] = arg0[0][1] = arg0[0][2] = arg0[3][0] = 0.0f;
    arg0[0][0] = arg0[1][1] = arg0[2][2] = 1.0f;
}

void addVec3At0x24(Mat4x3 arg0, f32 arg1, f32 arg2, f32 arg3) {
    arg0[3][0] += arg1;
    arg0[3][1] += arg2;
    arg0[3][2] += arg3;
}

void setVec3At0x24(Mat4x3 arg0, f32 arg1, f32 arg2, f32 arg3) {
    arg0[3][0] = arg1;
    arg0[3][1] = arg2;
    arg0[3][2] = arg3;
    arg0[2][0] = arg0[2][1] = arg0[1][0] = arg0[1][2] = arg0[0][1] = arg0[0][2] = 0.0f;
    arg0[0][0] = arg0[1][1] = arg0[2][2] = 1.0f;
}

void applyScaleToMat3x4(Mat4x3 arg0, f32 arg1, f32 arg2, f32 arg3) {
    Mat4x3 sp10;

    sp10[0][0] = arg1;
    sp10[1][1] = arg2;
    sp10[2][2] = arg3;
    sp10[2][0] = sp10[2][1] = sp10[3][2] = sp10[1][0] = sp10[1][2] = sp10[3][1] = sp10[0][1] = sp10[0][2] = sp10[3][0] = 0.0f;
    mat3x4Multiply(sp10, arg0, arg0);
}

void initVec4TripletFromArgs(Mat4x3 arg0, f32 arg1, f32 arg2, f32 arg3) {
    f32 zero = 0.0f;
    arg0[0][0] = arg1;
    arg0[1][1] = arg2;
    arg0[2][2] = arg3;
    arg0[2][0] = arg0[2][1] = arg0[3][2] = arg0[1][0] = arg0[1][2] = arg0[3][1] = arg0[0][1] = arg0[0][2] = arg0[3][0] = 0.0f;
}

void composeRotationMatrixSlot0(Mat4x3 arg0, f32 arg1) {
    Mat4x3 sp10;
    f32 temp_fs0;
    f32 temp_fv0;

    temp_fs0 = sinf(DEGREE_TO_RADIAN_F(arg1));
    temp_fv0 = cosf(DEGREE_TO_RADIAN_F(arg1));
    sp10[2][1] = temp_fs0;
    sp10[1][1] = temp_fv0;
    sp10[2][2] = temp_fv0;
    sp10[1][2] = -temp_fs0;
    sp10[1][0] = sp10[2][0] = sp10[3][1] = sp10[3][2] = sp10[0][1] = sp10[0][2] = sp10[3][0] = 0.0f;
    sp10[0][0] = 1.0f;
    mat3x4Multiply(sp10, arg0, arg0);
}

void buildRotationMatrixSlot0(Mat4x3 arg0, f32 arg1) {
    f32 temp_fs0;
    f32 temp_fv0;

    temp_fs0 = sinf(DEGREE_TO_RADIAN_F(arg1));
    temp_fv0 = cosf(DEGREE_TO_RADIAN_F(arg1));
    arg0[2][1] = temp_fs0;
    arg0[1][1] = temp_fv0;
    arg0[2][2] = temp_fv0;
    arg0[1][2] = -temp_fs0;
    arg0[1][0] = arg0[2][0] = arg0[3][1] = arg0[3][2] = arg0[0][1] = arg0[0][2] = arg0[3][0] = 0.0f;
    arg0[0][0] = 1.0f;
}

void composeRotationMatrixSlot1(Mat4x3 arg0, f32 arg1) {
    Mat4x3 sp10;
    f32 temp_fs0;
    f32 temp_fv0;

    temp_fs0 = sinf(DEGREE_TO_RADIAN_F(arg1));
    temp_fv0 = cosf(DEGREE_TO_RADIAN_F(arg1));
    sp10[0][2] = temp_fs0;
    sp10[0][0] = temp_fv0;
    sp10[2][2] = temp_fv0;
    sp10[2][0] = -temp_fs0;
    sp10[1][2] = sp10[2][1] = sp10[3][1] = sp10[3][2] = sp10[0][1] = sp10[1][0] = sp10[3][0] = 0.0f;
    sp10[1][1] = 1.0f;
    mat3x4Multiply(sp10, arg0, arg0);
}

void buildRotationMatrixSlot1(Mat4x3 arg0, f32 arg1) {
    f32 temp_fs0;
    f32 temp_fv0;

    temp_fs0 = sinf(DEGREE_TO_RADIAN_F(arg1));
    temp_fv0 = cosf(DEGREE_TO_RADIAN_F(arg1));
    arg0[0][2] = temp_fs0;
    arg0[0][0] = temp_fv0;
    arg0[2][2] = temp_fv0;
    arg0[2][0] = -temp_fs0;
    arg0[1][2] = arg0[2][1] = arg0[3][1] = arg0[3][2] = arg0[0][1] = arg0[1][0] = arg0[3][0] = 0.0f;
    arg0[1][1] = 1.0f;
}

void composeRotationMatrixSlot2(Mat4x3 arg0, f32 arg1) {
    Mat4x3 sp10;
    f32 temp_fs0;
    f32 temp_fv0;

    temp_fs0 = sinf(DEGREE_TO_RADIAN_F(arg1));
    temp_fv0 = cosf(DEGREE_TO_RADIAN_F(arg1));
    sp10[1][0] = temp_fs0;
    sp10[0][0] = temp_fv0;
    sp10[1][1] = temp_fv0;
    sp10[0][1] = -temp_fs0;
    sp10[2][0] = sp10[2][1] = sp10[3][1] = sp10[3][2] = sp10[0][2] = sp10[1][2] = sp10[3][0] = 0.0f;
    sp10[2][2] = 1.0f;
    mat3x4Multiply(sp10, arg0, arg0);
}

void buildRotationMatrixSlot2(Mat4x3 arg0, f32 arg1) {
    f32 temp_fs0;
    f32 temp_fv0;

    temp_fs0 = sinf(DEGREE_TO_RADIAN_F(arg1));
    temp_fv0 = cosf(DEGREE_TO_RADIAN_F(arg1));
    arg0[1][0] = temp_fs0;
    arg0[0][0] = temp_fv0;
    arg0[1][1] = temp_fv0;
    arg0[0][1] = -temp_fs0;
    arg0[2][0] = arg0[2][1] = arg0[3][1] = arg0[3][2] = arg0[0][2] = arg0[1][2] = arg0[3][0] = 0.0f;
    arg0[2][2] = 1.0f;
}

#if 0
f32 vec3Length(Vec3f arg0) {
    return sqrtf((arg0[0] * arg0[0]) + (arg0[1] * arg0[1]) + (arg0[2] * arg0[2]));
}
#else
INCLUDE_ASM("asm/nonmatchings/main/1D000", vec3Length);
#endif

#if 0
void normalize_vector(Vec3f arg0) {
    f32 x2, y2, z2;
    f32 temp_fv0_2;

    x2 = arg0[0] * arg0[0];
    y2 = arg0[1] * arg0[1];
    z2 = arg0[2] * arg0[2];
    arg0[0] = arg0[0] / sqrtf(x2 + y2 + z2);
    arg0[2] = arg0[2] / sqrtf(x2 + y2 + z2);
    arg0[1] = arg0[1] / sqrtf(x2 + y2 + z2);
}
#else
INCLUDE_ASM("asm/nonmatchings/main/1D000", normalize_vector);
#endif

#if 0
void vec3NormalizeInto(Vec3f arg0, Vec3f arg1) {
    f32 temp_ft1;
    f32 temp_fv0;
    f32 temp_fv0_2;
    f32 temp_fv1;

    temp_ft1 = arg1[0];
    temp_fv1 = arg1[1];
    temp_fv0 = arg1[2];
    temp_fv0_2 = sqrtf((temp_ft1 * temp_ft1) + (temp_fv1 * temp_fv1) + (temp_fv0 * temp_fv0));
    arg0[0] = (arg1[0] / temp_fv0_2);
    arg0[1] = (arg1[1] / temp_fv0_2);
    arg0[2] = (arg1[2] / temp_fv0_2);
}
#else
INCLUDE_ASM("asm/nonmatchings/main/1D000", vec3NormalizeInto);
#endif

f32 vec3Dot(Vec3f arg0, Vec3f arg1) {
    return (arg0[0] * arg1[0]) + (arg0[1] * arg1[1]) + (arg0[2] * arg1[2]);
}

f32 vec2Cross2D(Vec3f arg0, Vec3f arg1) {
    return (arg0[0] * arg1[1]) - (arg0[1] * arg1[0]);
}

void quatFromCardinalAxis(Vec4f arg0, u8 arg1, f32 arg2) {
    f32 temp_fs0;

    arg0[1] = arg0[2] = arg0[3] = 0.0f;
    temp_fs0 = DEGREE_TO_RADIAN_F(arg2) / 2.0f;
    switch (arg1) {
    case 0:
        arg0[1] = 1.0f;
        break;
    case 1:
        arg0[2] = 1.0f;
        break;
    case 2:
        arg0[3] = 1.0f;
        break;
    case 3:
        arg0[1] = -1.0f;
        break;
    case 4:
        arg0[2] = -1.0f;
        break;
    case 5:
        arg0[3] = -1.0f;
        break;
    }
    arg0[0]  = cosf(temp_fs0);
    temp_fs0 = sinf(temp_fs0);
    arg0[1] *= temp_fs0;
    arg0[2] *= temp_fs0;
    arg0[3] *= temp_fs0;
}

#if 0
void quatFromAxisAngleSafe(Vec4f arg0, Vec3f arg1, f32 arg2) {
    f32 temp_fs0;
    f32 temp_fs0_2;
    f32 temp_fs1;
    f32 temp_ft0;
    f32 temp_fv0;
    f32 temp_fv1;
    s32 var_v0;
    s32 var_v1;

    temp_fv0 = arg1[0];
    temp_fv1 = arg1[1];
    temp_ft0 = arg1[2];
    temp_fs1 = sqrtf((temp_fv0 * temp_fv0) + (temp_fv1 * temp_fv1) + (temp_ft0 * temp_ft0));
    temp_fs0 = DEGREE_TO_RADIAN_F(arg2) / 2.0f;
    if (((temp_fs0 != 0.0f) && (temp_fs1 != 0.0f))) {
        arg0[0] = cosf(temp_fs0);
        temp_fs0 = sinf(temp_fs0) / temp_fs1;
        arg0[1] = arg1[0] * temp_fs0;
        arg0[2] = arg1[1] * temp_fs0;
        arg0[3] = arg1[2] * temp_fs0;
    } else {
        arg0[0] = 1.0f;
        arg0[1] = arg0[2] = arg0[3] = 0.0f;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/main/1D000", quatFromAxisAngleSafe);
#endif

void quatFromAxisAngle(Vec4f arg0, Vec3f arg1, f32 arg2) {
    f32 temp_fs0;
    f32 temp_fv0;

    arg0[0]  = cosf(DEGREE_TO_RADIAN_F(arg2) / 2.0f);
    temp_fv0 = sinf(DEGREE_TO_RADIAN_F(arg2) / 2.0f);
    arg0[1] = arg1[0] * temp_fv0;
    arg0[2] = arg1[1] * temp_fv0;
    arg0[3] = arg1[2] * temp_fv0;
}

void quatMultiply(Vec4f arg0, Vec4f arg1, Vec4f arg2) {
    Vec3f sp10;

    arg2[0] = (arg0[0] * arg1[0]) - ((arg0[1] * arg1[1]) + (arg0[2] * arg1[2]) + (arg0[3] * arg1[3]));
    vec3Cross(sp10, &arg0[1], &arg1[1]);
    arg2[1] = (arg0[0] * arg1[1]) + (arg1[0] * arg0[1]) + sp10[0];
    arg2[2] = (arg0[0] * arg1[2]) + (arg1[0] * arg0[2]) + sp10[1];
    arg2[3] = (arg0[0] * arg1[3]) + (arg1[0] * arg0[3]) + sp10[2];
}

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

void quatToRotationMatrix(Vec4f arg0, Mat4x3 arg1) {
    f32 temp_fa0;
    f32 temp_fa0_2;
    f32 temp_fs0;
    f32 temp_fs1;
    f32 temp_fs4;
    f32 temp_ft0;
    f32 temp_ft0_2;
    f32 temp_ft1;
    f32 temp_ft1_2;
    f32 temp_ft2;
    f32 temp_ft2_2;
    f32 temp_ft3;
    f32 temp_ft3_2;
    f32 temp_ft4;
    f32 temp_fv0;
    f32 temp_fv1;
    f32 temp_fv1_2;

    temp_ft3 = arg0[1];
    temp_fa0 = arg0[2];
    temp_ft2 = arg0[3];
    temp_ft1 = arg0[0];
    temp_fv1 = 2.0f / ((temp_ft3 * temp_ft3) + (temp_fa0 * temp_fa0) + (temp_ft2 * temp_ft2) + (temp_ft1 * temp_ft1));
    temp_fs0 = temp_ft3 * temp_fv1;
    temp_ft0 = temp_fa0 * temp_fv1;
    temp_fv1_2 = temp_ft2 * temp_fv1;
    temp_fs1 = temp_ft1 * temp_ft0;
    temp_fv0 = temp_ft1 * temp_fv1_2;
    temp_fs4 = temp_fa0 * temp_ft0;
    temp_ft2_2 = temp_ft2 * temp_fv1_2;
    temp_ft0_2 = temp_ft3 * temp_ft0;
    temp_ft4 = temp_ft3 * temp_fv1_2;
    temp_ft3_2 = temp_ft3 * temp_fs0;
    temp_ft1_2 = temp_ft1 * temp_fs0;
    temp_fa0_2 = temp_fa0 * temp_fv1_2;
    arg1[0][0] = 1.0f - (temp_fs4 + temp_ft2_2);
    arg1[1][0] = temp_ft0_2 + temp_fv0;
    arg1[2][0] = temp_ft4 - temp_fs1;
    arg1[0][1] = temp_ft0_2 - temp_fv0;
    arg1[1][1] = 1.0f - (temp_ft3_2 + temp_ft2_2);
    arg1[2][1] = temp_fa0_2 + temp_ft1_2;
    arg1[0][2] = temp_ft4 + temp_fs1;
    arg1[1][2] = temp_fa0_2 - temp_ft1_2;
    arg1[2][2] = 1.0f - (temp_ft3_2 + temp_fs4);
    arg1[3][0] = (arg1[3][1] = (arg1[3][2] = 0.0f));
}

#if 0
void convertMat3x4ToQuat(Mat4x3 arg0, Vec4f arg1) {
    f32 temp_ft0;
    f32 temp_ft1;
    f32 temp_ft1_2;
    f32 temp_ft1_3;
    f32 temp_ft1_4;
    f32 temp_ft1_5;
    f32 temp_ft2;
    f32 temp_fv1;
    s32 temp_a2_2;
    s32 temp_t0_2;
    s32 temp_t1;
    s32 temp_t1_2;
    s32 temp_v0;
    s32 var_t1;
    u8 temp_a2;
    u8 temp_t0;
    void *temp_a0;
    void *temp_a1;
    void *temp_a3;
    void *temp_t4;

    temp_ft1 = arg0[0][0];
    temp_fv1 = arg0[1][1];
    temp_ft2 = arg0[2][2];
    temp_ft0 = temp_ft1 + temp_fv1 + temp_ft2;
    if (temp_ft0 > 0.0f) {
        temp_ft1_2 = sqrtf(temp_ft0 + 1.0f);
        temp_ft1_3 = 0.5f / temp_ft1_2;
        arg1[0] = (f32) (temp_ft1_2 * 0.5f);
        arg1[1] = (f32) ((arg0[2][1] - arg0[1][2]) * temp_ft1_3);
        arg1[2] = (f32) ((arg0[0][2] - arg0[2][0]) * temp_ft1_3);
        arg1[3] = (f32) ((arg0[1][0] - arg0[0][1]) * temp_ft1_3);
        return;
    }
    var_t1 = 0;
    temp_t4 = arg1 + 4;
    if (temp_ft1 < temp_fv1) {
        var_t1 = 1;
    }
    if (arg0[var_t1][var_t1] < temp_ft2) {
        var_t1 = 2;
    }
    temp_a2 = D_main_80037840[var_t1];
    temp_t0 = D_main_80037840[temp_a2];
    temp_ft1_4 = sqrtf((arg0[var_t1][var_t1] - (arg0[temp_a2][temp_a2] + arg0[temp_t0][temp_t0])) + 1.0f);
    temp_ft1_5 = 0.5f / temp_ft1_4;
    arg1[0] = (arg0[temp_t0][temp_a2] - arg0[temp_a2][temp_t0]) * temp_ft1_5;
    arg1[var_t1 + 1] = temp_ft1_4 * 0.5f;
    arg1[temp_a2 + 1] = (arg0[temp_a2][var_t1] + arg0[var_t1][temp_a2]) * temp_ft1_5;
    arg1[temp_t0 + 1] = (arg0[temp_t0][var_t1] + arg0[var_t1][temp_t0]) * temp_ft1_5;
}
#else
INCLUDE_ASM("asm/nonmatchings/main/1D000", convertMat3x4ToQuat);
#endif

#if 0
void slerpQuaternions(Vec4f arg0, Vec4f arg1, f32 arg2, Vec4f arg3) {
    f32 temp_ft3;
    f64 temp_fa0;
    f64 temp_fs0;
    f64 temp_fs0_2;
    f64 temp_fs1;
    f64 temp_fs2;
    f64 var_fa0;
    f64 var_fs2;

    temp_ft3 = arg0[2];
    temp_fs0 = (arg0[1] * arg1[1]) + (temp_ft3 * arg1[2]) + (arg0[3] * arg1[3]) + (arg0[0] * arg1[0]);
    if ((temp_fs0 + 1.0) > 1e-5) {
        if ((1.0 - temp_fs0) > 1e-5) {
            temp_fs1 = M_HALF_PI_F - sinfApprox(temp_fs0);
            temp_fs0_2 = sqrtf(1.0f - (f32) (temp_fs0 * temp_fs0));
            var_fs2 = sinf((1.0f - arg2) * temp_fs1);
            var_fa0 = sinf(arg2 * temp_fs1);
            var_fs2 /= temp_fs0_2;
            var_fa0 /= temp_fs0_2;
        } else {
            var_fa0 = arg2;
            var_fs2 = 1.0f - arg2;
        }
        arg3[1] = (f32) ((var_fs2 * (f64) arg0[1]) + (var_fa0 * (f64) arg1[1]));
        arg3[2] = (f32) ((var_fs2 * (f64) arg0[2]) + (var_fa0 * (f64) arg1[2]));
        arg3[3] = (f32) ((var_fs2 * (f64) arg0[3]) + (var_fa0 * (f64) arg1[3]));
        arg3[0] = (f32) ((var_fs2 * (f64) arg0[0]) + (var_fa0 * (f64) arg1[0]));
    } else {
        arg3[1] = (f32) -temp_ft3;
        arg3[2] = (f32) arg0[1];
        arg3[3] = (f32) -arg0[0];
        arg3[0] = (f32) arg0[3];
        temp_fs2 = (f64) sinf((1.0f - arg2) * M_HALF_PI_F);
        temp_fa0 = (f64) sinf(arg2 * M_HALF_PI_F);
        arg3[1] = (f32) ((temp_fs2 * (f64) arg0[1]) + (temp_fa0 * (f64) arg3[1]));
        arg3[2] = (f32) ((temp_fs2 * (f64) arg0[2]) + (temp_fa0 * (f64) arg3[2]));
        arg3[3] = (f32) ((temp_fs2 * (f64) arg0[3]) + (temp_fa0 * (f64) arg3[3]));
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/main/1D000", slerpQuaternions);
#endif

void composeQuatToMat3x4(Mat4x3 arg0, Vec4f arg1) {
    Mat4x3 sp10;
    f32 temp_fa1;
    f32 temp_fs0;
    f32 temp_fs1;
    f32 temp_fs4;
    f32 temp_ft0;
    f32 temp_ft0_2;
    f32 temp_ft1;
    f32 temp_ft1_2;
    f32 temp_ft2;
    f32 temp_ft2_2;
    f32 temp_ft3;
    f32 temp_ft3_2;
    f32 temp_ft5;
    f32 temp_fv0;
    f32 temp_fv0_2;
    f32 temp_fv1;
    f32 temp_fv1_2;

    temp_ft2 = arg1[1];
    temp_ft3 = arg1[2];
    temp_ft1 = arg1[3];
    temp_ft0 = arg1[0];
    temp_fv1 = 2.0f / ((temp_ft2 * temp_ft2) + (temp_ft3 * temp_ft3) + (temp_ft1 * temp_ft1) + (temp_ft0 * temp_ft0));
    temp_fs0 = temp_ft2 * temp_fv1;
    temp_fv0 = temp_ft3 * temp_fv1;
    temp_fv1_2 = temp_ft1 * temp_fv1;
    temp_fs1 = temp_ft0 * temp_fv0;
    temp_ft5 = temp_ft0 * temp_fv1_2;
    temp_fs4 = temp_ft3 * temp_fv0;
    temp_ft1_2 = temp_ft1 * temp_fv1_2;
    temp_fv0_2 = temp_ft2 * temp_fv0;
    temp_fa1 = temp_ft2 * temp_fv1_2;
    temp_ft2_2 = temp_ft2 * temp_fs0;
    temp_ft0_2 = temp_ft0 * temp_fs0;
    temp_ft3_2 = temp_ft3 * temp_fv1_2;
    sp10[3][2] = 0.0f;
    sp10[3][1] = 0.0f;
    sp10[3][0] = 0.0f;
    sp10[0][0] = 1.0f - (temp_fs4 + temp_ft1_2);
    sp10[1][0] = temp_fv0_2 + temp_ft5;
    sp10[2][0] = temp_fa1 - temp_fs1;
    sp10[0][1] = temp_fv0_2 - temp_ft5;
    sp10[1][1] = 1.0f - (temp_ft2_2 + temp_ft1_2);
    sp10[2][1] = temp_ft3_2 + temp_ft0_2;
    sp10[0][2] = temp_fa1 + temp_fs1;
    sp10[1][2] = temp_ft3_2 - temp_ft0_2;
    sp10[2][2] = 1.0f - (temp_ft2_2 + temp_fs4);
    mat3x4Multiply((f32 (*)[3]) &sp10, arg0, arg0);
}

INCLUDE_ASM("asm/nonmatchings/main/1D000", transformVec3ToNpcLocalWithScale);

f32 floatModulo(f32 arg0, f32 arg1) {
    f32 temp_fv0;

    temp_fv0 = arg0 / arg1;
    return (temp_fv0 - (s32) temp_fv0) * arg1;
}

INCLUDE_RODATA("asm/nonmatchings/main/1D000", D_main_80000984);
