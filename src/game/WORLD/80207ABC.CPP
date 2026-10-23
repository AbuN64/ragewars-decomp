#include "include_asm.h"
#include "WORLD/INTEGERSTATE170.H"
#include "COMMON/AUDIO_CALLBACKS.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/LEVEL_ACTOR.H"
#include "COMMON/WORLD.H"
#include "COMMON/REC.H"
#include "TYPES.H"
#include "COMMON/EXTERNS_6.H"
#include "WORLD/80207ABC.H"
#include "WEAPONS/80213ED4.H"

typedef struct Owner Owner;

extern void func_80278D78_de(void *arg0, s32 arg1, void *arg2);


extern void func_80285DB0_de(Shared_World *, void *, s32);

extern void func_8028B670_de(void *a, unsigned short b, unsigned short c, int d);

void func_80207ABC_de(void *object, void *state) {
    Player *arg0 = object;
    ActorMotionState *arg1 = state;
    s32 temp_a2;
    ActorMotionResource *resource;
    ActorMotionDefinition *temp_a3;
    s32 var_v1;
    s32 temp_v0;

    resource = arg0->definition;
    temp_a3 = &resource->motion;
    temp_a2 = temp_a3->transitionFlags;
    var_v1 = 1;
    if (temp_a2 & 0x10) {
        temp_v0 = arg1->flags & 0x10000;
        var_v1 = (u32)0 < (u32)temp_v0;
    }
    if ((temp_a2 & 0x100) && !(arg0->movementFlags & 0x40)) {
        var_v1 = 0;
    }
    if ((temp_a3->transitionFlags & 0x400) && (arg0->movementFlags & 0x40)) {
        var_v1 = 0;
    }
    if (var_v1 != 0) {
        if (arg1->timer >= temp_a3->openThreshold) {
            func_80214178_de(arg0, arg1, 1);
        }
    } else {
        arg1->timer = 0.0f;
    }
}

void func_80207B5C_de(void *object, u32 *arg1) {
    Player *arg0 = object;
    ActorMotionResource *resource;
    ActorMotionDefinition *temp_s0;

    resource = arg0->definition;
    temp_s0 = &resource->motion;
    func_80278D78_de(arg0, 0x10000, arg0);
    if (!(temp_s0->transitionFlags & 0x40)) {
        *arg1 &= 0xFFFEFFFF;
    }
}

void func_80207BB8_de(void *object, void *state) {
    Player *arg0 = object;
    ActorMotionState *arg1 = state;
    ActorMotionResource *resource;
    ActorMotionDefinition *temp_a3;
    s32 temp_a2;
    s32 var_v1;

    resource = arg0->definition;
    temp_a3 = &resource->motion;
    temp_a2 = temp_a3->transitionFlags;
    var_v1 = 1;
    if (temp_a2 & 0x10000) {
        var_v1 = (u32)(arg0->movementFlags & 0x40) < (u32)var_v1;
    }
    if ((temp_a2 & 0x4000) && !(arg0->movementFlags & 0x40)) {
        var_v1 = 0;
    }
    if (arg0->movementFlags & 8) {
        var_v1 = 0;
    }
    if (var_v1 != 0) {
        arg1->speed = arg1->speed + (D_800D2988 / temp_a3->transitionTime);
    }
    if (arg1->speed >= D_800C1BA0_de) {
        func_80214178_de(arg0, arg1, 2);
    }
}

void func_80207C68_de(void *arg0, s32 *arg1) {
    if (!((((struct func_8020D1FC_S1 *) ((s8 *) ((struct ObjRecAt18V5 *) ((s8 *) arg0))->unk18))->unk38) & 0x80)) {
        *arg1 &= 0xFFFDFFFF;
    }
}

void func_80207C94_de(void *object, void *state) {
    Player *arg0 = object;
    ActorMotionState *arg1 = state;
    s32 temp_a2;
    ActorMotionResource *resource;
    ActorMotionDefinition *temp_a3;
    s32 var_v1;
    s32 temp_v0;

    resource = arg0->definition;
    temp_a3 = &resource->motion;
    temp_a2 = temp_a3->transitionFlags;
    var_v1 = 1;
    if (temp_a2 & 0x20) {
        temp_v0 = arg1->flags & 0x20000;
        var_v1 = (u32)0 < (u32)temp_v0;
    }
    if ((temp_a2 & 0x200) && !(arg0->movementFlags & 0x40)) {
        var_v1 = 0;
    }
    if ((temp_a3->transitionFlags & 0x800) && (arg0->movementFlags & 0x40)) {
        var_v1 = 0;
    }
    if (var_v1 != 0) {
        if (arg1->timer >= temp_a3->closeThreshold) {
            func_80214178_de(arg0, arg1, 3);
        }
    } else {
        arg1->timer = 0.0f;
    }
}

void func_80207D34_de(void *object, u32 *arg1) {
    Player *arg0 = object;
    ActorMotionResource *resource;
    ActorMotionDefinition *temp_s0;

    resource = arg0->definition;
    temp_s0 = &resource->motion;
    func_80278D78_de(arg0, 0x20000, arg0);
    if (!(temp_s0->transitionFlags & 0x80)) {
        *arg1 &= 0xFFFDFFFF;
    }
}

void func_80207D90_de(void *object, void *state) {
    Player *arg0 = object;
    ActorMotionState *arg1 = state;
    ActorMotionResource *resource;
    ActorMotionDefinition *temp_a3;
    s32 temp_a2;
    s32 var_v1;

    resource = arg0->definition;
    temp_a3 = &resource->motion;
    temp_a2 = temp_a3->transitionFlags;
    var_v1 = 1;
    if (temp_a2 & 0x20000) {
        var_v1 = (u32)(arg0->movementFlags & 0x40) < (u32)var_v1;
    }
    if ((temp_a2 & 0x8000) && !(arg0->movementFlags & 0x40)) {
        var_v1 = 0;
    }
    if (arg0->movementFlags & 8) {
        var_v1 = 0;
    }
    if (var_v1 != 0) {
        arg1->speed = arg1->speed - (D_800D2988 / temp_a3->transitionTime);
    }
    if (arg1->speed <= 0.0f) {
        func_80214178_de(arg0, arg1, 0);
    }
}

void func_80207E3C_de(struct Shared_Actor *arg0, int *arg1) {
    arg0->weaponFlags |= 0x2100;
    *arg1 |= 0x10000;
    func_80214178_de(arg0, arg1, 1);
}

void func_80207E74_de(struct Shared_Actor *arg0, int *arg1) {
    arg0->weaponFlags |= 0x2100;
    *arg1 |= 0x20000;
    func_80214178_de(arg0, arg1, 3);
}

void func_80207EAC_de(struct Shared_Actor *arg0) {
    func_80285DB0_de(&D_8011FE88, arg0, 1);
    arg0->weaponFlags |= 0x100;
}

void func_80207EEC_de(void *event) {
    ActorMotionEvent *arg0 = event;
    func_8028B670_de(&D_8011FE88, arg0->id, arg0->key, 1);
}

void func_80207F1C_de(struct Shared_Actor *arg0) {
    func_80285DB0_de(&D_8011FE88, arg0, 0);
    arg0->weaponFlags &= ~0x100;
}

void func_80207F60_de(void *event) {
    ActorMotionEvent *arg0 = event;
    func_8028B670_de(&D_8011FE88, arg0->id, arg0->key, 0);
}

/** Set flags 0x2100 in the word at offset 0x100. */
void func_80207F90_de(void *object) {
    Player *arg0 = object;
    arg0->weaponFlags |= 0x2100;
}

void func_80207FA0_de(LevelActor *arg0, ActorMotionState *arg1) {
    arg1->flags = (s32) (arg1->flags | 0x10000);
    arg0->flags = (s32) (arg0->flags | 0x2100);
    arg1->unk16C = 0;
}

/** Set the fixed flags on the supplied object and word. */
void func_80207FC4_de(char *object, unsigned int *flags) {
    Player *actor = (void *)object;
    *flags |= 0x20000;
    actor->weaponFlags |= 0x2100;
}

              /* size 0x0 */

s32 func_80207FE4_de(void *arg0) {
    Player *actor = arg0;
    s32 temp_v0;

    temp_v0 = actor->weaponFlags & ~0x2000;
    actor->weaponFlags = temp_v0;
    return temp_v0;
}

#if defined(VERSION_EU_X)
unsigned int func_80207FE4_de_padding_8C18[1] = {
    0x00000000,
};
#endif

#if defined(VERSION_DE)
unsigned int rodata_unresolved_80207FF8[2] = {
    0x428DA56D, 0x4312CABA,
};
#endif
