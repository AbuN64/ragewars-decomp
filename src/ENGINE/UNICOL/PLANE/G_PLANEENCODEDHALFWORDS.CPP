#include "include_asm.h"
#include "TYPES.H"

/* 800C8838.CPP */
#if defined(VERSION_US_REV1)
/* ROM-grounded data: rodata/unresolved/800C8838 */
/* Alignment fill to the next 16-byte object boundary. */
unsigned int g_PlaneEncodedWordsAlignmentPad[2] = {
    0x47800000, 0x4F000000,
};
#endif

/* 800C8F82.CPP */
#if defined(VERSION_EU_X)
/* ROM-grounded data: rodata/unresolved/800C8F82 */
/* Alignment fill to the next 16-byte object boundary. */
unsigned short g_PlaneEncodedHalfwordsAlignmentPad[] = {
    0x0000,
#if defined(VERSION_EU_X)
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
#endif
};
#endif

#if defined(VERSION_EU_X)
/* bytes live in the preceding array */
#endif

#if defined(VERSION_US_REV1)
/* bytes live in the preceding array */
#endif

/* 802591C0_3.CPP */
#if defined(VERSION_US)
/* Alignment fill to the next 16-byte object boundary. */
unsigned int k_PlaneEncodedWordsAlignmentPad[1] = {
    0x00080071,
};
#endif

/* 802624A0_24.CPP */
#if defined(VERSION_EU)
/* Alignment fill to the next 16-byte object boundary. */
unsigned int k_PlaneEncodedWordsBlock1AlignmentPad[1] = {
    0xAFA80020,
};
#endif
