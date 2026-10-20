#include "include_asm.h"
#include "TYPES.H"

f32 func_802B72B0_de(f32 value) {
    return __builtin_sqrtf(value);
}

#if defined(VERSION_EU)
#ifdef NON_MATCHING
int func_802B755C_eu(int arg0, int *arg1) {
    return *arg1;
}
#else
INCLUDE_ASM("span_1000", func_802B755C_eu);
#endif
#endif
