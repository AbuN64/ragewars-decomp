#include "include_asm.h"

#ifdef NON_MATCHING
#include "TYPES.H"

/* Signed 64-bit remainder. The ROM normalizes both operands before unsigned
 * division and restores the dividend's sign on the remainder. */
s64 func_802C0820_de(s64 numerator, s64 denominator) {
    u64 dividend = numerator < 0 ? -(u64)numerator : (u64)numerator;
    u64 divisor = denominator < 0 ? -(u64)denominator : (u64)denominator;
    u64 remainder = 0;
    s32 bit;

    for (bit = 0; bit < 64; bit++) {
        remainder = (remainder << 1) | (dividend >> 63);
        dividend <<= 1;
        if (remainder >= divisor) {
            remainder -= divisor;
        }
    }
    return numerator < 0 ? -remainder : remainder;
}
#else
#if !(defined(VERSION_EU_X) || defined(VERSION_US_REV1))
INCLUDE_ASM("span_1000", func_802C0820_de);
#endif
#if defined(VERSION_EU_X)
INCLUDE_ASM("span_1000", func_802C0B04);
#endif
#if defined(VERSION_US_REV1)
INCLUDE_ASM("span_1000", func_802C5914);
#endif
#endif

#if defined(VERSION_US)
INCLUDE_DATA("span_1000", rodata_unresolved_802C0CC8);
#endif
