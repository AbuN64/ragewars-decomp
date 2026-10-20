#include "include_asm.h"

#ifdef NON_MATCHING
#include "TYPES.H"

/* Unsigned 64-bit remainder, using restoring division so the runtime
 * primitive does not call itself through a compiler-generated modulo. */
u64 func_802C1330_de(u64 numerator, u64 divisor)
{
    u64 remainder = 0;
    u32 carry;
    s32 bit;
    if (divisor == 0) {
        return 1U / (u32)divisor;
    }
    for (bit = 63; bit >= 0; --bit) {
        carry = (u32)(remainder >> 63);
        remainder = (remainder << 1) | ((numerator >> bit) & 1);
        if (carry || remainder >= divisor) {
            remainder -= divisor;
        }
    }
    return remainder;
}
#else
INCLUDE_ASM("span_1000", func_802C1330_de);
#endif
