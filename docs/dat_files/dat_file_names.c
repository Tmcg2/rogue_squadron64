#include <spng.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <endian.h>

struct item_list {
    const uint32_t item_type;
    const uint32_t item_count_offset;
    uint32_t item_count;
    uint32_t offset_list_offset;
    uint32_t *offset_list;
    char **item_names;
};

struct collection_entry {
    uint32_t item_type;
    uint32_t item_index;
};

void item_handle(FILE *source_file, struct item_list *item_list) {
    uint32_t item_count;
    uint32_t next_item_offset, item_name_offset;
    uint32_t name_size;
    char item_name[256];

    fseek(source_file, item_list->item_count_offset, SEEK_SET);
    fread(&item_count, sizeof(uint32_t), 1, source_file);
    item_count = be32toh(item_count);

    if (item_count == 0) {
        printf("No Item %d entries\n", item_list->item_type);
        return;
    }

    fread(&item_list->offset_list_offset, sizeof(uint32_t), 1, source_file);
    item_list->offset_list_offset = be32toh(item_list->offset_list_offset);

    item_list->offset_list = malloc(sizeof(uint32_t) * item_count);
    item_list->item_names = calloc(sizeof(char*), item_count);

    fseek(source_file, item_list->offset_list_offset, SEEK_SET);
    fread(item_list->offset_list, sizeof(uint32_t), item_count, source_file);
    for (int i = 0; i < item_count; i++) {
        item_list->offset_list[i] = be32toh(item_list->offset_list[i]);
    }

    printf("%d Item %d's:\n", item_count, item_list->item_type);

    for (int i = 0; i < item_count; i++) {
        // It's a little silly to split all these fseeks apart, but it makes things easier for me to track
        fseek(source_file, item_list->offset_list_offset, SEEK_SET);
        fseek(source_file, item_list->offset_list[i], SEEK_CUR);
        fseek(source_file, 0x8, SEEK_CUR);

        fread(&next_item_offset, sizeof(uint32_t), 1, source_file);
        next_item_offset = be32toh(next_item_offset);

        fread(&item_name_offset, sizeof(uint32_t), 1, source_file);
        item_name_offset = be32toh(item_name_offset);

        if (item_name_offset == 0) {
            printf("\tNONAME at %#010x\n", item_list->offset_list_offset + item_list->offset_list[i]);
        } else {
            name_size = next_item_offset - item_name_offset;
            item_list->item_names[i] = calloc(sizeof(char), (name_size + 1));
            fseek(source_file, item_name_offset - 0x10, SEEK_CUR);
            fread(item_list->item_names[i], sizeof(char), name_size, source_file);
            printf("\t%d: %s\n", i, item_list->item_names[i]);
        }
    }
}

int main(int argc, char *argv[]) {
    FILE *source_file;

    uint32_t item_collection_size;
    uint32_t item_collection_offset;
    uint32_t collection_count;
    uint32_t collection_offsets[256];
    uint32_t item_type;
    uint32_t item_index;
    char *item_name;

    struct item_list item0_list = { 0, 0x00, 0, 0, NULL, NULL };
    struct item_list item2_list = { 2, 0x10, 0, 0, NULL, NULL };
    struct item_list item3_list = { 3, 0x18, 0, 0, NULL, NULL };
    struct item_list item6_list = { 6, 0x30, 0, 0, NULL, NULL };
    struct item_list item7_list = { 7, 0x38, 0, 0, NULL, NULL };

    source_file = fopen(argv[1], "rb");

    if (source_file == NULL) {
        printf("Failed to open the source file\n");
        return -1;
    }

    item_handle(source_file, &item0_list);
    item_handle(source_file, &item2_list);
    item_handle(source_file, &item3_list);
    item_handle(source_file, &item6_list);
    item_handle(source_file, &item7_list);

    fseek(source_file, 0x40, SEEK_SET);
    fread(&item_collection_size, sizeof(uint32_t), 1, source_file);
    item_collection_size = be32toh(item_collection_size);
    item_collection_size -= sizeof(uint32_t) * 256;

    collection_count = item_collection_size / 8;

    fread(&item_collection_offset, sizeof(uint32_t), 1, source_file);
    item_collection_offset = be32toh(item_collection_offset);

    fseek(source_file, item_collection_offset, SEEK_SET);
    fread(collection_offsets, sizeof(uint32_t), 256, source_file);

    for (int i = 0; i < 256; i++) {
        collection_offsets[i] = be32toh(collection_offsets[i]);

        if (collection_offsets[i] == 0) continue;

        fseek(source_file, item_collection_offset + collection_offsets[i], SEEK_SET);

        fread(&item_type, sizeof(uint32_t), 1, source_file);
        item_type = be32toh(item_type);
        fread(&item_index, sizeof(uint32_t), 1, source_file);
        item_index = be32toh(item_index);

        while (item_type != 0xFFFFFFFF) {
            switch(item_type) {
            case 0:
                item_name = item0_list.item_names[item_index];
                break;
            case 2:
                item_name = item2_list.item_names[item_index];
                break;
            case 3:
                item_name = item3_list.item_names[item_index];
                break;
            case 6:
                item_name = item6_list.item_names[item_index];
                break;
            case 7:
                item_name = item7_list.item_names[item_index];
                break;
            }

            printf("%s -> ", item_name);

            fread(&item_type, sizeof(uint32_t), 1, source_file);
            item_type = be32toh(item_type);
            fread(&item_index, sizeof(uint32_t), 1, source_file);
            item_index = be32toh(item_index);
        }
        printf("\n");
    }

    fclose(source_file);
    printf("\n");
    // free(item_lists.item0_list.offset_list);
    // free(item_lists.item2_list.offset_list);
    // free(item_lists.item3_list.offset_list);
    // free(item_lists.item6_list.offset_list);
    // free(item_lists.item7_list.offset_list);
    return 0;
}
