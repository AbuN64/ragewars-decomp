#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
INCLUDE_RODATA("data_800C", D_80246184_C9514);
#endif

#if defined(VERSION_US)
INCLUDE_DATA("data_800C", rodata_unresolved_800C375C);
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", rodata_unresolved_800C3B1C);
#endif

#if defined(VERSION_EU)
INCLUDE_DATA("data_800C", rodata_unresolved_800C3ADC);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("data_800C", rodata_unresolved_800C382C);
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_80246184_C9514_us_rev1.c */
const unsigned int D_blob_7cb729509528ee0305eb[1] = {
    0x3F800000,
};

/* ROM-grounded data: src/rw_pool_8024643C_C9518_us_rev1.c */
const unsigned int D_blob_f37d5279a6b8bc3cae0a[1] = {
    0x3F4CCCCD,
};
#endif
