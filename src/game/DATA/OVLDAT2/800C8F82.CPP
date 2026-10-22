#include "include_asm.h"

#if defined(VERSION_EU_X)
/* ROM-grounded data: rodata/unresolved/800C8F82 */
unsigned short D_blob_091c4ad28e966884f678[1] = {
    0x0000,
};
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", data_unresolved_800C8F84);
#endif

#if defined(VERSION_US_REV1)
INCLUDE_DATA("data_800C", rodata_unresolved_800C8F82);
#endif
