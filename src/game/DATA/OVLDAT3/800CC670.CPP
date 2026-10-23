#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
const unsigned int D_802AF2E0_CD270[3] = {
    0x42FE0000, 0x4F000000, 0x3F800000,
};
#endif

#if defined(VERSION_US)
unsigned int rodata_unresolved_800C734C[1] = {
    0x6174615F,
};
#endif

#if defined(VERSION_EU_X)
unsigned int rodata_unresolved_800C89EC[1] = {
    0x00000000,
};
#endif

#if defined(VERSION_EU)
unsigned int rodata_unresolved_800C801C[1] = {
    0x4275C28F,
};
#endif

#if defined(VERSION_DE)
unsigned int rodata_unresolved_800C742C[1] = {
    0xAFB60030,
};
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_802AF2E0_CD270_us_rev1.c */
const unsigned int D_blob_868e5463195d5f476023[3] = {
    0x42FE0000, 0x4F000000, 0x3F800000,
};
#endif
