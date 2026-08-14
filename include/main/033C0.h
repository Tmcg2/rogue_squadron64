#ifndef MAIN_033C0_H
#define MAIN_033C0_H

#include "PR/os.h"

struct D_main_80110520 {
    /* 0x00 */ OSPfs pfs;
    /* 0x68 */ u8 unk68;
    /* 0x69 */ u8 unk69;
    /* 0x6A */ u8 unk6A;
    /* 0x6B */ u8 unk6B;
    /* 0x6C */ u8 unk6C;
    // All 3 of these might be compiler padding
    /* 0x6D */ // u8 unk6D;
    /* 0x6E */ // u8 unk6E;
    /* 0x6F */ // u8 unk6F;
    /* 0x70 */ void *unk70;
    /* 0x74 */ f32 unk74;
    /* 0x78 */ f32 unk78;
    /* 0x7C */ f32 unk7C;
    /* 0x80 */ f32 unk80;
    /* 0x84 */ u32 unk84;
}; // size 0x88

void processPolledControllerData(void);
u32  startRumbleEffect(u8, void*);
s32  stopRumbleEffect(s32);
void initRumblePakSlots(void);
void serviceRumblePakMotors(void);
void startSiPollingThread(void);
s32  pollControllerInputs(void);
s32  bindControllerStatusBuffer(u8, OSContPad*);
u8   isRumbleSlotActive(u8);
s32  clearControllerPakPresence(u8);
s32  setRumbleSuspended(u8);
void wakeSerialThreadOnSi(void);
void waitForSerialIdle(void);
void releaseSerialLock(void);
void initSiQueue(void);

#endif
