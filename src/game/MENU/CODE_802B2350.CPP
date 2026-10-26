#include "include_asm.h"

#if !(defined(VERSION_EU))
float func_802B2350(int floatHighBits) {
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
