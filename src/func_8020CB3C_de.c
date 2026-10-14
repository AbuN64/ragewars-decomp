#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_8020AF9C.h"
#include "types.h"



extern void func_80271F68_de(Vec3 *out, void *arg1, void *arg2);




s32 func_8020CB3C_de(struct Obj8020BC50 *arg0, void *arg1) {
    Vec3 sp10;
    f32 temp_f2;
    f32 var_f20;
    void *items;
    s32 stride;
    s32 var_s0;
    s32 var_s1;

    var_s1 = -1;
    var_f20 = 0.0f;
    var_s0 = 0;
    if (arg0->count > 0) {
        do {
            items = arg0->records;
            stride = *(s32 *)items;
            func_80271F68_de(&sp10, arg1, (char *)items + (var_s0 * stride + 8));
            temp_f2 = (sp10.x * sp10.x) + (sp10.y * sp10.y) + (sp10.z * sp10.z);
            if ((var_s1 < 0) || (temp_f2 < var_f20)) {
                var_s1 = var_s0;
                var_f20 = temp_f2;
            }
            var_s0 += 1;
        } while (var_s0 < arg0->count);
    }
    return var_s1;
}
