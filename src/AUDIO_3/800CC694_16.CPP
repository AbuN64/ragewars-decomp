#include "include_asm.h"
#include "COMMON/EXTERNS_2.H"

#if !(defined(VERSION_US_REV1))
INCLUDE_RODATA("data_800C", D_802B468C_CD438);
#endif

#if defined(VERSION_US)
INCLUDE_RODATA("data_800C", rodata_unresolved_800C7510);
#endif

#if defined(VERSION_US)
INCLUDE_DATA("data_800C", rodata_unresolved_800C7518);
#endif

#if defined(VERSION_EU)
INCLUDE_RODATA("data_800C", rodata_unresolved_800C81E0);
#endif

#if defined(VERSION_EU)
INCLUDE_DATA("data_800C", rodata_unresolved_800C81E8);
#endif

#if defined(VERSION_DE)
INCLUDE_RODATA("data_800C", rodata_unresolved_800C75F0);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("data_800C", rodata_unresolved_800C75F8);
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded us-rev1 data; explicit withholding in other holders. */
const unsigned int D_blob_e509e1b562191b6803a2[2] = {
    0x3F100000, 0x00000000,
};
#endif
