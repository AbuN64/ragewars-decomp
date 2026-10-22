#include "include_asm.h"

#if defined(VERSION_DE)
INCLUDE_DATA("data_800C", rodata_unresolved_800DCC3C);
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded us-rev1 data; explicit withholding in other holders. */
unsigned int D_blob_3f2bd19df87b0b9c1c27[1] = {
    0x200C1000,
};
#endif
