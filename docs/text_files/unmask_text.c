#include <spng.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <endian.h>
#include <string.h>

// As the variable name suggests, this is incredibly dumb
// But it'll do for my purposes
// If dumb == 0, decrypt the language data in one fell swoop
// If dumb == 1, decrypt each string in the language data one-by-one
uint8_t dumb = 0;

struct language_context {
    uint32_t language_offset;
    uint32_t language_size;
    uint16_t string_count;
};

void decrypt(uint8_t *string_data, uint32_t string_size) {
    uint8_t prev = 0xf5;

    for (int i = 0; i < string_size; i++) {
        string_data[i] ^= prev;
        prev ^= string_data[i];
    }
}

void extract_language(FILE *source, struct language_context *ctx) {
    uint8_t   prev;
    uint32_t  language_data_size;
    uint16_t *string_offsets;
    uint8_t  *string_data;

    // This is a little goofy...
    // We add an extra string offset that really points to the end of the language's data
    // This makes the handling of voice text a little bit easier down the road
    string_offsets = malloc(sizeof(uint16_t) * (ctx->string_count + 1));
    fseek(source, ctx->language_offset, SEEK_SET);
    fread(string_offsets, sizeof(uint16_t), ctx->string_count, source);

    for (int i = 0; i < ctx->string_count; i++) {
        string_offsets[i] = be16toh(string_offsets[i]);
    }
    string_offsets[ctx->string_count] = ctx->language_size;

    language_data_size = ctx->language_size - string_offsets[0];
    string_data = malloc(sizeof(uint8_t) * language_data_size);

    for (int i = ctx->string_count; i >= 0; i--) {
        string_offsets[i] -= string_offsets[0];
    }

    fread(string_data, sizeof(uint8_t), language_data_size, source);
    if (dumb == 0) {
        decrypt(string_data, language_data_size);
    } else {
        for (int i = 0; i < ctx->string_count; i++) {
            decrypt(&string_data[string_offsets[i]], string_offsets[i + 1] - string_offsets[i]);
        }
    }

    for(int i = 0; i < ctx->string_count; i++) {
        printf("0x%04x: \"%s\"\n", i, &string_data[string_offsets[i]]);
    }
    free(string_data);
    free(string_offsets);
}

void extract_game_front(FILE *source) {
    uint16_t  string_count;
    uint16_t  language_count;
    uint32_t *language_offsets;
    struct language_context ctx = {0};

    fread(&language_count, sizeof(uint16_t), 1, source);
    language_count = be16toh(language_count);

    fread(&ctx.string_count, sizeof(uint16_t), 1, source);
    ctx.string_count = be16toh(ctx.string_count);

    // We're doing something a little goofy here, we're treating
    // the filesize entry as just another language offset
    // This simplifies some code during the language extraction
    language_offsets = malloc(sizeof(uint32_t) * (language_count + 1));
    fread(language_offsets, sizeof(uint32_t), language_count + 1, source);

    for (int i = 0; i < language_count + 1; i++) {
        language_offsets[i] = be32toh(language_offsets[i]);
    }

    for (int i = 0; i < language_count; i++) {
        ctx.language_offset = language_offsets[i];
        ctx.language_size = language_offsets[i + 1] - language_offsets[i];
        extract_language(source, &ctx);
        printf("\n");
    }
    free(language_offsets);
}

int main(int argc, uint8_t const *argv[])
{
    FILE *source = NULL;

    source = fopen("./data_blob/data/game_TXT.raw", "rb");
    if (source != NULL) {
        extract_game_front(source);
        fclose(source);
    }

    source = fopen("./data_blob/data/front_TXT.raw", "rb");
    if (source != NULL) {
        extract_game_front(source);
        fclose(source);
    }

    source = fopen("./data_blob/data/voice_TXT.raw", "rb");
    if (source != NULL) {
        dumb = 1;
        extract_game_front(source);
        fclose(source);
    }

    return 0;
}
