#include "common.h"

#include "textures.h"

#include "main/55AF0.h"
#include "main/64EA0.h"

INCLUDE_ASM("asm/nonmatchings/main/55AF0", loadAssetAndIterateSubchunks);

INCLUDE_ASM("asm/nonmatchings/main/55AF0", loadSpriteSheetTextureFrames);

void full_header_image_offset_convert(struct texture_entry *texture_entry, u32 file_base_addr) {
    s32 var_a2;

    for (var_a2 = 0; var_a2 < 8; var_a2++) {
        if (texture_entry->pixel_offsets[var_a2] != NULL) {
            texture_entry->pixel_offsets[var_a2] += file_base_addr;
        }
    }
    if (texture_entry->plte_offset != NULL) {
        texture_entry->plte_offset += file_base_addr;
    }
    if (texture_entry->texture_name_offset != NULL) {
        texture_entry->texture_name_offset += file_base_addr;
    }
}

u16 loadAndRelocateAsset(char *arg0, char *arg1, u32 arg2) {
    u16 temp_s0;
    s32 var_a0;
    u32 base_addr;
    struct material_entry sp10;
    struct full_image_header *temp_v0;
    struct texture_entry *why;

    temp_v0 = load_asset(arg0);
    why = &temp_v0->ent;
    base_addr = why->pixel_offsets;
    for(var_a0 = 0; var_a0 < 8; var_a0++) {
        if (why->pixel_offsets[var_a0] != NULL) {
            why->pixel_offsets[var_a0] += base_addr;
        }
    }
    if (why->plte_offset != NULL) {
        why->plte_offset += base_addr;
    }
    if (why->texture_name_offset != NULL) {
        why->texture_name_offset += base_addr;
    }
    sp10.material_type = 1;
    sp10.zero = 0;
    sp10.alwaysa = 1;
    sp10.misc_float = 0.2f;
    sp10.one = 1.0f;
    temp_v0->ent.flags_type |= arg2;
    if (arg1 != NULL) {
        rs_strncpy(sp10.material_name, arg1, 0x10U);
        temp_v0->ent.texture_name_offset = sp10.material_name;
    } else {
        rs_strncpy(sp10.material_name, temp_v0->ent.texture_name_offset, 0x10U);
    }
    temp_s0 = registerHmtTextureInTable(&sp10, &temp_v0->ent, 0U);
    rs_free(temp_v0);
    return temp_s0;
}

INCLUDE_ASM("asm/nonmatchings/main/55AF0", fake_func_800555E8);
