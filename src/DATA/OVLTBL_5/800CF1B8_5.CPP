#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
INCLUDE_RODATA("data_800C", D_8021EEFC_CFDB8);
#endif

#if defined(VERSION_US)
INCLUDE_DATA("data_800C", rodata_unresolved_800C9E8C);
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", rodata_unresolved_800CB52C);
#endif

#if defined(VERSION_EU)
INCLUDE_DATA("data_800C", rodata_unresolved_800CAB5C);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("data_800C", rodata_unresolved_800C9F78);
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_8021EEFC_CFDB8_us_rev1.c */
const unsigned int D_blob_9d33f2f29912959783e4[1] = {
    0xC2EC0000,
};
#endif
