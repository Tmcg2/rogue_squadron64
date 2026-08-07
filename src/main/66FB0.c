#include "common.h"

INCLUDE_ASM("asm/nonmatchings/main/66FB0", loadSndFiles);

INCLUDE_ASM("asm/nonmatchings/main/66FB0", initAudioListenerFromCamera);

INCLUDE_ASM("asm/nonmatchings/main/66FB0", loadSongAssetByName);

INCLUDE_ASM("asm/nonmatchings/main/66FB0", updateAudioListenerVelocity);

INCLUDE_ASM("asm/nonmatchings/main/66FB0", teardownAudioListenerNode);

INCLUDE_ASM("asm/nonmatchings/main/66FB0", waitForAnyAudioSlot);

INCLUDE_ASM("asm/nonmatchings/main/66FB0", parseLoadedSndSection);

INCLUDE_ASM("asm/nonmatchings/main/66FB0", freeAudioCacheEntry);

INCLUDE_ASM("asm/nonmatchings/main/66FB0", findAudioChannelById);

INCLUDE_ASM("asm/nonmatchings/main/66FB0", updateAudioListenerPosFromPlayer);

INCLUDE_ASM("asm/nonmatchings/main/66FB0", initSpeechSubsystem);

INCLUDE_ASM("asm/nonmatchings/main/66FB0", enqueueSpeechClip);

INCLUDE_ASM("asm/nonmatchings/main/66FB0", applySpeechVolumeScalar);

INCLUDE_ASM("asm/nonmatchings/main/66FB0", playSpeechClip);

INCLUDE_ASM("asm/nonmatchings/main/66FB0", queueSpeechClipWithPriority);

INCLUDE_ASM("asm/nonmatchings/main/66FB0", tickSpeechSubsystem);

INCLUDE_ASM("asm/nonmatchings/main/66FB0", resetSpeechSubsystem);

INCLUDE_ASM("asm/nonmatchings/main/66FB0", finalizeCurrentSpeechBuffer);

INCLUDE_ASM("asm/nonmatchings/main/66FB0", initSpeechPlaybackState);

INCLUDE_ASM("asm/nonmatchings/main/66FB0", clearSpeechActiveFlags);

INCLUDE_ASM("asm/nonmatchings/main/66FB0", beginSpeechTimingWindow);

INCLUDE_ASM("asm/nonmatchings/main/66FB0", endSpeechTimingWindow);

INCLUDE_ASM("asm/nonmatchings/main/66FB0", getSpeechPlaybackElapsedTime);

INCLUDE_ASM("asm/nonmatchings/main/66FB0", isSpeechBusyOrQueued);

INCLUDE_ASM("asm/nonmatchings/main/66FB0", setSpeechVolume);

INCLUDE_ASM("asm/nonmatchings/main/66FB0", isSpeechSlotActive);

INCLUDE_ASM("asm/nonmatchings/main/66FB0", stopSpeechSlotIfActive);

INCLUDE_ASM("asm/nonmatchings/main/66FB0", stopAllSpeechSlots);

INCLUDE_ASM("asm/nonmatchings/main/66FB0", advanceSpeechRingAndStopHead);

INCLUDE_ASM("asm/nonmatchings/main/66FB0", playSpeechClipGated);
