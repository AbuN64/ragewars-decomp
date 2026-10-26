#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/RECRECAT4.H"
#include "TYPES.H"
#include "COMMON/UNUSED.H"
#include "COMMON/SHARED_MENUREPLY.H"

/* Runs the screen D_800E4600 each frame: past stage 1 of D_800E28E0 it only calls Tsmos_DeactivateControllerState;
   otherwise it calls Tsmos_ActivateControllerState and, while the opening delay at 0xC runs, counts it down and
   calls func_8041A47C_de on its menu when it expires; after that, while the menu reports 3, it counts
   the scroll delay at 0x14 down and on expiry scrolls the list at 0x8 back one row, wrapping to
   the menu's own row count, and restarts the delay at 3, and when the menu reports 4 it calls
   MarkMenuEventHandled and leaves through func_80298368_de with the target at 0x18. Returns zero. Adapted
   from func_8042DAF8_de with the opening delay added, the scroll delay and target moved and the -1
   target test removed. */







extern struct State_func_804241BC_de *D_800E4600;
extern void Tsmos_DeactivateControllerState();
extern void Tsmos_ActivateControllerState();
extern s32 func_8041A470_de(struct Menu_func_804241BC_de *);
extern void func_8041A47C_de(struct Menu_func_804241BC_de *);
extern void MarkMenuEventHandled();

s32 func_804241BC_de(void) {
    s32 result;

    if (D_800E28E0 >= 2) {
        Tsmos_DeactivateControllerState();
        return 0;
    }
    Tsmos_ActivateControllerState();
    if (D_800E4600->opening > 0) {
        if (--D_800E4600->opening == 0) {
            func_8041A47C_de(D_800E4600->menu);
            return 0;
        }
        return 0;
    }
    switch (result = func_8041A470_de(D_800E4600->menu)) {
    case 3:
        if (--D_800E4600->delay <= 0) {
            D_800E4600->list->unk16--;
            if (D_800E4600->list->unk16 + D_800E4600->list->unk1A < 0) {
                D_800E4600->list->unk16 = D_800E4600->menu->list->unk1A;
            }
            D_800E4600->delay = result;
        }
        break;
    case 4:
        MarkMenuEventHandled();
        func_80298368_de(D_800E4600->target);
        break;
    default:
        return 0;
    }
    return 0;
}
