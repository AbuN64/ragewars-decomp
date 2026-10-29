#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
#if defined(VERSION_DE)
unsigned short D_src_af61b546[8] = {
    0x8014, 0x86C0, 0x8014, 0x8740, 0x3F40, 0x0000, 0x3F00, 0x0000,
};
#endif
#if defined(VERSION_EU)
unsigned short D_src_af61b546[8] = {
    0x8015, 0x86C0, 0x8015, 0x8740, 0x6869, 0x7665, 0x206F, 0x6620,
};
#endif
#if defined(VERSION_EU_X)
unsigned short D_src_af61b546[8] = {
    0x8015, 0x26C0, 0x8015, 0x2740, 0x0200, 0x0400, 0x0800, 0x1000,
};
#endif
#if defined(VERSION_US)
unsigned short D_src_af61b546[8] = {
    0x8014, 0x66C0, 0x8014, 0x6740, 0x0004, 0x0000, 0x001C, 0x5346,
};
#endif
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded us-rev1 data; explicit withholding in other holders. */
unsigned int g_gamecoreWriteperipheralhandlewordDataAddressWords[2] = {
    0x8014E950, 0x8014E9D0,
};
#endif
