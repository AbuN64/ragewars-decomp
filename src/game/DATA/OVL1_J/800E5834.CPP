#include "include_asm.h"

#if !(defined(VERSION_US) || defined(VERSION_US_REV1))
INCLUDE_DATA("data_800C", D_src_e3e7c440);
#endif

#if defined(VERSION_US) || defined(VERSION_US_REV1)
/* ROM-grounded exact candidate, normalized from prior lane proof. */
extern char D_00438CB4[];
extern char D_00438E64[];
unsigned int D_blob_26675c10b25a02170679[6] = {
    0x00000E08, 0x00000012, (unsigned int)D_00438E64, 0x00000E07, 0x00000012, (unsigned int)D_00438CB4,
};
#endif

#if defined(VERSION_US)
INCLUDE_DATA("data_800C", data_unresolved_800E04AC);
#endif
