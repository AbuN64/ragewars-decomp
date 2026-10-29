#include "include_asm.h"

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/ragewars_weapon_presentation_D100C_us_rev1.c */
struct {
    unsigned int w0;
    unsigned short h1[2];
} g_weaponPresentationDescriptor1Rev1 = { 0x800D7138, { 0x04D6, 0x0BC9 } };
#endif

#if defined(VERSION_US_REV1)
unsigned short D_src_5ef0e8ff[2] = {
    0x0000, 0xFFFF,
};
#endif
