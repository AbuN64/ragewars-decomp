#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
const unsigned int rodata_unresolved_800C98E8[2] = {
    0x3F800000, 0x3F800000,
};
#endif

#if !(defined(VERSION_US_REV1))
const unsigned int D_80271430_CA4F0[4] = {
    0x461C4000, 0x38D1B717, 0x3F800000, 0x3F800000,
};
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: rodata/unresolved/800C98E8 */
const unsigned int D_blob_e63c5efcbef0bd808452[2] = {
    0x3F800000, 0x3F800000,
};

const unsigned int D_auto_src_rw_pool_80271430_CA4F0_us_rev1[4] = {
    0x461C4000, 0x38D1B717, 0x3F800000, 0x3F800000,
};
#endif
