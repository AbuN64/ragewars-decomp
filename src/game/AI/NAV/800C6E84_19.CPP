#include "include_asm.h"

#if !(defined(VERSION_US))
/* ROM-grounded data: src/rw_constants_80212E24_eu_x_C7DC0_us_rev1.c */
const unsigned int D_blob_0f1afdbce69ade8acdc6[1] = {
    0x42CCCCCC,
};
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", rodata_unresolved_800C23B4);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("data_800C", rodata_unresolved_800C20D4);
#endif
