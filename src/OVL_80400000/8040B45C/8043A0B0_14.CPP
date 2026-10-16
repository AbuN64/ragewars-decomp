#include "span_16E000/code_8043A0A4.h"
#include "TYPES.H"

/* Counts how many of the four 0x4D0-byte entries D_800E59E0 points to have the word at offset
   0x4B0 equal to one. */


extern struct EntryRecAt4B0 *D_800E59E0;

s32 func_8043BA24_de(void) {
    s32 count = 0;
    s32 i;

    for (i = 0; i < 4; i++) {
        if (D_800E59E0[i].state == 1) {
            count++;
        }
    }
    return count;
}
