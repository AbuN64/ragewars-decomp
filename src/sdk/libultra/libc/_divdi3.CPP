#include "include_asm.h"

/* SignedDivide: libgcc2 division with the VR4300 HI/LO hazards. */
#define __divdi3 Libc_SignedDivide
#define L_divdi3
#define LIBGCC2_EXTERNAL_CLZ D_800C88F0
#include "libgcc2.inc.c"
