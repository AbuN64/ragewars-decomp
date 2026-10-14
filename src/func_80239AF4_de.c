#include "common/types_1dc8418c21db.h"
#include "span_1000/code_802393F4.h"
#include "types.h"



extern void func_80255ED8_de(void *, s32);
extern s32 func_80255CB8_de(void *, s32);






void func_80239AF4_de(s32 arg0, void *arg1) {
    Node_func_80239AF4_de *var_s1;
    Node_func_80239AF4_de *temp_s0;
    void *var_a0;

    if (arg1 != 0) {
        var_s1 = ((struct ScreenMessagePool *)arg1)->freeMessages.tail;
        var_a0 = &((struct ScreenMessagePool *)arg1)->freeMessages;
        if (var_s1 != 0) {
            do {
                temp_s0 = var_s1->next;
                func_80255ED8_de(var_a0, var_s1);
                func_80255CB8_de(&((struct ScreenMessageOwner *)arg0)->activeMessages, (s32)var_s1);
                var_s1 = temp_s0;
                var_a0 = &((struct ScreenMessagePool *)arg1)->freeMessages;
            } while (var_s1 != 0);
        }
    }
}
