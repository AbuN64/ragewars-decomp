#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
#if defined(VERSION_DE)
const unsigned int D_src_1fb9cba3[1] = {
    0x43200000,
};
#endif
#if defined(VERSION_EU) || defined(VERSION_EU_X) || defined(VERSION_US)
const unsigned char D_src_1fb9cba3[3] = {
    0x43, 0x20, 0x00,
};
#endif
#endif

#if defined(VERSION_US)
unsigned char k_CharacterPreviewDistanceFragmentsEncodedBytes[13] = {
    0x00, 0x43, 0x48, 0x00, 0x00, 0x43, 0x20, 0x00, 0x00, 0x43, 0x48, 0x00, 0x00,
};
#endif

#if defined(VERSION_US)
/* bytes live in the preceding array */
#endif

#if defined(VERSION_EU_X)
unsigned char k_CharacterPreviewDistanceFragmentsEncodedBytesBlock1[13] = {
    0x00, 0x43, 0x48, 0x00, 0x00, 0x43, 0x20, 0x00, 0x00, 0x43, 0x48, 0x00, 0x00,
};
#endif

#if defined(VERSION_EU_X)
/* bytes live in the preceding array */
#endif

#if defined(VERSION_EU)
unsigned char k_CharacterPreviewDistanceFragmentsEncodedBytesBlock2[13] = {
    0x00, 0x43, 0x48, 0x00, 0x00, 0x43, 0x20, 0x00, 0x00, 0x43, 0x48, 0x00, 0x00,
};
#endif

#if defined(VERSION_EU)
/* bytes live in the preceding array */
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded us-rev1 data; explicit withholding in other holders. */
const unsigned int g_characterPreviewDistanceUsRev1[1] = {
    0x43200000,
};
#endif
