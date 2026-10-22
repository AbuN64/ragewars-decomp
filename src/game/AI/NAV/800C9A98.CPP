#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
INCLUDE_RODATA("data_800C", D_80274DFC_CA698);
#endif

#if defined(VERSION_US)
INCLUDE_DATA("data_800C", rodata_unresolved_800C48E4);
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", rodata_unresolved_800C4CA4);
#endif

#if defined(VERSION_EU)
INCLUDE_DATA("data_800C", rodata_unresolved_800C4C64);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("data_800C", rodata_unresolved_800C49B4);
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_80274DFC_CA698_us_rev1.c */
const unsigned int D_blob_a3631d75d7ffe498db90[3] = {
    0xBF800000, 0x3F800000, 0x3F800000,
};
#endif
