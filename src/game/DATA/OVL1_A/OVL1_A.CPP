#include "include_asm.h"
#include "TYPES.H"

/* 800C6B40.CPP */
#if !(defined(VERSION_EU) || defined(VERSION_EU_X))
/* ROM-grounded data: src/rw_constants_8020402C_us_rev1_C7740_us_rev1.c */
#if !(defined(VERSION_US_REV1) || defined(VERSION_DE) || defined(VERSION_US))
const unsigned int D_blob_c8d42251da213ab141b0[1] = {
    0x42F5C28F,
};
#endif
#endif

/* 802624A0_25.CPP */
#if defined(VERSION_EU_X)
unsigned int rodata_unresolved_800C45DC[1] = {
    0x7F7FFFFF,
};
#endif

/* 802ABDBC_18.CPP */
#if defined(VERSION_US)
unsigned int rodata_unresolved_800C618C[1] = {
    0x6E5F7404,
};
#endif

/* 802ABDBC_22.CPP */
#if defined(VERSION_EU)
unsigned int rodata_unresolved_800C64FC[1] = {
    0x00671823,
};
#endif
