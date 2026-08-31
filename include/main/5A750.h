#ifndef MAIN_5A750_H
#define MAIN_5A750_H

#include "common_types.h"
#include "main/192E0.h"

void mat34CrossRowsAndCopyPos(Mat4x3, Mat4x3, f32);
void mat34CrossRowsAndCopyPosPtr(Mat4x3, Mat4x3, Vec3f);
// The type of arg1 might be wrong, can't say for certain at the moment...
void extractOrthonormalFrameFromStruct(Mat4x3, Mat4x3);
void composeEulerRotationXYZ(Mat4x3, f32, f32, f32);
void computeBillboardFacingVector(Mat4x3, Vec3f);
void orthonormalizeFrame(Mat4x3);
void orthonormalizeFrameAndSnapToZero(Mat4x3);

#endif
