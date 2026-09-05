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

char *getGameOrFrontText(s32 textId);

#endif
