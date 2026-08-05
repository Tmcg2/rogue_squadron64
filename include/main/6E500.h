#ifndef MAIN_66FB0_H
#define MAIN_66FB0_H

#include "PR/ultratypes.h"

void loadDefaultHighScores(void);
void unlockMissleUpgradeOnLevelCompletion(u8);
void setAccountHighscore(u8, u16, u8);

extern char *defaultHighscoreNames[0xA];

#endif
