#include "shared/gameplay_transition.h"
#include "span_1000/code_8022D944.h"
#include "types.h"

extern void func_80274870_de(f32 *value, f32 target, f32 rate);
extern f32 D_800C2DF8_de[2];





void func_8022DD94_de(void *arg0) {
    f32 sp10;
    f32 var_f1;
    f32 var_f2;

    var_f1 = 0.0f;
    if ((u32)((u16)((Shared_ActorView *)arg0)->action - 9) < 4U) {
        var_f1 = D_800C2DF8_de[0];
    }
    sp10 = ((Shared_ActorView *)arg0)->transitionBlend;
    func_80274870_de(&sp10, var_f1, 0.25f);
    var_f2 = sp10 - ((Shared_ActorView *)arg0)->transitionBlend;
    if (var_f2 < 0.0f) {
        if (-var_f2 < D_800C2DF8_de[1]) {
            goto clamp;
        }
    } else if (var_f2 < D_800C2E00_de) {
clamp:
        var_f2 = 0.0f;
    }
    ((Shared_ActorView *)arg0)->transitionBlend = ((Shared_ActorView *)arg0)->transitionBlend + var_f2;
}
