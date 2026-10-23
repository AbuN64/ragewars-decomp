#include "include_asm.h"
#include "COMMON/LIGHTDATA.H"
#include "TYPES.H"
#include "SYSTEM_3/80265370_3.H"

extern s32 D_800CBC80;
extern s32 D_8010C4A0;
void func_80265DD0_de(void) {
    D_8010C4A0 = D_800CBC80;
    if (D_800CBC80 == 0) {
        D_800CBC80 = 0x20;
        return;
    }
    D_800CBC80 = 0;
}

#if defined(VERSION_US)
unsigned int rodata_unresolved_80265DA8[2] = {
    0x63740000, 0x0000940A,
};
#endif
