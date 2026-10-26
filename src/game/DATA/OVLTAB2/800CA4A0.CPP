#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
#if defined(VERSION_DE)
const unsigned int D_8044DC60_CB0A0[1] = {
    0xBF2ADC4D,
};
#endif
#if defined(VERSION_EU) || defined(VERSION_EU_X) || defined(VERSION_US)
const unsigned int D_8044DC60_CB0A0[3] = {
    0xBF2ADC4D, 0x3F741616, 0xBF1273B4,
};
#endif
#endif

#if defined(VERSION_EU_X)
unsigned int rodata_unresolved_800C56AC[1] = {
    0x4E2C2053,
};
#endif

#if defined(VERSION_EU)
unsigned int rodata_unresolved_800C566C[1] = {
    0x080B02A1,
};
#endif

#if defined(VERSION_DE)
const unsigned int rodata_func_8044DC60_de_800C53B4[2] = {
    0x3F741616, 0xBF1273B4,
};
#endif

#if defined(VERSION_DE)
unsigned int rodata_unresolved_800C53BC[1] = {
    0x3F333333,
};
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded us-rev1 data; explicit withholding in other holders. */
const unsigned int D_blob_b6a39bcb3e685d133582[3] = {
    0xBF2ADC4D, 0x3F741616, 0xBF1273B4,
};
#endif
