#include "include_asm.h"

#if !(defined(VERSION_US) || defined(VERSION_US_REV1))
INCLUDE_DATA("data_800C", D_src_3cb405cb);
#endif

#if defined(VERSION_US) || defined(VERSION_US_REV1)
/* ROM-grounded exact candidate, normalized from prior lane proof. */
extern char D_004391F0[];
extern char D_004391F8[];
unsigned int D_blob_db924ce98cb273cd46e4[6] = {
    0x00000E07, 0x00000006, (unsigned int)D_004391F0, 0x00000E08, 0x00000006, (unsigned int)D_004391F8,
};
#endif

#if defined(VERSION_US)
INCLUDE_DATA("data_800C", data_unresolved_800E0520);
#endif
