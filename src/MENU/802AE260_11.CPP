#include "include_asm.h"

#if !(defined(VERSION_EU))
float func_802B2350(int arg0) {
    int tmp = arg0 << 16;
    return *(float *)&tmp;
}
#endif

#if defined(VERSION_US)
INCLUDE_DATA("span_1000", func_802AD1C8_us_padding_ADDC8);
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("span_1000", func_802AD578_eu_x_padding_AE178);
#endif
