#include "common.h"

#include "main/02490.h"
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

INCLUDE_ASM("asm/nonmatchings/main/56F50", applyRgbaTintToMeshVertices);

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

INCLUDE_ASM("asm/nonmatchings/main/56F50", applyMeshdef1AnimColors);

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

INCLUDE_ASM("asm/nonmatchings/main/56F50", createMeshInstanceFromSource);

INCLUDE_ASM("asm/nonmatchings/main/56F50", setMeshInstanceLodAndRebuildNodes);

INCLUDE_ASM("asm/nonmatchings/main/56F50", checkAndReturnByteFlagAsU8);

INCLUDE_ASM("asm/nonmatchings/main/56F50", lookupHmtMaterialByName);

INCLUDE_ASM("asm/nonmatchings/main/56F50", getNpcContextFloatAt34);

INCLUDE_ASM("asm/nonmatchings/main/56F50", findModelChildNodeByName);

INCLUDE_ASM("asm/nonmatchings/main/56F50", applyFlagsToMeshTreeOrList);

INCLUDE_ASM("asm/nonmatchings/main/56F50", setMaterialFlagByIdInMeshTree);

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
