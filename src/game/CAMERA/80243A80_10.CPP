#include "COMMON/GROUP.H"
#include "COMMON/FUNCPTR.H"
#include "COMMON/SHAREDTRACKOBJECTPREFIX.H"
#include "CAMERA/EXTERNS.H"
#include "COMMON/EXTERNS_8.H"
#include "COMMON/ACCESS_S8_10F.H"
#include "CAMERA/80243A80_10.H"

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
            void *owner = D_800E2830->owner;
            if (owner != 0) {
                func_80253838_de(0, owner);
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
