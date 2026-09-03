#include "common.h"

#include "mission_overlay/0C7EB0.h"
#include "mission_overlay/0C84A0.h"
#include "mission_overlay/level_objective_handling/lv_7.h"

s32 D_mission_overlay_8010D090;
s32 D_mission_overlay_8010D094;
s32 D_mission_overlay_8010D098;
s32 D_mission_overlay_8010D09C;
s32 D_mission_overlay_8010D0A0;

s32 lv7_checkComplexObjectives(void) {
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 temp_v0_4;
    s32 temp_v0_5;
    s32 temp_v0_6;
    s32 temp_v0_7;
    s32 temp_v0_8;
    s32 temp_v0_9;

    temp_v0 = getObjectiveBoolean(0x61);
    if ((temp_v0 == 1) && (getObjectiveBoolean(0x62) == 0) && (getObjectiveBoolean(0x63) == 0) && (D_mission_overlay_8010D098 == 0)) {
        D_mission_overlay_8010D098 = temp_v0;
        setHudFlagBit40AndStoreArg("cam_2");
        setObjectiveBoolean(0x3D, 1U);
        playObjectiveVoiceLine2(0x8AU, 0.5f);
        playObjectiveVoiceLine2(0x11AU, 0.5f);
    }
    if (getObjectiveBoolean(0x61) == 0) {
        temp_v0_2 = getObjectiveBoolean(0x62);
        if ((temp_v0_2 == 1) && (getObjectiveBoolean(0x63) == 0) && (D_mission_overlay_8010D090 == 0)) {
            D_mission_overlay_8010D090 = temp_v0_2;
            setHudFlagBit40AndStoreArg("cam_1");
            setObjectiveBoolean(0x40, 1U);
            playObjectiveVoiceLine2(0x2A6U, 0.5f);
            playObjectiveVoiceLine2(0x8BU, 3.0f);
        }
    }
    if ((getObjectiveBoolean(0x61) == 0) && (getObjectiveBoolean(0x62) == 0)) {
        temp_v0_3 = getObjectiveBoolean(0x63);
        if ((temp_v0_3 == 1) && (D_mission_overlay_8010D094 == 0)) {
            D_mission_overlay_8010D094 = temp_v0_3;
            setHudFlagBit40AndStoreArg("cam_1c");
            setObjectiveBoolean(0x43, 1U);
            playObjectiveVoiceLine2(0x2A6U, 0.5f);
            playObjectiveVoiceLine2(0x8AU, 3.0f);
        }
    }
    if ((getObjectiveCount(0x14) >= 0x15) && (getObjectiveBoolean(0x61) == 0)) {
        setObjectiveBoolean(0x61, 1U);
        increaseObjectiveCount(0x63, 1);
        activateObjectiveCompleteFlag(2);
        setObjectiveBoolean(0x78, 1U);
    }
    if ((getObjectiveCount(0x1E) >= 0xA) && (getObjectiveBoolean(0x62) == 0)) {
        setObjectiveBoolean(0x62, 1U);
        increaseObjectiveCount(0x63, 1);
        activateObjectiveCompleteFlag(1);
        setObjectiveBoolean(0x79, 1U);
    }
    if ((getObjectiveCount(0x28) >= 6) && (getObjectiveBoolean(0x63) == 0)) {
        setObjectiveBoolean(0x63, 1U);
        increaseObjectiveCount(0x63, 1);
        activateObjectiveCompleteFlag(3);
        setObjectiveBoolean(0x7A, 1U);
    }
    if ((getObjectiveCount(0x28) >= 6) && (getObjectiveCount(0x1E) >= 0xA) && (getObjectiveBoolean(0x6A) == 0) && (D_mission_overlay_8010D09C == 0)) {
        D_mission_overlay_8010D09C = 1;
        setObjectiveBoolean(0x29, 1U);
        setHudFlagBit40AndStoreArg("Camera_Shuttle_01");
        triggerSoundCueByType(3);
    }
    if (getObjectiveCount(0x14) == 0x13) {
        temp_v0_4 = getObjectiveBoolean(0x62);
        if (temp_v0_4 == 1) {
            temp_v0_5 = getObjectiveBoolean(0x63);
            if ((temp_v0_5 == temp_v0_4) && (D_mission_overlay_8010D0A0 == 0)) {
                D_mission_overlay_8010D0A0 = temp_v0_5;
                setObjectiveBoolean(0x32, 1U);
                setHudFlagBit40AndStoreArg("Wedge_Cam_1");
                playObjectiveVoiceLine2(0x23DU, 0.0f);
                playObjectiveVoiceLine2(0x155U, 0.5f);
                playObjectiveVoiceLine2(0x89U, 0.0f);
                playObjectiveVoiceLine2(0x103U, 0.0f);
                playObjectiveVoiceLine2(0x156U, 0.5f);
                playObjectiveVoiceLine2(0x149U, 0.5f);
            }
        }
    }
    temp_v0_6 = getObjectiveBoolean(0x61);
    if ((temp_v0_6 == 1) && (getObjectiveCount(0x1E) == 8)) {
        temp_v0_7 = getObjectiveBoolean(0x63);
        if ((temp_v0_7 == temp_v0_6) && (D_mission_overlay_8010D0A0 == 0)) {
            D_mission_overlay_8010D0A0 = temp_v0_7;
            setObjectiveBoolean(0x32, 1U);
            setHudFlagBit40AndStoreArg("Wedge_Cam_1");
            playObjectiveVoiceLine2(0x23DU, 0.0f);
            playObjectiveVoiceLine2(0x155U, 0.5f);
            playObjectiveVoiceLine2(0x89U, 0.0f);
            playObjectiveVoiceLine2(0x103U, 0.0f);
            playObjectiveVoiceLine2(0x156U, 0.5f);
            playObjectiveVoiceLine2(0x149U, 0.5f);
        }
    }
    temp_v0_8 = getObjectiveBoolean(0x61);
    if (temp_v0_8 == 1) {
        temp_v0_9 = getObjectiveBoolean(0x62);
        if ((temp_v0_9 == temp_v0_8) && (getObjectiveCount(0x28) == 4) && (D_mission_overlay_8010D0A0 == 0)) {
            D_mission_overlay_8010D0A0 = temp_v0_9;
            setObjectiveBoolean(0x32, 1U);
            setHudFlagBit40AndStoreArg("Wedge_Cam_1");
            playObjectiveVoiceLine2(0x23DU, 0.0f);
            playObjectiveVoiceLine2(0x155U, 0.5f);
            playObjectiveVoiceLine2(0x89U, 0.0f);
            playObjectiveVoiceLine2(0x103U, 0.0f);
            playObjectiveVoiceLine2(0x156U, 0.5f);
            playObjectiveVoiceLine2(0x149U, 0.5f);
        }
    }
    if (getObjectiveCount(0x63) >= 3) {
        setHudEnableBit8();
    }
    return 0;
}

s32 lv7_initializeObjectTracking(void) {
    D_mission_overlay_8010D090 = 0;
    D_mission_overlay_8010D094 = 0;
    D_mission_overlay_8010D098 = 0;
    D_mission_overlay_8010D09C = 0;
    D_mission_overlay_8010D0A0 = 0;
    setLevelObjectTrackingScalar(7.5f);
    return 0;
}

s32 lv7_80104A58(void) {
    return 0;
}

s32 lv7_calculateFriendliesSaved(void) {
    setFriendliesSaved(-(getObjectiveCount(0x80) + getObjectiveCount(0x80)));
    return 0;
}
