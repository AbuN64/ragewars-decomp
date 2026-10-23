#include "include_asm.h"

#if defined(VERSION_EU)
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#include "COMMON/ITEMRECAT20V1.H"
extern ResidentEventHandlerEntry D_800E4EC0[];

s32 func_80429CA0_eu(MenuWidget *pThis, s32 event, s32 arg2, s32 arg3, s32 arg4) {
    s32 i;
    for (i = 0; D_800E4EC0[i].handler != 0; i++) {
        if (D_800E4EC0[i].event == event &&
            (D_800E4EC0[i].actorKind == pThis->resource || D_800E4EC0[i].actorKind == 30000)) {
            return D_800E4EC0[i].handler(pThis, event, arg2, arg3, arg4);
        }
    }
    return 0;
}
#endif

#if defined(VERSION_EU)
unsigned int func_804291D0_de_padding_19FD2C[1] = {
    0x46000802,
};
#endif
