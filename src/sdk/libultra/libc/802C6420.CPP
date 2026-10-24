#include "include_asm.h"

#if !defined(VERSION_EU)
/* UnsignedRemainder: libgcc2 remainder with the VR4300 HI/LO hazards. */
/* gcc-2.8.1 libgcc2 __umoddi3 compiled in place; the units name it Libc_UnsignedRemainder */
#define __umoddi3 Libc_UnsignedRemainder
#define L_umoddi3
#if defined(VERSION_US)
#define LIBGCC2_EXTERNAL_CLZ D_auto_rodata_unresolved_800C7C18_0C8A20_0C8B20
#else
#define LIBGCC2_EXTERNAL_CLZ D_auto_src_rw_u64_remainder_normalization_width_us_rev1
#endif
#include "libgcc2.inc.c"
#else
INCLUDE_ASM("span_1000", Libc_UnsignedRemainder);
#endif
