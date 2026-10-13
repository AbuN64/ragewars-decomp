#include "span_1000/code_8025E568.h"
#include "span_1000/code_8028FC98.h"
#include "common/types_1dc8418c21db.h"
#include "span_1000/code_802624A0.h"
#include "types.h"



extern void *func_8026049C_de(void *arg0);
extern char *func_8028FDB4_de(s32 *, s32);
extern f32 func_80273EE4_de(f32, f32, f32);






void func_802625F0_de(void *arg0, f32 arg1) {
    s16 *base;
    s32 count;
    s32 temp_f2;
    s32 temp_a0;
    s32 var_v1;
    f32 b_term;
    f32 e_term;

    base = (s16 *)((ResidentDataChunk *)func_8028FDB4_de(func_8026049C_de(arg0), 0))->data;
    count = (s16)((AnimRef *)arg0)->count;
    var_v1 = count - 1;
    temp_f2 = (s32) arg1;
    temp_a0 = temp_f2 + 1;
    if (temp_a0 < var_v1) {
        var_v1 = temp_a0;
    }
    b_term = (f32) base[temp_f2] * D_800C4258_de;
    e_term = (f32) base[var_v1] * D_800C4258_de;
    func_80273EE4_de(arg1 - (f32) temp_f2, b_term, e_term);
}
