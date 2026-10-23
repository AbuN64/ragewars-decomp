#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
const unsigned int D_80292900_CB15C[2] = {
    0x358637BD, 0x41700000,
};
#endif

#if defined(VERSION_DE)
const unsigned int rodata_unresolved_800C5474[1] = {
    0x3F666666,
};
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded us-rev1 data; explicit withholding in other holders. */
const unsigned int D_blob_f8704a809bee673252d0[2] = {
    0x358637BD, 0x41700000,
};
#endif
