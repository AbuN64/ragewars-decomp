#include "include_asm.h"

#if !(defined(VERSION_US) || defined(VERSION_US_REV1))
INCLUDE_DATA("data_800C", D_src_95297a43);
#endif

#if defined(VERSION_US) || defined(VERSION_US_REV1)
/* ROM-grounded exact candidate, normalized from prior lane proof. */
extern char D_0042F988[];
extern char D_0042FAFC[];
extern char D_00435BA4[];
unsigned int D_blob_8e1913286f812ae02607[9] = {
    0x00000E07, 0x00000013, (unsigned int)D_00435BA4, 0x00000E0A, 0x00000013, (unsigned int)D_0042F988, 0x00000E08, 0x00000013,
    (unsigned int)D_0042FAFC,
};
#endif

#if defined(VERSION_US)
INCLUDE_DATA("data_800C", data_unresolved_800E012C);
#endif
