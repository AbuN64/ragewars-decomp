#include "include_asm.h"

#if defined(VERSION_US)
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#include "COMMON/MULTIPLAYEROPTIONS.H"
extern ResidentEventHandlerEntry D_800EB1A4[];

s32 func_8041F120_us(ActorDefinitionHeader *actor, s32 event, s32 arg2, s32 arg3, s32 arg4) {
    s32 index;
    index = 0;
    if (D_800EB1A4[index].handler != 0) {
        do {
            if (D_800EB1A4[index].event == event) {
                if (D_800EB1A4[index].actorKind == actor->character || D_800EB1A4[index].actorKind == 30000) {
                    return D_800EB1A4[index].handler(actor, event, arg2, arg3, arg4);
                }
            }
            index++;
        } while (D_800EB1A4[index].handler != 0);
    }
    return 0;
}
#endif

#if defined(VERSION_US)
INCLUDE_DATA("ovl_80400000", rodata_unresolved_8041F1A8);
#endif
