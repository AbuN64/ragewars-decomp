#include "include_asm.h"

#if !(defined(VERSION_US) || defined(VERSION_US_REV1))
INCLUDE_DATA("data_800C", D_src_d9561b8a);
#endif

#if defined(VERSION_US) || defined(VERSION_US_REV1)
/* ROM-grounded us-rev1 data; explicit withholding in other holders. */
extern char D_00422260[];
extern char D_004222A8[];
extern char D_004222D8[];
extern char D_00422370[];
extern char D_004223FC[];
extern char D_00422444[];
extern char D_0042245C[];
unsigned int D_blob_1344574394ee8bcac553[24] = {
    0x00000E06, 0x00000019, (unsigned int)D_00422260, 0x00000E03, 0x00000019, (unsigned int)D_004222A8, 0x00000002, 0x00000019,
    (unsigned int)D_0042245C, 0x00000001, 0x00000019, (unsigned int)D_00422444, 0x00000E0A, 0x00000019, (unsigned int)D_004222D8, 0x00000E08,
    0x00000019, (unsigned int)D_00422370, 0x0000000A, 0x00000019, (unsigned int)D_004223FC, 0x00000000, 0x00000000, 0x00000000,
};
#endif

#if defined(VERSION_US)
INCLUDE_DATA("data_800C", data_unresolved_800DF164);
#endif
