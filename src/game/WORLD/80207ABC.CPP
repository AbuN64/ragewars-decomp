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


extern void Render_SetActorStateBit(Shared_World *, void *, s32);

extern void func_8028B670_de(void *a, unsigned short b, unsigned short c, int d);

void func_80207ABC_de(void *object, void *state) {
    Player *player = object;
    ActorMotionState *motionState = state;
    s32 transitionFlags;
    ActorMotionResource *resource;
    ActorMotionDefinition *motionDefinition;
    s32 transitionAllowed;
    s32 requiredStateFlag;

    resource = player->definition;
    motionDefinition = &resource->motion;
    transitionFlags = motionDefinition->transitionFlags;
    transitionAllowed = 1;
    if (transitionFlags & 0x10) {
        requiredStateFlag = motionState->flags & 0x10000;
        transitionAllowed = (u32)0 < (u32)requiredStateFlag;
    }
    if ((transitionFlags & 0x100) && !(player->movementFlags & 0x40)) {
        transitionAllowed = 0;
    }
    if ((motionDefinition->transitionFlags & 0x400) && (player->movementFlags & 0x40)) {
        transitionAllowed = 0;
    }
    if (transitionAllowed != 0) {
        if (motionState->timer >= motionDefinition->openThreshold) {
            Weapons_RequestActorState(player, motionState, 1);
        }
    } else {
        motionState->timer = 0.0f;
    }
}

void func_80207B5C_de(void *object, u32 *stateFlags) {
    Player *player = object;
    ActorMotionResource *resource;
    ActorMotionDefinition *motionDefinition;

    resource = player->definition;
    motionDefinition = &resource->motion;
    func_80278D78_de(player, 0x10000, player);
    if (!(motionDefinition->transitionFlags & 0x40)) {
        *stateFlags &= 0xFFFEFFFF;
    }
}

void func_80207BB8_de(void *object, void *state) {
    Player *player = object;
    ActorMotionState *motionState = state;
    ActorMotionResource *resource;
    ActorMotionDefinition *motionDefinition;
    s32 transitionFlags;
    s32 progressAllowed;

    resource = player->definition;
    motionDefinition = &resource->motion;
    transitionFlags = motionDefinition->transitionFlags;
    progressAllowed = 1;
    if (transitionFlags & 0x10000) {
        progressAllowed = (u32)(player->movementFlags & 0x40) < (u32)progressAllowed;
    }
    if ((transitionFlags & 0x4000) && !(player->movementFlags & 0x40)) {
        progressAllowed = 0;
    }
    if (player->movementFlags & 8) {
        progressAllowed = 0;
    }
    if (progressAllowed != 0) {
        motionState->speed = motionState->speed + (D_800D2988 / motionDefinition->transitionTime);
    }
    if (motionState->speed >= D_800C1BA0_de) {
        Weapons_RequestActorState(player, motionState, 2);
    }
}

void func_80207C68_de(void *actor, s32 *stateFlags) {
    if (!((((struct func_8020D1FC_S1 *) ((s8 *) ((struct ObjRecAt18V5 *) ((s8 *) actor))->unk18))->unk38) & 0x80)) {
        *stateFlags &= 0xFFFDFFFF;
    }
}

void func_80207C94_de(void *object, void *state) {
    Player *player = object;
    ActorMotionState *motionState = state;
    s32 transitionFlags;
    ActorMotionResource *resource;
    ActorMotionDefinition *motionDefinition;
    s32 transitionAllowed;
    s32 requiredCloseFlag;

    resource = player->definition;
    motionDefinition = &resource->motion;
    transitionFlags = motionDefinition->transitionFlags;
    transitionAllowed = 1;
    if (transitionFlags & 0x20) {
        requiredCloseFlag = motionState->flags & 0x20000;
        transitionAllowed = (u32)0 < (u32)requiredCloseFlag;
    }
    if ((transitionFlags & 0x200) && !(player->movementFlags & 0x40)) {
        transitionAllowed = 0;
    }
    if ((motionDefinition->transitionFlags & 0x800) && (player->movementFlags & 0x40)) {
        transitionAllowed = 0;
    }
    if (transitionAllowed != 0) {
        if (motionState->timer >= motionDefinition->closeThreshold) {
            Weapons_RequestActorState(player, motionState, 3);
        }
    } else {
        motionState->timer = 0.0f;
    }
}

void func_80207D34_de(void *object, u32 *stateFlags) {
    Player *player = object;
    ActorMotionResource *resource;
    ActorMotionDefinition *motionDefinition;

    resource = player->definition;
    motionDefinition = &resource->motion;
    func_80278D78_de(player, 0x20000, player);
    if (!(motionDefinition->transitionFlags & 0x80)) {
        *stateFlags &= 0xFFFDFFFF;
    }
}

void func_80207D90_de(void *object, void *state) {
    Player *player = object;
    ActorMotionState *motionState = state;
    ActorMotionResource *resource;
    ActorMotionDefinition *motionDefinition;
    s32 transitionFlags;
    s32 progressAllowed;

    resource = player->definition;
    motionDefinition = &resource->motion;
    transitionFlags = motionDefinition->transitionFlags;
    progressAllowed = 1;
    if (transitionFlags & 0x20000) {
        progressAllowed = (u32)(player->movementFlags & 0x40) < (u32)progressAllowed;
    }
    if ((transitionFlags & 0x8000) && !(player->movementFlags & 0x40)) {
        progressAllowed = 0;
    }
    if (player->movementFlags & 8) {
        progressAllowed = 0;
    }
    if (progressAllowed != 0) {
        motionState->speed = motionState->speed - (D_800D2988 / motionDefinition->transitionTime);
    }
    if (motionState->speed <= 0.0f) {
        Weapons_RequestActorState(player, motionState, 0);
    }
}

void func_80207E3C_de(struct Shared_Actor *actor, int *motionFlags) {
    actor->weaponFlags |= 0x2100;
    *motionFlags |= 0x10000;
    Weapons_RequestActorState(actor, motionFlags, 1);
}

void func_80207E74_de(struct Shared_Actor *actor, int *motionFlags) {
    actor->weaponFlags |= 0x2100;
    *motionFlags |= 0x20000;
    Weapons_RequestActorState(actor, motionFlags, 3);
}

void func_80207EAC_de(struct Shared_Actor *actor) {
    Render_SetActorStateBit(&g_world, actor, 1);
    actor->weaponFlags |= 0x100;
}

void func_80207EEC_de(void *event) {
    ActorMotionEvent *actorMotionEvent = event;
    func_8028B670_de(&g_world, actorMotionEvent->id, actorMotionEvent->key, 1);
}

void func_80207F1C_de(struct Shared_Actor *actor) {
    Render_SetActorStateBit(&g_world, actor, 0);
    actor->weaponFlags &= ~0x100;
}

void func_80207F60_de(void *event) {
    ActorMotionEvent *actorMotionEvent = event;
    func_8028B670_de(&g_world, actorMotionEvent->id, actorMotionEvent->key, 0);
}

/** Set flags 0x2100 in the word at offset 0x100. */
void func_80207F90_de(void *object) {
    Player *player = object;
    player->weaponFlags |= 0x2100;
}

void func_80207FA0_de(LevelActor *actor, ActorMotionState *motionState) {
    motionState->flags = (s32) (motionState->flags | 0x10000);
    actor->flags = (s32) (actor->flags | 0x2100);
    motionState->unk16C = 0;
}

/** Set the fixed flags on the supplied object and word. */
void func_80207FC4_de(char *object, unsigned int *flags) {
    Player *actor = (void *)object;
    *flags |= 0x20000;
    actor->weaponFlags |= 0x2100;
}

              /* size 0x0 */

s32 func_80207FE4_de(void *player) {
    Player *actor = player;
    s32 updatedFlags;

    updatedFlags = actor->weaponFlags & ~0x2000;
    actor->weaponFlags = updatedFlags;
    return updatedFlags;
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
