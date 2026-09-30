#ifndef MENU_110410_H
#define MENU_110410_H

#include "PR/ultratypes.h"

#include "crafts.h"
#include "levels.h"

char *hangarGenerateSecondaryWeaponString(enum Level, enum PlayerCraft);
void  extractTextBeforeFmtChar(char*);
void  hangarLoadShadows(void);

#endif