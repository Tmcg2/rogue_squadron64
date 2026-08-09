#include "common.h"
#include "levels.h"
#include "main/64EA0.h"
#include "menu_overlay/1331E0.h"

struct game_medal_info   D_menu_overlay_800D03D0;
struct asset_medal_info *medalInfo;

void loadMedalInfo(void) {
    medalInfo = load_asset("medal_info");
}

u8 getMissionMedal(u8 levelId, struct mission_stats *stats) {
    u8 var_v0;
    s32 blah;
    struct asset_medal_info *temp_v1_2;

    if (levelId == LEVEL_BEGGARS_CANYON) return stats->friendlies_saved; 

    for (blah = GOLD; blah > NO_MEDAL; blah--) {
        var_v0 = blah;
        temp_v1_2 = &medalInfo[levelId*3 + var_v0 - 1];
        D_menu_overlay_800D03D0.completion_time = temp_v1_2->completion_time * 60.0f;
        D_menu_overlay_800D03D0.enemies_destroyed = temp_v1_2->enemies_destroyed;
        D_menu_overlay_800D03D0.accuracy = temp_v1_2->accuracy;
        D_menu_overlay_800D03D0.friendlies_saved = temp_v1_2->friendlies_saved;
        D_menu_overlay_800D03D0.bonus_collected = temp_v1_2->bonus_collected;
        if (compareStatstoMedalInfo(&D_menu_overlay_800D03D0, stats) == 0x1F) break;
    }
    return blah;
}

u8 calculatePlayerRank(u8 *medalsPerLevel) {
    u8 levelId;
    u8 var_a2;
    u8 temp_v0;

    /*
    Bronze medals are worth 1 point, Silvers 2 points, and Golds 4 points.
    And, obviously, no medal at all is worth 0 points.
    Rank is calculated by dividing points by 4, so each Gold medal guarantees a rank increase
    */
    var_a2 = 0;
    for (levelId = 0; levelId < NUM_LEVELS; levelId++) {
        if (medalsPerLevel[levelId] != NO_MEDAL) {
            var_a2 += 1 << (medalsPerLevel[levelId] - 1);
        }
    }
    var_a2 /= 4;
    if (var_a2 > SUPREME_ALLIED_COMMANDER) {
        var_a2 = SUPREME_ALLIED_COMMANDER;
    }
    return var_a2;
}

struct game_medal_info *getMedalInfo(u8 levelId, u8 medalType) {
    struct asset_medal_info *temp_a0;

    // I really, REALLY, do not like this array access
    temp_a0 = &medalInfo[levelId*3 + medalType - 1];
    D_menu_overlay_800D03D0.completion_time = temp_a0->completion_time * 60.0f;
    D_menu_overlay_800D03D0.enemies_destroyed = temp_a0->enemies_destroyed;
    D_menu_overlay_800D03D0.accuracy = temp_a0->accuracy;
    D_menu_overlay_800D03D0.friendlies_saved = temp_a0->friendlies_saved;
    D_menu_overlay_800D03D0.bonus_collected = temp_a0->bonus_collected;
    return &D_menu_overlay_800D03D0;
}

u8 compareStatstoMedalInfo(struct game_medal_info *medal, struct mission_stats *stats) {
    u8 statFlags;
    u8 accuracy;
    s32 why; //???

    if (stats->shots_fired != 0) {
        accuracy = (stats->shots_landed * 0x64) / stats->shots_fired;
        if (accuracy > 0x64) {
            accuracy = 0x64;
        }
        statFlags = 0x1F;
    } else {
        accuracy = 0;
        statFlags = 0x1F;
    }
    why = accuracy;
    if (stats->completion_time > medal->completion_time) {
        statFlags = 0x1E;
    }
    if (stats->enemies_destroyed < medal->enemies_destroyed) {
        statFlags &= ~0x2;
    }
    if ((u8)why < medal->accuracy) {
        statFlags &= ~0x4;
    }
    if (stats->friendlies_saved < medal->friendlies_saved) {
        statFlags &= ~0x8;
    }
    if (stats->bonus_collected < medal->bonus_collected) {
        statFlags &= ~0x10;
    }
    return statFlags;
}

u8 calculateShotAccuracy(struct mission_stats *stats) {
    u8 accuracy;

    if (stats->shots_fired != 0) {
        accuracy = (stats->shots_landed * 0x64) / stats->shots_fired;
        if (accuracy > 0x64) {
            accuracy = 0x64;
        }
    } else {
        accuracy = 0;
    }
    return accuracy;
}

INCLUDE_ASM("asm/nonmatchings/menu_overlay/1331E0", fake_func_800CC3D4);

// DO NOT DELETE ME, I am necessary for matching
static const u32 datajunk = 0x8FC200C0;
