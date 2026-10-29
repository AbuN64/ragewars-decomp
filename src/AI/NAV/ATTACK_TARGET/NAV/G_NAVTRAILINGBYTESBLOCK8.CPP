#include "include_asm.h"

/* 8020EAE0_15.CPP */
#if defined(VERSION_EU_X) || defined(VERSION_US_REV1)
/* Data separated from executable functions by the legacy split layout. */
unsigned int func_802106FC_eu_x[1] = { 0x00101080U };
#endif

/* 802106E0_18.CPP */
#if defined(VERSION_EU)
unsigned char g_NavTrailingBytesBlock8[12] = { 0x24, 0x02, 0x00, 0x01, 0x46, 0x01, 0x00, 0x00, 0xC7, 0xA1, 0x00, 0x18 };
#endif

/* 8023A284_2.CPP */
#if defined(VERSION_US)
unsigned int k_NavEncodedWordsBlock7[1] = {
    0x43454649,
};
#endif
