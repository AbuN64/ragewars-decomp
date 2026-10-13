#include "span_1000/code_80243A80.h"
#include "shared/func_804235A8_eu_layout.h"
/* Returns the globally selected record's word at 0xAC while its word at 0x38 is non-zero, and 0
   otherwise. */
extern void *D_800E2830;




int func_80245940_de(void) {
    Shared_MenuContext *record = D_800E2830;
    int cond = record->active != 0;
    if (cond) {
        if (record) {
            return record->spec.settings[1];
        } else {
            return record->spec.settings[1];
        }
    }
    return 0;
}
