#include "include_asm.h"

/* ROM-grounded us-rev1 data; explicit withholding in other holders. */
unsigned int D_blob_aef496b2319f23767239[2] = {
    0x00000003, 0x00000003,
};

#if defined(VERSION_US)
INCLUDE_DATA("data_800C", data_unresolved_800DD558);
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", data_unresolved_800EA0D8);
#endif

#if defined(VERSION_EU)
INCLUDE_DATA("data_800C", data_unresolved_800EEF18);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("data_800C", data_unresolved_800DE8A8);
#endif
