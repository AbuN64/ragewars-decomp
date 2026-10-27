#include "include_asm.h"

/* 800D0640.CPP */
#if !(defined(VERSION_US_REV1))
const unsigned int D_8023D380_D1240[1] = {
    0x3CA3D70A,
};
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_8023D380_D1240_us_rev1.c */
const unsigned int D_blob_97cb2aed4b8556f7c974[1] = {
    0x3CA3D70A,
};
#endif

/* 800D0644.CPP */
/* ROM-grounded data: rodata/shared/800D0644 */
const unsigned int D_blob_phase2_5fbb4429271f7e1a124f[1] = {
    0x3CA3D70A,
};

/* 800CB398.CPP */
#if defined(VERSION_DE)
unsigned int D_auto_rodata_unresolved_800CB398[4] = {
    0x807FFFFF, 0x00000003, 0x7FFFFFFF, 0x00000000,
};

unsigned int D_auto_rodata_writable_800CB3A8[22] = {
    0x807FFFFF, 0x00000003, 0x9FFFFFFF, 0x00000000, 0xA07FFFFF, 0x00000003, 0xA3FFFFFF, 0x00000000,
    0xA4001FFF, 0x0000000B, 0xA5FFFFFF, 0x00000000, 0xA63FFFFF, 0x00000007, 0xAFFFFFFF, 0x00000000,
    0xB1FDFFFF, 0x00000007, 0xFFFFFFFF, 0x00000000, 0xFFFFF7FA, 0x92060009,
};
#endif
