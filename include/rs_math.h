#ifndef RSMATH_H
#define RSMATH_H

#define M_PI_F    3.14159265358979323846f
// This OUGHT to just be (M_PI_F/180.f), but that leads to silly floating point rounding differenes. Literally 1 bit off >:(
#define M_DTOR_F 0.01745329238474369f
#define DEGREE_TO_RADIAN_F(x) ((x) * M_DTOR_F)

#define M_HALF_PI_F (M_PI_F / 2.0f)

#endif
