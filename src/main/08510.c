#include "common.h"

#include "main/bss_801128E0.h"
#include "main/08510.h"
#include "main/1EE30.h"
#include "main/24570.h"
#include "main/24D30.h"

// Interim BSS externs
extern s32 D_main_bss_801143A0;
extern struct DisplayListBuffer  *D_main_bss_801163B0;
extern Gfx **D_main_bss_801163B8;
extern u8 D_main_bss_801163BC[];
extern Gfx *D_main_bss_801163D4;
extern struct DisplayListBuffer **D_main_bss_801163FC;
extern s32 D_main_bss_80117C00;
extern struct D_main_bss_80117C08_type D_main_bss_80117C08[0x200];
extern Gfx *D_main_bss_8011A438;
extern Gfx *D_main_bss_8011A43C;
extern u8 D_main_bss_8011A440;
extern Gfx *D_main_bss_8011A448;
extern Gfx *D_main_bss_8011A44C;
extern s8 D_main_bss_8011A450;
extern s32 D_main_bss_8011A460;
extern s32 D_main_bss_8011A4A8;
extern struct DisplayListBuffer **D_main_bss_8011A4AC;
extern struct DisplayListBuffer **D_main_bss_8011A4B8;
extern struct DisplayListBuffer **D_main_bss_8011A4BC;
extern struct DisplayListBuffer **D_main_bss_8011A4C4;
extern struct DisplayListBuffer **D_main_bss_8011A7DC;
extern u32 **D_main_bss_8011D090;
extern u8 D_main_bss_8011D094[]; // I really do not like this being an array, but code usage and BSS variable suggest that that is the case
extern struct D_main_bss_8011D498_type D_main_bss_8011D498[4];
extern s32 D_main_bss_80128C6C;

s32 registerSiCallback(void (*arg0)()) {
    s32 var_a1;

    for (var_a1 = 0; var_a1 < 4; var_a1++) {
        if (D_main_bss_8011A8A4[var_a1] != NULL) continue;
        D_main_bss_8011A8A4[var_a1] = arg0;
        return 1;
    }
    return 0;
}

void findAndZeroTableSlotMatching(void (*arg0)(void)) {
    s32 var_a1;

    for (var_a1 = 0; var_a1 < 4; var_a1++) {
        if (D_main_bss_8011A8A4[var_a1] == arg0) {
            D_main_bss_8011A8A4[var_a1] = NULL;
            break;
        }
    }
}

void clearFourWordTable(void) {
    s32 var_a1;

    for (var_a1 = 3; var_a1 >= 0; var_a1--) {
        D_main_bss_8011A8A4[var_a1] = NULL;
    }
}

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

INCLUDE_ASM("asm/nonmatchings/main/08510", heapWalker);

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

#if 0
// https://decomp.me/scratch/d5Kij
// Register allocation issues
// Also, something about the inlining of heapFreeListInsert causes the stack popping
// to occur in the `jr ra` delay slot, which is weird to see for a file compiled with
// GCC 2.7.2. Outside of this file, I've only seen that when using GCC 2.8.1
struct DisplayListBuffer *reclaimDisplayListChunk(void) {
    struct DisplayListBuffer *temp_a0;

    temp_a0 = D_main_bss_801163B0;
    if (D_main_bss_801163B0 == NULL) {
        heapFreeListInsert(findAndUnlinkSmallestEntry());
        temp_a0 = D_main_bss_801163B0;
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

#if 0
// Register allocation issues related to the inlining of `reclaimDisplayListChunk`
Gfx *allocateDisplayListBuffer(void) {
    struct DisplayListBuffer *temp_v1;

    temp_v1 = reclaimDisplayListChunk();
    if (*D_main_bss_801163FC == NULL) {
        *D_main_bss_801163FC = temp_v1;
    } else {
        (*D_main_bss_8011A7DC)->next = temp_v1;
        temp_v1->prev = *D_main_bss_8011A7DC;
    }
    temp_v1->next = NULL;
    *D_main_bss_8011A7DC = temp_v1;
    D_main_bss_801163D4 = &temp_v1->displayList[0x1F];
    return temp_v1->displayList;
}
#else
INCLUDE_ASM("asm/nonmatchings/main/08510", allocateDisplayListBuffer);
#endif

#if 0
// Register allocation issues related to the inlining of `reclaimDisplayListChunk`
Gfx *allocDLBlockToFillRectList(void) {
    struct DisplayListBuffer *temp_a1;

    temp_a1 = reclaimDisplayListChunk();
    if (*D_main_bss_8011A4C4 != NULL) {
        (*D_main_bss_8011A4C4)->prev = temp_a1;
    }
    temp_a1->next = *D_main_bss_8011A4C4;
    *D_main_bss_8011A4C4 = temp_a1;
    return temp_a1->displayList;
}
#else
INCLUDE_ASM("asm/nonmatchings/main/08510", allocDLBlockToFillRectList);
#endif

#if 0
// Register allocation issues related to the inlining of `reclaimDisplayListChunk`
Gfx *allocDLBlockToListB(void) {
    struct DisplayListBuffer *temp_a1;

    temp_a1 = reclaimDisplayListChunk();
    if (*D_main_bss_8011A4AC != NULL) {
        (*D_main_bss_8011A4AC)->prev = temp_a1;
    }
    temp_a1->next = *D_main_bss_8011A4AC;
    *D_main_bss_8011A4AC = temp_a1;
    return temp_a1->displayList;
}
#else
INCLUDE_ASM("asm/nonmatchings/main/08510", allocDLBlockToListB);
#endif

#if 0
// Register allocation issues related to the inlining of `reclaimDisplayListChunk`
Gfx *allocDLBlockToListC(void) {
    struct DisplayListBuffer *temp_a1;

    temp_a1 = reclaimDisplayListChunk();
    if (*D_main_bss_8011A4B8 != NULL) {
        (*D_main_bss_8011A4B8)->prev = temp_a1;
    }
    temp_a1->next = *D_main_bss_8011A4B8;
    *D_main_bss_8011A4B8 = temp_a1;
    return temp_a1->displayList;
}
#else
INCLUDE_ASM("asm/nonmatchings/main/08510", allocDLBlockToListC);
#endif

#if 0
// Register allocation issues related to the inlining of `reclaimDisplayListChunk`
Gfx *allocDLBlockToListD(void) {
    struct DisplayListBuffer *temp_a1;

    temp_a1 = reclaimDisplayListChunk();
    if (*D_main_bss_8011A4BC != NULL) {
        (*D_main_bss_8011A4BC)->prev = temp_a1;
    }
    temp_a1->next = *D_main_bss_8011A4BC;
    *D_main_bss_8011A4BC = temp_a1;
    return temp_a1->displayList;
}
#else
INCLUDE_ASM("asm/nonmatchings/main/08510", allocDLBlockToListD);
#endif

INCLUDE_ASM("asm/nonmatchings/main/08510", drainMeshReleaseQueue);

INCLUDE_ASM("asm/nonmatchings/main/08510", enqueueMeshForDeferredRelease);

#if 0
void recordDeferredDrawRefVariant(Gfx *arg0, s32 arg1, u32 arg2) {
    if (arg1 & 0x40000000) {
        if (D_main_bss_8011D094[0] >= 0x40) {
            D_main_bss_8011D090 = allocDLBlockToListD();
            D_main_bss_8011D094[0] = 0;
        }
        D_main_bss_8011D090[D_main_bss_8011D094[0]++] = SEGMENT_OFFSET(arg0) | (arg2 << 0x18);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/main/08510", recordDeferredDrawRefVariant);
#endif

INCLUDE_ASM("asm/nonmatchings/main/08510", commitMeshDrawBatchRefs);

#if 0
// Register allocation issues related to the inlining of `allocDLBlockToFillRectList`

Gfx *emitAllocatedDLCommand(Gfx *arg0, u32 arg1) {
    if (arg0 >= D_main_bss_801163D4) {
        gSPLine3D(arg0, 0, 0, 0);
        arg0 = allocateDisplayListBuffer();
    }
    recordDeferredDrawRefVariant(arg0, arg1, 0);
    D_main_bss_8011A448 = arg0++;
    D_main_bss_8011A450 = 0;
    D_main_bss_8011A44C = allocDLBlockToFillRectList();
    return arg0;
}
#else
INCLUDE_ASM("asm/nonmatchings/main/08510", emitAllocatedDLCommand);
#endif

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

s32 initRenderStateArrays(void) {
    s32 var_a1;
    s32 var_v0;

    beginFrameDLChunk();
    D_main_bss_80128C6C = 0;
    D_main_bss_801143A0 = 0;
    for (var_a1 = 0; var_a1 < 4; var_a1++) {
        for (var_v0 = 0x3F; var_v0 >= 0; var_v0--) {
            D_main_bss_8011D498[var_a1].unk000[var_v0] = NULL;
        }
        for (var_v0 = 0x1F; var_v0 >= 0; var_v0--) {
            D_main_bss_8011D498[var_a1].unk100[var_v0] = NULL;
        }
    }
    D_main_bss_8011A460 = 0;
    D_main_bss_8011A4A8 = 0;
    D_main_bss_80117C00 = 0;
    return 1;
}

#if 0
// Register allocation issues related to the inlining of first `allocateDisplayListBuffer`
s32 drawFrameProfilerBars(void) {
    beginFrameDLChunk();
    D_main_bss_8011DC58 = D_main_bss_8011DC50;
    D_main_bss_8011DC58 = emitProfilerBarSegment(D_main_bss_8011DC58, D_main_bss_8011A914, D_main_bss_8011A910 - 0x28, 0xFF, 0xFF, 0x00);
    D_main_bss_8011DC58 = emitProfilerBarSegment(D_main_bss_8011DC58, D_main_bss_80128EE0, D_main_bss_8011A910 - 0x23, 0x00, 0x00, 0xFF);
    D_main_bss_8011DC58 = emitProfilerBarSegment(D_main_bss_8011DC58, D_main_bss_80128EDC, D_main_bss_8011A910 - 0x1E, 0xFF, 0x00, 0x00);
    D_main_bss_8011DC58 = emitProfilerBarSegment(D_main_bss_8011DC58, D_main_bss_8011A920, D_main_bss_8011A910 - 0x19, 0xFF, 0x00, 0xFF);
    D_main_bss_8011DC58 = emitProfilerBarSegment(D_main_bss_8011DC58, D_main_bss_8011DC54, D_main_bss_8011A910 - 0x14, 0xFF, 0xFF, 0xFF);
    D_main_bss_8011DC58 = emitProfilerBarSegment(D_main_bss_8011DC58, D_main_bss_8011DC4C, D_main_bss_8011A910 - 0x0F, 0x00, 0xFF, 0x00);
    D_main_bss_8011DC58 = emitProfilerBarSegment(D_main_bss_8011DC58, D_main_bss_8011A918, D_main_bss_8011A910 - 0x0A, 0x00, 0xFF, 0xFF);
    D_main_bss_8011DC58 = flushDebugTextOverlay(D_main_bss_8011DC58);
    if (D_main_bss_8011DC58 >= D_main_bss_801163D4) {
        gSPLine3D(D_main_bss_8011DC58, 0, 0, 0);
        D_main_bss_8011DC58 = allocateDisplayListBuffer();
    }
    gDPFullSync(D_main_bss_8011DC58++);
    if (D_main_bss_8011DC58 >= D_main_bss_801163D4) {
        gSPLine3D(D_main_bss_8011DC58, 0, 0, 0);
        D_main_bss_8011DC58 = allocateDisplayListBuffer();
    }
    gSPEndDisplayList(D_main_bss_8011DC58++);
    return 1;
}
#else
INCLUDE_ASM("asm/nonmatchings/main/08510", drawFrameProfilerBars);
#endif

INCLUDE_ASM("asm/nonmatchings/main/08510", emitCombinerStateAndPatch);

void computeFrameDeltaTime(void) {
    if (D_main_bss_8011A900 == -1) {
        D_main_bss_8011A904 = 0;
    } else {
        D_main_bss_8011A904 = D_main_bss_80128ED8 - D_main_bss_8011A900;
    }
    D_main_bss_8011A900 = D_main_bss_80128ED8;
}

INCLUDE_ASM("asm/nonmatchings/main/08510", timeSnapshotFiller);

INCLUDE_ASM("asm/nonmatchings/main/08510", bufferArbiterProducerScanWait);

INCLUDE_ASM("asm/nonmatchings/main/08510", submitGfxFrame);

#if 0
void recordDeferredDrawRefA(u32 arg0, Gfx *arg1) {
    if (arg0 & 0x40000000) {
        if (D_main_bss_801163BC[0] >= 0x40U) {
            D_main_bss_801163B8 = allocDLBlockToListC();
            D_main_bss_801163BC[0] = 0;
        }
        D_main_bss_801163B8[D_main_bss_801163BC[0]++] = arg1;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/main/08510", recordDeferredDrawRefA);
#endif

#if 0
void recordDeferredDrawRefB(u32 arg0) {
    if (arg0 & 0x40000000) {
        if (D_main_bss_801163BC[0] >= 0x40U) {
            D_main_bss_801163B8 = allocDLBlockToListC();
            D_main_bss_801163BC[0] = 0;
        }
        D_main_bss_801163B8[D_main_bss_801163BC[0]++] = NULL;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/main/08510", recordDeferredDrawRefB);
#endif

#if 0
// NOT MATCHING
// The accessing of `D_main_bss_801163BC` in this function does not look like array access, unlike every other function that uses it.
void recordDeferredDrawRefC(u32 arg0, Gfx *arg1) {
    if (arg0 & 0x40000000) {
        if (D_main_bss_801163BC[0] >= 0x40U) {
            D_main_bss_801163B8 = allocDLBlockToListC();
            D_main_bss_801163BC[0] = 0;
        }
        D_main_bss_801163B8[D_main_bss_801163BC[0]++] = arg1;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/main/08510", recordDeferredDrawRefC);
#endif

#if 0
// NOT MATCHING
// The accessing of `D_main_bss_801163BC` in this function does not look like array access, unlike every other function that uses it.
void recordDeferredDrawRefD(u32 arg0) {
    if (arg0 & 0x40000000) {
        if (D_main_bss_801163BC[0] >= 0x40U) {
            D_main_bss_801163B8 = allocDLBlockToListC();
            D_main_bss_801163BC[0] = 0;
        }
        D_main_bss_801163B8[D_main_bss_801163BC[0]++] = NULL;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/main/08510", recordDeferredDrawRefD);
#endif

#if 0
Gfx *reserveAndEmitDLEntry(Gfx *arg0, u32 arg1) {
    if (arg0 >= D_main_bss_801163D4) {
        gSPLine3D(arg0, 0, 0, 0);
        arg0 = allocateDisplayListBuffer();
    }
    recordDeferredDrawRefVariant(arg0, arg1, 1);
    D_main_bss_8011A438 = arg0++;
    D_main_bss_8011A440 = 0;
    D_main_bss_8011A43C = allocDLBlockToListB();
    return arg0;
}
#else
INCLUDE_ASM("asm/nonmatchings/main/08510", reserveAndEmitDLEntry);
#endif

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
