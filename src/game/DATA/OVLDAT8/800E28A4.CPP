#include "include_asm.h"

#if defined(VERSION_DE) || defined(VERSION_US)
unsigned int rodata_unresolved_800E28A4[3] = {
    0x00002C00, 0x00000200, 0x00000000,
};
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded us-rev1 data; explicit withholding in other holders. */
unsigned int D_blob_f32799a6cdf43a0d380f[3] = {
    0x00002C00, 0x00000200, 0x00000001,
};
#endif
