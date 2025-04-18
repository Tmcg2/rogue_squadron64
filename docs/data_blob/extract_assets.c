#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <endian.h>
#include <sys/stat.h>

#include <errno.h>
#include <string.h>

#include <zlib.h>
#include <assert.h>

struct segment_header {
    /* 0x00 */ char     segment_name[16];
    /* 0x10 */ uint32_t unk10;
    /* 0x14 */ uint32_t unk14;
    /* 0x18 */ uint32_t unk18;
    /* 0x1C */ uint32_t data_offset;
}; // size: 0x20 bytes

struct block_header {
    /* 0x00 */ uint32_t block_size;
    /* 0x04 */ uint16_t flags;
    /* 0x06 */ uint16_t manifest_size;
}; // size: 0x8 bytes

struct manifest_entry {
    /* 0x00 */ uint32_t asset_offset;
    /* 0x04 */ uint32_t decompressed_size;
    /* 0x08 */ uint32_t compressed_size;
    /* 0x0C */ uint8_t  flags;
    /* 0x0D */ uint8_t  unk0D;
    /* 0x0E */ uint16_t directory_size;
    /* 0x10 */ char     asset_name[16];
}; // size: 0x20 bytes

#define NUM_SEGMENTS 2
#define SEGMENT_OFFSET 0x144340

#define DATA_OFFSET (SEGMENT_OFFSET + (sizeof(struct segment_header) * NUM_SEGMENTS))

#define MAX_FILENAME 256

#ifndef DEBUG
#define dbg(...)
#else
#define dbg(...) printf(__VA_ARGS__)
#endif

FILE *rom;

// This has been shamelessly copied from the `zpipe.c` example found in the zlib source repository
// Only tiny non-functional adjustments have been made
int32_t zlib_inflate(FILE *source, FILE *dest) {
    #define CHUNK 16384

    int32_t ret;
    uint32_t have;
    z_stream strm;
    uint8_t in[CHUNK];
    uint8_t out[CHUNK];

    /* allocate inflate state */
    strm.zalloc = Z_NULL;
    strm.zfree = Z_NULL;
    strm.opaque = Z_NULL;
    strm.avail_in = 0;
    strm.next_in = Z_NULL;
    ret = inflateInit(&strm);
    if (ret != Z_OK){
        return ret;
    }

    /* decompress until deflate stream ends or end of file */
    do {
        strm.avail_in = fread(in, sizeof(uint8_t), CHUNK, source);
        if (ferror(source)) {
            (void)inflateEnd(&strm);
            return Z_ERRNO;
        }
        if (strm.avail_in == 0){
            break;
        }
        strm.next_in = in;

        /* run inflate() on input until output buffer not full */
        do {
            strm.avail_out = CHUNK;
            strm.next_out = out;
            ret = inflate(&strm, Z_NO_FLUSH);
            assert(ret != Z_STREAM_ERROR);  /* state not clobbered */
            switch (ret) {
            case Z_NEED_DICT:
                ret = Z_DATA_ERROR;     /* and fall through */
            case Z_DATA_ERROR:
            case Z_MEM_ERROR:
                (void)inflateEnd(&strm);
                return ret;
            }
            have = CHUNK - strm.avail_out;
            if (fwrite(out, sizeof(uint8_t), have, dest) != have || ferror(dest)) {
                (void)inflateEnd(&strm);
                return Z_ERRNO;
            }
        } while (strm.avail_out == 0);

        /* done when inflate() says it's done */
    } while (ret != Z_STREAM_END);

    /* clean up and return */
    (void)inflateEnd(&strm);
    return ret == Z_STREAM_END ? Z_OK : Z_DATA_ERROR;
}

void inflate_asset(char *filename) {
    FILE *asset_file;
    FILE *inflated_file;
    char *extentsion;
    int32_t zret;

    dbg("Inflating  %s\n", filename);

    asset_file = fopen(filename, "rb");
    if (asset_file == NULL) {
        dbg("Failed to open compressed asset %s: %s\n", filename, strerror(errno));
    } else {
        extentsion = strrchr(filename, '.');
        *extentsion = '\0';

        inflated_file = fopen(filename, "wb");
        if (inflated_file == NULL) {
            dbg("Failed to open decompression target file %s: %s\n", filename, strerror(errno));
        } else {
            zret = zlib_inflate(asset_file, inflated_file);
            if (zret != Z_OK) {
                dbg("Error encoutered during decompression of %s: %d\n", filename, zret);
            }
            fclose(inflated_file);
        }
        fclose(asset_file);
    }
}

void extract_raw_asset(char *filename, uint32_t asset_size) {
    FILE *asset_file;
    uint8_t *asset_data;

    dbg("Extracting %s\n", filename);

    asset_file = fopen(filename, "wb");
    if (asset_file == NULL) {
        dbg("Failed to open file for %s\n", filename);
    } else {
        asset_data = malloc(asset_size);

        dbg("Asset read at 0x%08lx: 0x%08x\n", ftell(rom), asset_size);
        fread(asset_data, sizeof(uint8_t), asset_size, rom);
        fwrite(asset_data, sizeof(uint8_t), asset_size, asset_file);

        free(asset_data);
        fclose(asset_file);
    }
}

void extract_asset(struct manifest_entry *asset, char *output_directory) {
    uint32_t asset_size;
    uint8_t *asset_data;
    char filename[MAX_FILENAME];

    fseek(rom, asset->asset_offset, SEEK_SET);
    if (asset->compressed_size != 0xFFFFFFFF){
        snprintf(filename, MAX_FILENAME, "%s/%s.zz", output_directory, asset->asset_name);
        // All compressed sizes are oversized by 10
        extract_raw_asset(filename, asset->compressed_size - 10);
        inflate_asset(filename);
    } else {
        snprintf(filename, MAX_FILENAME, "%s/%s.raw", output_directory, asset->asset_name);
        extract_raw_asset(filename, asset->decompressed_size);
    }
}

void extract_assets(struct manifest_entry *asset, uint32_t asset_count, char *output_directory) {
    dbg("Asset_count: %d\n", asset_count);
    while(asset_count > 0) {
        if (asset->flags != 0x80) {
            extract_asset(asset, output_directory);
            asset++; asset_count--;
        } else {
            uint32_t newcount;
            char newdir[MAX_FILENAME];
            struct stat st = {0};

            snprintf(newdir, MAX_FILENAME, "%s/%s", output_directory, asset->asset_name);
            newcount = asset->directory_size / sizeof(struct manifest_entry);
            
            if (stat(newdir, &st) != 0) {
                dbg("mkdir %s\n", newdir);
                mkdir(newdir, 0755);
            }

            dbg("Extracting sub-directory %s\n", newdir);

            // Skip the directory entry itself
            asset++; newcount--; asset_count--;
            extract_assets(asset, newcount, newdir);
            asset += newcount; asset_count -= newcount;

            dbg("\n");
        }
    }
}

void extract_segment(struct segment_header *segment, char *top_level) {
    struct block_header bh;
    uint32_t manifest_count;
    uint16_t asset_count;
    struct manifest_entry *manifest_entries, *asset;
    char output_directory[MAX_FILENAME];
    struct stat st = {0};
    uint32_t base_offset;

    fseek(rom, DATA_OFFSET + segment->data_offset, SEEK_SET);

    fread(&bh, sizeof(struct block_header), 1, rom);

    bh.block_size    = be32toh(bh.block_size);
    bh.flags         = be16toh(bh.flags);
    bh.manifest_size = be16toh(bh.manifest_size);

    manifest_count = bh.manifest_size / sizeof(struct manifest_entry);
    manifest_entries = malloc(bh.manifest_size);

    fseek(rom, DATA_OFFSET + segment->data_offset + bh.block_size, SEEK_SET);
    fread(manifest_entries, sizeof(struct manifest_entry), manifest_count, rom);

    for (int i = 0; i < manifest_count; i++) {
        manifest_entries[i].asset_offset      = be32toh(manifest_entries[i].asset_offset);
        manifest_entries[i].decompressed_size = be32toh(manifest_entries[i].decompressed_size);
        manifest_entries[i].compressed_size   = be32toh(manifest_entries[i].compressed_size);
        manifest_entries[i].directory_size    = be16toh(manifest_entries[i].directory_size);

        // Set the asset offset to be the true file offset
        manifest_entries[i].asset_offset += DATA_OFFSET + segment->data_offset;
    }

    snprintf(output_directory, MAX_FILENAME, "%s/%s", top_level, segment->segment_name);
            
    if (stat(output_directory, &st) != 0) {
        dbg("mkdir %s\n", output_directory);
        mkdir(output_directory, 0755);
    }

    dbg("Extracting segment %s to %s\n", segment->segment_name, output_directory);
    extract_assets(manifest_entries, manifest_count, output_directory);

    free(manifest_entries);
}

// Usage: extract_assets ./path/to/rom ./top/level/output/directory
int main(int argc, char *argv[]) {
    struct stat st = {0};
    struct segment_header segments[NUM_SEGMENTS];

    rom = fopen(argv[1], "rb");

    if (rom == NULL) {
        printf("Failed to open source file\n");
        return -1;
    }

    if (stat(argv[2], &st) != 0) {
        dbg("mkdir %s\n", argv[2]);
        mkdir(argv[2], 0755);
    }

    fseek(rom, SEGMENT_OFFSET, SEEK_SET);
    fread(segments, sizeof(struct segment_header), NUM_SEGMENTS, rom);

    for (int i = 0; i < NUM_SEGMENTS; i++) {
        segments[i].data_offset = be32toh(segments[i].data_offset);
        extract_segment(&segments[i], argv[2]);
    }

    return 0;
}
