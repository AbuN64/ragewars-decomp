#include "COMMON/NUMBERPADSCREEN.H"
#include "TYPES.H"
#include "COMMON/SCREEN.H"

#if !(defined(VERSION_DE) || defined(VERSION_EU_X))
s32 Menu_HandleExtraOptionsChoice(void) {
    MarkMenuEventHandled();
    if (D_800E4400->open == 0) {
        Menu_ShowExtraOptionsPanel();
    } else {
        switch (func_80299A08_de()) {
        case 0x3AC:
            func_8041A430_de(D_800E4400->dialog, 2);
            Menu_ApplyExtraOptionFlags();
            break;
        case 0x3B6:
            Menu_OpenOptionsKeypad();
            break;
        }
    }
    return 0;
}
#endif
