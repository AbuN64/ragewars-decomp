#include "shared/func_804235A8_eu_layout.h"
#include "common/types_1dc8418c21db.h"
#include "span_1000/code_80243A80.h"
#include "types.h"

extern int func_80245784_de(void);

extern void func_80245BC0_de(void);
extern void func_80253838_de(void *, void *);
extern void *D_800E2830;




void func_802456A0_de(void) {
    if (func_80245784_de() != 0) {
        s32 temp_a1;
        Shared_MenuContext *record;

        func_80245B74_de(1);
        func_80245BC0_de();
        temp_a1 = (s32)((Shared_MenuContext *)D_800E2830)->owner;
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
}
