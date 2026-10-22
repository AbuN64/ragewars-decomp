#include "include_asm.h"

/* ROM-grounded us-rev1 data; explicit withholding in other holders. */
unsigned int D_blob_06e2da2b617a617ebeb3[1] = {
    0x003FFF01,
};

#if defined(VERSION_US)
INCLUDE_DATA("data_800C", data_unresolved_800D3F0C);
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", data_unresolved_800E0A9C);
#endif

#if defined(VERSION_EU)
INCLUDE_DATA("data_800C", data_unresolved_800E58DC);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("data_800C", data_unresolved_800D525C);
#endif
