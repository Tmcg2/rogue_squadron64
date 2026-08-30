#ifndef MISSION_STATE_H
#define MISSION_STATE_H

#include "PR/ultratypes.h"

struct MissionState {
    u8  numLives[1];             /* 0x00 */
    u8  playerRank;              /* 0x01 */
    u8  secondaryWeapon;         /* 0x02 */
    u8  secondaryWeaponMax;      /* 0x03 */
    u8  unk4;                    /* 0x04 */
    u8  completedObjectiveFlags; /* 0x05 If a flag is 1, the objective is complete and will be colored green */
    u8  hiddenObjectiveFlags;    /* 0x06 If a flag is 1, the objective IS NOT displayed */
    u8  numMissionObjectives;    /* 0x07 */
    // I think these are copied from gGameSettings on level start and then compared against them again afterwards to deduce if a new
    // unlocked was gained during the level
    u32 activeUnlockFlags;       /* 0x08 */
    u8  medalPerLevel[0x13];     /* 0x0C really ought to be enum MEDAL_TYPE, but enums are sized too big */
    u8  maxUnlockedLevel;        /* 0x1F  really ought to be enum Level, but enums are sized too big */
    u8  unk20;                   /* 0x20 */
    u8  unk21;                   /* 0x21 */
    u8  unk22;                   /* 0x22 */
    u8  unk23;                   /* 0x23 */
    u8  accountNumber;           /* 0x24 */
    u8  anyExtraLevelsUnlocked;  /* 0x25 */
    u8  unk26;                   /* 0x26 */
    u8  unk27;                   /* 0x27 */
}; // size 0x28

extern struct MissionState gMissionState; // 0x80130B10

#endif
