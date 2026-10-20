#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
INCLUDE_RODATA("data_800C", D_8023E8D4_C93C0);
#endif

#if defined(VERSION_US)
INCLUDE_DATA("data_800C", rodata_unresolved_800C360C);
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", rodata_unresolved_800C39CC);
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_8023E8D4_C93C0_us_rev1.c */
const unsigned int D_blob_37a27c5aff94f4a05d69[1] = {
    0x4123D70A,
};

/* ROM-grounded data: src/rw_pool_8023EA44_C93C4_us_rev1.c */
const unsigned int D_blob_9cc5494f8fcccf64909a[1] = {
    0x4123D70A,
};

/* ROM-grounded data: src/rw_pool_8023ED64_C93C8_us_rev1.c */
const unsigned int D_blob_c41017ce312045ac8b0c[1] = {
    0x4123D70A,
};
#endif
