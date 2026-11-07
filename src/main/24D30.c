#include "common.h"

#include "compiler/gcc/string.h"

#include "textures.h"

#include "main/04080.h"
#include "main/08510.h"
#include "main/24D30.h"

struct glyph_pos {
    s16 ulx;
    s16 uly;
    u8  glyph;
};

u8  D_main_bss_80128F20;
u8  bss_pad_24D30; // Why is this necessary???
u16 D_main_bss_80128F22;
struct glyph_pos D_main_bss_80128F28[0x800];
s16 D_main_bss_8012BF28;
u16 D_main_bss_8012BF2A;
u16 D_main_bss_8012BF2C;

char *D_main_80038CF0 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-=()!\"$%&/:.,#\\_;<>";

u32 data_pad_24D30[] = {
    0x8E020034,
    0x10400003,
    0x00A08821,
};

#if 0
Gfx *findOrCreateMaterial(Gfx *, u16, u32); // 1EE30.c, although that file thinks this function takes 4 arguments
extern Gfx *D_main_bss_801163D4; // Some BSS variable, don't know what file it belongs to
// https://decomp.me/scratch/swmVy
Gfx *flushDebugTextOverlay(Gfx *arg0) {
    Gfx *var_s0;
    s16 var_s4;
    s16 var_v0_3;
    u8 temp_a0;
    s32 temp_hi;
    s32 temp_s1;
    u32 temp_s2;
    u32 temp_s3;
    s32 temp_v0;
    char *temp_v0_2;
    u8 var_a1;

    if (D_main_bss_8012BF28 != 0) {
        if (arg0 >= D_main_bss_801163D4) {
            gSPLine3D(arg0, 0, 0, 0);
            arg0 = allocateDisplayListBuffer();
        }
        gDPPipeSync(arg0++);
        arg0 = findOrCreateMaterial(arg0, D_main_bss_8011A444[D_main_bss_80128F22].D_80128F08_index, 2);
        if (arg0 >= D_main_bss_801163D4) {
            gSPLine3D(arg0, 0, 0, 0);
            arg0 = allocateDisplayListBuffer();
        }
        gDPSetRenderMode(arg0++, G_RM_NOOP, G_RM_NOOP2);
        if (arg0 >= D_main_bss_801163D4) {
            gSPLine3D(arg0, 0, 0, 0);
            arg0 = allocateDisplayListBuffer();
        }
        gDPSetCycleType(arg0++, G_CYC_COPY);
        if (arg0 >= D_main_bss_801163D4) {
            gSPLine3D(arg0, 0, 0, 0);
            arg0 = allocateDisplayListBuffer();
        }
        gDPSetTextureFilter(arg0++, G_TF_POINT);
        if (arg0 >= D_main_bss_801163D4) {
            gSPLine3D(arg0, 0, 0, 0);
            arg0 = allocateDisplayListBuffer();
        }
        gDPSetTexturePersp(arg0++, G_TP_NONE);
        if (arg0 >= D_main_bss_801163D4) {
            gSPLine3D(arg0, 0, 0, 0);
            arg0 = allocateDisplayListBuffer();
        }
        gDPSetAlphaCompare(arg0++, G_AC_THRESHOLD);
        if (arg0 >= D_main_bss_801163D4) {
            gSPLine3D(arg0, 0, 0, 0);
            arg0 = allocateDisplayListBuffer();
        }
        gDPSetBlendColor(arg0++, 0x00, 0x00, 0x00, 0x00);
        for (var_s4 = 0; var_s4 < D_main_bss_8012BF28; var_s4++) {
            var_a1 = D_main_bss_80128F28[var_s4].glyph;
            if ((var_a1 - 0x61) < 0x1AU) {
                var_a1 -= 0x20;
            }
            temp_v0_2 = strchr(D_main_80038CF0, var_a1);
            if (temp_v0_2 == NULL) continue;

            var_a1 = temp_v0_2 - D_main_80038CF0;
            temp_s3 = var_a1 / 21;
            temp_s2 = (var_a1 % 21) * 7;
            if ((arg0 + 1) >= D_main_bss_801163D4) {
                gSPLine3D(arg0, 0, 0, 0);
                arg0 = allocateDisplayListBuffer();
            }
            gDPTextureRectangle(arg0,
                D_main_bss_80128F28[var_s4].ulx * 4, D_main_bss_80128F28[var_s4].uly * 4,
                (D_main_bss_80128F28[var_s4].ulx + 7) * 4, (D_main_bss_80128F28[var_s4].uly + 6) * 4,
                G_TX_RENDERTILE,
                temp_s3 * 256, temp_s2 * 32,
                0x1000, 0x0400);
                arg0+=2;
        }
        D_main_bss_8012BF28 = 0;
        D_main_bss_8012BF2A = 0x28;
        D_main_bss_8012BF2C = 0x10;
        return arg0;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/main/24D30", flushDebugTextOverlay);
#endif

void queueDebugTextGlyph(u16 arg0, u16 arg1, s8 arg2) {
    if ((D_main_bss_8012BF28 < 0x800) && (D_main_bss_80128F20 != 0)) {
        D_main_bss_80128F28[D_main_bss_8012BF28].ulx   = arg0;
        D_main_bss_80128F28[D_main_bss_8012BF28].uly   = arg1;
        D_main_bss_80128F28[D_main_bss_8012BF28].glyph = arg2;
        D_main_bss_8012BF28 += 1;
    }
}

void setDebugTextCursor(s32 arg0, s32 arg1) {
    D_main_bss_8012BF2A = ((arg0 << 0x10) >> 0xD) + 0x28;
    D_main_bss_8012BF2C = ((arg1 << 0x10) >> 0xD) + 0x10;
}

void drawDebugTextString(u8 *arg0) {
    while(*arg0) {
        switch (*arg0) {
            case ' ':
                D_main_bss_8012BF2A += 8;
                break;
            case '\n':
                D_main_bss_8012BF2A = 0x28;
                D_main_bss_8012BF2C += 8;
                break;
            case '\t':
                D_main_bss_8012BF2A = (((D_main_bss_8012BF2A >> 3) & 0x1FF8) + 8) * 8;
                break;
            default:
                queueDebugTextGlyph(D_main_bss_8012BF2A, D_main_bss_8012BF2C, *arg0);
                D_main_bss_8012BF2A += 8;
                break;
        }
        arg0++;
    }
    D_main_bss_8012BF2A = 0x28;
    D_main_bss_8012BF2C += 8;
}

// These are here to enable 100% matching. If that isn't a concern, you make these
// proper string literals in `loadDebugAssets`, removing the `\0crun` part of dbgfontmat
const char dbgdata[]        = {"dbg_data"};
const char dbgfont[]        = {"dbg_font"};
const char dbgfonttext[]    = {"dbg_fonttex"};
const char dbgfontmat[0x10] = {"dbg_fontmat\0crun"};

void loadDebugAssets(OSId arg0) {
    struct material_entry sp18;
    struct texture_entry sp40;
    s32 temp_v0;
    u32 temp_v0_2;
    struct partial_image_header *temp_s0_2;
    void *temp_v0_3;

    D_main_bss_80128F20 = 0;
    D_main_bss_8012BF28 = 0;
    temp_v0 = findManifestEntryByName(dbgdata);
    if (temp_v0 != -1) {
        temp_v0_2 = get_asset_size_extra(temp_v0, dbgfont);
        temp_s0_2 = rs_malloc(temp_v0_2, 8U);
        temp_v0_3 = findAssetAcrossSegments(arg0, NULL, temp_v0, dbgfont, 0U);
        setupAssetDma(arg0, NULL, temp_v0_3, 0U, temp_v0_2, temp_s0_2);
        teardownAssetDma(arg0, temp_v0_3);
        // This is hacky on my part, but it works and can't really be done any other way
        sp40.pixel_offsets[0] = (u32)temp_s0_2 + 0x3C;
        sp40.plte_offset      = (u32)temp_s0_2 + 0xC;
        sp40.texture_name_offset = dbgfonttext;
        sp40.width = temp_s0_2->image_pixel_width;
        sp40.height = temp_s0_2->image_pixel_height;
        sp40.one = 1;
        sp40.flags_type = temp_s0_2->flags | 0x4000;
        sp40.transparency_color.r = 0;
        sp40.transparency_color.g = 0;
        sp40.transparency_color.b = 0;
        memcpy(sp18.material_name, dbgfontmat, 0xC);
        D_main_bss_80128F22 = registerHmtTextureInTable(&sp18, &sp40, 1U);
        rs_free(temp_s0_2);
        freeManifestSegmentAssets(temp_v0);
        D_main_bss_8012BF2A = 0x28;
        D_main_bss_8012BF2C = 0x10;
        D_main_bss_80128F20 = 1;
    }
}

INCLUDE_ASM("asm/nonmatchings/main/24D30", fake_func_80024878);
