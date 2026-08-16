#ifndef MISSION_0F3E90_H
#define MISSION_0F3E90_H

#include "PR/ultratypes.h"

s32 initializeObjectiveHandles(void);
s32 addBooleanCountHandle(void (*)(), u8, u8, u8, u32, u8);
s32 addTimerHandle(void (*)(), f32);

#endif
