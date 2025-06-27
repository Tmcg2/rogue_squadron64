# HUD Stuff

General note about this section: ROM addresses mentioned are likley only valid if you are playing the "Search for the Nonna" mission.
Its possible they could be valid for other levels, but I wouldn't assume that is the case.

There's a struct at ROM address `0x8010CA30` that seems to be related to how the HUD elements get displayed.
Its very very big, but the bulk of its size is comprised an array of a another struct type.

```cpp
struct rgba {
    /* 0x00 */ u8 red;
    /* 0x01 */ u8 green;
    /* 0x02 */ u8 blue;
    /* 0x03 */ u8 alpha;
}; // size = 0x4

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
    /* 0x001 */ u8 secondaryWeaponState; // Involved in the firing of secondary weapons in one way or another
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
    /* 0x028 */ struct hud_sub_struct outerCrosshairRingElement;
    /* 0x058 */ struct hud_sub_struct innerCrosshairRingElement;
    /* 0x088 */ struct hud_sub_struct hud_elements[8];
    /* 0x208 */ u32 unknown_words208[0x1C];
}; // size 0x278

struct hud_struct D_8010CA30[2];

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
}; // size = 0x24

struct D_8011A444_entry {
    /* 0x0 */ u16 material_type;
    /* 0x2 */ u16 D_80128F08_index;
}; // size = 0x4

struct D_80128F08_type *D_80128F08;
struct D_8011A444_entry *D_8011A444;

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
    /* 0x03C */ struct hud_sub_struct hud_element_0;
    /* 0x06C */ struct hud_sub_struct livesCountElement;
    /* 0x09C */ struct hud_sub_struct upperHealthIndicatorElement;
    /* 0x0CC */ struct hud_sub_struct lowerHealthIndicatorElement;
    /* 0x0FC */ struct hud_sub_struct secondaryWeaponCountElement;
    /* 0x12C */ struct hud_sub_struct secondaryWeaponSymbolElement;
    /* 0x15C */ struct hud_sub_struct secondaryWeaponRingElement;
    /* 0x18C */ struct hud_sub_struct radarOutlineElement;
    /* 0x1BC */ struct hud_sub_struct playerIdElement;
    /* 0x1EC */ u16 hud_xy_offsets[6][2]; // Not sure why there's only 6 of these but 9 hud elements
    /* 0x204 */ struct rgba hud_element_color_0;
    /* 0x208 */ struct rgba livesCountColor;
    /* 0x20C */ struct rgba upperHealthIndicatorColor;
    /* 0x210 */ struct rgba lowerHealthIndicatorColor;
    /* 0x214 */ struct rgba secondaryWeaponCountColor;
    /* 0x218 */ struct rgba secondaryWeaponSymobolColor;
    /* 0x21C */ struct rgba secondaryWeaponRingColor;
    /* 0x220 */ struct rgba radarOutlineColor;
    /* 0x224 */ struct rgba playerIdColor; // name based on code, but I don't think anything is actually displayed
    /* 0x228 */ u16 livesCountTimer;
    /* 0x22A */ u16 unk22A;
    /* 0x22C */ void *unk22C;
    /* 0x230 */ void *unk230;
    /* 0x234 */ u32 rest01[12];
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
        // struct meshdef0 mini_meshdef0
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
            /* 0xCF0 */ u32 unk2C[12];
        } mini_meshdef1;
        // struct meshdef1 mini_meshdef1
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

struct healthIndicatorColors {
    /* 0x00 */ struct rgba upper;
    /* 0x04 */ struct rgba lower;
}; // size = 0x8

struct healthIndicatorColors advancedShieldColors;
struct healthIndicatorColors standardHealthColors[2];
struct healthIndicatorColors criticalHealthColors[3];
```

`D_8010CA30` gets referenced alot in the `0xFCA20` code segment, so that would be the best place to start investigating how it works.

I don't fully understand `D_80128F08_type` and `D_8011A444_entry` at this time.
They seem related to how textures from the [HMT files](/docs/hmt_files/hmt_files.md) get mapped on loading.
By that I mean, textures in the HMT file have their own 0 indexed numbers associated with them.
But when multiple HMT files are loaded, there would need to be way to differentiate the multiple "index 0" textures.
And to the best of my knowledge, that's what those 2 types/arrays are involved with.
The details are a fuzzy though, needs a lot more investigation.

`func_800C0084` initializes a struct that is `0xF80` bytes big.
It's somehow involved with the HUD stuff too, although how it differs from `D_8010CA30` is unclear to me.
It appears to contain several `struct hud_sub_struct`s, but there's clearly A LOT more in it than that.

`D_80109D2C` is an array of text ID's, 4 per level.
These are the mission objective text ID's.
In the event that there are less the 4 objectives, 0's fill out the rest of the array.

## Radar Stuff

```cpp
/*
Radar dots override the pixels in the heightmap
and this struct is used to track the values pre-override
*/
struct RadarPixelBackup {
    /* 0x00 */ u16 tlPixelIndex;
    /* 0x02 */ u8  tlOrigColorIndex;
    /* 0x03 */ u8  trOrigColorIndex;
    /* 0x04 */ u8  blOrigColorIndex;
    /* 0x05 */ u8  brOrigColorIndex;
}; // size = 0x6

struct Radar {
    // The Radar dispalyed in the HUD is a CI4 image projected onto a plane on-screen
    /* 0x000 */ u8 colorIndexes[0x800];
    /* 0x800 */ struct material_entry material;
    /* 0x824 */ struct texture_entry texture;
    /* 0x858 */ u16 textureId1;
    /* 0x85A */ u16 textureId2;
    /* 0x85C */ u16 unk85C;
    /* 0x85E */ u16 unk85E;
    /* 0x860 */ f32 matrix1[3][4];
    /* 0x890 */ struct meshdef0 radarmeshdef0;
    /* 0x8DC */ struct meshdef1 radarmeshdef1;
    /* 0x938 */ struct facegroup facegroup;
    /* 0x948 */ struct vertex hudOctagonCorners[8];
    /* 0x988 */ struct vertex hudObjectiveSlice[3];
    /* 0x9A0 */ struct vertex cockpitOctagonCorners[8];
    /* 0x9E0 */ struct vertex cockpitObjectiveSlice[3];
    /* 0x9F8 */ struct face unk9F8[16];
    /* 0xB18 */ // struct face unkB18[8];
    /* 0xC38 */ struct RadarPixelBackup dotBackups[0x40];
    /* 0xDB8 */ u16 numRadarDots;
    /* 0xDBA */ u16 padDBA;
    /* 0xDBC */ f32 unkDBC;
    /* 0xDC0 */ f32 unkDC0;
    /* 0xDC4 */ f32 unkDC4;
    /* 0xDC8 */ u16 unkDC8;
    /* 0xDCA */ u16 padDCA;
    /* 0xDCC */ f32 unkDCC;
    /* 0xDD0 */ u8  unkDD0;
    // Probably 3 bytes of padding
}; // size = 0xDD4

struct Radar D_8010BFE0;

struct rgb D_80109FF8[16]; // normal palette
struct rgb D_8010A028[16]; // height inverted palette
struct rgb D_8010A058[16]; // ATST level palette
```

`D_8010BFE0` is a pointer to all the Radar related stuff.
There's something like a [full header image](../image_files/image_files.md) inside it, specifically a CI4 image.
For reasons I don't understand, the radar is shaped like an octagon.
