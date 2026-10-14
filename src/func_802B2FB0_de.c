#include "common/types_1dc8418c21db.h"
#include "span_1000/code_802B2EF8.h"
#include "types.h"





s32 func_802BD170_de(s32);
void func_802B2FB0_de(void *arg0, void *arg1) {
    s32 temp_v0;
    temp_v0 = func_802BD170_de(1);
    (((struct State_func_80421D94_de *) ((s8 *) arg1))->value) = (s32) (((struct State_func_804232AC_de *) ((s8 *) arg0))->value);
    (((struct State_func_80421D94_de *) ((s8 *) arg1))->first) = (void *) (((struct State_func_804232AC_de *) ((s8 *) arg0))->menu);
    (((struct State_func_804232AC_de *) ((s8 *) arg0))->menu) = arg1;
    func_802BD170_de(temp_v0);
}
