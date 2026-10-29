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
unsigned int g_floatConvertTextPadding[4] = {
    0x080AA151, 0x02602821, 0x03E00008, 0x00000000,
};
#endif

/* Menu_ExpandFloatHighWord_Floatconvert.CPP */
#if !(defined(VERSION_EU))
float Menu_ExpandFloatHighWord(int floatHighBits) {
    int tmp = floatHighBits << 16;
    return *(float *)&tmp;
}
#endif

#if defined(VERSION_US)
unsigned int g_floatConvertTextPadding[2] = {
    0x65520000, 0x5F000000,
};
#endif

#if defined(VERSION_EU_X)
unsigned int g_floatConvertTextPadding[2] = {
    0x00A0A821, 0xAFB70134,
};
#endif
