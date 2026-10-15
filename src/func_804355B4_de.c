#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_80434F4C.h"
#include "types.h"

/* Counts how many of the four 2920-byte entries D_800E54A4 points to have a non-zero word at
   offset 0x58. */


extern struct PlayerRecAt58 *D_800E54A4;

s32 func_804355B4_de(void) {
    s32 count = 0;
    s32 i;

    for (i = 0; i < 4; i++) {
        if (D_800E54A4[i].state != 0) {
            count++;
        }
    }
    return count;
}
