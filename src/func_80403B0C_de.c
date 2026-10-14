#include "span_16E000/code_80400000.h"
#include "types.h"

/** Return the selected bit from a packed byte array. */
u32 func_80403B0C_de(u8 *bits, s32 index)
{
    s32 byte = index >> 3;
    u32 mask;

    index &= 7;
    mask = 1;
    bits += byte;
    return *bits & (mask << index);
}
