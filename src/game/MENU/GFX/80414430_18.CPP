#include "include_asm.h"

#if defined(VERSION_US)
INCLUDE_DATA("ovl_80400000", func_804160C4_eu_x);
#endif

#if defined(VERSION_EU_X) || defined(VERSION_US_REV1)
/* Data separated from executable functions by the legacy split layout. */
unsigned int func_804160C4_eu_x[3] = { 0x34C60204U, 0x3C050004U, 0x3C048011U };
#endif
