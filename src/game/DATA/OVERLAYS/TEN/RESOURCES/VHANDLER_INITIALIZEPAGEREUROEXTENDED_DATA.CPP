#include "include_asm.h"
#include "TYPES.H"

#if defined(VERSION_DE)
u32 data_writable_800FF1B0[30] = {
    0x3DD1A331, 0x0FE1150F, 0x3161E6A1, 0x6F6137EF, 0x2612912E, 0xA1F34005,
    0x0228B2E2, 0x13A1B410, 0xF0F15124, 0x0E2FA16C, 0x29CD8A02, 0x34ED5CB3,
    0xC2E2200F, 0x20EEE1A2, 0xB3BFE01D, 0x22FEE3EF, 0x10B12F30, 0xF01F0F5F,
    0x1106B110, 0x32317C11, 0x11331FB1, 0x312D3200, 0x060E4321, 0xB115B031,
    0x0223FE40, 0xFFB10D0D, 0x19E1FEFF, 0x2EE0C1F0, 0xB0FFF1FF, 0x0EFD1EB3,
};
#endif

#if defined(VERSION_DE)
unsigned int k_VhandlerInitializepagereuroextendedEncodedWords[2] = {
    0xB2E01EF1, 0xE1CDFFF3,
};
#endif

#if defined(VERSION_DE) || defined(VERSION_US)
#if defined(VERSION_DE)
unsigned int rodata_writable_800FF230[1] = {
    0xB1B31D31,
};
#endif
#if defined(VERSION_US)
unsigned int rodata_writable_800FF230[1] = {
    0x6A0402B3,
};
#endif
#endif

#if defined(VERSION_US)
/* bytes live in the preceding array */
#endif

#if defined(VERSION_US)
unsigned int data_unresolved_800FD234[1] = {
    0x010A5C6C,
};
#endif

#if defined(VERSION_DE)
/* bytes live in the preceding array */
#endif

#if defined(VERSION_DE)
unsigned int data_unresolved_800FF234[1] = {
    0xFFDEDA0B,
};
#endif

#if defined(VERSION_DE) || defined(VERSION_US)
#if defined(VERSION_DE)
unsigned int rodata_writable_800FF238[1] = {
    0x2EA1EC3D,
};
#endif
#if defined(VERSION_US)
unsigned int rodata_writable_800FF238[1] = {
    0x0402AB01,
};
#endif
#endif
