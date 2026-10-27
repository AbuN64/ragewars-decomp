#include "include_asm.h"

/* 802BE040_19.CPP */
#if defined(VERSION_EU)
unsigned char D_auto_func_802B9BE4_eu_padding_BA7E4[12] = { 0x27, 0xA5, 0x00, 0x18, 0x27, 0xA6, 0x00, 0x1A, 0x8F, 0xA8, 0x00, 0x54 };
#endif

/* 802C0390_18.CPP */
#if defined(VERSION_EU_X) || defined(VERSION_US_REV1)
/* Data separated from executable functions by the legacy split layout. */
unsigned int func_802BB6A8_eu_x[1] = { 0x445BF800U };
#endif

#if defined(VERSION_EU_X)
unsigned int func_802BB6A8_eu_x_padding_BC2AC[1] = {
    0x00000000,
};
#endif

/* DATA_802C04BC.CPP */
#if defined(VERSION_US_REV1)
/* ROM-grounded data: func_802BB6A8_eu_x_padding_C10BC */
unsigned int D_blob_phase2_26cb097518dd7297e264[1] = {
    0x00000000,
};
#endif
