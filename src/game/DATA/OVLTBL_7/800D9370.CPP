#include "include_asm.h"

#if !(defined(VERSION_US) || defined(VERSION_US_REV1))
INCLUDE_DATA("data_800C", D_src_1a91a118);
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded us-rev1 data; explicit withholding in other holders. */
unsigned int D_blob_70e6e8ff7793301112e1[3] = {
    0x80151AC8, 0x80151BC8, 0x80152B80,
};
#endif
