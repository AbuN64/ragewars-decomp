#include "include_asm.h"
#include "sdk/PERIPHERAL_PORT_BYTE_VIEWS.H"

/* Menu_GetFloatHighWord_Floatconvert.CPP */
unsigned short Menu_GetFloatHighWord(float value) {
#if defined(__BYTE_ORDER__) && __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
    /* A little-endian host keeps the high half (sign, exponent, top mantissa bits) at the second halfword. */
    return ((unsigned short *)&value)[1];
#else
    return *(unsigned short *)&value;
#endif
}

#if defined(VERSION_EU)
#include "TYPES.H"

f32 Menu_ExpandFloatHighWord(u32 value) {
    u32 bits = value << 16;
    return *(f32 *)&bits;
}
#ifdef NON_MATCHING
/* Split artefact: the tail of the routine at 0x802A8544's neighbour; hands $s3 to $a1 and jumps into that routine, the
   rest is a bare return. Carried as the original instructions. */
void Menu_FloatConversionSplitTailEuropean(void) {
    __asm__ volatile (
        ".set noreorder\n"
        ".set noat\n"
        "j          0x802A8544\n"
        "addu       $5, $19, $0\n"
        "jr         $31\n"
        "nop\n"
        ".set reorder\n"
    );
}
#else
INCLUDE_ASM("span_1000", Menu_FloatConversionSplitTailEuropean);
#endif
#endif

/* Menu_ExpandFloatHighWord_Floatconvert.CPP */
#if !(defined(VERSION_EU))
float Menu_ExpandFloatHighWord(int floatHighBits) {
    int tmp = floatHighBits << 16;
    return *(float *)&tmp;
}
#endif

#if defined(VERSION_US)
unsigned int func_802AD1C8_us_padding_ADDC8[2] = {
    0x65520000, 0x5F000000,
};
#endif

#if defined(VERSION_EU_X)
unsigned int func_802AD578_eu_x_padding_AE178[2] = {
    0x00A0A821, 0xAFB70134,
};
#endif
