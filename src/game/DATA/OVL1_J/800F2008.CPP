#include "include_asm.h"

#if defined(VERSION_DE) || defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", rodata_unresolved_800E59E6);
#endif

#if !(defined(VERSION_DE) || defined(VERSION_EU_X))
/* ROM-grounded us-rev1 data; explicit withholding in other holders. */
unsigned short D_blob_e8ba979c74d51b52ece3[1] = {
    0x00D1,
};
#endif
