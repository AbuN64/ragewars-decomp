#include "TYPES.H"
#include "shared/unsigned_quotient.h"

u64 func_802C0DA0_de(u64 numerator, u64 divisor) {
    u64 quotient = 0, remainder = 0;
    u32 i, carry;
    if (numerator < divisor) return 0;
    if (divisor == 1) return numerator;
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
    return quotient;
}
