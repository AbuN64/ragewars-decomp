#include "include_asm.h"
#include "COMMON/RESIDENTSTATE.H"
#include "TYPES.H"
#include "TEXTURE/80294C64.H"

struct Context;
s32 func_8022A880_de(struct Context *);
s32 func_80285D30_de(s32 *);
extern s32 D_8010EC90;
extern char D_80145040;
void func_80294C50_de(void) {
    func_80285D30_de(&D_8010EC90);
    func_8022A880_de(&D_80145040);
}

#if defined(VERSION_EU_X)
unsigned int func_80294C8C_de_padding_959D8[2] = {
    0x10400005, 0x24020002,
};
#endif

#if defined(VERSION_EU) || defined(VERSION_US)
#if defined(VERSION_EU)
unsigned int func_80294C8C_de_padding_959A8[2] = {
    0x24846248, 0x3C01800D,
};
#endif
#if defined(VERSION_US)
unsigned int func_80294C8C_de_padding_959A8[2] = {
    0x0000003C, 0x010000AC,
};
#endif
#endif

#if defined(VERSION_DE)
INCLUDE_ASM("span_1000", func_80294C84_de);
#endif

#if defined(VERSION_DE)
unsigned int func_80294C8C_de_padding_9588C[1] = {
    0x00290821,
};
#endif
