#include "include_asm.h"
#include "COMMON/EXTERNS_2.H"

/* ROM-grounded data: rodata/shared/800CC850 */
const unsigned char D_blob_phase2_f422b875d2f19de41a54[3] = {
    0x45, 0x58, 0x00,
};

#if defined(VERSION_US)
INCLUDE_DATA("data_800C", rodata_unresolved_800C7523);
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", rodata_unresolved_800C8BC3);
#endif

#if defined(VERSION_EU)
INCLUDE_DATA("data_800C", rodata_unresolved_800C81F3);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("data_800C", rodata_unresolved_800C7603);
#endif

#if defined(VERSION_US_REV1)
INCLUDE_DATA("data_800C", rodata_unresolved_800CC853);
#endif
