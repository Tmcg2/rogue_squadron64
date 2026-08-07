#ifndef COMMON_VARIABLES_H
#define COMMON_VARIABLES_H

#include "common_types.h"

/*
This is something of a dumping ground for extern definitions of variables that are used in a variety of files.
Hopefully it doesn't become a variable landfill.
*/

extern enum   PlayerCraft dDefaultCraftForLevel[NUM_LEVELS];
extern struct MissionState gMissionState; // 0x80130B10
extern u8 D_main_bss_80130B39; // 0x80130B39
extern struct GameSettings gGameSettings; // 0x80130B40
extern struct D_8013A5C0_type gSaveDataBody; // 0x8013A5C0

#endif