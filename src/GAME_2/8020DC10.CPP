#include "COMMON/SHAREDCALLBACK5.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/ACTORREC.H"
#include "TYPES.H"
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#include "COMMON/BOX_CONTACT.H"
#include "GAME_2/8020DC10.H"

extern void func_8020DCA0_de(void);


s32 func_80209874_de(void *, s32);

s32 func_8020DD04_de(s32);

s32 func_8020DC10_de(void *arg0) {
    if ((s32)((AiController *)arg0)->target != 0) {
        if ((u32) (((AiController *)arg0)->state - 3) < 3U) {
            func_8020DCA0_de();
            return 1;
        }
        func_8020DC60_de(arg0);
        return 1;
    }
    return 1;
}

void func_8020DC60_de(void *arg0) {
    s32 temp_v0;
    temp_v0 = func_8020DD04_de((((struct ObjRecAt18V4 *) ((s8 *) ((struct func_8020DCA0_S1 *) ((s8 *) arg0))->unk0))->unk18) + 0x14);
    (((struct func_8020DCA0_S1 *) ((s8 *) arg0))->unk230) = temp_v0;
    func_80209874_de(arg0, temp_v0);
}
