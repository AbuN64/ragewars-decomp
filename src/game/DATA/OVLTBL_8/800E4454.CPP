#include "include_asm.h"

#if !(defined(VERSION_US) || defined(VERSION_US_REV1))
INCLUDE_DATA("data_800C", D_src_3fb7e4b3);
#endif

#if defined(VERSION_US) || defined(VERSION_US_REV1)
/* ROM-grounded us-rev1 data; explicit withholding in other holders. */
extern char D_00421B20[];
extern char D_00421BEC[];
extern char D_00421C1C[];
extern char D_00421D18[];
extern char D_00421DC4[];
unsigned int D_blob_5a30de177bdbcc6f9c51[18] = {
    0x00000E08, 0x0000001B, (unsigned int)D_00421C1C, 0x00000E06, 0x0000001B, (unsigned int)D_00421B20, 0x00000E03, 0x0000001B,
    (unsigned int)D_00421BEC, 0x00000002, 0x0000001B, (unsigned int)D_00421DC4, 0x00000001, 0x0000001B, (unsigned int)D_00421D18, 0x00000000,
    0x00000000, 0x00000000,
};
#endif

#if defined(VERSION_US)
INCLUDE_DATA("data_800C", data_unresolved_800DF0FC);
#endif
