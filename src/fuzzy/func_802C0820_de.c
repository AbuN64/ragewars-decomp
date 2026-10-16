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
