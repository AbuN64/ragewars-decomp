#include "include_asm.h"

/* ROM-grounded data: rodata/shared/800D0EF8 */
/* Light colour bytes (r, g, b, pad): bytes so every host reads the same colour. */
const unsigned char D_blob_phase2_239070c3e8d24b970e5a[4] = {
    0x38, 0x38, 0x38, 0x00,
};

#if defined(VERSION_US)
const unsigned int rodata_shared_800CBBBC[1] = {
    0x38383800,
};
#endif

#if defined(VERSION_EU_X)
const unsigned int rodata_shared_800CD25C[1] = {
    0x38383800,
};
#endif

#if defined(VERSION_EU)
const unsigned int rodata_shared_800CC88C[1] = {
    0x38383800,
};
#endif

#if defined(VERSION_DE)
const unsigned int rodata_shared_800CBCAC[1] = {
    0x38383800,
};
#endif
