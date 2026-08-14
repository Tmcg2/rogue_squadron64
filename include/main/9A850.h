#ifndef MAIN_9A850_H
#define MAIN_9A850_H

#include "PR/ultratypes.h"
#include "common_types.h"

void transformVec3ByAffineMatrix(Mat4x3, Vec3f, Vec3f);
void normalizeVec3(Vec3f);
void crossProductVec3(Vec3f, Vec3f, Vec3f);
void invertOrientationMatrix(Mat4x3, Mat4x3);

#endif
