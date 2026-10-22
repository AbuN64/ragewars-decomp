#include "include_asm.h"

#if !(defined(VERSION_US) || defined(VERSION_US_REV1))
INCLUDE_DATA("data_800C", D_src_2527d91d);
#endif

#if defined(VERSION_US) || defined(VERSION_US_REV1)
/* ROM-grounded us-rev1 data; explicit withholding in other holders. */
extern char D_00435D14[];
extern char D_00435DE0[];
extern char D_00435E20[];
extern char D_00435E40[];
extern char D_00435E48[];
extern char D_00435E50[];
extern char D_00435E98[];
extern char D_00435EB8[];
unsigned int D_blob_e5d3a98b99e95fa6a111[27] = {
    0x00000E07, 0x00000001, (unsigned int)D_00435E20, 0x00000E08, 0x00000001, (unsigned int)D_00435E48, 0x00000E0A, 0x00000001,
    (unsigned int)D_00435E40, 0x00000E06, 0x00000001, (unsigned int)D_00435D14, 0x00000E03, 0x00000001, (unsigned int)D_00435DE0, 0x00000001,
    0x00000001, (unsigned int)D_00435EB8, 0x00000002, 0x00000001, (unsigned int)D_00435E98, 0x0000000A, 0x00000001, (unsigned int)D_00435E50,
    0x00000000, 0x00000000, 0x00000000,
};
#endif

#if defined(VERSION_US)
INCLUDE_DATA("data_800C", data_unresolved_800E0228);
#endif
