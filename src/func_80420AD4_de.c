#include "span_16E000/code_8041F1FC.h"
#include "types.h"

/* Counts how many of the four 0x4C8-byte entries D_800E42D0 points to are in state 1 or 2. */


extern struct EntryRecAt14V2 *D_800E42D0;

s32 func_80420AD4_de(void) {
    s32 count = 0;
    s32 i;

    for (i = 0; i < 4; i++) {
        if ((u32) (D_800E42D0[i].state - 1) < 2) {
            count++;
        }
    }
    return count;
}
