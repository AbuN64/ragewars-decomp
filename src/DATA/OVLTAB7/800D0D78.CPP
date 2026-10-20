#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
INCLUDE_DATA("data_800C", rodata_unresolved_800D0D78);
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded exact candidate, normalized from prior lane proof. */
unsigned int D_blob_dac98c16e73164f072df[6] = {
    0x800D0D60, 0x800D0D70, 0x8010C060, 0x403F0000, 0x3F8BD1C1, 0x3F8BADA9,
};
#endif
