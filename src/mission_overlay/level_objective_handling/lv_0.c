#include "common.h"

#include "mission_overlay/0C7EB0.h"
#include "mission_overlay/0C84A0.h"
#include "mission_overlay/level_objective_handling/lv_0.h"

s32 D_mission_overlay_8010B690 = 0;
s32 D_mission_overlay_8010B694 = 0;
s32 D_mission_overlay_8010B698 = 0;
s32 D_mission_overlay_8010B69C = 0;
s32 D_mission_overlay_8010B6A0 = 0;
s32 D_mission_overlay_8010B6A4 = 0;
s32 D_mission_overlay_8010B6A8 = 0;
// DO NOT DELTE ME I AM REQUIRED FOR MATCHING
u32 data_pad_lv_0 = 0x8FC50050;

s32 lv0_initializeObjectTracking(void) {
    D_mission_overlay_8010B690 = 0;
    D_mission_overlay_8010B694 = 0;
    D_mission_overlay_8010B698 = 0;
    D_mission_overlay_8010B69C = 0;
    D_mission_overlay_8010B6A0 = 0;
    D_mission_overlay_8010B6A4 = 0;
    D_mission_overlay_8010B6A8 = 0;
    setObjectiveBoolean(0x61, 1U);
    setObjectiveBoolean(0x62, 1U);
    setObjectiveBoolean(5, 1U);
    addBooleanCountHandleWrapper(func_mission_overlay_80101934, 0, 0, 1, 0x15);
    addBooleanCountHandleWrapper(func_mission_overlay_801018EC, 0, 0, 0x14, 1);
    func_mission_overlay_800C7CEC(7.5f);
    setObjectiveBoolean(0x3C, 1U);
    setObjectiveTimer(2, 0.0f);
    setObjectiveHiddenFlag(1, 1);
    setObjectiveHiddenFlag(1, 2);
    setObjectiveHiddenFlag(1, 3);
    setObjectiveHiddenFlag(1, 4);
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/mission_overlay/level_objective_handling/lv_0", lv0_checkComplexObjectives);

void func_mission_overlay_801018EC(void) {
    playObjectiveVoiceLine2(0x26E, 0.3f);
    playObjectiveVoiceLine2(0x148, 0.3f);
    playObjectiveVoiceLine2(0x270, 0.3f);
}


void func_mission_overlay_80101934(void) {
    setObjectiveCount(0x73, 6U);
}

s32 lv0_80101954(void) {
    return 0;
}

s32 lv0_calculateFriendliesSaved(void) {
    setFriendliesSaved(0x33 - (getObjectiveCount(2) + getObjectiveCount(3)));
    return 0;
}

// DO NOT DELTE ME I AM REQUIRED FOR MATCHING
const u32 rodata_pad_lv_0[] = {
    0xA8480000,
    0xB8480003,
};
