#include "include_asm.h"

/* DATA_800E2850.CPP */
/* ROM-grounded data: rodata/writable/800E2850 */
unsigned int D_blob_phase2_68c1c663cddeafbcff6d[3] = {
    0x00000000, 0x00000000, 0x00000000,
};

/* DATA_800E285C.CPP */
unsigned short g_controllerPakFilenameAlphabet[] = {
    0x007E, 0x7E7E, 0x7E7E, 0x7E7E, 0x7E7E, 0x7E7E, 0x7E7E, 0x7E20, 0x3031, 0x3233, 0x3435, 0x3637,
    0x3839, 0x4142, 0x4344, 0x4546, 0x4748, 0x494A, 0x4B4C, 0x4D4E, 0x4F50, 0x5152, 0x5354, 0x5556,
    0x5758, 0x595A, 0x2122, 0x2327, 0x2A2B, 0x2C2D, 0x2E2F, 0x3A3D, 0x3F40,
#if defined(VERSION_DE)
    0x006D,
#endif
#if defined(VERSION_EU)
    0x0020,
#endif
#if defined(VERSION_EU_X) || defined(VERSION_US_REV1)
    0x0012,
#endif
#if defined(VERSION_US)
    0x005F,
#endif
};

#if defined(VERSION_US)
/* bytes live in the preceding array */
#endif

#if defined(VERSION_EU_X)
/* bytes live in the preceding array */
#endif

#if defined(VERSION_EU)
/* bytes live in the preceding array */
#endif

#if defined(VERSION_DE)
/* bytes live in the preceding array */
#endif

#if defined(VERSION_US_REV1)
/* bytes live in the preceding array */
#endif

/* 800E28A0.CPP */
/* ROM-grounded data: rodata/writable/800E28A0 */
unsigned int D_blob_phase2_5a247187d2e6747d8707[1] = {
    0x00000002,
};

#if defined(VERSION_EU_X) || defined(VERSION_US_REV1)
/* ROM-grounded us-rev1 data; explicit withholding in other holders. */
unsigned int D_blob_f32799a6cdf43a0d380f[3] = {
    0x00002C00, 0x00000200, 0x00000001,
};
#endif

#if defined(VERSION_EU)
unsigned int rodata_unresolved_800EEEC4[3] = {
    0x00002C00, 0x00000200, 0x002BB820,
};
#endif

/* 800E28A4.CPP */
#if defined(VERSION_DE) || defined(VERSION_US)
unsigned int rodata_unresolved_800E28A4[3] = {
    0x00002C00, 0x00000200, 0x00000000,
};
#endif

/* 800E28A4_2.CPP */
unsigned int D_auto_rodata_writable_800E28B0[8] = {
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x00000000,
};

#if defined(VERSION_DE) || defined(VERSION_EU) || defined(VERSION_EU_X) || defined(VERSION_US)
unsigned int data_unresolved_800DD530[3] = {
    0x00000140, 0x000000F0, 0xFFFFFFFF,
};
#endif

#if !(defined(VERSION_US_REV1))
/* bytes live in the preceding array */
#endif
