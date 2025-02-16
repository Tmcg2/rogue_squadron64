# The Data Blob

The beginning of the data blob is at ROM address 0x144340.
From here on that address will be referred to as `data_start`.
The blob is where most (if not all) assets for the game reside.
Textures, image, sounds, songs, models, text, and probably a couple other things.
The ReRogue project has a decent explanation of what it looks like here `https://github.com/dpethes/rerogue/blob/master/doc/file_data_spec.txt`.
I'll a more verbose explanation here, using of C styled structs to specify the structure of the blob.

## Data Blob Structure

The blob starts with a list of what I'll call `segment_header`s.

```cpp
struct segment_header {
	char     segment_name[16];
	uint32_t unk10;
	uint32_t unk14;
	uint32_t unk18; // If this is non-zero the data block for this header won't get DMA'd. I don't know why that would ever be useful
	uint32_t data_offset;
}; // size: 0x20 bytes
```

Currently there are only 2 of these: `data` and `dbg_data`.

The `data_offset` value is relative to `data_start` and points to the beginning of the data for that segment.
The data blocks themselves have a tiny header too, henceforth called `block_header`s.

```cpp
struct block_header {
	union {
		uint32_t block_size;
		uint32_t manifest_offset;
	};
	uint16_t flags;
	uint16_t manifest_size;
}; // size: 0x8 bytes
```

`block_size` is the size of the data block (including the header!) in bytes.
You could also call this value `manifest_offset`, which is relative to `data_start + segment_header.data_offset`.
Alternatively, you can say the offset is relative to the `block_header`'s location.
It indicates where the manifest for the data block can be found.

`manifest_size` indicates the size in bytes of the manifest.
After the header is the raw data for the entire block.

The manifest is exactly what it sounds like.
A series of structs that explain the structres of the raw data for a given data block.

```cpp
struct manifest_entry {
	uint32_t asset_offset;
	uint32_t decompressed_size;
	uint32_t compressed_size;
	uint8_t  flags;
	uint8_t  unk0D;
	uint16_t directory_size;
	char     asset_name[16];
}; // size: 0x20 bytes
```

`asset_offset` is relative to the `block_header`'s location.
So, `data_start + segment_header.data_offset + manifest_entry.asset_offset`.

`compressed_size` is interesting, there's a couple things to note about it.
If its `-1`/`0xFFFFFFFF`, that indicates that the asset is uncompressed (what I'll call "raw" for now).
Otherwise, the asset in question is compressed with `zlib`.
The `compressed_size` is also a litte larger than necessary.
For example, if the asset size after deflation was 596 bytes, it would padded out the 599 bytes (1 less than the next multiple of 4).
I don't know why they do this.

For flags, bit 7 (0x80) indicates that the `manifest_entry` is really a directory, not a single asset.
Other flag bits are checked in the code but none are ever set so I don't know what they're meant to do yet.

`directory_size` is only ever non-zero if the directory bit flag is set, and it is the size in bytes of all the `manifest_entry`s (including itself!) in the directory.
You can get a count of `manifest_entry`s in the directoy (including the directory entry itself!) by dividing this value by 32.

## Asset Information

All compressed assets were compressed using `zlib`, and you can decompress them using the `pigz` utility.
Based on very VERY minor testing on my part, you can also use `pigz` to compress the the assets again in a way that will match their in-ROM state.

```bash
pigz --best -z filename_here
```

There are several asset types, I will do my best to explain them here.
For some files their type is easy to deduce by just looking at their name, for other you'll have to decompress them and investigate them manually.

### HOB

[ReRogue's version](https://github.com/dpethes/rerogue/blob/master/doc/file_hob_spec.txt)
These appear to be 3D models.
See the [HOB file specification](#/docs/hob_files/hob_files.md) for more details.

### HMT

[ReRogue's version](https://github.com/dpethes/rerogue/blob/master/doc/file_hmt_spec.txt)
These appear to be texture collections.
In 3D modeling parlance I think textures are more commonly called "materials".
See the [HMT file specification](#/docs/hmt_files/hmt_files.md) for more details.

### Various Image files

File types like:
- ANM
- IMG
- SPR
- TM

Are all invividual or collections of [images](/docs/image_files/image_files.md)

### Files like atpt_walk/start/stop

Presumably these are 3D model animations, although I have no idea what their internal structure is like.

### PAL

Presumably a pallette of some variety, although I can't say that with certainty.

### SND

Presumably short for "sound", I have to assume these are Musyx related files.

### SNG

Presumably short for "song", like [SND](#snd) I have to assume these are Musyx related.

### Speech file

The "speech" file is presumably where all the voice acted audio is stored.
Again, probably Musyx related.
This file is huge and I have no idea where to begin with it.

### HMP

Probably short for "height map", see [ReRogue's spec file](https://github.com/dpethes/rerogue/blob/master/doc/file_hmp_spec.txt).
I've done some manual verification on a couple of these files to ensure they match up with ReRogue, but I don't know how to extract them into, say, Blender for viewing.
[load_level_hmp.c](/docs/data_blob/load_level_hmp.c) is deeply involved with HMP files, doing some form of initial parsing of the file.

### DAT

Appears to contain a variety of things: spawn locations, splines, event triggers, and a couple other things that I can't readily identify.
See the [DAT File](/docs/dat_files/dat_file.md) specification for more information.

### GVM

I have no idea what these files are, I don't think the game ever uses them.

### TEX

Tiles in the [HMP](#hmp) files have a "texmap" entry, I believe they are referencing entires in this file.
I don't understand what the entries in this file are though.
[load_level_hmp.c](/docs/data_blob/load_level_hmp.c) does something with these files, although the details are entirely lost on me.

### INTRO/EXTRO

Don't know what these are, they start with strings the look like `F5KKc:\project\rogue\FrontEnd\Cuts\intro\anim_id0.wrl` and `F5KKc:\project\rogue\FrontEnd\Cuts\extro\anim_id0.wrl`.
I've looked for information on `wrl` files but nothing I found really fit with what I was looking at.

### JFIF

JFIF is short for "JPEG File Interchange Format".
As best as I can tell it is an ancient version of JPEG, most commonly appearing in the ROM in raw form.

### DEM

Presumably short for "demo", these are input replay files.
They have entries that can be described with the following C struct:

```cpp
struct demoInput {
    float    duration;
    uint16_t button;
    int8_t   stick_x;
    int8_t   stick_y;
}; // size: 0x8 bytes
```

`button`, `stick_x`, and `stick_y` are all named after their counterpart in the `OSContPad` struct found in `libultra`.
I'm not entirely sure that `duration` is truly the duration of the input.
In practive its always the value `1/30` or `1/20`, which kind of lines up with a one-per-frame setup.
But modifying this value never had any perceptible effects on the demos.

### TXT

Text files, things like menus and subtitles.
The [text file specification](/docs/text_files/text_files.md) has more information.

## Extracting Assets

I have written a utility, [zz_addresses.py](/docs/data_blob/zz_addresses.py) that:
1) Extracts the assets from the primary `data` segment
2) Outputs a [data_subsegment.yaml](/docs/data_blob/data_subsegments.yaml) file that is kind-of-sort-of a `splat` compatible set of entries for each asset

For #1, the assets are extracted as-is from the ROM and placed in a directory named `data_block`.
if this directory does not exist the uitility WILL NOT create it.
Assets are named after the `asset_name` from their `manifest_entry` and are prefixed with their ROM address.
Assets that are compresses are suffixed with `.zz`, while uncompressed files are suffixed with `.raw`.

Note: files that are compressed (`.zz` files) are raw `zlib` streams, they are NOT `gzip` compatible.
You have to use the `pigz` utility to decompress them, like so:

```bash
# -d -> decompress
# -k -> keep the compressed file
pigz -d -k data_block/<filename_here>.zz
```

To re-compress the file you can do:

```bash
# --best -> Compression level 9
# -z -> compress to zlib format, not gzip
pigz --best -z data_block<filename_here>
```

In regard to #2, `splat` allows end user to provide their own bespoke segment types, so its plausible that I could write an extractor for `zz` types.
But that would be a lot of work, and I don't really care to do that right now.
A potential would-be-nice for the future would be adding types that look something like `zz:HMT`, `zz:HOB`, and `zz:DEM`.
Composite types essentially, telling splat first how/if it should decompress the asset and then specifies what exactly the asset is.
But again, I don't really care to do this at the moment.

## Game Code stuff

### Getting a handle to a manifest entry

[find_manifest_entry.c](/docs/data_blob/find_manifest_entry.c) is the function used by the game to get a `manifest_entry` pointer to a specific asset.
It takes 2 arguments, the first being an index into an array of structures that I don't really understand (`D_80110AA0`).
The 2nd is the name of the asset its searching for.
For example, you could give it `pl_crafts/xwing_HOB` to find the X-Wing's HOB file.

Its also possible (in theory at least) to have entries in `D_80110AA0` contain a path in them that is prepended to all search names.
So, plausibly, you could stuff `pl_crafts` into an entry in `D_80110AA0` and then your search string would only need to be `xwing_HOB`.
I don't think this ever happens in the game though, at least not that I've ever seen.

### Other assorted functions

[get_asset_size_simple.c](/docs/data_blob/get_asset_size_simple.c) and [get_asset_size_extra.c](/docs/data_blob/get_asset_size_extra.c) both search for an asset and then return it's size (compressed if its compressed, decompressed otherwise), although `get_asset_size_simple` is more "vanilla" than `get_asset_size_extra`.
