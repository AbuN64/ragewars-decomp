#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
INCLUDE_RODATA("data_800C", D_src_1fb9cba3);
#endif

#if defined(VERSION_US)
INCLUDE_DATA("data_800C", rodata_unresolved_800DE6CF);
#endif

#if defined(VERSION_US)
INCLUDE_DATA("data_800C", data_unresolved_800DE6D0);
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", rodata_unresolved_800EB24F);
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", data_unresolved_800EB250);
#endif

#if defined(VERSION_EU)
INCLUDE_DATA("data_800C", rodata_unresolved_800F008F);
#endif

#if defined(VERSION_EU)
INCLUDE_DATA("data_800C", data_unresolved_800F0090);
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded us-rev1 data; explicit withholding in other holders. */
const unsigned int D_blob_c6fbe4d6b30f870ced2b[1] = {
    0x43200000,
};
#endif
