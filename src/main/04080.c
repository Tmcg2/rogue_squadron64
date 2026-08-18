#include "common.h"
#include "common_variables.h"

#include "main/01720.h"
#include "main/04080.h"
#include "main/06170.h"
#include "main/07800.h"
#include "main/08120.h"
#include "PR/os.h"
#include "compiler/gcc/string.h"

OSMesg      D_main_801107A0[8];
OSMesgQueue D_main_801107C0;
u32 bss_pad0_04080;
OSIoMesg    D_main_801107E0[8];
OSMesg      dmaSlotMesgBuffer[8];
OSMesgQueue dmaSlotMesgQueue[8];
OSMesg      gDmaSlotLockMesg;
u32 bss_pad1_04080;
u32 bss_pad2_04080;
OSMesgQueue gDmaSlotLockQueue;
s32         nextOpenDmaSlot;
s32         dmaSlotsAvailable;
u8         *dmaSlotDestAddr[8];
s32         dmaSlotTotalTxSize[8];
u8         *dmaSlotSrcAddr[8];
s32         dmaSlotTxSoFar[8];
s32         dmaSlotTxRemaning[8];
s32         dmaSlotTxThisStep[8];
volatile u8 dmaSlotMutex;
u8 bss_pad3_04080;
u8 bss_pad4_04080;
u8 bss_pad5_04080;
struct data_block_header_entry *D_main_bss_80110A74;
u32 bss_pad6_04080;
u32 bss_pad7_04080;
struct D_80110A80_entry D_gManifestTable[4]; // The name of this variable is wonky because otherwise it gets placed in the BSS section incorrectly
struct D_80110BC0_type  D_main_80110BC0[16];
s32 D_main_bss_80110D40;
u8 *D_main_bss_80110D44;
s32 D_main_bss_80110D48;
s32 D_main_bss_80110D4C;
u8 *D_main_bss_80110D50;
s32 D_main_bss_80110D54;
u32 bss_pad8_04080;
u32 bss_pad9_04080;
struct D_80110D60_type D_main_bss_80110D60[8];
union  D_80111100_type gServiceWorkerMesgBuf[8];
u32 D_main_bss_80111240;
s32 D_main_bss_80111244;
s32 D_main_bss_80111248;
s32 D_main_bss_8011124C;
s32 D_main_bss_80111250;
u32 dmaSlotMaxTxStepSize;

s32 submitDmaSlot(u8 *arg0, u8 *arg1, s32 arg2) {
    s32 temp_s2;
    s32 temp_v1;
    s32 var_s1;
    s32 var_v0;

    osRecvMesg(&gDmaSlotLockQueue, NULL, 1);
    temp_s2 = nextOpenDmaSlot;
    temp_v1 = temp_s2 + 1;
    var_v0 = temp_v1;
    if (temp_v1 < 0) {
        var_v0 = temp_s2 + 8;
    }
    nextOpenDmaSlot = temp_v1 - ((var_v0 >> 3) * 8);
    dmaSlotDestAddr[temp_s2]    = arg1;
    dmaSlotTotalTxSize[temp_s2] = arg2;
    dmaSlotSrcAddr[temp_s2]     = arg0;
    dmaSlotTxRemaning[temp_s2]  = arg2;
    dmaSlotTxSoFar[temp_s2]     = 0;
    if (dmaSlotMaxTxStepSize >= arg2) {
        var_s1 = arg2;
    } else {
        var_s1 = dmaSlotMaxTxStepSize;
    }
    dmaSlotTxThisStep[temp_s2] = var_s1;
    while (dispatchPendingPiDmaToWorker(0) == 1) {
        yieldThreadRet1(D_main_bss_80110D54);
    }
    dmaSlotMutex = 0;
    osWritebackDCache(arg1, var_s1);
    osPiStartDma(&D_main_801107E0[temp_s2], 0, 0, arg0, arg1, var_s1, &dmaSlotMesgQueue[temp_s2]);
    dmaSlotMutex = 1;
    dmaSlotsAvailable -= 1;
    osSendMesg(&gDmaSlotLockQueue, (void *)1, 1);
    return temp_s2;
}

void waitDmaSlotComplete(s32 arg0) {
    s32 var_s0;
    u8 *temp_s1;
    u8 *temp_s2;

    do {
        osRecvMesg(&dmaSlotMesgQueue[arg0], NULL, 1);
        osYieldThread();
        osInvalDCache(&dmaSlotDestAddr[arg0][dmaSlotTxSoFar[arg0]], dmaSlotTxThisStep[arg0]);
        dmaSlotTxRemaning[arg0] -= dmaSlotTxThisStep[arg0];
        dmaSlotTxSoFar[arg0] += dmaSlotTxThisStep[arg0];
        dmaSlotMutex = 0;
        if (dmaSlotTxRemaning[arg0] == 0) break;
        if (dmaSlotMaxTxStepSize >= dmaSlotTxRemaning[arg0]) {
            var_s0 = dmaSlotTxRemaning[arg0];
        } else {
            var_s0 = dmaSlotMaxTxStepSize;
        }
        dmaSlotTxThisStep[arg0] = var_s0;
        temp_s1 = &dmaSlotDestAddr[arg0][dmaSlotTxSoFar[arg0]];
        temp_s2 = &dmaSlotSrcAddr[arg0][dmaSlotTxSoFar[arg0]];
        while (dispatchPendingPiDmaToWorker(0) == 1) {
            yieldThreadRet1(D_main_bss_80110D54);
        }
        osWritebackDCache(temp_s1, var_s0);
        osPiStartDma(&D_main_801107E0[arg0], 0, 0, temp_s2, temp_s1, var_s0, &dmaSlotMesgQueue[arg0]);
        dmaSlotMutex = 1;
    } while(dmaSlotTxRemaning[arg0] != 0);
    dmaSlotsAvailable += 1;
    dispatchPendingPiDmaToWorker(1);
}

s32 pollDmaSlotStep(s32 arg0) {
    u32 var_s0;
    u8 *temp_s1_2;
    u8 *temp_s2;

    if (osRecvMesg(&dmaSlotMesgQueue[arg0], NULL, 1) != -1) {
        osYieldThread();
        osInvalDCache(&dmaSlotDestAddr[arg0][dmaSlotTxSoFar[arg0]], dmaSlotTxThisStep[arg0]);
        dmaSlotTxRemaning[arg0] -= dmaSlotTxThisStep[arg0];
        dmaSlotTxSoFar[arg0] += dmaSlotTxThisStep[arg0];
        dmaSlotMutex = 0;
        if (dmaSlotTxRemaning[arg0] != 0) {
            if (dmaSlotMaxTxStepSize >= dmaSlotTxRemaning[arg0]) {
                var_s0 = dmaSlotTxRemaning[arg0];
            } else {
                var_s0 = dmaSlotMaxTxStepSize;
            }
            dmaSlotTxThisStep[arg0] = var_s0;
            temp_s1_2 = &dmaSlotDestAddr[arg0][dmaSlotTxSoFar[arg0]];
            temp_s2 = &dmaSlotSrcAddr[arg0][dmaSlotTxSoFar[arg0]];
            while (dispatchPendingPiDmaToWorker(0) == 1) {
                yieldThreadRet1(D_main_bss_80110D54);
            }
            osWritebackDCache(temp_s1_2, var_s0);
            osPiStartDma(&D_main_801107E0[arg0], 0, 0, temp_s2, temp_s1_2, var_s0, &dmaSlotMesgQueue[arg0]);
            dmaSlotMutex = 1;
            return 0;
        } else {
            dmaSlotsAvailable += 1;
            dispatchPendingPiDmaToWorker(1);
            return 1;
        }
    }
    return 0;
}

#if 0
struct manifest_entry *find_manifest_entry(s32 idx, u8 *entry_name) {
    u8 sp10[0x100];
    u8 sp110[0x20];
    s32 temp_v1;
    s32 var_s4;
    u8 *var_s5;
    u8 *temp_v0_2;
    struct manifest_entry *var_s2;

    // Copy directory to sp10
    rs_strcpy(sp10, gManifestTable[idx].unk20);
    // If its non-null and doesn't end with '/'
    if ((sp10[0] != 0) && (sp10[strlen(sp10) - 1] != '/')) {
        // Append '/' to sp10
        rs_strcat(sp10, "/");
    }
    // Append `entry_name` to spp10
    rs_strcat(sp10, entry_name);
    // Append '/' to sp10
    rs_strcat(sp10, "/");
    var_s2 = gManifestTable[idx].manifest;
    var_s4 = gManifestTable[idx].entry_count;
    // Get the address of the first '/'
    temp_v0_2 = strchr(sp10, '/');
    // Copy everything from the start of the string to the first '/' to sp110
    rs_strncpy(sp110, sp10, temp_v0_2 - sp10);
    // Append a null-byte to sp110
    sp110[temp_v0_2 - sp10] = 0;
    // Point var_s5 to the byte immediately after the first '/'
    var_s5 = temp_v0_2 + 1;
    do {
        // If the current entry's name doesn't match sp110
        if (rs_strncmp(sp110, var_s2->name, 0x10) != 0) {
            // If the current entry is a directory
            if ((var_s2->flags & 0x80) != 0) {
                // Skip the entire directory
                temp_v1 = var_s2->directory_size >> 5;
                var_s2 += temp_v1;
                var_s4 -= temp_v1;
            } else {
                // Otherwise, the entry is a file
                var_s2++;
                var_s4--;
            }
        } else { // Name matches sp110
            // Entry is a file
            if (!(var_s2->flags & 0x80)){
                // Success! Return the entry
                return var_s2;
            } else {
                // Entry is a directory
                // Set entry count to the directory's size
                var_s4 = var_s2->directory_size >> 5;
                // Get the address of the first '/' after the top directory
                temp_v0_2 = strchr(var_s5, '/');
                // Copy everything from the start of var_s5 to the first '/' to sp110
                rs_strncpy(sp110, var_s5, temp_v0_2 - var_s5);
                // Append a null-byte to sp110
                sp110[temp_v0_2 - var_s5] = 0;
                // Point var_s5 to the byte immediately after the first '/'
                var_s5 = temp_v0_2 + 1;
                // Skip the directory entry, we only care about its sub-entries
                var_s2++;
                var_s4--;
            }
        }
    } while (var_s4 > 0);
    // Failed to find, return NULL
    return NULL;
}
#else
INCLUDE_ASM("asm/nonmatchings/main/04080", find_manifest_entry);
#endif

s32 pushEventToRingBuffer(union D_80111100_type *arg0) {
    s32 temp_a2;
    s32 temp_v1;
    s32 var_v0;

    temp_a2 = D_main_bss_80111244;
    temp_v1 = temp_a2 + 1;
    var_v0 = temp_v1;
    if (temp_v1 < 0) {
        var_v0 = temp_a2 + 8;
    }
    D_main_bss_80111244 = temp_v1 - ((var_v0 >> 3) * 8);
    D_main_bss_8011124C -= 1;
    D_main_bss_80110D60[temp_a2].unk02 = 0;
    D_main_bss_80110D60[temp_a2].unk04 = arg0;
    D_main_bss_80110D60[temp_a2].unk01 = 1;
    switch (arg0->flag_8000.unk01) {
    case 0:
        D_main_bss_80110D60[temp_a2].unk00 = 0;
        break;
    case 1:
        D_main_bss_80110D60[temp_a2].unk00 = arg0->flag_8000.unk01;
        break;
    case 2:
        D_main_bss_80110D60[temp_a2].unk00 = arg0->flag_8000.unk01;
        D_main_bss_80110D60[temp_a2].unk08 = 0;
        D_main_bss_80110D60[temp_a2].unk48[0] = 0;
    default:
        break;
    }
    return 1;
}

s32 subscribeEventHandler(s32 *arg0) {
    s32 var_a2;
    struct D_80110BC0_type *temp_a0;
    struct D_80110BC0_type *var_v1;
    struct D_80110D60_type *temp_v0;

    for (var_a2 = 0; var_a2 < 0x10; var_a2++) {
        if (D_main_80110BC0[var_a2].unk00 == 0) break;
    }
    if (D_main_80110BC0[var_a2].unk00 == 0) {
        D_main_80110BC0[var_a2].unk00 = 1;
        D_main_80110BC0[var_a2].manfiest = (struct manifest_entry *) D_main_bss_80110D60[D_main_bss_80111240].unk04->flag_8000.source;
        D_main_80110BC0[var_a2].unk0C = D_main_bss_80110D60[D_main_bss_80111240].unk04->flag_8000.size;
        D_main_80110BC0[var_a2].unk08 = 0;
        D_main_80110BC0[var_a2].unk10 = D_main_bss_80110D60[D_main_bss_80111240].unk04->flag_8000.offset;
        D_main_80110BC0[var_a2].unk14 = 0;
        *arg0 = var_a2;
    }
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/main/04080", processAssetLoadStep);

INCLUDE_ASM("asm/nonmatchings/main/04080", mainEventQueueWorker);

INCLUDE_ASM("asm/nonmatchings/main/04080", initDmaSlots);

#if 0
struct tyler {
    u32 unk0;
    u32 unk4;
};

s32 findManifestEntryByName(u8 *arg0) {
    u32 temp_s0;
    s32 temp_s2_2;
    s32 var_s0;
    s32 var_s4;
    struct D_80110A80_entry *temp_s3;
    struct D_80110A80_entry *var_a0;
    struct manifest_entry *temp_v0;
    u32 temp_s5;
    struct tyler *temp_s2;

    for (var_s0 = 0; var_s0 < D_main_bss_80110D40; var_s0++) {
        if (rs_strcmp(D_main_bss_80110A74[var_s0].name, arg0) == 0) break;
    }
    temp_s5 = D_main_bss_80110A74[var_s0].data_offset;
    for (var_s4 = 0; var_s4 < 4; var_s4++) {
        if (gManifestTable[var_s4].one == 0) break;
    }
    temp_s2 = rs_malloc(8, 9U);
    temp_s3 = &gManifestTable[var_s4];
    if (D_main_bss_80110A74[var_s0].unk18 == 0) {
        waitDmaSlotComplete(submitDmaSlot(&D_main_bss_80110D44[temp_s5], temp_s2, 8));
        temp_s2_2 = temp_s2->unk0;
        temp_s0 = temp_s2->unk4 & 0x7FFFFFFF;
        rs_free(temp_s2);
        temp_s3->manifest = rs_malloc(temp_s0, 9U);
        temp_s3->one = 1;
        temp_s3->unk00[0] = 0;
        temp_s3->unk20[0] = 0;
        temp_s3->entry_count = temp_s0 >> 5;
        temp_s3->unk4C = 0;
        temp_s3->data = &D_main_bss_80110D44[temp_s5];
        waitDmaSlotComplete(submitDmaSlot(&temp_s3->data[temp_s2_2], temp_s3->manifest, temp_s0));
    }
    return var_s4;
}
#else
INCLUDE_ASM("asm/nonmatchings/main/04080", findManifestEntryByName);
#endif

s32 freeManifestSegmentAssets(s32 arg0) {
    u32 var_a1;
    u32 var_s1;
    struct D_80110A80_entry *var_s0;

    if (arg0 == -1) {
        for (var_s1 = 0; var_s1 < 4; var_s1++) {
            if (D_gManifestTable[var_s1].one != 1) continue;

            for (var_a1 = 0; var_a1 < 0x10; var_a1++) {
                if ((D_main_80110BC0[var_a1].unk00 == 1) && (D_main_80110BC0[var_a1].unk10 == var_s1)) {
                    D_main_80110BC0[var_a1].unk00 = 0;
                }
            }
            rs_free(D_gManifestTable[var_s1].manifest);
            D_gManifestTable[var_s1].one = 0;
        }
    } else {
        var_s0 = &D_gManifestTable[arg0];
        for (var_a1 = 0; var_a1 < 0x10; var_a1++) {
            if ((D_main_80110BC0[var_a1].unk00 == 1) && (D_main_80110BC0[var_a1].unk10 == arg0)) {
                D_main_80110BC0[var_a1].unk00 = 0;
            }
        }
        rs_free(var_s0->manifest);
        var_s0->one = 0;
    }
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/main/04080", findAssetAcrossSegments);

INCLUDE_ASM("asm/nonmatchings/main/04080", teardownAssetDma);

#if 0
s32 get_asset_size_extra(s32 arg0, u8 *arg1) {
    s32 var_a0;
    u32 var_s0;
    s32 size;
    struct D_80110A80_entry *var_s1;
    struct manifest_entry *var_a1;
    struct manifest_entry *var_v0;

    if (arg0 == -1) {
        for (var_s0 = 0; var_s0 < 4; var_s0++) {
            if (D_gManifestTable[var_s0].one == 0) continue;

            var_v0 = find_manifest_entry(var_s0, arg1, 0U);
            if (var_v0 != NULL) {
                arg0 = var_s0;
                var_a1 = var_v0;
                goto tyler;
            }
        }
        var_a1 = NULL;
    } else {
        var_v0 = find_manifest_entry(arg0, arg1, 0U);
        var_a1 = var_v0;
    }
tyler:
    if (var_a1 != NULL) {
        size = 0;
    } else {
        var_a0 = 0;
        if ((D_gManifestTable[arg0].unk4C != 0) && (var_a1->compressed_size != -1U)) {
            var_a0 = ((var_a1->flags & 0x44) == 0) << 6;
        }
        if ((var_a1->flags & 4) != 0) {
            size = var_a1->compressed_size + var_a0;
        } else {
            size = var_a1->decompressed_size + var_a0;
        }
    }
    return size;
}
#else
INCLUDE_ASM("asm/nonmatchings/main/04080", get_asset_size_extra);
#endif

INCLUDE_ASM("asm/nonmatchings/main/04080", setupAssetDma);

INCLUDE_ASM("asm/nonmatchings/main/04080", spillArgsNoopHandler);

void noopHandler_80004FC8(void) {
}

void noopHandler_80004FD0(void) {
}

s32 teardownAssetManifestService(void) {
    unregisterServiceWorker(D_main_bss_80110D54);
    if (D_main_bss_80110D50 != NULL) {
        rs_free(D_main_bss_80110D50);
    }
    return 1;
}

s32 setManifestEntryName(s32 arg0, u8 *arg1) {
    if (arg0 == -1) {
        return 0;
    }
    if (arg1 != NULL) {
        rs_strcpy(D_gManifestTable[arg0].unk20, arg1);
    } else {
        D_gManifestTable[arg0].unk20[0] = '\0';
    }
    return 1;
}

#if 0
s32 get_manifest_entry_type(u32 arg0, u8 *entry_name) {
    u32 var_s0;
    struct manifest_entry *entry;

    if (arg0 == -1U) {
        for (var_s0 = 0; var_s0 < 4; var_s0++) {
            if (D_gManifestTable[var_s0].one == 0) continue;
            entry = find_manifest_entry(var_s0, entry_name, 1);
            if (entry != NULL) {
                arg0 = var_s0;
                goto why;
                break;
            }
        }
        entry = NULL;
    } else {
        entry = find_manifest_entry(arg0, entry_name, 1);
    }
    why:
    if (entry == NULL) {
        return 0;
    }
    if ((entry->flags & 0x80) != 0) {
        return 2;
    } else {
        return 1;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/main/04080", get_manifest_entry_type);
#endif

INCLUDE_ASM("asm/nonmatchings/main/04080", get_asset_size_simple);

s32 zlibReturnZeroStub(void) {
    return 0;
}

void synchronousDmaTransfer(u8 *arg0, u8 *arg1, s32 arg2) {
    waitDmaSlotComplete(submitDmaSlot(arg0, arg1, arg2));
}

void *mallocWithFallbackStrategy(s32 arg0) {
    void *ret = rs_malloc(arg0, 4U);
    if (ret == NULL) {
        ret = rs_malloc(arg0, 8U);
    }
    return ret;
}

void rs_zcfree(void *arg0) {
    if (arg0 != NULL) {
        rs_free(arg0);
    }
}

void *rs_zcalloc(u32 arg0, u32 arg1) {
    s32 why;
    void *var_s0;

    var_s0 = rs_malloc(arg0 * arg1, 4);
    if (var_s0 == NULL) {
        var_s0 = rs_malloc(arg0 * arg1, 8);
    }
    why = var_s0 != NULL;
    if (why) {
        rs_memset(var_s0, 0, arg0 * arg1);
    }
    return var_s0;
}

s32 returnNegativeOneStub(void) {
    return -1;
}

s32 returnZeroStubZlib(void) {
    return 0;
}

u8 *resolveAssetRamAddress(s32 arg0) {
    return &D_gManifestTable[D_main_80110BC0[arg0].unk10].data[D_main_80110BC0[arg0].manfiest->data_offset];
}

u8 getDmaSlotMutex(void) {
    return dmaSlotMutex;
}

void setDmaWorkerPriority(s32 arg0) {
    if (arg0 <= 0) {
        arg0 = 0x20;
    }
    setServiceWorkerPriority(D_main_bss_80110D54, arg0);
}

INCLUDE_ASM("asm/nonmatchings/main/04080", fake_func_8000537C);
