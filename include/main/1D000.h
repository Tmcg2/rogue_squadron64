#ifndef MAIN_1D000_H
#define MAIN_1D000_H

#include "common_types.h"

void initVec4TripletFromArgs(Mat4x3, f32, f32, f32);
f32 vec3Length(Vec3f);
f32 vec3Dot(Vec3f, Vec3f);
f32 vec2Cross2D(Vec3f, Vec3f);
void rotateVec3ByQuat(Vec4f, Vec3f, Vec3f);

#endif
