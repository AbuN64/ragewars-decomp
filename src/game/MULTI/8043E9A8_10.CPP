#include "include_asm.h"

#if defined(VERSION_US)
INCLUDE_DATA("ovl_80400000", func_8043F284_us_rev1);
#endif

#if defined(VERSION_US_REV1)
/* Data separated from executable functions by the legacy split layout. */
unsigned int func_8043F284_us_rev1[3] = { 0x240400FFU, 0x00602021U, 0x92220016U };
#endif
