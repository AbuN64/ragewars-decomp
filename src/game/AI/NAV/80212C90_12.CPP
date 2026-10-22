#include "include_asm.h"

#if defined(VERSION_US)
INCLUDE_DATA("span_1000", func_8021335C_eu_x);
#endif

#if defined(VERSION_EU_X) || defined(VERSION_US_REV1)
/* Data separated from executable functions by the legacy split layout. */
unsigned int func_8021335C_eu_x[1] = { 0xF7B60110U };
#endif
