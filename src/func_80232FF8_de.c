#include "common/types_06e4f7ef1f9e.h"
#include "span_1000/code_80231F5C.h"
#include "types.h"
#include "span_1000/code_8022C894.h"


extern s16 func_8022F96C_de(void *arg0);
extern s32 func_802301F4_de(void *, void *);
extern s32 func_80214178_de(void *, void *, s32);


extern WeaponActionRecord D_800CE8DC[];








void func_80232FF8_de(void *arg0, void *arg1) {
    char *o = (char *) arg0;
    void *temp_s0;
    s16 idx;
    s32 temp_s3;

    temp_s0 = (void *)((Actor_func_8022D290_de *)o)->self;
    idx = ((Actor_func_8022D290_de *)temp_s0)->unk_0x0650;
    temp_s3 = D_800CE8DC[idx].action;

    if (func_80222AA4_de(temp_s0, ((Actor_func_8022D290_de *)temp_s0)->unk_0x062E) == 0) {
        ((Actor_func_8022D290_de *)temp_s0)->unk_0x0770 = func_8022F96C_de(temp_s0);
    } else {
        ((ObjectState140 *)arg1)->unk_13C = 1;
        if (func_802301F4_de(arg0, arg1) == 0 && !(((Actor_func_8022D290_de *)o)->flags & 0x400)) {
            func_80214178_de(arg0, arg1, temp_s3);
        }
    }
}
