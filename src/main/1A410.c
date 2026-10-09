#include "common.h"

#include "main/bss_801128E0.h"
#include "main/1A410.h"

// Interim Data externs
// These may not be placed correctly in this file, they may belong in 08510.c instead
extern volatile s8 D_main_80037808;

void awaitFrameSyncMesgBlock(void) {
    osRecvMesg(&D_main_bss_80128D10, NULL, 1);
}

void signalFrameSyncMesgNonblock(void) {
    osSendMesg(&D_main_bss_80128D10, NULL, 0);
}

INCLUDE_ASM("asm/nonmatchings/main/1A410", viRetraceHandlerThread);

void yieldCurrentThread(void) {
    osYieldThread();
}

s32 getInactiveBufferIndex(void) {
    return D_main_bss_80128D2C ^ 1;
}

INCLUDE_ASM("asm/nonmatchings/main/1A410", spTaskSchedulerThread);

void yieldFromSpThread(void) {
    osYieldThread();
}

void yieldFromGfxFrame(void) {
    osYieldThread();
}

INCLUDE_ASM("asm/nonmatchings/main/1A410", postViThreadCommand);

INCLUDE_ASM("asm/nonmatchings/main/1A410", initVideoSubsystem);

s32 requestViFeatureChange(s32 arg0) {
    D_main_bss_80128E90 = arg0;
    return 1;
}

s32 beginSceneRenderFrame(s32 arg0) {
    D_main_bss_80128E94 = arg0;
    return 1;
}

void clearPendingViChanges(void) {
    D_main_bss_80128E90 = 0;
    D_main_bss_80128E94 = 0;
}

void applyPendingViChanges(void) {
    OSViMode *var_a0;

    if (D_main_bss_80128E94 & 1) {
        D_main_bss_8011A860[2] = 0;
    }
    if (D_main_bss_80128E94 & 8) {
        D_main_bss_8011A860[5] = 0;
    }
    if (D_main_bss_80128E90 & 1) {
        D_main_bss_8011A860[2] = 1;
    }
    if (D_main_bss_80128E90 & 8) {
        D_main_bss_8011A860[5] = 1;
    }
    if ((D_main_bss_80128E94 | D_main_bss_80128E90) & 9) {
        if ((D_main_bss_8011A860[5] == 0) || (D_main_bss_8011A860[4] != 0)) {
            if (D_main_bss_8011A860[2] == 0) {
                var_a0 = &D_main_bss_80128D50[1];
            } else {
                var_a0 = &D_main_bss_80128D50[0];
            }
        } else {
            if (D_main_bss_8011A860[2] != 0) {
                var_a0 = &D_main_bss_80128D50[2];
            } else {
                var_a0 = &D_main_bss_80128D50[3];
            }
        }
        osViSetMode(var_a0);
        if (!((D_main_bss_80128E90 | D_main_bss_80128E94) & 2)) {
            if (D_main_bss_8011A860[8] != 0) {
                osViSetSpecialFeatures(OS_VI_GAMMA_ON);
            } else {
                osViSetSpecialFeatures(OS_VI_GAMMA_OFF);
            }
        }
        if (!((D_main_bss_80128E90 | D_main_bss_80128E94) & 4)) {
            if (D_main_bss_8011A860[6] != 0) {
                osViSetSpecialFeatures(OS_VI_DITHER_FILTER_ON);
            } else {
                osViSetSpecialFeatures(OS_VI_DITHER_FILTER_OFF);
            }
        }
        if (!((D_main_bss_80128E90 | D_main_bss_80128E94) & 0x10)) {
            if (D_main_bss_8011A860[7] != 0) {
                osViSetSpecialFeatures(OS_VI_DIVOT_ON);
            } else {
                osViSetSpecialFeatures(OS_VI_DIVOT_OFF);
            }
        }
    }
    if (D_main_bss_80128E94 & 2) {
        osViSetSpecialFeatures(OS_VI_GAMMA_OFF);
        D_main_bss_8011A860[8] = 0;
    }
    if (D_main_bss_80128E94 & 4) {
        osViSetSpecialFeatures(OS_VI_DITHER_FILTER_OFF);
        D_main_bss_8011A860[6] = 0;
    }
    if (D_main_bss_80128E94 & 0x10) {
        osViSetSpecialFeatures(OS_VI_DIVOT_OFF);
        D_main_bss_8011A860[7] = 0;
    }
    if (D_main_bss_80128E90 & 2) {
        osViSetSpecialFeatures(OS_VI_GAMMA_ON);
        D_main_bss_8011A860[8] = 1;
    }
    if (D_main_bss_80128E90 & 4) {
        osViSetSpecialFeatures(OS_VI_DITHER_FILTER_ON);
        D_main_bss_8011A860[6] = 1;
    }
    if (D_main_bss_80128E90 & 0x10) {
        osViSetSpecialFeatures(OS_VI_DIVOT_ON);
        D_main_bss_8011A860[7] = 1;
    }
    D_main_bss_80128E94 = 0;
    D_main_bss_80128E90 = 0;
}

INCLUDE_ASM("asm/nonmatchings/main/1A410", swapBufferWithViMode);

#if 0
void selectAndApplyViMode(void) {
    OSViMode *var_v1;

    var_v1 = &D_main_bss_80128D50[0];
    if ((D_main_bss_8011A860[5] == 0) || (D_main_bss_8011A860[4] != 0)) {
        if (D_main_bss_8011A860[2] == 0) {
            var_v1 = &D_main_bss_80128D50[1];
        }
    } else if (D_main_bss_8011A860[2] == 0) {
        var_v1 = &D_main_bss_80128D50[3];
    } else {
        var_v1 = &D_main_bss_80128D50[2];
    }
    D_main_bss_80128C90 = *var_v1;
    // This stuf is weird. Seemingly, D_main_bss_80128CC0 and D_main_bss_80128CD4 are supposed to be references to the
    // D_main_bss_80128C90.fldRegs[0/1].vStart, but then the top u16 of the word is copied into its lower u16?
    // I don't get it, that's not a normal operation of any kind and I can't find any VI related macros that accomlish
    // anything similar
    // D_main_bss_80128CC2 = D_main_bss_80128CC0;
    // D_main_bss_80128CD6 = D_main_bss_80128CD4;
    osViSetMode(&D_main_bss_80128C90);
    waitOnVideoQueue();
}
#else
INCLUDE_ASM("asm/nonmatchings/main/1A410", selectAndApplyViMode);
#endif

s32 computeFramebufferByteSize(void) {
    s32 ret;
    if (D_main_bss_8011A848 < 0x18) {
        ret = D_main_bss_8011A838 * D_main_bss_8011A83C * 2;
    } else {
        ret = D_main_bss_8011A838 * D_main_bss_8011A83C * 4;
    }
    return ret;
}

void readBufferSwapState(s32 *arg0, s32 *arg1, s32 *arg2) {
    if (D_main_bss_80128EB4 == -1) {
        *arg0 = 0;
        *arg1 = 0;
        *arg2 = 0;
    } else {
        *arg1 = D_main_bss_80128EB4;
        *arg2 = D_main_bss_80128EB8;
        *arg0 = D_main_bss_80128EBC;
    }
}

INCLUDE_ASM("asm/nonmatchings/main/1A410", bufferArbiterProducerMark);

void waitOnVideoQueue(void) {
    D_main_80037808 = 1;
    osRecvMesg(&D_main_bss_80128CF0, NULL, 1);
    D_main_80037808 = 0;
    osYieldThread();
}

INCLUDE_ASM("asm/nonmatchings/main/1A410", bufferArbiterMarkSlotReady);

INCLUDE_ASM("asm/nonmatchings/main/1A410", bufferArbiterAllocSlot);

INCLUDE_ASM("asm/nonmatchings/main/1A410", acquireFreeBufferSlot);

INCLUDE_ASM("asm/nonmatchings/main/1A410", postSwapRdpReset);

INCLUDE_ASM("asm/nonmatchings/main/1A410", setPostSwapPendingFlags);

INCLUDE_ASM("asm/nonmatchings/main/1A410", waitForPostSwapAck);

INCLUDE_ASM("asm/nonmatchings/main/1A410", clearPostSwapPendingFlags);

INCLUDE_ASM("asm/nonmatchings/main/1A410", setGfxTaskYieldParams);

INCLUDE_ASM("asm/nonmatchings/main/1A410", dpInterruptHandlerThread);

INCLUDE_ASM("asm/nonmatchings/main/1A410", fake_func_8001C3FC);
