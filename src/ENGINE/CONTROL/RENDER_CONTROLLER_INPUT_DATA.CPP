#include "include_asm.h"

/* ROM-grounded data: src/k_RenderControllerInputOneWords_RenderControllerInput.c */
const float k_RenderControllerInputOneWords[1] = {
    1.0f,
};

#if defined(VERSION_US)
/* Alignment fill to the next 16-byte object boundary. */
unsigned int k_RenderControllerInputEncodedWordsAlignmentPad[1] = {
    0x5F486569,
};
#endif

#if defined(VERSION_EU_X)
/* Alignment fill to the next 16-byte object boundary. */
unsigned int k_RenderControllerInputEncodedWordsBlock2AlignmentPad[1] = {
    0x0044EDC0,
};
#endif

#if defined(VERSION_EU)
/* Alignment fill to the next 16-byte object boundary. */
unsigned int k_RenderControllerInputEncodedWordsBlock1AlignmentPad[1] = {
    0x8FAA0028,
};
#endif

#if defined(VERSION_DE)
/* Alignment fill to the next 16-byte object boundary. */
unsigned int k_RenderControllerInputSixteenWordsAlignmentPad[1] = {
    0x41800000,
};
#endif
