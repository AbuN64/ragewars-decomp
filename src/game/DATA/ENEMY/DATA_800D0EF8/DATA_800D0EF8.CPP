#include "include_asm.h"

/* ROM-grounded data: rodata/shared/800D0EF8 */
/* Light colour bytes (r, g, b, pad): bytes so every host reads the same colour. */
const unsigned char D_blob_phase2_239070c3e8d24b970e5a[4] = {
    0x38, 0x38, 0x38, 0x00,
};

#if defined(VERSION_DE) || defined(VERSION_EU) || defined(VERSION_EU_X) || defined(VERSION_US)
const unsigned int rodata_shared_800CBBBC[1] = {
    0x38383800,
};
#endif
