#include "common/types_1dc8418c21db.h"
#include "span_1000/code_80255BEC.h"
#include "types.h"
#include "span_1000/code_80254CE4.h"






void func_80255C4C_de(void *arg0, s32 *arg1, u32 *arg2) {
    u32 temp_a0;
    u32 var_v1;
    void *var_a3;

    *arg1 = 0;
    *arg2 = 0;
    var_a3 = ((Pool80255ACC *)arg0)->head;
    if (var_a3 != 0) {
        do {
            *arg1 += (u32)((Block80255720 *)var_a3)->size;
            var_v1 = (u32)((Block80255720 *)var_a3)->size;
            temp_a0 = *arg2;
            if (var_v1 < temp_a0) {
                var_v1 = temp_a0;
            }
            *arg2 = var_v1;
            var_a3 = ((Block80255720 *)var_a3)->next;
        } while (var_a3 != 0);
    }
}
