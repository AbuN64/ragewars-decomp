#include "common/types_1dc8418c21db.h"
#include "common/types_8fd754e1e915.h"
#include "span_1000/code_80268160.h"
#include "types.h"
#include "common/unused.h"

/* Effect callback that fires only near an object's height: when the event's height lies within D_800C9564 below or D_800C9560 above the object's y at 0xC, it forwards the event to func_80266810_de with mode 1 and flags 0x200. */







extern void func_80266810_de(char *, s32, s32, Triple_func_802683E0_de, struct Shape_func_802764D4_de_2, s32, s32, s32);

static inline void fire(char *arg0, s32 arg1, s32 arg2, Triple_func_802683E0_de arg3, struct Shape_func_802764D4_de_2 arg6)
{
    func_80266810_de(arg0, arg1, arg2, arg3, arg6, 1, 0, 0x200);
}




void func_802683E0_de(char *arg0, s32 arg1, s32 arg2, Triple_func_802683E0_de arg3, struct Shape_func_802764D4_de_2 arg6)
{
    Actor_func_8024A7A0_de *actor = (Actor_func_8024A7A0_de *)arg0;
    f32 d = actor->position0.y - arg3.y;

    if (d < 0.0f ? -d <= D_800C9560 : d <= D_800C9564) {
        fire(arg0, arg1, arg2, arg3, arg6);
    }
}
