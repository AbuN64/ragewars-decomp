#include "include_asm.h"
#include "COMMON/EXTERNS_2.H"

const char s_audioSynthesizerText[20] = "audio/synthesizer.c";

/* ROM-grounded data: src/rw_pool_802B3CD0_CD3D8_us_rev1.c */
const unsigned int D_blob_ba6b872948b26bb298a2[2] = {
    0x358637BD, 0x3F000000,
};

/* ROM-grounded data: src/rw_pool_802B3DB8_CD3E0_us_rev1.c */
const unsigned int D_blob_1a249f1d90e237f6ffb5[2] = {
    0x358637BD, 0x3F000000,
};

#if defined(VERSION_US)
unsigned int rodata_unresolved_800C74B8[2] = {
    0x08000600, 0x00000000,
};
#endif

#if defined(VERSION_EU_X)
unsigned int rodata_unresolved_800C8B58[2] = {
    0x00000000, 0x000052DA,
};
#endif

#if defined(VERSION_EU)
unsigned int rodata_unresolved_800C8188[2] = {
    0x00230180, 0x002300D4,
};
#endif

#if defined(VERSION_DE)
unsigned int rodata_unresolved_800C7598[2] = {
    0x002B3FBC, 0x002B3FCC,
};
#endif
