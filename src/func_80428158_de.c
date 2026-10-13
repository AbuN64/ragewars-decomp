#include "common/types_8a8189af7b05.h"
#include "span_16E000/code_804264F0.h"
#include "types.h"

/* Returns one when the two arguments are equal or when any of the sixty-four 12-byte pairs of D_800E4A84 holds exactly that ordered pair, zero otherwise.
   Adapted from func_8041F1D8_de with the single-key slot scan changed to an ordered-pair lookup over 64 twelve-byte entries. */



extern struct Pair D_800E4A84[];

s32 func_80428158_de(s32 a, s32 b) {
    s32 i;

    if (a == b) {
        return 1;
    }
    for (i = 0; i < 64; i++) {
        if (D_800E4A84[i].a == a && D_800E4A84[i].b == b) {
            return 1;
        }
    }
    return 0;
}
