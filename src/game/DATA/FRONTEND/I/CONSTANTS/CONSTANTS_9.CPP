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
unsigned char rodata_unresolved_800DE6CF[13] = {
    0x00, 0x43, 0x48, 0x00, 0x00, 0x43, 0x20, 0x00, 0x00, 0x43, 0x48, 0x00, 0x00,
};
#endif

#if defined(VERSION_US)
/* bytes live in the preceding array */
#endif

#if defined(VERSION_EU_X)
unsigned char rodata_unresolved_800EB24F[13] = {
    0x00, 0x43, 0x48, 0x00, 0x00, 0x43, 0x20, 0x00, 0x00, 0x43, 0x48, 0x00, 0x00,
};
#endif

#if defined(VERSION_EU_X)
/* bytes live in the preceding array */
#endif

#if defined(VERSION_EU)
unsigned char rodata_unresolved_800F008F[13] = {
    0x00, 0x43, 0x48, 0x00, 0x00, 0x43, 0x20, 0x00, 0x00, 0x43, 0x48, 0x00, 0x00,
};
#endif

#if defined(VERSION_EU)
/* bytes live in the preceding array */
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded us-rev1 data; explicit withholding in other holders. */
const unsigned int D_blob_c6fbe4d6b30f870ced2b[1] = {
    0x43200000,
};
#endif
