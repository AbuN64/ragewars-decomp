#include "include_asm.h"

#if !(defined(VERSION_EU) || defined(VERSION_US))
/* ROM-grounded data: rodata/func_8043B854_de/800E2040 */
#ifdef VERSION_DE
const unsigned int D_blob_phase2_48acc91ddba73dc2d583[5] = {
    0x0043B8DC, 0x0043B8DC, 0x0043B8FC, 0x0043B8FC, 0x0043B8EC,
};
#endif
#ifdef VERSION_EU_X
const unsigned int D_blob_phase2_48acc91ddba73dc2d583[5] = {
    0x0043C8EC, 0x0043C8EC, 0x0043C90C, 0x0043C90C, 0x0043C8FC,
};
#endif
#ifdef VERSION_US_REV1
const unsigned int D_blob_phase2_48acc91ddba73dc2d583[5] = {
    0x0043BABC, 0x0043BABC, 0x0043BADC, 0x0043BADC, 0x0043BACC,
};
#endif
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", rodata_unresolved_800E9864);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("data_800C", rodata_unresolved_800DE024);
#endif
