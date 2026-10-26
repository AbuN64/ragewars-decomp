#include "include_asm.h"

#if defined(VERSION_EU_X)
#include "COMMON/SCREEN.H"

s32 Menu_HandleEuxExtraOptionsChoice(void) {
    s32 message;
    MarkMenuEventHandled();
    if (D_800E4400->open == 0) {
        Menu_ShowExtraOptionsPanel();
    } else {
        message = func_80299A08_de();
        switch (message) {
        case 0x3BA:
            func_8041A430_de(D_800E4400->dialog, 2);
            Menu_ApplyExtraOptionFlags();
            break;
        case 0x3B2:
            Menu_OpenOptionsKeypad();
            break;
        }
    }
    return 0;
}
#endif
