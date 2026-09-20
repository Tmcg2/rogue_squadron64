#ifndef MISSION_0AA780_H
#define MISSION_0AA780_H

#include "PR/ultratypes.h"
#include "common_types.h"

void computeAngleToTargetFromTransform(Mat4x3, Vec3f, Vec3f);
void buildOrientationFromPosAndAngles(Mat4x3, Vec3f, Vec3f);
void stepAngleTowardTarget(Vec3f, Vec3f, f32, Vec3f);
void clampVec3ToUnitIfLongerThan(Vec3f);
void scaleVec3ByScalar(Vec3f, f32, Vec3f);
void addScaledVec3ToVec3(Vec3f, Vec3f, f32, Vec3f);
void buildRotationMatrixFromEulerAngles(Mat4x3, f32, f32, f32);
void buildTransformMatrixFromEulerAngles(Mat4x3, f32, f32, f32);

#endif
