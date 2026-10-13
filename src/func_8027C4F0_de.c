#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_8027A0F4.h"
#include "types.h"
/* Picks an animation slot from a global mode, then plays the slot's effect, spawns its object at the owner or a fixed position, plays its sound, and flags the owner. Adapted from func_8027C9CC_de, with the slot chosen by a switch on D_801042C4 (the extra case below 7 that shares the default body is needed for the decision tree; its value is not recoverable), the constant triple, one argument, the dropped func_80271F9C_de call, and the final test changed. */





extern Triple D_801002B8;
extern Vec3 D_801042C8;
extern char D_8011D8D0;

extern void func_80265E10_de(void *, void *, s32, s32, Triple, struct Shape_func_802764D4_de_2);
extern void func_80271818_de(struct Shape_typemap_165 *, Vec3 *);
extern s32 func_802800C0_de(void *, void *, void *, s32, s32, s32, Vec3, struct Shape_typemap_165, Triple, s32, s32, s32);
extern s32 func_8025DE54_de(s16, s32, s32, s32, s32, s32);
extern void func_80284570_de(void *, void *);










void func_8027C4F0_de(Shared_Particle *arg0) {
    struct Shape_func_802764D4_de_2 pair;
    struct Shape_typemap_165 rotation;
    Vec3 position;
    s32 temp_a1;
    struct Shared_ParticleEvents *temp_v0;
    s32 var_a0;
    s32 temp_a2;
    s32 temp_s2;
    s32 sound;
    struct Shared_ParticleDesc *temp_s1;
    struct Shape_func_802764D4_de_2 *temp_v0_2;

    switch (D_801042C4) {
    case 1:
    default:
        var_a0 = 1;
        break;
    case 7:
        var_a0 = 7;
        break;
    case 8:
        var_a0 = 8;
        break;
    }
    temp_s1 = arg0->desc;
    temp_a1 = var_a0;
    temp_v0 = temp_s1->events;
    temp_s2 = temp_v0->particles[temp_a1];
    temp_a2 = temp_v0->effects[temp_a1];
    temp_v0_2 = &temp_v0->parameters[var_a0];
    pair = *temp_v0_2;
    sound = temp_s1->events->sounds[temp_a1];
    if (temp_a2 != 0xFFFF) {
        func_80265E10_de(arg0, arg0, temp_a2, -1, D_801002B8, pair);
    }
    if (temp_s2 != 0xFFFF) {
        if ((arg0->desc->flags & 0x10) != 0) {
            position = D_801042C8;
        } else {
            position = arg0->inst.velocity;
        }
        func_80271818_de(&rotation, &position);
        func_802800C0_de(&D_8011D8D0, arg0,
                      arg0->owner,
                      arg0->ownerId,
                      (s32)arg0->target, temp_s2,
                      position, rotation, D_801002B8, 0,
                      -5,
                      (arg0->flags & 0x200006) | 1);
    }
    if (sound != 0xFFFF) {
        func_8025DE54_de((s16)sound, D_801002B8.x,
                      D_801002B8.y, D_801002B8.z, 0, -1);
    }
    arg0->flags |= 0x200;
    if ((arg0->desc->flags & 0x20000) != 0) {
        func_80284570_de(&D_8011D8D0, arg0);
        func_80284434_de(arg0);
    }
}
