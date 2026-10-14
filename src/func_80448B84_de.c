#include "span_16E000/code_80447BB0.h"
#include "types.h"
/* Returns the 16-bit sum of the first count bytes of a block. */

u16 func_80448B84_de(u8 *bytes, s32 count)
{
    s32 i;
    s32 sum;

    i = 0;
    sum = i;
    for (; i < count; i++) {
        sum += *bytes++;
        sum &= 0xFFFF;
    }
    return sum;
}
