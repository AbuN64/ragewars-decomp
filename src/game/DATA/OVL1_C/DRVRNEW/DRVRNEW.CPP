#include "include_asm.h"
#include "COMMON/ALFXPARAM.H"

/* ROM-grounded us-rev1 data; explicit withholding in other holders. */
const unsigned int D_blob_e509e1b562191b6803a2[2] = {
    0x3F100000, 0x00000000,
};

#if defined(VERSION_DE) || defined(VERSION_EU) || defined(VERSION_US)
const unsigned int rodata_unresolved_800C7510[2] = {
    0x40D00000, 0x00000000,
};
#endif

#if defined(VERSION_US)
unsigned int rodata_unresolved_800C7518[2] = {
    0xC86D0200, 0x08000C00,
};
#endif

#if defined(VERSION_EU)
unsigned int rodata_unresolved_800C81E8[2] = {
    0x3F800000, 0x3FE52EDF,
};
#endif

#if defined(VERSION_DE)
char rodata_unresolved_800C75F8[8] =
    "o/env.c\000";
#endif
