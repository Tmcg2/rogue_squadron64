#include "common.h"

#include "hmp.h"

#include "main/192E0.h"
#include "main/1D000.h"
#include "main/42AF0.h"

extern f32 D_main_bss_80130C50;
extern f32 D_main_bss_80130C54;
extern f32 D_main_bss_80130C58;
extern s16 D_main_bss_80130C70[0x50];
extern s16 D_main_bss_80130D10[0x50];
extern s8  D_main_bss_80130DB0[0x40][0x40];
extern s8  D_main_bss_80131DB0[0x40][0x40];
extern struct hmp_context D_main_bss_80136DC0;
extern u16 D_main_bss_80136FC0;
extern struct hmp_header *hmpFile;
extern u16 D_main_bss_80136FC8;
extern struct hmp_related_linked_list *gDoublyLinkedNodePool12;

void allocAndInitDoublyLinkedNodePool12(s32 arg0) {
    u16 why;
    s32 var_v1;

    gDoublyLinkedNodePool12 = rs_malloc(arg0 * sizeof(struct hmp_related_linked_list), 0U);
    for (var_v1 = 0; var_v1 < arg0; var_v1++) {
        gDoublyLinkedNodePool12[var_v1].prev = var_v1 - 1;
        gDoublyLinkedNodePool12[var_v1].next = var_v1 + 1;
        gDoublyLinkedNodePool12[var_v1].ukn08 = 0;
    }
    why = 0xFFFF;
    D_main_bss_80136FC8 = why;
    D_main_bss_80136FC0 = 0;
    gDoublyLinkedNodePool12[arg0 - 1].next = why;
    gDoublyLinkedNodePool12[0].prev = why;
}

#if 0
// FPU register allocation diffs  >:(
s32 rasterizeEdgeXSpansAscending(Vec3f arg0, Vec3f arg1, s32 arg2) {
    f32 temp_ft0;
    s32 var_a3;
    s32 why1, why2;

    if (arg1[2] > arg0[2]) {
        why1 = arg0[2];
        why2 = arg1[2];
        temp_ft0 = (arg1[2] - arg0[2]);
        temp_ft0 = (arg1[0] - arg0[0]) / temp_ft0;
        if (temp_ft0 < 0.0f) {
            for (var_a3 = why1; var_a3 < why2; var_a3++) {
                D_main_bss_80130C70[arg2++] = arg0[0] + ((var_a3 + 1) - arg0[2]) * temp_ft0;
            }
            D_main_bss_80130C70[arg2] = arg1[0];
        } else {
            if ((arg2 == 0) || (arg0[0] < D_main_bss_80130C70[arg2])) {
                D_main_bss_80130C70[arg2] = arg0[0];
            }
            for (var_a3 = why1 + 1; var_a3 <= why2; var_a3++) {
                D_main_bss_80130C70[++arg2] = arg0[0] + (var_a3 - arg0[2]) * temp_ft0;
            }
        }
    }
    return arg2;
}
#else
INCLUDE_ASM("asm/nonmatchings/main/42AF0", rasterizeEdgeXSpansAscending);
#endif

#if 0
// FPU register allocation diffs  >:(
s32 rasterizeEdgeXSpansDescending(Vec3f arg0, Vec3f arg1, s32 arg2) {
    f32 temp_ft0;
    s32 var_a3;
    s32 why1, why2;

    if (arg1[2] > arg0[2]) {
        why1 = arg0[2];
        why2 = arg1[2];
        temp_ft0 = (arg1[2] - arg0[2]);
        temp_ft0 = (arg1[0] - arg0[0]) / temp_ft0;
        if (temp_ft0 < 0.0f) {
            if ((arg2 == 0) || (arg0[0] < D_main_bss_80130D10[arg2])) {
                D_main_bss_80130D10[arg2] = arg0[0];
            }
            for (var_a3 = why1 + 1; var_a3 <= why2; var_a3++) {
                D_main_bss_80130D10[++arg2] = arg0[0] + (var_a3 - arg0[2]) * temp_ft0;
            }
        } else {
            for (var_a3 = why1; var_a3 < why2; var_a3++) {
                D_main_bss_80130D10[arg2++] = arg0[0] + ((var_a3 + 1) - arg0[2]) * temp_ft0;
            }
            D_main_bss_80130D10[arg2] = arg1[0];
        }
    }
    return arg2;
}
#else
INCLUDE_ASM("asm/nonmatchings/main/42AF0", rasterizeEdgeXSpansDescending);
#endif

#if 0
// DOES NOT MATCH!!
// Require a lot more work, but is in a decent state as-is
void scanConvertTriangleToSpanTable(Vec3f arg0, Vec3f arg1, Vec3f arg2, f32 arg3) {
    Vec3f sp10;
    Vec3f sp20;
    Vec3f sp30;
    f32 *temp_v0;
    f32 temp_fs0;
    f32 temp_ft0;
    f32 var_fs0;
    f32 var_fv0;
    f32 var_fv1;
    s32 var_a0_2;
    s32 temp_ft4;
    s32 temp_t3;
    s32 var_a1_2;
    s32 var_s0;

    while (arg1[2] < arg0[2]) {
        temp_v0 = arg0;
        arg0 = arg1;
        arg1 = arg2;
        arg2 = temp_v0;
    }
    sp10[0] = arg1[0] - arg0[0];
    sp10[1] = arg1[1] - arg0[1];
    sp10[2] = arg1[2] - arg0[2];
    sp20[0] = arg2[0] - arg0[0];
    sp20[1] = arg2[1] - arg0[1];
    sp20[2] = arg2[2] - arg0[2];
    vec3Cross(sp30, sp10, sp20);
    normalize_vector(sp30);
    if ((sp30[1] < 0.2) && (sp30[1] > -0.2)) {
        var_fs0 = (sp10[2] * sp20[0]) - (sp10[0] * sp20[2]);
        if (var_fs0 < 0.0f) {
            var_fs0 = -var_fs0;
        }
        if (((var_fs0 < 10.0f) && (var_fs0 > -10.0f))) return;
    }
    temp_fs0 = (-arg0[0] * sp30[0]) + (-arg0[1] * sp30[1]) + (-arg0[2] * sp30[2]);
    if (arg2[2] < arg1[2]) {
        if ((((arg1[0] - arg0[0]) / (arg1[2] - arg0[2])) - ((arg2[0] - arg0[0]) / (arg2[2] - arg0[2]))) < 0.0f) {
            var_s0 = rasterizeEdgeXSpansAscending(arg0, arg1, 0);
            rasterizeEdgeXSpansDescending(arg2, arg1, rasterizeEdgeXSpansDescending(arg0, arg2, 0));
        } else {
            var_s0 = rasterizeEdgeXSpansAscending(arg2, arg1, rasterizeEdgeXSpansAscending(arg0, arg2, 0));
            rasterizeEdgeXSpansDescending(arg0, arg1, 0);
        }
    } else if ((((arg2[0] -  arg0[0]) / (arg2[2] - arg0[2])) - ((arg1[0] -  arg0[0]) / (arg1[2] - arg0[2]))) < 0.0f) {
        var_s0 = rasterizeEdgeXSpansAscending(arg0, arg2, 0);
        rasterizeEdgeXSpansDescending(arg1, arg2, rasterizeEdgeXSpansDescending(arg0, arg1, 0));
    } else {
        var_s0 = rasterizeEdgeXSpansAscending(arg1, arg2, rasterizeEdgeXSpansAscending(arg0, arg1, 0));
        rasterizeEdgeXSpansDescending(arg0, arg2, 0);
    }
    temp_ft4 = (s32) arg0[2];
    temp_t3 = temp_ft4 + var_s0;
    if (sp30[1] > 0.0f) {
        for (var_a1_2 = temp_ft4; var_a1_2 <= temp_t3; var_a1_2++) {
            for (var_a0_2 = D_main_bss_80130C70[var_a1_2]; var_a0_2 <= D_main_bss_80130D10[var_a1_2]; var_a0_2++) {
                temp_ft0 = -temp_fs0 / sp30[1];
                if (sp30[0] > 0.0f) {
                    var_fv0 = (f32) (var_a0_2 + 1);
                } else {
                    var_fv0 = (f32) var_a0_2;
                }
                temp_ft0 -= (sp30[0] * var_fv0) / sp30[1];
                if (sp30[2] > 0.0f) {
                    var_fv0 = (f32) (var_a1_2 + 1);
                } else {
                    var_fv0 = (f32) var_a1_2;
                }
                temp_ft0 -= (sp30[2] * var_fv0) / sp30[1];
                temp_ft0 *= arg3;
                temp_ft0 = (s32) temp_ft0;
                if (temp_ft0 > 127.0f) {
                    temp_ft0 = 127.0f;
                } else if (temp_ft0 < -128.0f) {
                    temp_ft0 = -128.0f;
                }
                D_main_bss_80131DB0[var_a1_2][var_a0_2] = temp_ft0;
            }
        }
    } else {
        for (var_a1_2 = temp_ft4; var_a1_2 <= temp_t3; var_a1_2++) {
            for (var_a0_2 = D_main_bss_80130C70[var_a1_2]; var_a0_2 <= D_main_bss_80130D10[var_a1_2]; var_a0_2++) {
                temp_ft0 = -temp_fs0 / sp30[1];
                if (sp30[0] > 0.0f) {
                    var_fv0 = (f32) (var_a0_2 + 1);
                } else {
                    var_fv0 = (f32) var_a0_2;
                }
                temp_ft0 -= (sp30[0] * var_fv0) / sp30[1];
                if (sp30[2] > 0.0f) {
                    var_fv0 = (f32) (var_a1_2 + 1);
                } else {
                    var_fv0 = (f32) var_a1_2;
                }
                temp_ft0 -= (sp30[2] * var_fv0) / sp30[1];
                temp_ft0 *= arg3;
                temp_ft0 = (s32) temp_ft0;
                if (temp_ft0 > 127.0f) {
                    temp_ft0 = 127.0f;
                } else if (temp_ft0 < -128.0f) {
                    temp_ft0 = -128.0f;
                }
                D_main_bss_80130DB0[var_a1_2][var_a0_2] = temp_ft0;
            }
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/main/42AF0", scanConvertTriangleToSpanTable);
#endif

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
