#include "include_asm.h"

#if !(defined(VERSION_US) || defined(VERSION_US_REV1))
INCLUDE_DATA("data_800C", D_src_638b7747);
#endif

#if defined(VERSION_US) || defined(VERSION_US_REV1)
/* ROM-grounded us-rev1 data; explicit withholding in other holders. */
extern char D_00436D48[];
extern char D_00436D50[];
unsigned int D_blob_b50c0451f06e41fd3ba0[6] = {
    0x00000E07, 0x00000005, (unsigned int)D_00436D48, 0x00000E08, 0x00000005, (unsigned int)D_00436D50,
};
#endif

#if defined(VERSION_US)
INCLUDE_DATA("data_800C", data_unresolved_800E0310);
#endif
