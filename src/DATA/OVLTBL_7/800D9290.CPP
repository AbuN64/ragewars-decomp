#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
INCLUDE_DATA("data_800C", D_src_f0222606);
#endif

#if defined(VERSION_US)
INCLUDE_DATA("data_800C", rodata_writable_800D3F1C);
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded us-rev1 data; explicit withholding in other holders. */
unsigned int D_blob_d968cdf2700f9aaf66ad[4] = {
    0x00000000, 0xFFFFFFFF, 0x800D9290, 0x800D9290,
};
#endif
