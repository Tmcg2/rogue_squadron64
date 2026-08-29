#ifndef MISSION_STATE_H
#define MISSION_STATE_H

#include "PR/ultratypes.h"

struct MissionState {
    /* 0x00 */ u8  numLives[1];
    /* 0x01 */ u8  playerRank;
    /* 0x02 */ u8  secondaryWeapon;
    /* 0x03 */ u8  secondaryWeaponMax;
    /* 0x04 */ u8  unk4;
    /* 0x05 */ u8  completedObjectiveFlags; // If a flag is 1, the objective is complete and will be colored green
    /* 0x06 */ u8  hiddenObjectiveFlags; // If a flag is 1, the objective IS NOT displayed
    /* 0x07 */ u8  numMissionObjectives;
    // I think these are copied from gGameSettings on level start and then compared against them again afterwards to deduce if a new
    // unlocked was gained during the level
    /* 0x08 */ u32 activeUnlockFlags;
    /* 0x0C */ u8  medalPerLevel[0x13]; // really ought to be enum MEDAL_TYPE, but enums are sized too big
    /* 0x1F */ u8  maxUnlockedLevel; // really ought to be enum Level, but enums are sized too big
    /* 0x20 */ u8  unk20;
    /* 0x21 */ u8  unk21;
    /* 0x22 */ u8  unk22;
    /* 0x23 */ u8  unk23;
    /* 0x24 */ u8  accountNumber;
    /* 0x25 */ u8  anyExtraLevelsUnlocked;
    /* 0x26 */ u8  unk26;
    /* 0x27 */ u8  unk27;
}; // size 0x28

extern struct MissionState gMissionState; // 0x80130B10

#endif
