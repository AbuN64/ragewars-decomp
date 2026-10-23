#include "include_asm.h"

/* ROM-grounded data: rodata/shared/800E1B60 */
const unsigned char D_blob_phase2_d8cba5f9791df715fbae[] = {
    0x25, 0x64, 0x00,
#if defined(VERSION_EU)
    0xD3,
#endif
#if defined(VERSION_US)
    0x00,
#endif
#if defined(VERSION_US_REV1)
    0x10,
#endif
};

#if defined(VERSION_EU_X)
unsigned char rodata_unresolved_800E9373[13] = {
    0x10, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x0F, 0x00,
};
#endif

#if defined(VERSION_EU_X)
/* bytes live in the preceding array */
#endif

#if defined(VERSION_DE)
unsigned char rodata_unresolved_800DDB33[13] = {
    0x7C, 0x00, 0x42, 0xE2, 0xC0, 0x00, 0x42, 0xE3, 0x1C, 0x00, 0x42, 0xE3, 0x74,
};
#endif

#if defined(VERSION_DE)
/* bytes live in the preceding array */
#endif
