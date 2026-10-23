#include "include_asm.h"

#if !(defined(VERSION_US))
/* ROM-grounded data: src/rw_constants_80212E24_eu_x_C7DC0_us_rev1.c */
const unsigned int D_blob_0f1afdbce69ade8acdc6[1] = {
    0x42CCCCCC,
};
#endif

#if defined(VERSION_EU_X)
unsigned int rodata_unresolved_800C23B4[3] = {
    0x3C8EFA36, 0x41800000, 0x4F000000,
};
#endif

#if defined(VERSION_DE)
unsigned int rodata_unresolved_800C20D4[3] = {
    0x424CCCCC, 0xAFB10014, 0x00C08821,
};
#endif
