#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
INCLUDE_RODATA("data_800C", D_src_3e6e0646);
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded us-rev1 data; explicit withholding in other holders. */
unsigned int D_blob_9d129132f0eff55f707d[9] = {
    0x3C757365, 0x20746869, 0x7320746F, 0x20666164, 0x65206F75, 0x74206369, 0x6E656D61, 0x20746578,
    0x743E0000,
};
#endif
