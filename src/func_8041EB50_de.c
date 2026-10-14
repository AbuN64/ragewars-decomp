#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_8041DF04.h"
#include "types.h"

/* Counts how many of the three 28-byte entries of D_80153F80 hold a non-negative first word. */


extern struct EntryRecAt0V1 D_80153F80[];

s32 func_8041EB50_de(void) {
    s32 count = 0;
    s32 i;

    for (i = 0; i < 3; i++) {
        if (D_80153F80[i].value >= 0) {
            count++;
        }
    }
    return count;
}
