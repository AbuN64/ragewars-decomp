#include "include_asm.h"

#if defined(VERSION_EU)
INCLUDE_DATA("data_800C", rodata_unresolved_800C80C4);
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded us-rev1 data; explicit withholding in other holders. */
unsigned int D_blob_ed822d79597d2a49ba68[1] = {
    0x00000000,
};
#endif
