#include "include_asm.h"
#include "COMMON/OBJRECAT3CV2.H"

#if !(defined(VERSION_US_REV1))
INCLUDE_RODATA("data_800C", D_80297A34_CB3B0);
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded us-rev1 data; explicit withholding in other holders. */
const unsigned int D_blob_a8b599cb23bc51b717e6[2] = {
    0x408F4000, 0x00000000,
};
#endif
