#include "include_asm.h"
#include "COMMON/UNUSED.H"
#include "COMMON/TRIPLE.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/INTEGERSTATE1250.H"
#include "RENDER_2/8022AE90.H"
#include "TYPES.H"

f32 func_80274808_de(f32, f32, s32);

void func_8022B5C0_de(void *arg0) {
    if ((((struct ObjectState12C4 *) ((s8 *) arg0))->unk_5E4) != 0) {
        (((struct ObjectState12C4 *) ((s8 *) arg0))->unk_12C0) = func_80274808_de((((struct ObjectState12C4 *) ((s8 *) arg0))->unk_12C0), D_800C2D14_de, D_800C9FF0);
    }
}

#include "COMMON/GAMEPLAY_REACTIONS.H"
#include "RENDER_2/802192C0.H"
extern void func_80216488_de(Shared_ReactionInteraction *, s32, s32, f32, s32, s32);

void func_8022B60C_de(Shared_ReactionPlayer *actor, f32 amount, s32 source) {
    Shared_ReactionInteraction packet;
    f32 value;
    f32 limited;
    value = actor->reserve + amount;
    limited = gReactionReserveMaximum;
    if (!(limited <= value)) {
        limited = value;
    }
    actor->reserve = limited;
    if (gReactionReserveMaximum <= limited) {
        func_80216488_de(&packet, source, 0x40000, 25.599998f, 0x80, 0);
        func_80219A40_de((Shared_ReactionActor *)actor, &actor->unk170, &packet);
    }
}
