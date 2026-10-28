#include "include_asm.h"

#if defined(VERSION_EU_X)
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#include "COMMON/ITEMRECAT20V1.H"
extern ResidentEventHandlerEntry D_800F1DA8[];

s32 Menu_DispatchSettingsTableEvent(MenuWidget *pThis, s32 event, s32 arg2, s32 arg3, s32 arg4) {
    s32 i;
    for (i = 0; D_800F1DA8[i].handler != 0; i++) {
        if (D_800F1DA8[i].event == event &&
            (D_800F1DA8[i].actorKind == pThis->resource || D_800F1DA8[i].actorKind == 30000)) {
            return D_800F1DA8[i].handler(pThis, event, arg2, arg3, arg4);
        }
    }
    return 0;
}
#endif
