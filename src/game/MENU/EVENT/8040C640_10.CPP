#include "include_asm.h"

#if defined(VERSION_US)
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#include "COMMON/MULTIPLAYEROPTIONS.H"
extern ResidentEventHandlerEntry D_800E5628[];

s32 Frontend_DispatchResidentActorTableEvent(ActorDefinitionHeader *actor, s32 event, s32 eventArg2, s32 eventArg3, s32 eventArg4) {
    s32 index;
    index = 0;
    if (D_800E5628[index].handler != 0) {
        do {
            if (D_800E5628[index].event == event) {
                if (D_800E5628[index].actorKind == actor->character || D_800E5628[index].actorKind == 30000) {
                    return D_800E5628[index].handler(actor, event, eventArg2, eventArg3, eventArg4);
                }
            }
            index++;
        } while (D_800E5628[index].handler != 0);
    }
    return 0;
}
#endif

#if defined(VERSION_US)
unsigned int func_804364E4_de_padding_19A6C4[3] = {
    0x64655400, 0x000A0000, 0x00080032,
};
#endif
