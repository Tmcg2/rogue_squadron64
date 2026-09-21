#include "common.h"

#include "PR/os.h"

#include "main/01850.h"

// Interim BSS externs
// This stuff very messy because I don't want to keep going back to 8010D200.bss.s
// to find all this

// D_main_bss_8010D200, 0x8
// D_main_bss_8010D208, 0x8
extern u8 D_main_bss_8010D210;
extern u8 D_main_bss_8010D211[7]; // I bet this is really padding
extern OSThread gIdleThread;
extern OSThread gVideoThread;
// D_main_8010D580, 0x18
// D_main_8010D598, 0x4
// D_main_bss_8010D59C, 0x804
// D_main_8010DDA0, 0x1B0
// D_main_bss_8010DF50, 0x80
// D_main_8010DFD0, 0x4
// D_main_bss_8010DFD4, 0x2
// D_main_bss_8010DFD6, 0x2
// D_main_8010DFD8, 0x30
// D_main_bss_8010E008, 0x8
// D_main_bss_8010E010, 0x80
// D_main_bss_8010E090, 0x818
// D_main_bss_8010E8A8, 0x4
// D_main_bss_8010E8AC, 0x4
// D_main_bss_8010E8B0, 0x1000
// D_main_bss_8010F8B0, 0x400
// D_main_bss_8010FCB0, 0x228
// D_main_bss_8010FED8, 0x08

// Externs that belong to other files
// Ideally tese get delete at some point
extern u8 D_main_bss_801143B0[0x2000]; // video thread stack

u8 isPreNmiPending(void) {
    return D_main_bss_8010D210;
}

s32 returnZeroStub(void) {
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/main/01850", mainBootstrapWorker);

INCLUDE_ASM("asm/nonmatchings/main/01850", partitionFramebufferMemory);

INCLUDE_ASM("asm/nonmatchings/main/01850", thread3_video_handle);

INCLUDE_ASM("asm/nonmatchings/main/01850", runVideoFrameTick);

INCLUDE_ASM("asm/nonmatchings/main/01850", main);

INCLUDE_ASM("asm/nonmatchings/main/01850", preNmiResetThread);

void idle_thread_handle(void) {
    osCreateViManager(0xFE);
    osViBlack(1U);
    osCreateThread(&gVideoThread, 0, thread3_video_handle, NULL, (u32)&D_main_bss_801143B0 + sizeof(D_main_bss_801143B0), 9);
    osStartThread(&gVideoThread);
    osSetThreadPri(NULL, 0);
    while(1);
}
