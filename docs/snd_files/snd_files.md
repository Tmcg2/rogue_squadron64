# SND Files

There are 4 files with `_SND` suffix:

- `pool_SND`
- `proj_SND`
- `sdir_SND`
- `samp_SND`

They are loaded in `func_800663B0` and are further parsed in `func_80097518`.
They're probably sound related but beyond that I have not idea what to make for them.

[snd_file_dump.c](snd_file_dump.c) reads each file and kind-of-sort-of annotates each one.
The interpretation of the files is based on code found in `func_80097518`.
While that interpretation is far from complete, it does a good job describing the "shape" of each file.

## pool_SND

There are 4 major sections in `pool_SND`.
The file starts with 4 words, each one an offset to where each major section starts.

Each major section is comprised of subsections.
Each subsection starts with 2 words of information: a `size` and an `id`.
After that there are `size - 8` bytes of data.
I don't currently know how to further parse the data.
When the size of a subsection is `0xFFFFFFFF`, the major section is done.

The `id`s of these subsections are of interest.
The top nibble of each `id` is unique for each major section.

| Section | ID style |
| --- | --- |
| 0 | 0x0... |
| 1 | 0xC... |
| 2 | 0x4... |
| 3 | 0x8... |

This is notable because ceratin parts of `proj_SND` make reference to these `id`s, so there's some sort of inter-file linkage occuring.

## proj_SND

Each major section of `proj_SND` has a header.
The exact size of the header is variable as it depends on which `type` the section is.

```cpp
struct proj_section_header {
    /* 0x00 */ u32 size;
    /* 0x04 */ u16 id;
    /* 0x06 */ u16 type;
    /* 0x08 */ u32 sub_section_offsets[XXX];
}; // size = variable, depends on type
```

If `type` is `0` there are 8 `sub_section_offsets`.
If its `1` there's 6.
5 of those segments are common between each `type`.
The other sections are unique.

The offsets found in `sub_section_offsets` are relative to `sub_section_offsets` itself.
They ARE NOT file relative.

### Common Sub-Segments

The common sub-segments are arrays of 2 byte entries.
These entries are `id`s referencing entries found in [pool_SND](#pool_snd) or [sdir_SND](#sdir_snd).
An entry of `0xFFFF` indicates that the sub-segment is over.

| proj_SND Sub-Segment | |
| --- | --- |
| 0 | pool_SND 0 |
| 1 | sdir_SND |
| 2 | pool_SND 1 |
| 3 | pool_SND 2 |
| 4 | pool_SND 3 |

### Type 0 Special Sub-Segments

#### Type 0 Sub-Segment 5

```cpp
struct type0_subsegment5_type {
    /* 0x00 */ u32 unk00;
    /* 0x04 */ u8  unk04;
    /* 0x05 */ u8  unk05;
    // 2 bytes of padding
}; // size = 0x8
```

Section ends when an entire entry (including the padding) is set to `0xFF`

#### Type 0 Sub-Segment 6

```cpp
struct type0_subsegment6_type {
    /* 0x00 */ u32 unk00;
    /* 0x04 */ u8  unk04;
    /* 0x05 */ u8  unk05;
    // 2 bytes of padding
}; // size = 0x8
```

Section ends when an entire entry (including the padding) is set to `0xFF`

#### Type 0 Sub-Segment 7

This segment starts with a word of data whose purpose is unknown.
After that word there are exactly 16 data entries.

```cpp
struct type0_subsegment7_type {
    /* 0x00 */ u32 unk00;
    /* 0x04 */ u8  unk04;
    // 3 bytes of padding
}; // size = 0x8
```

### Type 1 Special Sub-Segment

#### Type 1 Sub-Segment 5

This segment starts with a 2 byte value indicating the number of entries that it has.
The entries are word aligned, so there's 2 bytes of padding after the entry count.

```cpp
struct type1_subsegment5_type {
    /* 0x00 */ u16 id;
    /* 0x00 */ u16 unk02;
    /* 0x00 */ u32 unk04; // this should probably be split into 4 separate bytes, but whatever
    /* 0x00 */ u8  unk08;
    // 3 bytes of padding
}; // size = 0xC
```

## sdir_SND

This file is just a bunch of `0x18` byte sized entries.

```cpp
struct sdir_type {
    u16 id;
    u16 unk02;
    u32 unk04; // seems like this could be an offset into samp_SND
    u32 unk08;
    u32 unk0C;
    u32 unk10;
    u32 unk14;
}; // size = 0x18
```

The `u32`s in that struct are likely not accurate.
In reality they're probably `u8` or `u16` entries, but I've been able to identify them as such.

The file is done when an `id` of `0xFFFF` is read.
