#include "COMMON/GAMEPLAY_TRANSITION.H"
#include "COMMON/LEVEL_ACTOR.H"
#include "COMMON/INTEGERSTATE1250.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/UNUSED.H"
#include "TYPES.H"
#include "RENDER_2/S1.H"

/* Decreases a float field at offset 0x12C0 by the given amount, clamps it from below at a floor, and when it reaches the floor builds and dispatches an event. Adapted from func_8022B60C_de, with the add, the clamp direction, the constant, the third argument (a field plus 0x1900), and a duplicated clamp assignment (which keeps the constant reloaded rather than held in a register) changed. */

extern void Weapons_FillDamagePacket(void *arg0, void *arg1, s32 arg2, f32 arg3, s32 arg4, s32 arg5);
extern void func_80219A40_de(void *arg0, void *arg1, void *arg2);






void func_8022B69C_de(void *actor, f32 arg1, void *arg2) {
    Slot damage;
    f32 temp_f0;
    f32 temp_f1;

    temp_f0 = ((Shared_ActorView *)actor)->reserve - arg1;
    temp_f1 = D_800C9190_de[1];
    if (!(temp_f0 <= temp_f1)) {
        if (actor != 0) {
            temp_f1 = temp_f0;
        } else {
            temp_f1 = temp_f0;
        }
    }
    temp_f0 = D_800C9190_de[1];
    ((Shared_ActorView *)actor)->reserve = temp_f1;
    if (temp_f1 <= temp_f0) {
        Weapons_FillDamagePacket(&damage, arg2, ((LevelActor *)actor)->active + 0x1900, 25.599998f, 0x80, 0);
        func_80219A40_de(actor, &((LevelActor *)actor)->behaviorFlags, &damage);
    }
}

/** Adds the argument scaled by D_800C7E08 to the object's float at 0x11DC and sets bit 0x2000 in its word at 0x122C. */






void func_8022B730_de(void *actorView, f32 arg1) {
    ((Shared_ActorView *)actorView)->impulse = ((Shared_ActorView *)actorView)->impulse + arg1 * D_800C7E08;
    ((Shared_ActorView *)actorView)->field122C = ((Shared_ActorView *)actorView)->field122C | 0x2000;
}
