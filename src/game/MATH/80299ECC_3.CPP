#include "COMMON/CALLBACK.H"
#include "MATH/80299ECC_3.H"
#include "MATH/SHARED_WIDGETIDE.H"

s32 func_80299A80_de(struct Shared_WidgetIdE *arg0, sm_dldc event) {
    WidgetCallback cb = func_8029AA80_find(arg0->id);

    if (cb != 0) {
        cb(arg0, event);
        return 1;
    }
    return 0;
}
