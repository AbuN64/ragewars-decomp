/* Normalize the operands, divide unsigned, then restore the dividend's sign. */
#define __moddi3 Libc_SignedRemainder
#define L_moddi3
#define LIBGCC2_EXTERNAL_CLZ D_800C7E00_de
#include "libgcc2.inc.c"

#if defined(VERSION_US)
char rodata_unresolved_802C0CC8[8] =
    "\000\000\000\016CMen";
#endif
