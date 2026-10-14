#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_80444030.h"
#include "types.h"

/* Counts the timer D_80154100 down by D_800D2988 without passing zero, then sets bit 24 of the flag word at offset 8 of a record unless func_80265350_de reports 0x400000, in which case the bit is cleared, stores what func_8040C3BC_de returns at offset 0x14 and returns zero. Adapted from func_80445590_de with the timer countdown added, func_80265350_de called without arguments and bit 24 instead of bit 23 changed. */


extern f32 D_80154100;
extern f32 D_800D2988;
extern s32 func_80265350_de(void);
extern s32 func_8040C3BC_de();

s32 func_80444C68_de(struct RecordRecAt14 *record) {
    D_80154100 -= D_800D2988;
    if (D_80154100 <= 0.0f) {
        D_80154100 = 0.0f;
    }
    if (func_80265350_de() != 0x400000) {
        record->flags |= 0x1000000;
    } else {
        record->flags &= ~0x1000000;
    }
    record->value = func_8040C3BC_de();
    return 0;
}
