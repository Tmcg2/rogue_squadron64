#ifndef COMMON_VARIABLES_H
#define COMMON_VARIABLES_H

#include "common_types.h"
#include "crafts.h"
#include "levels.h"

/*
This is something of a dumping ground for extern definitions of variables that are used in a variety of files.
Hopefully it doesn't become a variable landfill.
*/

extern enum   PlayerCraft dDefaultCraftForLevel[NUM_LEVELS];
extern u8 D_main_bss_80130B39; // 0x80130B39

#endif