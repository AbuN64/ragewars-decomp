#include "include_asm.h"

#if defined(VERSION_EU_X)
#include "TYPES.H"
#include "COMMON/EFFECTRENDER.H"
/* Signed 64-bit integer to double: the high word scaled by 2^32 plus the low word, each word read
   as signed and corrected by 2^32 when negative. */

double func_802C6970_us_rev1(s64 value) {
    double high, low;
    s32 negate = 0;
    if (value < 0) {
        value = -value;
        negate = 1;
    }
    high = (s32)(value >> 32);
    if ((s32)(value >> 32) < 0)
        high += D_800C8100_de;
    high *= D_800C8108_de;
    high *= D_800C8108_de;
    low = (s32)value;
    if ((s32)value < 0)
        low += D_800C8110_de;
    high += low;
    return negate ? -high : high;
}
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("span_1000", rodata_unresolved_802C1B58_0C27E8);
#endif
