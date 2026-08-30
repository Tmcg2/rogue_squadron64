#ifndef MAIN_1D000_H
#define MAIN_1D000_H

#include "common_types.h"

f32  sinfApprox(f32);
f32  constMinusSinfApprox(f32);
f32  atan2Approx(f32, f32);
void mat3x3InverseInto(Mat4x3, Mat4x3);
void clearVec4QuadStruct(Mat4x3);
void addVec3At0x24(Mat4x3, f32, f32, f32);
void setVec3At0x24(Mat4x3, f32, f32, f32);
void applyScaleToMat3x4(Mat4x3, f32, f32, f32);
void initVec4TripletFromArgs(Mat4x3, f32, f32, f32);
void composeRotationMatrixSlot0(Mat4x3, f32);
void buildRotationMatrixSlot0(Mat4x3, f32);
void composeRotationMatrixSlot1(Mat4x3, f32);
void buildRotationMatrixSlot1(Mat4x3, f32);
void composeRotationMatrixSlot2(Mat4x3, f32);
void buildRotationMatrixSlot2(Mat4x3, f32);
f32  vec3Length(Vec3f);
void normalize_vector(Vec3f);
void vec3NormalizeInto(Vec3f, Vec3f);
f32  vec3Dot(Vec3f, Vec3f);
f32  vec2Cross2D(Vec3f, Vec3f);
void quatFromCardinalAxis(Vec4f, u8, f32);
void quatFromAxisAngleSafe(Vec4f, Vec3f, f32);
void quatFromAxisAngle(Vec4f, Vec3f, f32);
void quatMultiply(Vec4f, Vec4f, Vec4f);
void rotateVec3ByQuat(Vec4f, Vec3f, Vec3f);
void quatToRotationMatrix(Vec4f, Mat4x3);
void convertMat3x4ToQuat(Mat4x3, Vec4f);
void slerpQuaternions(Vec4f, Vec4f, f32, Vec4f);
void composeQuatToMat3x4(Mat4x3, Vec4f);
#endif
