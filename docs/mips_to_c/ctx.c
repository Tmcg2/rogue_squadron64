typedef unsigned long u64;
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef long s64;
typedef int s32;
typedef short s16;
typedef char s8;
typedef float f32;

typedef f32 Vec3f[3];

/**********************************************************************/
/****************************** OS STUFF ******************************/
/**********************************************************************/

typedef struct {
    u32 ctrl;
    u32 width;
    u32 burst;
    u32 vSync;
    u32 hSync;
    u32 leap;
    u32 hStart;
    u32 xScale;
    u32 vCurrent;
} OSViCommonRegs;

typedef struct {
    u32 origin;
    u32 yScale;
    u32 vStart; 
    u32 vBurst;
    u32 vIntr;
} OSViFieldRegs;

typedef struct {
    u8          type;       /* Mode type */
    OSViCommonRegs  comRegs;    /* Common registers for both fields */
    OSViFieldRegs   fldRegs[2]; /* Registers for Field 1  & 2 */
} OSViMode;

OSViMode osViModeTable[];

typedef u32 OSEvent;
typedef void *OSMesg;

typedef s32 OSPri;
typedef s32 OSId;

typedef union {
    struct {
        f32 f_odd;
        f32 f_even;
    } f;
    f64 d;
} __OSfp;

typedef struct {
    u64 at, v0, v1, a0, a1, a2, a3;
    u64 t0, t1, t2, t3, t4, t5, t6, t7;
    u64 s0, s1, s2, s3, s4, s5, s6, s7;
    u64 t8, t9;
    u64 gp, sp, s8, ra;
    u64 lo, hi;
    u32 sr, pc, cause, badvaddr, rcp;
    u32 fpcsr;
    __OSfp  fp0,  fp2,  fp4,  fp6,  fp8, fp10, fp12, fp14;
    __OSfp fp16, fp18, fp20, fp22, fp24, fp26, fp28, fp30;
} __OSThreadContext;

typedef struct {
    u32 flag;
    u32 count;
    u64 time;
} __OSThreadprofile_s;

typedef struct OSThread_s {
    struct OSThread_s    *next;       /* run/mesg queue link */
    OSPri                 priority;   /* run/mesg queue priority */
    struct OSThread_s   **queue;      /* queue thread is on */
    struct OSThread_s    *tlnext;     /* all threads queue link */
    u16                   state;      /* OS_STATE_* */
    u16                   flags;      /* flags for rmon */
    OSId                  id;         /* id for debugging */
    int                   fp;         /* thread has used fp unit */
    __OSThreadprofile_s  *thprof;     /* workarea for thread profiler */
    __OSThreadContext     context;    /* register/interrupt mask */
} OSThread;

/*
 * Structure for message queue
 */
typedef struct OSMesgQueue_s {
    OSThread    *mtqueue;       /* Queue to store threads blocked on empty mailboxes (receive) */
    OSThread    *fullqueue;     /* Queue to store threads blocked on full mailboxes (send) */
    s32          validCount;    /* Contains number of valid message */
    s32          first;         /* Points to first valid message */
    s32          msgCount;      /* Contains total # of messages */
    OSMesg      *msg;           /* Points to message buffer array */
} OSMesgQueue;

typedef struct {
    u32      errStatus;         /* error status */
    void    *dramAddr;          /* RDRAM buffer address (DMA) */
    void    *C2Addr;            /* C2 buffer address */
    u32      sectorSize;        /* size of transfering sector */
    u32      C1ErrNum;          /* total # of C1 errors */
    u32      C1ErrSector[4];    /* error sectors */
} __OSBlockInfo;

typedef struct {
    u32             cmdType;        /* for disk only */
    u16             transferMode;   /* Block, Track, or sector?   */
    u16             blockNum;       /* which block is transfering */
    s32             sectorNum;      /* which sector is transfering */
    u32             devAddr;        /* Device buffer address */
    u32             bmCtlShadow;    /* asic bm_ctl(510) register shadow ram */
    u32             seqCtlShadow;   /* asic seq_ctl(518) register shadow ram */
    __OSBlockInfo   block[2];       /* bolck transfer info */
} __OSTranxInfo;


typedef struct OSPiHandle_s {
    struct OSPiHandle_s *next;          /* point to next handle on the table */
    u8                   type;          /* DEVICE_TYPE_BULK for disk */
    u8                   latency;       /* domain latency */
    u8                   pageSize;      /* domain page size */
    u8                   relDuration;   /* domain release duration */
    u8                   pulse;         /* domain pulse width */
    u8                   domain;        /* which domain */
    u32                  baseAddress;   /* Domain address */
    u32                  speed;         /* for roms only */
    /* The following are "private" elements" */
    __OSTranxInfo        transferInfo;  /* for disk only */
} OSPiHandle;

typedef struct {
    u8  type;
    u32 address;
} OSPiInfo;

/*
 * Structure for I/O message block
 */
typedef struct {
    u16          type;      /* Message type */
    u8           pri;       /* Message priority (High or Normal) */
    u8           status;    /* Return status */
    OSMesgQueue *retQueue;  /* Return message queue to notify I/O completion */
} OSIoMesgHdr;

typedef struct {
    OSIoMesgHdr  hdr;       /* Message header */
    void        *dramAddr;  /* RDRAM buffer address (DMA) */
    u32          devAddr;   /* Device buffer address (DMA) */
    u32          size;      /* DMA transfer size in bytes */
    OSPiHandle  *piHandle;  /* PI device handle */
} OSIoMesg;

/*
 * Structure for device manager block
 */
typedef struct {
    s32          active;    /* Status flag */
    OSThread    *thread;    /* Calling thread */
    OSMesgQueue *cmdQueue;  /* Command queue */
    OSMesgQueue *evtQueue;  /* Event queue */
    OSMesgQueue *acsQueue;  /* Access queue */
                /* Raw DMA routine */
    s32         (*dma)(s32, u32, void *, u32);
    s32         (*edma)(OSPiHandle *, s32, u32, void *, u32);
} OSDevMgr;

typedef struct {
    /* 0x00 */ int     status;
    /* 0x04 */ OSMesgQueue     *queue;
    /* 0x08 */ int     channel;
    /* 0x0C */ u8      id[32];
    /* 0x2C */ u8      label[32];
    /* 0x4C */ int     version;
    /* 0x50 */ int     dir_size;
    /* 0x54 */ int     inode_table;        /* block location */
    /* 0x58 */ int     minode_table;       /* mirrioring inode_table */
    /* 0x5C */ int     dir_table;      /* block location */
    /* 0x60 */ int     inode_start_page;   /* page # */
    /* 0x64 */ u8      banks;
    /* 0x65 */ u8      activebank;
} OSPfs; // size 0x68

typedef struct {
    u32 file_size;  /* bytes */
    u32     game_code;
    u16     company_code;
    char    ext_name[4];
    char    game_name[16];
} OSPfsState;

OSPfs D_80112730[];

s32 osPfsInitPak(OSMesgQueue*, OSPfs*, int);
s32 osPfsRepairId(OSPfs*);
s32 osPfsInit(OSMesgQueue*, OSPfs*, int);
s32 osPfsReFormat(OSPfs*, OSMesgQueue*, int);
s32 osPfsChecker(OSPfs*);
s32 osPfsAllocateFile(OSPfs*, u16, u32, u8*, u8*, int, s32*);
s32 osPfsFindFile(OSPfs*, u16, u32, u8*, u8*, s32*);
s32 osPfsDeleteFile(OSPfs*, u16, u32, u8*, u8*);
s32 osPfsReadWriteFile(OSPfs*, s32, u8, int, int, u8*);
s32 osPfsFileState(OSPfs*, s32, OSPfsState*);
s32 osPfsGetLabel(OSPfs*, u8*, int*);
s32 osPfsSetLabel(OSPfs*, u8*);
s32 osPfsIsPlug(OSMesgQueue*, u8*);
s32 osPfsFreeBlocks(OSPfs*, s32*);
s32 osPfsNumFiles(OSPfs*, s32*, s32*);

typedef struct {
    u16     type;                   /* Controller Type */
    u8      status;                 /* Controller status */
    u8  errno;
} OSContStatus;

typedef struct {
    u16     button;
    s8      stick_x;        /* -80 <= stick_x <= 80 */
    s8      stick_y;        /* -80 <= stick_y <= 80 */
    u8  errno;
} OSContPad;

typedef struct {
    void    *address;               /* Ram pad Address:  11 bits */
    u8      databuffer[32];         /* address of the data buffer */
        u8      addressCrc;             /* CRC code for address */
    u8      dataCrc;                /* CRC code for data */
    u8  errno;
} OSContRamIo;

OSContStatus gControllerStatuses[4];
OSContPad gControllerPads[4];

s32 osContInit(OSMesgQueue*, u8*, OSContStatus*);
s32 osContReset(OSMesgQueue*, OSContStatus*);
s32 osContStartQuery(OSMesgQueue*);
s32 osContStartReadData(OSMesgQueue*);
void osContGetQuery(OSContStatus*);
void osContGetReadData(OSContPad*);

s32 osMotorInit(OSMesgQueue*, OSPfs*, int);
s32 osMotorStop(OSPfs*);
s32 osMotorStart(OSPfs*);

s32 osEepromProbe(OSMesgQueue *);
s32 osEepromRead(OSMesgQueue *, u8, u8 *);
s32 osEepromWrite(OSMesgQueue *, u8, u8 *);
s32 osEepromLongRead(OSMesgQueue *, u8, u8 *, int);
s32 osEepromLongWrite(OSMesgQueue *, u8, u8 *, int);

void osCreateMesgQueue(OSMesgQueue*, OSMesg*, s32);
s32 osSendMesg(OSMesgQueue*, OSMesg, s32);
s32 osJamMesg(OSMesgQueue*, OSMesg, s32);
s32 osRecvMesg(OSMesgQueue*, OSMesg*, s32);
void osSetEventMesg(OSEvent, OSMesgQueue*, OSMesg);

void osInvalDCache(void*, s32);
void osInvalICache(void*, s32);
void osWritebackDCache(void*, s32);
void osWritebackDCacheAll(void);

/************************************************************************/
/****************************** GAME STUFF ******************************/
/************************************************************************/

struct texture_entry {
    /* 0x00 */ u32 pixel_offset;
    /* 0x04 */ u8 zeros[28];
    /* 0x20 */ u32 plte_offset;
    /* 0x24 */ u32 texture_name_offset;
    /* 0x28 */ u16 width;
    /* 0x2A */ u16 height;
    /* 0x2C */ u8 one; // Always(?) 0x01, purpose unknown
    /* 0x2D */ u8 bit_depth;
    /* 0x2E */ u8 unused;
    /* 0x2F */ u8 type;
    /* 0x30 */ u32 trans_color;
}; // size 0x34

s32 func_8007A260(struct texture_entry *texture_entry);

struct material_entry {
    /* 0x00 */ u16 material_type; // 1 = has texture, 2 = no texture
    /* 0x02 */ u16 texture_index;
    /* 0x04 */ f32 misc_float; // Pupose unknown
    /* 0x08 */ f32 one; // Always(?) 1.0f
    /* 0x0C */ u32 zero; // Always(?) 0
    /* 0x10 */ u32 alwaysa; // Always(?) 0x0a000000, purpose unknown
    /* 0x14 */ char material_name[16];
}; // size 0x24

struct rgba {
    /* 0x00 */ u8 red;
    /* 0x01 */ u8 green;
    /* 0x02 */ u8 blue;
    /* 0x03 */ u8 alpha;
}; // size 0x4

struct xy_offset {
    /* 0x0 */ u16 x;
    /* 0x2 */ u16 y;
}; // size = 0x4

struct hud_sub_struct {
    // Or is it prev then next?
    /* 0x00 */ struct hud_sub_struct *next;
    /* 0x04 */ struct hud_sub_struct *prev;
    // These seem to control whether the UI element is visible or not, somehow
    /* 0x08 */ u16 texture_count;
    /* 0x0A */ u16 unknown0A;
    /* 0x0C */ u16 *texture_id_pointer;
    /* 0x10 */ struct xy_offset *xy_offset_pointer;
    /* 0x14 */ u32 flags;
    /* 0x18 */ f32 xpos;
    /* 0x1C */ f32 ypos;
    /* 0x20 */ f32 zero; // zpos?, maybe padding
    /* 0x24 */ f32 width_scale;
    /* 0x28 */ f32 height_scale;
    /* 0x2C */ struct rgba rgba;
}; // size = 0x30

struct hud_struct {
    /* 0x000 */ u8 secondaryWeapon;
    /* 0x001 */ u8 unknown001;
    /* 0x002 */ u8 secondaryWeaponCount;
    /* 0x003 */ u8 secondaryWeaponReset; // Or maybe, secondaryWeaponMax?
    /* 0x004 */ u8 secondaryWeaponIsAdvanced;
    /* 0x005 */ u8 crosshairOnOff;
    /* 0x006 */ u8 unknown006;
    /* 0x007 */ u8 unknown007;
    /* 0x008 */ u16 unknown008;
    // I think these are indices into D_8011A444;
    /* 0x00A */ u16 texture_ids[10];
    /* 0x01E */ // u16 compiler_padding;
    /* 0x020 */ u32 unknown020; // could be padding?
    /* 0x024 */ f32 alpha_scaling;
    /* 0x028 */ struct hud_sub_struct hud_elements[10];
    /* 0x208 */ u32 unknown_words208[0x1C];
}; // size 0x278

struct hud_struct D_8010CA30[2];

struct data_block_header_entry {
    /* 0x00 */ u8 name[16];
    /* 0x10 */ u32 unk10;
    /* 0x14 */ u32 unk14;
    /* 0x18 */ u32 unk18; // If this is nonzero then this data block's manifest won't get DMA'd. I don't get why that would ever be useful
    /* 0x1C */ u32 data_offset; // offset after data block header to the data block for this entry
}; // size 0x20

struct data_block_header_entry *D_80110A74;

struct manifest_entry {
    /* 0x00 */ u32 data_offset;
    /* 0x04 */ u32 decompressed_size;
    /* 0x08 */ u32 compressed_size; // 0xFFFFFFFF (or -1 if signed) indicates that the entry is not compressed
    /*
    bit 7: is directory (0x80)
    bits 1-6: never set, checked in several places though
    bit 0: set a lot (but not alwasy). Purpose unknown
    */
    /* 0x0C */ u8 flags;
    /* 0x0D */ u8 unk0D;
    /*
    This is a number multiplied by 0x20 (<< 5)
    It is the size in bytes that the directory takes up in the manifest
    So, (directory content entries + 1(the directory entry itself)) * 0x20
    For non-directory entries, this number should be zero 
    */
    /* 0x0E */ u16 directory_size;
    /* 0x10 */ u8 name[16];
}; // size 0x20

struct D_80110A80_entry {
    /* 0x00 */ u32 unk00[16];
    /* 0x40 */ struct manifest_entry *manifest;
    /* 0x44 */ u8 *data; // pointer to the data block that the manifest refers to. Is a ROM pointer as well, weirdly
    /* 0x48 */ u32 entry_count; // number of entries in the manifest/number of files in the data block (same thing really)
    /* 0x4C */ u16 unk4C;
    /* 0x4E */ u8  one;
    /* 0x4F */ // u8 compiler_padding?;
}; // size 0x50

// Fake variable D_80110AA0 <- 0x20
struct D_80110A80_entry D_80110A80[4];

struct manifest_entry *find_manifest_entry(u32 idx, u8 *entry_name);

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

!YNGWIE!: Second stop to access the Naboo Starfighter
*/

enum CheatCodeBits {
    /* 0x00 */ GAMEFLO_BIT,
    /* 0x01 */ KOELSCH_BIT,
    /* 0x02 */ FARMBOY_BIT,
    /* 0x03 */ TIEDUP_BIT,
    /* 0x04 */ HALIFAX_BIT,
    /* 0x05 */ BLAMEUS_BIT,
    /* 0x06 */ ACE_BIT,
    /* 0x07 */ ICHHELD_BIT,
    /* 0x08 */ PSYLOCK_BIT,
    /* 0x09 */ WUTZI_BIT,
    /* 0x0A */ BERGLOWE_BIT,
    /* 0x0B */ TIECK_BIT,
    /* 0x0C */ RUDIBUBI_BIT,
    /* 0x0D */ CHIPPIE_BIT,
    /* 0x0E */ TOBIASS_BIT,
    /* 0x0F */ SIRHISS_BIT,
    /* 0x10 */ HARDROCK_BIT,
    /* 0x11 */ THBPILOT_BIT,
    /* 0x12 */ FLYDODGE_BIT,
    /* 0x13 */ MAESTRO_BIT,
    /* 0x14 */ DIRECTOR_BIT,
    /* 0x15 */ CREDITS_BIT,
    /* 0x16 */ IGIVEUP_BIT,
    /* 0x17 */ RADAR_BIT,
    /* 0x18 */ TOUGHGUY_BIT,
    /* 0x19 */ CHICKEN_BIT,
    /* 0x1A */ WOMPRAT_BIT,
    /* 0x1B */ WOISTHAN_BIT,
    /* 0x1C */ DEADDACK_BIT,
    /* 0x1D */ NUM_CHEAT_CODES,
};

#define GAMEFLO_MASK  (1 << GAMEFLO_BIT)  /* 0x00000001 */
#define KOELSCH_MASK  (1 << KOELSCH_BIT)  /* 0x00000002 */
#define FARMBOY_MASK  (1 << FARMBOY_BIT)  /* 0x00000004 */
#define TIEDUP_MASK   (1 << TIEDUP_BIT)   /* 0x00000008 */
#define HALIFAX_MASK  (1 << HALIFAX_BIT)  /* 0x00000010 */
#define BLAMEUS_MASK  (1 << BLAMEUS_BIT)  /* 0x00000020 */
#define ACE_MASK      (1 << ACE_BIT)      /* 0x00000040 */
#define ICHHELD_MASK  (1 << ICHHELD_BIT)  /* 0x00000080 */
#define PSYLOCK_MASK  (1 << PSYLOCK_BIT)  /* 0x00000100 */
#define WUTZI_MASK    (1 << WUTZI_BIT)    /* 0x00000200 */
#define BERGLOWE_MASK (1 << BERGLOWE_BIT) /* 0x00000400 */
#define TIECK_MASK    (1 << TIECK_BIT)    /* 0x00000800 */
#define RUDIBUBI_MASK (1 << RUDIBUBI_BIT) /* 0x00001000 */
#define CHIPPIE_MASK  (1 << CHIPPIE_BIT)  /* 0x00002000 */
#define TOBIASS_MASK  (1 << TOBIASS_BIT)  /* 0x00004000 */
#define SIRHISS_MASK  (1 << SIRHISS_BIT)  /* 0x00008000 */
#define HARDROCK_MASK (1 << HARDROCK_BIT) /* 0x00010000 */
#define THBPILOT_MASK (1 << THBPILOT_BIT) /* 0x00020000 */
#define FLYDODGE_MASK (1 << FLYDODGE_BIT) /* 0x00040000 */
#define MAESTRO_MASK  (1 << MAESTRO_BIT)  /* 0x00080000 */
#define DIRECTOR_MASK (1 << DIRECTOR_BIT) /* 0x00100000 */
#define CREDITS_MASK  (1 << CREDITS_BIT)  /* 0x00200000 */
#define IGIVEUP_MASK  (1 << IGIVEUP_BIT)  /* 0x00400000 */
#define RADAR_MASK    (1 << RADAR_BIT)    /* 0x00800000 */
#define TOUGHGUY_MASK (1 << TOUGHGUY_BIT) /* 0x01000000 */
#define CHICKEN_MASK  (1 << CHICKEN_BIT)  /* 0x02000000 */
#define WOMPRAT_MASK  (1 << WOMPRAT_BIT)  /* 0x04000000 */
#define WOISTHAN_MASK (1 << WOISTHAN_BIT) /* 0x08000000 */
#define DEADDACK_MASK (1 << DEADDACK_BIT) /* 0x10000000 */

enum Level {
    /* 0x00 */ MOSEISLEY_LEVEL,
    /* 0x01 */ BARKHESH_LEVEL,
    /* 0x02 */ NONNAH_LEVEL,
    /* 0x03 */ CORELLIA_LEVEL,
    /* 0x04 */ GERRARDV_LEVEL,
    /* 0x05 */ JADEMOON_LEVEL,
    /* 0x06 */ CONST_YARD_LEVEL,
    /* 0x07 */ KILEII_LEVEL,
    /* 0x08 */ KESSEL_RESCUE_LEVEL,
    /* 0x09 */ KESSEL_PRISON_LEVEL,
    /* 0x0A */ TALORAAN_LEVEL,
    /* 0x0B */ FEST_LEVEL,
    /* 0x0C */ CHANDRILA_LEVEL,
    /* 0x0D */ SULLUST_LEVEL,
    /* 0x0E */ THYFERRA_LEVEL,
    /* 0x0F */ CALAMARI_LEVEL,
    /* 0x10 */ BEGGARS_CANYON_LEVEL,
    /* 0x11 */ TRENCH_RUN_LEVEL,
    /* 0x12 */ HOTH_LEVEL,
    /* 0x13 */ NUM_LEVELS,
    /* 0x13 */ LOGO_LEVEL = 0x13,
    /* 0x14 */ ATST_LEVEL,
};

enum Level D_80130B70;
enum Level gCurrentLevel;

enum PlayerCraft {
    /* 0x0 */ XWING_CRAFT,
    /* 0x1 */ YWING_CRAFT,
    /* 0x2 */ AWING_CRAFT,
    /* 0x3 */ VWING_CRAFT,
    /* 0x4 */ SNOWSPEEDER_CRAFT,
    /* 0x5 */ FALCON_CRAFT,
    /* 0x6 */ TIEINTER_CRAFT,
    /* 0x7 */ T16_CRAFT,
    /* 0x8 */ KOELSCH_CRAFT,
};

// Default/demo craft per level
enum PlayerCraft dDefaultCraftForLevel[NUM_LEVELS];

char *D_80109CB0[];

enum SecondaryWeapon {
    /* 0x00 */ UNUSED, // not sure what's up with this...
    /* 0x01 */ ION_CANNON,
    /* 0x02 */ MISSLES,
    /* 0x03 */ SEEKER_MISSILES,
    /* 0x04 */ BOMBS,
    /* 0x05 */ PROTON_TORPEDOS,
    /* 0x06 */ TOW_CABLE,
    /* 0x07 */ CLUSTER_MISSILES,
    /* 0x08 */ SEEKER_TORPEDOS,
    /* 0x09 */ SEEKER_CLUSTER_MISSILES,
    /* 0xFF */ NONE = 0xFF,
};

u16 D_800A5840[];

enum SecondaryWeapon func_800C6728(enum Level arg0, enum PlayerCraft arg1, s32 arg2);
s32 func_800C6900(enum Level arg0);
char *func_800AE530(enum Level arg0, enum PlayerCraft arg1);

struct inner_player_struct {
    /* 0x000 */ void *unk000;
    /* 0x004 */ f32 posX;
    /* 0x008 */ f32 posY;
    /* 0x00C */ f32 posZ;
    /* 0x010 */ f32 unk010;
    /* 0x014 */ f32 unk014;
    /* 0x018 */ f32 unk018;
    /* 0x01C */ f32 unk01C;
    /* 0x020 */ f32 unk020;
    /* 0x024 */ f32 unk024;
    /* 0x028 */ f32 unk028;
    /* 0x02C */ f32 unk02C;
    /* 0x030 */ f32 unk030;
    /* 0x034 */ u16 unk034[0x40];
    /* 0x0B4 */ u16 unk0B4;
    /* 0x0B6 */ u16 unk0B6;
    /* 0x0B8 */ s32 unk0B8;
    /* 0x0BC */ void *unk0BC;
    /* 0x0C0 */ f32 currentHealth;
    /* 0x0C4 */ f32 maxHealth;
    /* 0x0C8 */ f32 unk0C8[0x2C];
    /* 0x178 */ u32 unk178[0x35];
    /* 0x24C */ f32 unk24C[0x10];
    /* 0x28C */ u16 unk28C;
    /* 0x28A */ u16 unk28A;
    /* 0x290 */ enum PlayerCraft vehicleId;
    /* 0x294 */ u32 unk294;
    /* 0x298 */ u32 unk298;
}; // size 0x29C

struct player_struct {
    /* 0x000 */ u8 unk000;
    /* 0x001 */ u8 unk001; // compiler padding?
    /* 0x002 */ u16 unk002;
    /* 0x004 */ struct inner_player_struct inner;
}; // size 0x2A0

// This array is only 1 entry long. I assume its an array as a leftover from when they were planning on having a multiplayer mode
// References to things inside this struct
// D_80137DBC -> 0x004
// D_8013800C -> 0x254
// D_8013803C -> 0x284
struct player_struct D_80137DB8[];

void func_800B1BE8(struct inner_player_struct *arg0, f32 arg1);
void func_800B3E4C(struct inner_player_struct *arg0, s32 arg1);

// This seems different from what ReRogue has as the languages (EN,DE,FR,ES,JP).
// This may differ across cart versions?
enum Language {
    LANGUAGE_EN, // English
    LANGUAGE_DE, // German
    LANGUAGE_FR, // Fr*nch
    LANGUAGE_IT, // Italian
    LANGUAGE_ES, // Spanish
    NUM_LANGUAGES,
};

enum ControllerSetting {
    CONTROLLER_SETTING_LUKE,
    CONTROLLER_SETTING_WEDGE,
    CONTROLLER_SETTING_JANSON,
    CONTROLLER_SETTING_HOBBIE,
    NUM_CONTROLLER_SETTINGS,
};

enum ResolutionSetting {
    RESOLUTION_NORMAL,
    RESOLUTION_HIGH,
    NUM_RESOLUTIONS,
};

struct D_80130B10_type {
    /* 0x0 */ u8 unk0;
    /* 0x1 */ u8 unk1;
    /* 0x2 */ u8 secondaryWeapon;
    /* 0x3 */ u8 secondaryWeaponMax;
    /* 0x4 */ u8 unk4;
    /* 0x5 */ u8 unk5;
    /* 0x6 */ u8 unk6;
    /* 0x7 */ u8 unk7;
}; // size 0x8

struct D_80130B10_type D_80130B10;

struct D_80130B40_type {
    /* 0x00 */ u8  currentLevel; // Should really be an `enum Level` but enums types are bigger than 1 byte
    /* 0x01 */ u8  vehicleId; // Should really be an `enum PlayerCraft` but enums types are bigger than 1 byte
    /* 0x02 */ u8  unk02;
    /* 0x03 */ u8  secondaryWeapon; // Should really be an `enum SecondaryWeapon` but enum types are bigger than 1 byte
    /* 0x04 */ u8  unk04;
    /* 0x05 */ u8  controllerSetting; // Should really an `enum ControllerSetting` but enums types are bigger than 1 byte
    /* 0x06 */ u8  languageSelect; // Should really an `enum Language` but enums types are bigger than 1 byte
    /* 0x07 */ char name[3]; // no null terminator
    /* 0x0A */ u8  unk0A;
    /* 0x0B */ u8  unk0B;
    // I suspect these next 4 bytes are really part of a single word
    // It might be a huge bit field?
    /* 0x0C */ u8  unk0C;
    /*
    |             7             |                6               |                 5                |           4           |
    |            ???            |               ???              |                ???               |          ???          |
    |             3             |                2               |                 1                |           0           |
    | 1/0, all craft  available | 1/0, TIE interceptor available | 1/0, millennium falcon available | 1/0, advanced shields |
    */
    /* 0x0D */ u8  unk0D;
    /*
    |          7          |               6              |            5           |               4               |
    | 1/0, advanced bombs | 1/0, seeker cluster missiles |  1/0, seeker torpedos  | 1/0, advanced proton torpedos |
    |          3          |               2              |            1           |               0               |
    | 1/0, seeker missles |     1/0, advanced missles    | 1/0, advanced blasters |              ???              |
    */
    /* 0x0E */ u8  unk0E;
    /*
    |                  7                 |  6   |            5            |            4           |
    |       1/0, crosshair on/off        | ???  | 1/0, free camera off/on |   1/0 cockpit on/off   |
    |                  3                 |  2   |            1            |            0           |
    | 1/0 displays (hud elements) on/off | ???  |  1/0, auto roll on/off  | 1/0, auto level on/off |
    */
    /* 0x0F */ u8  displaySettings;
    // I suspect these next 4 bytes are really part of a single word
    // It might be a huge bit field?
    /* 0x10 */ u8  unk10;
    /* 0x11 */ u8  unk11;
    /* 0x12 */ u8  unk12;
    /*
    |          7           |         6         |            5             |              4              |
    |    1/0 mono/stereo   |        ???        |    0/1 demo in/active    |     1/0 subtitles off/on    |
    |          3           |         2         |            1             |              0              |
    | 0/1 speech un/muted  | 0/1 sfx un/muted  |    0/1 music un/muted    |  1/0 resolution high/normal |
    */
    /* 0x13 */ u8  soundResolutionSettings;
    /* 0x14 */ u8  demoId;
    /* 0x15 */ u8  unk15;
    /* 0x16 */ u8  unk16;
    /* 0x17 */ u8  unk17;
    /* 0x18 */ u32 cheatCodeFlags[2]; // probably 2 words big for insurance, incase they added more cheats. In practice this is oversized
    /* 0x20 */ u8  musicVolume;
    /* 0x21 */ u8  soundFxVolume;
    /* 0x22 */ u8  speechVolume;
    /* 0x23 */ u8  unk23;
    /* 0x24 */ u32 unk24;
    /* 0x28 */ u32 unk28;
}; // size 0x2C

struct D_80130B40_type D_80130B40;

void func_800C5898(struct D_80130B40_type *arg0, s32 arg1, s32 arg2);
s32 func_800C5D9C(struct D_80130B40_type *arg0, s32 arg1);

struct demoInput {
    /*
    * I suspect this is duration of the input, but I can't be sure...
    * its nomrally 1/30th or 1/20th, which would sort of fit for a 1-per-frame setup
    * But increasing these values to things like 1 or 5 don't increase the input's duration (or, at least, not in any perceptible way)
    */
    /* 0x0 */ f32 unk0;
    /* 0x4 */ u16 button;
    /* 0x6 */ s8  stick_x;
    /* 0x7 */ s8  stick_y;
}; // size 0x8

u32 D_80109AE0; // Current demo step number
struct demoInput *D_8010BCA0;
OSContPad *D_80110748; // Pointer to D_80130B88???
OSContPad D_80130B88[4];

void func_800BECDC(s32 controllerId, struct demoInput *demoInput);

char *getGameOrFrontText(s32 textId);
void getControllerSettingsTitle(char *title);

// Really enum Level, but that will be sized too large
// Levels used for the demos
u8 D_800CD404[6];
u8 dLevelByDemoId[6];

// void func_800FEEF4(struct player_struct*, );

void rs_strcpy(u8 *dest, u8* src);
void rs_strncpy(u8 *dest, u8 *src, u32 size);
void rs_strcat(u8 *dest, u8 *src);
void rs_strncat(u8 *dest, u8 *src, u32 size);
s32  rs_strcmp(u8 *left, u8 *right);
s32  rs_strncmp(u8 *left, u8 *right, u32 count);
void rs_memset(u8 *dest, u8 value, u32 size);
u8 *strchr(u8 *s, s32 c);

void *rs_malloc(s32 size, u16 flags);
void  rs_free(void*);

s32 strlen(char*);
s32 func_800076F8(s8 *arg0, s8 *arg1); // strcmp?
void zmemcpy(u8 *dest, u8 *src, u32 size);

void func_80001C98(struct manifest_entry*);
void func_800159B4(struct hud_sub_struct *hud_element, void*);

u16 func_8001F954(struct texture_entry *texture, u32 *palte_offset, u16 width, u16 height, u32 *trans_color, char *texture_name_offset);
s32 func_80022B90(struct material_entry *material, struct texture_entry *texture, u32 arg2);
u16 func_80022A00(u16 arg0, struct material_entry *material, struct texture_entry *texture, u32 arg3, u32 arg4);

struct D_80110520_entry {
    /* 0x00 */ OSPfs pfs;
    /* 0x68 */ u8 unk68;
    /* 0x69 */ u8 unk69;
    /* 0x6A */ u8 unk6A;
    /* 0x6B */ u8 unk6B;
    /* 0x6C */ u8 unk6C;
    // All 3 of these might be compiler padding
    /* 0x6D */ // u8 unk6D;
    /* 0x6E */ // u8 unk6E;
    /* 0x6F */ // u8 unk6F;
    /* 0x70 */ void *unk70;
    /* 0x74 */ f32 unk74;
    /* 0x78 */ f32 unk78;
    /* 0x7C */ f32 unk7C;
    /* 0x80 */ f32 unk80;
    /* 0x84 */ u32 unk84;
}; // size 0x88

struct D_80110520_entry D_80110520[4];

u32 D_800A0ED0[29];

s32 D_80111254;
OSMesg D_801107A0[8];
OSMesgQueue D_801107C0;
OSIoMesg D_801107E0[8];
OSMesg D_801108A0[8];
OSMesgQueue D_801108C0[8];
OSMesg D_80110980;
OSMesgQueue D_80110990;
s32 D_801109A8;
s32 D_801109AC;
u8 *D_801109B0[8];
s32 D_801109D0[8];
u8 *D_801109F0[8];
s32 D_80110A10[8];
s32 D_80110A30[8];
s32 D_80110A50[8];
u8  D_80110A70;
OSMesgQueue D_80110BC0[16];

s32 func_80003480(u8 *source, u8 *dest, u32 size);

struct D_80128F08_type {
    /* 0x00 */ u8  unk00;
    /* 0x01 */ u8  unk01;
    /* 0x02 */ u8  unk02;
    /* 0x03 */ u8  unk03;
    /* 0x04 */ u32 unk04;
    /* 0x08 */ u16 width;
    /* 0x0A */ u16 height;
    /* 0x0C */ u16 texture_size;
    /* 0x0E */ u16 unk0E;
    /* 0x10 */ void *texture_data; // u8*?
    /* 0x14 */ u8 texture_name[16];
}; // size 0x24

struct D_8011A444_entry {
    /* 0x0 */ u16 material_type;
    /* 0x2 */ u16 D_80128F08_index;
}; // size 0x4

struct D_80128F08_type *D_80128F08;
struct D_8011A444_entry *D_8011A444;

u32 rs_crc32(u32 *crc32LUT, u8 *input, u32 length);

struct hmp_tile {
    /* 0x00 */ u16 texmap_idx;
    /* 0x02 */ u8 flags;
    /* 0x03 */ u8 min_height;
    /* 0x04 */ u8 max_height;
    /* 0x05 */ u8 height_values[25];
}; // size 0x1E

struct hmp_tile *D_80136DC4;

// Dumb name: this is a way to map _TEX texmap entries to the corresponding in-memory texture stuff found in D_80128F08_type/D_8011A444_entry
struct texmap_map {
    /* 0x0 */ u16 texmap_idx;
    /* 0x2 */ u16 interal_idx;
}; // size = 0x4

struct light_object {
    /* 0x00 */ Vec3f intensity;
    /* 0x0C */ u8 active;
    /* 0x0D */ u8 mode;
    /* 0x0E */ u8 intesity_boost;
    /* 0x0F */ u8 unk0;
    /* 0x10 */ Vec3f location;
    /* 0x1C */ f32 blue_intensity;
}; // size = 0x20

// Need to think about the name a bit harder...
struct hmp_context {
    /* 0x00 */ u16  *tile_idxs;
    /* 0x04 */ struct hmp_tile *hmp_tiles;
    /* 0x08 */ u16  *unk08;
    /* 0x0C */ struct texmap_map *texmap;
    /* 0x10 */ f32   unk10;
    /* 0x14 */ f32   unk14;
    /* 0x18 */ f32   unk18;
    /* 0x1C */ f32   unk1C;
    /* 0x20 */ f32   unk20;
    /* 0x24 */ f32   unk24;
    /* 0x28 */ f32   unk28;
    /* 0x2C */ f32   unk2C;
    /* 0x30 */ f32   unk30;
    /* 0x34 */ f32   unk34;
    /* 0x38 */ u16   width;
    /* 0x3A */ u16   height;
    /* 0x3C */ f32   unk3C;
    /* 0x40 */ f32   unk40;
    /* 0x44 */ f32   unk44;
    /* 0x48 */ struct light_object *lights;
    /* 0x4C */ u32   unk4C;
    /* 0x50 */ u32   unk50;
    /* 0x54 */ u32   unk54;
}; // size 0x58

struct hmp_context D_80136DC0;

void func_800457D0(struct hmp_context *hmp_ctx, s32 arg1);
void func_80049814(void *arg0, struct hmp_context *hmp_ctx);
void func_80049BBC(void *arg0, struct hmp_context *hmp_ctx);
void func_80049FB8(void *arg0, struct hmp_context *hmp_ctx);

s32 func_8006F43C(enum PlayerCraft craftType, enum SecondaryWeapon arg1);

struct account_data {
    /* 0x00 */ char name[4]; // has a null-terminator (I think?)
    /* 0x04 */ u32 unk04;
    /* 0x08 */ u32 unk08;
    /* 0x0C */ u32 unk0C;
    /* 0x10 */ u8  accountNumber;
    /* 0x11 */ u8  padding[3];
}; // size 0x14

struct EliteRogueData {
    char name[3]; // really just 3 characters, no null terminator
    u8 current_level; // should be an enum Level but enum entires are sized too big
    // Don't know if its a bit field, or if its just a u16 that they pick apart by hand
    union {
        u16 as_short;
        struct {
            u16 pad     : 1;
            u16 golds   : 5;
            u16 silvers : 5;
            u16 bronzes : 5;
        } as_bit_field;
    };
    u16 accountNumber; // I think?
}; // size 0x8

struct D_8013A5C0_type {
    /* 0x00 */ u32 unk00; // struct D_80130B40_type.unk10
    /* 0x04 */ u32 unk04; // struct D_80130B40_type.unk0C & 0x8B
    /* 0x08 */ u32 cheatCodeFlags[2];
    /* 0x10 */ u8  musicVolume;
    /* 0x11 */ u8  soundFxVolume;
    /* 0x12 */ u8  speechVolume;
    /* 0x13 */ u8  controllerSetting;
    /* 0x14 */ struct account_data accounts[3];
    /* 0x50 */ u8 unk50; // has a value, unsure of purpose
    /* 0x51 */ u8 unk51;
    // This stuff is aligned super weirdly, so being a proper struct may not work, only time will tell
    /* 0x52 */ struct EliteRogueData highscores[10];
    /* 0xA0 */ u32 unkA0;
    /* 0xA4 */ u32 unkA4;
    /* 0xA8 */ u8  languageSelect;
    /* 0xA9 */ u8  padding[3]; // maybe?
    /* 0xAC */ u32 unkAC;
}; // size 0xB0

struct save_data_body {
    /* 0x00 */ u32 D_8013A5C0_checksum;
    /* 0x04 */ u32 unknown_checksum; // checksum of the unk08 section
    // This looks like a series of pointers(?) but I can't be certain
    /* 0x08 */ u32 unk08[4];
    /* 0x18 */ struct D_8013A5C0_type body;
}; // size 0xC8

struct save_file_header {
    /* 0x000 */ u32 part1_checksum;
    /* 0x004 */ u32 part1[3];
    /* 0x010 */ u32 part2_checksum;
    /* 0x014 */ u32 part2[3];
}; // size 0x20

struct save_data {
    /* 0x000 */ struct save_file_header header;
    /* 0x020 */ struct save_data_body data[2];
    /* 0x1B0 */ u32 zeros[0x50]; // The game doesn't use all 256 bytes of the EEPROM, so there's a bunch of unused space at the bottom
}; // size 0x200

struct gamesave_asset D_801126C0;

struct account_data *func_8006EE5C(s32);
void func_8006EB48(struct account_data *arg0, s32 arg1);

struct D_800CE730_type {
    /* 0x00 */ char *screen_title;
    /* 0x04 */ u8 current_menu;
    /* 0x05 */ u8 back_menu; // that is, the menu you'll go back to when selecting the "Back" option
    /* 0x06 */ u16 unk06;
    /* 0x08 */ char *menu_entries[8];
    /* 0x28 */ u8 unk28[8]; // sub-type of each menu entry
    /* 0x30 */ s16 entry_xy_offsets[8][2]; // could maybe be struct, but an array works just as well
    /* 0x50 */ s16 title_xy_offset[2];
    /* 0x54 */ f32 entry_size_scaler[8];
    /* 0x74 */ u32 unk74[8]; // numbers found here have different meanings, dependent on the "sub-type" fount in unk28
    /* 0x94 */ u8 current_menu_entry;
    /* 0x95 */ u8 num_menu_entries; // This doesn't alway match the visible menu entries, so there's likely a nuance I'm missing
    /* 0x96 */ s16 overall_y_offset;
    /*
    bit field(?) indicating if the text of a menu entry is non-zero
    something like:
    u16 entry15 : 1;
    u16 entry14 : 1;
    ...
    u16 entry1  : 1;
    u16 entry0  : 1;
    */
    /* 0x98 */ u16 active_entries;
    /* 0x9A */ u16 unk9A;
    /* 0x9C */ f32 unk9C; // Changes whenever you move to a new menu entry, purpose unknown
    /* 0xA0 */ f32 highlight_timer;
    /* 0xA4 */ f32 unkA4;
    /* 0xA8 */ f32 unkA8;
    /* 0xAC */ f32 unkAC;
    /* 0xB0 */ f32 unkB0[8];
    /* 0xD0 */ f32 unkD0[8];
    /* 0xF0 */ f32 unkF0[2];
}; // size = 0xF8

struct D_800CE730_type D_800CE730;

struct D_800CC89C_type {
    /* 0x00 */ u16 name_text_id;
    /* 0x02 */ u16 unk02; // padding, maybe?
    /* 0x04 */ char *image_asset_name;
    /* 0x08 */ u16 image_width;
    /* 0x0A */ u16 image_height;
    /* 0x0C */ u16 image_x_offset;
    /* 0x0E */ u16 image_y_offset;
    /* 0x10 */ s16 name_x_offset;
    /* 0x12 */ u16 biography_text_id;
    /* 0x14 */ u16 unk14; // x-offset of the indent 
    /* 0x16 */ u16 unk16; // y-offset of where the biography text stops taking the picture into account
    /* 0x18 */ u16 unk18[6]; // maximum of 5 real entries with the 6th being `0xFFFF`
}; // size = 0x24

struct D_800CC89C_type D_800CC89C[7];

struct D_800CC974_type {
    /* 0x0 */ u16 option1_text_id;
    /* 0x2 */ u16 option2_text_id;
    /* 0x4 */ u8  D_80130B40_unk0C_byte;
    /* 0x5 */ u8  unk5; // padding?
    /* 0x6 */ u16 D_80130B40_unk0C_bit;
    /* 0x8 */ u16 unk8;
    /* 0xA */ u16 unkA;
}; // size = 0xC

struct D_800CC974_type D_800CC974[7];

struct D_800CCE1C_type {
    /* 0x0 */ char *song_name;
    /* 0x4 */ u32 song_id; // name is speculative
}; // size = 0x8

struct D_800CCE1C_type D_800CCE1C[0x3E];

struct D_800CE730_type *func_800BA0F0(u8 arg0, s32 arg1, s32 arg2);
s32 func_800BB234(s32 arg0, struct D_800CE730_type *arg1, s32 arg2, s32 arg3, u8 arg4);
void func_800C4C8C(struct D_800CE730_type *arg0, s32 arg1, s32 arg2);

char D_800CD540[4][0x30];

struct func_800C0084_d84_type {
    /* 0x00 */ u32 unk00[8];
    /* 0x20 */ u32 unk20;
    /* 0x24 */ u32 unk24;
    /* 0x28 */ u32 unk28;
    /* 0x2C */ u16 unk2C;
    /* 0x2E */ u16 unk2E;
    /* 0x30 */ u16 unk30;
    /* 0x32 */ u16 unk32;
    /* 0x34 */ u16 unk34;
    /* 0x36 */ u16 unk36;
    /* 0x38 */ u16 unk38;
    /* 0x3A */ u16 unk3A;
    /* 0x3C */ u16 unk3C;
    /* 0x3E */ u16 unk3E;
    /* 0x40 */ u16 unk40;
    /* 0x42 */ u16 unk42;
    /* 0x44 */ u32 unk44;
}; // size = 0x48

struct func_800C0084_type {
    /* 0x000 */ u16 hud_texture_ids[0x1E];
    /* 0x03C */ struct hud_sub_struct hud_elements[9];
    /* 0x1EC */ u16 hud_xy_offsets[6][2]; // Not sure why there's only 6 of these but 9 hud elements
    /* 0x204 */ struct rgba hud_element_colors[9];
    /* 0x22C */ u32 rest01[15];
    /* 0x264 */ struct hud_sub_struct menu_elements[16];
    /* 0x564 */ u16 menu_texture_ids[0x12C];
    /* 0x7BC */ u8  rest02[10];
    // The alignment of this is pretty bizarre
    /* 0x7C6 */ u16 menu_element_xy_offsets[0x12C][2];
    /* 0xC76 */ u8  rest03[2]; // padding, most likely
    /*
    Starting here it looks like there's something like a mini-hob. Its related to the dimming effect on the pause screen.
    The `big_block_o_floats` from the meshdef0 definition is a little small in this case though, only 14 floats instead of 28
    The meshdef1 is also interesting, in the middle of its `big_block_o_floats` there's a pointer of some kind, so that's probably undersized too
    */
    /* 0xC78  u32 mini_hob[0x3C];*/
    struct {
        struct {
            /* 0xC78 */ void *next_meshdef0_pointer;
            /* 0xC7C */ void *prev_meshdef0_pointer;
            /* 0xC80 */ void *unknown_meshdef0_pointer0;
            /* 0xC84 */ void *unknown_meshdef0_pointer1;
            /* 0xC88 */ void *meshdef1_pointer;
            /* 0xC8C */ u32 unk14;
            /* 0xC90 */ u32 unk18;
            /* 0xC94 */ float big_block_o_floats[9];
            /* 0xCB8 */ float pos[3];
        } mini_meshdef0;
        struct {
            /* 0xCC4 */ void *next_meshdef1_pointer;
            /* 0xCC8 */ void *prev_meshdef1_pointer;
            /* 0xCCC */ u32 unk08;
            /* 0xCD0 */ u32 unk0C;
            /* 0xCD4 */ u32 unk10;
            /* 0xCD8 */ u32 vertex_counts[2];
            /* 0xCE0 */ float some_float;
            /* 0xCE4 */ void *facegroup_pointer;
            /* 0xCE8 */ void *vertext_pointers[2];
        } mini_meshdef1;
        /* 0xCF0 */ u32 unk78[12];
        struct {
            /* 0xD20 */ void *next_facegroup;
            /* 0xD24 */ void *prev_facegroup;
            /* 0xD28 */ void *face_offset;
            /* 0xD2C */ u32 face_count;
        } facegroup;
        struct {
            /* 0xD30 */ u32 flags;
            /* struct {
                u32 extra                     : 2;
                u32 face_size                 : 6; // multiply by 4 to get the actual size
                u32 vertex_indices_offset1    : 6; // multiply by 4 to get the actual offset
                u32 vertex_color_offset       : 6; // multiply by 4 to get the actual offset
                u32 vertex_indices_offset2    : 6; // multiply by 4 to get the actual offset
                u32 texture_coordiante_offset : 6; // multiply by 4 to get the actual offset
            } stuffed_data; */
            /* 0xD34 */ u32 stuffed_data;
            /* 0xD38 */ u32 material_index;
            /* 0xD3C */ u16 vertex_indices[4];
            /* 0xD44 */ struct rgba vertex_colors;
        } face;
        /* 0xD58 */ struct {
            u16 x;
            u16 y;
            u16 z;
            u16 padding;
        } vertices[4];
    } mini_hob;
    /* 0xD68 */ u16 current_entry;
    /* 0xD6A */ u8  current_menu;
    /* 0xD6B */ u8  unkD6B;
    /* 0xD6C */ u32 unkD6C;
    /* 0xD70 */ f32 text_highlight_timer;
    /* 0xD74 */ f32 medal_timer; // a timer related to the medal's back-and-forth rotation
    /* 0xD78 */ u32 unkD78;
    /* 0xD7C */ u32 unkD7C;
    /* 0xD80 */ f32 objective_highlight_countdown; // a countdown to when the objectives should be highlighted, the hilighting uses the same time as the menu selection
    /* 0xD84 */ struct func_800C0084_d84_type unkD84[7];
    /* 0xF7C */ u8 unkF7C;
    /* 0xF7D */ u8 secondaryWeaponType;
    /* 0xF7E */ u8 secondaryWeaponLevel;
    /* 0xF7F */ u8 unkF7F;
}; // size = 0xF80

// This also for D_80109E24, D_80109EEC, and D_80109E68
struct D_80109DD4_type {
    /* 0x0 */ u16 flags;
    /* 0x2 */ u16 unk2;
    /* 0x4 */ u16 unk4;
}; // size = 0x6

struct D_80109DD4_type D_80109DD4[];
struct D_80109DD4_type D_80109E24[];
struct D_80109DD4_type D_80109E68[];
struct D_80109DD4_type D_80109EEC[];

u8 D_80109D2C[][4];

void func_80062108(s16 arg0, struct hud_sub_struct *arg1, u8 arg2, u8 *arg3, u16 arg4, u16 arg5);
void func_800C1D3C(struct func_800C0084_type *arg0, f32 arg1);
void func_800C298C(void *arg0, struct func_800C0084_type *arg1);
void func_800BFDC4(struct func_800C0084_type *arg0);
void func_800BFEA0(struct func_800C0084_d84_type *arg0, void **arg1, s32 arg2);
