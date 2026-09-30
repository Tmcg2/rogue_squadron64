#include "common.h"

#include "main/08510.h"
#include "main/1EE30.h"

// Interim BSS externs
extern struct DisplayListBuffer *D_main_bss_801163B0;

INCLUDE_ASM("asm/nonmatchings/main/08510", registerSiCallback);

INCLUDE_ASM("asm/nonmatchings/main/08510", findAndZeroTableSlotMatching);

INCLUDE_ASM("asm/nonmatchings/main/08510", clearFourWordTable);

#if 0
// I strongly suspect this file is compiled with O3, and that this function gets inlined
void heapFreeListInsert(struct DisplayListBuffer *arg0) {
    struct DisplayListBuffer *var_v1;

    if (arg0 != NULL) {
        var_v1 = arg0;
        if (arg0->next != NULL) {
            do {
                var_v1 = var_v1->next;
            } while (var_v1->next != NULL);
        }
        var_v1->next = D_main_bss_801163B0;
        if (D_main_bss_801163B0 != NULL) {
            D_main_bss_801163B0->prev = var_v1;
        }
        D_main_bss_801163B0 = arg0;
        D_main_bss_801163B0->prev = NULL;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/main/08510", heapFreeListInsert);
#endif

INCLUDE_ASM("asm/nonmatchings/main/08510", heapWalker);

#if 0
s32 countDisplayListChunks(void) {
    s32 blah;
    struct DisplayListBuffer *var_v1;

    blah = 0;
    var_v1 = D_main_bss_801163B0;
    while (var_v1 != NULL) {
        var_v1 = var_v1->next;
        blah += sizeof(struct DisplayListBuffer);
    }
    return blah;
}
#else
INCLUDE_ASM("asm/nonmatchings/main/08510", countDisplayListChunks);
#endif

#if 0
struct DisplayListBuffer *reclaimDisplayListChunk(void) {
    struct DisplayListBuffer *temp_a0;
    struct DisplayListBuffer *temp_v0;
    struct DisplayListBuffer *temp_v0_2;
    struct DisplayListBuffer *var_v1;

    temp_a0 = D_main_bss_801163B0;
    if (temp_a0 == NULL) {
        temp_v0 = findAndUnlinkSmallestEntry();
        heapFreeListInsert(temp_v0);
        // if (temp_v0 != NULL) {
        //     var_v1 = temp_v0;
        //     if (temp_v0->next != NULL) {
        //         do {
        //             var_v1 = var_v1->next;
        //         } while (var_v1->next != NULL);
        //     }
        //     var_v1->next = D_main_bss_801163B0;
        //     if (D_main_bss_801163B0 != NULL) {
        //         D_main_bss_801163B0->prev = var_v1;
        //     }
        //     D_main_bss_801163B0 = temp_v0;
        //     temp_v0->prev = NULL;
        // }
    }
    D_main_bss_801163B0 = D_main_bss_801163B0->next;
    if (D_main_bss_801163B0 != NULL) {
        D_main_bss_801163B0->prev = NULL;
    }
    return temp_a0;
}
#else
INCLUDE_ASM("asm/nonmatchings/main/08510", reclaimDisplayListChunk);
#endif

INCLUDE_ASM("asm/nonmatchings/main/08510", allocateDisplayListBuffer);

INCLUDE_ASM("asm/nonmatchings/main/08510", allocDLBlockToFillRectList);

INCLUDE_ASM("asm/nonmatchings/main/08510", allocDLBlockToListB);

INCLUDE_ASM("asm/nonmatchings/main/08510", allocDLBlockToListC);

INCLUDE_ASM("asm/nonmatchings/main/08510", allocDLBlockToListD);

INCLUDE_ASM("asm/nonmatchings/main/08510", drainMeshReleaseQueue);

INCLUDE_ASM("asm/nonmatchings/main/08510", enqueueMeshForDeferredRelease);

INCLUDE_ASM("asm/nonmatchings/main/08510", recordDeferredDrawRefVariant);

INCLUDE_ASM("asm/nonmatchings/main/08510", commitMeshDrawBatchRefs);

INCLUDE_ASM("asm/nonmatchings/main/08510", emitAllocatedDLCommand);

INCLUDE_ASM("asm/nonmatchings/main/08510", emitFaceDLCommands);

INCLUDE_ASM("asm/nonmatchings/main/08510", emitFrameRdpInitDl);

INCLUDE_ASM("asm/nonmatchings/main/08510", setActiveRenderListPtr);

INCLUDE_ASM("asm/nonmatchings/main/08510", emitColorFillRect);

INCLUDE_ASM("asm/nonmatchings/main/08510", setScreenColorOverlay);

INCLUDE_ASM("asm/nonmatchings/main/08510", disableScreenColorOverlay);

INCLUDE_ASM("asm/nonmatchings/main/08510", frameStartReset);

INCLUDE_ASM("asm/nonmatchings/main/08510", clearStructPair2C30);

INCLUDE_ASM("asm/nonmatchings/main/08510", waitForPrevFrameDone);

INCLUDE_ASM("asm/nonmatchings/main/08510", beginFrameDLChunk);

INCLUDE_ASM("asm/nonmatchings/main/08510", initRenderStateArrays);

INCLUDE_ASM("asm/nonmatchings/main/08510", drawFrameProfilerBars);

INCLUDE_ASM("asm/nonmatchings/main/08510", emitCombinerStateAndPatch);

INCLUDE_ASM("asm/nonmatchings/main/08510", computeFrameDeltaTime);

INCLUDE_ASM("asm/nonmatchings/main/08510", timeSnapshotFiller);

INCLUDE_ASM("asm/nonmatchings/main/08510", bufferArbiterProducerScanWait);

INCLUDE_ASM("asm/nonmatchings/main/08510", submitGfxFrame);

INCLUDE_ASM("asm/nonmatchings/main/08510", recordDeferredDrawRefA);

INCLUDE_ASM("asm/nonmatchings/main/08510", recordDeferredDrawRefB);

INCLUDE_ASM("asm/nonmatchings/main/08510", recordDeferredDrawRefC);

INCLUDE_ASM("asm/nonmatchings/main/08510", recordDeferredDrawRefD);

INCLUDE_ASM("asm/nonmatchings/main/08510", reserveAndEmitDLEntry);

INCLUDE_ASM("asm/nonmatchings/main/08510", reserveAlignedDLSpace);

INCLUDE_RODATA("asm/nonmatchings/main/08510", D_main_800005A0);

INCLUDE_RODATA("asm/nonmatchings/main/08510", D_main_800005A8);

INCLUDE_RODATA("asm/nonmatchings/main/08510", D_main_800005B0);

INCLUDE_RODATA("asm/nonmatchings/main/08510", D_main_800005B8);

INCLUDE_RODATA("asm/nonmatchings/main/08510", D_main_800005C0);

INCLUDE_RODATA("asm/nonmatchings/main/08510", D_main_800005C8);

INCLUDE_RODATA("asm/nonmatchings/main/08510", D_main_800005D0);

INCLUDE_RODATA("asm/nonmatchings/main/08510", D_main_800005D8);

INCLUDE_RODATA("asm/nonmatchings/main/08510", D_main_800005E0);

INCLUDE_RODATA("asm/nonmatchings/main/08510", D_main_800005E8);

INCLUDE_RODATA("asm/nonmatchings/main/08510", D_main_800005F0);

INCLUDE_RODATA("asm/nonmatchings/main/08510", D_main_800005F8);

INCLUDE_RODATA("asm/nonmatchings/main/08510", D_main_80000600);

INCLUDE_RODATA("asm/nonmatchings/main/08510", D_main_80000608);

INCLUDE_ASM("asm/nonmatchings/main/08510", heapFreeListDequeue);

INCLUDE_ASM("asm/nonmatchings/main/08510", emitTexturedFaceGeometry);

INCLUDE_ASM("asm/nonmatchings/main/08510", transformLightByType);

INCLUDE_ASM("asm/nonmatchings/main/08510", appendRdpStateDl);

INCLUDE_ASM("asm/nonmatchings/main/08510", selectRenderPresetByIndex);

INCLUDE_ASM("asm/nonmatchings/main/08510", selectSecondaryPresetByIndex);

INCLUDE_ASM("asm/nonmatchings/main/08510", emitMaterialTexturedDL);

INCLUDE_ASM("asm/nonmatchings/main/08510", emitMaterialTexturedDLAlt);

INCLUDE_ASM("asm/nonmatchings/main/08510", resetSceneLightsAndMaterials);

INCLUDE_ASM("asm/nonmatchings/main/08510", transformSceneLights);

INCLUDE_ASM("asm/nonmatchings/main/08510", bindFaceVerticesToCache);

INCLUDE_ASM("asm/nonmatchings/main/08510", renderLitTexturedMeshFaces);

INCLUDE_ASM("asm/nonmatchings/main/08510", submitSceneNodeRender);

INCLUDE_ASM("asm/nonmatchings/main/08510", renderFlatMeshFaceGroup);

INCLUDE_ASM("asm/nonmatchings/main/08510", renderUnlitMeshFaces);

INCLUDE_ASM("asm/nonmatchings/main/08510", resetVertexCacheSlot);

INCLUDE_ASM("asm/nonmatchings/main/08510", buildOrientedFaceGeometry);

INCLUDE_ASM("asm/nonmatchings/main/08510", renderLitMeshFaceGroup);

INCLUDE_ASM("asm/nonmatchings/main/08510", processMeshdef1ForLod);

INCLUDE_ASM("asm/nonmatchings/main/08510", processSceneNode);

INCLUDE_ASM("asm/nonmatchings/main/08510", traverseSceneGraphRecursive);

INCLUDE_ASM("asm/nonmatchings/main/08510", drawTextGlyphRect);

INCLUDE_ASM("asm/nonmatchings/main/08510", drawSubtitleText);

INCLUDE_ASM("asm/nonmatchings/main/08510", setupCameraMatrices);

INCLUDE_ASM("asm/nonmatchings/main/08510", setFrameLevelStateBytes);

INCLUDE_ASM("asm/nonmatchings/main/08510", setRenderStateFlagByteOne);

INCLUDE_ASM("asm/nonmatchings/main/08510", setRenderStateFlagByteTwo);

INCLUDE_ASM("asm/nonmatchings/main/08510", setRenderStateFlagByteThree);

INCLUDE_ASM("asm/nonmatchings/main/08510", setViewStateBytesAndFadeScale);

INCLUDE_ASM("asm/nonmatchings/main/08510", setViewStateTripletBytes);

INCLUDE_ASM("asm/nonmatchings/main/08510", setMissionLevelInitByte);

s32 resetMaterialPoolWrapper(void) {
    resetMaterialPool();
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/main/08510", setRenderViewScaleFloat);

INCLUDE_ASM("asm/nonmatchings/main/08510", buildAndRegisterDefaultMaterial);

INCLUDE_ASM("asm/nonmatchings/main/08510", advanceVideoFrame);

INCLUDE_ASM("asm/nonmatchings/main/08510", initVideoBootWrapper);

INCLUDE_ASM("asm/nonmatchings/main/08510", freeRenderSubsystemResources);

INCLUDE_ASM("asm/nonmatchings/main/08510", fake_func_800186D8);

INCLUDE_RODATA("asm/nonmatchings/main/08510", junk_800007E8);
