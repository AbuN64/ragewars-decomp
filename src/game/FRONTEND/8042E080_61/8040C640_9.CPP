#include "include_asm.h"

#if defined(VERSION_US)
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#include "COMMON/MULTIPLAYEROPTIONS.H"
extern ResidentEventHandlerEntry D_800E54A8[];

s32 Frontend_DispatchPakProfileEventUs(ActorDefinitionHeader *actor, s32 event, s32 arg2, s32 arg3, s32 arg4) {
    s32 index;
    index = 0;
    if (D_800E54A8[index].handler != 0) {
        do {
            if (D_800E54A8[index].event == event) {
                if (D_800E54A8[index].actorKind == actor->character || D_800E54A8[index].actorKind == 30000) {
                    return D_800E54A8[index].handler(actor, event, arg2, arg3, arg4);
                }
            }
            index++;
        } while (D_800E54A8[index].handler != 0);
    }
    return 0;
}
#endif

#if defined(VERSION_US)
unsigned char D_auto_func_80435CE4_us_padding_199CE4[8] = { 0x67, 0x48, 0x64, 0x72, 0x52, 0x00, 0x00, 0x00 };
#endif

#if defined(VERSION_US)
unsigned int rodata_unresolved_80435CEC[1] = {
    0x0000000A,
};
#endif
