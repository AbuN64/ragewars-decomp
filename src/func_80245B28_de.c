#include "shared/func_804235A8_eu_layout.h"
#include "common/types_1dc8418c21db.h"
#include "span_1000/code_80245980.h"
extern void *D_800E2830;
extern void func_80253838_de(void *arg0, void *arg1);




void func_80245B28_de(void) {
    int temp_a1 = (s32)((Shared_MenuContext *)D_800E2830)->owner;
    Shared_MenuContext *record;
    if (temp_a1 != 0) {
        func_80253838_de(0, temp_a1);
    }
    record = D_800E2830;
    record->owner = 0;
    record->resource = 0;
    record->active = 0;
    record->state3C = 0;
    record->unknown60 = 0;
}
