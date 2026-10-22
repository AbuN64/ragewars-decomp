#include "include_asm.h"

#if !(defined(VERSION_US) || defined(VERSION_US_REV1))
INCLUDE_DATA("data_800C", D_src_55fe5453);
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded exact candidate, normalized from prior lane proof. */
extern char D_00293DE4[];
extern char D_00293E60[];
extern char D_00293E90[];
extern char D_00293EAC[];
extern char D_00293F38[];
extern char D_00293FE4[];
extern char D_00294120[];
extern char D_00294128[];
extern char D_0029414C[];
unsigned int D_blob_53acc8abeee6cf9b8269[9] = {
    (unsigned int)D_00293DE4, (unsigned int)D_00293E60, (unsigned int)D_00293E90, (unsigned int)D_00293EAC, (unsigned int)D_00293F38, (unsigned int)D_00293FE4, (unsigned int)D_00294120, (unsigned int)D_00294128,
    (unsigned int)D_0029414C,
};
#endif
