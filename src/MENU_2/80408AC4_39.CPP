#include "include_asm.h"

#if defined(VERSION_DE) || defined(VERSION_EU_X)
extern void func_8041B110_de(int);

int func_80439D30_de(void) {
    func_8041B110_de(0x3d4);
    func_8041B110_de(0x3d5);
    return 0;
}
#endif
