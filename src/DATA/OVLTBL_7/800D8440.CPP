#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
INCLUDE_DATA("data_800C", D_src_c0f3ff2a);
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded us-rev1 data; explicit withholding in other holders. */
unsigned int D_blob_5b6ba380bd73098a91b8[2] = {
    0x800D83E0, 0x800D8410,
};
#endif
