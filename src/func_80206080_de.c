#include "common/types_1dc8418c21db.h"
#include "common/types_8fd754e1e915.h"
#include "span_1000/code_80204E78.h"
/* FAKEMATCH: retains inherited numeric field accesses because a verified live shared layout for those accesses is not available; the old access widths and evaluation order are preserved. */
#include "types.h"
#include "shared/level_actor.h"
#include "span_1000/code_80206258.h"
extern s32 D_801462C8;












void func_80206080_de(void *arg0, void *arg1) {
    Actor_func_8024A7A0_de *actor = arg0;
    ActorMotionState *motion = arg1;
    AnimationTriggerResource *resource;
    AnimationTriggerDefinition *base;
    char *ctx;
    f32 result;
    s32 count;
    s32 temp_v1;
    f64 var_f1;
    f32 scaled;

    resource = (void *)actor->definition;
    base = &resource->trigger;
    result = func_80274A90_de(base->delayMinimum, base->delayMaximum);
    motion->speed = result;
    ctx = (char *) &D_801462C8;
    if (((ObjectState1E_2 *)(ctx))->unk_1D != 0) {
        count = *(s32 *) (ctx - 0x1258);
        if ((u32) count >= 3) {
            count -= 2;
            scaled = result * D_800C1AD0_de;
            temp_v1 = 0x64 - count * 25;
            var_f1 = (f64) temp_v1;
            if (temp_v1 < 0) {
                var_f1 += (4294967296.0);
            }
            motion->speed = scaled * (f32) var_f1;
        }
    }
}
