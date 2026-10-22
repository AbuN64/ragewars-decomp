#include "include_asm.h"

/* ROM-grounded us-rev1 data; explicit withholding in other holders. */
unsigned int D_blob_9d5d011354eb91de81f2[1] = {
    0x00000000,
};

#if defined(VERSION_US)
INCLUDE_DATA("data_800C", data_unresolved_800D3044);
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", data_unresolved_800DFBD4);
#endif

#if defined(VERSION_EU)
INCLUDE_DATA("data_800C", data_unresolved_800E4A14);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("data_800C", data_unresolved_800D4394);
#endif
