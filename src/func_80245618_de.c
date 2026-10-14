#include "span_1000/code_8025A3EC.h"
#include "common/unused.h"
#include "span_1000/code_80243A80.h"
#include "shared/func_80245618_de_closed.h"

s32 func_80245618_de(s32 arg0, ContextCallback arg1, VoidCallback arg2) {
    s32 result;

    result = func_804030E0_de(arg0);
    if (D_800E2830->requestE0 == arg0) {
        D_800E2830->callbackE4 = arg1;
        D_800E2830->callbackE8 = arg2;
    } else {
        if (arg1 != 0) {
            arg1(D_800E2830);
        }
        if (arg2 != 0) {
            arg2();
        }
    }
    return result;
}
