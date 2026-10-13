#include "shared/func_804235A8_eu_layout.h"
#include "span_1000/code_80243A80.h"
/* Reports whether the globally selected record is active (its word at 0x38 is non-zero) and its
   value at 0x1C lies between the bounds at 0x30 and 0x34. */
extern void *D_800E2830;



int func_80245798_de(void) {
    Shared_MenuContext *record = D_800E2830;
    float temp_f1;
    int var_a0 = 0;

    if (record->active != 0) {
        temp_f1 = record->time;
        if (record->start <= temp_f1 && temp_f1 <= record->end) {
            var_a0 = 1;
        }
    }
    return var_a0;
}
