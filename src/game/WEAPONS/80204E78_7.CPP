#include "COMMON/ANIMATIONTRIGGERDEFINITION.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/LEVEL_ACTOR.H"
#include "COMMON/WORLD.H"
#include "COMMON/OBJ.H"
#include "COMMON/REC.H"
#include "TYPES.H"
#include "WEAPONS/80213ED4.H"

extern s32 D_801462C8;

extern int Rumble_TestActorStateBit(char *a, int b);

extern void Rumble_SetActorStateBit(Shared_World *a, void *b, int c);

void func_80206080_de(void *levelActor, void *actorMotionState) {
    LevelActor *actor = levelActor;
    ActorMotionState *motion = actorMotionState;
    AnimationTriggerResource *resource;
    AnimationTriggerDefinition *base;
    char *ctx;
    f32 result;
    s32 count;
    s32 delayPercent;
    f64 unsignedDelayPercent;
    f32 scaled;

    resource = (void *)actor->definition;
    base = &resource->trigger;
    result = GraphU64_RandomBetween(base->delayMinimum, base->delayMaximum);
    motion->speed = result;
    ctx = (char *) &D_801462C8;
    if (((ObjectState1E_2 *)(ctx))->unk_1D != 0) {
        count = *(s32 *) (ctx - 0x1258);
        if ((u32) count >= 3) {
            count -= 2;
            scaled = result * D_800C1AD0_de;
            delayPercent = 0x64 - count * 25;
            unsignedDelayPercent = (f64) delayPercent;
            if (delayPercent < 0) {
                unsignedDelayPercent += (4294967296.0);
            }
            motion->speed = scaled * (f32) unsignedDelayPercent;
        }
    }
}

void func_8020612C_de(LevelActor *actor, ActorMotionState *motionState) {
    AnimationTriggerResource *definition;
    AnimationTriggerDefinition *triggerDefinition;
    s32 flags;
    s32 interactionGuard;

    definition = (void *)actor->definition;
    triggerDefinition = &definition->trigger;
    if (triggerDefinition->enabled == 0) {
        if (triggerDefinition->firstAnimation == -1) {
            motionState->timer = 0.0f;
            return;
        }
        if (triggerDefinition->secondAnimation == -1) {
            motionState->timer = 0.0f;
            return;
        }
    }
    if (motionState->unk124 == triggerDefinition->animation) {
        motionState->timer = 0.0f;
        return;
    }
    flags = triggerDefinition->flags;
    if (!(flags & 1)) {
        if (motionState->unk128 <= 0) {
            return;
        }
    }
    interactionGuard = flags & 2;
    if (interactionGuard != 0) {
        if (actor->flags & 0x200) {
            motionState->timer = 0.0f;
            return;
        }
    }
    if (motionState->timer >= motionState->speed) {
        Weapons_RequestActorState(actor, motionState, 1);
    }
}

void func_802061D8_de(void *a, struct WeaponEventSource *b) {
    if (b->eventEnabled != 0) {
        Weapons_RequestActorState(a, b, 0x0);
    }
}

int func_80206200_de(int actor) {
    return Rumble_TestActorStateBit(&g_world, actor) == 1;
}

void func_80206230_de(void *actor) {
    Rumble_SetActorStateBit(&g_world, actor, 1);
}
