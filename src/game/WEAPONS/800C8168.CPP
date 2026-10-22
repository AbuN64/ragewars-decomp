#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
INCLUDE_RODATA("data_800C", D_8023371C_C8D68);
#endif

#if defined(VERSION_US)
INCLUDE_DATA("data_800C", rodata_unresolved_800C2FAC);
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", rodata_unresolved_800C336C);
#endif

#if defined(VERSION_EU)
INCLUDE_DATA("data_800C", rodata_unresolved_800C332C);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("data_800C", rodata_unresolved_800C307C);
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_8023371C_C8D68_us_rev1.c */
const unsigned int D_blob_9c143aa5516c0958c802[1] = {
    0x44160000,
};
#endif
