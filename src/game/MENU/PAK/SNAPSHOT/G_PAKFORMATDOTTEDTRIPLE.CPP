#include "include_asm.h"

#if defined(VERSION_DE) || defined(VERSION_US)
const char s_snapshotThreePartNumberFormatVariant[14] =
    "%3d.%02d.%02d\000";
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_text_8040A614_E19B4_us_rev1.c */
const unsigned short g_pakFormatDottedTriple[7] = {
    0x2533, 0x642E, 0x2530, 0x3264, 0x2E25, 0x3032, 0x6400,
};
#endif
