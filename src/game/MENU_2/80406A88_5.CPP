#include "include_asm.h"

#if defined(VERSION_EU_X)
#include "COMMON/SCREEN.H"

s32 func_80421E70_eu_x(void) {
    s32 message;
    MarkMenuEventHandled();
    if (D_800E4400->open == 0) {
        func_8042177C_de();
    } else {
        message = func_80299A08_de();
        switch (message) {
        case 0x3BA:
            func_8041A430_de(D_800E4400->dialog, 2);
            func_804210E8_de();
            break;
        case 0x3B2:
            func_804213DC_de();
            break;
        }
    }
    return 0;
}
#endif
