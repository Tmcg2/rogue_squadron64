#ifndef MAIN_7A8E0_H
#define MAIN_7A8E0_H

#include "PR/ultratypes.h"

void setNewAndPreviousButtonsPressed(void);
u32  getControllerButtonAndStick(u8);
void initNewAndPreviousButtonsPressed(void);
s32  isControllerStickReady(u8);
u32  readControllerInputs(u8);
u32  getControllerNewButtonsPressed(u8);
void pollControllerUntilButtonsLatched(u8);
void unsetControllerNewButtonsPressed(u8, u32);
f32  getControllerStickXPercentageGated(u8);
f32  getControllerStickYPercentageGated(u8);
f32  getControllerStickXPercentage(u8);
f32  getControllerStickYPercentage(u8);

#endif
