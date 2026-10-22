#include "include_asm.h"

#if defined(VERSION_EU)
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#include "COMMON/MULTIPLAYEROPTIONS.H"
extern ResidentEventHandlerEntry D_800E57DC[];

s32 func_804387F0_eu(ActorDefinitionHeader *actor, s32 event, s32 arg2, s32 arg3, s32 arg4) {
    s32 index;
    index = 0;
    if (D_800E57DC[index].handler != 0) {
        do {
            if (D_800E57DC[index].event == event) {
                if (D_800E57DC[index].actorKind == actor->character || D_800E57DC[index].actorKind == 30000) {
                    return D_800E57DC[index].handler(actor, event, arg2, arg3, arg4);
                }
            }
            index++;
        } while (D_800E57DC[index].handler != 0);
    }
    return 0;
}
#endif
