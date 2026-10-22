#include "include_asm.h"

/* ROM-grounded us-rev1 data; explicit withholding in other holders. */
unsigned int D_blob_9f91dd6eba30639cb782[1] = {
    0xFFFFFFFF,
};

#if defined(VERSION_US)
INCLUDE_DATA("data_800C", data_unresolved_800DD540);
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", data_unresolved_800EA0C0);
#endif

#if defined(VERSION_EU)
INCLUDE_DATA("data_800C", data_unresolved_800EEF00);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("data_800C", data_unresolved_800DE890);
#endif
