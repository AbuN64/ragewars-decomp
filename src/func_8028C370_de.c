#include "shared/world.h"
#include "span_1000/code_80277444.h"
#include "span_1000/code_8028B64C.h"
#include "types.h"

extern void func_80278E7C_de(void *arg0);








void func_8028C370_de(void *arg0, s32 arg1) {
    s32 var_s0;
    s32 var_s0_2;
    Record14 *var_s1;
    Record14 *var_s1_2;

    var_s0 = ((Shared_World *)arg0)->recordCount;
    var_s1 = ((Shared_World *)arg0)->recordArray;
    var_s0 -= 1;
    if (var_s0 != -1) {
        do {
            if (var_s1->kind == arg1) {
                func_80278E7C_de(var_s1);
            }
            var_s0 -= 1;
            var_s1 = var_s1 + 1;
        } while (var_s0 != -1);
    }
    var_s1_2 = ((Shared_World *)arg0)->alternateRecordArray;
    var_s0_2 = ((Shared_World *)arg0)->alternateRecordCount;
    var_s0_2 -= 1;
    if (var_s0_2 != -1) {
        do {
            if (var_s1_2->kind == arg1) {
                func_80278E7C_de(var_s1_2);
            }
            var_s0_2 -= 1;
            var_s1_2 = var_s1_2 + 1;
        } while (var_s0_2 != -1);
    }
}
