#include "shared/gameplay_transition.h"
#include "shared/level_actor.h"
#include "common/types_1dc8418c21db.h"
#include "span_1000/code_8022C894.h"
#include "types.h"

extern void func_802227F4_de(void *, void *, s32);
extern void func_8022CE78_de(s32 arg0, s32 arg1);








void func_8022CDBC_de(void *arg0, void *arg1) {
    f32 temp_f2;

    temp_f2 = ((Shared_ActorView *)arg0)->lateralSpeed;
    if ((temp_f2 < 0.0f && ((Shared_ActorView *)arg0)->lateralInput >= 0.0f) ||
        (temp_f2 > 0.0f && ((Shared_ActorView *)arg0)->lateralInput <= 0.0f) ||
        (((Shared_ActorView *)arg0)->actionTimer >= D_800C2D8C_de)) {
        func_802227F4_de(arg0, arg1, 8);
    } else {
        ((Actor_func_8024A7A0_de *)arg1)->position1.y = D_800C2D90_de;
    }
    func_8022CE78_de((s32)arg0, (s32)arg1);
}
