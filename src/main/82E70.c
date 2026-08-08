#include "common.h"
#include "common_types.h"
#include "common_variables.h"
#include "cheat_codes.h"

#include "main/01720.h"
#include "main/6C310.h"
#include "main/82E70.h"

static u32 gCheatCodeCrc32Table[] = {
    0xAF6FA05C, // rs_crc32("GAMEFLO!")
    0x63D0142E, // rs_crc32("KOELSCH-")
    0x393F8BBF, // rs_crc32("FARMBOY-")
    0xB66A9445, // rs_crc32("TIEDUP--")
    0x8FB7A6F2, // rs_crc32("HALIFAX?")
    0x2F696225, // rs_crc32("BLAMEUS-")
    0x40C19208, // rs_crc32("ACE-----")
    0x7DD0CC4B, // rs_crc32("ICHHELD-")
    0xA789B6ED, // rs_crc32("PSYLOCK-")
    0xC9278EE5, // rs_crc32("WUTZI---")
    0x3EBF0A20, // rs_crc32("BERGLOWE")
    0xE8A593FA, // rs_crc32("TIECK---")
    0x80080388, // rs_crc32("RUDIBUBI")
    0x0DCCDF98, // rs_crc32("CHIPPIE-")
    0x5CAE7F9F, // rs_crc32("TOBIASS-")
    0xCEB94078, // rs_crc32("SIRHISS-")
    0x654092D5, // rs_crc32("HARDROCK")
    0xE999EC85, // rs_crc32("THBPILOT")
    0x56289944, // rs_crc32("FLYDODGE")
    0xD842019E, // rs_crc32("MAESTRO-")
    0x0C687BEA, // rs_crc32("DIRECTOR")
    0x09B770C0, // rs_crc32("CREDITS-")
    0xA04A5DB4, // rs_crc32("IGIVEUP-")
    0x81A84CCA, // rs_crc32("RADAR---")
    0x9A58A558, // rs_crc32("TOUGHGUY")
    0x477AC2FB, // rs_crc32("CHICKEN-")
    0x557E6AD9, // rs_crc32("WOMPRAT!")
    0x494DAC91, // rs_crc32("WOISTHAN")
    0x3C0EF6F5, // rs_crc32("DEADDACK")
};

static u8 D_main_800A0F44[] = {
    0x13,
    0x14,
    0xFF,
    // ALL VALUES BELOW THIS COMMENT ARE JUNK!!
    // DO NOT DELETE THEM, THEY ARE REQUIRED FOR MATCHING
    0xB0,
    0x24,
    0x62,
    0xFF,
    0xFC,
    0x2C,
    0x43,
    0x00,
    0x0E,
};

// Credit to this match goes to inspectredc
// https://decomp.me/scratch/PuezA
s32 applyCheatCodeFromInput(u8 *arg0, u8 arg1, s8 *arg2) {
    u8 var_s2;
    u8 var_s4;
    s32 var_v1;
    u32 *crc32LUT;
    u32 temp_a0;
    u32 var_a1;
    u32 var_s0;
    s32 one;
    u32 blah;
    u32 byte;
    u8 bit;
    s32 blah2;
    

    var_s4 = 0;
    var_s2 = 0;
    crc32LUT = make_crc32_lut();
    temp_a0 = rs_crc32(crc32LUT, arg0, 8U);
    if (CHEAT_IS_ACTIVE(gGameSettings.cheatCodeFlags[0], HALIFAX_BIT)) {
        UNSET_CHEAT_FLAG(gGameSettings.cheatCodeFlags[0], HALIFAX_BIT);
        gGameSettings.unk28 = load_naboo_starfighter(temp_a0);
        return 0;
    }

    for (var_s0 = 0; (var_s0 & 0xFF) < NUM_CHEAT_CODES; var_s0++) {
        blah = gCheatCodeCrc32Table[(var_s0 & 0xFF)];
        one = 1;
        if ((blah == temp_a0) != one) continue;
        switch (arg1) {
        case 0:
            SET_CHEAT_FLAG(gGameSettings.cheatCodeFlags[(var_s0 & 0xFF) / 32], var_s0 % 32);
            break;
        case 1:
            UNSET_CHEAT_FLAG(gGameSettings.cheatCodeFlags[(var_s0 & 0xFF) / 32], var_s0 % 32);
            break;
        default:
            break;
        }
        var_s2 = 1;
        var_s4 = CHEAT_IS_ACTIVE(gGameSettings.cheatCodeFlags[(var_s0 & 0xFF) / 32], var_s0 % 32);
        if (CHEAT_IS_ACTIVE(gGameSettings.cheatCodeFlags[(var_s0 & 0xFF) / 32], var_s0 % 32) && ((var_s0 & 0xFF) >= ICHHELD_BIT) && ((var_s0 & 0xFF) <= FLYDODGE_BIT)) {
            for (var_a1 = ICHHELD_BIT; (var_a1 & 0xFF) <= FLYDODGE_BIT; var_a1++) {
                UNSET_CHEAT_FLAG(gGameSettings.cheatCodeFlags[(var_a1 & 0xFF) / 32], var_a1 % 32);
            }
            SET_CHEAT_FLAG(gGameSettings.cheatCodeFlags[(var_s0 & 0xFF) / 32], var_s0 % 32);
        }
        break;
    }
    rs_free(crc32LUT);
    *arg2 = 0;
    if (var_s2) {
        var_s0 &= 0xFF;
        if (isCheatCodeIndexAllowed(var_s0)) {
            *arg2 = 1;
        }
        if (var_s0 == 4) {
            var_s2 = 0;
        }
        if (var_s2) {
            var_v1 = 2;
            if (var_s4) {
                var_v1 = 1;
            }
        } else {
            var_v1 = 0;
        }
    } else {
        var_v1 = 0;
    }
    return var_v1;
}

u8 isCheatCodeIndexAllowed(u8 arg0) {
    u8 var_v1;

    for (var_v1 = 0; ; var_v1++) {
        if (D_main_800A0F44[var_v1] == 0xFF) {
            return 0;
        }
        if (D_main_800A0F44[var_v1] == arg0) {
            return 1;
        }
    }
}

u32 rs_crc32(u32 *crc32LUT, u8 *input, u32 length) {
    u32 var_a3;
    u32 var_t0;

    var_t0 = 0xFAC5FAC5;
    for (var_a3 = 0; var_a3 < length; var_a3++) {
        var_t0 = crc32LUT[(var_t0 ^ input[var_a3]) & 0xFF] ^ (var_t0 >> 8);
    }
    return var_t0;
}

u32 *make_crc32_lut(void) {
    u32 var_a0;
    u32 var_a1;
    u32 var_v1;
    u32 *temp_v0;

    temp_v0 = rs_malloc(0x00000400, 0U);
    for (var_a1 = 0; var_a1 < 0x100; var_a1++) {
        var_v1 = var_a1;
        for (var_a0 = 0; var_a0 < 8; var_a0++) {
            if ((var_v1 % 2) != 0) {
                var_v1 = (var_v1 >> 1) ^ 0xEDB88320;
            } else {
                var_v1 >>= 1;
            }
        }
        temp_v0[var_a1] = var_v1;
    }
    return temp_v0;
}

void noopHandler_800825C0(void) {
}

INCLUDE_ASM("asm/nonmatchings/main/82E70", fake_func_800825C8);
