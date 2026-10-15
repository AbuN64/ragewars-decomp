#include "common/types_1dc8418c21db.h"
#include "span_1000/code_802B2EF8.h"
#include "types.h"


extern void *func_802B3BF8_de(void);
extern void func_802B3C3C_de(s32 arg0, void *arg1);











void func_802B3200_de(void *arg0, void *arg1) {
    void *Shared_func_802B3200_de_v0;
    void *temp_a0;
    SharedRecV8 fn;
    s32 new_var;

    if ((((ObjectStateC_2 *)(arg1))->unk_8.v0) != 0) {
        if ((((struct IntegerStateDC_2 *) ((ObjectStateC_2 *) arg1)->unk_8.v1)->state) != 0) {
            Shared_func_802B3200_de_v0 = func_802B3BF8_de();
            if (Shared_func_802B3200_de_v0 != 0) {
                new_var = (((struct Shape_typemap_71 *)(arg0))->field_1C) + (((struct IntegerStateDC_2 *) ((ObjectStateC_2 *) arg1)->unk_8.v1)->state);
                ((ObjectLinks10_2 *)(Shared_func_802B3200_de_v0))->unk_8 = 0;
                ((ObjectLinks10_2 *)(Shared_func_802B3200_de_v0))->unk_4 = new_var;
                ((ObjectLinks10_2 *)(Shared_func_802B3200_de_v0))->unk_C = ((ObjectStateC_2 *)(arg1))->unk_8.v0;
                temp_a0 = ((struct Draw *) ((ObjectStateC_2 *) arg1)->unk_8.v1)->model;
                fn = ((CallbackStateC_4 *)(temp_a0))->callback;
                fn(temp_a0, 3, Shared_func_802B3200_de_v0);
                ((ObjectStateC_2 *)(arg1))->unk_8.v0 = 0;
            }
        } else {
            func_802B3C3C_de((s32) arg0, ((ObjectStateC_2 *)(arg1))->unk_8.v0);
            ((ObjectStateC_2 *)(arg1))->unk_8.v0 = 0;
        }
    }
}
