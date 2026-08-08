#include "common.h"

INCLUDE_ASM("asm/nonmatchings/main/08510", registerSiCallback);

INCLUDE_ASM("asm/nonmatchings/main/08510", findAndZeroTableSlotMatching);

INCLUDE_ASM("asm/nonmatchings/main/08510", clearFourWordTable);

INCLUDE_ASM("asm/nonmatchings/main/08510", heapFreeListInsert);

INCLUDE_ASM("asm/nonmatchings/main/08510", heapWalker);

INCLUDE_ASM("asm/nonmatchings/main/08510", countDisplayListChunks);

INCLUDE_ASM("asm/nonmatchings/main/08510", reclaimDisplayListChunk);

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

INCLUDE_ASM("asm/nonmatchings/main/08510", resetMaterialPoolWrapper);

INCLUDE_ASM("asm/nonmatchings/main/08510", setRenderViewScaleFloat);

INCLUDE_ASM("asm/nonmatchings/main/08510", buildAndRegisterDefaultMaterial);

INCLUDE_ASM("asm/nonmatchings/main/08510", advanceVideoFrame);

INCLUDE_ASM("asm/nonmatchings/main/08510", initVideoBootWrapper);

INCLUDE_ASM("asm/nonmatchings/main/08510", freeRenderSubsystemResources);

INCLUDE_ASM("asm/nonmatchings/main/08510", fake_func_800186D8);
