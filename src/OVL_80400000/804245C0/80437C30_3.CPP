#include "OVL_80400000/804245C0.H"
#include "common/unused.h"
#include "shared/func_804235A8_eu_closed.h"
#include "shared/func_80425674_de_layout.h"
#include "span_16E000/code_804379C8.h"
#include "TYPES.H"

void func_804389F0_de(void) {
    s32 next;
    ViewportLayoutRules *layout = &D_801462C8.viewportLayout;
    layout->rules.squads = 0;
    layout->rules.countRule = 0;
    if (layout->humanWon == 1 && D_8015402C >= 35) {
        switch (D_801462C8.controllerMode) {
        case 4:
            next = 3;
            break;
        default:
            next = 3;
            break;
        case 1:
            next = 7;
            break;
        case 3:
            next = 3;
            break;
        }
    } else {
        next = 10;
    }
    func_80298368_de(next);
}
