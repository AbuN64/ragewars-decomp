#include "sdk/libgultra.h"
#include "common/types_1dc8418c21db.h"
#include "span_1000/code_802B2EF8.h"
#include "types.h"

extern void *__allocParam(void);











void func_802B32A0_de(void *arg0, void *arg1, s8 arg2) {
    s32 new_var;
    s32 var_v0;
    void *Shared_func_802B32A0_de_v0;
    void *temp_a0;
    SharedRecV4 fn;

    if ((((ObjectStateC_2 *)(arg1))->unk_8.v0) != 0) {
        Shared_func_802B32A0_de_v0 = __allocParam();
        if (Shared_func_802B32A0_de_v0 != 0) {
            new_var = (((struct Shape_typemap_71 *)(arg0))->field_1C) + (((struct IntegerStateDC_2 *) ((ObjectStateC_2 *) arg1)->unk_8.v1)->state);
            ((ObjectState10_3 *)(Shared_func_802B32A0_de_v0))->unk_8 = 0x10;
            ((ObjectState10_3 *)(Shared_func_802B32A0_de_v0))->unk_4 = new_var;
            if (arg2 < 0) {
                var_v0 = -arg2;
            } else {
                var_v0 = (u8) arg2;
            }
            ((ObjectState10_3 *)(Shared_func_802B32A0_de_v0))->unk_C = var_v0;
            ((ObjectState10_3 *)(Shared_func_802B32A0_de_v0))->unk_0 = 0;
            temp_a0 = ((struct Draw *) ((ObjectStateC_2 *) arg1)->unk_8.v1)->model;
            fn = ((CallbackStateC_4 *)(temp_a0))->callback;
            fn(temp_a0, 3, Shared_func_802B32A0_de_v0);
        }
    }
}

extern void *__allocParam(void);











void func_802B3350_de(void *arg0, void *arg1, u8 arg2) {
    s32 new_var;
    void *Shared_func_802B3350_de_v0;
    void *temp_a0;
    SharedRecV5 fn;

    if ((((ObjectStateC_2 *)(arg1))->unk_8.v0) != 0) {
        Shared_func_802B3350_de_v0 = __allocParam();
        if (Shared_func_802B3350_de_v0 != 0) {
            new_var = (((struct Shape_typemap_71 *)(arg0))->field_1C) + (((struct IntegerStateDC_2 *) ((ObjectStateC_2 *) arg1)->unk_8.v1)->state);
            ((ObjectState10_3 *)(Shared_func_802B3350_de_v0))->unk_8 = 0xC;
            ((ObjectState10_3 *)(Shared_func_802B3350_de_v0))->unk_C = arg2;
            ((ObjectState10_3 *)(Shared_func_802B3350_de_v0))->unk_0 = 0;
            ((ObjectState10_3 *)(Shared_func_802B3350_de_v0))->unk_4 = new_var;
            temp_a0 = ((struct Draw *) ((ObjectStateC_2 *) arg1)->unk_8.v1)->model;
            fn = ((CallbackStateC_4 *)(temp_a0))->callback;
            fn(temp_a0, 3, Shared_func_802B3350_de_v0);
        }
    }
}

extern void *__allocParam(void);











void func_802B33E0_de(void *arg0, void *arg1, f32 arg2) {
    s32 new_var;
    void *Shared_func_802B33E0_de_v0;
    void *temp_a0;
    SharedRecV7 fn;

    if ((((ObjectStateC_2 *)(arg1))->unk_8.v0) != 0) {
        Shared_func_802B33E0_de_v0 = __allocParam();
        if (Shared_func_802B33E0_de_v0 != 0) {
            new_var = (((struct Shape_typemap_71 *)(arg0))->field_1C) + (((struct IntegerStateDC_2 *) ((ObjectStateC_2 *) arg1)->unk_8.v1)->state);
            ((ObjectState10_4 *)(Shared_func_802B33E0_de_v0))->unk_8 = 7;
            ((ObjectState10_4 *)(Shared_func_802B33E0_de_v0))->unk_C = arg2;
            ((ObjectState10_4 *)(Shared_func_802B33E0_de_v0))->unk_0 = 0;
            ((ObjectState10_4 *)(Shared_func_802B33E0_de_v0))->unk_4 = new_var;
            temp_a0 = ((struct Draw *) ((ObjectStateC_2 *) arg1)->unk_8.v1)->model;
            fn = ((CallbackStateC_4 *)(temp_a0))->callback;
            fn(temp_a0, 3, Shared_func_802B33E0_de_v0);
        }
    }
}
