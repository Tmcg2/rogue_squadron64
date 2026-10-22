#include "common.h"

#include "compiler/gcc/string.h"

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

#if 0
Gfx *findOrCreateMaterial(Gfx *, u16, u32); // 1EE30.c, although that file thinks this function takes 4 arguments
extern Gfx *D_main_bss_801163D4; // Some BSS variable, don't know what file it belongs to
extern char *D_main_80038CF0; // This is data, see 01600.rodata.s for the contents of the pointer.
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

INCLUDE_ASM("asm/nonmatchings/main/24D30", loadDebugAssets);

INCLUDE_ASM("asm/nonmatchings/main/24D30", fake_func_80024878);
