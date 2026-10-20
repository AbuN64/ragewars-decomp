#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
INCLUDE_RODATA("data_800C", D_8020EC14_C7B50);
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", rodata_unresolved_800C2144);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("data_800C", rodata_unresolved_800C1E64);
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_8020EC14_C7B50_us_rev1.c */
const unsigned int D_blob_69afdf3e057a5b96fec2[1] = {
    0x47480000,
};
#endif
