#include "MAIN/80255280.H"
#include "common/types_8fd754e1e915.h"
#include "span_1000/code_8025D948.h"
#include "TYPES.H"


extern void func_802AFF90_de(s32 arg0);







void func_8025D928_de(void *arg0) {
    ObjectState40 *o = arg0;
    f32 temp_f1;
    f32 temp_f2;
    f32 var_f0;
    s32 temp_f3;

    if (o->flags & 2) {
        func_802AFF60_de(o->unk_14, (s16)o->volume);
        temp_f3 = (s32) ((f32) o->volume - o->fadeStep);
        o->volume = temp_f3;
        if (temp_f3 <= 0) {
            o->volume = 0;
            func_802AFF90_de(o->unk_14);
            o->flags |= 4;
        }
    } else if (o->unk_38 != 0) {
        temp_f1 = o->unk_3C;
        temp_f2 = o->targetGain;
        if (temp_f2 < temp_f1) {
            var_f0 = temp_f1 - D_800C4000_de;
            if (temp_f2 <= var_f0) {
                goto store;
            }
            goto clamp;
        }
        if (temp_f1 < temp_f2) {
            var_f0 = temp_f1 + (0.01666666753590107f);
            if (var_f0 <= temp_f2) {
                goto store;
            }
clamp:
            var_f0 = temp_f2;
store:
            o->unk_3C = var_f0;
        }
    }
}
