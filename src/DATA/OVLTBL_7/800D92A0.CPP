#include "include_asm.h"

#if defined(VERSION_US) || defined(VERSION_US_REV1)
/* ROM-grounded us-rev1 data; explicit withholding in other holders. */
unsigned int D_blob_5a9d95bf8283eca200f7[2] = {
    0x00000000, 0x00000000,
};
#endif

#if defined(VERSION_US)
INCLUDE_DATA("data_800C", data_unresolved_800D3F28);
#endif
