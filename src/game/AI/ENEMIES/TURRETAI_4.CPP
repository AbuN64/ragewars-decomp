#include "COMMON/EXTERNS_15.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/LEVEL_ACTOR.H"
#include "COMMON/WORLD.H"
#include "COMMON/OBJ.H"
#include "COMMON/REC.H"
#include "TYPES.H"
#include "WEAPONS/80213ED4.H"

extern s32 Turret_TrackTarget(void *arg0);


extern s32 Weapons_SpawnFlaggedEffects(void *arg0, void *arg1, s32 arg2, s32 arg3, s32 arg4);

extern void Rumble_SetActorStateBit(Shared_World *, void *, s32);

extern void func_80278D78_de(void *arg0, s32 arg1, void *arg2);

s32 AnimPool_ReleaseSceneEffect(void *);

extern s32 Rumble_TestActorStateBit(void *, void *);

void Turret_Code_IDLE(void *actor, void *state) {
    if (Turret_TrackTarget(actor) != 0) {
        Weapons_RequestActorState(actor, state, 0x3F);
    }
}

void Turret_Code_FIRE(void *actor, void *state) {
    if (Turret_TrackTarget(actor) == 0) {
        Weapons_RequestActorState(actor, state, 0x3E);
    }
}

void Turret_Setup_DEATH(void *actor, void *state) {
    LevelActor *actorView = actor;
    ActorMotionState *stateView = state;
    ActorMotionDefinition *motion;
    s32 clearedFlags;
    Shared_World *world;

    motion = &((ActorMotionResource *)actorView->definition)->motion;
    Weapons_SpawnFlaggedEffects(actor, state, 4, motion->eventMask, motion->secondaryEventMask);
    world = &g_world;
    stateView->event = 0;
    Rumble_SetActorStateBit(world, actor, 1);
    func_80278D78_de(actor, 1, actor);
    clearedFlags = actorView->flags & 0xFFFEFFFF;
    actorView->flags = clearedFlags;
    if (world->mode != 4) {
        actorView->flags = clearedFlags | 0x08000000;
    }
}

void Turret_Code_DEATH(LevelActor *actor, ActorMotionState *state) {
    if ((state->actionPending != 0) && (actor->flags & 0x80000)) {
        AnimPool_ReleaseSceneEffect(actor);
    }
}

void Turret_LinkEffect_MakeVisible(Shared_Actor *actor) {
    if (Rumble_TestActorStateBit(&g_world, actor) == 0) {
        actor->weaponFlags |= 0x2100;
    }
}
