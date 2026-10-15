#include "span_16E000/code_80420E90.h"
#include "types.h"
#include "shared/func_80421E70_eu_closed.h"

s32 func_80421E70_eu(void) {
    func_8029973C_de();
    if (D_800E4400->open == 0) {
        func_8042177C_de();
    } else {
        switch (func_80299A08_de()) {
        case 0x3AC:
            func_8041A430_de(D_800E4400->dialog, 2);
            func_804210E8_de();
            break;
        case 0x3B6:
            func_804213DC_de();
            break;
        }
    }
    return 0;
}
