#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
#if defined(VERSION_DE)
const float g_OvlgameInitializerenderdirectionWords1[1] = {
    -0.667424f,
};
#endif
#if defined(VERSION_EU) || defined(VERSION_EU_X) || defined(VERSION_US)
const float g_OvlgameInitializerenderdirectionWords1[3] = {
    -0.667424f, 0.953462f, -0.572078f,
};
#endif
#endif

#if defined(VERSION_EU_X)
/* Alignment fill to the next 16-byte object boundary. */
unsigned int k_OvlgameInitializerenderdirectionEncodedWordsBlock2AlignmentPad[1] = {
    0x4E2C2053,
};
#endif

#if defined(VERSION_EU)
/* Alignment fill to the next 16-byte object boundary. */
unsigned int k_OvlgameInitializerenderdirectionEncodedWordsBlock1AlignmentPad[1] = {
    0x080B02A1,
};
#endif

#if defined(VERSION_DE)
const float g_OvlgameInitializerenderdirectionWords3[2] = {
    0.953462f, -0.572078f,
};
#endif

#if defined(VERSION_DE)
/* Alignment fill to the next 16-byte object boundary. */
unsigned int k_OvlgameInitializerenderdirectionEncodedWordsAlignmentPad[1] = {
    0x3F333333,
};
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded us-rev1 data; explicit withholding in other holders. */
const float g_OvlgameInitializerenderdirectionWords2[3] = {
    -0.667424f, 0.953462f, -0.572078f,
};
#endif
