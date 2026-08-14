#include "common.h"

#include "compiler/gcc/memory.h"

#include "main/01720.h"
#include "main/08510.h"
#include "main/1EE30.h"

u16 D_main_bss_80128EF0;
u16 bss_pad;
struct MaterialPoolEntry   *D_main_bss_80128EF4;
struct MaterialPoolEntry   *D_main_bss_80128EF8;
u16 **D_main_bss_80128EFC;
struct MaterialPoolEntry  **D_main_bss_80128F00;
void *D_main_bss_80128F04;
struct D_main_bss_80128F08 *D_main_bss_80128F08;

INCLUDE_ASM("asm/nonmatchings/main/1EE30", initTextureLUTAndAllocBuffers);

void destroyTextureLUTs(void) {
    rs_free(D_main_bss_80128F08);
    rs_free(D_main_bss_80128EFC);
}

INCLUDE_ASM("asm/nonmatchings/main/1EE30", packTlutEntriesRgba5551);

INCLUDE_ASM("asm/nonmatchings/main/1EE30", allocTextureTlutBlock);

INCLUDE_ASM("asm/nonmatchings/main/1EE30", freeTextureTlutBlock);

INCLUDE_ASM("asm/nonmatchings/main/1EE30", freeTextureDataSlot);

u16 decodeRdpFormatFlags(u16 arg0) {
    u32 ret;
    switch (arg0 & 0x3F) {
        case 1:
            ret = 0;
            break;
        case 2:
            ret = 1;
            break;
        case 3:
            ret = 2;
            break;
        case 4:
            ret = 3;
            break;
        case 5:
            ret = 4;
            break;
        case 6:
            ret = 5;
            break;
    }
    if (arg0 & 0x8000) {
        ret |= 0x8000;
    }
    if (arg0 & 0x4000) {
        ret |= 0x4000;
    }
    if (arg0 & 0x2000) {
        ret |= 0x2000;
    }
    if (arg0 & 0x1000) {
        ret |= 0x1000;
    }
    if (arg0 & 0x800) {
        ret |= 0x800;
    }
    if (arg0 & 0x400) {
        ret |= 0x400;
    }
    if (arg0 & 0x200) {
        ret |= 0x200;
    }
    if (arg0 & 0x100) {
        ret |= 0x100;
    }
    if (arg0 & 0x80) {
        ret |= 0x80;
    }
    if (arg0 & 0x40) {
        ret |= 0x40;
    }
    return ret;
}

u16 decodeRdpSizeFlags(u16 arg0) {
    u32 ret;
    switch (arg0 & 0xF) {
        case 4:
            ret = 5;
            break;
        case 0:
            ret = 1;
            break;
        case 5:
            ret = 6;
            break;
        case 1:
            ret = 2;
            break;
        case 2:
            ret = 3;
            break;
        case 3:
            ret = 4;
            break;
    }
    if (arg0 & 0x8000) {
        ret |= 0x8000;
    }
    if (arg0 & 0x4000) {
        ret |= 0x4000;
    }
    if (arg0 & 0x2000) {
        ret |= 0x2000;
    }
    if (arg0 & 0x1000) {
        ret |= 0x1000;
    }
    if (arg0 & 0x800) {
        ret |= 0x800;
    }
    if (arg0 & 0x400) {
        ret |= 0x400;
    }
    if (arg0 & 0x200) {
        ret |= 0x200;
    }
    if (arg0 & 0x100) {
        ret |= 0x100;
    }
    if (arg0 & 0x80) {
        ret |= 0x80;
    }
    if (arg0 & 0x40) {
        ret |= 0x40;
    }
    return ret;
}

INCLUDE_ASM("asm/nonmatchings/main/1EE30", parseImageFile);

INCLUDE_ASM("asm/nonmatchings/main/1EE30", loadTextureToMemory);

INCLUDE_ASM("asm/nonmatchings/main/1EE30", loadTextureTile);

INCLUDE_ASM("asm/nonmatchings/main/1EE30", emitMaterialRenderStateDL);

void resetMaterialPool(void) {
    u32 var_a0;

    for (var_a0 = 0; var_a0 < D_main_bss_80128EF0; var_a0++) {
        D_main_bss_80128F00[var_a0] = NULL;
    }

    D_main_bss_80128EF8 = D_main_bss_80128EF4;
    D_main_bss_80128EF4[0].prev = NULL;
    for (var_a0 = 1; var_a0 < 0x200; var_a0++) {
        D_main_bss_80128EF4[var_a0 - 1].next = &D_main_bss_80128EF4[var_a0];
        D_main_bss_80128EF4[var_a0].prev = &D_main_bss_80128EF4[var_a0 - 1];
    }
    D_main_bss_80128EF4[var_a0 - 1].next = NULL;
}

u8 buildMaterialFreeList(void) {
    u32 var_a0;

    for (var_a0 = 0; var_a0 < D_main_bss_80128EF0; var_a0++) {
        D_main_bss_80128F00[var_a0] = NULL;
    }

    D_main_bss_80128EF8 = D_main_bss_80128EF4;
    D_main_bss_80128EF4[0].prev = NULL;
    for (var_a0 = 1; var_a0 < 0x200; var_a0++) {
        D_main_bss_80128EF4[var_a0 - 1].next = &D_main_bss_80128EF4[var_a0];
        D_main_bss_80128EF4[var_a0].prev = &D_main_bss_80128EF4[var_a0 - 1];
    }
    D_main_bss_80128EF4[var_a0 - 1].next = NULL;
    return 1;
}

s32 createMaterialPool(void) {
    D_main_bss_80128EF4 = rs_malloc(sizeof(struct MaterialPoolEntry) * 0x200, 0x80U);
    if (D_main_bss_80128EF4 != NULL) {
        return buildMaterialFreeList();
    } else {
        return 0;
    }
}

s32 unlinkTextureMaterialList(u16 arg0) {
    struct MaterialPoolEntry *temp_s1;
    struct MaterialPoolEntry *var_s0;

    var_s0 = D_main_bss_80128F00[arg0];
    while (var_s0 != NULL) {
        temp_s1 = var_s0->next;
        heapFreeListInsert(var_s0->unk14);
        if (var_s0->prev != NULL) {
            var_s0->prev->next = var_s0->next;
        } else {
            D_main_bss_80128F00[arg0] = var_s0->next;
        }
        if (var_s0->next != NULL) {
            var_s0->next->prev = var_s0->prev;
        }
        var_s0->next = D_main_bss_80128EF8;
        if (D_main_bss_80128EF8 != NULL) {
            D_main_bss_80128EF8->prev = var_s0;
        }
        var_s0->prev = NULL;
        D_main_bss_80128EF8 = var_s0;
        var_s0 = temp_s1;
    }
    return 1;
}

void tickTextureMaterialExpiry(void) {
    u32 var_s2;
    struct MaterialPoolEntry *temp_s3;
    struct MaterialPoolEntry *var_s0;

    for(var_s2 = 0; var_s2 < D_main_bss_80128EF0; var_s2++) {
        var_s0 = D_main_bss_80128F00[var_s2];
        while (var_s0 != NULL) {
            temp_s3 = var_s0->next;
            if (var_s0->unk08 < 0x708U) {
                var_s0->unk08++;
            } else {
                heapFreeListInsert(var_s0->unk14);
                if (var_s0->prev != NULL) {
                    var_s0->prev->next = var_s0->next;
                } else {
                    D_main_bss_80128F00[var_s2] = var_s0->next;
                }
                if (var_s0->next != NULL) {
                    var_s0->next->prev = var_s0->prev;
                }
                var_s0->next = D_main_bss_80128EF8;
                if (D_main_bss_80128EF8 != NULL) {
                    D_main_bss_80128EF8->prev = var_s0;
                }
                var_s0->prev = NULL;
                D_main_bss_80128EF8 = var_s0;
            }
            var_s0 = temp_s3;
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/main/1EE30", resetMaterialExpiryById);

void *findAndUnlinkSmallestEntry(void) {
    u32 var_a3;
    struct MaterialPoolEntry *var_a1;
    struct MaterialPoolEntry *var_v1;

    var_a1 = NULL;
    for (var_a3 = 0; var_a3 < D_main_bss_80128EF0; var_a3++) {
        var_v1 = D_main_bss_80128F00[var_a3];
        while (var_v1 != NULL) {
            if ((var_v1->unk08 != 0) && ((var_a1 == NULL) || (var_v1->unk08 >= var_a1->unk08))) {
                var_a1 = var_v1;
            }
            var_v1 = var_v1->next;
        }
    }
    if (var_a1 != NULL) {
        if (var_a1->prev != NULL) {
            var_a1->prev->next = var_a1->next;
        } else {
            D_main_bss_80128F00[var_a1->unk0A] = var_a1->next;
        }
        if (var_a1->next != NULL) {
            var_a1->next->prev = var_a1->prev;
        }
        var_a1->prev = NULL;
        var_a1->next = D_main_bss_80128EF8;
        if (D_main_bss_80128EF8 != NULL) {
            D_main_bss_80128EF8->prev = var_a1;
        }
        D_main_bss_80128EF8 = var_a1;
        return var_a1->unk14;
    } else {
        return NULL;
    }
}

struct MaterialPoolEntry *popMaterialNodeIntoBucket(u16 arg0) {
    struct MaterialPoolEntry *temp_a1;

    temp_a1 = D_main_bss_80128EF8;
    if (D_main_bss_80128EF8 != NULL) {
        D_main_bss_80128EF8 = D_main_bss_80128EF8->next;
        if (D_main_bss_80128EF8 != NULL) {
            D_main_bss_80128EF8->prev = NULL;
        }
        temp_a1->next = D_main_bss_80128F00[arg0];
        if (temp_a1->next != NULL) {
            temp_a1->next->prev = temp_a1;
        }
        D_main_bss_80128F00[arg0] = temp_a1;
    }
    return temp_a1;
}

INCLUDE_ASM("asm/nonmatchings/main/1EE30", allocOrEvictMaterialNode);

INCLUDE_ASM("asm/nonmatchings/main/1EE30", findOrCreateMaterial);

u16 getTextureLUTFieldAt8(u16 arg0) {
    return D_main_bss_80128F08[arg0].width;
}

u16 getTextureLUTFieldAtA(u16 arg0) {
    return D_main_bss_80128F08[arg0].height;
}

INCLUDE_ASM("asm/nonmatchings/main/1EE30", releaseTextureLutEntry);

INCLUDE_ASM("asm/nonmatchings/main/1EE30", initTextureMaterialPools);

s32 getTextureDimsBySlot(u16 arg0, u16 *arg1, u16 *arg2) {
    u32 temp_a0_2;

    if (D_main_bss_8011A444[arg0].material_type & 1) {
        temp_a0_2 = D_main_bss_8011A444[arg0].D_80128F08_index;
        *arg1 = D_main_bss_80128F08[temp_a0_2].width;
        *arg2 = D_main_bss_80128F08[temp_a0_2].height;
        return 1;
    } else {
        return 0;
    }
}

INCLUDE_ASM("asm/nonmatchings/main/1EE30", parseHmtMaterials);

INCLUDE_ASM("asm/nonmatchings/main/1EE30", registerHmtTextureInTable);

INCLUDE_ASM("asm/nonmatchings/main/1EE30", findMatchingTextureRecursive);

INCLUDE_ASM("asm/nonmatchings/main/1EE30", findTextureByName);

INCLUDE_ASM("asm/nonmatchings/main/1EE30", copyTextureDescriptorWithData);

INCLUDE_ASM("asm/nonmatchings/main/1EE30", fillTextureDescriptorNoCopy);

INCLUDE_ASM("asm/nonmatchings/main/1EE30", loadAndDecodeTexture);

INCLUDE_ASM("asm/nonmatchings/main/1EE30", uploadTextureDescriptorData);

void *getTextureDataByMaterialId(u16 arg0) {
    return D_main_bss_80128F08[D_main_bss_8011A444[arg0].D_80128F08_index].texture_data;
}

s32 returnOne_80023334(void) {
    return 1;
}

u16 *getTextureTlutEntry(u16 arg0) {
    return D_main_bss_80128EFC[arg0];
}

s32 returnOne_8002335C(void) {
    return 1;
}

u16 getTextureAttrBySlot(u16 arg0) {
    if (D_main_bss_8011A444[arg0].material_type & 1) {
        return D_main_bss_80128F08[D_main_bss_8011A444[arg0].D_80128F08_index].unk0E;
    } else {
        return 0xFFFF;
    }
}

INCLUDE_ASM("asm/nonmatchings/main/1EE30", texPackTlutAtAllocSlot);

INCLUDE_ASM("asm/nonmatchings/main/1EE30", texPackTlutSlotOrAlloc);

INCLUDE_ASM("asm/nonmatchings/main/1EE30", texPackTlutAtIndex);

s32 unpackTlutToRgbaBytes(u16 arg0, u8 *arg1, u8 arg2, u8 arg3, u8 arg4) {
    s32 var_a2;
    u16 *temp_v0;
    u32 temp_a0;
    u8 temp_v0_2;
    u8 *why;
    u16 huh, wtf;

    temp_v0 = &D_main_bss_80128EFC[arg0][arg2];
    if (arg4 != 0) {
        for (var_a2 =0; var_a2 < arg3; var_a2++) {
            temp_a0 = temp_v0[var_a2];
            temp_v0_2 = temp_a0 >> 0xB;
            *arg1++ = (temp_v0_2 << 3) | (temp_v0_2 >> 2);

            temp_v0_2 = (temp_a0 >> 6) & 0x1F;
            *arg1++ = (temp_v0_2 << 3) | (temp_v0_2 >> 2);

            temp_a0 >>= 1;
            temp_a0 &= 0x1F;
            temp_v0_2 = temp_a0 << 3;
            temp_a0 >>= 2;
            *arg1++ = temp_v0_2 | temp_a0;

            why = arg1++;
            huh = temp_v0[var_a2];
            wtf = huh;
            wtf &= 1;
            *why = -wtf;
        }
    } else {
        for (var_a2 =0; var_a2 < arg3; var_a2++) {
            temp_a0 = temp_v0[var_a2];
            temp_v0_2 = temp_a0 >> 0xB;
            *arg1++ = (temp_v0_2 << 3) | (temp_v0_2 >> 2);

            temp_v0_2 = (temp_a0 >> 6) & 0x1F;
            *arg1++ = (temp_v0_2 << 3) | (temp_v0_2 >> 2);

            temp_a0 >>= 1;
            temp_a0 &= 0x1F;
            temp_v0_2 = temp_a0 << 3;
            temp_a0 >>= 2;
            *arg1++ = temp_v0_2 | temp_a0;
        }
    }
    return 1;
}

s32 shiftTlutEntryWithinChunk(u16 arg0, u8 arg1, u8 arg2, s8 arg3) {
    u16 blah;
    u16 var_a3;
    u16 *temp_a0;

    temp_a0 = D_main_bss_80128EFC[arg0];
    if (arg3 < 0) {
        blah = temp_a0[arg1];
        for (var_a3 = arg1 + 1; var_a3 < arg1 + arg2; var_a3++) {
            temp_a0[var_a3 - 1] = temp_a0[var_a3];
        }
        temp_a0[var_a3 - 1] = blah;
    } else {
        // ???
        blah = temp_a0[var_a3 = (arg1 + arg2) - 1];
        for (; var_a3 > arg1; var_a3--) {
            temp_a0[var_a3] = temp_a0[var_a3 - 1];
        }
        temp_a0[var_a3] = blah;
    }
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/main/1EE30", getLoadedTextureCount);

INCLUDE_ASM("asm/nonmatchings/main/1EE30", fake_func_80023968);

INCLUDE_RODATA("asm/nonmatchings/main/1EE30", D_main_800009F0);
