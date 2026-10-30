#include "TYPES.H"


#if defined(VERSION_US_REV1)
unsigned int g_osaisetnextbufferDataConstantWords[8] = {
    0x00000010, 0x00000010, 0x00000020, 0x00000000, 0xC1200000, 0x00000000, 0x00000000, 0x00000000,
};

/* ROM-grounded data: src/ragewars_ai_boundary_flag_us_rev1.c */
#if defined(VERSION_US_REV1)
u8 g_osaisetnextbufferDataTextBytes = 0;
#endif
#endif
