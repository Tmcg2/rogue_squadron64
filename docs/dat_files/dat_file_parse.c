#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <endian.h>

enum DAT_SUBTYPE {
    /* 0x00 */ DAT_UNKNOWN_00,
    /* 0x01 */ DAT_TYPE_0_PLAYER_START_POSITION,
    /* 0x02 */ DAT_TYPE_0_RESTART_POSITION, // Mostly used by players, but used for Moff Seerdon too
    /* 0x03 */ DAT_TYPE_3_03, // "regular" spline type
    /* 0x04 */ DAT_TYPE_6_HIGH_LOD_BOX, // Name is speculative
    /* 0x05 */ DAT_TYPE_6_LOW_LOD_BOX, // Name is speculative
    /* 0x06 */ DAT_TYPE_0_HANGAR_SUBTYPE0, // Only used in the hangar, mostly in reference to the player craft
    /* 0x07 */ DAT_TYPE_0_HANGAR_SUBTYPE1, // Used in the hangar, bridge, and logo scenes, purpose unknown
    /* 0x08 */ DAT_TYPE_3_08, // Another spline type, only used in the hangar and the logo scenes
    /* 0x09 */ DAT_TYPE_2_09,
    /* 0x0A */ DAT_UNKNOWN_0A,
    /* 0x0B */ DAT_UNKNOWN_0B,
    /* 0x0C */ DAT_TYPE_0_TIE_FIGHTER,
    /* 0x0D */ DAT_TYPE_0_GUN_TURRET,
    /* 0x0E */ DAT_TYPE_0_PROBE_DROID,
    /* 0x0F */ DAT_TYPE_0_ATAT,
    /* 0x10 */ DAT_TYPE_6_MUSIC_RNG,
    /* 0x11 */ DAT_TYPE_7_11, // Could be boxes for event activation?
    /* 0x12 */ DAT_TYPE_0_TIE_INTERCEPTOR,
    /* 0x13 */ DAT_TYPE_0_TIE_BOMBER,
    /* 0x14 */ DAT_TYPE_0_GENERIC_BUILDING, // These trigger the loading of the "destroyed building" model
    /* 0x15 */ DAT_UNKNOWN_15,
    /* 0x16 */ DAT_TYPE_6_16,
    /* 0x17 */ DAT_TYPE_7_17, // Could be spheres for event activation?
    /* 0x18 */ DAT_TYPE_7_18, // Could be timers for event activation?
    /* 0x19 */ DAT_TYPE_7_19, // ??
    /* 0x1A */ DAT_TYPE_7_1A, // One of the NONAME entry types
    /* 0x1B */ DAT_TYPE_7_1B, // One of the NONAME entry types
    /* 0x1B */ DAT_TYPE_7_1C, // One of the NONAME entry types
    /* 0x1D */ DAT_UNKNOWN_1D,
    /* 0x1E */ DAT_TYPE_0_MISSLE_TURRET,
    /* 0x1F */ DAT_TYPE_0_ATST,
    /* 0x1B */ DAT_TYPE_7_20, // One of the NONAME entry types
    /* 0x21 */ DAT_TYPE_0_21, // Stationary NPC spawn locations?
    /* 0x22 */ DAT_TYPE_7_22, // One of the NONAME entry types
    /* 0x23 */ DAT_TYPE_7_23, // One of the NONAME entry types
    /* 0x24 */ DAT_TYPE_0_SHUTTLE,
    /* 0x25 */ DAT_TYPE_0_TANK_DROID,
    /* 0x26 */ DAT_TYPE_0_CAMERA_POSITION,
    /* 0x27 */ DAT_TYPE_0_WINGMAN_POSITION, // Has a sub-sub-type to indicate the exact craft to be used
    /*
    This is really 3 models under one sub-type:
    The Gerrard V mega turrets
    The Trench Run mega turrets
    The generic mega turrets

    The exact model chosen is decided by the currently loaded level
    */
    /* 0x28 */ DAT_TYPE_0_MEGA_TURRENT,
    /* 0x29 */ DAT_TYPE_0_TIE_D, // ??????
    /* 0x2A */ DAT_TYPE_0_RADAR_DISH,
    /* 0x2B */ DAT_TYPE_0_REBEL_TRANSPORT,
    /* 0x2C */ DAT_TYPE_0_HEAVY_SHUTTLE,
    /* 0x2D */ DAT_TYPE_0_CARGO_01,
    /* 0x2E */ DAT_TYPE_0_REBEL_COMBAT, // Don't know exactly what this is...
    // All three of these load the same model, I'm not sure why they're separate sub-types
    /* 0x2F */ DAT_TYPE_0_IMPERIAL_TRAIN0,
    /* 0x30 */ DAT_TYPE_0_IMPERIAL_TRAIN1,
    /* 0x31 */ DAT_TYPE_0_IMPERIAL_TRAIN2,
    /* 0x32 */ DAT_TYPE_0_SHIELD, // ?????
    /* 0x33 */ DAT_TYPE_0_IMPERIAL_TRAIN_PILLAR,
    // Both of these load the same model, I'm not sure why they're separate sub-types
    /* 0x34 */ DAT_TYPE_0_REBEL_TRAIN0,
    /* 0x35 */ DAT_TYPE_0_REBEL_TRAIN1,
    /* 0x36 */ DAT_TYPE_0_REBEL_TRAIN_PILLAR,
    /* 0x37 */ DAT_TYPE_0_WORLD_DEVASTATOR,
    /* 0x38 */ DAT_UNKNOWN_38,
    /* 0x39 */ DAT_TYPE_6_39, // One of the NONAME entry types
    /* 0x3A */ DAT_TYPE_7_3A, // One of the NONAME entry types
    /* 0x3B */ DAT_TYPE_0_IMPERIAL_TROOPER,
    /* 0x3C */ DAT_TYPE_0_REBEL_PILOT,
    /* 0x3D */ DAT_TYPE_0_CIVILIAN,
    /* 0x3E */ DAT_TYPE_0_ASSAULT_BOAT,
    /* 0x3F */ DAT_UNKNOWN_3F,
    /* 0x40 */ DAT_TYPE_0_WAVE_SKIMMER,
    /* 0x41 */ DAT_TYPE_0_REBEL_TURRET,
    /* 0x42 */ DAT_TYPE_0_TALORAAN_TURRET,
    /* 0x43 */ DAT_TYPE_0_CLOUD_CAR,
    /* 0x44 */ DAT_TYPE_0_IMPERIAL_PLATFORM, // Not sure what exactly this is, maybe the floating platforms in the Taloraan level
    /* 0x45 */ DAT_UNKNOWN_45,
    /* 0x46 */ DAT_TYPE_0_46, // Moving NPC spawn position?
    /* 0x47 */ DAT_TYPE_0_ATPT,
    /* 0x48 */ DAT_TYPE_0_BOSS_HUT, // Only shows up once, named "MOFF SEERDON"
    /* 0x49 */ DAT_TYPE_0_WORLD_DEVASTATOR_GUN,
    /* 0x4A */ DAT_TYPE_0_POWER_GENERATOR,
    /* 0x4B */ DAT_TYPE_0_4B, // Large generic buildings?
    /* 0x4C */ DAT_TYPE_0_POWER_UP,
    /* 0x4D */ DAT_TYPE_0_HEAVY_RAPTOR_SHUTTLE,
    /* 0x4E */ DAT_TYPE_7_4E, // One of the NONAME entry types
    /* 0x4F */ DAT_TYPE_0_EXHAUST_PORT, // Death Star exhaust port
    /* 0x50 */ DAT_TYPE_0_B_SOLDIER, // Not present in any DAT files
    /* 0x51 */ DAT_TYPE_2_LAVA_FARTS, // Only used by the Raid on Sullust level
    /* 0x52 */ DAT_TYPE_0_52, // One of the NONAME entry types
    /* 0x53 */ DAT_NUM_SUBTYPES,
};

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

void parse_objective_stuff(FILE *src, uint32_t entryOffset) {
    uint32_t group1Index;
    uint32_t group1Value;
    uint32_t flagIndex;
    uint32_t flagValue;
    uint32_t group2Index;
    uint32_t group2Value;

    fseek(src, entryOffset + 0x70, SEEK_SET);
    fread(&group1Index, sizeof(uint32_t), 1, src);
    fread(&group1Value, sizeof(uint32_t), 1, src);
    fread(&flagIndex,   sizeof(uint32_t), 1, src);
    fread(&flagValue,   sizeof(uint32_t), 1, src);
    fread(&group2Index, sizeof(uint32_t), 1, src);
    fread(&group2Value, sizeof(uint32_t), 1, src);

    group1Index = be32toh(group1Index);
    group1Value = be32toh(group1Value);
    flagIndex   = be32toh(flagIndex);
    flagValue   = be32toh(flagValue);
    group2Index = be32toh(group2Index);
    group2Value = be32toh(group2Value);

    if (group1Index != 0) {
        printf("\t\t\tGroup 1 Index: %d\n", group1Index);
        printf("\t\t\tGroup 1 Value: %d\n", group1Value);
    }
    if (flagIndex != 0) {
        printf("\t\t\tFlag Index:    %d\n", flagIndex);
        printf("\t\t\tFlag Value:    %d\n", flagValue);
    }
    if (group2Index != 0) {
        printf("\t\t\tGroup 2 Index: %d\n", group2Index);
        printf("\t\t\tGroup 2 Value: %d\n", group2Value);
    }
}

void parse_health(FILE *src, uint32_t entryOffset) {
    uint32_t health;

    fseek(src, entryOffset + 0x6C, SEEK_SET);
    fread(&health, sizeof(uint32_t), 1, src);
    health = be32toh(health);
    printf("\t\t\tHealth:        %d\n", health);
}

void parse_extra_string(FILE *src, struct entry_header *header, uint32_t entryOffset, uint32_t extraOffsetOffset, char *extraName) {
    char name[256];
    uint32_t extraOffset;

    // Offset to the name of a Type 7 item that is for this probe droid
    fseek(src, entryOffset + extraOffsetOffset, SEEK_SET);
    fread(&extraOffset, sizeof(uint32_t), 1, src);
    extraOffset = be32toh(extraOffset);
    if (extraOffset != 0) {
        fseek(src, entryOffset + extraOffset, SEEK_SET);
        fread(name, sizeof(char), header->item_size - extraOffset, src);
        printf("\t\t\t%s%s\n", extraName, name);
    } else {
        printf("\t\t\t%sNULL\n", extraName);
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////

void parse_destructible_building_invariant_model(FILE *src, struct entry_header *header, uint32_t entryOffset) {
    parse_health(src, entryOffset);
    parse_objective_stuff(src, entryOffset);
}

void parse_destructible_building_variable_model(FILE *src, struct entry_header *header, uint32_t entryOffset) {
    parse_health(src, entryOffset);
    parse_objective_stuff(src, entryOffset);
    parse_extra_string(src, header, entryOffset, 0x5C, "Model Name:    ");
}

void parse_indestructible_building(FILE *src, struct entry_header *header, uint32_t entryOffset) {
    // No health, which by extension means...
    // No objective booleans/counts to be updating
    parse_extra_string(src, header, entryOffset, 0x5C, "Model Name:    ");
}

void parse_box_bound_npc(FILE *src, struct entry_header *header, uint32_t entryOffset) {
    parse_health(src, entryOffset);
    parse_objective_stuff(src, entryOffset);
    parse_extra_string(src, header, entryOffset, 0x8C, "Box Name:      ");
}

void parse_spline_following_npc(FILE *src, struct entry_header *header, uint32_t entryOffset) {
    parse_health(src, entryOffset);
    parse_objective_stuff(src, entryOffset);
    parse_extra_string(src, header, entryOffset, 0x8C, "Spline Name:   ");
}

void parse_wingman(FILE *src, struct entry_header *header, uint32_t entryOffset) {
    parse_health(src, entryOffset);
    parse_objective_stuff(src, entryOffset);
    parse_extra_string(src, header, entryOffset, 0x94, "Spline Name:   ");
}

void parse_camera(FILE *src, struct entry_header *header, uint32_t entryOffset) {
    parse_extra_string(src, header, entryOffset, 0x64, "Focus Target:  ");
    parse_extra_string(src, header, entryOffset, 0x68, "Next Camera:   ");
}

/////////////////////////////////////////////////////////////////////////////////////////////

void parse_type0_subtype46(FILE *src, struct entry_header *header, uint32_t entryOffset) {
    parse_health(src, entryOffset);
    parse_objective_stuff(src, entryOffset);
    parse_extra_string(src, header, entryOffset, 0x5C, "Model Name:    ");
    parse_extra_string(src, header, entryOffset, 0x90, "Spline Name:   ");
}

/////////////////////////////////////////////////////////////////////////////////////////////

void parse_world_dev(FILE *src, struct entry_header *header, uint32_t entryOffset) {
    parse_health(src, entryOffset);
    parse_objective_stuff(src, entryOffset);
    parse_extra_string(src, header, entryOffset, 0x8C, "Spline Name:   ");
    parse_extra_string(src, header, entryOffset, 0xE4, "Gun Instance:  ");
    parse_extra_string(src, header, entryOffset, 0xE8, "Gun Instance:  ");
    parse_extra_string(src, header, entryOffset, 0xEC, "Gun Instance:  ");
    parse_extra_string(src, header, entryOffset, 0xE0, "Gun Instance:  ");
    parse_extra_string(src, header, entryOffset, 0xF4, "Gun Instance:  ");
}

/////////////////////////////////////////////////////////////////////////////////////////////

void parse_extra(FILE *src, struct entry_header *header, uint32_t entryOffset)  {
        switch(header->sub_type) {
            case DAT_TYPE_0_4B:
            case DAT_TYPE_0_EXHAUST_PORT:
            case DAT_TYPE_0_IMPERIAL_PLATFORM:
            case DAT_TYPE_0_REBEL_TRAIN_PILLAR:
            case DAT_TYPE_0_IMPERIAL_TRAIN_PILLAR:
                parse_indestructible_building(src, header, entryOffset);
                break;
            case DAT_TYPE_0_21:
            case DAT_TYPE_0_POWER_GENERATOR:
            case DAT_TYPE_0_GENERIC_BUILDING:
                parse_destructible_building_variable_model(src, header, entryOffset);
                break;
            case DAT_TYPE_0_RADAR_DISH:
            case DAT_TYPE_0_GUN_TURRET:
            case DAT_TYPE_0_MEGA_TURRENT:
            case DAT_TYPE_0_REBEL_TURRET:
            case DAT_TYPE_0_MISSLE_TURRET:
            case DAT_TYPE_0_TALORAAN_TURRET:
                parse_destructible_building_invariant_model(src, header, entryOffset);
                break;
            case DAT_TYPE_0_ATAT:
            case DAT_TYPE_0_ATPT:
            case DAT_TYPE_0_ATST:
            case DAT_TYPE_0_TIE_D:
            case DAT_TYPE_0_SHUTTLE:
            case DAT_TYPE_0_BOSS_HUT:
            case DAT_TYPE_0_CARGO_01:
            case DAT_TYPE_0_CLOUD_CAR:
            case DAT_TYPE_0_TIE_BOMBER:
            case DAT_TYPE_0_TANK_DROID:
            case DAT_TYPE_0_TIE_FIGHTER:
            case DAT_TYPE_0_ASSAULT_BOAT:
            case DAT_TYPE_0_WAVE_SKIMMER:
            case DAT_TYPE_0_REBEL_TRAIN0:
            case DAT_TYPE_0_REBEL_TRAIN1:
            case DAT_TYPE_0_REBEL_COMBAT:
            case DAT_TYPE_0_HEAVY_SHUTTLE:
            case DAT_TYPE_0_REBEL_TRANSPORT:
            case DAT_TYPE_0_TIE_INTERCEPTOR:
            case DAT_TYPE_0_IMPERIAL_TRAIN0:
            case DAT_TYPE_0_IMPERIAL_TRAIN1:
            case DAT_TYPE_0_IMPERIAL_TRAIN2:
            case DAT_TYPE_0_HEAVY_RAPTOR_SHUTTLE:
                parse_spline_following_npc(src, header, entryOffset);
                break;
            case DAT_TYPE_0_CIVILIAN:
            case DAT_TYPE_0_PROBE_DROID:
            case DAT_TYPE_0_REBEL_PILOT:
            case DAT_TYPE_0_IMPERIAL_TROOPER:
                parse_box_bound_npc(src, header, entryOffset);
                break;
            case DAT_TYPE_0_CAMERA_POSITION:
                parse_camera(src, header, entryOffset);
                break;
            case DAT_TYPE_0_WINGMAN_POSITION:
                parse_wingman(src, header, entryOffset);
                break;
            case DAT_TYPE_0_46:
                parse_type0_subtype46(src, header, entryOffset);
                break;
            case DAT_TYPE_0_WORLD_DEVASTATOR:
                parse_world_dev(src, header, entryOffset);
                break;
            default:
                break;
        }
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
            printf("\t\tEntry %d, Name:    NULL\n", i);
        } else {
            fseek(src, entryOffset + header.item_name_offset, SEEK_SET);
            /*
            There are some sub-types that have (at least) one extra name after the main one.
            Presumably this is to link items together (so an NPC craft to a spline for example)
            But without more knowledge of the sub-types, I'm going to elide parsing the extra names.
            */
            fread(name, sizeof(char), header.item_size - header.item_name_offset, src);
            printf("\t\tEntry %d, Name:    %s\n", i, name);
            printf("\t\t\tName Hash:     0x%02x\n", name_hash(name));
        }
        printf("\t\t\tEntry Offset:  0x%08x\n", entryOffset);
        printf("\t\t\tSub-type:      0x%04x\n", header.sub_type);
        printf("\t\t\tIndex:         0x%04x\n", header.item_index);
        printf("\t\t\tSize:          0x%08x\n", header.item_size);
        printf("\t\t\tName Offset:   0x%08x\n", header.item_name_offset);

        parse_extra(src, &header, entryOffset);
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
        if (listOffset == 0) continue;

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
