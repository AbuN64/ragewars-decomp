#include "shared/gameplay_transition.h"
#include "shared/level_actor.h"
#include "span_1000/code_8022AE90.h"
#include "common/types_1dc8418c21db.h"
#include "common/unused.h"
#include "types.h"
#include "shared/func_8022B69C_de_layout.h"

/* Decreases a float field at offset 0x12C0 by the given amount, clamps it from below at a floor, and when it reaches the floor builds and dispatches an event. Adapted from func_8022B60C_de, with the add, the clamp direction, the constant, the third argument (a field plus 0x1900), and a duplicated clamp assignment (which keeps the constant reloaded rather than held in a register) changed. */

extern void func_80216488_de(void *arg0, void *arg1, s32 arg2, f32 arg3, s32 arg4, s32 arg5);
extern void func_80219A40_de(void *arg0, void *arg1, void *arg2);






void func_8022B69C_de(void *arg0, f32 arg1, void *arg2) {
    Slot sp18;
    f32 temp_f0;
    f32 temp_f1;

    temp_f0 = ((Shared_ActorView *)arg0)->reserve - arg1;
    temp_f1 = D_800C9190_de[1];
    if (!(temp_f0 <= temp_f1)) {
        if (arg0 != 0) {
            temp_f1 = temp_f0;
        } else {
            temp_f1 = temp_f0;
        }
    }
    temp_f0 = D_800C9190_de[1];
    ((Shared_ActorView *)arg0)->reserve = temp_f1;
    if (temp_f1 <= temp_f0) {
        func_80216488_de(&sp18, arg2, ((LevelActor *)arg0)->active + 0x1900, 25.599998f, 0x80, 0);
        func_80219A40_de(arg0, &((LevelActor *)arg0)->behaviorFlags, &sp18);
    }
}

/** Adds the argument scaled by D_800C7E08 to the object's float at 0x11DC and sets bit 0x2000 in its word at 0x122C. */






void func_8022B730_de(void *arg0, f32 arg1) {
    ((Shared_ActorView *)arg0)->impulse = ((Shared_ActorView *)arg0)->impulse + arg1 * D_800C7E08;
    ((Shared_ActorView *)arg0)->field122C = ((Shared_ActorView *)arg0)->field122C | 0x2000;
}
