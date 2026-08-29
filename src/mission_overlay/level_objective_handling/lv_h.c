#include "common.h"

#include "mission_overlay/0C7EB0.h"
#include "mission_overlay/0C84A0.h"
#include "mission_overlay/level_objective_handling/lv_h.h"

s32 lvh_initializeObjectTracking(void) {
    func_mission_overlay_800C7CEC(7.5f);
    addBooleanCountHandleWrapper(func_mission_overlay_80108C98, 7, 1, 0, 0);
    addBooleanCountHandleWrapper(func_mission_overlay_80108D1C, 0xF, 1, 0, 0);
    addBooleanCountHandleWrapper(func_mission_overlay_80108D6C, 0x10, 1, 0, 0);
    addBooleanCountHandleWrapper(func_mission_overlay_80108D98, 0x11, 1, 0, 0);
    addBooleanCountHandleWrapper(func_mission_overlay_80108DF0, 0x15, 1, 0, 0);
    addBooleanCountHandleWrapper(func_mission_overlay_80108E10, 0x16, 1, 0, 0);
    addBooleanCountHandleWrapper(func_mission_overlay_80108DC4, 0x17, 1, 0, 0);
    addBooleanCountHandleWrapper(func_mission_overlay_80108E48, 0x18, 1, 0, 0);
    return 0;
}

void func_mission_overlay_80108C98(void) {
    func_mission_overlay_800C7884("Cam_01");
    playObjectiveVoiceLine2(0x8DU, 0.0f);
    playObjectiveVoiceLine2(0x13DU, 0.5f);
    playObjectiveVoiceLine2(1U, 0.0f);
    playObjectiveVoiceLine2(2U, 0.0f);
    playObjectiveVoiceLine2(3U, 0.0f);
    playObjectiveVoiceLine2(0x13FU, 0.0f);
    func_mission_overlay_800C7D60("MUSICRNG_LevelSettings", 1);
}

void func_mission_overlay_80108D1C(void) {
    playObjectiveVoiceLine2(0x2B4U, 0.0f);
    playObjectiveVoiceLine2(0x142U, 0.0f);
    playObjectiveVoiceLine2(0x1E6U, 0.0f);
    playObjectiveVoiceLine2(0x11AU, 0.5f);
}

void func_mission_overlay_80108D6C(void) {
    playObjectiveVoiceLine2(0x93U, 0.0f);
    playObjectiveVoiceLine2(0x96U, 3.5f);
}

void func_mission_overlay_80108D98(void) {
    playObjectiveVoiceLine2(0x1EBU, 0.0f);
    playObjectiveVoiceLine2(0x1ACU, 2.5f);
}

void func_mission_overlay_80108DC4(void) {
    playObjectiveVoiceLine2(0x246U, 0.0f);
    playObjectiveVoiceLine2(0x11AU, 0.5f);
}

void func_mission_overlay_80108DF0(void) {
    playObjectiveVoiceLine2(0x22EU, 8.0f);
}

void func_mission_overlay_80108E10(void) {
    playObjectiveVoiceLine2(0x1F7U, 0.0f);
    playObjectiveVoiceLine2(0x1F3U, 0.0f);
}

void func_mission_overlay_80108E48(void) {
    playObjectiveVoiceLine2(0x219U, 8.0f);
}

s32 lvh_80108E68(void) {
    return 0;
}

s32 lvh_calculateFriendliesSaved(void) {
    setFriendliesSaved(-(getObjectiveCount(0x80) + getObjectiveCount(0x80)));
    return 0;
}

s32 lvh_checkComplexObjectives(void) {
    if (((f64) func_mission_overlay_800C794C() < -0.3) && (getObjectiveBoolean(0x64) == 0)) {
        setObjectiveBoolean(0x64, 1U);
        increaseObjectiveCount(0x65, 1);
        func_mission_overlay_800C7738();
        playObjectiveVoiceLine2(0x2B8U, 0.0f);
        playObjectiveVoiceLine2(0x1F0U, 0.0f);
        return 0;
    }
    if (getObjectiveBoolean(0xA) == 1) {
        func_mission_overlay_800C776C();
    }
    return 0;
}
