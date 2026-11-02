#include "common.h"

#include "main/bss_80130BD0.h"
#include "main/42AF0.h"

INCLUDE_ASM("asm/nonmatchings/main/42AF0", allocAndInitDoublyLinkedNodePool12);

INCLUDE_ASM("asm/nonmatchings/main/42AF0", rasterizeEdgeXSpansAscending);

INCLUDE_ASM("asm/nonmatchings/main/42AF0", rasterizeEdgeXSpansDescending);

INCLUDE_ASM("asm/nonmatchings/main/42AF0", scanConvertTriangleToSpanTable);

INCLUDE_ASM("asm/nonmatchings/main/42AF0", binPolygonIntoTerrainGrid);

INCLUDE_ASM("asm/nonmatchings/main/42AF0", streamTerrainGridCellsByDistance);

INCLUDE_ASM("asm/nonmatchings/main/42AF0", buildGridCellMeshForFace);

INCLUDE_ASM("asm/nonmatchings/main/42AF0", buildVisibleTerrainGridAroundCamera);

void markLowLodCellsInGrid(f32 arg0, f32 arg1, f32 arg2, f32 arg3) {
    s32 var_a0;
    s32 var_a1;
    s32 var_a2;
    s32 var_t0;
    s32 var_t2;

    var_t2 = (s32) ((arg0 - D_main_bss_80136DC0.unk20[0]) * 0.5f);
    if (var_t2 < 0) {
        var_t2 = 0;
    }
    var_a2 = (s32) ((arg1 - D_main_bss_80136DC0.unk20[0]) * 0.5f);
    if (var_a2 >= (s32) D_main_bss_80136DC0.width) {
        var_a2 = D_main_bss_80136DC0.width - 1;
    }
    var_a1 = (s32) ((arg2 - D_main_bss_80136DC0.unk2C[0]) * 0.5f);
    if (var_a1 < 0) {
        var_a1 = 0;
    }
    var_t0 = (s32) ((arg3 - D_main_bss_80136DC0.unk2C[0]) * 0.5f);
    if (var_t0 >= (s32) D_main_bss_80136DC0.height) {
        var_t0 = D_main_bss_80136DC0.height - 1;
    }
    for (; var_a1 <= var_t0; var_a1++) {
        for (var_a0 = var_t2; var_a0 <= var_a2; var_a0++) {
            D_main_bss_80136DC0.tile_indices[var_a0 + (var_a1 * D_main_bss_80136DC0.width)] |= 0x8000;
            D_main_bss_80136DC0.tiles[D_main_bss_80136DC0.tile_indices[var_a0 + (var_a1 * D_main_bss_80136DC0.width)] & 0x1FFF].flags |= 1;
        }
    }
}

void markHighLodCellsInGrid(f32 arg0, f32 arg1, f32 arg2, f32 arg3) {
    s32 var_a0;
    s32 var_a1;
    s32 var_a2;
    s32 var_t0;
    s32 var_t2;

    var_t2 = (s32) ((arg0 - D_main_bss_80136DC0.unk20[0]) * 0.5f);
    if (var_t2 < 0) {
        var_t2 = 0;
    }
    var_a2 = (s32) ((arg1 - D_main_bss_80136DC0.unk20[0]) * 0.5f);
    if (var_a2 >= (s32) D_main_bss_80136DC0.width) {
        var_a2 = D_main_bss_80136DC0.width - 1;
    }
    var_a1 = (s32) ((arg2 - D_main_bss_80136DC0.unk2C[0]) * 0.5f);
    if (var_a1 < 0) {
        var_a1 = 0;
    }
    var_t0 = (s32) ((arg3 - D_main_bss_80136DC0.unk2C[0]) * 0.5f);
    if (var_t0 >= (s32) D_main_bss_80136DC0.height) {
        var_t0 = D_main_bss_80136DC0.height - 1;
    }
    for (; var_a1 <= var_t0; var_a1++) {
        for (var_a0 = var_t2; var_a0 <= var_a2; var_a0++) {
            D_main_bss_80136DC0.tile_indices[var_a0 + (var_a1 * D_main_bss_80136DC0.width)] |= 0x4000;
            D_main_bss_80136DC0.tiles[D_main_bss_80136DC0.tile_indices[var_a0 + (var_a1 * D_main_bss_80136DC0.width)] & 0x1FFF].flags |= 2;
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/main/42AF0", load_level_hmp);

INCLUDE_ASM("asm/nonmatchings/main/42AF0", cutsceneActorNpcHandler);

#if 0
// This funtion is VERY WIP, choosing to move on for now, needs to be revisited
// The first for-loop is decently accurate, I think.
void computeGridTileEdgeAdjacencyMasks(void) {
    u8 temp_a2;
    s32 temp_a2_2;
    s32 temp_a2_3;
    s32 temp_a2_4;
    s32 temp_a2_5;
    s32 temp_t0_7;
    s32 temp_t0_8;
    s32 temp_v0_2;
    s32 var_a0;
    s32 var_a0_2;
    s32 var_a0_3;
    s32 var_a0_4;
    s32 var_a0_5;
    s32 var_a0_6;
    s32 var_a0_7;
    s32 var_a1;
    s32 var_t2;
    s32 var_v0;
    s32 var_v0_2;
    s32 var_v0_3;
    s32 var_v0_4;
    s32 var_v0_5;
    s32 var_v0_6;
    s32 var_v0_7;
    s32 var_v1;
    s32 var_v1_2;
    s32 var_v1_3;
    s32 var_v1_4;
    s32 var_v1_5;
    s8 temp_a0;
    s8 temp_a1;
    s8 temp_a1_2;
    s8 temp_a2_6;
    s8 temp_t0;
    s8 temp_t0_2;
    s8 temp_t0_3;
    s8 temp_t0_4;
    s8 temp_t0_5;
    s8 temp_t0_6;
    s8 temp_t1_2;
    s8 temp_v1_11;
    u16 *var_a3;
    u32 temp_v1;
    u32 temp_v0_3;
    u32 temp_v1_10;
    u32 temp_v1_6;
    u32 temp_v1_7;
    u32 temp_v1_8;
    u32 temp_v1_9;
    u8 *temp_v0;
    u8 temp_t1;
    u8 temp_v1_5;
    u32 var_t1;
    void *var_a3_2;

    temp_v0 = rs_malloc(hmpFile->tile_count, 0U);
    rs_memset(temp_v0, 0xFFU, hmpFile->tile_count);
    for (var_a1 = 0; var_a1 < D_main_bss_80136DC0.height; var_a1++) {
        for (var_a0 = 0; var_a0 < D_main_bss_80136DC0.width; var_a0++) {
            var_t1 = temp_v0[D_main_bss_80136DC0.tile_indices[var_a1 + var_a0] & 0x1FFF];
            if (var_a0 > 0) {
                temp_v1 = D_main_bss_80136DC0.tile_indices[(var_a1 * D_main_bss_80136DC0.width) + var_a0 - 1];
                if (!(temp_v1 & 0xC000)) {
                    var_t1 &= ~0x10;
                }
                if (!(temp_v1 & 0x8000)) {
                    var_t1 &= ~1;
                }
            }
            if (var_a0 < (D_main_bss_80136DC0.width - 1)) {
                temp_v1 = D_main_bss_80136DC0.tile_indices[(var_a1 * D_main_bss_80136DC0.width) + var_a0 + 1];
                if (!(temp_v1 & 0xC000)) {
                    var_t1 &= ~0x20;
                }
                if (!(temp_v1 & 0x8000)) {
                    var_t1 &= ~2;
                }
            }
            if (var_a1 > 0) {
                temp_v1 = D_main_bss_80136DC0.tile_indices[var_a0 + ((var_a1 - 1) * D_main_bss_80136DC0.width)];
                if (!(temp_v1 & 0xC000)) {
                    var_t1 &= ~0x40;
                }
                if (!(temp_v1 & 0x8000)) {
                    var_t1 &= ~4;
                }
            }
            if (var_a1 < (D_main_bss_80136DC0.height - 1)) {
                temp_v1 = D_main_bss_80136DC0.tile_indices[var_a0 + ((var_a1 + 1) * D_main_bss_80136DC0.width)];
                if (!(temp_v1 & 0xC000)) {
                    var_t1 &= ~0x80;
                }
                if (!(temp_v1 & 0x8000)) {
                    var_t1 &= ~0x80;
                }
            }
            temp_v0[D_main_bss_80136DC0.tile_indices[var_a1 + var_a0] & 0x1FFF] = var_t1;
        }
    }
    for (var_t2 = 0; var_t2 < hmpFile->tile_count; var_t2++) {
        temp_v1_5 = D_main_bss_80136DC0.tiles[var_t2].flags;
        var_t1 = temp_v0[var_t2];
        if (temp_v1_5 & 0x18) continue;
        if (temp_v1_5 & 2) {
            if (var_t1 & 0x40) {
                temp_v1_6 = D_main_bss_80136DC0.tiles[var_t2].height_values[4] - D_main_bss_80136DC0.tiles[var_t2].height_values[2];
                D_main_bss_80136DC0.tiles[var_t2].height_values[1] = D_main_bss_80136DC0.tiles[var_t2].height_values[0] + ((D_main_bss_80136DC0.tiles[var_t2].height_values[2] - D_main_bss_80136DC0.tiles[var_t2].height_values[0]) / 2);
                D_main_bss_80136DC0.tiles[var_t2].height_values[3] = D_main_bss_80136DC0.tiles[var_t2].height_values[2] + ((temp_v1_6 + (temp_v1_6 >> 0x1F)) / 2);
            }
            if (var_t1 & 0x10) {
                temp_v1_6 = D_main_bss_80136DC0.tiles[var_t2].height_values[2] - D_main_bss_80136DC0.tiles[var_t2].height_values[10];
                D_main_bss_80136DC0.tiles[var_t2].height_values[5] = D_main_bss_80136DC0.tiles[var_t2].height_values[0] + ((D_main_bss_80136DC0.tiles[var_t2].height_values[10] - D_main_bss_80136DC0.tiles[var_t2].height_values[0]) / 2);
                D_main_bss_80136DC0.tiles[var_t2].height_values[15] = D_main_bss_80136DC0.tiles[var_t2].height_values[10] + ((temp_v1_6 + (temp_v1_6 >> 0x1F)) / 2);
            }
            if (var_t1 & 0x20) {
                temp_v1_6 = D_main_bss_80136DC0.tiles[var_t2].height_values[24] - D_main_bss_80136DC0.tiles[var_t2].height_values[14];
                D_main_bss_80136DC0.tiles[var_t2].height_values[9] = D_main_bss_80136DC0.tiles[var_t2].height_values[4] + ((D_main_bss_80136DC0.tiles[var_t2].height_values[14] - D_main_bss_80136DC0.tiles[var_t2].height_values[4]) / 2);
                D_main_bss_80136DC0.tiles[var_t2].height_values[19] = D_main_bss_80136DC0.tiles[var_t2].height_values[14] + ((temp_v1_6 + (temp_v1_6 >> 0x1F)) / 2);
            }
            if (var_t1 & 0x80) {
                temp_v1_6 = D_main_bss_80136DC0.tiles[var_t2].height_values[24] - D_main_bss_80136DC0.tiles[var_t2].height_values[22];
                D_main_bss_80136DC0.tiles[var_t2].height_values[21] = D_main_bss_80136DC0.tiles[var_t2].height_values[20] + ((D_main_bss_80136DC0.tiles[var_t2].height_values[22] - D_main_bss_80136DC0.tiles[var_t2].height_values[20]) / 2);
                D_main_bss_80136DC0.tiles[var_t2].height_values[23] = D_main_bss_80136DC0.tiles[var_t2].height_values[22] + ((temp_v1_6 + (temp_v1_6 >> 0x1F)) / 2);
            }
            D_main_bss_80136DC0.tiles[var_t2].height_values[6]  = D_main_bss_80136DC0.tiles[var_t2].height_values[0]  + ((D_main_bss_80136DC0.tiles[var_t2].height_values[12] - D_main_bss_80136DC0.tiles[var_t2].height_values[0])  / 2);
            D_main_bss_80136DC0.tiles[var_t2].height_values[7]  = D_main_bss_80136DC0.tiles[var_t2].height_values[2]  + ((D_main_bss_80136DC0.tiles[var_t2].height_values[12] - D_main_bss_80136DC0.tiles[var_t2].height_values[2])  / 2);
            D_main_bss_80136DC0.tiles[var_t2].height_values[8]  = D_main_bss_80136DC0.tiles[var_t2].height_values[2]  + ((D_main_bss_80136DC0.tiles[var_t2].height_values[14] - D_main_bss_80136DC0.tiles[var_t2].height_values[2])  / 2);
            D_main_bss_80136DC0.tiles[var_t2].height_values[11] = D_main_bss_80136DC0.tiles[var_t2].height_values[10] + ((D_main_bss_80136DC0.tiles[var_t2].height_values[12] - D_main_bss_80136DC0.tiles[var_t2].height_values[10]) / 2);
            D_main_bss_80136DC0.tiles[var_t2].height_values[13] = D_main_bss_80136DC0.tiles[var_t2].height_values[12] + ((D_main_bss_80136DC0.tiles[var_t2].height_values[14] - D_main_bss_80136DC0.tiles[var_t2].height_values[12]) / 2);
            D_main_bss_80136DC0.tiles[var_t2].height_values[16] = D_main_bss_80136DC0.tiles[var_t2].height_values[10] + ((D_main_bss_80136DC0.tiles[var_t2].height_values[22] - D_main_bss_80136DC0.tiles[var_t2].height_values[10]) / 2);
            D_main_bss_80136DC0.tiles[var_t2].height_values[17] = D_main_bss_80136DC0.tiles[var_t2].height_values[12] + ((D_main_bss_80136DC0.tiles[var_t2].height_values[22] - D_main_bss_80136DC0.tiles[var_t2].height_values[12]) / 2);
            temp_v1_6 = D_main_bss_80136DC0.tiles[var_t2].height_values[24] - D_main_bss_80136DC0.tiles[var_t2].height_values[22];
            D_main_bss_80136DC0.tiles[var_t2].height_values[18] = D_main_bss_80136DC0.tiles[var_t2].height_values[12] + ((temp_v1_6 + (temp_v1_6 >> 0x1F)) / 2);
        } else if (temp_v1_5 & 1) {
            if (var_t1 & 4) {
                temp_a2 = D_main_bss_80136DC0.tiles[var_t2].height_values[4] - D_main_bss_80136DC0.tiles[var_t2].height_values[0];
                if (temp_a2 < 0) {
                    var_a0_2 = temp_a2 + 3;
                } else {
                    var_a0_2 = temp_a2;
                }
                var_v1 = temp_a2 * 3;
                D_main_bss_80136DC0.tiles[var_t2].height_values[1] = (D_main_bss_80136DC0.tiles[var_t2].height_values[0] + (var_a0_2 >> 2));
                D_main_bss_80136DC0.tiles[var_t2].height_values[2] = (D_main_bss_80136DC0.tiles[var_t2].height_values[0] + (temp_a2 / 2));
                if (var_v1 < 0) {
                    var_v1 += 3;
                }
                D_main_bss_80136DC0.tiles[var_t2].height_values[3] = (D_main_bss_80136DC0.tiles[var_t2].height_values[0] + (var_v1 >> 2));
            }
            if (var_t1 & 2) {
                temp_a2 = D_main_bss_80136DC0.tiles[var_t2].height_values[24] - D_main_bss_80136DC0.tiles[var_t2].height_values[4];
                if (temp_a2 < 0) {
                    var_a0_2 = temp_a2 + 3;
                } else {
                    var_a0_2 = temp_a2;
                }
                var_v1 = temp_a2 * 3;
                D_main_bss_80136DC0.tiles[var_t2].height_values[9] = (D_main_bss_80136DC0.tiles[var_t2].height_values[4] + (var_a0_2 >> 2));
                D_main_bss_80136DC0.tiles[var_t2].height_values[14] = (D_main_bss_80136DC0.tiles[var_t2].height_values[4] + (temp_a2 / 2));
                if (var_v1 < 0) {
                    var_v1 += 3;
                }
                D_main_bss_80136DC0.tiles[var_t2].height_values[19] = (D_main_bss_80136DC0.tiles[var_t2].height_values[4] + (var_v1 >> 2));
            }
        }
    }
    // var_t2 = 0;
    // if (hmpFile->tile_count != 0) {
    //     var_a3_2 = D_main_bss_80136DC4 + 0x10;
    //     do {
    //         temp_v1_5 = var_a3_2->unk-E;
    //         temp_t1 = temp_v0[var_t2];
    //         if (!(temp_v1_5 & 0x18)) {
    //             if (temp_v1_5 & 2) {
    //                 var_v0_2 = temp_t1 & 0x10;
    //                 if (temp_t1 & 0x40) {
    //                     temp_v1_6 = var_a3_2->unk-7 - var_a3_2->unk-9;
    //                     var_a3_2->unk-A = (s8) ((u8) var_a3_2->unk-B + ((s32) (var_a3_2->unk-9 - var_a3_2->unk-B) / 2));
    //                     var_a3_2->unk-8 = (s8) ((u8) var_a3_2->unk-9 + ((s32) (temp_v1_6 + (temp_v1_6 >> 0x1F)) >> 1));
    //                     var_v0_2 = temp_t1 & 0x10;
    //                 }
    //                 var_v0_3 = temp_t1 & 0x20;
    //                 if (var_v0_2 != 0) {
    //                     temp_v1_7 = var_a3_2->unk9 - var_a3_2->unk-1;
    //                     var_a3_2->unk-6 = (s8) ((u8) var_a3_2->unk-B + ((s32) (var_a3_2->unk-1 - var_a3_2->unk-B) / 2));
    //                     var_a3_2->unk4 = (s8) ((u8) var_a3_2->unk-1 + ((s32) (temp_v1_7 + (temp_v1_7 >> 0x1F)) >> 1));
    //                     var_v0_3 = temp_t1 & 0x20;
    //                 }
    //                 var_v0_4 = temp_t1 & 0x80;
    //                 if (var_v0_3 != 0) {
    //                     temp_v1_8 = var_a3_2->unkD - var_a3_2->unk3;
    //                     var_a3_2->unk-2 = (s8) ((u8) var_a3_2->unk-7 + ((s32) (var_a3_2->unk3 - var_a3_2->unk-7) / 2));
    //                     var_a3_2->unk8 = (s8) ((u8) var_a3_2->unk3 + ((s32) (temp_v1_8 + (temp_v1_8 >> 0x1F)) >> 1));
    //                     var_v0_4 = temp_t1 & 0x80;
    //                 }
    //                 if (var_v0_4 != 0) {
    //                     temp_v1_9 = var_a3_2->unkD - var_a3_2->unkB;
    //                     var_a3_2->unkA = (s8) ((u8) var_a3_2->unk9 + ((s32) (var_a3_2->unkB - var_a3_2->unk9) / 2));
    //                     var_a3_2->unkC = (s8) ((u8) var_a3_2->unkB + ((s32) (temp_v1_9 + (temp_v1_9 >> 0x1F)) >> 1));
    //                 }
    //                 temp_a1 = var_a3_2->unk-9;
    //                 var_a3_2->unk-5 = (s8) ((u8) var_a3_2->unk-B + ((s32) (var_a3_2->unk1 - var_a3_2->unk-B) / 2));
    //                 var_a3_2->unk-4 = (s8) ((u8) var_a3_2->unk-9 + ((s32) (var_a3_2->unk1 - temp_a1) / 2));
    //                 var_a3_2->unk-3 = (s8) ((u8) var_a3_2->unk-9 + ((s32) (var_a3_2->unk3 - temp_a1) / 2));
    //                 var_a3_2->unk0 = (s8) ((u8) var_a3_2->unk-1 + ((s32) (var_a3_2->unk1 - var_a3_2->unk-1) / 2));
    //                 var_a3_2->unk2 = (s8) ((u8) var_a3_2->unk1 + ((s32) (var_a3_2->unk3 - var_a3_2->unk1) / 2));
    //                 var_a3_2->unk5 = (s8) ((u8) var_a3_2->unk-1 + ((s32) (var_a3_2->unkB - var_a3_2->unk-1) / 2));
    //                 temp_v1_10 = var_a3_2->unkD - var_a3_2->unk1;
    //                 var_a3_2->unk6 = (s8) ((u8) var_a3_2->unk1 + ((s32) (var_a3_2->unkB - var_a3_2->unk1) / 2));
    //                 var_a3_2->unk7 = (s8) ((u8) var_a3_2->unk1 + ((s32) (temp_v1_10 + (temp_v1_10 >> 0x1F)) >> 1));
    //             } else if (temp_v1_5 & 1) {
    //                 var_v0_5 = temp_t1 & 2;
    //                 if (temp_t1 & 4) {
    //                     temp_t0 = var_a3_2->unk-B;
    //                     temp_a2 = var_a3_2->unk-7 - temp_t0;
    //                     var_a0_2 = temp_a2;
    //                     if (temp_a2 < 0) {
    //                         var_a0_2 = temp_a2 + 3;
    //                     }
    //                     var_v1 = temp_a2 * 3;
    //                     var_a3_2->unk-A = (s8) (temp_t0 + (var_a0_2 >> 2));
    //                     var_a3_2->unk-9 = (s8) (temp_t0 + (temp_a2 / 2));
    //                     if (var_v1 < 0) {
    //                         var_v1 += 3;
    //                     }
    //                     var_a3_2->unk-8 = (s8) (temp_t0 + (var_v1 >> 2));
    //                     var_v0_5 = temp_t1 & 2;
    //                 }
    //                 var_v0_6 = temp_t1 & 1;
    //                 if (var_v0_5 != 0) {
    //                     temp_t0_2 = var_a3_2->unk-7;
    //                     temp_a2_2 = var_a3_2->unkD - temp_t0_2;
    //                     var_a0_3 = temp_a2_2;
    //                     if (temp_a2_2 < 0) {
    //                         var_a0_3 = temp_a2_2 + 3;
    //                     }
    //                     var_v1_2 = temp_a2_2 * 3;
    //                     var_a3_2->unk-2 = (s8) (temp_t0_2 + (var_a0_3 >> 2));
    //                     var_a3_2->unk3 = (s8) (temp_t0_2 + (temp_a2_2 / 2));
    //                     if (var_v1_2 < 0) {
    //                         var_v1_2 += 3;
    //                     }
    //                     var_a3_2->unk8 = (s8) (temp_t0_2 + (var_v1_2 >> 2));
    //                     var_v0_6 = temp_t1 & 1;
    //                 }
    //                 var_v0_7 = temp_t1 & 8;
    //                 if (var_v0_6 != 0) {
    //                     temp_t0_3 = var_a3_2->unk-B;
    //                     temp_a2_3 = var_a3_2->unk9 - temp_t0_3;
    //                     var_a0_4 = temp_a2_3;
    //                     if (temp_a2_3 < 0) {
    //                         var_a0_4 = temp_a2_3 + 3;
    //                     }
    //                     var_v1_3 = temp_a2_3 * 3;
    //                     var_a3_2->unk-6 = (s8) (temp_t0_3 + (var_a0_4 >> 2));
    //                     var_a3_2->unk-1 = (s8) (temp_t0_3 + (temp_a2_3 / 2));
    //                     if (var_v1_3 < 0) {
    //                         var_v1_3 += 3;
    //                     }
    //                     var_a3_2->unk4 = (s8) (temp_t0_3 + (var_v1_3 >> 2));
    //                     var_v0_7 = temp_t1 & 8;
    //                 }
    //                 if (var_v0_7 != 0) {
    //                     temp_t0_4 = var_a3_2->unk9;
    //                     temp_a2_4 = var_a3_2->unkD - temp_t0_4;
    //                     var_a0_5 = temp_a2_4;
    //                     if (temp_a2_4 < 0) {
    //                         var_a0_5 = temp_a2_4 + 3;
    //                     }
    //                     var_v1_4 = temp_a2_4 * 3;
    //                     var_a3_2->unkA = (s8) (temp_t0_4 + (var_a0_5 >> 2));
    //                     var_a3_2->unkB = (s8) (temp_t0_4 + (temp_a2_4 / 2));
    //                     if (var_v1_4 < 0) {
    //                         var_v1_4 += 3;
    //                     }
    //                     var_a3_2->unkC = (s8) (temp_t0_4 + (var_v1_4 >> 2));
    //                 }
    //                 temp_t0_5 = var_a3_2->unk-B;
    //                 temp_a2_5 = var_a3_2->unkD - temp_t0_5;
    //                 var_a0_6 = temp_a2_5;
    //                 if (temp_a2_5 < 0) {
    //                     var_a0_6 = temp_a2_5 + 3;
    //                 }
    //                 var_v1_5 = temp_a2_5 * 3;
    //                 var_a3_2->unk-5 = (s8) (temp_t0_5 + (var_a0_6 >> 2));
    //                 var_a3_2->unk1 = (s8) (temp_t0_5 + (temp_a2_5 / 2));
    //                 if (var_v1_5 < 0) {
    //                     var_v1_5 += 3;
    //                 }
    //                 temp_a0 = var_a3_2->unk-7;
    //                 var_a3_2->unk7 = (s8) (temp_t0_5 + (var_v1_5 >> 2));
    //                 temp_v0_2 = ((s32) (var_a3_2->unkD - temp_a0) / 4) + temp_a0;
    //                 temp_t0_6 = var_a3_2->unk-5;
    //                 temp_t1_2 = var_a3_2->unk-B;
    //                 temp_a1_2 = var_a3_2->unk-7;
    //                 var_a0_7 = (var_a3_2->unk9 - temp_t1_2) * 3;
    //                 temp_v0_3 = (((s32) (var_a3_2->unkD - temp_a1_2) / 2) + temp_a1_2) - var_a3_2->unk1;
    //                 var_a3_2->unk2 = (s8) ((u8) var_a3_2->unk1 + ((s32) (temp_v0_3 + (temp_v0_3 >> 0x1F)) >> 1));
    //                 var_a3_2->unk-4 = (s8) (temp_t0_6 + ((temp_v0_2 - temp_t0_6) / 3));
    //                 temp_v1_11 = var_a3_2->unk7;
    //                 var_a3_2->unk-3 = (s8) (temp_t0_6 + (((temp_v0_2 - temp_t0_6) * 2) / 3));
    //                 if (var_a0_7 < 0) {
    //                     var_a0_7 += 3;
    //                 }
    //                 temp_t0_7 = (var_a0_7 >> 2) + temp_t1_2;
    //                 temp_a2_6 = var_a3_2->unk-B;
    //                 var_a3_2->unk5 = (s8) (temp_t0_7 + ((temp_v1_11 - temp_t0_7) / 3));
    //                 temp_t0_8 = ((s32) (var_a3_2->unk9 - temp_a2_6) / 2) + temp_a2_6;
    //                 var_a3_2->unk6 = (s8) (temp_t0_7 + (((temp_v1_11 - temp_t0_7) * 2) / 3));
    //                 var_a3_2->unk0 = (s8) (temp_t0_8 + ((s32) (var_a3_2->unk1 - temp_t0_8) / 2));
    //             }
    //         }
    //         var_t2 += 1;
    //         var_a3_2 += 0x1E;
    //     } while (var_t2 < (s32) hmpFile->tile_count);
    // }
    rs_free(temp_v0);
}
#else
INCLUDE_ASM("asm/nonmatchings/main/42AF0", computeGridTileEdgeAdjacencyMasks);
#endif

INCLUDE_ASM("asm/nonmatchings/main/42AF0", loadLevelAssets);

INCLUDE_ASM("asm/nonmatchings/main/42AF0", computeGridLayerScrollOffset);

INCLUDE_ASM("asm/nonmatchings/main/42AF0", teardownAnimatedMapGridLayer);

void setGridLayerScrollX(f32 arg0) {
    D_main_bss_80130C50 = arg0;
}

void setGridLayerScrollBounds(f32 arg0, f32 arg1) {
    D_main_bss_80130C54 = arg0;
    D_main_bss_80130C58 = arg1;
}

INCLUDE_ASM("asm/nonmatchings/main/42AF0", fake_func_800457CC);
