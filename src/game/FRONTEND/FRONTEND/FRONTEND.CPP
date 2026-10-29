#include "include_asm.h"

#if defined(VERSION_US)
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#include "COMMON/MULTIPLAYEROPTIONS.H"
extern ResidentEventHandlerEntry D_800E54A8[];

s32 Frontend_DispatchPakProfileEventUs(ActorDefinitionHeader *actor, s32 event, s32 eventPayload, s32 eventValue, s32 eventExtra) {
    s32 index;
    index = 0;
    if (D_800E54A8[index].handler != 0) {
        do {
            if (D_800E54A8[index].event == event) {
                if (D_800E54A8[index].actorKind == actor->character || D_800E54A8[index].actorKind == 30000) {
                    return D_800E54A8[index].handler(actor, event, eventPayload, eventValue, eventExtra);
                }
            }
            index++;
        } while (D_800E54A8[index].handler != 0);
    }
    return 0;
}
#endif

#if defined(VERSION_US)
unsigned char g_FrontendTrailingBytesBlock7[8] = { 0x67, 0x48, 0x64, 0x72, 0x52, 0x00, 0x00, 0x00 };
#endif

#if defined(VERSION_US)
unsigned int k_FrontendEncodedWordsBlock18[1] = {
    0x0000000A,
};
#endif
