#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
const unsigned int D_80240C8C_C942C[3] = {
    0x3F800000, 0x3F800000, 0x3F800000,
};
#endif

#if defined(VERSION_US)
char rodata_unresolved_800C3678[8] =
    "\000\016m_dwCh";
#endif

#if defined(VERSION_EU_X)
unsigned int rodata_unresolved_800C3A38[2] = {
    0x47800000, 0x4F000000,
};
#endif

#if defined(VERSION_EU)
unsigned int rodata_unresolved_800C39F8[2] = {
    0x8E420028, 0x8E440044,
};
#endif

#if defined(VERSION_DE)
unsigned int rodata_unresolved_800C3748[2] = {
    0x3ED1B717, 0x3ED1B717,
};
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
