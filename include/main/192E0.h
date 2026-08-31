#ifndef MAIN_192E0_H
#define MAIN_192E0_H

#include "common_types.h"

void mat3x4Multiply(Mat4x3, Mat4x3, Mat4x3);
void transformVec3ByMat34(Mat4x3, Vec3f, Vec3f);
void vec3Cross(Vec3f, Vec3f, Vec3f);
void zmemcpy(u8*, u8*, u32);

#endif
