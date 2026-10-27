#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
const unsigned int D_8023DF70_C9380[3] = {
    0x4123D70A, 0x3F800000, 0x4123D70A,
};
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_8023DF70_C9380_us_rev1.c */
const unsigned int D_blob_6624772531fcc4dc0e62[1] = {
    0x4123D70A,
};

/* ROM-grounded data: src/rw_pool_8023E178_C9384_us_rev1.c */
const unsigned int D_blob_15414668f9063e063991[2] = {
    0x3F800000, 0x4123D70A,
};
#endif
