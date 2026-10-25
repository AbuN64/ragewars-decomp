#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/OBJRECAT26DD8.H"
#include "RENDER/802944E8.H"
#include "TYPES.H"
#include "RENDER/802944E8_10.H"

/* Opens the idle-time prompt when allowed and reports whether the pause input remains active. */


s32 Camera_IsSequenceInWindow();                                /* extern */
s32 func_80245850_de();                                /* extern */
s32 Camera_GetSequenceRequest();                                /* extern */
void func_804037D4_de(void *);                            /* extern */
s32 Pak_CountLiveNodes(void *);                             


extern func_80294BB0_S1 D_8014561C;

s32 func_80294B9C_de(ObjRecAt26DD4 *arg0) {
    s32 var_v0;
    Prompt *prompt;

    if ((Pak_CountLiveNodes(&D_8014561C) == 0) && (Camera_IsSequenceInWindow() != 0)) {
        if (Camera_GetSequenceRequest() == 0x78) {
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
