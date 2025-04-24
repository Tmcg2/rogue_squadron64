#include <spng.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <endian.h>
#include <string.h>
#include <assert.h>
#include <math.h>

/*
 * KNOWN ISSUES
 * If 2 assets have the same description string they overwrite each other, see wrld_vsanim as an example
 */

#define MAX_FILENAME 256
char *png_output_format = "./output_pngs/%s.png";

// Generic X bit to Y bit scaling function
// Works both directions, X does not have to be larger than Y
uint32_t scale_x_y(uint32_t value, uint8_t x, uint8_t y) {
    // No scaling needed
    if (x == y) {
        return value;
    }

    // Makes no sense to convert to/from 0 bits, but we'll return 0 just to return something
    // I suppose this would be a case where in a better implementation, we'd set `errno` to something
    // meaningful
    if ((x == 0) || (y == 0)) {
        return 0;
    }

    // Currently only support scaling up/down from/to 32 bit numbers
    // I suppose this would be a case where in a better implementation, we'd set `errno` to something
    // meaningful
    if ((x > 32) || (y > 32)) {
        // Gotta do something here...
    }

    // Upscaling from 1 bit, return either the maximum value or 0
    if (x == 1) {
        return value ? (1 << y) - 1 : 0;
    }

    // Downscaling to 1 bit is fuzzier
    // Do we only return 1 if we're at max value or do we want to do something more akin to rounding?
    // The former is (kindof) complimentary to how upscaling from 1 bit works, so we'll do that
    // I suppose in a more complete implemenation you could have a `flags` argument that could control this behaviour
    if (y == 1) {
        return value == ((1 << x) - 1) ? 1 : 0;
    }

    // Generic Downscale
    // Right shift the (x - y) least significant bits out of the number
    if (x > y) {
        return value >> (x - y);
    }

    // Generic Upscale
    // This loop creates floor(y/x) copies of `value` pushed as far left as necessary
    // For a 5 bit number `abcde`  upscaling to  8 bits, this loop will generate `abcde???`
    // For a 6 bit number `abcdef` upscaling to  8 bits, this loop will generate `abcdef??`
    // For a 3 bit number `abc`    upscaling to 10 bits, this loop will generate `abcabcabc?`
    // For a 5 bit number `abcde`  upscaling to 12 bits, this loop will generate `abcdeabcde??`
    uint32_t temp = 0;
    while (x < y) {
        y -= x;
        temp |= (value << y);
    }

    // Then, place the (y % x) most significant bits at the bottom of the scaled value
    // Continuing the examples from above:
    // 5 to  8 ends with `abcdeabc`
    // 6 to  8 ends with `abcdefab`
    // 3 to 10 ends with `abcabcabca`
    // 5 to 12 ends with `abcdeabcdeab`
    return temp | (value >> (x - y));
}

enum image_types {
    // Both CI types are plain RGB, no alpha channel
    CI4 = 0,
    CI8 = 1,
    RGBA5551 = 2,
    RGBA32 = 3, // Truecolor with alpha, bit-depth of 8
    // Consult header's bit_depth to diffirentiate between 4bpp and 8bpp
    // 0 = 4bpp
    // 1 = 8bpp
    GRAYSCALE4_8 = 4,
    GRAYSCALE16 = 5,
};

#define CI4_PAL_SIZE 16
#define CI8_PAL_SIZE 256

struct rgb {
    uint8_t red;
    uint8_t green;
    uint8_t blue;
};

struct rgba {
    uint8_t red;
    uint8_t green;
    uint8_t blue;
    uint8_t alpha;
};

struct full_image_header {
    uint32_t image_size;
    uint32_t pixel_offset[8];
    uint32_t palette_offset;
    uint32_t image_name_offset;
    uint16_t image_pixel_width;
    uint16_t image_pixel_height;
    uint8_t  always_1;
    uint8_t  bit_depth;
    uint16_t flags_type;
    uint32_t transparency_color;
};

struct image_context {
    uint32_t image_size;
    uint32_t pixel_offset;
    uint32_t palette_offset;
    uint16_t image_pixel_width;
    uint16_t image_pixel_height;
    uint8_t  bit_depth;
    uint16_t flags_type;
    uint32_t transparency_color;

    uint32_t pixel_count;
    char image_name[MAX_FILENAME];
};

void export_ci4(FILE *source_file, struct image_context *image) {
    int        ret;
    uint32_t   raw_size;
    FILE      *png_file;
    uint8_t   *raw_data;
    char       png_filename[MAX_FILENAME] = {0};
    struct rgb palette[CI4_PAL_SIZE];

    spng_ctx        *ctx  = NULL;
    struct spng_ihdr ihdr = {0};
    struct spng_plte plte = {0};
    struct spng_trns trns = {0};

    printf("Extracting CI4 image %s\n", image->image_name);

    raw_size = image->image_size;

    ihdr.bit_depth = 4;
    ihdr.width = image->image_pixel_width;
    ihdr.height = image->image_pixel_height;
    ihdr.color_type = SPNG_COLOR_TYPE_INDEXED;

    fseek(source_file, image->palette_offset, SEEK_SET);
    fread(palette, sizeof(struct rgb), CI4_PAL_SIZE, source_file);

    plte.n_entries = CI4_PAL_SIZE;
    if (image->flags_type & 0x4000) {
        trns.n_type3_entries = CI4_PAL_SIZE;
        for (int i = 0; i < CI4_PAL_SIZE; i++) {
            plte.entries[i].red   = palette[i].red;
            plte.entries[i].green = palette[i].green;
            plte.entries[i].blue  = palette[i].blue;
            if ((plte.entries[i].red   != ((image->transparency_color & 0xFF000000) >> 0x18)) ||
                (plte.entries[i].green != ((image->transparency_color & 0x00FF0000) >> 0x10)) ||
                (plte.entries[i].blue  != ((image->transparency_color & 0x0000FF00) >> 0x08))) {
                trns.type3_alpha[i] = 0xFF;
            } else {
                trns.type3_alpha[i] = 0x00;
            }
        }
    } else {
        for (int i = 0; i < CI4_PAL_SIZE; i++) {
            plte.entries[i].red   = palette[i].red;
            plte.entries[i].green = palette[i].green;
            plte.entries[i].blue  = palette[i].blue;
        }
    }

    raw_data = malloc(raw_size);
    fseek(source_file, image->pixel_offset, SEEK_SET);
    fread(raw_data, sizeof(uint8_t), raw_size, source_file);

    snprintf(png_filename, MAX_FILENAME, png_output_format, image->image_name);
    png_file = fopen(png_filename, "wb");

    ctx = spng_ctx_new(SPNG_CTX_ENCODER);

    spng_set_png_file(ctx, png_file);

    ret = spng_set_ihdr(ctx, &ihdr);
    if (ret != SPNG_OK) {
        printf("\tset_ihdr: %d: %s\n", ret, spng_strerror(ret));
    }

    ret = spng_set_plte(ctx, &plte);
    if (ret != SPNG_OK) {
        printf("\tset_plte: %d: %s\n", ret, spng_strerror(ret));
    }

    if (image->flags_type & 0x4000) {
        ret = spng_set_trns(ctx, &trns);

        if (ret != SPNG_OK) {
            printf("\tset_trns: %d: %s\n", ret, spng_strerror(ret));
        }
    }

    ret = spng_encode_image(ctx, raw_data, raw_size, SPNG_FMT_RAW, SPNG_ENCODE_FINALIZE);

    spng_ctx_free(ctx);
    fclose(png_file);
    free(raw_data);
}

void export_ci8(FILE *source_file, struct image_context *image) {
    int        ret;
    uint32_t   raw_size;
    FILE      *png_file;
    uint8_t   *raw_data;
    char       png_filename[MAX_FILENAME] = {0};
    struct rgb palette[CI8_PAL_SIZE];

    spng_ctx        *ctx  = NULL;
    struct spng_ihdr ihdr = {0};
    struct spng_plte plte = {0};
    struct spng_trns trns = {0};

    printf("Extracting CI8 image %s\n", image->image_name);

    raw_size = image->image_size;

    ihdr.bit_depth = 8;
    ihdr.width = image->image_pixel_width;
    ihdr.height = image->image_pixel_height;
    ihdr.color_type = SPNG_COLOR_TYPE_INDEXED;

    fseek(source_file, image->palette_offset, SEEK_SET);
    fread(palette, sizeof(struct rgb), CI8_PAL_SIZE, source_file);

    plte.n_entries = CI8_PAL_SIZE;
    for (int i = 0; i < CI8_PAL_SIZE; i++) {
        plte.entries[i].red   = palette[i].red;
        plte.entries[i].green = palette[i].green;
        plte.entries[i].blue  = palette[i].blue;
    }
    if (image->flags_type & 0x4000) {
        trns.n_type3_entries = CI8_PAL_SIZE;
        for (int i = 0; i < CI8_PAL_SIZE; i++) {
            if ((plte.entries[i].red   != ((image->transparency_color & 0xFF000000) >> 0x18)) ||
                (plte.entries[i].green != ((image->transparency_color & 0x00FF0000) >> 0x10)) ||
                (plte.entries[i].blue  != ((image->transparency_color & 0x0000FF00) >> 0x08))) {
                trns.type3_alpha[i] = 0xFF;
            } else {
                trns.type3_alpha[i] = 0x00;
            }
        }
    }

    raw_data = malloc(raw_size);
    fseek(source_file, image->pixel_offset, SEEK_SET);
    fread(raw_data, sizeof(uint8_t), raw_size, source_file);

    snprintf(png_filename, MAX_FILENAME, png_output_format, image->image_name);
    png_file = fopen(png_filename, "wb");

    ctx = spng_ctx_new(SPNG_CTX_ENCODER);

    spng_set_png_file(ctx, png_file);

    ret = spng_set_ihdr(ctx, &ihdr);
    if (ret != SPNG_OK) {
        printf("\tset_ihdr: %d: %s\n", ret, spng_strerror(ret));
    }

    ret = spng_set_plte(ctx, &plte);
    if (ret != SPNG_OK) {
        printf("\tset_plte: %d: %s\n", ret, spng_strerror(ret));
    }

    if (image->flags_type & 0x4000) {
        ret = spng_set_trns(ctx, &trns);

        if (ret != SPNG_OK) {
            printf("\tset_trns: %d: %s\n", ret, spng_strerror(ret));
        }
    }

    ret = spng_encode_image(ctx, raw_data, raw_size, SPNG_FMT_RAW, SPNG_ENCODE_FINALIZE);

    spng_ctx_free(ctx);
    fclose(png_file);
    free(raw_data);
}

void export_rgba5551(FILE *source_file, struct image_context *image) {
    int          ret;
    uint32_t     raw_size;
    uint32_t     converted_size;
    struct rgb   trans_color, raw_color;
    FILE        *png_file;
    uint16_t    *raw_data;
    uint8_t     *converted_data;
    struct rgba *converted;
    char         png_filename[MAX_FILENAME] = {0};

    spng_ctx        *ctx  = NULL;
    struct spng_ihdr ihdr = {0};
    struct spng_trns trns = {0};

    printf("Extracting RGBA5551 image %s\n", image->image_name);

    raw_size = image->image_size;

    ihdr.bit_depth = 8;
    ihdr.width = image->image_pixel_width;
    ihdr.height = image->image_pixel_height;

    if (image->flags_type & 0x8000) {
        ihdr.color_type = SPNG_COLOR_TYPE_TRUECOLOR_ALPHA;
        converted_size = sizeof(struct rgba) * image->pixel_count;
    } else {
        ihdr.color_type = SPNG_COLOR_TYPE_TRUECOLOR;
        converted_size = sizeof(struct rgb) * image->pixel_count;
    }

    raw_data = malloc(raw_size);
    fseek(source_file, image->pixel_offset, SEEK_SET);
    fread(raw_data, sizeof(uint8_t), raw_size, source_file);

    converted_data = malloc(converted_size);

    if (image->flags_type & 0x8000) {
        for (uint32_t i = 0; i < image->pixel_count; i++) {
            raw_data[i] = be16toh(raw_data[i]);
            converted_data[(4*i) + 0] = scale_x_y((raw_data[i] & 0x7C00) >> 10, 5, 8);
            converted_data[(4*i) + 1] = scale_x_y((raw_data[i] & 0x03E0) >>  5, 5, 8);
            converted_data[(4*i) + 2] = scale_x_y((raw_data[i] & 0x001F) >>  0, 5, 8);
            // Alpha is the leading bit????
            converted_data[(4*i) + 3] = scale_x_y((raw_data[i] & 0x8000) >> 15, 1, 8);
        }
    } else {
        for (uint32_t i = 0; i < image->pixel_count; i++) {
            raw_data[i] = be16toh(raw_data[i]);
            converted_data[(3*i) + 0] = scale_x_y((raw_data[i] & 0x7C00) >> 10, 5, 8);
            converted_data[(3*i) + 1] = scale_x_y((raw_data[i] & 0x03E0) >>  5, 5, 8);
            converted_data[(3*i) + 2] = scale_x_y((raw_data[i] & 0x001F) >>  0, 5, 8);
        }
    }

    snprintf(png_filename, MAX_FILENAME, png_output_format, image->image_name);
    png_file = fopen(png_filename, "wb");

    ctx = spng_ctx_new(SPNG_CTX_ENCODER);

    spng_set_png_file(ctx, png_file);

    ret = spng_set_ihdr(ctx, &ihdr);
    if (ret != SPNG_OK) {
        printf("\tset_ihdr: %d: %s\n", ret, spng_strerror(ret));
    }

    if (image->flags_type & 0x4000) {
        trns.red   = (image->transparency_color & 0xFF000000) >> 0x18;
        trns.green = (image->transparency_color & 0x00FF0000) >> 0x10;
        trns.blue  = (image->transparency_color & 0x0000FF00) >> 0x08;

        ret = spng_set_trns(ctx, &trns);

        if (ret != SPNG_OK) {
            printf("\tset_trns: %d: %s\n", ret, spng_strerror(ret));
        }
    }

    ret = spng_encode_image(ctx, converted_data, converted_size, SPNG_FMT_RAW, SPNG_ENCODE_FINALIZE);

    if (ret != SPNG_OK) {
        printf("\tencode_image: %d: %s\n", ret, spng_strerror(ret));
    }

    spng_ctx_free(ctx);
    fclose(png_file);
    free(converted_data);
    free(raw_data);
}

void export_rgba32(FILE *source_file, struct image_context *image) {
    int      ret;
    uint32_t raw_size;
    FILE    *png_file;
    uint8_t *raw_data;
    char     png_filename[MAX_FILENAME] = {0};

    spng_ctx        *ctx  = NULL;
    struct spng_ihdr ihdr = {0};
    struct spng_trns trns = {0};

    printf("Extracting RGBA32 image %s\n", image->image_name);

    raw_size = image->image_size;

    ihdr.bit_depth = 8;
    ihdr.width = image->image_pixel_width;
    ihdr.height = image->image_pixel_height;

    if (image->flags_type & 0x8000) {
        ihdr.color_type = SPNG_COLOR_TYPE_TRUECOLOR_ALPHA;
    } else {
        ihdr.color_type = SPNG_COLOR_TYPE_TRUECOLOR;
    }

    raw_data = malloc(raw_size);
    fseek(source_file, image->pixel_offset, SEEK_SET);
    fread(raw_data, sizeof(uint8_t), raw_size, source_file);

    snprintf(png_filename, MAX_FILENAME, png_output_format, image->image_name);
    png_file = fopen(png_filename, "wb");

    ctx = spng_ctx_new(SPNG_CTX_ENCODER);
    spng_set_png_file(ctx, png_file);

    spng_set_ihdr(ctx, &ihdr);

    if (image->flags_type & 0x4000) {
        trns.red   = (image->transparency_color & 0xFF000000) >> 0x18;
        trns.green = (image->transparency_color & 0x00FF0000) >> 0x10;
        trns.blue  = (image->transparency_color & 0x0000FF00) >> 0x08;

        ret = spng_set_trns(ctx, &trns);

        if (ret != SPNG_OK) {
            printf("\tset_trns: %d: %s\n", ret, spng_strerror(ret));
        }
    }

    ret = spng_encode_image(ctx, raw_data, raw_size, SPNG_FMT_RAW, SPNG_ENCODE_FINALIZE);

    spng_ctx_free(ctx);
    fclose(png_file);
    free(raw_data);
}

void export_grayscale4_8(FILE *source_file, struct image_context *image) {
    int      ret;
    uint32_t raw_size;
    uint32_t converted_size;
    FILE    *png_file;
    uint8_t *converted_data;
    uint8_t *raw_data;
    char     png_filename[MAX_FILENAME] = {0};

    spng_ctx        *ctx  = NULL;
    struct spng_ihdr ihdr = {0};
    struct spng_trns trns = {0};

    if (image->bit_depth == 0) {
        printf("Extracting Greyscale4 image %s\n", image->image_name);
    } else {
        printf("Extracting Greyscale8 image %s\n", image->image_name);
        // This flag should always be set if we're dealing with 8 bit greyscale
        assert(image->flags_type & 0x8000);
    }

    raw_size = image->image_size;

    ihdr.bit_depth = 8;
    ihdr.width = image->image_pixel_width;
    ihdr.height = image->image_pixel_height;

    if (image->bit_depth == 1) {
        ihdr.color_type = SPNG_COLOR_TYPE_GRAYSCALE_ALPHA;
        // Each pixel takes 2 bytes: one for the grey sample and one for the alpha sample
        converted_size = sizeof(uint8_t) * 2 * image->pixel_count;
        // The converted data should take double the amount of space as the raw data
        assert(converted_size == (raw_size * 2));
    } else {
        ihdr.color_type = SPNG_COLOR_TYPE_GRAYSCALE;
        // Each pixel takes 1 byte
        converted_size = sizeof(uint8_t) * image->pixel_count;
        // The converted data should take double the amount of space as the raw data
        assert(converted_size == (raw_size * 2));
    }

    raw_data = malloc(raw_size);
    fseek(source_file, image->pixel_offset, SEEK_SET);
    fread(raw_data, sizeof(uint8_t), raw_size, source_file);

    converted_data = malloc(converted_size);

    if (image->bit_depth == 1) {
        for (int i = 0; i < image->pixel_count; i++) {
            converted_data[(2*i) + 0] = scale_x_y((raw_data[i] & 0xF0) >> 4,  4, 8);
            converted_data[(2*i) + 1] = scale_x_y((raw_data[i] & 0x0F) >> 0,  4, 8);
        }
    } else {
        for (int i = 0; i < image->pixel_count; i++) {
            if ((i % 2) == 0){
                converted_data[i] = scale_x_y((raw_data[i/2] & 0xF0) >> 4,  4, 8);
            } else {
                converted_data[i] = scale_x_y((raw_data[i/2] & 0x0F) >> 0,  4, 8);
            }
        }
    }

    snprintf(png_filename, MAX_FILENAME, png_output_format, image->image_name);
    png_file = fopen(png_filename, "wb");

    ctx = spng_ctx_new(SPNG_CTX_ENCODER);

    spng_set_png_file(ctx, png_file);

    ret = spng_set_ihdr(ctx, &ihdr);
    if (ret != SPNG_OK) {
        printf("\tset_ihdr: %d: %s\n", ret, spng_strerror(ret));
    }

    if (image->flags_type & 0x4000) {
        // Use of a transparency color implies a bit depth of 4
        assert(image->bit_depth == 0);

        trns.gray = (image->transparency_color & 0xF0000000) >> 0x1C;

        ret = spng_set_trns(ctx, &trns);

        if (ret != SPNG_OK) {
            printf("\tset_trns: %d: %s\n", ret, spng_strerror(ret));
        }
    }

    ret = spng_encode_image(ctx, converted_data, converted_size, SPNG_FMT_RAW, SPNG_ENCODE_FINALIZE);

    if (ret != SPNG_OK) {
        printf("\tencode_image: %d: %s\n", ret, spng_strerror(ret));
    }

    spng_ctx_free(ctx);
    fclose(png_file);
    free(converted_data);
    free(raw_data);
}

void export_grayscale16(FILE *source_file, struct image_context *image) {
    int      ret;
    uint32_t raw_size;
    FILE    *png_file;
    uint8_t *raw_data;
    char     png_filename[MAX_FILENAME] = {0};

    spng_ctx        *ctx  = NULL;
    struct spng_ihdr ihdr = {0};
    struct spng_trns trns = {0};

    printf("Extracting Greyscale16 image %s\n", image->image_name);

    raw_size = image->image_size;

    ihdr.bit_depth = 8;
    ihdr.width = image->image_pixel_width;
    ihdr.height = image->image_pixel_height;

    if (image->flags_type  & 0x8000) {
        ihdr.color_type = SPNG_COLOR_TYPE_GRAYSCALE_ALPHA;
    } else {
        ihdr.color_type = SPNG_COLOR_TYPE_GRAYSCALE;
    }

    raw_data = malloc(raw_size);
    fseek(source_file, image->pixel_offset, SEEK_SET);
    fread(raw_data, sizeof(uint8_t), raw_size, source_file);

    snprintf(png_filename, MAX_FILENAME, png_output_format, image->image_name);
    png_file = fopen(png_filename, "wb");

    ctx = spng_ctx_new(SPNG_CTX_ENCODER);
    spng_set_png_file(ctx, png_file);

    spng_set_ihdr(ctx, &ihdr);

    if (image->flags_type & 0x4000) {
        trns.gray = (image->transparency_color & 0xFF000000) >> 0x18;

        spng_set_trns(ctx, &trns);
    }

    ret = spng_encode_image(ctx, raw_data, raw_size, SPNG_FMT_RAW, SPNG_ENCODE_FINALIZE);

    spng_ctx_free(ctx);
    fclose(png_file);
    free(raw_data);
}

void export_png(FILE *source_file, struct image_context *image) {
    switch((image->flags_type & 0x000F)) {
    case CI4:
        export_ci4(source_file, image);
        break;
    case CI8:
        export_ci8(source_file, image);
        break;
    case RGBA5551:
        export_rgba5551(source_file, image);
        break;
    case RGBA32:
        export_rgba32(source_file, image);
        break;
    case GRAYSCALE4_8:
        export_grayscale4_8(source_file, image);
        break;
    case GRAYSCALE16:
        export_grayscale16(source_file, image);
        break;
    default:
        break;
    }
}

void parse_asset_header(struct full_image_header *header) {
    header->image_size          = be32toh(header->image_size);
    for (int i = 0; i < 8; i++) {
        header->pixel_offset[i] = be32toh(header->pixel_offset[i]);
    }
    header->palette_offset      = be32toh(header->palette_offset);
    header->image_name_offset   = be32toh(header->image_name_offset);
    header->image_pixel_width   = be16toh(header->image_pixel_width);
    header->image_pixel_height  = be16toh(header->image_pixel_height);
    header->flags_type          = be16toh(header->flags_type);
    header->transparency_color  = be32toh(header->transparency_color);

    // if ((header->image_pixel_width  % 2) == 1) header->image_pixel_width++;
    // if ((header->image_pixel_height % 2) == 1) header->image_pixel_height++;
}

void extarct_all_images(FILE *source_file) {
    long end;
    long start;

    fseek(source_file, 0, SEEK_END);
    end = ftell(source_file);
    fseek(source_file, 0, SEEK_SET);

    do {
        struct image_context image = {0};
        struct full_image_header header = {0};

        start = ftell(source_file);

        fread(&header, sizeof(struct full_image_header), 1, source_file);
        parse_asset_header(&header);

        // This is way less involved than detecting its type and doing some math
        if (header.flags_type & 0x0C00) {
            image.image_size     = header.pixel_offset[1]   - header.pixel_offset[0];
        } else {
            image.image_size     = header.image_name_offset - header.pixel_offset[0];
        }
        // Convert realtive offsets to absolute offsets
        image.pixel_offset       = header.pixel_offset[0] + start + 4;
        image.palette_offset     = header.palette_offset  + start + 4;
        image.image_pixel_width  = header.image_pixel_width;
        image.image_pixel_height = header.image_pixel_height;
        image.bit_depth          = header.bit_depth;
        image.flags_type         = header.flags_type;
        image.transparency_color = header.transparency_color;

        image.pixel_count        = image.image_pixel_width * image.image_pixel_height;

        fseek(source_file, header.image_name_offset + start + 4, SEEK_SET);
        fread(image.image_name, sizeof(uint8_t), header.image_size - header.image_name_offset, source_file);

        export_png(source_file, &image);

        if (header.flags_type & 0x0C00) {
            // The scale calculation I'm doing is a little screwy.
            // I'm using image_size and the type information to deduce the number of pixels
            // In the extra image, and then compare that against the number of pixels in the primary image
            int scale;

            image.image_size = header.image_name_offset - header.pixel_offset[1];

            image.pixel_offset = header.pixel_offset[1] + start + 4;
            if (header.flags_type & 0x0800) {
                image.flags_type = GRAYSCALE4_8;
                image.bit_depth = 0;
                // 2 pixels per byte in the extra image
                scale = sqrtf(image.pixel_count / (image.image_size * 2));
            } else {
                image.flags_type = GRAYSCALE16;
                // 1 pixel per 2 bytes in the extra image
                scale = sqrtf(image.pixel_count / (image.image_size / 2));
            }
            image.image_pixel_width  /= scale;
            image.image_pixel_height /= scale;

            image.pixel_count = image.image_pixel_width * image.image_pixel_height;
            strcat(image.image_name, "_gs");
            export_png(source_file, &image);
        }
        // Files with single images usually end exactly at the name's null-terminator
        // In fact, the asset_sizes in those files appear to be byte-exact for the asset, no padding involved
        // Multi-image files by contrast are padded up to the nearest 4 byte boundary
        fseek(source_file, ((header.image_size + 3) & ~0x3) + start + 4, SEEK_SET);
    // < since some files have names that don't neatly end at the 4 byte boundary, so the previous seek can over-shoot the file end
    } while (ftell(source_file) < end);
}

int main(int argc, char *argv[]) {
    FILE *source_file;

    source_file = fopen(argv[1], "rb");

    if (source_file == NULL) {
        printf("Failed to open the source file\n");
        return -1;
    }

    extarct_all_images(source_file);

    fclose(source_file);
    return 0;
}
