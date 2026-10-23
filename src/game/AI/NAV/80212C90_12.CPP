#include "include_asm.h"

#if defined(VERSION_US)
unsigned int func_8021335C_eu_x[1] = {
    0x4D494E49,
};
#endif

#if defined(VERSION_EU_X) || defined(VERSION_US_REV1)
/* Data separated from executable functions by the legacy split layout. */
unsigned int func_8021335C_eu_x[1] = { 0xF7B60110U };
#endif
