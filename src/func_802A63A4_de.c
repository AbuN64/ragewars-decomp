#include "span_1000/code_8027A0F4.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_802A6AC0.h"
#include "types.h"



extern void func_80270910_de(f32 *, s32);
extern void func_8027347C_de(void *arg0, f32 sx, f32 sy, f32 sz);
extern void func_80272828_de(f32 *arg0);
extern void func_802A25D0_de(void *arg0, void *arg1, f32 *arg2);








void func_802A63A4_de(void *arg0, void *arg1, void *arg2, s32 arg3) {
    State802A6DF8 *state = arg1;
    f32 local[16];
    Shared_Particle *entry;
    f32 scale;

    entry = state->object;
    if (entry == arg2 && state->value > 0.0f) {
        func_80270910_de(local, arg3);
        scale = D_800C5EC0_de;
        if (entry->desc->renderModel != 0) {
            scale = D_800C5EC4_de;
        }
        func_8027347C_de(local, scale, scale, scale);
        func_80272828_de(local);
        func_802A25D0_de(arg0, state, local);
    }
}
