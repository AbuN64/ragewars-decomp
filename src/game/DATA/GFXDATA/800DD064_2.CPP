#include "include_asm.h"
#if defined(VERSION_DE)
const unsigned int D_auto_rodata_func_8040BB40_de_800DD07C[1] = {
    0x0040DBA0,
};
#endif

#if !(defined(VERSION_EU) || defined(VERSION_US))
/* ROM-grounded data: rodata/func_8040DB04_de/800E10B0 */
#ifdef VERSION_DE
const unsigned int D_blob_phase2_909a18e76a085edf187f[8] = {
    0x0040DEE0, 0x0040DD8C, 0x0040DB4C, 0x0040DBA0, 0x0040E02C, 0x0040DBF4, 0x0040E02C, 0x0040DC48,
};
#endif
#ifdef VERSION_EU_X
const unsigned int D_blob_phase2_909a18e76a085edf187f[8] = {
    0x0040E320, 0x0040E1CC, 0x0040DF8C, 0x0040DFE0, 0x0040E46C, 0x0040E034, 0x0040E46C, 0x0040E088,
};
#endif
#ifdef VERSION_US_REV1
const unsigned int D_blob_phase2_909a18e76a085edf187f[8] = {
    0x0040DF60, 0x0040DE0C, 0x0040DBCC, 0x0040DC20, 0x0040E0AC, 0x0040DC74, 0x0040E0AC, 0x0040DCC8,
};
#endif
#endif

#if defined(VERSION_EU_X)
const unsigned int rodata_func_8040E0D4_de_800E88E0[4] = {
    0x3F800000, 0x3F000000, 0x3F800000, 0x3F800000,
};
#endif

#if defined(VERSION_DE)
const unsigned int rodata_func_8040E0D4_de_800DD0A0[4] = {
    0x3F800000, 0x3F000000, 0x3F800000, 0x3F800000,
};
#endif
