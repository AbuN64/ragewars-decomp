#include "span_1000/code_8022C894.h"
#include "common/types_06e4f7ef1f9e.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "common/types_8fd754e1e915.h"
#include "shared/gameplay_movement.h"
#include "shared/gameplay_transition.h"
#include "shared/level_actor.h"
#include "shared/world.h"
#include "span_1000/code_8022D944.h"
#include "span_C76B0/data.h"
#include "types.h"
#include "span_1000/code_8022E938.h"

/* Eases a player's crouch depth at 0x718: the target is D_800C7ED0[0] while input bits 0xC0000 are
   held or crouching is forced at 0x71C (which also enters state 4 unless already in it) and zero
   otherwise; the depth moves a quarter of the way through func_80274870_de, steps smaller than
   D_800C7ED0[1] downward or D_800C7ED8[0] upward are dropped, and bit 0x80 of the flags is set while
   D_800C7ED8[1] less the depth lies within D_800C7EE0 to (&D_800C7EE0)[1], cleared otherwise. */



extern s32 func_802227F4_de(void *, void *, s32);



extern f32 func_8024E464_de(void *arg0);



struct MotionSurface;
extern s32 func_8024491C_de(void *arg0, Vec3 arg1, Vec3 arg2, struct MotionSurface *arg3,
                         f32 arg4, f32 arg5, f32 arg6, f32 arg7);

extern char D_80103FCC[];

/* Updates a player's charge effect: cancels the charge and moves its effect to state 3 when the
   current weapon's entry in D_800D052C has no ammunition, the charge is off, or D_801468F4 is set with
   the player's controller flag at 0x8F; while the button at 0x5E4 is held and charging it targets
   D_800C7EF4, then runs the effect through func_80219480_de, eases the level toward the target by half
   through func_80274870_de and clears a level below D_800C7EF8 once the target is zero. */



extern void func_80219480_de(void *, void *);


/* Returns whether the entry func_8028B2F8_de finds in D_8011FE88 for an object's key at 0x14 exists
   and has bit 6 of its flags at 0x52 set. */





extern struct Entry_func_8022E130_de *func_8028B2F8_de(Shared_World *, s32);

/* Returns the constant after D_800C7EC0 less the cube of its difference from the argument. */






f32 func_8022DBC4_de(f32 arg0) {
    f32 temp = D_800C2DD4_de - arg0;
    return D_800C2DD4_de - (temp * temp * temp);
}

void func_8022DBE4_de(Player *arg0) {
    float temp = arg0->state708;
    float k = D_800C7EC8;
    arg0->state714 = 0;
    arg0->state70C = temp;
    arg0->state710 = k;
}

void func_8022DC00_de(Player *arg0) {
    float temp = arg0->state708;
    arg0->state710 = 0;
    arg0->state714 = 0;
    arg0->state70C = temp;
}

/** Perform the no-op hook at VRAM 0x8022DC04. */
void func_8022DC14_de(void) {
}

/* Reports whether the object's float at 0x718 is above the constant after D_800C7EC8. */








s32 func_8022DC1C_de(Shared_ActorView *arg0) {
    f32 field = arg0->speed;
    f32 konst = D_800C2DDC_de;
    s32 result = 1;
    if (!(konst < field)) {
        result = 0;
    }
    return result;
}

void func_8022DC44_de(Player *arg0, LevelActor *arg1, s32 unused, s32 *flags) {
    s32 held;
    s32 crouch;
    f32 target;
    f32 depth;
    f32 step;
    f32 clearance;
    f32 moved;
    f32 lo;

    held = arg1->motionState & 0xC0000;
    crouch = held != 0;
    if (arg0->forceCrouch != 0) {
        crouch = 1;
        if (arg0->pose != 4) {
            func_802227F4_de(arg0, arg1, 4);
        }
    }
    target = 0.0f;
    if (crouch) {
        target = D_800C7ED0[0];
    }
    depth = arg0->crouchDepth;
    func_80274870_de(&depth, target, 0.25f);
    do {
        step = depth - arg0->crouchDepth;
        if (step < 0.0f) {
            if (-step < D_800C7ED0[1]) {
                goto still;
            }
        } else if (step < D_800C7ED8[0]) {
        still:
            step = 0.0f;
        }
        moved = arg0->crouchDepth + step;
        clearance = D_800C7ED8[1] - moved;
        lo = D_800C7EE0;
    } while (0);
    arg0->crouchDepth = moved;
    if (lo <= clearance && clearance <= (&D_800C7EE0)[1]) {
        *flags |= 0x80;
    } else {
        *flags &= ~0x80;
    }
}

void func_8022DD94_de(Shared_ActorView *arg0) {
    f32 sp10;
    f32 var_f1;
    f32 var_f2;

    var_f1 = 0.0f;
    if ((u32)((u16)arg0->action - 9) < 4U) {
        var_f1 = D_800C2DF8_de[0];
    }
    sp10 = arg0->transitionBlend;
    func_80274870_de(&sp10, var_f1, 0.25f);
    var_f2 = sp10 - arg0->transitionBlend;
    if (var_f2 < 0.0f) {
        if (-var_f2 < D_800C2DF8_de[1]) {
            goto clamp;
        }
    } else if (var_f2 < D_800C2E00_de) {
clamp:
        var_f2 = 0.0f;
    }
    arg0->transitionBlend = arg0->transitionBlend + var_f2;
}

void func_8022DE58_de(Player *arg0, LevelActor *arg1) {
    Vec3 next;
    f32 temp_f0;
    f32 temp_f1;
    f32 temp_f20;
    f32 temp_f21;
    f32 temp_f22;
    f32 var_f23;

    var_f23 = (((((ModelBlend *)(arg0->definition))->height -
                    arg0->cameraOffset) -
                   arg0->crouchDepth) -
                  arg0->eyeOffset) -
                 arg0->heightDelta;
    if (var_f23 > 0.0f) {
        temp_f22 = func_8024E464_de(arg1);
        temp_f21 = func_8024D398_de(arg1);
        temp_f20 = func_8024D284_de(arg1);
        temp_f0 = func_8024E420_de(arg1);
        next.x = arg1->position0.x;
        next.y = arg1->position0.y + var_f23;
        next.z = arg1->position0.z;
        if (func_8024491C_de(arg1, arg1->position0, next,
                           &D_801000F0, temp_f22, temp_f21, temp_f20,
                           temp_f0) != 0) {
            temp_f1 = ((Shared_Floor *)(*(void **)D_80103FCC))->y -
                      arg1->position0.y;
            arg0->previousPosition.y -= var_f23 - temp_f1;
            var_f23 = temp_f1;
        }
    }
    arg0->heightDelta += var_f23;
}

void func_8022DFA8_de(void *arg0) {
    f32 target;
    char *effect;
    s32 state;

    target = 0.0f;
    effect = &((ObjectLinks87C *)(arg0))->unk_878;
    if (((struct Shape_typemap_14 *)(D_800D052C[((ObjectLinks87C *)(arg0))->unk_62E]))->field_8 <= 0
        || ((ObjectLinks87C *)(arg0))->unk_7E8 == 0
        || (D_801468F4 != 0 && ((struct ObjRecAt8F *) ((ObjectLinks87C *) arg0)->unk_5D8)->unk8F != 0)) {
        do {
            ((ObjectLinks87C *)(arg0))->unk_7E8 = 0;
            state = ((Shared_Effect *)(effect))->state;
        } while (0);
        if (state != 0 && state != 3) {
            ((Shared_Effect *)(effect))->state = 3;
        }
    }
    if (((ObjectLinks87C *)(arg0))->unk_5E4 != 0 && ((ObjectLinks87C *)(arg0))->unk_7E8 != 0) {
        target = D_800C7EF4;
        ((ObjectLinks87C *)(arg0))->unk_7E8 = 1;
    }
    ((ObjectLinks87C *)(arg0))->unk_7F0 = target;
    func_80219480_de(&((ObjectLinks87C *)(arg0))->unk_878, arg0);
    func_80274870_de(&((ObjectLinks87C *)(arg0))->unk_7EC, target, 0.5f);
    if (target == 0.0f && ((ObjectLinks87C *)(arg0))->unk_7EC < D_800C7EF8) {
        ((ObjectLinks87C *)(arg0))->unk_7EC = 0.0f;
    }
}

void func_8022E0B0_de(void *arg0, void *arg1) {
    ObjRecAt1AV1 *range;
    ObjRecAt724 *actor;
    s32 value;
    f32 amount;

    ObjRecAt1CV2 *event = arg1;
    ObjRecAt1D8V1 *object;

    range = event->unk1C;
    value = event->unk4;
    if (value < range->unk18) {
        return;
    }
    if (range->unk19 < value) {
        return;
    }

    object = event->unk8;
    actor = object->unk1D8;
    amount = -actor->unk724;
    if (actor->unk650 == 0xF) {
        amount += D_800C2E0C_de;
    }
    func_802738C0_de(arg0, amount / (f32)range->unk1A);
}

s32 func_8022E130_de(struct func_80204468_S3 *object) {
    struct Entry_func_8022E130_de *entry;

    if (object->unk14 != 0) {
        entry = func_8028B2F8_de(&D_8011FE88, object->unk14);
        if (entry != 0 && (entry->flags & 0x40)) {
            return 1;
        }
    }
    return 0;
}
