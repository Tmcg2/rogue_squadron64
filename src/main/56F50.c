#include "common.h"

#include "main/56F50.h"

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

INCLUDE_ASM("asm/nonmatchings/main/56F50", meshdef0_offset_convert);

INCLUDE_ASM("asm/nonmatchings/main/56F50", applyMeshdef1AnimColors);

INCLUDE_ASM("asm/nonmatchings/main/56F50", freeAllHobFiles);

INCLUDE_ASM("asm/nonmatchings/main/56F50", createMeshInstanceFromSource);

INCLUDE_ASM("asm/nonmatchings/main/56F50", setMeshInstanceLodAndRebuildNodes);

INCLUDE_ASM("asm/nonmatchings/main/56F50", checkAndReturnByteFlagAsU8);

INCLUDE_ASM("asm/nonmatchings/main/56F50", lookupHmtMaterialByName);

INCLUDE_ASM("asm/nonmatchings/main/56F50", getNpcContextFloatAt34);

INCLUDE_ASM("asm/nonmatchings/main/56F50", findModelChildNodeByName);

INCLUDE_ASM("asm/nonmatchings/main/56F50", applyFlagsToMeshTreeOrList);

INCLUDE_ASM("asm/nonmatchings/main/56F50", setMaterialFlagByIdInMeshTree);

INCLUDE_ASM("asm/nonmatchings/main/56F50", releaseSceneObjectMeshTree);

INCLUDE_ASM("asm/nonmatchings/main/56F50", recursivelyReleaseMeshTree);

INCLUDE_ASM("asm/nonmatchings/main/56F50", walkMeshdef0TreeApplyAnimColors);

INCLUDE_ASM("asm/nonmatchings/main/56F50", findNameTreeEntryIndexByName);

INCLUDE_ASM("asm/nonmatchings/main/56F50", findNameTreeEntryNodeByName);

INCLUDE_ASM("asm/nonmatchings/main/56F50", readFirstNameTreeEntry);

INCLUDE_ASM("asm/nonmatchings/main/56F50", readFirstNameTreeEntryFromNode);

INCLUDE_ASM("asm/nonmatchings/main/56F50", enqueueMeshTypeForCleanup);

INCLUDE_ASM("asm/nonmatchings/main/56F50", walkListAndUpdateFlagsAt0xC);

INCLUDE_ASM("asm/nonmatchings/main/56F50", applyFlagsToMeshdef1List);

INCLUDE_ASM("asm/nonmatchings/main/56F50", processMeshTreeExcludingList);

INCLUDE_ASM("asm/nonmatchings/main/56F50", fake_func_80059B4C);
