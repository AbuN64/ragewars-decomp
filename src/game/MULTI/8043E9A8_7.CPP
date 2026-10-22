#include "include_asm.h"

#if defined(VERSION_US)
INCLUDE_DATA("ovl_80400000", func_8043EFCC_us_rev1);
#endif

#if defined(VERSION_US_REV1)
/* Data separated from executable functions by the legacy split layout. */
unsigned int func_8043EFCC_us_rev1[1] = { 0x00E0A021U };
#endif
