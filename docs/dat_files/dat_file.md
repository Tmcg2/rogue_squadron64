# DAT File Specification

DAT files contain a variety of data for playable levels and certain menu locations (the hanger and the briefing room for example).
They are initially parsed by [func_80046784](func_80046784.c).
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

## Type 0 Intenals

```cpp
struct item_type_0 {
	uint16_t sub_type;
	uint16_t padding;
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

## Type 2 Intenals

Since `Attack on Mos Eisley` doesn't have any of these, I have no clue what they look like.
Presumably they aren't that different from all the others.

## Type 3 Intenals

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

## Type 6 Intenals

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

## Type 7 Intenals

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
