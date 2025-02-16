# DAT File Specification

DAT files contain a variety of data for playable levels and certain menu locations (the hanger and the briefing room for example).
They are initially parsed by [load_level_dat](load_level_dat.c).
One of the big things that function does is convert offsets into pointers.

I have also made a utility called [dat_file_names.c](dat_file_names.c) that will extract the names of each of the data items from a DAT file.
Note that some data items do not have names, in such cases the utility will output `NONAME  at <file offset of item in question>`
I do not attempt to extract any other data from the file, and there is A LOT of other data to be extracted.
I have passed every level's DAT file through that utility and saved the output to [dat_file_item_names.txt](dat_file_names.txt).

There are 5 types of data stored in DAT files

## Type 0

Spawn locations.
Although "spawn" might be too specific, it also appears to have positions for placement of buildings and "props" (for lack of a better term).

There are A LOT of sub-types for this data type, no idea what any of them are.

The player's start position is always `player_StartPosition`.

Some extra parsing of these items happens in `func_80065790` and `func_80046620`

## Type 2

Unknown.
There's only 1 playable level that even has entries of this type (`Raid on Sullust`) and all those entries are named `LAVAFART##`.
Could be lights, maybe?

## Type 3

Splines

## Type 6

LOD related things, maybe boxes which dictate what LOD models to use at any given time?

Things called `MUSICRNG_SomethingElseHere`.
The name is suggestive but I don't know what exactly they are.

There are A LOT of sub-types for this data type, no idea what any of them are.

Some extra parsing of these items happens in `func_800653B4`

## Type 7

Events, or maybe more accurately event triggers (or at least their locations)?

Some extra parsing of these items happens in `func_800AA870` and `func_80046620`

## Item Groups

These aren't really a proper type.
Some (but not all) items are grouped together.
I don't really understand what these groups represent though, nor do I understand their purpose.

# File Structure

I'll do my best to explain the general structure of a DAT file.
I'd advise referencing the [lvl0_dat](lvl0_dat) file while reading this explanation.
It is the DAT file for level 0 (Attack on Mos Eisley) that I have partially annotated for easier understanding.

The first 0x48 bytes of the file are the counts and offsets-to-offset-lists for each of the data types, with some padding in it.

Offset 0x00 and 0x04 are Item 0 count and offset respecitively
Offset 0x10 and 0x14 are Item 2 count and offset respecitively
Offset 0x18 and 0x1C are Item 3 count and offset respecitively
Offset 0x30 and 0x34 are Item 6 count and offset respecitively
Offset 0x38 and 0x3C are Item 7 count and offset respecitively
Offset 0x40 and 0x44 are Item Collection count and offset respecitively

Offset lists are pretty much exactly what they sound like.
They are a list of numbers that are offsets RELATIVE TO THE BEGINNING OF THE LIST where a given item can be found.
Each item type has its own offset list.
For `Attack on Mos Eisley`, the offset list for Item 0's can be found at offset 0x48

Entries of a given item type appear to have variable sizes, especially Item 0's (with its various sub-types), thus I can't provide a generic C struct to explain all of their internals.
I'll provide a struct-like explanation of the parts that appear constant for each entry though.

## Type 0 Internals

```cpp
struct item_type_0 {
	uint16_t sub_type;
	uint16_t unk02;
	uint16_t item_index; // Maybe?
	uint16_t padding;
	union {
		// Don't know which of these it is
		uint32_t item_size;
		uint32_t offset_to_next_item;
	};
	uint32_t offset_to_item_name; // If this is 0, the item has no name
	float position[3]; // Maybe? Don't know this is really
	/*
	Lots more stuff after this, there may or may not be sub-type independent data here, can't tell.
	*/
};
```

## Type 2 Internals

Since `Attack on Mos Eisley` doesn't have any of these, I have no clue what they look like.
Presumably they aren't that different from all the others.

## Type 3 Internals

```cpp
struct item_type_3 {
	uint16_t unk00;
	uint16_t unk02;
	uint32_t padding;
	union {
		// Don't know which of these it is
		uint32_t item_size;
		uint32_t offset_to_next_item;
	};
	uint32_t offset_to_item_name; // If this is 0, the item has no name
	float position[3]; // Maybe? Don't know this is really
	/*
	Lots more stuff after this, there may or may not be sub-type independent data here, can't tell.
	*/
};
```

There are extra count+offset combos at offset 0x1C+0x20 and 0x28+0x2C of the item.
Those offsets are RELATIVE TO THE ITEM ITSELF.
I don't know what the counts or offsets are referencing

## Type 6 Internals

```cpp
struct item_type_6 {
	uint16_t sub_type; // I think?
	uint16_t unk02;
	uint32_t padding;
	union {
		// Don't know which of these it is
		uint32_t item_size;
		uint32_t offset_to_next_item;
	};
	uint32_t offset_to_item_name; // If this is 0, the item has no name
	float position[3]; // Maybe? Don't know this is really
	/*
	Lots more stuff after this, there may or may not be sub-type independent data here, can't tell.
	*/
};
```

## Type 7 Internals

```cpp
struct item_type_7 {
	uint16_t unk00;
	uint16_t unk02;
	uint32_t padding;
	union {
		// Don't know which of these it is
		uint32_t item_size;
		uint32_t offset_to_next_item;
	};
	uint32_t offset_to_item_name; // If this is 0, the item has no name
	float position[3]; // Maybe? Don't know this is really
	/*
	Lots more stuff after this, there may or may not be sub-type independent data here, can't tell.
	*/
};
```

## Item Collection Internals

These are actually straightforward.
There are exactly 256 groups (I don't know the significance of that number) of items.
Each group contains entries that look like:

```cpp
struct item_collection_entry {
	uint32_t item_type; // so 0, 2, 3, 6, or 7
	uint32_t item_index;
};
```

Each group of items ends with an entry where both `item_type` and `item_index` `0xFFFFFFFF` (`-1`).

# Code stuff

`D_801375D8` appears to be what amounts to a DAT file pointer.
`load_dat_file_assets` is invovled in [Type 0](#type-0) handling, especially the loading of the models for sub types with models.

`D_80139990` is only ever referenced in `load_dat_file_assets`.
It seems to be a list of bytes indicating whether a given sub-type has been loaded or not.
The `rs_memset` call suggests that there are `0x53` total sub-types, although the array looks to be `0x58` bytes big based on debugger viewing.

```cpp
/*
Nomenclature:
    - DAT_UNKNOWN_XX: Not observed in any DAT or source code files
    - DAT_TYPE_X_YY: Used by Type X entries, named after its enum value YY
    - DAT_TYPE_X_A_NAME: Used by Type X entries, named after code or DAT file usage A_NAME
*/
enum DAT_SUBTYPE {
	/* 0x00 */ DAT_UNKNOWN_00,
	/* 0x01 */ DAT_TYPE_0_PLAYER_START_POSITION,
	/* 0x02 */ DAT_TYPE_0_RESTART_POSITION, // Mostly used by players, but used for Moff Seerdon too
	/* 0x03 */ DAT_TYPE_3_03, // "regular" spline type
	/* 0x04 */ DAT_TYPE_6_HIGH_LOD_BOX, // Name is speculative
	/* 0x05 */ DAT_TYPE_6_LOW_LOD_BOX, // Name is speculative
	/* 0x06 */ DAT_TYPE_0_HANGAR_SUBTYPE0, // Only used in the hangar, mostly in reference to the player craft
	/* 0x07 */ DAT_TYPE_0_HANGAR_SUBTYPE1, // Used in the hangar, bridge, and logo scenes, purpose unknown
	/* 0x08 */ DAT_TYPE_3_08, // Another spline type, only used in the hangar and the logo scenes
	/* 0x09 */ DAT_TYPE_2_09,
	/* 0x0A */ DAT_UNKNOWN_0A,
	/* 0x0B */ DAT_UNKNOWN_0B,
	/* 0x0C */ DAT_TYPE_0_TIE_FIGHTER,
	/* 0x0D */ DAT_TYPE_0_GUN_TURRET,
	/* 0x0E */ DAT_TYPE_0_PROBE_DROID,
	/* 0x0F */ DAT_TYPE_0_ATAT,
	/* 0x10 */ DAT_TYPE_6_MUSIC_RNG,
	/* 0x11 */ DAT_TYPE_7_11, // Could be boxes for event activation?
	/* 0x12 */ DAT_TYPE_0_TIE_INTERCEPTOR,
	/* 0x13 */ DAT_TYPE_0_TIE_BOMBER,
	/* 0x14 */ DAT_TYPE_0_GENERIC_BUILDING, // These trigger the loading of the "destroyed building" model
	/* 0x15 */ DAT_UNKNOWN_15,
	/* 0x16 */ DAT_TYPE_6_16,
	/* 0x17 */ DAT_TYPE_7_17, // Could be spheres for event activation?
	/* 0x18 */ DAT_TYPE_7_18, // Could be timers for event activation?
	/* 0x19 */ DAT_TYPE_7_19, // ??
	/* 0x1A */ DAT_TYPE_7_1A, // One of the NONAME entry types
	/* 0x1B */ DAT_TYPE_7_1B, // One of the NONAME entry types
	/* 0x1B */ DAT_TYPE_7_1C, // One of the NONAME entry types
	/* 0x1D */ DAT_UNKNOWN_1D,
	/* 0x1E */ DAT_TYPE_0_MISSLE_TURRET,
	/* 0x1F */ DAT_TYPE_0_ATST,
	/* 0x1B */ DAT_TYPE_7_20, // One of the NONAME entry types
	/* 0x21 */ DAT_TYPE_0_21, // Non-moving NPC spawn locations?
	/* 0x22 */ DAT_TYPE_7_22, // One of the NONAME entry types
	/* 0x23 */ DAT_TYPE_7_23, // One of the NONAME entry types
	/* 0x24 */ DAT_TYPE_0_SHUTTLE,
	/* 0x25 */ DAT_TYPE_0_TANK_DROID,
	/* 0x26 */ DAT_TYPE_0_CAMERA_POSITION,
	/* 0x27 */ DAT_TYPE_0_WINGMAN_POSITION, // Has a sub-sub-type to indicate the exact craft to be used
	/*
	This is really 3 models under one sub-type:
	The Gerrard V mega turrets
	The Trench Run mega turrets
	The generic mega turrets

	The exact model chosen is decided by the currently loaded level
	*/
	/* 0x28 */ DAT_TYPE_0_MEGA_TURRENT,
	/* 0x29 */ DAT_TYPE_0_TIE_D, // ??????
	/* 0x2A */ DAT_TYPE_0_RADAR_DISH,
	/* 0x2B */ DAT_TYPE_0_REBEL_TRANSPORT,
	/* 0x2C */ DAT_TYPE_0_HEAVY_SHUTTLE,
	/* 0x2D */ DAT_TYPE_0_CARGO_01,
	/* 0x2E */ DAT_TYPE_0_REBEL_COMBAT, // Don't know exactly what this is...
	// All three of these load the same model, I'm not sure why they're separate sub-types
	/* 0x2F */ DAT_TYPE_0_IMPERIAL_TRAIN0,
	/* 0x30 */ DAT_TYPE_0_IMPERIAL_TRAIN1,
	/* 0x31 */ DAT_TYPE_0_IMPERIAL_TRAIN2,
	/* 0x32 */ DAT_TYPE_0_SHIELD, // ?????
	/* 0x33 */ DAT_TYPE_0_IMPERIAL_TRAIN_PILLAR,
	// Both of these load the same model, I'm not sure why they're separate sub-types
	/* 0x34 */ DAT_TYPE_0_REBEL_TRAIN0,
	/* 0x35 */ DAT_TYPE_0_REBEL_TRAIN1,
	/* 0x36 */ DAT_TYPE_0_REBEL_TRAIN_PILLAR,
	/* 0x37 */ DAT_TYPE_0_WORLD_DEVASTATOR,
	/* 0x38 */ DAT_UNKNOWN_38,
	/* 0x39 */ DAT_TYPE_6_39, // One of the NONAME entry types
	/* 0x3A */ DAT_TYPE_7_3A, // One of the NONAME entry types
	/* 0x3B */ DAT_TYPE_0_IMPERIAL_TROOPER,
	/* 0x3C */ DAT_TYPE_0_REBEL_PILOT,
	/* 0x3D */ DAT_TYPE_0_CIVILIAN,
	/* 0x3E */ DAT_TYPE_0_ASSAULT_BOAT,
	/* 0x3F */ DAT_UNKNOWN_3F,
	/* 0x40 */ DAT_TYPE_0_WAVE_SKIMMER,
	/* 0x41 */ DAT_TYPE_0_REBEL_TURRET,
	/* 0x42 */ DAT_TYPE_0_TALORAAN_TURRET,
	/* 0x43 */ DAT_TYPE_0_CLOUD_CAR,
	/* 0x44 */ DAT_TYPE_0_IMPERIAL_PLATFORM, // Not sure what exactly this is, maybe the floating platforms in the Taloraan level
	/* 0x45 */ DAT_UNKNOWN_45,
	/* 0x46 */ DAT_TYPE_0_46, // Moving NPC spawn position?
	/* 0x47 */ DAT_TYPE_0_ATPT,
	/* 0x48 */ DAT_TYPE_0_BOSS_HUT, // Only shows up once, named "MOFF SEERDON"
	/* 0x49 */ DAT_TYPE_0_WORLD_DEVASTATOR_GUN,
	/* 0x4A */ DAT_TYPE_0_POWER_GENERATOR,
	/* 0x4B */ DAT_TYPE_0_4B, // Large generic buildings?
	/* 0x4C */ DAT_TYPE_0_POWER_UP,
	/* 0x4D */ DAT_TYPE_0_HEAVY_RAPTOR_SHUTTLE,
	/* 0x4E */ DAT_TYPE_7_4E, // One of the NONAME entry types
	/* 0x4F */ DAT_TYPE_0_EXHAUST_PORT, // Death Star exhaust port
	/* 0x50 */ DAT_TYPE_0_B_SOLDIER, // Not present in any DAT files
	/* 0x51 */ DAT_TYPE_2_LAVA_FARTS, // Only used by the Raid on Sullust level
	/* 0x52 */ DAT_TYPE_0_52, // One of the NONAME entry types
	/* 0x53 */ DAT_NUM_SUBTYPES,
};
```

`func_80047B70` is somehow involved with the [Item Groups](#item-groups).
