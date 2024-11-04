#include <spng.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <endian.h>

struct material_entry {
    /* 0x00 */ uint16_t material_type; // 1 = has texture, 2 = no texture
    /* 0x02 */ uint16_t texture_index;
    /* 0x04 */ float misc_float; // Pupose unknown
    /* 0x08 */ float one; // Always(?) 1.0f
    /* 0x0C */ uint32_t zero; // Always(?) 0
    /* 0x10 */ uint32_t alwaysa; // Always(?) 0x0a000000, purpose unknown
    /* 0x14 */ char material_name[16];
}; // size 0x24

void process_material_entry(struct material_entry *material) {
    material->material_type = be16toh(material->material_type);
    material->texture_index = be16toh(material->texture_index);
    // This is so incredibly dumb
    // But reading floats from binary files appears to be ill-advised anyway in general so we're stuck with this
    *(uint32_t*)&material->misc_float = be32toh(*(uint32_t*)&material->misc_float);
    *(uint32_t*)&material->one = be32toh(*(uint32_t*)&material->one);
    material->alwaysa = be32toh(material->alwaysa);
}

struct texture_entry {
    /* 0x00 */ uint32_t pixel_offset;
    /* 0x04 */ uint8_t zeros[28];
    /* 0x20 */ uint32_t plte_offset;
    /* 0x24 */ uint32_t texture_name_offset;
    /* 0x28 */ uint16_t width;
    /* 0x2A */ uint16_t height;
    /* 0x2C */ uint8_t one; // Always(?) 0x01, purpose unknown
    /* 0x2D */ uint8_t bit_depth;
    /* 0x2E */ uint8_t unused;
    /* 0x2F */ uint8_t type;
    /* 0x30 */ uint32_t trans_color;
}; // size 0x34

void process_texture_entry(struct texture_entry *texture) {
    texture->pixel_offset = be32toh(texture->pixel_offset);
    texture->plte_offset = be32toh(texture->plte_offset);
    texture->texture_name_offset = be32toh(texture->texture_name_offset);
    texture->width = be16toh(texture->width);
    if ((texture->width % 2) != 0) texture->width++;
    texture->height = be16toh(texture->height);
    if ((texture->height % 2) != 0) texture->height++;
    texture->trans_color = be32toh(texture->trans_color);
}

enum image_types {
    // Both CI types are plain RGB, not alpha channel in the color itself
    CI4 = 0,
    CI8 = 1,
    RGB16 = 2, // ????
    RGBA32 = 3, // Truecolor with alpha, bit-depth of 8
    // Consult header's bit_depth to diffirentiate between 4bpp and 8bpp
    // 0 = 4bpp
    // 1 = 8bpp
    GRAYSCALE4_8 = 4,
    GRAYSCALE16 = 5,
};

#define CI4_PAL_SIZE 16
#define CI8_PAL_SIZE 256

struct rgb888 {
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

void export_ci4(FILE *source_file, struct texture_entry *texture) {
    FILE *png_file;
    uint8_t *raw_data;
    uint32_t data_size;
    struct rgb888 palette[CI4_PAL_SIZE];
    char texture_name[16];
    char png_filename[256];
    int ret;

    spng_ctx *ctx = NULL;
    struct spng_ihdr ihdr = {0};
    struct spng_plte plte = {0};
    /*
    * In theory, we should be able to use the trans_color entry from the header
    * to deduce which pixels are transparent. Skip that for now to simplify things
    * struct spng_trns trns = {0};
    */

    fseek(source_file, texture->plte_offset, SEEK_SET);
    fread(palette, sizeof(struct rgb888), CI4_PAL_SIZE, source_file);

    // This fixes a single image, dew_tail from the first level's HTM collection. I have no idea why.
    // if (texture->width % 2 != 0) {printf("Odd width "); texture->width++;}
    // if (texture->height % 2 != 0) {printf("Odd height "); texture->height++;}
    data_size = (texture->width * texture->height) / 2;
    raw_data = malloc(data_size);

    fseek(source_file, texture->pixel_offset, SEEK_SET);
    fread(raw_data, sizeof(uint8_t), data_size, source_file);

    fseek(source_file, texture->texture_name_offset, SEEK_SET);
    fread(texture_name, sizeof(char), 16, source_file);

    snprintf(png_filename, sizeof(png_filename), "./output_pngs/%s.png", texture_name);
    printf("%s ", png_filename);
    png_file = fopen(png_filename, "wb");

    ctx = spng_ctx_new(SPNG_CTX_ENCODER);
    spng_set_png_file(ctx, png_file);

    ihdr.width = texture->width;
    ihdr.height = texture->height;
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

    ret = spng_encode_image(ctx, raw_data, data_size, SPNG_FMT_RAW, SPNG_ENCODE_FINALIZE);
    if (ret != SPNG_OK) {
        printf("%s ", spng_strerror(ret));
    }

    spng_ctx_free(ctx);
    fclose(png_file);
    free(raw_data);
}

void export_ci8(FILE *source_file, struct texture_entry *texture) {
    FILE *png_file;
    uint8_t *raw_data;
    uint32_t data_size;
    struct rgb888 palette[CI8_PAL_SIZE];
    char texture_name[16];
    char png_filename[256];
    int ret;

    spng_ctx *ctx = NULL;
    struct spng_ihdr ihdr = {0};
    struct spng_plte plte = {0};
    /*
    * In theory, we should be able to use the trans_color entry from the header
    * to deduce which pixels are transparent. Skip that for now to simplify things
    * struct spng_trns trns = {0};
    */

    fseek(source_file, texture->plte_offset, SEEK_SET);
    fread(palette, sizeof(struct rgb888), CI8_PAL_SIZE, source_file);

    data_size = texture->width * texture->height;
    raw_data = malloc(data_size);

    fseek(source_file, texture->pixel_offset, SEEK_SET);
    fread(raw_data, sizeof(uint8_t), data_size, source_file);

    fseek(source_file, texture->texture_name_offset, SEEK_SET);
    fread(texture_name, sizeof(char), 16, source_file);

    snprintf(png_filename, sizeof(png_filename), "./output_pngs/%s.png", texture_name);
    printf("%s ", png_filename);
    png_file = fopen(png_filename, "wb");

    ctx = spng_ctx_new(SPNG_CTX_ENCODER);
    spng_set_png_file(ctx, png_file);

    ihdr.width = texture->width;
    ihdr.height = texture->height;
    ihdr.color_type = SPNG_COLOR_TYPE_INDEXED;
    ihdr.bit_depth = 8;
    spng_set_ihdr(ctx, &ihdr);

    plte.n_entries = CI8_PAL_SIZE;
    for (int i = 0; i < CI8_PAL_SIZE; i++) {
        plte.entries[i].red   = palette[i].red;
        plte.entries[i].green = palette[i].green;
        plte.entries[i].blue  = palette[i].blue;
    }
    spng_set_plte(ctx, &plte);

    ret = spng_encode_image(ctx, raw_data, data_size, SPNG_FMT_RAW, SPNG_ENCODE_FINALIZE);

    spng_ctx_free(ctx);
    fclose(png_file);
    free(raw_data);
}

uint32_t scale_5_8(uint32_t value) {
    return ((value << 3) | (value >> 2));
}

void export_tyler(FILE *source_file, struct texture_entry *texture) {
    FILE *png_file;
    uint16_t *raw_data;
    struct rgba *converted;
    char texture_name[16];
    char png_filename[256];
    int ret;

    spng_ctx *ctx = NULL;
    struct spng_ihdr ihdr = {0};

    raw_data = malloc(sizeof(uint16_t) * (texture->width * texture->height));
    converted = malloc(sizeof(struct rgba) * (texture->width * texture->height));

    fseek(source_file, texture->pixel_offset, SEEK_SET);
    fread(raw_data, sizeof(uint16_t), (texture->width * texture->height), source_file);

    fseek(source_file, texture->texture_name_offset, SEEK_SET);
    fread(texture_name, sizeof(char), 16, source_file);

    for (int i = 0; i < (texture->width * texture->height); i++) {
        raw_data[i] = htobe16(raw_data[i]);
        converted[i].red   = scale_5_8((raw_data[i] & 0x7C00) >> 10);
        converted[i].green = scale_5_8((raw_data[i] & 0x03E0) >>  5);
        converted[i].blue  = scale_5_8((raw_data[i] & 0x001F) >>  0);
        converted[i].alpha = (raw_data[i] & 0x8000) ? 0xFF : 0x00;
    }

    snprintf(png_filename, sizeof(png_filename), "./output_pngs/%s.png", texture_name);
    printf("%s ", png_filename);
    png_file = fopen(png_filename, "wb");

    ctx = spng_ctx_new(SPNG_CTX_ENCODER);
    spng_set_png_file(ctx, png_file);

    ihdr.width = texture->width;
    ihdr.height = texture->height;
    ihdr.color_type = SPNG_COLOR_TYPE_TRUECOLOR_ALPHA;
    ihdr.bit_depth = 8;
    spng_set_ihdr(ctx, &ihdr);

    ret = spng_encode_image(ctx, converted, sizeof(struct rgba) * (texture->width * texture->height), SPNG_FMT_RAW, SPNG_ENCODE_FINALIZE);

    spng_ctx_free(ctx);
    fclose(png_file);
    free(converted);
    free(raw_data);
}

void export_truecoloralpha(FILE *source_file, struct texture_entry *texture) {
    FILE *png_file;
    uint8_t *raw_data;
    uint32_t data_size;
    char texture_name[16];
    char png_filename[256];
    int ret;

    spng_ctx *ctx = NULL;
    struct spng_ihdr ihdr = {0};

    data_size = (texture->width * texture->height) * 4;
    raw_data = malloc(data_size);

    fseek(source_file, texture->pixel_offset, SEEK_SET);
    fread(raw_data, sizeof(uint8_t), data_size, source_file);

    fseek(source_file, texture->texture_name_offset, SEEK_SET);
    fread(texture_name, sizeof(char), 16, source_file);

    snprintf(png_filename, sizeof(png_filename), "./output_pngs/%s.png", texture_name);
    printf("%s ", png_filename);
    png_file = fopen(png_filename, "wb");

    ctx = spng_ctx_new(SPNG_CTX_ENCODER);
    spng_set_png_file(ctx, png_file);

    ihdr.width = texture->width;
    ihdr.height = texture->height;
    ihdr.color_type = SPNG_COLOR_TYPE_TRUECOLOR_ALPHA;
    ihdr.bit_depth = 8;
    spng_set_ihdr(ctx, &ihdr);

    ret = spng_encode_image(ctx, raw_data, data_size, SPNG_FMT_RAW, SPNG_ENCODE_FINALIZE);

    spng_ctx_free(ctx);
    fclose(png_file);
    free(raw_data);
}

void export_grayscale4_8(FILE *source_file, struct texture_entry *texture) {
    FILE *png_file;
    uint8_t *raw_data;
    uint32_t data_size;
    char texture_name[16];
    char png_filename[256];
    int ret;

    spng_ctx *ctx = NULL;
    struct spng_ihdr ihdr = {0};
    struct spng_trns trns = {0};

    if (texture->bit_depth == 1) {
        data_size = (texture->width * texture->height) / 2;
    } else {
        data_size = texture->width * texture->height;
    }
    raw_data = malloc(data_size);

    fseek(source_file, texture->pixel_offset, SEEK_SET);
    fread(raw_data, sizeof(uint8_t), data_size, source_file);

    fseek(source_file, texture->texture_name_offset, SEEK_SET);
    fread(texture_name, sizeof(char), 16, source_file);

    snprintf(png_filename, sizeof(png_filename), "./output_pngs/%s.png", texture_name);
    printf("%s ", png_filename);
    png_file = fopen(png_filename, "wb");

    ctx = spng_ctx_new(SPNG_CTX_ENCODER);
    spng_set_png_file(ctx, png_file);

    ihdr.width = texture->width;
    ihdr.height = texture->height;
    ihdr.color_type = SPNG_COLOR_TYPE_GRAYSCALE;
    if (texture->bit_depth == 1) {
        ihdr.bit_depth = 4;
    } else {
        ihdr.bit_depth = 8;
    }
    spng_set_ihdr(ctx, &ihdr);

    trns.gray = texture->trans_color;
    spng_set_trns(ctx, &trns);

    ret = spng_encode_image(ctx, raw_data, data_size, SPNG_FMT_RAW, SPNG_ENCODE_FINALIZE);

    if (ret != SPNG_OK)
        printf("%s ", spng_strerror(ret));

    spng_ctx_free(ctx);
    fclose(png_file);
    free(raw_data);
}

void export_grayscale16(FILE *source_file, struct texture_entry *texture) {
    FILE *png_file;
    uint8_t *raw_data;
    uint32_t data_size;
    char texture_name[16];
    char png_filename[256];
    int ret;

    spng_ctx *ctx = NULL;
    struct spng_ihdr ihdr = {0};
    struct spng_trns trns = {0};

    data_size = texture->width * texture->height;
    raw_data = malloc(data_size);

    fseek(source_file, texture->pixel_offset, SEEK_SET);
    fread(raw_data, sizeof(uint8_t), data_size, source_file);

    fseek(source_file, texture->texture_name_offset, SEEK_SET);
    fread(texture_name, sizeof(char), 16, source_file);

    snprintf(png_filename, sizeof(png_filename), "./output_pngs/%s.png", texture_name);
    printf("%s ", png_filename);
    png_file = fopen(png_filename, "wb");

    ctx = spng_ctx_new(SPNG_CTX_ENCODER);
    spng_set_png_file(ctx, png_file);

    ihdr.width = texture->width;
    ihdr.height = texture->height;
    ihdr.color_type = SPNG_COLOR_TYPE_GRAYSCALE;
    ihdr.bit_depth = 8;
    spng_set_ihdr(ctx, &ihdr);

    trns.gray = texture->trans_color;
    spng_set_trns(ctx, &trns);

    ret = spng_encode_image(ctx, raw_data, data_size, SPNG_FMT_RAW, SPNG_ENCODE_FINALIZE);

    spng_ctx_free(ctx);
    fclose(png_file);
    free(raw_data);
}

void export_png(FILE *source_file, struct texture_entry *texture) {
    switch(texture->type) {
    case CI4:
        printf("CI4 ");
        export_ci4(source_file, texture);
        break;
    case CI8:
        printf("CI8 ");
        export_ci8(source_file, texture);
        break;
    case RGB16:
        printf("RGB16 ");
        // export_truecolor(source_file, texture);
        export_tyler(source_file, texture);
        break;
    case RGBA32:
        printf("RGBA32 ");
        export_truecoloralpha(source_file, texture);
        break;
    case GRAYSCALE4_8:
        if (texture->bit_depth == 1) {
            printf("GS4 ");
        } else {
            printf("GS8 ");
        }
        export_grayscale4_8(source_file, texture);
        break;
    case GRAYSCALE16:
        printf("GS16 ");
        export_grayscale16(source_file, texture);
        break;
    default:
        break;
    }
}

int main(int argc, char *argv[]) {
    FILE *source_file;
    int peek;

    uint16_t material_count;
    uint32_t material_entry_size;
    struct material_entry *materials;
    uint16_t texture_count;
    struct texture_entry *textures;

    source_file = fopen(argv[1], "rb");

    if (source_file == NULL) {
        printf("Failed to open the source file\n");
        return -1;
    }

    fread(&material_count, sizeof(uint16_t), 1, source_file);
    material_count = be16toh(material_count);

    fseek(source_file, 2, SEEK_CUR);
    fread(&material_entry_size, sizeof(uint32_t), 1, source_file);
    material_entry_size = be32toh(material_entry_size);

    materials = calloc(material_count, sizeof(struct material_entry));
    fread(materials, sizeof(struct material_entry), material_count, source_file);

    printf("[");
    for (int i = 0; i < material_count; i++) {
        if ((i % 4) == 0) printf("\n\t");
        printf("(%d, \"%s\"), ", i, materials[i].material_name);
        process_material_entry(&materials[i]);
    }
    printf("\n]\n");

    fread(&texture_count, sizeof(uint16_t), 1, source_file);
    texture_count = be16toh(texture_count);
    fseek(source_file, 2, SEEK_CUR);

    textures = calloc(texture_count, sizeof(struct texture_entry));
    fread(textures, sizeof(struct texture_entry), texture_count, source_file);

    for (int i = 0; i < texture_count; i++) {
        printf("Texture %d ", i);
        process_texture_entry(&textures[i]);
        export_png(source_file, &textures[i]);
        printf("\n");
    }

    free(textures);
    free(materials);
    fclose(source_file);
    return 0;
}
