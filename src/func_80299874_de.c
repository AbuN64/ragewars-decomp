#include "common/types_1dc8418c21db.h"
#include "span_1000/code_80297CD0.h"
#include "types.h"





extern Ui_func_80297FA0_de *D_8014D080;
void func_80299874_de(s32 arg0, s32 arg1) {
    s32 var_a2;
    Rec_func_8024C92C_de *var_v1;
    var_a2 = 0;
    var_v1 = D_8014D080->slots;
    do {
        if (var_v1->x == arg0) {
            var_v1->pad1 = arg1;
        }
        var_a2 += 1;
        var_v1++;
    } while (var_a2 < 0x40);
}
