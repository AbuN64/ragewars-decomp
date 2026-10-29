#include "include_asm.h"

/* ROM-grounded data: src/rw_pool_8021EEFC_CFDB8_us_rev1.c */
const unsigned int k_overlayFiveLinkRecordFloatConstantWordsBlock2[1] = {
    0xC2EC0000,
};

#if defined(VERSION_DE) || defined(VERSION_EU) || defined(VERSION_EU_X) || defined(VERSION_US)
unsigned int k_OverlayFiveLinkRecordFloatConstantWordsC9F74EncodedWords[3] = {
    0x42940000, 0x42940000, 0xC2EC0000,
};
#endif
