#ifndef MENU_110410_H
#define MENU_110410_H

#include "PR/ultratypes.h"

#include "crafts.h"
#include "levels.h"

void  hangarInitialize(s32, u8, s32, u8);
s32   runHangarSelectionFrame(u8);
s32   tickEasedCameraKeyframeBlend(Vec3f, Vec3f, f32);
char *hangarGenerateSecondaryWeaponString(enum Level, enum PlayerCraft);
void  gracefulMenuShutdown(void);
void  extractTextBeforeFmtChar(char*);
void  hangarLoadShadows(void);

#endif