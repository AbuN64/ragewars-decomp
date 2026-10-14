#include "span_1000/code_80209AE8.h"
#include "types.h"











void func_8020A884_de(void *arg0, void *arg1) {
    AiController *o = arg0;
    AiConfig *i = arg1;
    s32 timer = o->unk2EC;

    if (timer == 0) {
        if (o->unk23C == 0 && o->unk240 <= 0) {
            f32 k = D_800C1D2C_de;
            f32 threshold = func_80274564_de(D_800C1D28_de) + k;

            if ((f32) i->unk18 < threshold) {
                o->unk240 = 1;
                func_8020A95C_de(arg0, arg1);
            }
            o->unk2EC = i->unk10;
            o->unk2EC =
                (s32) ((f32) o->unk2EC +
                       func_80274564_de(k) * (f32) i->unk14);
        }
    } else {
        o->unk2EC = timer - 1;
    }
}
