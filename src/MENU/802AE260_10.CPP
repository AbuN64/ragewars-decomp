#include "include_asm.h"
#include "sdk/OBJECTSTATE2.H"

unsigned short func_802AD270_de(float arg0) {
    return *(unsigned short *)&arg0;
}

#if defined(VERSION_EU)
#include "TYPES.H"

f32 func_802AD520_eu(u32 value) {
    u32 bits = value << 16;
    return *(f32 *)&bits;
}
INCLUDE_ASM("span_1000", func_802AD538);
#endif
