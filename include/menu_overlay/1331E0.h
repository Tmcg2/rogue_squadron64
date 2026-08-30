#ifndef MENU_1331E0_H
#define MENU_1331E0_H

#include "PR/ultratypes.h"
#include "mission_stats.h"

void loadMedalInfo(void);
u8 getMissionMedal(u8 levelId, struct mission_stats *stats);
u8 calculatePlayerRank(u8*);
struct game_medal_info *getMedalInfo(u8, u8);
u8 compareStatstoMedalInfo(struct game_medal_info*, struct mission_stats*);
u8 calculateShotAccuracy(struct mission_stats*);

#endif