#include "COMMON/MENUSELECTIONMESSAGE.H"
#include "TYPES.H"

#if !(defined(VERSION_DE) || defined(VERSION_EU_X))
/* Calls func_8041B110_de with 0x3D0 and then 0x3D1, and returns zero. */
extern void func_8041B110_de(s32);

s32 func_80438618_eu(void) {
    func_8041B110_de(0x3D0);
    func_8041B110_de(0x3D1);
    return 0;
}
#endif
