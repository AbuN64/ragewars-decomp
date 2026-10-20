#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
INCLUDE_RODATA("data_800C", D_80240C8C_C942C);
#endif

#if defined(VERSION_US)
INCLUDE_DATA("data_800C", rodata_unresolved_800C3678);
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", rodata_unresolved_800C3A38);
#endif

#if defined(VERSION_EU)
INCLUDE_DATA("data_800C", rodata_unresolved_800C39F8);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("data_800C", rodata_unresolved_800C3748);
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_80240C8C_C942C_us_rev1.c */
const unsigned int D_blob_9fabb12b4d9c02426ef9[1] = {
    0x3F800000,
};

/* ROM-grounded data: src/rw_pool_802412D0_C9430_us_rev1.c */
const unsigned int D_blob_20bbdad142670bb714dd[1] = {
    0x3F800000,
};

/* ROM-grounded data: src/rw_pool_802413C8_C9434_us_rev1.c */
const unsigned int D_blob_5404c89adeaf311159c1[1] = {
    0x3F800000,
};
#endif
