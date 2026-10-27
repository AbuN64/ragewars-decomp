#include "include_asm.h"

#if !(defined(VERSION_EU) || defined(VERSION_EU_X))
/* ROM-grounded data: rodata/shared/800E2790 */
const unsigned short g_fmtSpaceDec3[3] = {
    0x2025, 0x3033, 0x6400,
};
#endif
