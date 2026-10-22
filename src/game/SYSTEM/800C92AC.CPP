#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
INCLUDE_RODATA("data_800C", D_8026193C_C9EAC);
#endif

#if defined(VERSION_US)
INCLUDE_DATA("data_800C", rodata_unresolved_800C40F4);
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", rodata_unresolved_800C44B4);
#endif

#if defined(VERSION_EU)
INCLUDE_DATA("data_800C", rodata_unresolved_800C4474);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("data_800C", rodata_unresolved_800C41C4);
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_8026193C_C9EAC_us_rev1.c */
const unsigned int D_blob_92158a92bbaada1c319d[2] = {
    0x38C9116D, 0x3D888889,
};
#endif
