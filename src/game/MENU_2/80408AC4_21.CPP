#include "include_asm.h"

#if defined(VERSION_DE)
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#include "COMMON/ITEMRECAT20V1.H"
extern ResidentEventHandlerEntry D_800EB1A4[];

s32 Menu_DispatchGermanJoinOptionsEvent(MenuWidget *pThis, s32 event, s32 arg2, s32 arg3, s32 arg4) {
    s32 i;
    for (i = 0; D_800EB1A4[i].handler != 0; i++) {
        if (D_800EB1A4[i].event == event &&
            (D_800EB1A4[i].actorKind == pThis->resource || D_800EB1A4[i].actorKind == 30000)) {
            return D_800EB1A4[i].handler(pThis, event, arg2, arg3, arg4);
        }
    }
    return 0;
}
#endif

#if defined(VERSION_DE)
unsigned char D_auto_func_8041F138_de_padding_185138[8] = { 0x00, 0x00, 0x20, 0x21, 0x8F, 0xAA, 0x00, 0x40 };
#endif
