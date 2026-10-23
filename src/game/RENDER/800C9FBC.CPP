#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
const unsigned int D_802859D0_CABBC[2] = {
    0x3F800000, 0x3F800000,
};
#endif

#if defined(VERSION_US)
unsigned int rodata_unresolved_800C4E04[3] = {
    0x000B0000, 0x00000012, 0x43414D45,
};
#endif

#if defined(VERSION_EU_X)
unsigned int rodata_unresolved_800C51C4[3] = {
    0x3F000000, 0x3B088889, 0x4F000000,
};
#endif

#if defined(VERSION_EU)
unsigned int rodata_unresolved_800C5184[3] = {
    0xAC450000, 0x01201821, 0x28620002,
};
#endif

#if defined(VERSION_DE)
char rodata_unresolved_800C4ED4[12] =
    "ne__Construc";
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_802859D0_CABBC_us_rev1.c */
const unsigned int D_blob_4faf23a8416908d6583f[2] = {
    0x3F800000, 0x3F800000,
};
#endif
