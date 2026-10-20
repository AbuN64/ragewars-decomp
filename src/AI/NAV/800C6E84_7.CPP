#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
INCLUDE_RODATA("data_800C", D_8020D6E4_C7AA4);
#endif

#if defined(VERSION_US)
INCLUDE_DATA("data_800C", rodata_unresolved_800C1CEC);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("data_800C", rodata_unresolved_800C1DBC);
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_8020D6E4_C7AA4_us_rev1.c */
const unsigned int D_blob_d6926af3944f8f0280f7[1] = {
    0x3F800000,
};

/* ROM-grounded data: src/rw_pool_8020D9C0_C7AA8_us_rev1.c */
const unsigned int D_blob_db0a814bd02b424ea5bd[1] = {
    0x3F800000,
};
#endif
