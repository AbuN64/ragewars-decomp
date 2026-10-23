#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
const unsigned int D_802A63A4_CBC50[2] = {
    0x3C23D70A, 0x3E95CBEC,
};
#endif

#if defined(VERSION_US)
char rodata_unresolved_800C5DF8[8] =
    "hangedT\000";
#endif

#if defined(VERSION_EU_X)
char rodata_unresolved_800C61A8[8] =
    "        ";
#endif

#if defined(VERSION_EU)
unsigned int rodata_unresolved_800C6168[2] = {
    0x00002812, 0x0065102B,
};
#endif

#if defined(VERSION_DE)
unsigned int rodata_unresolved_800C5EC8[2] = {
    0x3E800000, 0x3F400000,
};
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_802A63A4_CBC50_us_rev1.c */
const unsigned int D_blob_f456bd3bc88b06ab000f[2] = {
    0x3C23D70A, 0x3E95CBEC,
};
#endif
