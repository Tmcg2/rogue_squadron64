#include "common.h"
#include "common_variables.h"

#include "main/01720.h"
#include "main/04080.h"
#include "main/08120.h"
#include "compiler/gcc/string.h"

INCLUDE_ASM("asm/nonmatchings/main/04080", submitDmaSlot);

INCLUDE_ASM("asm/nonmatchings/main/04080", waitDmaSlotComplete);

INCLUDE_ASM("asm/nonmatchings/main/04080", pollDmaSlotStep);

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

INCLUDE_ASM("asm/nonmatchings/main/04080", pushEventToRingBuffer);

INCLUDE_ASM("asm/nonmatchings/main/04080", subscribeEventHandler);

INCLUDE_ASM("asm/nonmatchings/main/04080", processAssetLoadStep);

INCLUDE_ASM("asm/nonmatchings/main/04080", mainEventQueueWorker);

INCLUDE_ASM("asm/nonmatchings/main/04080", initDmaSlots);

INCLUDE_ASM("asm/nonmatchings/main/04080", findManifestEntryByName);

INCLUDE_ASM("asm/nonmatchings/main/04080", freeManifestSegmentAssets);

INCLUDE_ASM("asm/nonmatchings/main/04080", findAssetAcrossSegments);

INCLUDE_ASM("asm/nonmatchings/main/04080", teardownAssetDma);

INCLUDE_ASM("asm/nonmatchings/main/04080", get_asset_size_extra);

INCLUDE_ASM("asm/nonmatchings/main/04080", setupAssetDma);

INCLUDE_ASM("asm/nonmatchings/main/04080", spillArgsNoopHandler);

void noopHandler_80004FC8(void) {
}

void noopHandler_80004FD0(void) {
}

INCLUDE_ASM("asm/nonmatchings/main/04080", teardownAssetManifestService);

s32 setManifestEntryName(s32 arg0, u8 *arg1) {
    if (arg0 == -1) {
        return 0;
    }
    if (arg1 != NULL) {
        rs_strcpy(gManifestTable[arg0].unk20, arg1);
    } else {
        gManifestTable[arg0].unk20[0] = '\0';
    }
    return 1;
}

#if 0
s32 get_manifest_entry_type(u32 arg0, u8 *entry_name) {
    u32 var_s0;
    struct manifest_entry *entry;

    if (arg0 == -1U) {
        for (var_s0 = 0; var_s0 < 4; var_s0++) {
            if (gManifestTable[var_s0].one == 0) continue;
            entry = find_manifest_entry(var_s0, entry_name, 1);
            if (entry != NULL) {
                break;
            }
        }
        entry = NULL;
    } else {
        entry = find_manifest_entry(arg0, entry_name, 1);
    }
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

INCLUDE_ASM("asm/nonmatchings/main/04080", synchronousDmaTransfer);

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

INCLUDE_ASM("asm/nonmatchings/main/04080", resolveAssetRamAddress);

INCLUDE_ASM("asm/nonmatchings/main/04080", getDmaSlotMutex);

INCLUDE_ASM("asm/nonmatchings/main/04080", setDmaWorkerPriority);

INCLUDE_ASM("asm/nonmatchings/main/04080", fake_func_8000537C);
