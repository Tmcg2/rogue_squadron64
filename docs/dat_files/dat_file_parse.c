#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <endian.h>

struct entry_header {
    uint16_t sub_type;
    uint16_t padding;
    uint16_t item_index;
    uint16_t padding2;
    uint32_t item_size;
    uint32_t item_name_offset; // If this is 0, the item has no name
};

uint8_t name_hash(char *name) {
    uint32_t hash = 0xFFFF;

    while(*name != '\0') {
        hash = *name++ + ((hash & 0xFFFF) * 0x21);
    }
    return hash & 0xFF;
}

void parse_type(FILE *src, uint32_t type) {
    uint32_t count;
    uint32_t entryOffset;
    uint32_t offsetListOffset;
    struct entry_header header;
    /*
    In the lvl_b dat file there is a type 3 entry with 312 bytes between the name and the end of the entry.
    I think that's the largest gap found anywhere, but I'll over compensate for the fun of it.
    */
    char name[1024];

    fseek(src, type * 8, SEEK_SET);
    fread(&count, sizeof(uint32_t), 1, src);
    count = be32toh(count);

    printf("\t%d Item %d's\n", count, type);
    if (count == 0) return;

    fread(&offsetListOffset, sizeof(uint32_t), 1, src);
    offsetListOffset = be32toh(offsetListOffset);
    
    for (int i = 0; i < count; i++) {
        fseek(src, offsetListOffset + i*4, SEEK_SET);
        fread(&entryOffset, sizeof(uint32_t), 1, src);
        entryOffset = be32toh(entryOffset);
        entryOffset += offsetListOffset;
        fseek(src, entryOffset, SEEK_SET);

        fread(&header, sizeof(struct entry_header), 1, src);
        header.sub_type         = be16toh(header.sub_type);
        header.item_index       = be16toh(header.item_index);
        header.item_size        = be32toh(header.item_size);
        header.item_name_offset = be32toh(header.item_name_offset);
        
        if (header.item_name_offset == 0) {
            printf("\t\tEntry %d, Name: NULL\n", i);
        } else {
            fseek(src, entryOffset + header.item_name_offset, SEEK_SET);
            /*
            There are some sub-types that have (at least) one extra name after the main one.
            Presumably this is to link items together (so an NPC craft to a spline for example)
            But without more knowledge of the sub-types, I'm going to elide parsing the extra names.
            */
            fread(name, sizeof(char), header.item_size - header.item_name_offset, src);
            printf("\t\tEntry %d, Name: %s\n", i, name);
            printf("\t\t\tName Hash:   0x%02x\n", name_hash(name));
        }
        printf("\t\t\tSub-type:    0x%04x\n", header.sub_type);
        printf("\t\t\tIndex:       0x%04x\n", header.item_index);
        printf("\t\t\tSize:        0x%08x\n", header.item_size);
        printf("\t\t\tName Offset: 0x%08x\n", header.item_name_offset);
    }
}

struct map_entry {
    uint32_t sub_type;
    uint32_t index;
};

void parse_item_map(FILE *src) {
    uint32_t map_size;
    uint32_t listOffset;
    uint32_t offsetListOffset;
    struct map_entry map_entry;
    fseek(src, 0x40, SEEK_SET);

    fread(&map_size,         sizeof(uint32_t), 1, src);
    fread(&offsetListOffset, sizeof(uint32_t), 1, src);

    map_size         = be32toh(map_size);
    offsetListOffset = be32toh(offsetListOffset);

    printf("\tItem Map\n");
    printf("\t\t| Name Hash | Entries |\n");
    for (int i = 0; i < 256; i++) {
        fseek(src, offsetListOffset + i*4, SEEK_SET);
        fread(&listOffset, sizeof(uint32_t), 1, src);
        listOffset = be32toh(listOffset);

        printf("\t\t|    0x%02x   | ", i);
        if (listOffset == 0) {
            printf("NULL |\n");
        } else {
            listOffset += offsetListOffset;
            fseek(src, listOffset, SEEK_SET);

            fread(&map_entry, sizeof(struct map_entry), 1, src);
            map_entry.sub_type = be32toh(map_entry.sub_type);
            map_entry.index = be32toh(map_entry.index);
            do {
                printf("(0x%02x, 0x%04x) ->", map_entry.sub_type, map_entry.index);
                fread(&map_entry, sizeof(struct map_entry), 1, src);
                map_entry.sub_type = be32toh(map_entry.sub_type);
                map_entry.index = be32toh(map_entry.index);
            } while(map_entry.sub_type != 0xFFFFFFFF);
            printf(" |\n");
        }
    }
}

int main(int argc, char *argv[]) {
    FILE *src;

    src = fopen(argv[1], "rb");

    if (src == NULL) {
        printf("Failed to open %s\n", argv[1]);
        return 1;
    }

    printf("%s\n", argv[1]);

    for (int i = 0; i < 8; i++) {
        parse_type(src, i);
    }
    parse_item_map(src);
    printf("\n\n");

    fclose(src);

    return 0;
}
