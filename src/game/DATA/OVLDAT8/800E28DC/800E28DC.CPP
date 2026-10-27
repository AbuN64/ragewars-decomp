#include "include_asm.h"

/* ROM-grounded us-rev1 data; explicit withholding in other holders. */
unsigned int D_blob_9f91dd6eba30639cb782[1] = {
    0xFFFFFFFF,
};

#if defined(VERSION_US)
unsigned int data_unresolved_800DD540[4] = {
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
};
#endif

#if defined(VERSION_EU_X)
unsigned int data_unresolved_800EA0C0[4] = {
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
};
#endif

#if defined(VERSION_EU)
unsigned int data_unresolved_800EEF00[4] = {
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
};
#endif

#if defined(VERSION_DE)
unsigned int data_unresolved_800DE890[4] = {
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
};
#endif
