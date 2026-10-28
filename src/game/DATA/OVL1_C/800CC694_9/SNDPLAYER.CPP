#include "include_asm.h"
#include "COMMON/EXTERNS_2.H"

#if !(defined(VERSION_US_REV1))
const unsigned char D_802B2780_CD394[7] = {
    0x38, 0xD1, 0xB7, 0x17, 0x45, 0x58, 0x00,
};
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_tail_802B2780_CD394_us_rev1.c */
const unsigned int D_blob_67e9e1dfeb2151f9ee6b[1] = {
    0x38D1B717,
};

/* ROM-grounded data: src/rw_formats_802B2CF0_CD398_us_rev1.c */
const unsigned char D_blob_ce162ddee47edc10f46e[3] = {
    0x45, 0x58, 0x00,
};
#endif
