#include "common.h"

#include "main/02420.h"
#include "main/08510.h"
#include "main/1D000.h"
#include "main/56F50.h"

// Interim BSS externs
extern struct hobObjectListItem hobObjectListItems[0x60];

// You could alternatively consider this the next open hobObjectList index
// In practice this always ends up tracking the number of loaded objects
extern u16 numHobObjectsLoaded;

/*
A hashmap, of sorts
object names have their characters sum'd and then %25'd.
The entires in this array are indices of entries in hobObjectListItems, representing the 
*/
extern u16 hobObjectHashMap[25];

f32 D_main_8009ECB0[] = {
    19.5f,
    32.0f,
    100.0f,
    200.0f,
};

INCLUDE_ASM("asm/nonmatchings/main/56F50", initNpcBookkeepingTables);

INCLUDE_ASM("asm/nonmatchings/main/56F50", load_hmt_and_hob);

INCLUDE_ASM("asm/nonmatchings/main/56F50", isHobObjectLoaded);

INCLUDE_ASM("asm/nonmatchings/main/56F50", walkMeshdef0List);

INCLUDE_ASM("asm/nonmatchings/main/56F50", instantiateNamedMeshInstance);

void applyRgbaTintToMeshVertices(struct D_main_bss_801394E8_type *arg0, struct rgba *arg1) {
    s32 temp_a1;
    s32 temp_a2;
    s32 temp_t2;
    s32 temp_t3;
    struct face *var_t0;
    struct face *var_t5;
    struct facegroup *temp_v0;
    u32 temp_v1;
    s32 var_t4;
    struct rgba *temp_a0;
    struct rgba *temp_v1_2;

    temp_v0 = arg0->meshdef0[0].meshdef1_pointer->facegroup_pointer;
    var_t0 = temp_v0->face_offset;
    var_t5 = arg0->object_entry->meshdef0->inner.meshdef1_pointer->facegroup_pointer->face_offset;
    temp_t3 = (arg1->r << 8) / 255;
    temp_t2 = (arg1->g << 8) / 255;
    temp_a2 = (arg1->b << 8) / 255;
    temp_a1 = (arg1->a << 8) / 255;
    for (var_t4 = temp_v0->face_count; var_t4 > 0; var_t4--) {
        temp_v1 = (var_t0->stuffed_data & 0x3F000) >> 0xA;
        temp_a0   = (u32) var_t5 + temp_v1;
        temp_v1_2 = (u32) var_t0 + temp_v1;
        temp_v1_2[0].r = (temp_a0[0].r * temp_t3) >> 8;
        temp_v1_2[0].g = (temp_a0[0].g * temp_t2) >> 8;
        temp_v1_2[0].b = (temp_a0[0].b * temp_a2) >> 8;
        temp_v1_2[0].a = (temp_a0[0].a * temp_a1) >> 8;
        if (var_t0->flags & 0x10) {
            temp_v1_2[1].r = (temp_a0[1].r * temp_t3) >> 8;
            temp_v1_2[1].g = (temp_a0[1].g * temp_t2) >> 8;
            temp_v1_2[1].b = (temp_a0[1].b * temp_a2) >> 8;
            temp_v1_2[1].a = (temp_a0[1].a * temp_a1) >> 8;
            temp_v1_2[2].r = (temp_a0[2].r * temp_t3) >> 8;
            temp_v1_2[2].g = (temp_a0[2].g * temp_t2) >> 8;
            temp_v1_2[2].b = (temp_a0[2].b * temp_a2) >> 8;
            temp_v1_2[2].a = (temp_a0[2].a * temp_a1) >> 8;
            if (var_t0->flags & 8) {
                temp_v1_2[3].r = (temp_a0[0].r * temp_t3) >> 8;
                temp_v1_2[3].g = (temp_a0[0].g * temp_t2) >> 8;
                temp_v1_2[3].b = (temp_a0[0].b * temp_a2) >> 8;
                temp_v1_2[3].a = (temp_a0[0].a * temp_a1) >> 8;
            }
        }
        temp_v1 = (var_t0->stuffed_data & 0x3F000000) >> 0x16;
        var_t0 = (u32) var_t0 + temp_v1;
        var_t5 = (u32) var_t5 + temp_v1;
    }
}

INCLUDE_ASM("asm/nonmatchings/main/56F50", releaseMeshAsset);

INCLUDE_ASM("asm/nonmatchings/main/56F50", releaseFlaggedMeshInstanceMeshes);

INCLUDE_ASM("asm/nonmatchings/main/56F50", getHobObjectByName);

INCLUDE_ASM("asm/nonmatchings/main/56F50", addNpcToVisibilityBucket);

INCLUDE_ASM("asm/nonmatchings/main/56F50", selectMeshLodAndSubmitForRender);

INCLUDE_ASM("asm/nonmatchings/main/56F50", lookupHmtTextureByName);

INCLUDE_ASM("asm/nonmatchings/main/56F50", computeNamedAttachPointTransform);

INCLUDE_ASM("asm/nonmatchings/main/56F50", meshdef1_offset_convert);

void meshdef0_offset_convert(struct meshdef0 *arg0, u32 arg1, u32 arg2, u32 arg3, u32 arg4) {
    if (arg0 != NULL) {
        do {
            if (arg0->inner.next_meshdef0_pointer != 0) {
                arg0->inner.next_meshdef0_pointer = (u32)arg0->inner.next_meshdef0_pointer + arg1;
            }
            if (arg0->inner.prev_meshdef0_pointer != 0) {
                arg0->inner.prev_meshdef0_pointer = (u32)arg0->inner.prev_meshdef0_pointer + arg1;
            }
            if (arg0->inner.unknown_meshdef0_pointer0 != 0) {
                arg0->inner.unknown_meshdef0_pointer0 = (u32)arg0->inner.unknown_meshdef0_pointer0 + arg1;
            }
            if (arg0->inner.unknown_meshdef0_pointer1 != 0) {
                arg0->inner.unknown_meshdef0_pointer1 = (u32)arg0->inner.unknown_meshdef0_pointer1 + arg1;
            }
            if (arg0->inner.meshdef1_pointer != 0) {
                arg0->inner.meshdef1_pointer = (u32)arg0->inner.meshdef1_pointer + arg1;
                meshdef1_offset_convert(arg0->inner.meshdef1_pointer, arg1, arg2, arg3, arg4);
            }
            if (arg0->inner.unknown_meshdef0_pointer1 != 0) {
                meshdef0_offset_convert(arg0->inner.unknown_meshdef0_pointer1, arg1, arg2, arg3, arg4);
            }
            clearVec4QuadStruct(arg0->inner.mtx);
            if (arg0->flags & 1) {
                addVec3At0x24(arg0->inner.mtx, -arg0->somevector0[0], -arg0->somevector0[1], -arg0->somevector0[2]);
            }
            if (arg0->flags & 2) {
                applyScaleToMat3x4(arg0->inner.mtx, arg0->somevector1[0], arg0->somevector1[1], arg0->somevector1[2]);
            }
            if (arg0->flags & 4) {
                composeQuatToMat3x4(arg0->inner.mtx, arg0->somequat0);
            }
            if ((arg0->flags & 9) == 9) {
                addVec3At0x24(arg0->inner.mtx, arg0->somevector2[0] + arg0->somevector0[0], arg0->somevector2[1] + arg0->somevector0[1], arg0->somevector2[2] + arg0->somevector0[2]);
            } else if ((arg0->flags & 9) == 8) {
                addVec3At0x24(arg0->inner.mtx, arg0->somevector2[0], arg0->somevector2[1], arg0->somevector2[2]);
            } else if ((arg0->flags & 9) & 1) {
                addVec3At0x24(arg0->inner.mtx, arg0->somevector0[0], arg0->somevector0[1], arg0->somevector0[2]);
            }
            arg0 = arg0->inner.next_meshdef0_pointer;
        } while (arg0 != NULL);
    }
}

#if 0
// https://decomp.me/scratch/cBIpL
// For some reason there's some extraneous temp juggling occuring in the target assembly, no idea why could be triggering it

#define clamp(x,y,floattmp,u8tmp) do { \
    floattmp = x * y;                  \
    if (floattmp < 0.0f ) {            \
        u8tmp = 0;                     \
    } else if (floattmp >= 256.0f) {   \
        u8tmp = 0xFF;                  \
    } else {                           \
        u8tmp = floattmp;              \
    }                                  \
    x = u8tmp;                         \
} while(0)

void applyMeshdef1AnimColors(struct meshdef1 *arg0, Vec3f arg1) {
    u32 var_t2;
    f32 temp;
    u8 why;
    struct rgba *temp_a2;
    struct face *var_t0;
    struct facegroup *var_t1;

    while (arg0 != NULL) {
        var_t1 = arg0->facegroup_pointer;
        while (var_t1 != NULL) {
            var_t0 = var_t1->face_offset;
            if (var_t0 != NULL) {
                for (var_t2 = 0; var_t2 < var_t1->face_count; var_t2++) {
                    temp_a2 = (u32)var_t0 + (((u32) var_t0->stuffed_data >> 0xC) & 0x3F)*4;
                    if (var_t0->flags & 0x10) {
                        clamp(temp_a2[0].r, arg1[0], temp, why);
                        clamp(temp_a2[0].g, arg1[1], temp, why);
                        clamp(temp_a2[0].b, arg1[2], temp, why);
                        clamp(temp_a2[1].r, arg1[0], temp, why);
                        clamp(temp_a2[1].g, arg1[1], temp, why);
                        clamp(temp_a2[1].b, arg1[2], temp, why);
                        clamp(temp_a2[2].r, arg1[0], temp, why);
                        clamp(temp_a2[2].g, arg1[1], temp, why);
                        clamp(temp_a2[2].b, arg1[2], temp, why);
                        if (var_t0->flags & 8) {
                            clamp(temp_a2[3].r, arg1[0], temp, why);
                            clamp(temp_a2[3].g, arg1[1], temp, why);
                            clamp(temp_a2[3].b, arg1[2], temp, why);
                        }
                    } else {
                        clamp(temp_a2[0].r, arg1[0], temp, why);
                        clamp(temp_a2[0].g, arg1[1], temp, why);
                        clamp(temp_a2[0].b, arg1[2], temp, why);
                    }
                    var_t0 = (u32)var_t0 + (((u32) var_t0->stuffed_data >> 0x16) & 0xFC);
                }
            }
            var_t1 = var_t1->next_facegroup;
        }
        arg0 = arg0->next_meshdef1_pointer;
    }
}

#undef clamp
#else
INCLUDE_ASM("asm/nonmatchings/main/56F50", applyMeshdef1AnimColors);
#endif

#if 0
// https://decomp.me/scratch/X81CI
void freeAllHobFiles(void) {
    s32 var_s2;
    u16 var_v1;

    for (var_s2 = 0; var_s2 < 25; var_s2++) {
        var_v1 = hobObjectHashMap[var_s2];
        while (var_v1 != 0xFFFF) {
            if (hobObjectListItems[var_v1].hob_file != NULL) {
                rs_free(hobObjectListItems[var_v1].hob_file);
            }
            var_v1 = hobObjectListItems[var_v1].nextIndex;
            hobObjectHashMap[var_s2] = var_v1;
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/main/56F50", freeAllHobFiles);
#endif

struct D_main_bss_801394E8_type *createMeshInstanceFromSource(struct object_entry *arg0, struct D_main_bss_801394E8_type *arg1) {
    struct D_main_bss_801394E8_type *var_s0;
    struct meshdef1 *temp_a0;

    var_s0 = arg1;
    if (var_s0 == NULL) {
        var_s0 = rs_malloc(sizeof(struct D_main_bss_801394E8_type), 0U);
    }
    var_s0->object_entry = arg0;
    temp_a0 = var_s0->meshdef1;
    arg0->bshort += 1;
    var_s0->unk04 = NULL;
    var_s0->unk08 = 1;
    var_s0->unk0A = 0;
    var_s0->unk0B = 0;
    var_s0->meshdef0[0].unknown_meshdef0_pointer1 = NULL;
    var_s0->meshdef0[0].unknown_meshdef0_pointer0 = NULL;
    var_s0->meshdef0[0].next_meshdef0_pointer = NULL;
    var_s0->meshdef0[0].prev_meshdef0_pointer = NULL;
    var_s0->meshdef0[0].meshdef1_pointer = temp_a0;
    var_s0->meshdef0[0].two_floats[0] = 0.0f;
    var_s0->meshdef1[0].prev_meshdef1_pointer = NULL;
    var_s0->meshdef1[0].next_meshdef1_pointer = NULL;
    var_s0->meshdef1[0].unk08 = arg0->meshdef1_prelude_offsets[0]->meshdef1_offsets_mostly[0];
    var_s0->meshdef1[0].unk0C = 4;
    clearStructPair2C30(temp_a0);
    return var_s0;
}

INCLUDE_ASM("asm/nonmatchings/main/56F50", setMeshInstanceLodAndRebuildNodes);

INCLUDE_ASM("asm/nonmatchings/main/56F50", checkAndReturnByteFlagAsU8);

INCLUDE_ASM("asm/nonmatchings/main/56F50", lookupHmtMaterialByName);

INCLUDE_ASM("asm/nonmatchings/main/56F50", getNpcContextFloatAt34);

INCLUDE_ASM("asm/nonmatchings/main/56F50", findModelChildNodeByName);

INCLUDE_ASM("asm/nonmatchings/main/56F50", applyFlagsToMeshTreeOrList);

void setMaterialFlagByIdInMeshTree(struct meshdef1 *arg0, u16 arg1, u16 arg2) {
    s32 temp_a1;
    struct face *var_v1;
    struct facegroup *var_a3;
    s32 var_a0;

    var_a3 = arg0->facegroup_pointer;
    while (var_a3 != NULL) {
        var_v1 = var_a3->face_offset;
        for (var_a0 = var_a3->face_count; var_a0 > 0; var_a0--) {
            if ((arg1 == 0xFFFF) || (var_v1->unk08.as_pair.material_index == arg1)) {
                var_v1->unk08.as_word = var_v1->unk08.as_pair.unk0A | (arg2 << 0x10);
            }
            var_v1 = (u32) var_v1 + ((u32) (var_v1->stuffed_data & 0x3F000000) >> 0x16);
        }
        var_a3 = var_a3->next_facegroup;
    }
}

INCLUDE_ASM("asm/nonmatchings/main/56F50", releaseSceneObjectMeshTree);

void recursivelyReleaseMeshTree(struct meshdef0 *arg0) {
    struct meshdef1 *temp_a0;
    struct meshdef1 *var_s0;

    if (arg0 != NULL) {
        do {
            temp_a0 = arg0->inner.meshdef1_pointer;
            if (temp_a0 != NULL) {
                var_s0 = temp_a0;
                do {
                    if (var_s0->unk0C & 0x10) {
                        enqueueMeshForDeferredRelease(var_s0);
                        var_s0->unk0C |= 8;
                    }
                    var_s0 = var_s0->next_meshdef1_pointer;
                } while (var_s0 != NULL);
            }
            if (arg0->inner.unknown_meshdef0_pointer1 != NULL) {
                recursivelyReleaseMeshTree(arg0->inner.unknown_meshdef0_pointer1);
            }
            arg0 = arg0->inner.next_meshdef0_pointer;
        } while (arg0 != NULL);
    }
}

void walkMeshdef0TreeApplyAnimColors(struct meshdef0 *arg0, u32 arg1) {
    if (arg0 != NULL) {
        do {
            if (arg0->inner.meshdef1_pointer != NULL) {
                applyMeshdef1AnimColors(arg0->inner.meshdef1_pointer, arg1);
            }
            if (arg0->inner.unknown_meshdef0_pointer1 != NULL) {
                walkMeshdef0TreeApplyAnimColors(arg0->inner.unknown_meshdef0_pointer1, arg1);
            }
            arg0 = arg0->inner.next_meshdef0_pointer;
        } while (arg0 != NULL);
    }
}

INCLUDE_ASM("asm/nonmatchings/main/56F50", findNameTreeEntryIndexByName);

INCLUDE_ASM("asm/nonmatchings/main/56F50", findNameTreeEntryNodeByName);

INCLUDE_ASM("asm/nonmatchings/main/56F50", readFirstNameTreeEntry);

INCLUDE_ASM("asm/nonmatchings/main/56F50", readFirstNameTreeEntryFromNode);

INCLUDE_ASM("asm/nonmatchings/main/56F50", enqueueMeshTypeForCleanup);

void walkListAndUpdateFlagsAt0xC(struct meshdef1 *arg0, u32 arg1, u32 arg2) {
    if (arg0 != NULL) {
        do {
            arg0->unk0C = (arg0->unk0C & ~arg2) | arg1;
            arg0 = arg0->next_meshdef1_pointer;
        } while (arg0 != NULL);
    }
}

void applyFlagsToMeshdef1List(struct meshdef0 *arg0, u32 arg1, u32 arg2) {
    struct meshdef1 *why;
    struct meshdef0 *doublewhy;
    struct meshdef1 *var_v1;

    doublewhy = arg0;
    while (doublewhy != NULL) {
        // It feels like this is meant to be an inlined version of `walkListAndUpdateFlagsAt0xC`, but I can't get that to match
        why = doublewhy->inner.meshdef1_pointer;
        if (why != NULL) {
            var_v1 = why;
            while (var_v1 != NULL) {
                var_v1->unk0C = ((var_v1->unk0C & ~arg2) | arg1);
                var_v1 = var_v1->next_meshdef1_pointer;
            }
        }
        if (doublewhy->inner.unknown_meshdef0_pointer1 != NULL) {
            applyFlagsToMeshdef1List(doublewhy->inner.unknown_meshdef0_pointer1, arg1, arg2);
        }
        doublewhy = doublewhy->inner.next_meshdef0_pointer;
    }
}

INCLUDE_ASM("asm/nonmatchings/main/56F50", processMeshTreeExcludingList);

INCLUDE_ASM("asm/nonmatchings/main/56F50", fake_func_80059B4C);
