#include "common/types_1dc8418c21db.h"
#include "span_1000/code_802B369C.h"
#include "types.h"



s32 func_802B3EDC_de(Obj_func_802B3EDC_de *arg0, s32 arg1, s32 arg2) {
    int new_var;
    s32 *base;
    s32 count;

    base = arg0->base;
    if (arg1 == 2) {
        new_var = arg0->count;
        count = new_var;
        base[count] = arg2;
        new_var = count + 1;
        arg0->count = new_var;
    }
    return 0;
}
