#include <spng.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <endian.h>

/*
 * KNOWN ISSUES
 * If 2 assets have the same description string they overwrite each other, see wrld_vsanim as an example
 */

#define PNG_OUTPUT_FORMAT "./output_pngs/%s.png"

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

struct greyscalealpha4 {
    uint8_t grey_sample : 4;
    uint8_t alpha_sample : 4;
};

struct asset_header {
    uint32_t asset_size; // Really, the size of the asset minus the 4 bytes used for this header entry
    // All offsets are relative to the point AFTER asset_size
    uint32_t pixel_offset;
    // In reality `pixel_offset` should be an array with size [8], but I've only seen 2 instances of multiple pixel offsets so I'm going to simplify my life a little
    uint32_t extra_offset;
    uint32_t palette_offset; // Ought be to 0 for non-palette image types
    uint32_t description_string_offset;
    uint16_t width, height;
    uint8_t bit_depth; // 0 = 4, 1 = 8, only matters for palette/greyscale image types
    /*
    * The next 2 flags don't matter to CI assets
    * If neither of the next 2 flags are set, the alpha value is always maxed out (not alpha, basically)
    * 0x8000: Alpha value is embedded with the color values
    * 0x4000: Alpha value is either 0 or max value, depends on whether the color value matches `trans_color` or not
    * 0x2000: Unknown
    * 0x1000: Unknown
    * 0x0800: Has an extra Greyscale4/8 image after the primary image
    * 0x0400: Has an extra Greyscale16  image after the primary image
    * 0x0200: Unknown
    * 0x0100: Unknown
    * 0x0080: Unknown
    * 0x0040: Unknown
    * 0x0020: Unknown
    * 0x0010: Unknown
    */
    uint16_t flags;
    uint8_t  type;
    uint32_t trans_color;

    // Calculated values, not part of the header found in the files
    uint32_t description_string_size;
    uint32_t img_byte_size;
};

void export_ci4(FILE *source_file, struct asset_header *header) {
    int        ret;
    FILE      *png_file;
    uint8_t   *raw_data;
    uint8_t   *img_data;
    char      *description_string;
    char       png_filename[256];
    struct rgb palette[CI4_PAL_SIZE];

    spng_ctx        *ctx  = NULL;
    struct spng_ihdr ihdr = {0};
    struct spng_plte plte = {0};
    struct spng_trns trns = {0};

    ihdr.width = header->width;
    ihdr.height = header->height;
    ihdr.color_type = SPNG_COLOR_TYPE_INDEXED;
    ihdr.bit_depth = 4;

    fread(palette, sizeof(struct rgb), CI4_PAL_SIZE, source_file);

    plte.n_entries = CI4_PAL_SIZE;
    if (header->flags & 0x4000) {
        trns.n_type3_entries = CI4_PAL_SIZE;
        for (int i = 0; i < CI4_PAL_SIZE; i++) {
            plte.entries[i].red   = palette[i].red;
            plte.entries[i].green = palette[i].green;
            plte.entries[i].blue  = palette[i].blue;
            if ((plte.entries[i].red   != ((header->trans_color & 0xFF000000) >> 0x18)) ||
                (plte.entries[i].green != ((header->trans_color & 0x00FF0000) >> 0x10)) ||
                (plte.entries[i].blue  != ((header->trans_color & 0x0000FF00) >> 0x08))) {
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

    raw_data = malloc(header->img_byte_size);
    fread(raw_data, sizeof(uint8_t), header->img_byte_size, source_file);

    img_data = raw_data;

    description_string = malloc(header->description_string_size);
    fread(description_string, sizeof(char), header->description_string_size, source_file);

    if ((header->description_string_size % 4) != 0) {
        fseek(source_file, 4 - (header->description_string_size % 4), SEEK_CUR);
    }

    snprintf(png_filename, sizeof(png_filename), PNG_OUTPUT_FORMAT, description_string);
    printf("%s\n", png_filename);
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

    if (header->flags &0x4000) {
        ret = spng_set_trns(ctx, &trns);

        if (ret != SPNG_OK) {
            printf("\tset_trns: %d: %s\n", ret, spng_strerror(ret));
        }
    }

    ret = spng_encode_image(ctx, img_data, header->img_byte_size, SPNG_FMT_RAW, SPNG_ENCODE_FINALIZE);

    spng_ctx_free(ctx);
    fclose(png_file);
    free(description_string);
    free(raw_data);
}

void export_ci8(FILE *source_file, struct asset_header *header) {
    int        ret;
    FILE      *png_file;
    uint8_t   *raw_data;
    uint8_t   *img_data;
    char      *description_string;
    char       png_filename[256];
    struct rgb palette[CI8_PAL_SIZE];

    spng_ctx        *ctx  = NULL;
    struct spng_ihdr ihdr = {0};
    struct spng_plte plte = {0};
    struct spng_trns trns = {0};

    ihdr.width = header->width;
    ihdr.height = header->height;
    ihdr.color_type = SPNG_COLOR_TYPE_INDEXED;
    ihdr.bit_depth = 8;

    fread(palette, sizeof(struct rgb), CI8_PAL_SIZE, source_file);

    plte.n_entries = CI8_PAL_SIZE;
    if (header->flags & 0x4000) {
        trns.n_type3_entries = CI8_PAL_SIZE;
        for (int i = 0; i < CI8_PAL_SIZE; i++) {
            plte.entries[i].red   = palette[i].red;
            plte.entries[i].green = palette[i].green;
            plte.entries[i].blue  = palette[i].blue;
            if ((plte.entries[i].red   != ((header->trans_color & 0xFF000000) >> 0x18)) ||
                (plte.entries[i].green != ((header->trans_color & 0x00FF0000) >> 0x10)) ||
                (plte.entries[i].blue  != ((header->trans_color & 0x0000FF00) >> 0x08))) {
                trns.type3_alpha[i] = 0xFF;
            } else {
                trns.type3_alpha[i] = 0x00;
            }
        }
    } else {
        for (int i = 0; i < CI8_PAL_SIZE; i++) {
            plte.entries[i].red   = palette[i].red;
            plte.entries[i].green = palette[i].green;
            plte.entries[i].blue  = palette[i].blue;
        }
    }

    raw_data = malloc(header->img_byte_size);
    fread(raw_data, sizeof(uint8_t), header->img_byte_size, source_file);

    img_data = raw_data;

    description_string = malloc(header->description_string_size);
    fread(description_string, sizeof(char), header->description_string_size, source_file);

    if ((header->description_string_size % 4) != 0) {
        fseek(source_file, 4 - (header->description_string_size % 4), SEEK_CUR);
    }

    snprintf(png_filename, sizeof(png_filename), PNG_OUTPUT_FORMAT, description_string);
    printf("%s\n", png_filename);
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

    if (header->flags &0x4000) {
        ret = spng_set_trns(ctx, &trns);

        if (ret != SPNG_OK) {
            printf("\tset_trns: %d: %s\n", ret, spng_strerror(ret));
        }
    }

    ret = spng_encode_image(ctx, img_data, header->img_byte_size, SPNG_FMT_RAW, SPNG_ENCODE_FINALIZE);

    spng_ctx_free(ctx);
    fclose(png_file);
    free(description_string);
    free(raw_data);
}

void export_rgba5551(FILE *source_file, struct asset_header *header) {
    int          ret;
    uint32_t     img_size;
    uint32_t     raw_size;
    struct rgb   trans_color, raw_color;
    FILE        *png_file;
    char        *description_string;
    uint8_t     *img_data;
    uint16_t    *raw_data;
    struct rgba *converted;
    char         png_filename[256];

    spng_ctx        *ctx  = NULL;
    struct spng_ihdr ihdr = {0};
    struct spng_trns trns = {0};

    ihdr.width = header->width;
    ihdr.height = header->height;
    ihdr.bit_depth = 8;
    if (header->flags & 0x8000) {
        ihdr.color_type = SPNG_COLOR_TYPE_TRUECOLOR_ALPHA;

        img_size = header->width * header->height * 4;
        raw_size = header->width * header->height * 2;
    } else {
        ihdr.color_type = SPNG_COLOR_TYPE_TRUECOLOR;

        if (header->flags & 0x4000){
            trns.red   = (header->trans_color & 0xFF000000) >> 0x18;
            trns.green = (header->trans_color & 0x00FF0000) >> 0x10;
            trns.blue  = (header->trans_color & 0x0000FF00) >> 0x08;
        }

        img_size = header->width * header->height * 3;
        raw_size = header->width * header->height * 2;
    }

    raw_data = malloc(sizeof(uint8_t) * raw_size);
    fread(raw_data, sizeof(uint8_t), raw_size, source_file);

    img_data = malloc(sizeof(uint8_t) * img_size);

    if (header->flags & 0x8000) {
        for (uint32_t i = 0; i < (header->width * header->height); i++) {
            raw_data[i] = be16toh(raw_data[i]);
            img_data[4*i]     = scale_x_y((raw_data[i] & 0x7C00) >> 10, 5, 8);
            img_data[4*i + 1] = scale_x_y((raw_data[i] & 0x03E0) >>  5, 5, 8);
            img_data[4*i + 2] = scale_x_y((raw_data[i] & 0x001F) >>  0, 5, 8);
            img_data[4*i + 3] = scale_x_y((raw_data[i] & 0x8000) >> 15, 1, 8);
        }
    } else {
        for (uint32_t i = 0; i < (header->width * header->height); i++) {
            raw_data[i] = be16toh(raw_data[i]);
            img_data[3*i]     = scale_x_y((raw_data[i] & 0x7C00) >> 10, 5, 8);
            img_data[3*i + 1] = scale_x_y((raw_data[i] & 0x03E0) >>  5, 5, 8);
            img_data[3*i + 2] = scale_x_y((raw_data[i] & 0x001F) >>  0, 5, 8);
        }
    }

    /*
    These checks should technically exist in EVERY image extraction handler, but I've only ever seen this flag for RGBA551 images,
    specifically `ionexp_IMGS` and `ionex2_IMGS`.
    We're checking to see if there's an extra data for a greyscale 4/8/16 image after the expected image data.
    If there is, we'll seek over it for now. In the future we'll have to try and actually extract it.

    An argument to `func_8001F954.c` controls with width/height of the extra image. Its not always the same width/height of the normal image
    */
    if (header->flags & 0x0C00) {
        fseek(source_file, header->description_string_offset - header->extra_offset, SEEK_CUR);
    }

    description_string = malloc(header->description_string_size);
    fread(description_string, sizeof(char), header->description_string_size, source_file);

    if ((header->description_string_size % 4) != 0) {
        fseek(source_file, 4 - (header->description_string_size % 4), SEEK_CUR);
    }

    snprintf(png_filename, sizeof(png_filename), PNG_OUTPUT_FORMAT, description_string);
    printf("%s\n", png_filename);
    png_file = fopen(png_filename, "wb");

    ctx = spng_ctx_new(SPNG_CTX_ENCODER);

    spng_set_png_file(ctx, png_file);

    ret = spng_set_ihdr(ctx, &ihdr);
    if (ret != SPNG_OK) {
        printf("\tset_ihdr: %d: %s\n", ret, spng_strerror(ret));
    }

    if (header->flags &0x4000) {
        ret = spng_set_trns(ctx, &trns);

        if (ret != SPNG_OK) {
            printf("\tset_trns: %d: %s\n", ret, spng_strerror(ret));
        }
    }

    ret = spng_encode_image(ctx, img_data, img_size, SPNG_FMT_RAW, SPNG_ENCODE_FINALIZE);

    if (ret != SPNG_OK) {
        printf("\tencode_image: %d: %s\n", ret, spng_strerror(ret));
    }

    spng_ctx_free(ctx);
    fclose(png_file);
    free(description_string);
    free(img_data);
    free(raw_data);
}

void export_rgba32(FILE *source_file, struct asset_header *header) {
    int      ret;
    FILE    *png_file;
    uint8_t *raw_data;
    char    *description_string;
    char     png_filename[256];

    spng_ctx        *ctx  = NULL;
    struct spng_ihdr ihdr = {0};

    raw_data = malloc(header->img_byte_size);

    fread(raw_data, sizeof(uint8_t), header->img_byte_size, source_file);

    description_string = malloc(header->description_string_size);
    fread(description_string, sizeof(char), header->description_string_size, source_file);

    if ((header->description_string_size % 4) != 0) {
        fseek(source_file, 4 - (header->description_string_size % 4), SEEK_CUR);
    }

    snprintf(png_filename, sizeof(png_filename), PNG_OUTPUT_FORMAT, description_string);
    printf("%s\n", png_filename);
    png_file = fopen(png_filename, "wb");

    ctx = spng_ctx_new(SPNG_CTX_ENCODER);
    spng_set_png_file(ctx, png_file);

    ihdr.width = header->width;
    ihdr.height = header->height;
    ihdr.color_type = SPNG_COLOR_TYPE_TRUECOLOR_ALPHA;
    ihdr.bit_depth = 8;
    spng_set_ihdr(ctx, &ihdr);

    ret = spng_encode_image(ctx, raw_data, header->img_byte_size, SPNG_FMT_RAW, SPNG_ENCODE_FINALIZE);

    spng_ctx_free(ctx);
    fclose(png_file);
    free(description_string);
    free(raw_data);
}

void export_grayscale4_8(FILE *source_file, struct asset_header *header) {
    int      ret;
    uint32_t raw_size;
    uint32_t img_size;
    FILE    *png_file;
    uint8_t *raw_data;
    uint8_t *img_data;
    char    *description_string;
    char     png_filename[256];

    spng_ctx        *ctx  = NULL;
    struct spng_ihdr ihdr = {0};
    struct spng_trns trns = {0};

    ihdr.width = header->width;
    ihdr.height = header->height;
    if (header->flags & 0x8000) {
        ihdr.bit_depth = 8;
        ihdr.color_type = SPNG_COLOR_TYPE_GRAYSCALE_ALPHA;

        raw_size = header->width * header->height;
        img_size = header->width * header->height * 2;
    } else {
        ihdr.bit_depth = 4;
        ihdr.color_type = SPNG_COLOR_TYPE_GRAYSCALE;

        if (header->flags & 0x4000){
            trns.gray = (header->trans_color & 0xF0000000) >> 0x1C;
        }

        raw_size = img_size = (header->width * header->height) / 2;
    }

    raw_data = malloc(sizeof(uint8_t) * raw_size);
    fread(raw_data, sizeof(uint8_t), raw_size, source_file);

    img_data = malloc(sizeof(uint8_t) * img_size);

    if (header->flags & 0x8000) {
        for (uint32_t i = 0; i < (header->width * header->height); i++) {
            img_data[2*i]     = scale_x_y(raw_data[i] & 0xF0 >> 4, 4, 8);
            img_data[2*i + 1] = scale_x_y(raw_data[i] & 0x0F, 4, 8);
        }
    } else {
        for (uint32_t i = 0; i < (header->width * header->height) / 2; i++) {
            img_data[i] = raw_data[i];
        }
    }

    description_string = malloc(header->description_string_size);
    fread(description_string, sizeof(char), header->description_string_size, source_file);

    if ((header->description_string_size % 4) != 0) {
        fseek(source_file, 4 - (header->description_string_size % 4), SEEK_CUR);
    }

    snprintf(png_filename, sizeof(png_filename), PNG_OUTPUT_FORMAT, description_string);
    printf("%s\n", png_filename);
    png_file = fopen(png_filename, "wb");

    ctx = spng_ctx_new(SPNG_CTX_ENCODER);

    spng_set_png_file(ctx, png_file);

    ret = spng_set_ihdr(ctx, &ihdr);
    if (ret != SPNG_OK) {
        printf("\tset_ihdr: %d: %s\n", ret, spng_strerror(ret));
    }

    if (header->flags &0x4000) {
        ret = spng_set_trns(ctx, &trns);

        if (ret != SPNG_OK) {
            printf("\tset_trns: %d: %s\n", ret, spng_strerror(ret));
        }
    }

    ret = spng_encode_image(ctx, img_data, img_size, SPNG_FMT_RAW, SPNG_ENCODE_FINALIZE);

    if (ret != SPNG_OK) {
        printf("\tencode_image: %d: %s\n", ret, spng_strerror(ret));
    }

    spng_ctx_free(ctx);
    fclose(png_file);
    free(description_string);
    free(img_data);
    free(raw_data);
}

void export_grayscale16(FILE *source_file, struct asset_header *header) {
    int      ret;
    FILE    *png_file;
    uint8_t *raw_data;
    char    *description_string;
    char     png_filename[256];

    spng_ctx        *ctx  = NULL;
    struct spng_ihdr ihdr = {0};
    struct spng_trns trns = {0};

    raw_data = malloc(header->img_byte_size);

    fread(raw_data, sizeof(uint8_t), header->img_byte_size, source_file);

    description_string = malloc(header->description_string_size);
    fread(description_string, sizeof(char), header->description_string_size, source_file);

    if ((header->description_string_size % 4) != 0) {
        fseek(source_file, 4 - (header->description_string_size % 4), SEEK_CUR);
    }

    snprintf(png_filename, sizeof(png_filename), PNG_OUTPUT_FORMAT, description_string);
    printf("%s\n", png_filename);
    png_file = fopen(png_filename, "wb");

    ctx = spng_ctx_new(SPNG_CTX_ENCODER);
    spng_set_png_file(ctx, png_file);

    ihdr.width = header->width;
    ihdr.height = header->height;
    ihdr.color_type = SPNG_COLOR_TYPE_GRAYSCALE_ALPHA;
    ihdr.bit_depth = 8;
    spng_set_ihdr(ctx, &ihdr);

    trns.gray = header->trans_color;
    spng_set_trns(ctx, &trns);

    ret = spng_encode_image(ctx, raw_data, header->img_byte_size, SPNG_FMT_RAW, SPNG_ENCODE_FINALIZE);

    spng_ctx_free(ctx);
    fclose(png_file);
    free(description_string);
    free(raw_data);
}

void export_png(FILE *source_file, struct asset_header *header) {
    switch(header->type) {
    case CI4:
        export_ci4(source_file, header);
        break;
    case CI8:
        export_ci8(source_file, header);
        break;
    case RGBA5551:
        export_rgba5551(source_file, header);
        break;
    case RGBA32:
        export_rgba32(source_file, header);
        break;
    case GRAYSCALE4_8:
        export_grayscale4_8(source_file, header);
        break;
    case GRAYSCALE16:
        export_grayscale16(source_file, header);
        break;
    default:
        break;
    }
}

void parse_asset_header(FILE *source_file, struct asset_header *header) {
    fread(&header->asset_size, sizeof(uint32_t), 1, source_file);
    header->asset_size = be32toh(header->asset_size);

    fread(&header->pixel_offset, sizeof(uint32_t), 1, source_file);
    header->pixel_offset = be32toh(header->pixel_offset);

    fread(&header->extra_offset, sizeof(uint32_t), 1, source_file);
    header->extra_offset = be32toh(header->extra_offset);

    // Large block of 0 bytes
    fseek(source_file, 24, SEEK_CUR);

    fread(&header->palette_offset, sizeof(uint32_t), 1, source_file);
    header->palette_offset = be32toh(header->palette_offset);

    fread(&header->description_string_offset, sizeof(uint32_t), 1, source_file);
    header->description_string_offset = be32toh(header->description_string_offset);
    header->description_string_size = header->asset_size - header->description_string_offset;

    fread(&header->width, sizeof(uint16_t), 1, source_file);
    header->width = be16toh(header->width);

    fread(&header->height, sizeof(uint16_t), 1, source_file);
    header->height = be16toh(header->height);

    // if ((header->width  % 2) == 1) header->width++;
    // if ((header->height % 2) == 1) header->height++;

    // Always 0x01, purpose unknown
    fseek(source_file, 1, SEEK_CUR);

    fread(&header->bit_depth, sizeof(uint8_t), 1, source_file);

    // 0x00, 0x40 or 0x80, purpose unknown
    // fseek(source_file, 1, SEEK_CUR);
    // fread(&header->type, sizeof(uint8_t), 1, source_file);

    uint16_t flags;
    fread(&flags, sizeof(uint16_t), 1, source_file);

    flags = be16toh(flags);
    header->flags = flags & 0xFFF0;
    header->type  = flags & 0x000F;

    fread(&header->trans_color, sizeof(uint32_t), 1, source_file);
    header->trans_color = be32toh(header->trans_color);

    switch(header->type) {
    case CI4:
        printf("CI4 image, ");
        header->img_byte_size = (sizeof(uint8_t) * header->width * header->height) / 2;
        break;
    case CI8:
        printf("CI8 image, ");
        header->img_byte_size = sizeof(uint8_t) * header->width * header->height;
        break;
    case RGBA5551:
        printf("RGBA5551 image, ");
        header->img_byte_size = sizeof(uint16_t) * header->width * header->height;
        break;
    case RGBA32:
        printf("RGBA32 image, ");
        header->img_byte_size = sizeof(uint32_t) * header->width * header->height;
        break;
    case GRAYSCALE4_8:
        if (header->bit_depth == 0) {
            printf("GRAYSCALE4 image, ");
            header->img_byte_size = (sizeof(uint8_t) * header->width * header->height) / 2;
        } else {
            printf("GRAYSCALE8 image, ");
            header->img_byte_size = sizeof(uint8_t) * header->width * header->height;
        }
        break;
    case GRAYSCALE16:
        printf("GRAYSCALE16 image, ");
        header->img_byte_size = sizeof(uint16_t) * header->width * header->height;
        break;
    default:
        break;
    }
    printf("flags=0x%04x: ", header->flags);
}

int main(int argc, char *argv[]) {
    FILE *source_file;
    struct asset_header header = {0};
    int ret;
    int peek;

    source_file = fopen(argv[1], "rb");

    if (source_file == NULL) {
        printf("Failed to open the source file\n");
        return -1;
    }

    while ((peek = fgetc(source_file)) != EOF) {
        ungetc(peek, source_file);
        parse_asset_header(source_file, &header);
        export_png(source_file, &header);
    }
    fclose(source_file);
    return 0;
}
