#include "include_asm.h"
#include "COMMON/ALFXPARAM.H"

#if !(defined(VERSION_US_REV1))
const unsigned char g_SndplayerBytes1[7] = {
    0x38, 0xD1, 0xB7, 0x17, 0x45, 0x58, 0x00,
};
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_tail_802B2780_CD394_us_rev1.c */
const unsigned int g_SndplayerWords1[1] = {
    0x38D1B717,
};

/* ROM-grounded data: src/rw_formats_802B2CF0_CD398_us_rev1.c */
const unsigned char g_SndplayerBytes2[3] = {
    0x45, 0x58, 0x00,
};
#endif
