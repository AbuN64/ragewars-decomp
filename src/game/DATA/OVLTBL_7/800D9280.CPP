#include "include_asm.h"

/* ROM-grounded data: src/ragewars_audio_interface_clock_us_rev1.c */
unsigned int D_blob_73f39d5b3aba05ce9b42[1] = {
    0x02E6D354,
};

#if defined(VERSION_US)
INCLUDE_DATA("data_800C", rodata_unresolved_800D3F04);
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", rodata_unresolved_800E0A94);
#endif

#if defined(VERSION_EU)
INCLUDE_DATA("data_800C", rodata_unresolved_800E58D4);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("data_800C", rodata_unresolved_800D5254);
#endif
