#include "span_1000/code_80299DB4.h"
#include "shared/func_80299A80_de_closed.h"

s32 func_80299A80_de(struct Shared_WidgetIdE *arg0, NodeEvent event) {
    WidgetCallback cb = func_8029AA80_find(arg0->id);

    if (cb != 0) {
        cb(arg0, event);
        return 1;
    }
    return 0;
}
