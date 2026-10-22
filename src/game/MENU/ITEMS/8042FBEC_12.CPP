#include "include_asm.h"

#if defined(VERSION_EU)
extern void func_8041B110_de(int);

int func_8043AC00_eu(void) {
    func_8041B110_de(0x3da);
    func_8041B110_de(0x3db);
    return 0;
}
#endif
