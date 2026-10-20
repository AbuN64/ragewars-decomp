#include "include_asm.h"

#if !(defined(VERSION_US) || defined(VERSION_US_REV1))
INCLUDE_DATA("data_800C", D_src_6bb6ec48);
#endif

#if defined(VERSION_US) || defined(VERSION_US_REV1)
/* ROM-grounded us-rev1 data; explicit withholding in other holders. */
extern char D_0042439C[];
unsigned int D_blob_867707feeb8d8b03c71b[3] = {
    0x00000E08, 0x00000003, (unsigned int)D_0042439C,
};
#endif

#if defined(VERSION_US)
INCLUDE_DATA("data_800C", data_unresolved_800DF270);
#endif
