#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
const unsigned int D_80275F28_CA6F4[1] = {
    0xBF800000,
};
#endif

#if defined(VERSION_US)
unsigned int rodata_unresolved_800C4938[2] = {
    0x00000800, 0x08001400,
};
#endif

#if defined(VERSION_EU_X)
unsigned int rodata_unresolved_800C4CF8[2] = {
    0xB58637BD, 0x358637BD,
};
#endif

#if defined(VERSION_EU)
unsigned int rodata_unresolved_800C4CB8[2] = {
    0x00000000, 0x46022082,
};
#endif

#if defined(VERSION_DE)
unsigned int rodata_unresolved_800C4A08[2] = {
    0x3C40C0C1, 0x4F000000,
};
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_80275F28_CA6F4_us_rev1.c */
const unsigned int D_blob_dd17c7991d2f6b062f5a[1] = {
    0xBF800000,
};
#endif
