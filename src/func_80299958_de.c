#include "span_1000/code_80297CD0.h"
#include "types.h"
extern Ui_func_80297FA0_de *D_8014D080;
s32 func_80299958_de(void) {
    s32 result;
    s32 field4;
    result = D_80146E18;
    if (result < 0) {
        field4 = D_8014D080->current;
        if (field4 < 0) {
            return -1;
        }
        result = D_8014D080->screens[field4].owner;
    }
    return result;
}
