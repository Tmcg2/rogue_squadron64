# Image File Specification

I want to highlight that the image file specification from the [ReRouge project](https://github.com/dpethes/rerogue/blob/master/doc/file_image_spec.txt) is a very good resource.
This document is, really, just a more verbose version of that one.

Most but not all images in the game meet this specification.
The ones that don't are JFIF (ancient JPEG format) files, and are raw (uncompressed).

A single image file may contain multiple images.

[func_8001EB24](func_8001EB24.c) is a function deeply involved of the parsing of these images.
It very noticeably has a switch/case inside for [image types](#image-types) and it clearly checks for various [flags](#flags).

Image data is prefaced by a header, either "full" or "partial".
I have written 2 utilities to extract images from files with either header type, named [extract_full_header_img.c](extract_full_header_img.c) and [extract_partial_header_img.c](extract_partial_header_img.c).
They aren't perfect, but they should work for most files I've tried them with.
You'll need to install the [spng](https://libspng.org/) library and link against it when compiling the utilities.

```bash
gcc -g -o extract_full_header_img extract_full_header_img.c -lspng -lm
gcc -g -o extract_partial_header_img extract_partial_header_img.c -lspng
```

## Header Structs

### Full Header

Example files from the [Data Blob](/docs/data_blob/data_blob.md) include: `ionex2_IMGS`

!! WARNING !!
In its current state, [extract_full_header_img.c](extract_full_header_img.c) doesn't fully work for the listed example.
For one, that example is using the `0x080` flag which complicates matters greatly.
For two, that example isn't getting extracted right.

```cpp
// Multi-byte values are big-endian
struct full_image_header {
	uint32_t image_size;
	uint32_t pixel_offset[8];
	uint32_t palette_offset;
	uint32_t image_name_offset;
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
};
```

### Partial Header

Example files from the [Data Blob](/docs/data_blob/data_blob.md) include: `m_bronze/m_silver/m_gold` and `yellow_bnt`

Author's note to self: all those images have the `0x800` flag set, whereas I don't think I've seen either `0x800` or `0x400` set in full header images with this type. Very peculiar, wonder if that's indicative of anything.

```cpp
// Multi-byte values are big-endian
struct partial_image_header {
	union {
		struct {
			uint16_t flags      : 12;
			uint16_t image_type :  4;
		};
		uint16_t flags_type;
	};
	uint8_t  always_0; // May not always be 0, but I personally have only seen 0
	uint8_t  bit_depth;
	uint16_t image_pixel_width;
	uint16_t image_pixel_height;
	uint32_t transparency_color;
};
```

## Image Size

`image_size` is the size in bytes of both the header and the image data itself.
Counter-intuitively, `image_size` does not include the 4 bytes used to store the size itself.

## Pixel Offsets

Offests are NOT relative to the beginning of the file.
They are relative to the point AFTER `image_size`, which is very frustrating.

[load_hmt_and_hob.c](/docs/image_files/load_hmt_and_hob.c) isn't related to image files directly, infact its more focused on [HMT](/docs/hmt_files/hmt_files.md) and [HOB](/docs/hob_files/hob_files.md) files.
HMT files do have image-like entries in them though and code in this function suggests that there's potentially 8 pixel offsets.
I don't know what multiple non-zero entries would imply, but the game's code suggests that its possible.

## Palette Offset

`palette_offset` is zero if the image type in question does not use a palette at all.

## Image Name Offset

What it says on the tin: offset in bytes to reach the string with the image's name.

Note: Files with multiple images in them are NOT guaranteed to have unique names for each image.
The asset file from the [Data Blob](/docs/data_blob/data_blob.md) named `wrld_vsanim` is one such file.
It might be the only such file, but I can't say that with certainty.

Note: partial header images do not have names.

## Image Pixel Width and Height

What is says on the tin: the width and height of the image measured in pixels.

## Bit Depth

`bit_depth` is a bit strange.

Its only relevant for the Greyscale 4/8 images.
0 indicates that there's 4 bits per pixel.
1 indicates that there's 8 bits per pixel.

Its values do match what's mentioned in the ReRogue project, but the value is never referenced in the game's code.
Instead, bit depth is usually inferred from the `image_type` and `flags`.
You can see this in [func_8001EB24](func_8001EB24.c), specifically in case 4.
It checks for flags `0x800` and `0x400` and depending on which flag is detected, it treats the data slightly differently.
If flag `0x800` is set, its 8 bits per pixel.
If flag `0x400` is set, its 4 bits per pixel.

## Flags

I've only been able to identify 4 of the 12 possible flags, although I'm not unaware of the other 8 being used or checked anywhere.
Treating the flags as a 12 bit number:

### 0x800

Alpha value is embedded with the colors.

[func_8001EB24](func_8001EB24.c) suggests that CI4 and CI8 images don't use this flag at all.
And I don't think I've seen any assets that suggest otherwise.

### 0x400

Alpha value is determined by comparing the color to `transparency_color`.

[func_8001EB24](func_8001EB24.c) suggests that CI4 and CI8 images don't use this flag at all.
Which is strange, because there are some images that use this flag and respecting it makes the image extraction better.
`trp_anm_run` and `trp_anm_sht` from the [Data Blob](/docs/data_blob/data_blob.md) are good examples of this.
According to the palette, they have a bunch of grey-ish pixels in them but if you respect this flag you find that they become transparent.

`r_pilot_anm` is another really interesting example, because while it has a transparency color, only one image has its palette setup right to use it.
All other palettes have a similare but different color in that position, which means they don't become transparent even if you respect this flag.

### 0x080

In addition to the data for the given [image type](#image-types), there's data for a Greyscale 4/8 bit image.
Refer to [func_8001F954](func_8001F954.c) line 96.

### 0x040

In addition to the data for the given [image type](#image-types), there's data for a Greyscale 16 bit image.
Refer to [func_8001F954](func_8001F954.c) line 96.

## Image Types

### 0: Color Index, 4 bits per pixel (CI4)

Colors in the palette are in RGB format, 8 bits per channel.
There are 16 colors in the palette.
`transparency_color` is an RGBA32 color, although the alpha part of that color (if its even set) should be ignored.

### 1: Color Index, 8 bits per pixel (CI8)

Colors in the palette are in RGB format, 8 bits per channel.
There are 256 colors in the palette.
`transparency_color` is an RGBA32 color, although the alpha part of that color (if its even set) should be ignored.

### 2: RGBA5551

`transparency_color` is an RGBA32 color, although the alpha part of that color (if its even set) should be ignored.

!! WARNING !!

See annotations for this image type in [func_8001EB24](func_8001EB24.c) (case 2).
The code present in that case suggests that the the colors in this image type would be more accurately described as ARGB 1555.
More investigation is needed for this, really.

### 3: RGBA, 8 bits per channel (RGBA32)

`transparency_color` is an RGBA32 color, although the alpha part of that color (if its even set) should be ignored.

### 4: Greyscale, 4 or 8 bits per pixel

If `bit_depth` is 0, this is Greyscale 4 bits per pixel.
If `bit_depth` is 1, this is Greyscale 8 bits per pixel.

The game's code however infers the bit depth by looking at the `flags`, rather than querying this value.

If flag `0x800` is set, the image is Greyscale 8 bits per pixel, with the alpha co-located with the data.
4 bits for the color, 4 bits for the alpha.

If that flag is unset, the image is Greyscale 4 bits per pixel.
If flag `0x400` is additionally set, the top 4 bits of `transparency_color` define the transparency color.
Otherwise, there is no alpha data to be extracted.

### 5: Greyscale, 16 bits per pixel

Much the same as Greyscale 4/8 bits per pixel, just with 16 bits.
I not 100% confident in my understanding of this image type.
The code I have in [extract_full_header_img.c](extract_full_header_img.c) treats it as if the `0x800` flag is always set (alpha embedded with the color), but then it also sets the transparency color?
That doesn't make sense, and almost certainly isn't accurate for every Greyscal 16 bits per pixel image in the game.

## Transparency Color

The exact format of this color is somewhat flexible, although its almost always RGBA32.
The only time its not is when the image type is Greyscale 4 bits per pixel AND the `0x400` flag has been set, in which cause the top 4 bits of a 32 bit word are the alpha color.
