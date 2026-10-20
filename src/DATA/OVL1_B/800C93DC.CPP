#include "include_asm.h"

#if defined(VERSION_EU)
INCLUDE_DATA("data_800C", rodata_unresolved_800C93DC);
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded us-rev1 data; explicit withholding in other holders. */
unsigned int D_blob_0258f5d8fd3d518f9a07[1] = {
    0x7F7FFFFF,
};
#endif
