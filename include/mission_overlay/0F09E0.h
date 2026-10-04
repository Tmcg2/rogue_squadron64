#ifndef MISSION_0F09E0_H
#define MISSION_0F09E0_H

#include "PR/ultratypes.h"
#include "common_types.h"

s32  isVectorWithinConeAndRange(Mat4x3, f32, f32, Vec3f);
s32  isVectorInConeWriteDistance(Mat4x3, f32, f32, Vec3f, f32*);
s32  computeTurnAxisTowardTarget(Mat4x3, f32, f32, Vec3f, UNIDENTIFIED_TYPE*, struct Struct3f*);
f32  computeTurnVectorTowardTarget(Mat4x3, Vec3f, struct Struct3f*, f32*);
f32  computeTurnVectorAndDistanceToTarget(Mat4x3, Vec3f, struct Struct3f*, f32*);
void computeAnchorRelativePositionByDistanceRatio(Vec3f, Mat4x3, f32, Vec3f);
s32  returnZero_800F3258(void);

#endif
