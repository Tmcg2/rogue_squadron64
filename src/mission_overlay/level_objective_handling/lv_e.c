#include "common.h"

#include "mission_overlay/0C7EB0.h"
#include "mission_overlay/0C84A0.h"
#include "mission_overlay/level_objective_handling/lv_e.h"

s32 D_mission_overlay_8010D160;
s32 D_mission_overlay_8010D164;
s32 D_mission_overlay_8010D168;
s32 D_mission_overlay_8010D16C;
s32 D_mission_overlay_8010D170;
s32 D_mission_overlay_8010D174;
s32 D_mission_overlay_8010D178;
s32 D_mission_overlay_8010D17C;
s32 D_mission_overlay_8010D180;
s32 D_mission_overlay_8010D184;
s32 D_mission_overlay_8010D188;
s32 D_mission_overlay_8010D18C;
s32 D_mission_overlay_8010D190;
s32 D_mission_overlay_8010D194;
s32 D_mission_overlay_8010D198;

s32 lve_initializeObjectTracking(void) {
    D_mission_overlay_8010D160 = 0;
    D_mission_overlay_8010D164 = 0;
    D_mission_overlay_8010D168 = 0;
    D_mission_overlay_8010D16C = 0;
    D_mission_overlay_8010D170 = 0;
    D_mission_overlay_8010D174 = 0;
    D_mission_overlay_8010D178 = 0;
    D_mission_overlay_8010D17C = 0;
    D_mission_overlay_8010D180 = 0;
    D_mission_overlay_8010D184 = 0;
    D_mission_overlay_8010D188 = 0;
    D_mission_overlay_8010D18C = 0;
    D_mission_overlay_8010D190 = 0;
    D_mission_overlay_8010D194 = 0;
    D_mission_overlay_8010D198 = 0;
    setObjectiveBoolean(0x15, 1U);
    setObjectiveBoolean(0x16, 1U);
    setObjectiveBoolean(0x17, 1U);
    setObjectiveBoolean(0x18, 1U);
    setObjectiveBoolean(0x1C, 1U);
    setObjectiveBoolean(0x1D, 1U);
    setObjectiveBoolean(0x20, 1U);
    setObjectiveBoolean(0x21, 1U);
    setObjectiveBoolean(0x23, 1U);
    setObjectiveBoolean(0x24, 1U);
    setObjectiveBoolean(0x25, 1U);
    setObjectiveBoolean(0x28, 1U);
    setObjectiveBoolean(0x29, 1U);
    setObjectiveBoolean(0x2A, 1U);
    setObjectiveBoolean(0x2C, 1U);
    setObjectiveBoolean(0x2D, 1U);
    setObjectiveBoolean(0x2E, 1U);
    setObjectiveBoolean(0x2F, 1U);
    setObjectiveBoolean(0x30, 1U);
    setObjectiveBoolean(0x31, 1U);
    setObjectiveBoolean(0x32, 1U);
    setObjectiveBoolean(0x56, 1U);
    setObjectiveBoolean(0x57, 1U);
    setObjectiveBoolean(0x58, 1U);
    setObjectiveBoolean(0x59, 1U);
    setObjectiveBoolean(0x5A, 1U);
    setObjectiveBoolean(0x5B, 1U);
    setObjectiveBoolean(0x5C, 1U);
    setObjectiveBoolean(0x5D, 1U);
    setObjectiveTimer(7, 4.0f);
    func_mission_overlay_800C7CEC(7.5f);
    return 0;
}

s32 lve_checkComplexObjectives(void) {
    f32 temp_fs0;
    f32 var_a1;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 temp_v0_4;
    s32 temp_v0_5;
    u32 var_a0;

    if (getObjectiveCount(0x1F) >= 5) {
        func_mission_overlay_800C7738();
        playObjectiveVoiceLine2(0x17C, 0.3f);
        return 0;
    }
    if (getObjectiveCount(0x1E) >= 0xD) {
        func_mission_overlay_800C7738();
        playObjectiveVoiceLine2(0x17D, 0.3f);
        return 0;
    }
    if (getObjectiveBoolean(0x66) == 1) {
        activateObjectiveCompleteFlag(4);
        func_mission_overlay_800C776C();
        playObjectiveVoiceLine2(0x1E1, 0.3f);
        return 0;
    }
    if ((getObjectiveCount(0xA) >= 0x1A) && (getObjectiveCount(0x1D) >= 0xE) && (D_mission_overlay_8010D198 == 0)) {
        D_mission_overlay_8010D198 = 1;
        activateObjectiveCompleteFlag(3);
    }
    if ((getObjectiveCount(0xA) >= 0x1A) && (getObjectiveBoolean(0x1A) == 0)) {
        setObjectiveBoolean(0x1A, 1U);
    }
    temp_v0 = getObjectiveBoolean(0x1A);
    if (temp_v0 == 1) {
        if ((getObjectiveBoolean(0x6C) == temp_v0) && (getObjectiveBoolean(0x33) == 0)) {
            setObjectiveBoolean(0x33, 1U);
        }
        if ((getObjectiveBoolean(0xD) == 1) && (getObjectiveBoolean(0x34) == 0)) {
            setObjectiveBoolean(0x34, 1U);
        }
        if ((getObjectiveBoolean(0x10) == 1) && (getObjectiveBoolean(0x35) == 0)) {
            setObjectiveBoolean(0x35, 1U);
        }
        if ((getObjectiveBoolean(0x13) == 1) && (getObjectiveBoolean(0x36) == 0)) {
            setObjectiveBoolean(0x36, 1U);
        }
    }
    temp_v0_2 = getObjectiveBoolean(1);
    if ((temp_v0_2 == 1) && (getObjectiveBoolean(2) == temp_v0_2) && (getObjectiveBoolean(0x43) == 0)) {
        setObjectiveBoolean(0x43, 1U);
    }
    temp_v0_3 = getObjectiveBoolean(3);
    if ((temp_v0_3 == 1) && (getObjectiveBoolean(0x55) == temp_v0_3) && (getObjectiveBoolean(0x44) == 0)) {
        setObjectiveBoolean(0x44, 1U);
    }
    if ((getObjectiveBoolean(4) == 1) && (getObjectiveBoolean(0x45) == 0)) {
        setObjectiveBoolean(0x45, 1U);
    }
    if ((getObjectiveCount(4) == 2) && (getObjectiveBoolean(0x46) == 0)) {
        setObjectiveBoolean(0x46, 1U);
    }
    if ((getObjectiveCount(5) == 2) && (getObjectiveBoolean(0x47) == 0)) {
        setObjectiveBoolean(0x47, 1U);
    }
    if ((getObjectiveCount(6) == 1) && (getObjectiveBoolean(0x48) == 0)) {
        setObjectiveBoolean(0x48, 1U);
    }
    if ((getObjectiveCount(7) == 5) && (getObjectiveBoolean(0x49) == 0)) {
        setObjectiveBoolean(0x49, 1U);
    }
    if ((getObjectiveCount(8) == 1) && (getObjectiveBoolean(0x4A) == 0)) {
        setObjectiveBoolean(0x4A, 1U);
    }
    if ((getObjectiveCount(9) == 1) && (getObjectiveBoolean(0x4B) == 0)) {
        setObjectiveBoolean(0x4B, 1U);
    }
    if ((getObjectiveCount(0xB) == 6) && (getObjectiveBoolean(0x4C) == 0)) {
        setObjectiveBoolean(0x4C, 1U);
    }
    if ((getObjectiveCount(0xC) == 2) && (getObjectiveBoolean(0x4D) == 0)) {
        setObjectiveBoolean(0x4D, 1U);
    }
    if ((getObjectiveCount(0xD) == 1) && (getObjectiveBoolean(0x4E) == 0)) {
        setObjectiveBoolean(0x4E, 1U);
    }
    if ((getObjectiveCount(0xE) == 3) && (getObjectiveBoolean(0x4F) == 0)) {
        setObjectiveBoolean(0x4F, 1U);
    }
    if ((D_mission_overlay_8010D160 == 1) && (getObjectiveTimer(7) >= 6.0f)) {
        D_mission_overlay_8010D160 = 0;
    }
    if (D_mission_overlay_8010D160 == 0) {
        if (D_mission_overlay_8010D164 == 0) {
            D_mission_overlay_8010D164 = 1;
            D_mission_overlay_8010D160 = 1;
            setObjectiveTimer(7, 4.0f);
            playObjectiveVoiceLine2(0x100, 0.3f);
            return 0;
        }
        temp_v0_4 = getObjectiveBoolean(0xF);
        if ((temp_v0_4 == 1) && (D_mission_overlay_8010D168 == 0)) {
            D_mission_overlay_8010D168 = temp_v0_4;
            D_mission_overlay_8010D160 = temp_v0_4;
            setObjectiveTimer(7, 3.0f);
            playObjectiveVoiceLine2(0x29B, 0.3f);
            return 0;
        }
        if ((getObjectiveCount(0x1E) == 2) && (D_mission_overlay_8010D16C == 0)) {
            D_mission_overlay_8010D16C = 1;
            D_mission_overlay_8010D160 = 1;
            setObjectiveTimer(7, 0.0f);
            playObjectiveVoiceLine2(0x2AA, 0.3f);
            return 0;
        }
        if ((getObjectiveCount(0x1E) == 7) && (D_mission_overlay_8010D170 == 0)) {
            D_mission_overlay_8010D170 = 1;
            D_mission_overlay_8010D160 = 1;
            setObjectiveTimer(7, 0.0f);
            playObjectiveVoiceLine2(0x2A9, 0.3f);
            return 0;
        }
        if ((getObjectiveCount(0x1E) == 0xA) && (D_mission_overlay_8010D174 == 0)) {
            D_mission_overlay_8010D174 = 1;
            D_mission_overlay_8010D160 = 1;
            setObjectiveTimer(7, 0.0f);
            playObjectiveVoiceLine2(0x2A8, 0.3f);
            return 0;
        }
        if ((getObjectiveCount(0x1F) >= 2) && (D_mission_overlay_8010D178 == 0)) {
            D_mission_overlay_8010D178 = 1;
            D_mission_overlay_8010D160 = 1;
            setObjectiveTimer(7, 0.0f);
            playObjectiveVoiceLine2(0x179, 0.3f);
            return 0;
        }
        if ((getObjectiveCount(0xA) >= 0x1A) && (getObjectiveCount(0x1D) >= 0xE) && (getObjectiveCount(0x14) >= 4) && (getObjectiveBoolean(0x65) == 0) && (D_mission_overlay_8010D17C == 0)) {
            D_mission_overlay_8010D17C = 1;
            D_mission_overlay_8010D160 = 1;
            activateObjectiveCompleteFlag(1);
            activateObjectiveCompleteFlag(2);
            setObjectiveBoolean(0x65, 1U);
            func_mission_overlay_800C7884("MOFF_SEERDON_CAMERA");
            setObjectiveTimer(7, 0.0f);
            playObjectiveVoiceLine2(0x1D7U, 0.3f);
            func_mission_overlay_800C7D98(4);
            func_mission_overlay_800C7D60("MUSICRNG_LevelSettings", 1);
            return 0;
        }
        temp_v0_5 = getObjectiveBoolean(0x65);
        if ((temp_v0_5 == 1) && (D_mission_overlay_8010D180 == 0)) {
            D_mission_overlay_8010D180 = temp_v0_5;
            D_mission_overlay_8010D160 = temp_v0_5;
            setObjectiveTimer(7, 0.0f);
            playObjectiveVoiceLine2(0x17AU, 0.3f);
            playObjectiveVoiceLine2(0x1D8, 0.3f);
        } else {
            if ((getDatItemHealth("MOFF_SEERDON") < 0x3EA) && (D_mission_overlay_8010D184 == 0)) {
                D_mission_overlay_8010D184 = 1;
                D_mission_overlay_8010D160 = 1;
                setObjectiveTimer(7, 0.0f);
                playObjectiveVoiceLine2(0x1D9, 0.3f);
            }
            else if ((getDatItemHealth("MOFF_SEERDON") < 0x322) && (D_mission_overlay_8010D188 == 0)) {
                D_mission_overlay_8010D188 = 1;
                D_mission_overlay_8010D160 = 1;
                setObjectiveTimer(7, 0.0f);
                playObjectiveVoiceLine2(0x1DA, 0.3f);
            }
            else if ((getDatItemHealth("MOFF_SEERDON") < 0x25A) && (D_mission_overlay_8010D18C == 0)) {
                D_mission_overlay_8010D18C = 1;
                D_mission_overlay_8010D160 = 1;
                setObjectiveTimer(7, 0.0f);
                playObjectiveVoiceLine2(0x1DC, 0.3f);
            }
            else if ((getDatItemHealth("MOFF_SEERDON") < 0x192) && (D_mission_overlay_8010D190 == 0)) {
                D_mission_overlay_8010D190 = 1;
                D_mission_overlay_8010D160 = 1;
                setObjectiveTimer(7, 0.0f);
                playObjectiveVoiceLine2(0x1DE, 0.3f);
            }
            else if ((getDatItemHealth("MOFF_SEERDON") < 0xCA) && (D_mission_overlay_8010D194 == 0)) {
                D_mission_overlay_8010D194 = 1;
                D_mission_overlay_8010D160 = 1;
                setObjectiveTimer(7, 0.0f);
                playObjectiveVoiceLine2(0x1DD, 0.3f);
            }
        }
    }
    return 0;
}

s32 lve_80107E58(void) {
    return 0;
}

s32 lve_calculateFriendliesSaved(void) {
    setFriendliesSaved(0x3B - (getObjectiveCount(0x1E) + getObjectiveCount(0x1F)));
    return 0;
}

// DO NOT DELETE ME I AM REQUIRED FOR MATCHING
const u32 rodata_pad_lv_e[] = {
    0x00000000,
    0x45010005,
};

INCLUDE_ASM("asm/nonmatchings/mission_overlay/level_objective_handling/lv_e", fake_func_80107EA4);
