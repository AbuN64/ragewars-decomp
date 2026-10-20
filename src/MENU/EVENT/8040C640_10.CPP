#include "include_asm.h"

#if defined(VERSION_US)
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#include "COMMON/MULTIPLAYEROPTIONS.H"
extern ResidentEventHandlerEntry D_800E5628[];

s32 func_80436640_us(ActorDefinitionHeader *actor, s32 event, s32 arg2, s32 arg3, s32 arg4) {
    s32 index;
    index = 0;
    if (D_800E5628[index].handler != 0) {
        do {
            if (D_800E5628[index].event == event) {
                if (D_800E5628[index].actorKind == actor->character || D_800E5628[index].actorKind == 30000) {
                    return D_800E5628[index].handler(actor, event, arg2, arg3, arg4);
                }
            }
            index++;
        } while (D_800E5628[index].handler != 0);
    }
    return 0;
}
#endif

#if defined(VERSION_US)
INCLUDE_DATA("ovl_80400000", func_804364E4_de_padding_19A6C4);
#endif
