#include "include_asm.h"

#if !(defined(VERSION_EU) || defined(VERSION_EU_X))
/* ROM-grounded data: rodata/shared/800E2790 */
const unsigned short D_blob_phase2_6827ef79cc30b8572dd6[3] = {
    0x2025, 0x3033, 0x6400,
};
#endif

#if defined(VERSION_US)
unsigned short rodata_unresolved_800DD416[1] = {
    0x0000,
};
#endif

#if defined(VERSION_DE)
unsigned short rodata_unresolved_800DE766[1] = {
    0x0000,
};
#endif

#if defined(VERSION_US_REV1)
unsigned short rodata_unresolved_800E2796[1] = {
    0x0000,
};
#endif
