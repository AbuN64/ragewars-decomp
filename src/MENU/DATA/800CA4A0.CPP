#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
INCLUDE_RODATA("data_800C", D_8044DC60_CB0A0);
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", rodata_unresolved_800C56AC);
#endif

#if defined(VERSION_EU)
INCLUDE_DATA("data_800C", rodata_unresolved_800C566C);
#endif

#if defined(VERSION_DE)
INCLUDE_RODATA("data_800C", rodata_func_8044DC60_de_800C53B4);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("data_800C", rodata_unresolved_800C53BC);
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded us-rev1 data; explicit withholding in other holders. */
const unsigned int D_blob_b6a39bcb3e685d133582[3] = {
    0xBF2ADC4D, 0x3F741616, 0xBF1273B4,
};
#endif
