#include "common.h"

#include "main/01720.h"
#include "main/3F160.h"

struct D_80130BB0_type *gNpcSlotList;
u16 gNpcSlotListTail;
u16 pad; // necessary for matching, for some reason. Without this pointers beneath it end up misaligned which makes no sense to me
struct D_80130BB8_type *gNpcContextArray;
struct D_80130BB8_type **gNpcContextArrayPtrs;
void *D_main_bss_80130BC0;
void *D_main_bss_80130BC4;
s32   gNpcNextOpenSlot;

void initNpcSlotList(void) {
    s32 var_a1;

    gNpcSlotList = rs_malloc(sizeof(struct D_80130BB0_type) * 0x800, 0U);
    for (var_a1 = 0; var_a1 < 0x800; var_a1++) {
        gNpcSlotList[var_a1].unk00 = NULL;
        gNpcSlotList[var_a1].prev_idx = var_a1 - 1 ;
        gNpcSlotList[var_a1].next_idx = var_a1 + 1;
    }
    gNpcSlotListTail = 2;
    gNpcSlotList[0].prev_idx = 0xFFFF;
    gNpcSlotList[0].next_idx = 1;
    gNpcSlotList[1].prev_idx = 0;
    gNpcSlotList[1].next_idx = 0xFFFF;
    gNpcSlotList[1].prev_idx = 0xFFFF;
    gNpcSlotList[2].prev_idx = 0xFFFF;
    gNpcSlotList[0x7FF].next_idx = 0xFFFF;
}

s32 allocateNpcSlot(struct D_80130BB8_type *arg0) {
    u16 tail;

    tail = gNpcSlotListTail;
    if (tail == 0xFFFF) {
        return 0xFFFF;
    }
    gNpcSlotListTail = gNpcSlotList[tail].next_idx;
    if (gNpcSlotListTail != 0xFFFF) {
        gNpcSlotList[gNpcSlotListTail].prev_idx = 0xFFFF;
    }
    gNpcSlotList[tail].prev_idx = 0xFFFF;
    gNpcSlotList[tail].next_idx = 0xFFFF;
    gNpcSlotList[tail].unk00 = NULL;
    if (arg0 != NULL) {
        arg0->unk1C[arg0->unk1B++] = tail;
    }
    return tail;
}

#if 0
u16 popNpcSlotFromTail(u16 arg0, struct D_80130BB8_type *arg1) {
    u16 tail;
    u16 var_v1;
    u8 var_t2;
    s32 blah;

    struct D_80130BB8_type *new_var;

    var_t2 = 0;
    if (arg1 != NULL) {
        if (arg1->unk1B >= 0x10) return 0xFFFF;
        if (arg1) {
            var_t2 = arg1->unk19;
        } else {
            var_t2 = 0;
        }
    }
    tail = gNpcSlotListTail;
    if (tail == 0xFFFF) return 0xFFFF;
    gNpcSlotListTail = gNpcSlotList[tail].next_idx;
    if (gNpcSlotListTail != 0xFFFF) {
        gNpcSlotList[gNpcSlotListTail].prev_idx = 0xFFFF;
    }
    for (var_v1 = arg0; var_v1 != 0xFFFF; var_v1 = gNpcSlotList[var_v1].next_idx) {
        if (gNpcSlotList[var_v1].unk00 == NULL) continue;
        if (var_t2 >= gNpcSlotList[var_v1].unk00->unk19) break;
        arg0 = var_v1;
    }
    gNpcSlotList[tail].next_idx = gNpcSlotList[arg0].next_idx;
    if (gNpcSlotList[tail].next_idx != 0xFFFF) {
        gNpcSlotList[gNpcSlotList[tail].next_idx].prev_idx = tail;
    }
    gNpcSlotList[tail].prev_idx = arg0;
    gNpcSlotList[arg0].next_idx = tail;
    gNpcSlotList[tail].unk00 = arg1;
    if (arg1 != NULL) {
        arg1->unk1C[arg1->unk1B++] = tail;
    }
    return tail;
}
#else
INCLUDE_ASM("asm/nonmatchings/main/3F160", popNpcSlotFromTail);
#endif

void unregisterAndFreeNpcSlot(u16 arg0, struct D_80130BB8_type *arg1) {
    s32 var_a0;

    for (var_a0 = arg1->unk1B - 1; var_a0 >= 0; var_a0--) {
        if (arg1->unk1C[var_a0] != arg0) continue;

        arg1->unk1B--;
        for (; var_a0 < arg1->unk1B; var_a0++) {
            arg1->unk1C[var_a0] = arg1->unk1C[var_a0 + 1];
        }
        if (gNpcSlotList[arg0].next_idx != 0xFFFF) {
            gNpcSlotList[gNpcSlotList[arg0].next_idx].prev_idx =gNpcSlotList[arg0].prev_idx;
        }
        if (gNpcSlotList[arg0].prev_idx != 0xFFFF) {
            gNpcSlotList[gNpcSlotList[arg0].prev_idx].next_idx = gNpcSlotList[arg0].next_idx;
        }
        gNpcSlotList[arg0].next_idx = gNpcSlotListTail;
        if (gNpcSlotListTail != 0xFFFF) {
            gNpcSlotList[gNpcSlotListTail].prev_idx = arg0;
        }
        gNpcSlotListTail = arg0;
        gNpcSlotList[arg0].prev_idx = 0xFFFF;
        break;
    }
}

s32 slotDispatcherIter(u16 arg0, s32 arg1, void *arg2) {
    u16 temp_s3;
    u16 var_s0;
    struct D_80130BB8_type *temp_a0;

    while (arg0 != 0xFFFF) {
        if (gNpcSlotList[arg0].unk00 != NULL) {
            temp_a0 = gNpcSlotList[arg0].unk00;
            temp_a0->unk1A++;
            if (!(temp_a0->unk14 & 8)) {
                var_s0 = gNpcSlotList[arg0].next_idx;
                temp_s3 = gNpcSlotList[arg0].prev_idx;
                if (temp_a0->update_func(temp_a0, arg1, arg2) != 0) {
                    if (gNpcSlotList[arg0].prev_idx == temp_s3) {
                        var_s0 = gNpcSlotList[arg0].next_idx;
                    } else if ((var_s0 != 0xFFFF) && (gNpcSlotList[var_s0].prev_idx != temp_s3)) {
                        var_s0 = 0xFFFF;
                    }
                } else {
                    var_s0 = 0xFFFF;
                }
            } else {
                var_s0 = gNpcSlotList[arg0].next_idx;
            }
            temp_a0->unk1A--;
            if (!temp_a0->unk1A && (temp_a0->unk14 & 8)) {
                destroyNpcSlotByIndex(arg0);
            }
        } else {
            var_s0 = gNpcSlotList[arg0].next_idx;
        }
        arg0 = var_s0;
    }
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/main/3F160", slotDispatcherInner);

INCLUDE_ASM("asm/nonmatchings/main/3F160", reinsertNpcIntoSortedFreeList);

void destroyNpcSlotByIndex(u16 arg0) {
    s32 var_a2;
    struct D_80130BB8_type *temp_s0;

    temp_s0 = gNpcSlotList[arg0].unk00;
    if (temp_s0 == NULL) return;
    if (temp_s0->unk1A != 0) {
        temp_s0->unk14 |= 8;
    } else {
        temp_s0->unk08 = NULL;
        temp_s0->unk1A++;
        if (temp_s0->update_func != NULL) temp_s0->update_func(temp_s0, 2, NULL);
        temp_s0->unk1A--;
        reinsertNpcIntoSortedFreeList(temp_s0);
        for (var_a2 = temp_s0->unk1B - 1; var_a2 >= 0; var_a2--) {
            if (gNpcSlotList[temp_s0->unk1C[var_a2]].next_idx != 0xFFFF) {
                gNpcSlotList[gNpcSlotList[temp_s0->unk1C[var_a2]].next_idx].prev_idx = gNpcSlotList[temp_s0->unk1C[var_a2]].prev_idx;
            }
            if (gNpcSlotList[temp_s0->unk1C[var_a2]].prev_idx != 0xFFFF) {
                gNpcSlotList[gNpcSlotList[temp_s0->unk1C[var_a2]].prev_idx].next_idx = gNpcSlotList[temp_s0->unk1C[var_a2]].next_idx;
            }
            gNpcSlotList[temp_s0->unk1C[var_a2]].next_idx = gNpcSlotListTail;
            if (gNpcSlotListTail != 0xFFFF) {
                gNpcSlotList[gNpcSlotListTail].prev_idx = temp_s0->unk1C[var_a2];
            }
            gNpcSlotList[temp_s0->unk1C[var_a2]].prev_idx = 0xFFFF;
            gNpcSlotListTail = temp_s0->unk1C[var_a2];
        }
        gNpcNextOpenSlot++;
        gNpcContextArrayPtrs[gNpcNextOpenSlot] = temp_s0;
    }
}

INCLUDE_ASM("asm/nonmatchings/main/3F160", revalidateNpcSlotIterator);

INCLUDE_ASM("asm/nonmatchings/main/3F160", relinkNpcSlotToNewParentGroup);

void destroyNpcSlotChain(u16 arg0) {
    u16 var_a0;

    while (arg0 != 0xFFFF) {
        var_a0 = gNpcSlotList[arg0].next_idx;
        if (gNpcSlotList[arg0].unk00 != NULL) {
            unregisterAndFreeNpcSlot(arg0, gNpcSlotList[arg0].unk00);
        } else {
            if (var_a0 != 0xFFFF) {
                gNpcSlotList[gNpcSlotList[arg0].next_idx].prev_idx = gNpcSlotList[arg0].prev_idx;
            }
            if (gNpcSlotList[arg0].prev_idx != 0xFFFF) {
                gNpcSlotList[gNpcSlotList[arg0].prev_idx].next_idx = gNpcSlotList[arg0].next_idx;
            }
            gNpcSlotList[arg0].next_idx = gNpcSlotListTail;
            if (gNpcSlotListTail != 0xFFFF) {
                gNpcSlotList[gNpcSlotListTail].prev_idx = arg0;
            }
            gNpcSlotListTail = arg0;
            gNpcSlotList[arg0].prev_idx = 0xFFFF;
        }
        arg0 = var_a0;
    }
}

INCLUDE_ASM("asm/nonmatchings/main/3F160", spawnChildNpcWithTransform);

INCLUDE_ASM("asm/nonmatchings/main/3F160", spawnInheritedNpcVariantA);

INCLUDE_ASM("asm/nonmatchings/main/3F160", spawnInheritedNpcVariantB);

INCLUDE_ASM("asm/nonmatchings/main/3F160", spawnInheritedNpcVariantC);

void freeNpcSlotArray(void) {
    rs_free(gNpcSlotList);
    gNpcSlotList = NULL;
}

INCLUDE_ASM("asm/nonmatchings/main/3F160", findActiveNpcInSlotChain);

INCLUDE_ASM("asm/nonmatchings/main/3F160", findFirstActiveNpcChildInChain);

void allocNpcContextArrays(void) {
    s32 var_a2;
    struct D_80130BB8_type **temp_v0;
    struct D_80130BB8_type **var_a1;
    struct D_80130BB8_type *var_a0;

    gNpcContextArray     = rs_malloc(sizeof(struct D_80130BB8_type)  * 0xC0, 0U);
    gNpcContextArrayPtrs = rs_malloc(sizeof(struct D_80130BB8_type*) * 0xC0, 0U);
    for (var_a2 = 0xBF; var_a2 >= 0; var_a2--) {
        gNpcContextArrayPtrs[var_a2] = &gNpcContextArray[var_a2];
    }
    gNpcNextOpenSlot = 0xBF;
    D_main_bss_80130BC4 = 0;
    D_main_bss_80130BC0 = 0;
}

INCLUDE_ASM("asm/nonmatchings/main/3F160", destroyNpcContextArrays);

u16 spawnNpcWithSubtype(npc_update arg0, void *arg1, u32 arg2, u8 arg3) {
    u16 var_a1;
    struct D_80130BB8_type *temp_s0;

    if (gNpcNextOpenSlot < 0) {
        for (var_a1 = gNpcSlotList[1].prev_idx; var_a1 != 0xFFFF; var_a1 = gNpcSlotList[var_a1].prev_idx) {
            if ((gNpcSlotList[var_a1].unk00 != NULL) && (gNpcSlotList[var_a1].unk00->unk1A == 0)) {
                destroyNpcSlotByIndex(var_a1);
                break;
            }
        }
    }
    temp_s0 = gNpcContextArrayPtrs[gNpcNextOpenSlot--];
    temp_s0->unk04 = NULL;
    temp_s0->unk08 = NULL;
    temp_s0->unk0C = 0;
    temp_s0->update_func = arg0;
    temp_s0->unk10 = 0;
    temp_s0->unk14 = arg2;
    temp_s0->unk1B = 0;
    temp_s0->unk1A = 0;
    temp_s0->unk19 = arg3;
    temp_s0->unk16 = allocateNpcSlot(temp_s0);
    gNpcSlotList[temp_s0->unk16].unk00 = temp_s0;
    popNpcSlotFromTail(0U, temp_s0);
    slotDispatcherInner(temp_s0);
    slotDispatcherIter(temp_s0->unk16, 8, arg1);
    return temp_s0->unk16;
}

u16 spawnNpcOfType(npc_update arg0, void *arg1, u32 arg2, u8 arg3) {
    u16 var_a1;
    struct D_80130BB8_type *temp_s0;

    if (gNpcNextOpenSlot < 0) {
        for (var_a1 = gNpcSlotList[1].prev_idx; var_a1 != 0xFFFF; var_a1 = gNpcSlotList[var_a1].prev_idx) {
            if ((gNpcSlotList[var_a1].unk00 != NULL) && (gNpcSlotList[var_a1].unk00->unk1A == 0)) {
                destroyNpcSlotByIndex(var_a1);
                break;
            }
        }
    }
    temp_s0 = gNpcContextArrayPtrs[gNpcNextOpenSlot--];
    temp_s0->unk04 = NULL;
    temp_s0->unk08 = NULL;
    temp_s0->unk0C = 0;
    temp_s0->update_func = arg0;
    temp_s0->unk10 = 0;
    temp_s0->unk14 = arg2;
    temp_s0->unk1B = 0;
    temp_s0->unk1A = 0;
    temp_s0->unk19 = arg3;
    temp_s0->unk16 = allocateNpcSlot(temp_s0);
    gNpcSlotList[temp_s0->unk16].unk00 = temp_s0;
    popNpcSlotFromTail(0U, temp_s0);
    slotDispatcherInner(temp_s0);
    slotDispatcherIter(temp_s0->unk16, 1, arg1);
    return temp_s0->unk16;
}

struct D_80130BB8_type *getNpcContextByIndex(u16 arg0) {
    return gNpcSlotList[arg0].unk00;
}

void *getNpcContextField8(u16 arg0) {
    if (gNpcSlotList[arg0].unk00 != NULL) {
        return gNpcSlotList[arg0].unk00->unk08;
    } else {
        return NULL;
    }
}

u16 findFreeNpcSlotByKey(struct D_80130BB8_type *arg0, u16 arg1) {
    u16 var_s0;

    var_s0 = 0xFFFF;
    if (arg1 != 0xFFFF) {
        if (gNpcSlotList[arg1].unk00 != NULL) {
            var_s0 = allocateNpcSlot(NULL);
            if (var_s0 != 0xFFFF) {
                popNpcSlotFromTail(var_s0, gNpcSlotList[arg1].unk00);
            }
        }
    }
    return var_s0;
}

u16 getNextSlotNpcTypeId(u16 arg0) {
    if ((arg0 == 0xFFFF) || (gNpcSlotList[arg0].next_idx == 0xFFFF)) {
        return 0xFFFF;
    } else {
        return gNpcSlotList[gNpcSlotList[arg0].next_idx].unk00->unk16;
    }
}

u16 getNpcNextSlotIndex(u16 arg0) {
    u16 ret;
    if (arg0 != 0xFFFF) {
        ret = gNpcSlotList[arg0].next_idx;
    } else {
        ret = 0xFFFF;
    }
    return ret;
}

void destroyTransientNpcSlots(void) {
    u16 var_a1;

    for (var_a1 = gNpcSlotList[1].prev_idx; var_a1 != 0xFFFF; var_a1 = gNpcSlotList[var_a1].prev_idx) {
        if ((gNpcSlotList[var_a1].unk00 != NULL) && (gNpcSlotList[var_a1].unk00->unk1A == 0)) {
            destroyNpcSlotByIndex(var_a1);
            break;
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/main/3F160", fake_func_80040304);
