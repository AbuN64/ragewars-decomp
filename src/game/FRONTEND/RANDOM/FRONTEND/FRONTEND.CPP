#include "include_asm.h"

/* DATA_800DC810.CPP */
#if defined(VERSION_US)
unsigned int D_auto_rodata_unresolved_800DC810[8] = {
    0x0042F404, 0x0042F41C, 0x0042F4C8, 0x0042F410, 0x0042F3F8, 0x0042F3E0, 0x0042F3EC, 0x0042F4F0,
};
#endif

/* 8042F12C.CPP */
#if defined(VERSION_EU_X) || defined(VERSION_US_REV1)
unsigned char D_auto_func_8042F12C_us_rev1_padding_19D12C[4] = { 0x00, 0x05, 0x10, 0xC0 };
#endif
#if defined(VERSION_DE)
unsigned char D_auto_func_8042EF4C_de_padding_194F4C[4] = { 0x00, 0x00, 0x30, 0x21 };
#endif
#if defined(VERSION_EU)
unsigned char D_auto_func_8042FBEC_eu_padding_1A5BEC[4] = { 0x24, 0xA5, 0xC5, 0x74 };
#endif
