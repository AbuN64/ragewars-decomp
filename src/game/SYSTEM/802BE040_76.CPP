#include "include_asm.h"

#if !(defined(VERSION_US))
/* ROM-grounded data: rodata/func_802B92F0_eu_x/800CCB80 */
#ifdef VERSION_DE
const unsigned int D_blob_phase2_4abd2dc3cf6e7a8e8e8d[7] = {
    0x002B9354, 0x002B9274, 0x002B92A8, 0x002B9364, 0x002B9364, 0x002B92DC, 0x002B9318,
};
#endif
#ifdef VERSION_EU
const unsigned int D_blob_phase2_4abd2dc3cf6e7a8e8e8d[8] = {
    0x002B95F4, 0x002B9514, 0x002B9548, 0x002B9604, 0x002B9604, 0x002B957C, 0x002B95B8, 0x41800000,
};
#endif
#ifdef VERSION_EU_X
const unsigned int D_blob_phase2_4abd2dc3cf6e7a8e8e8d[7] = {
    0x002B9634, 0x002B9554, 0x002B9588, 0x002B9644, 0x002B9644, 0x002B95BC, 0x002B95F8,
};
#endif
#ifdef VERSION_US_REV1
const unsigned int D_blob_phase2_4abd2dc3cf6e7a8e8e8d[7] = {
    0x002BE444, 0x002BE364, 0x002BE398, 0x002BE454, 0x002BE454, 0x002BE3CC, 0x002BE408,
};
#endif
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", rodata_unresolved_800C8F0C);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("data_800C", rodata_unresolved_800C794C);
#endif
