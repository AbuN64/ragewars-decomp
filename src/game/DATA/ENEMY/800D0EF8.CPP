#include "include_asm.h"

/* ROM-grounded data: rodata/shared/800D0EF8 */
/* Light colour bytes (r, g, b, pad): bytes so every host reads the same colour. */
const unsigned char D_blob_phase2_239070c3e8d24b970e5a[4] = {
    0x38, 0x38, 0x38, 0x00,
};

#if defined(VERSION_US)
INCLUDE_RODATA("data_800C", rodata_shared_800CBBBC);
#endif

#if defined(VERSION_EU_X)
INCLUDE_RODATA("data_800C", rodata_shared_800CD25C);
#endif

#if defined(VERSION_EU)
INCLUDE_RODATA("data_800C", rodata_shared_800CC88C);
#endif

#if defined(VERSION_DE)
INCLUDE_RODATA("data_800C", rodata_shared_800CBCAC);
#endif
