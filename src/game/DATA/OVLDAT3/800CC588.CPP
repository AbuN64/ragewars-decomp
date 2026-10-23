#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
const unsigned int D_802AE824_CD188[3] = {
    0x41F00000, 0x00000000, 0x4F000000,
};
#endif

#if defined(VERSION_US)
unsigned int rodata_unresolved_800C7264[3] = {
    0x40010000, 0x00000C43, 0x4672616D,
};
#endif

#if defined(VERSION_EU_X)
unsigned int rodata_unresolved_800C8904[3] = {
    0x002791AC, 0x002791EC, 0x002790F0,
};
#endif

#if defined(VERSION_EU)
unsigned int rodata_unresolved_800C7F34[3] = {
    0x00229ED8, 0x00229EE0, 0x00229EE8,
};
#endif

#if defined(VERSION_DE)
char rodata_unresolved_800C7344[12] =
    "audio/csplay";
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_802AE824_CD188_us_rev1.c */
const unsigned int D_blob_6e17b1ab7ebf49014ea8[3] = {
    0x41F00000, 0x00000000, 0x4F000000,
};
#endif
