#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
const unsigned int D_8020EDCC_C7BCC[3] = {
    0x47480000, 0x4123D70A, 0xC4199999,
};
#endif

#if defined(VERSION_EU_X)
unsigned int rodata_unresolved_800C21C8[2] = {
    0x002301B0, 0x00230104,
};
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_8020EDCC_C7BCC_us_rev1.c */
const unsigned int D_blob_db5938c31029476434e9[1] = {
    0x47480000,
};

/* ROM-grounded data: src/rw_pool_8020EE50_C7BD0_us_rev1.c */
const unsigned int D_blob_b357b72b76d4c13fda02[1] = {
    0x4123D70A,
};

/* ROM-grounded data: src/rw_pool_8020EEA4_C7BD4_us_rev1.c */
const unsigned int D_blob_a86961089d07a2efc2e5[1] = {
    0xC4199999,
};
#endif
