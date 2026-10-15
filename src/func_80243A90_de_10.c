#include "span_1000/code_80243A80.h"
#include "shared/func_802052C4_de_closed.h"
#include "shared/func_802453D4_de_closed.h"
#include "shared/func_80245B74_de_closed.h"
#include "shared/func_80245BC0_de_closed.h"
#include "span_1000/code_80245980.h"

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

void func_80245BC0_de(void) {
    if (D_800E2830->closed == 0) {
        {
            void *temp_a1 = D_800E2830->owner;
            if (temp_a1 != 0) {
                func_80253838_de(0, temp_a1);
            }
        }
        {
            void *record = D_800E2830;
            FuncPtr fn = ((Shared_MenuContext *)(record))->onClose;

            ((Shared_MenuContext *)(record))->owner = 0;
            ((Shared_MenuContext *)(record))->resource = 0;
            ((Shared_MenuContext *)(record))->active = 0;
            ((Shared_MenuContext *)(record))->state3C = 0;
            ((Shared_MenuContext *)(record))->unknown60 = 0;
            if (fn != 0) {
                ((Shared_MenuContext *)(record))->onClose = 0;
                fn();
            }
        }
        D_800E2830->closed = 1;
    }
}
