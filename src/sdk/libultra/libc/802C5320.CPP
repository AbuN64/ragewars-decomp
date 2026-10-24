#include "include_asm.h"

#if defined(NON_MATCHING) || !defined(VERSION_US)
/* SignedDivide: libgcc2 division with the VR4300 HI/LO hazards. */
#if defined(VERSION_US)
#define __divdi3 func_802C0164
#else
#define __divdi3 Libc_SignedDivide
#endif
#define L_divdi3
#define LIBGCC2_EXTERNAL_CLZ D_800C88F0
#include "libgcc2.inc.c"
#else
#if !(defined(VERSION_US))
INCLUDE_ASM("span_1000", Libc_SignedDivide);
#endif
#if defined(VERSION_US)
INCLUDE_ASM("span_1000", func_802C0164);
#endif
#endif
