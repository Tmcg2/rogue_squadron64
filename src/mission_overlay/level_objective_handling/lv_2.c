#include "common.h"

#include "mission_overlay/0C7EB0.h"
#include "mission_overlay/0C84A0.h"
#include "mission_overlay/level_objective_handling/lv_2.h"

u8  D_mission_overlay_8010B6C0[] = {0x6E, 0x6F, 0x70};
s32 D_mission_overlay_8010B6C4 = 0;
s32 D_mission_overlay_8010B6C8 = 0;
s32 D_mission_overlay_8010B6CC = 0;

s32 lv2_initializeObjectTracking(void) {
    D_mission_overlay_8010B6C4 = 0;
    D_mission_overlay_8010B6C8 = 0;
    D_mission_overlay_8010B6CC = 0;
    setLevelObjectTrackingScalar(7.5f);
    setObjectiveBoolean(0x20, 1U);
    addBooleanCountHandleWrapper(func_mission_overlay_801026CC, 0, 0, 0x3D, 1);
    addBooleanCountHandleWrapper(func_mission_overlay_801026EC, 4, 1, 0, 0);
    addBooleanCountHandleWrapper(func_mission_overlay_8010270C, 5, 1, 0, 0);
    addBooleanCountHandleWrapper(func_mission_overlay_8010272C, 6, 1, 0, 0);
    addBooleanCountHandleWrapper(func_mission_overlay_8010274C, 0x40, 1, 0, 0);
    addBooleanCountHandleWrapper(func_mission_overlay_8010276C, 0x41, 1, 0, 0);
    addBooleanCountHandleWrapper(func_mission_overlay_8010278C, 0x42, 1, 0, 0);
    addBooleanCountHandleWrapper(func_mission_overlay_801027AC, 1, 1, 0, 0);
    addBooleanCountHandleWrapper(func_mission_overlay_801027F0, 2, 1, 0, 0);
    addBooleanCountHandleWrapper(func_mission_overlay_80102834, 3, 1, 0, 0);
    addBooleanCountHandleWrapper(func_mission_overlay_80102878, 0x3D, 1, 0, 0);
    addBooleanCountHandleWrapper(func_mission_overlay_801028B0, 0x3E, 1, 0, 0);
    addBooleanCountHandleWrapper(func_mission_overlay_801028F4, 0x3F, 1, 0, 0);
    addBooleanCountHandleWrapper(func_mission_overlay_80102938, 0, 0, 0xB, 4);
    addBooleanCountHandleWrapper(func_mission_overlay_8010299C, 0, 0, 0xC, 4);
    addBooleanCountHandleWrapper(func_mission_overlay_80102A00, 0, 0, 0xD, 4);
    setObjectiveHiddenFlag(1, 3);
    return 0;
}

// This is here to force a specific string ordering, if matching isn't a concern
// replace the variable reference with raw copies of this string
const u8 string0_lv_2[] = {
    "MUSICRNG_LevelSettings"
};

s32 lv2_checkComplexObjectives(void) {
    s32 temp_v0;
    s32 temp_v0_10;
    s32 temp_v0_11;
    s32 temp_v0_12;
    s32 temp_v0_13;
    s32 temp_v0_14;
    s32 temp_v0_15;
    s32 temp_v0_16;
    s32 temp_v0_17;
    s32 temp_v0_18;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 temp_v0_4;
    s32 temp_v0_5;
    s32 temp_v0_6;
    s32 temp_v0_7;
    s32 temp_v0_8;
    s32 temp_v0_9;

    if ((getObjectiveBoolean(0x65) == 1) && (getObjectiveTimer(7) >= 6.0f)) {
        setObjectiveBoolean(0x65, 0U);
    }
    if (getObjectiveBoolean(0x65) == 0) {
        temp_v0 = getObjectiveBoolean(1);
        if ((temp_v0 == 1) && (getObjectiveBoolean(0x63) == 0) && (getObjectiveBoolean(7) == temp_v0) && (getObjectiveBoolean(0x64) == 0)) {
            setObjectiveBoolean(0x64, 1U);
            setObjectiveBoolean(0x65, 1U);
            setObjectiveTimer(7, 0.0f);
            playObjectiveVoiceLine2(0x55U, 0.0f);
            return 0;
        }
        if (getObjectiveBoolean(0x64) == 1) {
            setHudEnableBit4();
        }
        temp_v0_2 = getObjectiveBoolean(2);
        if ((temp_v0_2 != 1) || (getObjectiveBoolean(0x63) != 0) || (getObjectiveBoolean(8) != temp_v0_2) || (getObjectiveBoolean(0x64) != 0)) {
            if (getObjectiveBoolean(0x64) != 1) {
                temp_v0_3 = getObjectiveBoolean(3);
                if ((temp_v0_3 == 1) && (getObjectiveBoolean(0x63) == 0) && (getObjectiveBoolean(9) == temp_v0_3) && (getObjectiveBoolean(0x64) == 0)) {
                    setObjectiveBoolean(0x64, 1U);
                    setObjectiveBoolean(0x65, 1U);
                    setObjectiveTimer(7, 0.0f);
                    playObjectiveVoiceLine2(0x55U, 0.0f);
                    return 0;
                }
            } else {
                setHudEnableBit4();
            }
            if (getObjectiveBoolean(0x64) == 1) {
                setHudEnableBit4();
            }
            if ((getObjectiveCount(0x28) > 0) && (getObjectiveBoolean(0x6D) == 0)) {
                setObjectiveBoolean(0x6D, 1U);
                setObjectiveBoolean(0x65, 1U);
                setObjectiveTimer(7, 0.0f);
                playObjectiveVoiceLine2(0x56U, 0.0f);
                return 0;
            }
            if (getObjectiveBoolean(0x6D) == 1) {
                setHudEnableBit4();
            }
        } else {
            setObjectiveBoolean(0x64, 1U);
            setObjectiveBoolean(0x65, 1U);
            setObjectiveTimer(7, 0.0f);
            playObjectiveVoiceLine2(0x55U, 0.0f);
            return 0;
        }
    }
    if ((getObjectiveBoolean(0x80) == 1) && (getObjectiveBoolean(0x7F) == 0)) {
        setObjectiveBoolean(0x7F, 1U);
        setObjectiveBoolean(randMod(3) + 1, 1U);
    }
    if ((getObjectiveBoolean(0x3B) == 0) && (getObjectiveTimer(1) >= 100.0f)) {
        if ((getObjectiveBoolean(1) == 1) && (getObjectiveBoolean(7) == 0)) {
            setObjectiveBoolean(0x15, 1U);
            setObjectiveBoolean(0x3B, 1U);
            setObjectiveHiddenFlag(0, 3);
        }
        if ((getObjectiveBoolean(2) == 1) && (getObjectiveBoolean(8) == 0)) {
            setObjectiveBoolean(0x16, 1U);
            setObjectiveBoolean(0x3B, 1U);
            setObjectiveHiddenFlag(0, 3);
        }
        if ((getObjectiveBoolean(3) == 1) && (getObjectiveBoolean(9) == 0)) {
            setObjectiveBoolean(0x17, 1U);
            setObjectiveBoolean(0x3B, 1U);
            setObjectiveHiddenFlag(0, 3);
        }
    }
    if ((getObjectiveBoolean(0x3C) == 0) && (getObjectiveTimer(2) >= 60.0f)) {
        if (getObjectiveBoolean(1) == 1) {
            setObjectiveBoolean(0xB, 1U);
            setObjectiveBoolean(0x3C, 1U);
        }
        if (getObjectiveBoolean(2) == 1) {
            setObjectiveBoolean(0xC, 1U);
            setObjectiveBoolean(0x3C, 1U);
        }
        if (getObjectiveBoolean(3) == 1) {
            setObjectiveBoolean(0xD, 1U);
            setObjectiveBoolean(0x3C, 1U);
        }
    }
    temp_v0_4 = getObjectiveBoolean(0x63);
    if (temp_v0_4 == 1) {
        temp_v0_5 = getObjectiveBoolean(1);
        if ((temp_v0_5 == temp_v0_4) && (D_mission_overlay_8010B6C4 == 0)) {
            D_mission_overlay_8010B6C4 = temp_v0_5;
            setHudFlagBit40AndStoreArg("Camera_01");
            activateObjectiveCompleteFlag(2);
            setObjectiveBooleans(&D_mission_overlay_8010B6C0, 0);
            delegateToLevelStageTick(string0_lv_2, 0);
        }
    }
    temp_v0_6 = getObjectiveBoolean(0x63);
    if (temp_v0_6 == 1) {
        temp_v0_7 = getObjectiveBoolean(2);
        if ((temp_v0_7 == temp_v0_6) && (D_mission_overlay_8010B6C8 == 0)) {
            D_mission_overlay_8010B6C8 = temp_v0_7;
            setHudFlagBit40AndStoreArg("Camera_02");
            activateObjectiveCompleteFlag(2);
            setObjectiveBooleans(&D_mission_overlay_8010B6C0, 0);
            delegateToLevelStageTick(string0_lv_2, 0);
        }
    }
    temp_v0_8 = getObjectiveBoolean(0x63);
    if (temp_v0_8 == 1) {
        temp_v0_9 = getObjectiveBoolean(3);
        if ((temp_v0_9 == temp_v0_8) && (D_mission_overlay_8010B6CC == 0)) {
            D_mission_overlay_8010B6CC = temp_v0_9;
            setHudFlagBit40AndStoreArg("Camera_03");
            activateObjectiveCompleteFlag(2);
            setObjectiveBooleans(&D_mission_overlay_8010B6C0, 0);
            delegateToLevelStageTick(string0_lv_2, 0);
        }
    }
    if (getObjectiveBoolean(0x1F) == 0) {
        temp_v0_10 = getObjectiveBoolean(1);
        if (temp_v0_10 == 1) {
            temp_v0_11 = getObjectiveBoolean(4);
            if ((temp_v0_11 == temp_v0_10) && (getObjectiveBoolean(0x63) == temp_v0_11)) {
                setObjectiveTimer(1, 0.0f);
                setObjectiveTimer(2, 0.0f);
                setObjectiveBoolean(0x1F, 1U);
            }
        }
    }
    if ((getObjectiveBoolean(4) == 1) && (getObjectiveBoolean(0x66) == 0)) {
        setObjectiveBoolean(0x66, 1U);
        activateObjectiveCompleteFlag(1);
    }
    if (getObjectiveBoolean(0x1F) == 0) {
        temp_v0_12 = getObjectiveBoolean(2);
        if (temp_v0_12 == 1) {
            temp_v0_13 = getObjectiveBoolean(5);
            if ((temp_v0_13 == temp_v0_12) && (getObjectiveBoolean(0x63) == temp_v0_13)) {
                setObjectiveTimer(1, 0.0f);
                setObjectiveTimer(2, 0.0f);
                setObjectiveBoolean(0x1F, 1U);
            }
        }
    }
    if ((getObjectiveBoolean(5) == 1) && (getObjectiveBoolean(0x66) == 0)) {
        setObjectiveBoolean(0x66, 1U);
        activateObjectiveCompleteFlag(1);
    }
    if (getObjectiveBoolean(0x1F) == 0) {
        temp_v0_14 = getObjectiveBoolean(3);
        if (temp_v0_14 == 1) {
            temp_v0_15 = getObjectiveBoolean(6);
            if ((temp_v0_15 == temp_v0_14) && (getObjectiveBoolean(0x63) == temp_v0_15)) {
                setObjectiveTimer(1, 0.0f);
                setObjectiveTimer(2, 0.0f);
                setObjectiveBoolean(0x1F, 1U);
            }
        }
    }
    if ((getObjectiveBoolean(6) == 1) && (getObjectiveBoolean(0x66) == 0)) {
        setObjectiveBoolean(0x66, 1U);
        activateObjectiveCompleteFlag(1);
    }
    temp_v0_16 = getObjectiveBoolean(0x1F);
    if (temp_v0_16 == 1) {
        temp_v0_17 = getObjectiveBoolean(0x20);
        if (temp_v0_17 == temp_v0_16) {
            temp_v0_18 = getObjectiveBoolean(0x21);
            if ((temp_v0_18 == temp_v0_17) && (getObjectiveBoolean(0x63) == temp_v0_18)) {
                setHudEnableBit8();
            }
        }
    }
    return 0;
}

void func_mission_overlay_801026CC(void) {
    playObjectiveVoiceLine2(0xA4U, 0.0f);
}

void func_mission_overlay_801026EC(void) {
    playObjectiveVoiceLine2(0x139U, 0.0f);
}

void func_mission_overlay_8010270C(void) {
    playObjectiveVoiceLine2(0x139U, 0.0f);
}

void func_mission_overlay_8010272C(void) {
    playObjectiveVoiceLine2(0x139U, 0.0f);
}

void func_mission_overlay_8010274C(void) {
    playObjectiveVoiceLine2(0x1F5U, 0.0f);
}

void func_mission_overlay_8010276C(void) {
    playObjectiveVoiceLine2(0x1F5U, 0.0f);
}

void func_mission_overlay_8010278C(void) {
    playObjectiveVoiceLine2(0x1F5U, 0.0f);
}

void func_mission_overlay_801027AC(void) {
    playObjectiveVoiceLine2(0x138U, 0.0f);
    playObjectiveVoiceLine2(0x1EFU, 0.0f);
    playObjectiveVoiceLine2(0x10DU, 1.0f);
}

void func_mission_overlay_801027F0(void) {
    playObjectiveVoiceLine2(0x138U, 0.0f);
    playObjectiveVoiceLine2(0x1EFU, 0.0f);
    playObjectiveVoiceLine2(0x10DU, 1.0f);
}

void func_mission_overlay_80102834(void) {
    playObjectiveVoiceLine2(0x138U, 0.0f);
    playObjectiveVoiceLine2(0x1EFU, 0.0f);
    playObjectiveVoiceLine2(0x10DU, 1.0f);
}

void func_mission_overlay_80102878(void) {
    playObjectiveVoiceLine2(0x53U, 3.0f);
    playObjectiveVoiceLine2(0x25U, 0.5f);
    setObjectiveBoolean(0x6E, 1U);
}

void func_mission_overlay_801028B0(void) {
    playObjectiveVoiceLine2(0x53U, 0.0f);
    playObjectiveVoiceLine2(0x25U, 0.0f);
    setObjectiveBoolean(0x6F, 1U);
}

void func_mission_overlay_801028F4(void) {
    playObjectiveVoiceLine2(0x53U, 0.0f);
    playObjectiveVoiceLine2(0x25U, 0.0f);
    setObjectiveBoolean(0x70, 1U);
}

void func_mission_overlay_80102938(void) {
    addTimerHandleWrapper(func_mission_overlay_8010295C, 1.5f);
}

void func_mission_overlay_8010295C(void) {
    playObjectiveVoiceLine2(0x11DU, 0.0f);
    playObjectiveVoiceLine2(0x1E3U, 0.5f);
    setHudFlagBit40AndStoreArg("Camera_04");
    triggerSoundCueByType(3);
}

void func_mission_overlay_8010299C(void) {
    addTimerHandleWrapper(func_mission_overlay_801029C0, 1.5f);
}

void func_mission_overlay_801029C0(void) {
    playObjectiveVoiceLine2(0x11DU, 0.0f);
    playObjectiveVoiceLine2(0x1E3U, 0.5f);
    setHudFlagBit40AndStoreArg("Camera_05");
    triggerSoundCueByType(3);
}

void func_mission_overlay_80102A00(void) {
    addTimerHandleWrapper(func_mission_overlay_80102A24, 1.5f);
}

// There's a bunch of padding junk in the ROM after this string,
// but we can't just dump it in the function like normal because the compiler will
// append another `\0` to the end. But this string is already aligned to the 16 byte
// boundary, so that extra `\0` pushes it over limit and now there needs to be another
// 15 bytes of padding that shoves everything out of place
// So instead we have to pull some shenanigans to make things play nice
// If matching isn't a concern, see the comment in `func_mission_overlay_80102A24`
const u8 padded_string_lv_2[12] = {
    "Camera_06\x00\x00\x24"
};

void func_mission_overlay_80102A24(void) {
    playObjectiveVoiceLine2(0x11DU, 0.0f);
    playObjectiveVoiceLine2(0x1E3U, 0.5f);
    setHudFlagBit40AndStoreArg(padded_string_lv_2);
    // If matching isn't a concern, use this instead of the call above
    // func_mission_overlay_800C7884("Camera_06");
    triggerSoundCueByType(3);
}

s32 lv2_80102A64(void) {
    return 0;
}

s32 lv2_calculateFriendliesSaved(void) {
    setFriendliesSaved(1 - getObjectiveCount(0x28));
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/mission_overlay/level_objective_handling/lv_2", fake_func_80102A98);
