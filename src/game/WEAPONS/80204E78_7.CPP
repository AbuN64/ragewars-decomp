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

extern int Render_TestActorStateBit(char *a, int b);

extern void Render_SetActorStateBit(Shared_World *a, void *b, int c);

void func_80206080_de(void *levelActor, void *actorMotionState) {
    LevelActor *actor = levelActor;
    ActorMotionState *motion = actorMotionState;
    AnimationTriggerResource *resource;
    AnimationTriggerDefinition *base;
    char *ctx;
    f32 result;
    s32 count;
    s32 temp_v1;
    f64 var_f1;
    f32 scaled;

    resource = (void *)actor->definition;
    base = &resource->trigger;
    result = Nav_RandomBetween(base->delayMinimum, base->delayMaximum);
    motion->speed = result;
    ctx = (char *) &D_801462C8;
    if (((ObjectState1E_2 *)(ctx))->unk_1D != 0) {
        count = *(s32 *) (ctx - 0x1258);
        if ((u32) count >= 3) {
            count -= 2;
            scaled = result * D_800C1AD0_de;
            temp_v1 = 0x64 - count * 25;
            var_f1 = (f64) temp_v1;
            if (temp_v1 < 0) {
                var_f1 += (4294967296.0);
            }
            motion->speed = scaled * (f32) var_f1;
        }
    }
}

void func_8020612C_de(LevelActor *actor, ActorMotionState *motionState) {
    AnimationTriggerResource *definition;
    AnimationTriggerDefinition *temp_a2;
    s32 flags;
    s32 var_v0;

    definition = (void *)actor->definition;
    temp_a2 = &definition->trigger;
    if (temp_a2->enabled == 0) {
        if (temp_a2->firstAnimation == -1) {
            motionState->timer = 0.0f;
            return;
        }
        if (temp_a2->secondAnimation == -1) {
            motionState->timer = 0.0f;
            return;
        }
    }
    if (motionState->unk124 == temp_a2->animation) {
        motionState->timer = 0.0f;
        return;
    }
    flags = temp_a2->flags;
    if (!(flags & 1)) {
        if (motionState->unk128 <= 0) {
            return;
        }
    }
    var_v0 = flags & 2;
    if (var_v0 != 0) {
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

int func_80206200_de(int arg0) {
    return Render_TestActorStateBit(&D_8011FE88, arg0) == 1;
}

void func_80206230_de(void *arg0) {
    Render_SetActorStateBit(&D_8011FE88, arg0, 1);
}
