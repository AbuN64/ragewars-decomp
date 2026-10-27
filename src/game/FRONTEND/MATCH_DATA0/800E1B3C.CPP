#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
const unsigned int D_8042D28C_E273C[2] = {
    0x43160000, 0x437F0000,
};
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_8042D28C_E273C_us_rev1.c */
const unsigned int D_blob_e43399bdbd08619aff58[2] = {
    0x43160000, 0x437F0000,
};
#endif
