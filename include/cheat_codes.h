#ifndef CHEAT_CODES_H
#define CHEAT_CODES_H

/*
Copied from http://www.factor5.com/secrets_rogue_squadron.shtml:

GAMEFLO!: Unlocks all regular missions.
KOELSCH:  Turns the V-Wing into a 1969 Buick convertible.
FARMBOY:  Enables the Millennium Falcon.
TIEDUP:   Enables the Tie Fighter.
HALIFAX?: First step access the Naboo Starfighter
BLAMEUS:  Displays a picture of the development team.
ACE:      Changes difficulty level to really hard.
ICHHELD:  Luke turns into R. Henke
PSYLOCK:  Luke turns into M. Wagner
WUTZI:    Luke turns into J. Eggebrecht
BERGLOWE: Luke turns into H. Schmidt
TIECK:    Luke turns into F. Sauer
RUDIBUBI: Luke turns into R. Stember
CHIPPIE:  Luke turns into C. Huelsbeck
TOBIASS:  Luke turns into T. Richter
SIRHISS:  Luke turns into J. Petersam
HARDROCK: Luke turns into T. Engel 
THBPILOT: Luke turns into B. Hoppe
FLYDODGE: Luke turns into D. Jagalski
MAESTRO:  Activates the music menu.
DIRECTOR: Let's you view all the cutscenes.
CREDITS:  The Credits.
IGIVEUP:  Unlimited lives.
RADAR:    Switches dark for bright in radar screen.
TOUGHGUY: All weapon and shield powerups.
CHICKEN:  Play as an AT-ST.
WOMPRAT!: Unlocks the Tatooine race bonus level.
WOISTHAN: Unlocks the Death Star Trench bonus level.
DEADDACK: Unlocks the Battle of Hoth bonus level.

!YNGWIE!: Second code to access the Naboo Starfighter
*/

enum CheatCodeBits {
    GAMEFLO_BIT,     /* 0x00 */ 
    KOELSCH_BIT,     /* 0x01 */ 
    FARMBOY_BIT,     /* 0x02 */ 
    TIEDUP_BIT,      /* 0x03 */ 
    HALIFAX_BIT,     /* 0x04 */ 
    BLAMEUS_BIT,     /* 0x05 */ 
    ACE_BIT,         /* 0x06 */ 
    ICHHELD_BIT,     /* 0x07 */ 
    PSYLOCK_BIT,     /* 0x08 */ 
    WUTZI_BIT,       /* 0x09 */ 
    BERGLOWE_BIT,    /* 0x0A */ 
    TIECK_BIT,       /* 0x0B */ 
    RUDIBUBI_BIT,    /* 0x0C */ 
    CHIPPIE_BIT,     /* 0x0D */ 
    TOBIASS_BIT,     /* 0x0E */ 
    SIRHISS_BIT,     /* 0x0F */ 
    HARDROCK_BIT,    /* 0x10 */ 
    THBPILOT_BIT,    /* 0x11 */ 
    FLYDODGE_BIT,    /* 0x12 */ 
    MAESTRO_BIT,     /* 0x13 */ 
    DIRECTOR_BIT,    /* 0x14 */ 
    CREDITS_BIT,     /* 0x15 */ 
    IGIVEUP_BIT,     /* 0x16 */ 
    RADAR_BIT,       /* 0x17 */ 
    TOUGHGUY_BIT,    /* 0x18 */ 
    CHICKEN_BIT,     /* 0x19 */ 
    WOMPRAT_BIT,     /* 0x1A */ 
    WOISTHAN_BIT,    /* 0x1B */ 
    DEADDACK_BIT,    /* 0x1C */ 
    NUM_CHEAT_CODES, /* 0x1D */ 
};

#define CHEAT_MASK(bit) (1 << (bit))
#define CHEAT_IS_ACTIVE(flags, bit)  (((flags) & CHEAT_MASK((bit))) != 0)
#define SET_CHEAT_FLAG(flags, bit)   (flags) |=  CHEAT_MASK((bit))
#define UNSET_CHEAT_FLAG(flags, bit) (flags) &= ~CHEAT_MASK((bit))

#define CHEAT_MASK_GAMEFLO  (CHEAT_MASK(GAMEFLO_BIT))  /* 0x00000001 */
#define CHEAT_MASK_KOELSCH  (CHEAT_MASK(KOELSCH_BIT))  /* 0x00000002 */
#define CHEAT_MASK_FARMBOY  (CHEAT_MASK(FARMBOY_BIT))  /* 0x00000004 */
#define CHEAT_MASK_TIEDUP   (CHEAT_MASK(TIEDUP_BIT))   /* 0x00000008 */
#define CHEAT_MASK_HALIFAX  (CHEAT_MASK(HALIFAX_BIT))  /* 0x00000010 */
#define CHEAT_MASK_BLAMEUS  (CHEAT_MASK(BLAMEUS_BIT))  /* 0x00000020 */
#define CHEAT_MASK_ACE      (CHEAT_MASK(ACE_BIT))      /* 0x00000040 */
#define CHEAT_MASK_ICHHELD  (CHEAT_MASK(ICHHELD_BIT))  /* 0x00000080 */
#define CHEAT_MASK_PSYLOCK  (CHEAT_MASK(PSYLOCK_BIT))  /* 0x00000100 */
#define CHEAT_MASK_WUTZI    (CHEAT_MASK(WUTZI_BIT))    /* 0x00000200 */
#define CHEAT_MASK_BERGLOWE (CHEAT_MASK(BERGLOWE_BIT)) /* 0x00000400 */
#define CHEAT_MASK_TIECK    (CHEAT_MASK(TIECK_BIT))    /* 0x00000800 */
#define CHEAT_MASK_RUDIBUBI (CHEAT_MASK(RUDIBUBI_BIT)) /* 0x00001000 */
#define CHEAT_MASK_CHIPPIE  (CHEAT_MASK(CHIPPIE_BIT))  /* 0x00002000 */
#define CHEAT_MASK_TOBIASS  (CHEAT_MASK(TOBIASS_BIT))  /* 0x00004000 */
#define CHEAT_MASK_SIRHISS  (CHEAT_MASK(SIRHISS_BIT))  /* 0x00008000 */
#define CHEAT_MASK_HARDROCK (CHEAT_MASK(HARDROCK_BIT)) /* 0x00010000 */
#define CHEAT_MASK_THBPILOT (CHEAT_MASK(THBPILOT_BIT)) /* 0x00020000 */
#define CHEAT_MASK_FLYDODGE (CHEAT_MASK(FLYDODGE_BIT)) /* 0x00040000 */
#define CHEAT_MASK_MAESTRO  (CHEAT_MASK(MAESTRO_BIT))  /* 0x00080000 */
#define CHEAT_MASK_DIRECTOR (CHEAT_MASK(DIRECTOR_BIT)) /* 0x00100000 */
#define CHEAT_MASK_CREDITS  (CHEAT_MASK(CREDITS_BIT))  /* 0x00200000 */
#define CHEAT_MASK_IGIVEUP  (CHEAT_MASK(IGIVEUP_BIT))  /* 0x00400000 */
#define CHEAT_MASK_RADAR    (CHEAT_MASK(RADAR_BIT))    /* 0x00800000 */
#define CHEAT_MASK_TOUGHGUY (CHEAT_MASK(TOUGHGUY_BIT)) /* 0x01000000 */
#define CHEAT_MASK_CHICKEN  (CHEAT_MASK(CHICKEN_BIT))  /* 0x02000000 */
#define CHEAT_MASK_WOMPRAT  (CHEAT_MASK(WOMPRAT_BIT))  /* 0x04000000 */
#define CHEAT_MASK_WOISTHAN (CHEAT_MASK(WOISTHAN_BIT)) /* 0x08000000 */
#define CHEAT_MASK_DEADDACK (CHEAT_MASK(DEADDACK_BIT)) /* 0x10000000 */

#endif
