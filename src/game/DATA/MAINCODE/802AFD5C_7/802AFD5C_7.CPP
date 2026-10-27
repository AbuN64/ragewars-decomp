#include "COMMON/ALPARAM_S.H"
#include "TYPES.H"
#include "abi.h"
#include "acmd.h"
#include "COMMON/AUDIO_CALLBACKS.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/UNUSED.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#include "COMMON/ALAUXBUS_S.H"
#include "include_asm.h"

/* 802AFD5C_7.CPP */
#if defined(VERSION_EU)
unsigned char D_auto_func_802B5674_eu_padding_B6274[12] = { 0xAF, 0xB0, 0x00, 0x18, 0x00, 0x80, 0x80, 0x21, 0xAF, 0xB1, 0x00, 0x1C };
#endif

/* DATA_80212FD4.CPP */
#if defined(VERSION_US)
char func_80212FBC_de_padding_13BD4[12] =
    "\000\000\000\000\000\027SFX_CE";
#endif

#if defined(VERSION_US_REV1)
unsigned int D_d0_e2ba8104dc56df8a[3] = {
    0xA2220035, 0x822300CA, 0x10650004,
};
#endif
