#ifndef LEVEL_OBJECTIVES_H
#define LEVEL_OBJECTIVES_H

#include "PR/ultratypes.h"

struct D_8010A450_type {
     s32 (*initializeObjectiveTracking)(void); /* 0x0 */
     s32 (*unk4)(void);                        /* 0x4 */
     s32 (*calculateFriendliesSaved)(void);    /* 0x8 */
     s32 (*checkComplexObjectives)(void);      /* 0xC */
}; // size = 0x10

struct simpleCheckHandle {
    void (*handle)(void);     /* 0x00 */
    union {
        struct {
            u8 objectiveBooleanIndex; /* 0x04 */
            u8 objectiveBooleanValue; /* 0x05 */
            u8 objectiveCountIndex;   /* 0x06 */
            u8 unk07;                 /* 0x07 */
        } boolcount;
        struct level_objectives
        {
            f32 timer;
        } timer;
    } checks;
    s32 objectiveCountValue;  /* 0x08 */
    u8 checkType;             /* 0x0C 0 = objective check, 1 = timer check ? */
    u8 unk0D;                 /* 0x0D */
    u8 active;                /* 0x0E */
    u8 unk0F;                 /* 0x0F might be padding? */
}; // size = 0x10

extern s32 gObjectiveCounts[0x80];
extern u8  gObjectiveBooleans[0x80];
extern f32 gObjectiveTimers[8];
extern struct simpleCheckHandle simpleCheckHandles[0x30];

#endif
