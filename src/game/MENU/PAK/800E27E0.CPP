#include "include_asm.h"

#if defined(VERSION_DE) || defined(VERSION_US_REV1)
/* ROM-grounded data: rodata/shared/800E27E0 */
const unsigned short g_pakFormatSpacedInt2[3] = {
    0x2020, 0x2532, 0x6400,
};
#endif

#if defined(VERSION_DE)
unsigned short rodata_unresolved_800DE7A6[1] = {
    0x0000,
};
#endif

#if defined(VERSION_US_REV1)
unsigned short rodata_unresolved_800E27E6[1] = {
    0x0000,
};
#endif
