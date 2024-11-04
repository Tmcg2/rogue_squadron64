#include <spng.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <endian.h>

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
    // Both CI types are plain RGB, not alpha channel in the color itself
    CI4 = 0,
    CI8 = 1,
    RGBA5551 = 2, // ????
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

struct asset_header {
    uint8_t type;
    uint8_t bit_depth; // 0 = 4, 1 = 8, only matters for palette/greyscale image types
    uint16_t width, height;
    uint32_t trans_color;

    // Calculated value, not part of the header in the file
    uint32_t img_byte_size;
};

void export_ci4(FILE *source_file, struct asset_header *header, char *png_filename) {
    int        ret;
    FILE      *png_file;
    uint8_t   *raw_data;
    struct rgb palette[CI4_PAL_SIZE];

    spng_ctx        *ctx  = NULL;
    struct spng_ihdr ihdr = {0};
    struct spng_plte plte = {0};
    /*
    * In theory, we should be able to use the trans_color entry from the header
    * to deduce which pixels are transparent. Skip that for now to simplify things
    * struct spng_trns trns = {0};
    */

    fread(palette, sizeof(struct rgb), CI4_PAL_SIZE, source_file);

    raw_data = malloc(header->img_byte_size);

    fread(raw_data, sizeof(uint8_t), header->img_byte_size, source_file);

    png_file = fopen(png_filename, "wb");

    ctx = spng_ctx_new(SPNG_CTX_ENCODER);
    spng_set_png_file(ctx, png_file);

    ihdr.width = header->width;
    ihdr.height = header->height;
    ihdr.color_type = SPNG_COLOR_TYPE_INDEXED;
    ihdr.bit_depth = 4;
    spng_set_ihdr(ctx, &ihdr);

    plte.n_entries = CI4_PAL_SIZE;
    for (int i = 0; i < CI4_PAL_SIZE; i++) {
        plte.entries[i].red   = palette[i].red;
        plte.entries[i].green = palette[i].green;
        plte.entries[i].blue  = palette[i].blue;
    }
    spng_set_plte(ctx, &plte);

    ret = spng_encode_image(ctx, raw_data, header->img_byte_size, SPNG_FMT_RAW, SPNG_ENCODE_FINALIZE);

    spng_ctx_free(ctx);
    fclose(png_file);
    free(raw_data);
}

void export_ci8(FILE *source_file, struct asset_header *header, char *png_filename) {
    int         ret;
    FILE       *png_file;
    uint8_t    *raw_data;
    struct rgba palette[CI8_PAL_SIZE];

    spng_ctx        *ctx  = NULL;
    struct spng_ihdr ihdr = {0};
    struct spng_plte plte = {0};
    struct spng_trns trns = {0};

    fread(palette, sizeof(struct rgba), CI8_PAL_SIZE, source_file);

    raw_data = malloc(header->img_byte_size);

    fread(raw_data, sizeof(uint8_t), header->img_byte_size, source_file);

    png_file = fopen(png_filename, "wb");

    ctx = spng_ctx_new(SPNG_CTX_ENCODER);
    spng_set_png_file(ctx, png_file);

    ihdr.width = header->width;
    ihdr.height = header->height;
    ihdr.color_type = SPNG_COLOR_TYPE_INDEXED;
    ihdr.bit_depth = 8;
    spng_set_ihdr(ctx, &ihdr);

    plte.n_entries = CI8_PAL_SIZE;
    trns.n_type3_entries = CI8_PAL_SIZE;
    for (int i = 0; i < CI8_PAL_SIZE; i++) {
        plte.entries[i].red   = palette[i].red;
        plte.entries[i].green = palette[i].green;
        plte.entries[i].blue  = palette[i].blue;
        trns.type3_alpha[i]   = palette[i].alpha;
    }
    spng_set_plte(ctx, &plte);
    spng_set_trns(ctx, &trns);

    ret = spng_encode_image(ctx, raw_data, header->img_byte_size, SPNG_FMT_RAW, SPNG_ENCODE_FINALIZE);

    spng_ctx_free(ctx);
    fclose(png_file);
    free(raw_data);
}

void export_rgba5551(FILE *source_file, struct asset_header *header, char *png_filename) {
    int          ret;
    uint32_t     converted_size;
    FILE        *png_file;
    uint16_t    *raw_data;
    struct rgba *converted;

    spng_ctx        *ctx = NULL;
    struct spng_ihdr ihdr = {0};

    raw_data = malloc(header->img_byte_size);

    converted_size = sizeof(struct rgba) * header->width * header->height;
    converted = malloc(converted_size);

    fread(raw_data, sizeof(uint8_t), header->img_byte_size, source_file);

    for (int i = 0; i < (header->width * header->height); i++) {
        raw_data[i] = be16toh(raw_data[i]);
        converted[i].red   = scale_x_y((raw_data[i] & 0x7C00) >> 10, 5, 8);
        converted[i].green = scale_x_y((raw_data[i] & 0x03E0) >>  5, 5, 8);
        converted[i].blue  = scale_x_y((raw_data[i] & 0x001F) >>  0, 5, 8);
        converted[i].alpha = scale_x_y((raw_data[i] & 0x8000) >> 15, 1, 8);
    }

    png_file = fopen(png_filename, "wb");

    ctx = spng_ctx_new(SPNG_CTX_ENCODER);
    spng_set_png_file(ctx, png_file);

    ihdr.width = header->width;
    ihdr.height = header->height;
    ihdr.color_type = SPNG_COLOR_TYPE_TRUECOLOR_ALPHA;
    ihdr.bit_depth = 8;
    spng_set_ihdr(ctx, &ihdr);

    ret = spng_encode_image(ctx, converted, converted_size, SPNG_FMT_RAW, SPNG_ENCODE_FINALIZE);

    spng_ctx_free(ctx);
    fclose(png_file);
    free(converted);
    free(raw_data);
}

void export_rgba32(FILE *source_file, struct asset_header *header, char *png_filename) {
    int      ret;
    FILE    *png_file;
    uint8_t *raw_data;

    spng_ctx        *ctx  = NULL;
    struct spng_ihdr ihdr = {0};

    raw_data = malloc(header->img_byte_size);

    fread(raw_data, sizeof(uint8_t), header->img_byte_size, source_file);

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
    free(raw_data);
}

void export_grayscale4_8(FILE *source_file, struct asset_header *header, char *png_filename) {
    int      ret;
    FILE    *png_file;
    uint8_t *raw_data;

    spng_ctx        *ctx  = NULL;
    struct spng_ihdr ihdr = {0};

    raw_data = malloc(header->img_byte_size);

    fread(raw_data, sizeof(uint8_t), header->img_byte_size, source_file);

    png_file = fopen(png_filename, "wb");

    ctx = spng_ctx_new(SPNG_CTX_ENCODER);
    spng_set_png_file(ctx, png_file);

    ihdr.width = header->width;
    ihdr.height = header->height;
    ihdr.color_type = SPNG_COLOR_TYPE_GRAYSCALE;
    if (header->bit_depth == 0) {
        ihdr.bit_depth = 4;
    } else {
        ihdr.bit_depth = 8;
    }
    spng_set_ihdr(ctx, &ihdr);

    ret = spng_encode_image(ctx, raw_data, header->img_byte_size, SPNG_FMT_RAW, SPNG_ENCODE_FINALIZE);

    spng_ctx_free(ctx);
    fclose(png_file);
    free(raw_data);
}

void export_grayscale16(FILE *source_file, struct asset_header *header, char *png_filename) {
    int      ret;
    FILE    *png_file;
    uint8_t *raw_data;

    spng_ctx        *ctx  = NULL;
    struct spng_ihdr ihdr = {0};
    struct spng_trns trns = {0};

    raw_data = malloc(header->img_byte_size);

    fread(raw_data, sizeof(uint8_t), header->img_byte_size, source_file);

    png_file = fopen(png_filename, "wb");

    ctx = spng_ctx_new(SPNG_CTX_ENCODER);
    spng_set_png_file(ctx, png_file);

    ihdr.width = header->width;
    ihdr.height = header->height;
    ihdr.color_type = SPNG_COLOR_TYPE_GRAYSCALE;
    ihdr.bit_depth = 16;
    spng_set_ihdr(ctx, &ihdr);

    trns.gray = header->trans_color;
    spng_set_trns(ctx, &trns);

    ret = spng_encode_image(ctx, raw_data, header->img_byte_size, SPNG_FMT_RAW, SPNG_ENCODE_FINALIZE);

    spng_ctx_free(ctx);
    fclose(png_file);
    free(raw_data);
}

void export_png(FILE *source_file, struct asset_header *header, char *png_filename) {
    switch(header->type) {
    case CI4:
        printf("CI4 image: %s\n", png_filename);
        export_ci4(source_file, header, png_filename);
        break;
    case CI8:
        printf("CI8 image: %s\n", png_filename);
        export_ci8(source_file, header, png_filename);
        break;
    case RGBA5551:
        printf("RGBA5551 image: %s\n", png_filename);
        export_rgba5551(source_file, header, png_filename);
        break;
    case RGBA32:
        printf("RGBA32 image: %s\n", png_filename);
        export_rgba32(source_file, header, png_filename);
        break;
    case GRAYSCALE4_8:
        printf("GRAYSCALE4/8 image: %s\n", png_filename);
        export_grayscale4_8(source_file, header, png_filename);
        break;
    case GRAYSCALE16:
        printf("GRAYSCALE16 image: %s\n", png_filename);
        export_grayscale16(source_file, header, png_filename);
        break;
    default:
        break;
    }
}

void parse_asset_header(FILE *source_file, struct asset_header *header) {
    // 0x00, 0x40 or 0x80, purpose unknown
    fseek(source_file, 1, SEEK_CUR);

    fread(&header->type, sizeof(uint8_t), 1, source_file);

    // Might have these backwards, can't say for sure though as every file of this type has just 0x0000 here

    // Always 0x00, purpose unknown
    fseek(source_file, 1, SEEK_CUR);

    fread(&header->bit_depth, sizeof(uint8_t), 1, source_file);

    fread(&header->width, sizeof(uint16_t), 1, source_file);
    header->width = be16toh(header->width);

    fread(&header->height, sizeof(uint16_t), 1, source_file);
    header->height = be16toh(header->height);

    // 0 bytes
    // Usually just 0x0000, but could be the transparency color?
    fseek(source_file, 4, SEEK_CUR);
    // fread(&header->trans_color, sizeof(uint32_t), 1, source_file);
    // header->trans_color = htobe32(header->trans_color);

    switch(header->type) {
    case CI4:
        header->img_byte_size = (sizeof(uint8_t) * header->width * header->height) / 2;
        break;
    case CI8:
        header->img_byte_size = sizeof(uint8_t) * header->width * header->height;
        break;
    case RGBA5551:
        header->img_byte_size = sizeof(uint16_t) * header->width * header->height;
        break;
    case RGBA32:
        header->img_byte_size = sizeof(uint32_t) * header->width * header->height;
        break;
    case GRAYSCALE4_8:
        if (header->bit_depth == 0) {
            header->img_byte_size = (sizeof(uint8_t) * header->width * header->height) / 2;
        } else {
            header->img_byte_size = sizeof(uint8_t) * header->width * header->height;
        }
        break;
    case GRAYSCALE16:
        header->img_byte_size = sizeof(uint16_t) * header->width * header->height;
        break;
    default:
        break;
    }
}

int main(int argc, char *argv[]) {
    FILE *source_file;
    struct asset_header header = {0};
    int ret;
    int peek;
    char png_filename[256];

    if (argc < 2) {
        printf("Please provide an ouput name for the PNG\n");
        return 1;
    }

    source_file = fopen(argv[1], "rb");

    if (source_file == NULL) {
        printf("Failed to open the source file\n");
        return -1;
    }

    while ((peek = fgetc(source_file)) != EOF) {
        ungetc(peek, source_file);
        parse_asset_header(source_file, &header);
        snprintf(png_filename, sizeof(png_filename), PNG_OUTPUT_FORMAT, argv[2]);
        export_png(source_file, &header, png_filename);
    }
    fclose(source_file);
    return 0;
}
