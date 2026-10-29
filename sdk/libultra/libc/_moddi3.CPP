/* Normalize the operands, divide unsigned, then restore the dividend's sign. */
#define __moddi3 Libc_SignedRemainder
#define L_moddi3
#define LIBGCC2_EXTERNAL_CLZ g_signedRemainderLeadingZeroTable
#include "../../libgcc/libgcc2.inc.c"

#if defined(VERSION_US)
char k_Moddi3EncodedBytes[8] =
    "\000\000\000\016CMen";
#endif
