#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
const unsigned int D_802C0044_CDB38[4] = {
    0x3F000000, 0x46FFFE00, 0x3F000000, 0xC7000000,
};
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_802C0044_CDB38_us_rev1.c */
const unsigned int D_blob_dc2a18ce4ba9881b8b1a[4] = {
    0x3F000000, 0x46FFFE00, 0x3F000000, 0xC7000000,
};
#endif
