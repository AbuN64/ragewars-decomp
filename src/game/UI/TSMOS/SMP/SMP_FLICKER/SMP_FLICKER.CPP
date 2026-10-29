#include "include_asm.h"

/* 804196C0_27.CPP */
#if defined(VERSION_EU)
unsigned char g_SmpFlickerTrailingBytesBlock3[4] = { 0x52, 0x42, 0x00, 0x01 };
#endif

/* 804196C0_18.CPP */
#if defined(VERSION_US)
unsigned int func_8041A05C_de_padding_1880DC[1] = {
    0x75042E65,
};
#endif

#if defined(VERSION_US_REV1)
unsigned char g_SmpFlickerTrailingBytesBlock2[4] = { 0x27, 0xBD, 0xFF, 0xE8 };
#endif

/* 804196C0_9.CPP */
#if defined(VERSION_DE)
unsigned char g_SmpFlickerTrailingBytesBlock1[4] = { 0x00, 0x00, 0x18, 0x21 };
#endif

/* 804196C0_5.CPP */
#if defined(VERSION_EU_X)
unsigned char g_SmpFlickerTrailingBytes[4] = { 0x27, 0xBD, 0xFF, 0xE8 };
#endif
