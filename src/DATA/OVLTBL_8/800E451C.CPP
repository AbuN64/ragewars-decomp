#include "include_asm.h"

#if !(defined(VERSION_US) || defined(VERSION_US_REV1))
INCLUDE_DATA("data_800C", D_src_4b23fe05);
#endif

#if defined(VERSION_US) || defined(VERSION_US_REV1)
/* ROM-grounded us-rev1 data; explicit withholding in other holders. */
extern char D_0042340C[];
unsigned int D_blob_ec5dd4e360119bdc0fe4[3] = {
    0x00000E08, 0x00000004, (unsigned int)D_0042340C,
};
#endif

#if defined(VERSION_US)
INCLUDE_DATA("data_800C", data_unresolved_800DF188);
#endif
