#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
const unsigned int D_804491E8_C7FF0[2] = {
    0x43DAC000, 0xC428C000,
};
#endif

#if defined(VERSION_US)
const unsigned int rodata_unresolved_800C2238[4] = {
    0x3E800000, 0x3E400000, 0x3FC90FDC, 0x437F0000,
};
#endif

#if defined(VERSION_EU_X)
const unsigned int rodata_unresolved_800C25E8[4] = {
    0x3E800000, 0x3E400000, 0x3FC90FDC, 0x437F0000,
};
#endif

#if defined(VERSION_EU)
const unsigned int rodata_unresolved_800C25A8[4] = {
    0x3E800000, 0x3E400000, 0x3FC90FDC, 0x437F0000,
};
#endif

#if defined(VERSION_DE)
const unsigned int rodata_unresolved_800C2308[4] = {
    0x3E800000, 0x3E400000, 0x3FC90FDC, 0x437F0000,
};
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded us-rev1 data; explicit withholding in other holders. */
const unsigned int D_blob_28d41ed09454f07e35e4[2] = {
    0x43DAC000, 0xC428C000,
};
#endif
