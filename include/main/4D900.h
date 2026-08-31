#ifndef MAIN_4D900_H
#define MAIN_4D900_H

#include "PR/ultratypes.h"
#include "common_types.h"
#include "rs_math.h"

void computeAimAnglesFromObjectPositions(Mat4x3, Mat4x3, Vec3f, f32);
void computeAimAnglesFromPoints(Vec3f, Vec3f, Vec3f, f32);

#endif
