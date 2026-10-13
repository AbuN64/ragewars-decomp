#include "shared/gameplay_transition.h"
#include "span_1000/code_80233920.h"
#include "span_1000/code_802AB3FC.h"
#include "types.h"










s32 func_802AD1B4_de(void *arg0) {
    f32 value;
    f32 input;
    f32 threshold;
    u32 converted;

    ((Shared_ActorView *)arg0)->field16D4 =
        ((Shared_ActorView *)arg0)->field16D4 == 0;
    if (((Shared_ActorView *)arg0)->message != 0) {
        input = D_800C62E0;
        ((Racer *)((Shared_ActorView *)arg0)->message)->pad124 = 0;
        value = func_80274564_de(input);
        threshold = (&D_800C62E0)[1];
        if (!(threshold <= value)) {
            converted = (s32)value;
        } else {
            converted = (s32)(value - threshold) | 0x80000000;
        }
        func_802391AC_de(((Shared_ActorView *)arg0)->message, 0xFF, 0xFF, 0xFF,
                      0xFF, (u8)converted, 1, 0);
    }
    return 1;
}
