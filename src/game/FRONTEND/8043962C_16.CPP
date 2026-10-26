#include "COMMON/OWNERRECAT8V1.H"
#include "COMMON/OBJECTRECAT28.H"
#include "TYPES.H"
#include "include_asm.h"

#if defined(VERSION_US_REV1)
s32 func_80439F10_us_rev1(void) {
    func_8041B110_de(0x3DA);
    func_8041B110_de(0x3DB);
    return 0;
}
#endif

#if defined(VERSION_US)
extern void func_8041B110_de(int id);

int func_80439F10_us(void) { func_8041B110_de(0x3DA); func_8041B110_de(0x3DB); return 0; }
#endif

#if defined(VERSION_EU)
extern void func_8041B110_de(int);

int func_8043AC00_eu(void) {
    func_8041B110_de(0x3da);
    func_8041B110_de(0x3db);
    return 0;
}
#endif

#if defined(VERSION_DE) || defined(VERSION_EU_X)
extern void func_8041B110_de(int);

int func_80439D30_de(void) {
    func_8041B110_de(0x3d4);
    func_8041B110_de(0x3d5);
    return 0;
}
#endif
