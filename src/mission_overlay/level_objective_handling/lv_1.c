#include "common.h"

#include "mission_overlay/0C7EB0.h"
#include "mission_overlay/0C84A0.h"
#include "mission_overlay/level_objective_handling/lv_1.h"

s32 D_mission_overlay_8010B6B0 = 0;
// DO NOT DELTE ME I AM REQUIRED FOR MATCHING
u32 data_pad_lv_1[] = {
    0xC46000E8,
    0xC4820004,
    0x46020002,
};

s32 D_mission_overlay_8010D040;
s32 D_mission_overlay_8010D044;

s32 lv1_initializeObjectTracking(void) {
    D_mission_overlay_8010D040 = 0;
    D_mission_overlay_8010D044 = 0;
    D_mission_overlay_8010B6B0 = 1;
    playObjectiveVoiceLine2(0x2FU, 2.0f);
    playObjectiveVoiceLine2(0x100U, 0.0f);
    addBooleanCountHandleWrapper(func_mission_overlay_80101AD8, 0, 0, 0xD, 2);
    addBooleanCountHandleWrapper(func_mission_overlay_80101B98, 0, 0, 0xD, 3);
    addBooleanCountHandleWrapper(func_mission_overlay_80101AF8, 7, 1, 0, 0);
    addBooleanCountHandleWrapper(func_mission_overlay_80101B34, 0, 0, 0xA, 1);
    addBooleanCountHandleWrapper(func_mission_overlay_80101B54, 0, 0, 0x32, 1);
    addBooleanCountHandleWrapper(func_mission_overlay_80101B74, 5, 1, 0, 0);
    addBooleanCountHandleWrapper(func_mission_overlay_80101BB8, 0xE, 1, 0, 0);
    D_mission_overlay_8010D040 = 0;
    D_mission_overlay_8010D044 = 0;
    return 0;
}

void func_mission_overlay_80101AD8(void) {
    playObjectiveVoiceLine2(0xBU, 0.0f);
}

// There's a bunch of padding junk in the ROM after this string,
// but we can't just dump it in the function like normal because the compiler will
// append another `\0` to the end. But this string is already aligned to the 16 byte
// boundary, so that extra `\0` pushes it over limit and now there needs to be another
// 15 bytes of padding that shoves everything out of place
// So instead we have to pull some shenanigans to make things play nice
// If matching isn't a concern, see the comment in `func_mission_overlay_80101AF8`
const u8 padded_string_lv_1[32] = {
    "MUSICRNG_ConvoyStart\x00\x68\x00\x03\xA8\x48\x00\x00\xB8\x48\x00\x03"
};

void func_mission_overlay_80101AF8(void) {
    playObjectiveVoiceLine2(0x4CU, 0.0f);
    playObjectiveVoiceLine2(0x29CU, 3.0f);
    func_mission_overlay_800C7D60(padded_string_lv_1, 0);
    // If matching isn't a concern, use this instead of the call above
    //func_mission_overlay_800C7D60("MUSICRNG_ConvoyStart", 0);
}

void func_mission_overlay_80101B34(void) {
    playObjectiveVoiceLine2(0x21CU, 1.0f);
}

void func_mission_overlay_80101B54(void) {
    playObjectiveVoiceLine2(0x4DU, 0.5f);
}

void func_mission_overlay_80101B74(void) {
    playObjectiveVoiceLine2(0x1F8U, 0.3f);
}

void func_mission_overlay_80101B98(void) {
    playObjectiveVoiceLine2(0x22CU, 0.5f);
}

void func_mission_overlay_80101BB8(void) {
    playObjectiveVoiceLine2(0x21CU, 0.0f);
    playObjectiveVoiceLine2(0x4DU, 2.0f);
}

s32 lv1_80101BE4(void) {
    return 0;
}

s32 lv1_calculateFriendliesSaved(void) {
    setFriendliesSaved(0x13 - (getObjectiveCount(0x28) + getObjectiveCount(0xD) + getObjectiveCount(0x29)));
    return 0;
}

s32 lv1_checkComplexObjectives(void) {
    s32 temp_v0;

    if (D_mission_overlay_8010D040 == 0) {
        if (getObjectiveCount(0xD) >= 5) {
            func_mission_overlay_800C7738();
            playObjectiveVoiceLine2(0x50U, 1.0f);
            D_mission_overlay_8010D040 = 1;
        }
        temp_v0 = getObjectiveBoolean(6);
        if (temp_v0 == 1) {
            D_mission_overlay_8010D040 = temp_v0;
            func_mission_overlay_800C776C();
            activateObjectiveCompleteFlag(1);
        }
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/mission_overlay/level_objective_handling/lv_1", fake_func_80101CCC);
