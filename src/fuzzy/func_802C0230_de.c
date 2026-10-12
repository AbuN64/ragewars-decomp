#include "types.h"

s64 func_802C0230_de(s64 dividend, s64 denominator) {
    u64 numerator = (u64)dividend, divisor = (u64)denominator;
    s32 negative = (dividend < 0) != (denominator < 0);
    u64 quotient = 0, remainder = 0;
    u32 i, carry;
    if (dividend < 0) numerator = 0 - numerator;
    if (denominator < 0) divisor = 0 - divisor;
    for (i = 0; i < 64; i++) {
        carry = (u32)(remainder >> 63);
        remainder = (remainder << 1) | (numerator >> 63);
        numerator <<= 1;
        quotient <<= 1;
        if (carry || remainder >= divisor) {
            remainder -= divisor;
            quotient |= 1;
        }
    }
    if (negative) quotient = 0 - quotient;
    return (s64)quotient;
}
