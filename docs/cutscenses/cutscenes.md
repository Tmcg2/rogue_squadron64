# Cutscenes

There are cutscene files for each cutscene in the game.

I don't know much about the internals of the cutscene files.
I have the general "shape" of the file figured out, but most of the fine grained details are lost on me.
I slightly annotated a [cutscene file](/docs/cutscenes/level_0_intro_cutscene) for reference.

There are 3 types of cutscenes:
- "Intro"
- "Extra"
- "Special"

"Intro" and "Extro" are pretty self explanatory, their the cutscenes that play at the beginning and end of a level.
"Special" I'm a little less certain of, there's only 2 of them total.
One for the "Defection at Corellia" level and one for the logo sequence.
For the "Defection" level I'd assume its a mid-level cutscene, but the logo sequence I'm less sure.

```cpp
enum CutsceneType {
	/* 0x0 */ CUTSCENE_INTRO,
	/* 0x1 */ CUTSCENE_EXTRO,
	/* 0x2 */ CUTSCENE_SPECIAL,
	/* 0x3 */ NUM_CUTSCENE_TYPES,
};

// strings to be used to fill out a format string when searching for cutscene file assets
// "intro", "extra", "special"
char *D_800AF6B0[NUM_CUTSCENE_TYPES];
```

There's a part of the cutscene files that has a "constant" size (there's probably a better word to use than "constant" but whatever).
That size is `0x25AC`.

Cutscene files start with a "filename", seemingly the path and name of the file as it existed on the development box Factor 5 used.
This can be up to 64 characters long.

`unk13D8_active_count` (offset `0x4A`) is a count of the populated members found in `unk13D8`.
`unk13D8` is sized to fit up to 60 `struct cuts_13D8_type` entries.

`unk0058_active_count` (offset `0x4E`) is a count of the populated members found in `unk0058`.
`unk0058` is sized to fit up to 200 `struct cuts_0058_type` entries.

There are always 6 `struct cuts_1318_type` entries found at offset `0x1318`.
In the [annotated cutscene](/docs/cutscenes/level_0_intro_cutscene) there's only one entry that has any non-zero values.
Based on a loop found in `func_800A5D80`, I think there can only be 1 entry with any values set, although I don't see any rhyme or reason for such a decision.

Offset `0x25A8` is another count, a count of entries that will be found starting at offset `0x25AC`.

Offset `0x25AC` is the beginning of the non-constant part of the cutscene file.
It is a giant list of floating point numbers, clustered in groups of 3.
I don't think they're `Vec3f`s, despite what I put in the struct definition.
If you plot all the entries as if they're 3D points, it looks very flat.
The supposed `z` value is too small for most entries.
But if they aren't `Vec3f`s, then I don't know what they are.

`D_800B1904` is a pointer to the currently loaded cutscene file (obviously, this is only valid if a cutscen is being played).

```cpp
struct cuts_0058_type {
	/* 0x00 */ u32 sub_type; // ???
	/* 0x04 */ u32 unk04;
	/* 0x08 */ u32 unk08;
	/* 0x0C */ u32 unk0C;
	/* 0x10 */ u32 unk10;
	/* 0x14 */ u32 unk14;
}; // size = 0x18

struct cuts_1318_type {
	/* 0x00 */ u32 vec3f_list_indices[8];
}; // size = 0x20

struct cuts_13D8_type {
	/* 0x00 */ char name[28]; // sometime an asset path, sometimes something else
	/* 0x1C */ u32 flags;
	/* 0x20 */ u32 unk20[11];
}; // size = 0x4C

struct cuts_file_constant {
	/* 0x0000 */ char filename[64];
	/* 0x0040 */ u32 unk0040;
	/* 0x0044 */ u32 unk0044;
	/* 0x0048 */ u16 unk0048;
	/* 0x004A */ u16 unk13D8_active_count;
	/* 0x004C */ u16 unk004C;
	/* 0x004E */ u16 unk0058_active_count;
	/* 0x0050 */ f32 unk0050;
	/* 0x0054 */ f32 unk0054;
	/* 0x0058 */ struct cuts_0058_type unk0058[200];
	/* 0x1318 */ struct cuts_1318_type unk1318[6];
	/* 0x13D8 */ struct cuts_13D8_type unk13D8[60];
	/* 0x25A8 */ u32 vec3f_count;
	// While these are definitely collections of 3 floating point numbers, I don't know if they're really Vec3f's (i.e. x/y/z)
	/* 0x25AC */ Vec3f vec3f_list[1]; // size is bogus, this entry is only here to make using m2c a bit more ergonomic
}; // size = 0x25AC

struct cuts_file_constant *D_800B1904;
```

`D_800B1900` is a pointer to a list of `struct D_800B1900_type` entries.
There are `unk13D8_active_count` entries in this list.
I don't have nay idea what the details of these are though.

```cpp
struct D_800B1900_type {
	/* 0x000 */ u8    unk000;
	/* 0x001 */ u8    unk001;
	/* 0x002 */ u8    unk002;
	/* 0x003 */ u8    unk003;
	/* 0x004 */ u32   unk004;
	/* 0x008 */ void *unk008;
	/* 0x00C */ u32   unk00C;
	/* 0x010 */ u32   unk010;
	/* 0x014 */ u32   unk014;
	/* 0x018 */ u32   unk018;
	/* 0x01C */ u32   unk01C;
	/* 0x020 */ f32   unk020[12];
	/* 0x050 */ void *unk050;
	/* 0x054 */ u32   unk054;
	/* 0x058 */ u16   unk058;
	/* 0x05A */ u16   unk05A;
	/* 0x05C */ u32   unk05C;
	/* 0x060 */ u32   unk060;
	/* 0x064 */ f32   unk064[21];
	/* 0x0B8 */ u16   unk0B8;
	/* 0x0BA */ u16   unk0BA;
	/* 0x0BC */ u32   unk0BC;
	/* 0x0C0 */ u32   unk0C0;
	/* 0x0C4 */ u32   unk0C4;
	/* 0x0C8 */ u32   unk0C8;
	/* 0x0CC */ u32   unk0CC;
	/* 0x0D0 */ u32   unk0D0;
	/* 0x0D4 */ u32   unk0D4;
	/* 0x0D8 */ u32   unk0D8;
	/* 0x0DC */ u32   unk0DC;
	/* 0x0E0 */ u32   unk0E0;
	/* 0x0E4 */ u32   unk0E4;
	/* 0x0E8 */ u32   unk0E8;
	/* 0x0EC */ u32   unk0EC;
	/* 0x0F0 */ u32   unk0F0;
	/* 0x0F4 */ u32   unk0F4;
	/* 0x0F8 */ u32   unk0F8;
	/* 0x0FC */ u32   unk0FC;
	/* 0x100 */ u32   unk100;
	/* 0x104 */ u32   unk104;
	/* 0x108 */ u32   unk108;
	/* 0x10C */ u32   unk10C;
	/* 0x110 */ u32   unk110;
	/* 0x114 */ u32   unk114;
	/* 0x118 */ u32   unk118;
	/* 0x11C */ u32   unk11C;
	/* 0x120 */ u32   unk120;
	/* 0x124 */ u32   unk124;
	/* 0x128 */ u32   unk128;
	/* 0x12C */ u32   unk12C;
	/* 0x130 */ u32   unk130;
	/* 0x134 */ u32   unk134;
	/* 0x138 */ u32   unk138;
}; // size = 0x13C

struct D_800B1900_type *D_800B1900;
```

There are 32 entires of size `0x5C` in `D_800AF92C`.
They are somehow related to the cutscense, although exactly how is unclear to me.
My speculation (based on strings in the ROM near that location) is that they are related to ships/buildings that are present in the various cutscenes.
So they have things like the asset's path, its name, the path to animation data if its a model, etc.
I don't know what the non-string members are.

```cpp
struct D_800AF92C_type {
	/* 0x00 */ char asset_path_prefix[32];
	/* 0x20 */ char asset_name[16];
	/* 0x30 */ f32 unk30;
	/* 0x34 */ f32 unk34;
	/* 0x38 */ f32 unk38;
	/* 0x3C */ char walk_animation_asset_path[24]; // size of this is a bit speculative
	/* 0x54 */ f32 unk24;
	/* 0x58 */ u16 unk58;
	/* 0x5A */ u16 unk5A;
}; // size = 0x5C

struct D_800AF92C_type D_800AF92C[32];
```
