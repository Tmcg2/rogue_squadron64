# HMT Files

I don't know what `HMT` stands for, although speculatively the `MT` is short for `material`.
[ReRogue's spec file](https://github.com/dpethes/rerogue/blob/master/doc/file_hmt_spec.txt) is a good reference, this file will serve as a more verbose specification.

HMT files are actually really similar to [image files](/docs/image_files/image_files.md).
In some ways, you could describe them as being collections of images with some extra data attached to each image, which is the `material` part.
The nuance here is that not all `materials` have a texture (image) associated with them.
I don't know why, I'm sure there's some technical reason but its completely lost on me.

## Specification

Please referece the [Naboo Starfigher HMT file](/docs/hmt_files/naboo_starfighter.hmt) while reading this specification.
Its an HMT file that I have partially annotated to (hopefully) make clear how its put together.

### Header

I feel a little silly for calling this a header, but I'm going to just to keep things simple.
The header looks like this C struct:

```cpp
struct hmt_header {
	uint16_t material_count;
	uint16_t padding;
	uint32_t texture_offset;
};
```

`material_count` is what the name implies.
It is a count of materials in the file.

`texture_offset` is an offset to the texture (image) part of the file.
The offset is relative to the start of the file.

### Materials

Then we get the `material_entry`s, which look like the following C struct:

```cpp
struct material_entry {
	union {
		// 1 = has texture, 2 = no texture
    	/* 0x00 */ uint16_t material_type;
    	/* 0x00 */ uint16_t material_flags;
	};
    /* 0x02 */ uint16_t texture_index;
    /* 0x04 */ float misc_float; // Pupose unknown
    /* 0x08 */ float one; // Always(?) 1.0f
    /* 0x0C */ uint32_t zero; // Always(?) 0
    /* 0x10 */ uint32_t alwaysa; // Always(?) 0x0a000000, purpose unknown
    /* 0x14 */ char material_name[16];
}; // size 0x24
```

Its unclear whether the first member is a `type` or a set of `flags`.
In [load_hmt_and_hob.c](/docs/hmt_files/load_hmt_and_hob.c), it accessed in a flag-like manner.
If this value is `1` (or it has the LSB set) there is a texture associate with the material.
Otherwise, there's no texture.
In all cases that I've seen, that also means this value `2`.

`texture_index` is only non-zero if there's a texture associated with the material.

I don't know what the `float`s or the `uint32_t`s are.

`material_name` is exactly what the tin says.

### Textures

The start of the texture section is a single 32 bit word, `texture_count`.
As the name suggests, its a count of textures in the file.

After this come all the textures in sequence.
The textures are nearly identical to [full header images](/docs/image_files/image_files.md).
The only difference is that HMT images don't have an `image_size` member.

```cpp
struct texture_entry {
	uint32_t pixel_offset[8]; // relative to the start of the file
	uint32_t palette_offset; // relative to the start of the file
	uint32_t image_name_offset; // relative to the start of the file
	uint16_t image_pixel_width;
	uint16_t image_pixel_height;
	uint8_t  always_1; // May not always be 1, but I personally have only seen 1
	uint8_t  bit_depth;
	union {
		struct {
			uint16_t flags      : 12;
			uint16_t image_type :  4;
		};
		uint16_t flags_type;
	};
	uint32_t transparency_color;
}; // size = 0x34
```

An interesting technical note: in [image files](/docs/image_files/image_files.md), the `image_name` is usually after all the image data, while in HMT textures the `texture_name` usually before the image data.

## Extracting Images

I have made a utility that can extract the textures from HMT files called [extract_hmt.c](/docs/hmt_files/extract_hmt.c).
Really its just [extract_full_header_img.c](/docs/image_files/extract_full_header_img.c) with some extra management of the `material_entry` stuff.

!! IMPORTANT NOTE !! [extract_hmt.c](/docs/hmt_files/extract_hmt.c) is much, much messier than its image file compatriot.
I spent a lot of time correcting [extract_full_header_img.c](/docs/image_files/extract_full_header_img.c) as I wrote its documentation, while [extract_hmt.c](/docs/hmt_files/extract_hmt.c) was left behind.
So user beware, it may not work everywhere.

## Game Code Stuff

[load_hmt_and_hob.c](/docs/hmt_files/load_hmt_and_hob.c) is deeply involved in the handling of HMT files.
One of the big things its doing is translating the various offsets to pointers.
