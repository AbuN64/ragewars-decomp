#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/OBJRECAT26DD8.H"
#include "RENDER/802944E8.H"
#include "TYPES.H"
#include "RENDER/802944E8_10.H"
#include "include_asm.h"
#include "COMMON/LONE/D_8010EC90.H"
#include "COMMON/RESIDENTSTATE.H"

/* Opens the idle-time prompt when allowed and reports whether the pause input remains active. */


s32 Cinema_IsSequenceInWindow();                                /* extern */
s32 func_80245850_de();                                /* extern */
s32 Cinema_GetSequenceRequest();                                /* extern */
void func_804037D4_de(void *);                            /* extern */
s32 Pak_CountLiveNodes(void *);                             


extern func_80294BB0_S1 D_8014561C;

s32 SimpPool_CheckSequencePromptRequest(ObjRecAt26DD4 *arg0) {
    s32 var_v0;
    Prompt *prompt;

    if ((Pak_CountLiveNodes(&D_8014561C) == 0) && (Cinema_IsSequenceInWindow() != 0)) {
        if (Cinema_GetSequenceRequest() == 0x78) {
            prompt = &D_8014561C.unk1284;
            if (prompt->unk88 == 0) {
                if (arg0->unk26DD4 == 0) {
                    prompt->unk88 = 1;
                    func_804037D4_de(prompt);
                }
                goto block_6;
            }
            goto block_7;
        }
    }
block_6:
    if (D_801462C8.counters.first != 0) {
block_7:
        if (func_80245850_de() != 0) return 1;
    }
    return 0;
}

struct Context;
s32 Player_ResetPlayerControllers(struct Context *);
s32 Rumble_FreeAllPoolNodes(s32 *);
extern char D_80145040;
void SimpPool_ResetEffectsAndControllers(void) {
    Rumble_FreeAllPoolNodes(&D_8010EC90);
    Player_ResetPlayerControllers(&D_80145040);
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
