#if defined(NON_MATCHING) && defined(__GNUC__) && __GNUC__ >= 3
long long Libc_SignedRemainder(long long numerator, long long denominator) {
    return denominator == -1 ? 0 : numerator % denominator;
}
#else
/* Normalize the operands, divide unsigned, then restore the dividend's sign. */
#define __moddi3 Libc_SignedRemainder
#define L_moddi3
#define LIBGCC2_EXTERNAL_CLZ D_800C7E00_de
#include "libgcc2.inc.c"
#endif

#if defined(VERSION_US)
char rodata_unresolved_802C0CC8[8] =
    "\000\000\000\016CMen";
#endif
