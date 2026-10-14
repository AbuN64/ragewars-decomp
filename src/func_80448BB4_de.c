#include "span_16E000/code_80447BB0.h"
#include "types.h"

/* Sums the fourteen halfwords of a 0x1C-byte block into two checksums: the plain sum and the sum
   of their complements. Returns zero. */
s32 func_80448BB4_de(u16 *block, u16 *sum, u16 *inverse) {
    u32 offset;

    *inverse = 0;
    *sum = 0;
    for (offset = 0; offset < 0x1C; offset += 2) {
        u16 value = *(u16 *) ((char *) block + offset);

        *sum += value;
        *inverse += (u16) ~value;
    }
    return 0;
}
