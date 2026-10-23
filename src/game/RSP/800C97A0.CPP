#include "include_asm.h"

#if !(defined(VERSION_DE) || defined(VERSION_US_REV1))
const unsigned int D_8026E5E0_CA3A0[3] = {
    0x41700000, 0x40A00000, 0x43800000,
};
#endif

#if defined(VERSION_US)
unsigned int rodata_unresolved_800C45EC[1] = {
    0x740E6D5F,
};
#endif

#if defined(VERSION_EU_X)
unsigned int rodata_unresolved_800C49AC[1] = {
    0x00000000,
};
#endif

#if defined(VERSION_EU)
unsigned int rodata_unresolved_800C496C[1] = {
    0x4491A000,
};
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_8026E5E0_CA3A0_us_rev1.c */
const unsigned int D_blob_66088a10f518a8d8ca1f[3] = {
    0x41700000, 0x40A00000, 0x43800000,
};
#endif
