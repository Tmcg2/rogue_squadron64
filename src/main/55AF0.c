#include "common.h"

#include "main/55AF0.h"

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

INCLUDE_ASM("asm/nonmatchings/main/55AF0", loadAndRelocateAsset);

INCLUDE_ASM("asm/nonmatchings/main/55AF0", fake_func_800555E8);
