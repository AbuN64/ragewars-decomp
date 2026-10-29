#include "include_asm.h"

/* 800E0DCC.CPP */
#if defined(VERSION_DE) || defined(VERSION_US)
const unsigned char k_GDigitdotformatEncodedBytes[5] = {
    0x25, 0x31, 0x64, 0x2E, 0x00,
};
#endif

#if defined(VERSION_US)
/* bytes live in the preceding array */
#endif

#if defined(VERSION_DE)
/* bytes live in the preceding array */
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_text_8040B444_E19CC_us_rev1.c */
const unsigned char g_digitDotFormat[5] = {
    0x25, 0x31, 0x64, 0x2E, 0x00,
};
#endif

/* 800E0DD1.CPP */

/* 800E0DD1_2.CPP */

