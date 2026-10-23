#include "COMMON/CALLBACK.H"
#include "MATH/80299ECC_3.H"
#include "MATH/SHARED_WIDGETIDE.H"

s32 func_80299A80_de(struct Shared_WidgetIdE *widget, sm_dldc event) {
    WidgetCallback cb = func_8029AA80_find(widget->id);

    if (cb != 0) {
        cb(widget, event);
        return 1;
    }
    return 0;
}
