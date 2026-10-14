#include "span_1000/code_80245980.h"
#include "shared/func_80245B74_de_closed.h"

void func_80245B74_de(s32 unused) {
    Shared_MenuContext *record;
    Shared_MenuVoidCallback fn;

    record = D_800E2830;
    if (record->initialized44 == 0) {
        fn = record->callback10;
        if (fn != 0) {
            record->callback10 = 0;
            fn();
        }
        record = D_800E2830;
        record->initialized44 = 1;
    }
}
