#ifndef MAIN_562A0_H
#define MAIN_562A0_H

#include "PR/ultratypes.h"

enum Language {
    LANGUAGE_EN, // English
    LANGUAGE_DE, // German
    LANGUAGE_FR, // French
    LANGUAGE_IT, // Italian
    LANGUAGE_ES, // Spanish
    NUM_LANGUAGES,
};

s32   loadTxtFile(u8*, u8);
void  loadGameOrFrontTxtFile(u8*);
char *getGameOrFrontText(s32 textId);
void  loadVoiceTxtFile(u8*);
char *getVoiceTxtStringPtr(void);

#endif
