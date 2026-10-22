#include "include_asm.h"

#if defined(VERSION_US) || defined(VERSION_US_REV1)
/* ROM-grounded us-rev1 data; explicit withholding in other holders. */
unsigned int D_blob_871ddb7f200dd0a5f378[4] = {
    0x00000000, 0x00000000, 0xFFFFFFEC, 0xFFFFFFEC,
};
#endif

#if defined(VERSION_US)
INCLUDE_DATA("data_800C", data_unresolved_800DE71C);
#endif
