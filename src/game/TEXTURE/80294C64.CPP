#include "include_asm.h"
#include "COMMON/LONE/D_8010EC90.H"
#include "COMMON/RESIDENTSTATE.H"
#include "TYPES.H"
#include "TEXTURE/80294C64.H"

struct Context;
s32 Weapons_ResetPlayerControllers(struct Context *);
s32 Render_FreeAllPoolNodes(s32 *);
extern char D_80145040;
void func_80294C50_de(void) {
    Render_FreeAllPoolNodes(&D_8010EC90);
    Weapons_ResetPlayerControllers(&D_80145040);
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
