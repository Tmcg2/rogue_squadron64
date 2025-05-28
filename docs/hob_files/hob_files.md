# HOB Files

I don't know what `HOB` stands for, although I speculate the `OB` part stands for `Object`.
THese files appear to contain what I would call "models", although I'm sure there's a more accurate technical term for it.
`HOB` files can contain multiple different models, and they reference entries in [HMT files](/docs/hmt_files/hmt_files.md).

[ReRogue's spec file](https://github.com/dpethes/rerogue/blob/master/doc/file_hob_spec.txt) is a good reference here.
This file will mostly serve as a more verbose specification.

I will say that while I use the same vocabulary as ReRogue, I dont understand most of it.
This is mainly in reference to the `meshdef*` names.
I don't know what a "meshdef" is supposed to be and I don't get what separates type 0 from type 1.

It would greatly behoove you to reference the [XWing HOB file](/docs/hob_files/xwing_hob) that I've annotated while reading the spec.
There's also a [destroyed buildings HOB file](/docs/hob_files/dest_hob) and a [radar dish HOB file](/docs/hob_files/radar_dish_hob) as well.
The destoryed buildings file is special because it has multiple objects in it.
Those other 2 files are not anywhere as well annotated though.

As a general warning: HOB files aren't really amenable to being broken up into C structs, too many of their parts have variable sizes.
So I will provide the best struct-like format that I can, but bear in mind that it won't be perfect.

Unless otherwise noted, offsets in a HOB file are relative to the file itself.

`HOB` files can be split into 2 major parts: the `object` list and the `face` list(s).

## Object Entries

The object entry list (or, really, the entire file) starts with a tiny header-like block

```cpp
struct object_section_header {
    uint16_t object_count;
    uint16_t padding;
    uint32_t object_section_size; // not really sure what this is actually
};
```

`object_count` is exactly what it sounds like.

`object_section_size` INCLUDES the size of the `object_section_header`.

This is, naturally, followed by `object_count` objects.

```cpp
// Some members aren't fully understood, so they may be wrong. Reader beware
struct object_entry {
    /* 0x00 */ char object_name[16];
    /* 0x10 */ uint32_t meshdef0_offset;
    /* 0x14 */ uint32_t meshdef0_prelude_offset;
    /* 0x18 */ uint32_t meshdef1_prelude_offsets[4];
    /* 0x28 */ uint32_t unknown_offsets[3];
    /* 0x34 */ float afloat;
    /* 0x38 */ uint16_t ashort;
    /* 0x3A */ uint16_t bshort;
    /* 0x3C */ float afloat_list[7];
    /* 0x58 */ uint32_t header_end_offset;
    /* 0x5C */ float bfloat_list[6];
}; // size 0x74
```

`object_name` is exactly what it sounds like.

`meshdef0_offset` is an offset to the list of [meshdef0](#meshdef0) entries for the object.

`meshdef0_prelude_offset` is an offset to the [meshdef0 prelude](#meshdef0-preulde) for the object.

`meshdef1_prelude_offsets` is an offset to the list of [meshdef1 preuldes](#meshdef1-preulde) entries for the object.
Game code suggests there are up to 4 such offsets per object, although its unclear what that indicates about the object in question.

NOTE: if more than 1 `meshdef1_prelude_offsets` is set, all preludes except the first one come AFTER the [header end block](#header-end).

Each of the `unknown_offsets` entries point to slightly different entry types.
All sections of this have a word (32 bits) of zero's after them, indicating that the section is over.
In the event that an `unknown` section has no entries, it'll contain just terminating zero-word.

I don't really get what `header_end_offset` is supposed to be.
It seems to point to a place just short of the end of the object's data.
The true end of a given object's data is indicated by a full word of `FF` bytes, but that is usually a few bytes after `header_end_offset`.

## Meshdef Preludes

After all the `object_entry`'s come the meshdef0/1 prelude(s).

### Meshdef0 Preulde

```cpp
struct meshdef0_prelude_entry {
    uint32_t flags; // ???
    uint32_t meshdef0_offset;
};

struct meshdef0_prelude {
    uint16_t meshdef0_count;
    uint16_t meshdef1_count;
    struct meshdef0_prelude_entry ents[meshdef0_count];
};
```

### Meshdef1 Preulde

```cpp
struct meshdef1_prelude {
    uint16_t meshdef0_count;
    uint16_t meshdef1_count;
    uint32_t meshdef1_offsets_mostly[AAA];
    uint32_t zero_word;
};
```

`meshdef1_offsets_mostly` contains a couple zero-words, with only `meshdef1_count` non-zero entries.
Speculatively, it could be that meshdef1's come in groups, and each group has a zero-word to separate it from the other meshdef1 groups.

## Unknown Offsets

After the preludes come the actual `unknown_offset` blocks.

### Unknown Offset Type 0

There is a block of this type at file offset `0xC8` in the annotated HOB file.

```cpp
struct unknown_offset0_entry {
    char name[8]; // no null terminator???
    uint16_t some_index;
    uint32_t zero_word;
};
```

### Unknown Offset Type 1

There is a block of this type at file offset `0xE0` in the annotated HOB file.

```cpp
struct unknown_offset1_entry {
    uint32_t meshdef1_offset;
    char name[6];
    uint16_t some_index;
    uint32_t zero_word;
};
```

### Unknown Offset Type 2

There is a block of this type at file offset `0x120` in the annotated HOB file.

```cpp
struct unknown_offset2_entry {
    char name [6];
    uint8_t flags; // maybe??? maybe its a meshdef0 index instead???
    uint8_t some_count;
    float float_blocks[some_count][9];
    uint32_t zero_word;
}
```

Note the variable size of the entries in this block.

## Header End

There is a block of this type at file offset `0x440` in the annotated HOB file.
Finally, there's the header end.
As already mentioned, I don't really get what this section is.
It appears to be bunch of floats and then a terminating all-F-word.

## Meshdef0

```cpp
struct meshdef0 {
    /* 0x00 */ uint32_t next_meshdef0_offset;
    /* 0x04 */ uint32_t prev_meshdef0_offset;
    /* 0x08 */ uint32_t unknown_meshdef0_offset0;
    /* 0x0C */ uint32_t unknown_meshdef0_offset1;
    /* 0x10 */ uint32_t meshdef1_offset;
    /* 0x14 */ float big_block_o_floats[14];
    /* 0x4C */ float big_block_o_floats2[14];
}; // size = (without big_block_o_floats2) 0x4C, otherwise 0x84
```

`meshdef0`s can seemingly have a linked list like structure, hence the `next` and `prev` entries.

The `unknown_meshdef0_offset` entries are enigmas at the moment.
They are definitely meshdef0 offsets, but what puropse they serve is unknown.
The are commonly used in the game code to handle recursive calls for some functions, but beyond that their purpose is unknown.
Maybe they're some form of sub-mesh?

`meshdef1_offset` is exactly what it sounds like.

`big_block_o_floats` is actuallly a little ambiguous, I'm assuming its all floats but it could potentially have other stuff hidden in there.
Also the size of it is a little speculative.
`func_80056EB0` suggests that `meshdef0`'s should have a size of `0x4C`, but that leaves 14 floats unaccounted for in the HOB files themselves.
I don't know what to make of that.

## Meshdef1

The provided C struct represents (or at least is close to) what the game code uses when dealing with meshdef1.
However, in the HOB files proper there is an extra word just before the struct, at offset "-4" in the struct, if that makes any sense.
It appears to be an `end_of_facegroup` offset.

Its unclear why its not part of the meshdef1 proper.
Or, if it is part of the meshdef1, its very unclear why all meshdef1 offsets would point to a spot immediately after it.

```cpp
struct meshdef1 {
    /* 0x00 */ uint32_t next_meshdef1_offset;
    /* 0x04 */ uint32_t prev_meshdef1_offset;
    /* 0x08 */ uint32_t unk08;
    /* 0x0C */ uint32_t unk0C;
    /* 0x10 */ uint32_t unk10;
    /* 0x14 */ uint32_t vertex_counts[2];
    /* 0x1C */ float some_float;
    /* 0x20 */ uint32_t facegroup_offset;
    /* 0x24 */ uint32_t vertext_offsets[2];
    /* 0x2C */ float big_block_o_floats[12];
}; // size = 0x5C
```

`meshdef1`s can seemingly have a linked list like structure, hence the `next` and `prev` entries.

They also can have up to 2 sets of vertices associated with them, hence there being multiple `vertex_counts` and `vertex_offsets`.

`vertex_counts` is the count of vertices in each vertex list.

`vertex_offsets` is the offset to a given vertex list.

`big_block_o_floats` is actuallly a little ambiguous, I'm assuming its all floats but it could potentially have other stuff hidden in there.

## Facegroup

```cpp
struct facegroup {
    uint32_t next_facegroup;
    uint32_t prev_facegroup;
    uint32_t face_offset;
    uint32_t face_count;
};
```

`next_facegroup` and `prev_facegroup` are somewhat speculative, as I've never seen them set to non-zero values.
However, [func_800587F0.c](/docs/hmt_files/func_800587F0.c) suggests they're link-list style offsets/pointers to other facegroups.

`face_offset` is what it sounds like, a file offset to faces in this face group.

`face_count` is also what it sounds like, a count of faces in the face group.

## Face

Faces are a bit hard to specify as they have variable sizes which can only be deduced after doing a partial read of the face itself.
So you'll see several memebers in the C struct whose sizes or even presence is variable.

```cpp
struct face {
    uint32_t flags;
    struct {
        uint32_t ??                        : 2;
        uint32_t face_size                 : 6; // multiply by 4 to get the actual size
        uint32_t vertex_indices_offset1    : 6; // multiply by 4 to get the actual offset
        uint32_t vertex_color_offset       : 6; // multiply by 4 to get the actual offset
        uint32_t vertex_indices_offset2    : 6; // multiply by 4 to get the actual offset
        uint32_t texture_coordiante_offset : 6; // multiply by 4 to get the actual offset
    } stuffed_data;
    uint16_t material_index;
    uint16_t padding;
    uint16_t vertex_indices[2][4]; // there may only be set of indices, see flags
    uint32_t vertex_colors[3/4]; // these may not be present at all, there can be 3 or 4 entries, see flags
    uint32_t texture_coordinates[3/4]; // these may not be present at all, there can be 3 or 4 entries,  see flags
}
```

### Flags

| Flag       | Usage |
| ---------- | ----- |
| 0x00000002 | Might be unique to player craft HOBs, indicates there's a second set of vertex indices |
| 0x00000004 | Face has U/V texture coordinates |
| 0x00000008 | If set, this face is a quad. If unset, its a tri. |
| 0x00000010 | If set, this face has vertex colors. If unset, it only has a single face color |
| 0x00000020 | If set there's some color associated with the face |
| 0x00000040 | If set there's a second set of vertex indices |

All other flags have unknown use.

I don't really get what's up with there being 2 flags that indicate there's a second set of vertex indices.
Presumably they actually indicate 2 different things that just so happen to both require a second set of vertices.

`stuffed_data` contains a bunch of different information about the face all shoved into a bit field.
Note that the offsets found in here are relative to the face itself, not the HOB file.

`material_index` is a reference to the HMT file associated with this HOB file.
Each material from the HMT file is given a number and that number is what is being referenced here.

`vertex_indices` is a set of indices into the vertex list referenced by `vertex_offset` from the [meshdef1](#meshdef1).
If the face is a tri (rather than a quad) the 4th index will always be 0.

`vertex_colors` is a set of RGBA32 colors.
I've never see a face that has JUST a face color, but game code suggests that in such case there is exactly 1 color.

`texture_coordinates` is a set of fixed-point u/v coordinates used for the texture mapping.
16 bits for u, 16 bits for v.
You'll need to scale these down by `4096` to get a number between `0` and `1`.

## Vertices

Finally, there's the vertex lists.

```cpp
struct vertex {
    uint16_t x;
    uint16_t y;
    uint16_t z;
    uint16_t padding;
};
```

## Extraction

I made a utility that kind-of-sort-of extract models from HOB files, [extract_hob.py](/docs/hob_files/extract_hob.py).
It is written in Python instead of C because I wanted it to use it in tandem with [Blender](https://www.blender.org/) to view the models after extraction.
To be honest, it doesn't make much sense to me reading over it so I doubt its going to be easy for anyone else to understand it.

## Game Code Stuff

[load_hmt_and_hob.c](/docs/hmt_files/load_hmt_and_hob.c) is the function that DMA's and does initial parsing of the HOB file.
The big thing that it's doing is converting offsets in the file into pointers.

[func_800587F0.c](/docs/hmt_files/func_800587F0.c) is doing much the same but for the [facegroup](#facegroup) and [face](#face) entries.

[func_800587F0.c](/docs/hmt_files/func_800587F0.c) appears to be scaling(?) the RGB channels of the vertex colors in each face (the alpha channel is left alone).
It also implies that in the case where there's only a face color (as opposed to per-vertex colors) then there will be exactly one entry in the `vertex_colors` of the face.
Or, at least, there's only 1 entry that matters.
