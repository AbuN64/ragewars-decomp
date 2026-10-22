#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
INCLUDE_DATA("data_800C", D_src_af61b546);
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded us-rev1 data; explicit withholding in other holders. */
unsigned int D_blob_112992f280dd57ee6601[2] = {
    0x8014E950, 0x8014E9D0,
};
#endif
