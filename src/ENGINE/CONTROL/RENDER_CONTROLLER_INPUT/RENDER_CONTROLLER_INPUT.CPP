#include "include_asm.h"

/* ROM-grounded data: src/k_RenderControllerInputOneWords_RenderControllerInput.c */
const unsigned int k_RenderControllerInputOneWords[1] = {
    0x3F800000,
};

#if defined(VERSION_US)
unsigned int k_RenderControllerInputEncodedWords[1] = {
    0x5F486569,
};
#endif

#if defined(VERSION_EU_X)
unsigned int k_RenderControllerInputEncodedWordsBlock2[1] = {
    0x0044EDC0,
};
#endif

#if defined(VERSION_EU)
unsigned int k_RenderControllerInputEncodedWordsBlock1[1] = {
    0x8FAA0028,
};
#endif

#if defined(VERSION_DE)
unsigned int k_RenderControllerInputSixteenWords[1] = {
    0x41800000,
};
#endif
