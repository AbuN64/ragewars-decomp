#include "include_asm.h"
#include "sdk/libgultra.h"

/* 800CCD40.CPP */
#if !(defined(VERSION_US_REV1))
const char g_printfFlagCharactersText[8] =
    " +-#0\000\000\000";
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_text_802BD430_CD940_us_rev1.c */
const unsigned short D_blob_46cdb71ef7093b251943[3] = {
    0x202B, 0x2D23, 0x3000,
};
#endif

/* 800CD394_7.CPP */
#if defined(VERSION_US_REV1)
/* ROM-grounded data: rodata/unresolved/800CCD46 */
unsigned short D_blob_85ed6555d8a22b993a41[1] = {
    0x0000,
};
#endif

/* 800CD394_8.CPP */
#if defined(VERSION_US_REV1)
unsigned int D_auto_data_unresolved_800CCD48[6] = {
    0x00000001, 0x00000002, 0x00000004, 0x00000008, 0x00000010, 0x00000000,
};
#endif
