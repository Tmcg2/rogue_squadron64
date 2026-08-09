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
    CHEAT_BIT_GAMEFLO,     /* 0x00 */ 
    CHEAT_BIT_KOELSCH,     /* 0x01 */ 
    CHEAT_BIT_FARMBOY,     /* 0x02 */ 
    CHEAT_BIT_TIEDUP,      /* 0x03 */ 
    CHEAT_BIT_HALIFAX,     /* 0x04 */ 
    CHEAT_BIT_BLAMEUS,     /* 0x05 */ 
    CHEAT_BIT_ACE,         /* 0x06 */ 
    CHEAT_BIT_ICHHELD,     /* 0x07 */ 
    CHEAT_BIT_PSYLOCK,     /* 0x08 */ 
    CHEAT_BIT_WUTZI,       /* 0x09 */ 
    CHEAT_BIT_BERGLOWE,    /* 0x0A */ 
    CHEAT_BIT_TIECK,       /* 0x0B */ 
    CHEAT_BIT_RUDIBUBI,    /* 0x0C */ 
    CHEAT_BIT_CHIPPIE,     /* 0x0D */ 
    CHEAT_BIT_TOBIASS,     /* 0x0E */ 
    CHEAT_BIT_SIRHISS,     /* 0x0F */ 
    CHEAT_BIT_HARDROCK,    /* 0x10 */ 
    CHEAT_BIT_THBPILOT,    /* 0x11 */ 
    CHEAT_BIT_FLYDODGE,    /* 0x12 */ 
    CHEAT_BIT_MAESTRO,     /* 0x13 */ 
    CHEAT_BIT_DIRECTOR,    /* 0x14 */ 
    CHEAT_BIT_CREDITS,     /* 0x15 */ 
    CHEAT_BIT_IGIVEUP,     /* 0x16 */ 
    CHEAT_BIT_RADAR,       /* 0x17 */ 
    CHEAT_BIT_TOUGHGUY,    /* 0x18 */ 
    CHEAT_BIT_CHICKEN,     /* 0x19 */ 
    CHEAT_BIT_WOMPRAT,     /* 0x1A */ 
    CHEAT_BIT_WOISTHAN,    /* 0x1B */ 
    CHEAT_BIT_DEADDACK,    /* 0x1C */ 
    NUM_CHEAT_CODES, /* 0x1D */ 
};

#define CHEAT_MASK(bit) (1 << (bit))
#define CHEAT_IS_ACTIVE(flags, bit)  (((flags) & CHEAT_MASK((bit))) != 0)
#define SET_CHEAT_FLAG(flags, bit)   (flags) |=  CHEAT_MASK((bit))
#define UNSET_CHEAT_FLAG(flags, bit) (flags) &= ~CHEAT_MASK((bit))

#define CHEAT_MASK_GAMEFLO  (CHEAT_MASK(CHEAT_BIT_GAMEFLO))  /* 0x00000001 */
#define CHEAT_MASK_KOELSCH  (CHEAT_MASK(CHEAT_BIT_KOELSCH))  /* 0x00000002 */
#define CHEAT_MASK_FARMBOY  (CHEAT_MASK(CHEAT_BIT_FARMBOY))  /* 0x00000004 */
#define CHEAT_MASK_TIEDUP   (CHEAT_MASK(CHEAT_BIT_TIEDUP))   /* 0x00000008 */
#define CHEAT_MASK_HALIFAX  (CHEAT_MASK(CHEAT_BIT_HALIFAX))  /* 0x00000010 */
#define CHEAT_MASK_BLAMEUS  (CHEAT_MASK(CHEAT_BIT_BLAMEUS))  /* 0x00000020 */
#define CHEAT_MASK_ACE      (CHEAT_MASK(CHEAT_BIT_ACE))      /* 0x00000040 */
#define CHEAT_MASK_ICHHELD  (CHEAT_MASK(CHEAT_BIT_ICHHELD))  /* 0x00000080 */
#define CHEAT_MASK_PSYLOCK  (CHEAT_MASK(CHEAT_BIT_PSYLOCK))  /* 0x00000100 */
#define CHEAT_MASK_WUTZI    (CHEAT_MASK(CHEAT_BIT_WUTZI))    /* 0x00000200 */
#define CHEAT_MASK_BERGLOWE (CHEAT_MASK(CHEAT_BIT_BERGLOWE)) /* 0x00000400 */
#define CHEAT_MASK_TIECK    (CHEAT_MASK(CHEAT_BIT_TIECK))    /* 0x00000800 */
#define CHEAT_MASK_RUDIBUBI (CHEAT_MASK(CHEAT_BIT_RUDIBUBI)) /* 0x00001000 */
#define CHEAT_MASK_CHIPPIE  (CHEAT_MASK(CHEAT_BIT_CHIPPIE))  /* 0x00002000 */
#define CHEAT_MASK_TOBIASS  (CHEAT_MASK(CHEAT_BIT_TOBIASS))  /* 0x00004000 */
#define CHEAT_MASK_SIRHISS  (CHEAT_MASK(CHEAT_BIT_SIRHISS))  /* 0x00008000 */
#define CHEAT_MASK_HARDROCK (CHEAT_MASK(CHEAT_BIT_HARDROCK)) /* 0x00010000 */
#define CHEAT_MASK_THBPILOT (CHEAT_MASK(CHEAT_BIT_THBPILOT)) /* 0x00020000 */
#define CHEAT_MASK_FLYDODGE (CHEAT_MASK(CHEAT_BIT_FLYDODGE)) /* 0x00040000 */
#define CHEAT_MASK_MAESTRO  (CHEAT_MASK(CHEAT_BIT_MAESTRO))  /* 0x00080000 */
#define CHEAT_MASK_DIRECTOR (CHEAT_MASK(CHEAT_BIT_DIRECTOR)) /* 0x00100000 */
#define CHEAT_MASK_CREDITS  (CHEAT_MASK(CHEAT_BIT_CREDITS))  /* 0x00200000 */
#define CHEAT_MASK_IGIVEUP  (CHEAT_MASK(CHEAT_BIT_IGIVEUP))  /* 0x00400000 */
#define CHEAT_MASK_RADAR    (CHEAT_MASK(CHEAT_BIT_RADAR))    /* 0x00800000 */
#define CHEAT_MASK_TOUGHGUY (CHEAT_MASK(CHEAT_BIT_TOUGHGUY)) /* 0x01000000 */
#define CHEAT_MASK_CHICKEN  (CHEAT_MASK(CHEAT_BIT_CHICKEN))  /* 0x02000000 */
#define CHEAT_MASK_WOMPRAT  (CHEAT_MASK(CHEAT_BIT_WOMPRAT))  /* 0x04000000 */
#define CHEAT_MASK_WOISTHAN (CHEAT_MASK(CHEAT_BIT_WOISTHAN)) /* 0x08000000 */
#define CHEAT_MASK_DEADDACK (CHEAT_MASK(CHEAT_BIT_DEADDACK)) /* 0x10000000 */

#endif
