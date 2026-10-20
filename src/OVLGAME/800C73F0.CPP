#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
INCLUDE_RODATA("data_800C", D_804491E8_C7FF0);
#endif

#if defined(VERSION_US)
INCLUDE_RODATA("data_800C", rodata_unresolved_800C2238);
#endif

#if defined(VERSION_EU_X)
INCLUDE_RODATA("data_800C", rodata_unresolved_800C25E8);
#endif

#if defined(VERSION_EU)
INCLUDE_RODATA("data_800C", rodata_unresolved_800C25A8);
#endif

#if defined(VERSION_DE)
INCLUDE_RODATA("data_800C", rodata_unresolved_800C2308);
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded us-rev1 data; explicit withholding in other holders. */
const unsigned int D_blob_28d41ed09454f07e35e4[2] = {
    0x43DAC000, 0xC428C000,
};
#endif
