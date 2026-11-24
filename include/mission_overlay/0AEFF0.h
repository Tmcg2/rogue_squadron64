#ifndef MISSION_0AEFF0_H
#define MISSION_0AEFF0_H

#include "PR/ultratypes.h"

#include "player.h"

void populateCutsceneSubtitleTextIds(void);
void applyCraftCapabilityFlags(struct inner_player_struct*);
void initPlayerCraftMovementMode(struct inner_player_struct*);
void cancelSceneQueueHandle(struct inner_player_struct*);
void resetSpeechOncePerLevelFlag(s32);
void destroySceneNpcsAndUnlink(struct inner_player_struct*);
void decayWeaponCooldownTimer(void*, f32);
f32  getWeaponChargeLevel(void);

#endif
