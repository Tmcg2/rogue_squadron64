#include "common.h"

INCLUDE_ASM("asm/nonmatchings/main/06560", initMemoryPack);

INCLUDE_ASM("asm/nonmatchings/main/06560", writeSaveBodyToEeprom);

INCLUDE_ASM("asm/nonmatchings/main/06560", writeSaveDataBodyToEeprom);

INCLUDE_ASM("asm/nonmatchings/main/06560", copySaveUnk08);

INCLUDE_ASM("asm/nonmatchings/main/06560", initSaveData);

INCLUDE_ASM("asm/nonmatchings/main/06560", freeSaveDataBuffer);

INCLUDE_ASM("asm/nonmatchings/main/06560", setSaveDataCallback);

INCLUDE_ASM("asm/nonmatchings/main/06560", saveLoadDispatcher);

INCLUDE_ASM("asm/nonmatchings/main/06560", loadOrSaveEepromRecord);

INCLUDE_ASM("asm/nonmatchings/main/06560", loadOrSaveAllEepromRecords);

INCLUDE_ASM("asm/nonmatchings/main/06560", fake_func_80006BFC);
