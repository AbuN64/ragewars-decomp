#include "include_asm.h"

#if !(defined(VERSION_US) || defined(VERSION_US_REV1))
INCLUDE_DATA("data_800C", D_src_897c5b16);
#endif

#if defined(VERSION_US) || defined(VERSION_US_REV1)
/* ROM-grounded us-rev1 data; explicit withholding in other holders. */
extern char D_0041C32C[];
extern char D_0041C45C[];
extern char D_0041C48C[];
extern char D_0041C4EC[];
extern char D_0041C4F4[];
extern char D_0041C514[];
unsigned int D_blob_b47dbfd8aa76bb4c7e00[21] = {
    0x00000E08, 0x0000001D, (unsigned int)D_0041C48C, 0x00000E06, 0x0000001D, (unsigned int)D_0041C32C, 0x00000E03, 0x0000001D,
    (unsigned int)D_0041C45C, 0x00000001, 0x0000001D, (unsigned int)D_0041C514, 0x00000002, 0x0000001D, (unsigned int)D_0041C4F4, 0x0000000A,
    0x0000001D, (unsigned int)D_0041C4EC, 0x00000000, 0x00000000, 0x00000000,
};
#endif

#if defined(VERSION_US)
INCLUDE_DATA("data_800C", data_unresolved_800DE1D0);
#endif
