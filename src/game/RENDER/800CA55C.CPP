#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
INCLUDE_RODATA("data_800C", D_80292900_CB15C);
#endif

#if defined(VERSION_DE)
INCLUDE_RODATA("data_800C", rodata_unresolved_800C5474);
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded us-rev1 data; explicit withholding in other holders. */
const unsigned int D_blob_f8704a809bee673252d0[2] = {
    0x358637BD, 0x41700000,
};
#endif
