#include "include_asm.h"
#include "COMMON/ALFXPARAM.H"

#if !(defined(VERSION_US_REV1))
const unsigned int D_802B6900_CD6C8[7] = {
    0xBF800000, 0x3F800000, 0x3F800000, 0x47800000, 0x3F800000, 0x47800000, 0x37800000,
};
#endif

#if defined(VERSION_EU)
unsigned int rodata_unresolved_800C8484[3] = {
    0x00000000, 0x41F00000, 0x00000000,
};
#endif

#if defined(VERSION_DE)
unsigned int rodata_unresolved_800C7894[3] = {
    0x3F000000, 0xBF800000, 0x40000000,
};
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_802B6900_CD6C8_us_rev1.c */
const unsigned int D_blob_189a1b8a242510f76644[2] = {
    0xBF800000, 0x3F800000,
};

/* ROM-grounded data: src/rw_pool_802B6B80_CD6D0_us_rev1.c */
const unsigned int D_blob_7f01e3274669e6363caf[2] = {
    0x3F800000, 0x47800000,
};

/* ROM-grounded data: src/rw_pool_802B6C6C_CD6D8_us_rev1.c */
const unsigned int D_blob_86ba82f1b7cdc4449705[1] = {
    0x3F800000,
};

/* ROM-grounded data: src/rw_pool_802B6CBC_CD6DC_us_rev1.c */
const unsigned int D_blob_aa7e07c11c48ab19cc55[1] = {
    0x47800000,
};

/* ROM-grounded data: src/rw_pool_802B6D54_CD6E0_us_rev1.c */
const unsigned int D_blob_f8768ba7f63b40f8e1cf[1] = {
    0x37800000,
};
#endif
