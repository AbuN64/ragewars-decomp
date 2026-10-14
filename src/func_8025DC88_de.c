#include "common/unused.h"
#include "common/types_06e4f7ef1f9e.h"
#include "common/types_1dc8418c21db.h"
#include "span_1000/code_8025D948.h"
#include "types.h"





extern f32 D_800C4030_de;









void func_8025DC88_de(void *arg0) {
    ObjectState40 *o = arg0;
    f32 var_f20;
    ContextRecAt2BC0 *temp_v0;

    if (o->unk_38 != 0) {
        f32 prod = o->context->green;
        prod = prod * D_800C4024_de;
        var_f20 = (f32) (o->unk_24);
        var_f20 = var_f20 * prod;
        var_f20 = var_f20 * o->unk_3C;
        goto do_update;
    }
    temp_v0 = o->context;
    var_f20 = (f32) (o->unk_24) * (temp_v0->green * D_800C4028_de);
    if (temp_v0->field2BB8 != 0) {
        var_f20 = var_f20 * (0.699999988079071f);
    }
    if (var_f20 != o->unk_2C) {
do_update:
        func_802AFF60_de(o->unk_14, (s16) (s32) (var_f20 * D_800C4030_de));
        o->unk_2C = var_f20;
    }
}
