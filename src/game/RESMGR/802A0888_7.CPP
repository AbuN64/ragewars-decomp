#include "include_asm.h"
#include "COMMON/MESSAGESEMAPHORE.H"
#include "COMMON/INTEGERSTATE14_2.H"
#include "TYPES.H"
#include "MENU/GFX/80414480_3.H"

#if defined(VERSION_EU)
#ifdef NON_MATCHING
/* Drafted below with the DE twin. */
#else
INCLUDE_ASM("span_1000", func_802A0BE8_eu);
#endif
#endif

#if defined(VERSION_DE) || (defined(NON_MATCHING) && defined(VERSION_EU))
#include "stdarg.h"
extern int D_8014D0D0;
extern int D_800CD918;

#if defined(VERSION_EU)
int *func_802A0BE8_eu(int format, ...) {
#else
int *func_802A0AD0_de(int format, ...) {
#endif
    va_list args;
    va_start(args, format);
    D_800CD918 = func_80414CCC_de(&D_8014D0D0, format, (int)args);
    va_end(args);
    return &D_8014D0D0;
}
#endif

#if !(defined(VERSION_US))

extern s32 D_8014D0D0;

s32 func_802A0B20_de(s32 arg0, ...) {
    char *args;

    args = __builtin_next_arg(arg0);
    D_800CD918 = func_80414CCC_de(&D_8014D0D0, arg0, (s32) args);
    if (D_800CD91C != 0) {
        ((s32 (*)(s32 *)) D_800CD91C)(&D_8014D0D0);
    }
    return D_800CD918;
}

s32 func_802A0B8C_de(s32 arg0, s32 arg1, s32 arg2, ...) {
    char *args;

    args = __builtin_next_arg(arg2);
    D_800CD918 = func_80414CCC_de(&D_8014D0D0, arg2, (s32) args);
    ((s32 (*)(s32 *, s32, s32)) D_800CD920_de)(&D_8014D0D0, arg0, arg1);
    return D_800CD918;
}
#endif
