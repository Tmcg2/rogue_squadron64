#include <stdio.h>
#include <stdint.h>
#include <endian.h>
#include <stdlib.h>

#define print_visual_separator() do { printf("================================================================================================================================\n"); } while(0)

void parse_u16_subsection(FILE *proj, uint32_t subsection_start) {
    uint16_t data;
    uint32_t count = 0;

    fseek(proj, subsection_start, SEEK_SET);
    do {
        fread(&data, sizeof(uint16_t), 1, proj);
        data = be16toh(data);
        if ((count % 8) == 0) printf("\t\t");
        printf("%04x", data);
        count++;
        if ((count % 8) == 0) printf("\n");
        else printf(" ");
    } while(data != 0xFFFF);
    if ((count % 8) != 0) printf("\n");
    return;
}

void parse_common_subsegments(FILE *proj, uint32_t section_start) {
    for (int i = 0; i < 5; i++) {
        uint32_t subsection_start;

        fseek(proj, section_start + 8 + 4*i, SEEK_SET);
        fread(&subsection_start, sizeof(uint32_t), 1, proj);
        subsection_start = be32toh(subsection_start);
        subsection_start += section_start + 8;

        printf("\tSubsection %d at 0x%08x:\n", i, subsection_start);
        parse_u16_subsection(proj, subsection_start);
    }
}

void parse_type0_subsegment5(FILE *proj, uint32_t section_start) {
    struct type0_special1 {
        uint32_t unk00;
        uint8_t  unk04;
        uint8_t  unk05;
        // 3 bytes of padding
    };  // size = 0x8

    uint32_t subsection_start;
    struct type0_special1 data;

    fseek(proj, section_start + 0x1C, SEEK_SET);
    fread(&subsection_start, sizeof(uint32_t), 1, proj);
    subsection_start = be32toh(subsection_start);
    subsection_start += section_start + 8;

    fseek(proj, subsection_start, SEEK_SET);

    printf("\tSubsection 5 at 0x%08x:\n", subsection_start);
    do {
        fread(&data, sizeof(struct type0_special1), 1, proj);
        data.unk00 = be32toh(data.unk00);
        printf("\t\tunk00: 0x%08x, unk04: 0x%02x, unk05: 0x%02x\n", data.unk00, data.unk04, data.unk05);
    } while (data.unk05 != 0xFF);
    return;
}

void parse_type0_subsegment6(FILE *proj, uint32_t section_start) {
    struct type0_special2 {
        uint32_t unk00;
        uint8_t  unk04;
        uint8_t  unk05;
        // 3 bytes of padding
    };  // size = 0x8

    uint32_t subsection_start;
    struct type0_special2 data;

    fseek(proj, section_start + 0x20, SEEK_SET);
    fread(&subsection_start, sizeof(uint32_t), 1, proj);
    subsection_start = be32toh(subsection_start);
    subsection_start += section_start + 8;

    fseek(proj, subsection_start, SEEK_SET);

    printf("\tSubsection 6 at 0x%08x:\n", subsection_start);
    do {
        fread(&data, sizeof(struct type0_special2), 1, proj);
        data.unk00 = be32toh(data.unk00);
        printf("\t\tunk00: 0x%08x, unk04: 0x%02x, unk05: 0x%02x\n", data.unk00, data.unk04, data.unk05);
    } while (data.unk05 != 0xFF);
    return;
}

void parse_type0_subsegment7(FILE *proj, uint32_t section_start) {
    struct type0_special3 {
        uint32_t unk00;
        uint8_t  unk04;
        // 3 bytes of padding
    };  // size = 0x8

    uint32_t subsection_start;
    struct type0_special3 data;

    fseek(proj, section_start + 0x24, SEEK_SET);
    fread(&subsection_start, sizeof(uint32_t), 1, proj);
    subsection_start = be32toh(subsection_start);
    subsection_start += section_start + 8;

    fseek(proj, subsection_start, SEEK_SET);
    fseek(proj, 4, SEEK_CUR);

    printf("\tSubsection 7 at 0x%08x:\n", subsection_start);
    for (int i = 0; i < 16; i++) {
        fread(&data, sizeof(struct type0_special3), 1, proj);
        data.unk00 = be32toh(data.unk00);
        printf("\t\tunk00: 0x%08x, unk04: 0x%02x\n", data.unk00, data.unk04);
    }
    return;
}

void parse_type0(FILE *proj, uint32_t section_start) {
    parse_common_subsegments(proj, section_start);
    parse_type0_subsegment5(proj, section_start);
    parse_type0_subsegment6(proj, section_start);
    parse_type0_subsegment7(proj, section_start);
    return;
}

void parse_type1_subsegment5(FILE *proj, uint32_t section_start) {
    struct type1_special {
        uint16_t id;
        uint16_t unk02;
        uint32_t unk04;
        uint8_t  unk08;
        // 3 bytes of padding
    };  // size = 0xC

    uint32_t count;
    uint32_t subsection_start;
    struct type1_special data;

    fseek(proj, section_start + 0x1C, SEEK_SET);
    fread(&subsection_start, sizeof(uint32_t), 1, proj);
    subsection_start = be32toh(subsection_start);
    subsection_start += section_start + 8;

    fseek(proj, subsection_start, SEEK_SET);
    fread(&count, sizeof(uint16_t), 1, proj);
    count = be16toh(count);
    fseek(proj, sizeof(uint16_t), SEEK_CUR);

    printf("\tSubsection 5 at 0x%08x, count 0x%04x:\n", subsection_start, count);
    for (int i = 0; i < count; i++) {
        fread(&data, sizeof(struct type1_special), 1, proj);
        data.id    = be16toh(data.id);
        data.unk02 = be16toh(data.unk02);
        data.unk04 = be32toh(data.unk04);
        printf("\t\tid: 0x%04x, unk02: 0x%04x, unk04: 0x%08x, unk08: 0x%02x\n", data.id, data.unk02, data.unk04, data.unk08);
    }
    return;
}

void parse_type1(FILE *proj, uint32_t section_start) {
    parse_common_subsegments(proj, section_start);
    parse_type1_subsegment5(proj, section_start);
    return;
}

void parse_proj(FILE *proj) {
    uint32_t end;
    uint32_t section_size;
    uint32_t section_start = 0;
    uint32_t section_count = 0;

    printf("proj_SND\n");

    fread(&section_size, sizeof(uint32_t), 1, proj);
    section_size = be32toh(section_size);
    while (section_size != 0xFFFFFFFF) {
        uint16_t id;
        uint16_t type;
        fread(&id,   sizeof(uint16_t), 1, proj);
        fread(&type, sizeof(uint16_t), 1, proj);

        id   = be16toh(id);
        type = be16toh(type);

        printf("Section %2d at 0x%08x, id 0x%04x, type 0x%04x:\n", section_count++, section_start, id, type);

        switch (type) {
        case 0:
            parse_type0(proj, section_start);
            break;
        case 1:
            parse_type1(proj, section_start);
            break;
        default:
            printf("\tUnimplemented type\n");
            break;
        }
        printf("\n");

        section_start += section_size;
        fseek(proj, section_start, SEEK_SET);
        fread(&section_size, sizeof(uint32_t), 1, proj);
        section_size = be32toh(section_size);
    }
}

void parse_sdir(FILE *sdir) {
    struct sdir_type {
        uint16_t id;
        uint16_t unk02;
        uint32_t unk04;
        uint32_t unk08;
        uint32_t unk0C;
        uint32_t unk10;
        uint32_t unk14;
    }; // size = 0x18

    uint32_t count = 0;
    struct sdir_type data;

    printf("sdir_SND\n");

    fread(&data, sizeof(struct sdir_type), 1, sdir);
    while (data.id != 0xFFFF) {
        data.id    = be16toh(data.id);
        data.unk02 = be16toh(data.unk02);
        data.unk04 = be32toh(data.unk04);
        data.unk08 = be32toh(data.unk08);
        data.unk0C = be32toh(data.unk0C);
        data.unk10 = be32toh(data.unk10);
        data.unk14 = be32toh(data.unk14);

        printf("\tItem %03d\n", count++);
        printf("\t\tid: 0x%04x, unk02: 0x%04x, unk04: 0x%08x, unk08: 0x%08x, unk0C: 0x%08x, unk10: 0x%08x, unk14: 0x%08x\n",
        data.id, data.unk02, data.unk04, data.unk08, data.unk0C, data.unk10, data.unk14);
        fread(&data, sizeof(struct sdir_type), 1, sdir);
    }
    printf("\n\n");
}

void parse_pool_section(FILE *pool, uint32_t section_start) {
    uint16_t id;
    uint32_t data;
    uint32_t size;
    uint32_t item_count;
    uint32_t current_offset;
    uint32_t subsection_count = 0;

    current_offset = section_start;
    fseek(pool, current_offset, SEEK_SET);

    fread(&size, sizeof(uint32_t), 1, pool);
    fread(&id, sizeof(uint16_t), 1, pool);
    fseek(pool, 2, SEEK_CUR);
    while (size != 0xFFFFFFFF) {
        id          = be16toh(id);
        size = be32toh(size);

        printf("\tSubsection %03d at 0x%08x, size: 0x%08x id: 0x%04x\n", subsection_count++, current_offset, size, id);
        item_count = 0;
        while (item_count < (size - 8) / 4) {
            fread(&data, sizeof(uint32_t), 1, pool);
            data = be32toh(data);
            if ((item_count % 4) == 0) printf("\t\t");
            printf("%08x", data);
            item_count++;
            if ((item_count % 4) == 0) printf("\n");
            else printf(" ");
        }
        if ((item_count % 4) != 0) printf("\n");

        current_offset += size;
        fseek(pool, current_offset, SEEK_SET);
        fread(&size, sizeof(uint32_t), 1, pool);
        fread(&id, sizeof(uint16_t), 1, pool);
        fseek(pool, 2, SEEK_CUR);
    }
    printf("\n");
}

void parse_pool(FILE *pool) {
    uint32_t section_offset;

    printf("pool_SND\n");

    for (int i = 0; i < 4; i++) {
        printf("Section %d\n", i);
        fseek(pool, i*4, SEEK_SET);
        fread(&section_offset, sizeof(uint32_t), 1, pool);
        section_offset = be32toh(section_offset);
        parse_pool_section(pool, section_offset);
    }
}

int main(int argc, char *argv[]) {
    printf("\n");

    FILE *pool = fopen("./data_blob/data/sound/pool_SND", "rb");
    parse_pool(pool);
    fclose(pool);

    print_visual_separator();
    print_visual_separator();
    print_visual_separator();
    printf("\n");
    
    FILE *proj = fopen("./data_blob/data/sound/proj_SND", "rb");
    parse_proj(proj);
    fclose(proj);

    print_visual_separator();
    print_visual_separator();
    print_visual_separator();
    printf("\n");

    FILE *sdir = fopen("./data_blob/data/sound/sdir_SND", "rb");
    parse_sdir(sdir);
    fclose(sdir);

    return 0;
}
