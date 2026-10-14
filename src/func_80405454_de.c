#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_80405454.h"
#include "types.h"

/* Chooses a free extension letter for a new note on the Controller Pak on channel ch: refuses with
   -2 unless the pak is ready, queries each of the 16 notes through func_8040458C_de (failing with -1
   on error) and marks the letter of every existing note, then writes the first unused letter from
   'A' as the extension, returning 0, or -1 when all 16 letters are taken. */



extern s32 func_8040458C_de(s32 ch, s32 index, s32 *exists, char *gameName, u8 *ext, s32 *size,
                         char *companyCode, char *gameCode);

s32 func_80405454_de(s32 ch, u8 *ext) {
    char companyCode[8];
    char gameCode[8];
    char gameName[16];
    s32 exists;
    s32 size;
    s32 used;
    s32 i;

    used = 0;
    if (D_801534F0[ch] != 3) {
        return -2;
    }
    for (i = 0; i < 16; i++) {
        if (func_8040458C_de(ch, i, &exists, gameName, ext, &size, companyCode, gameCode) != 0) {
            return -1;
        }
        if (exists != 0) {
            used |= 1 << (ext[0] - 'A');
        }
    }
    ext[0] = 'A';
    ext[1] = 0;
    ext[2] = 0;
    ext[3] = 0;
    for (i = 0; i < 16 && (used & (1 << i) & 0xFFFF); i++) {
        ext[0]++;
    }
    if (i >= 16) {
        return -1;
    }
    return 0;
}

/* Returns whether entry i of D_80153500 is -4 when entry i of the state table D_801534F0 is 3,
   otherwise zero. */



s32 func_80405598_de(s32 index) {
    if (D_801534F0[index] != 3) {
        return 0;
    }
    return D_80153500[index] == -4;
}

/* Marks the given controller port's 0x70-byte pak record in D_80153330 present when the port's D_8010FBE3 status byte is clear and func_802B7FD8_de initialises the pak block at offset 8 of the record through D_8010FC00 without error, clearing the mark otherwise, and returns the mark.
   Adapted from func_8028B2F8_de with the record reached by port index, the status byte guard and the initialisation result stored as a byte flag changed. */



extern u8 D_8010FBE3[];
extern char D_8010FC00[];
extern PakRecord D_80153330[];
extern s32 func_802B7FD8_de(void *queue, void *pak, s32 channel);

s32 func_804055D4_de(s32 channel) {
    PakRecord *record = &D_80153330[channel];
    s32 result;

    if (D_8010FBE3[channel * 4] == 0) {
        record->present = func_802B7FD8_de(D_8010FC00, record->pak, channel) == 0;
        result = record->present;
    } else {
        record->present = 0;
        result = 0;
    }
    return result;
}

extern u8 D_800DE80C[];

/* Converts a controller-pak filename through its character table, blanking leading nulls, then trims trailing spaces. */
void func_80405648_de(u8 *arg0, u8 *arg1, s32 arg2) {
    s32 i;
    s32 started;

    for (i = 0; i < arg2; i++) {
        arg1[i] = 0;
    }

    started = 0;
    for (i = started; i < arg2; i++, arg0++) {
        if (*arg0 < 0x42) {
            if (*arg0 == 0 && !started) {
                arg1[i] = ' ';
            } else {
                arg1[i] = D_800DE80C[*arg0];
                started = 1;
            }
        } else {
            arg1[i] = '~';
        }
    }

    for (i = arg2 - 1; i >= 0; i--) {
        if (arg1[i] != ' ' && arg1[i] != 0) {
            break;
        }
        arg1[i] = 0;
    }
    arg1[arg2 - 1] = 0;
}

extern u8 func_802A05A0_de(u8);
extern u8 D_800DE80C[0x42];

/* Maps input bytes through a lookup table and stores results. */
void func_8040570C_de(u8 *arg0, s8 *arg1, s32 arg2) {
    s32 var_s2;
    s8 *var_s1;
    s32 var_a0;
    u8 *var_s0;
    int new_var;

    var_s2 = 0;
    if (arg2 > 0) {
        new_var = 0x42;
        var_s1 = arg1;
        var_s0 = arg0;
        do {
            *var_s0 = func_802A05A0_de(*var_s0);
            for (var_a0 = 0; var_a0 < 0x42; var_a0 += 1) {
                if (*var_s0 == D_800DE80C[var_a0]) {
                    *var_s1 = (s8)var_a0;
                    break;
                }
            }
            if (var_a0 == new_var) {
                *var_s1 = 0;
            }
            var_s1 += 1;
            var_s2 += 1;
            var_s0 += 1;
        } while (var_s2 < arg2);
    }
}

/* Returns one when a tilde appears among the first n + 1 bytes of a string, otherwise zero. */
s32 func_804057BC_de(u8 *text, s32 count) {
    do {
        if (*text++ == '~') {
            return 1;
        }
    } while (--count != -1);
    return 0;
}

/* Rounds a byte count up to whole 256-byte units; func_80435384_de passes it the 0x648-byte size
   that func_80435424_de returns. */
u32 func_804057EC_de(u32 bytes) {
    return (bytes + 0xFF) >> 8;
}

/* Computes the CRC-32 with polynomial 0xEDB88320 of arg1 bytes at arg0, continuing from the running value arg2, from a 256-entry table built on the stack. Adapted from func_802A08B8_de. */

u32 func_804057F8_de(u8 *arg0, u32 arg1, u32 arg2) {
    u32 table[256];
    u32 i;
    u32 j;
    u32 value;
    u32 shifted;
    u8 *end;

    for (i = 0; i < 256; i++) {
        value = i;
        for (j = 0; j < 8; j++) {
            shifted = value >> 1;
            if (value & 1) {
                shifted ^= 0xEDB88320U;
            }
            value = shifted;
        }
        table[i] = value;
    }

    end = arg0 + arg1;
    arg2 = ~arg2;
    while (arg0 < end) {
        arg2 = table[(arg2 ^ *arg0++) & 0xFF] ^ ((arg2 >> 8) & 0xFFFFFF);
    }
    return ~arg2;
}

/* Returns the word held in D_800E2850. */
extern s32 D_800E2850;

s32 func_804058A0_de(void) {
    return D_800E2850;
}
