#include "COMMON/INTEGERSTATE14_2.H"
#include "COMMON/UNUSED.H"
#include "stdarg.h"
#include "TYPES.H"
#include "MENU/GFX/80414480_3.H"

#if defined(VERSION_EU_X) || defined(VERSION_US_REV1)
extern u8 D_8014D0D0;

u8 *XStdio_FormatScratchBuffer(u8 *arg0, ...) {
    va_list args;
    va_start(args, arg0);
    D_800CD918 = func_80414CCC_de(&D_8014D0D0, arg0, args);
    va_end(args);
    return &D_8014D0D0;
}
#endif
