#include "common.h"

INCLUDE_ASM("asm/nonmatchings/main/97D20", resetSongSubsystemCounter);

INCLUDE_ASM("asm/nonmatchings/main/97D20", bindMacroIdsToSoundGroup);

INCLUDE_ASM("asm/nonmatchings/main/97D20", registerSndMacroTable);

INCLUDE_ASM("asm/nonmatchings/main/97D20", registerSndCurveTable);

INCLUDE_ASM("asm/nonmatchings/main/97D20", registerSndSampleTable);

INCLUDE_ASM("asm/nonmatchings/main/97D20", applySndMidiSetupRecords);

INCLUDE_ASM("asm/nonmatchings/main/97D20", releaseSndMidiSetupRecords);

INCLUDE_ASM("asm/nonmatchings/main/97D20", parseSndFiles);

INCLUDE_ASM("asm/nonmatchings/main/97D20", unloadLastSndFileGroup);

INCLUDE_ASM("asm/nonmatchings/main/97D20", returnZeroAudioStub);

INCLUDE_ASM("asm/nonmatchings/main/97D20", playSongByIdLockCtl);

INCLUDE_ASM("asm/nonmatchings/main/97D20", playSongById);

INCLUDE_ASM("asm/nonmatchings/main/97D20", fake_func_80097D58);
