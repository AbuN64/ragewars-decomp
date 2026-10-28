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
#include "COMMON/LONE/D_800E4680.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/UNUSED.H"
#include "COMMON/SHARED_VOIDCALLBACK.H"
#include "COMMON/MULTIPLAYEROPTIONS.H"
#include "COMMON/LISTHEADER.H"
#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/RENDERCOUNTERS.H"
#include "RENDER/80206258.H"
#include "particle/8027A0F4_8.H"
#include "include_asm.h"

/* 80204E78_7.CPP */
/* 80204E78_7.CPP */

extern s32 Rumble_TestActorStateBit(void *, void *);

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
    result = Graphu64_RandomBetween(base->delayMinimum, base->delayMaximum);
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
        Actor_RequestActorState(actor, motionState, 1);
    }
}

void func_802061D8_de(void *a, struct WeaponEventSource *b) {
    if (b->eventEnabled != 0) {
        Actor_RequestActorState(a, b, 0x0);
    }
}

int func_80206200_de(int actor) {
    return Rumble_TestActorStateBit(&g_world, actor) == 1;
}

void func_80206230_de(void *actor) {
    Rumble_SetActorStateBit(&g_world, actor, 1);
}

/* 80206258.CPP */
extern void Scene_SetLevelActorStateBit(void *a, unsigned short b, unsigned short c, int d);

/* Spawns effect kind at an actor's position through SetN64_SpawnModelEffect in D_80131600's list: kind 0xBD7
   is skipped while both of D_801468A0's flags at 0x78 and 0x80 are set, and kind 0x1388 is offset by
   the variant byte at D_800E4680 when option D_801462D5 is 1 (skipped for variant 0); a spawned node
   has its word at 0x1A0 cleared, takes one charge from the owner and starts effect 0x11D at its own
   position through func_80216288_de. */

extern SpawnDispatchActor *SetN64_SpawnModelEffect(char *, void *, s32, CVector3, Triple, s32, f32);

extern s32 Animpool_SpawnSceneEffect(void *arg0, s32 arg1, s32 arg2, s32 arg3,
                         s32 arg4, Triple arg5, f32 arg6, CVector3 arg7,
                         Triple arg8, void *arg9);

extern char D_8011D8D0;

extern char D_80145040;

struct Context;
extern void *func_8022A8F0_de(struct Context *arg0);

extern s32 Gobjinst_RequestAnimationKind(void *a, s32 c, s32 flag);

extern s32 Cinema_GetSequenceRequest(void);

extern func_80206604_G1 D_801462E5;

void func_80206258_de(Trigger *trigger) {
    Scene_SetLevelActorStateBit(&g_world, trigger->owner, trigger->actor, 1);
}

void func_80206288_de(void *actor) {
    Rumble_SetActorStateBit(&g_world, actor, 0);
}

void func_802062B0_de(Trigger *trigger) {
    Scene_SetLevelActorStateBit(&g_world, trigger->owner, trigger->actor, 0);
}

void func_802062E0_de(LevelActor *actor, ActorMotionState *owner, Params params, s32 kind) {
    SpawnDispatchActor *node;
    CGameStatus *settings;

    if (kind == 0xBD7) {
        settings = &D_801462C8.counters;
        if (settings->m_bCTFOn != 0 && settings->m_CTFPlayerWithFlag != 0) {
            return;
        }
    }
    if (kind == 0x1388 && D_801462C8.controllerMode == 1) {
        kind = *D_800E4680 + 0x1388;
        if (kind == 0x1388) {
            return;
        }
    }
    node = SetN64_SpawnModelEffect(&D_80131600, &owner->unk124, kind,
                         actor->position1, params.v, params.w, 0.0f);
    if (node != 0) {
        node->state = 0;
        owner->unk128 -= 1;
        Barrel_SpawnActorEffect(node, 0x11D, node->position, 0);
    }
}

void func_802063EC_de(LevelActor *actor, ActorMotionState *spawnState, Triple spawnPosition, Triple spawnColor,
                   s32 spawnOwner, s32 spawnId, s32 spawnCount) {
    if (Animpool_SpawnSceneEffect(&D_80131150, spawnId, 0, spawnCount,
                      spawnOwner, spawnPosition,
                      actor->yaw,
                      actor->position1, spawnColor,
                      &spawnState->unk124) != 0) {
        spawnState->unk128 -= 1;
    }
}

void func_802064A0_de(void *actor, ActorMotionState *spawnState, Triple effectPosition,
                   s32 unused5, s32 effectKind) {
    s32 result;

    result = Particle_SpawnEffectGroup((struct EffectSystem *)&D_8011D8D0, (struct EffectActor *)actor, (struct EffectActor *)actor,
                           (s32 *)&spawnState->unk124, 0, effectKind,
                           ((LevelActor *)actor)->position1,
                           ((LevelActor *)actor)->rotation,
                           *(CVector3 *)&effectPosition, 0, -1, 0);
    spawnState->unk128 -= result;
}

s32 func_8020655C_de(s32 actorKind) {
    SpawnDispatchActor *node;

    if (actorKind == 0x84F) {
        node = D_80137064.head;
        while (node != 0) {
            if (*node->definition == 4) {
                return 0;
            }
            node = node->next;
        }
        return func_8022A8F0_de(&D_80145040) == 0;
    }
    return 1;
}

void func_802065C0_de(void *a, ActorMotionState *b, s32 c) {
    b->action = -1;
    b->actionPending = 0;
    b->unk124 = c;
    Gobjinst_RequestAnimationKind(a, c, 1);
    func_802472F0_de(a);
}

void func_80206604_de(LevelActor *actor, ActorMotionState *motionState) {
    s32 flags;
    s32 flags2;

    motionState->table = &D_800C85F0_de;
    motionState->update = &D_00206724;
    flags = actor->flags;
    flags |= 0x01000000;
    flags |= 0x02000000;
    flags2 = flags | 0x20000;
    actor->flags = flags2;
    if (D_801462E5.unk0 == 0) {
        actor->flags = flags2 | 0x10000000;
    }
    if ((actor->type == 0x453) && (Cinema_GetSequenceRequest() == 0x6F)) {
        motionState->secondaryUpdate = &D_0020694C;
    }
}

void func_802066A4_de(LevelActor *actor, Dest *deviceState) {
    deviceState->field124 = ((ActorHealthDefinition *)actor->definition)->health;
    Actor_RequestActorState(actor, deviceState, 0);
    deviceState->charge = D_800C1AE0_de;
    deviceState->field12C = D_800C1AE0_de;
    if (Rumble_TestActorStateBit(&g_world, actor) == 1) {
        actor->flags &= ~0x2000;
        actor->flags &= ~0x100;
    }
}

void func_80206724_de(void *callbackContext, Shared_CallbackOwner *callbackOwner) {
    Shared_CallbackHook *obj = callbackOwner->hook;
    if (obj != 0) {
        Shared_VoidCallback fn = obj->callback;
        if (fn != 0) {
            ((void (*)(void *, Shared_CallbackOwner *))fn)(callbackContext, callbackOwner);
        }
    }
}

int func_80206758_de(void *unused0, Dest *deviceState) {
    return deviceState->field124;
}

void func_80206764_de(void) {
}

/* 800C6BC4.CPP */

/* 80204E78_7_DATA3.CPP */
/* 800C6BD0.CPP */
/* ROM-grounded data: src/rw_pool_802066A4_C77D0_us_rev1.c */
const unsigned int D_blob_06def481576a7536a499[1] = {
    0x3F800000,
};

#if defined(VERSION_EU_X)
unsigned int rodata_unresolved_800C1DC4[3] = {
    0x40C90FDB, 0x3E4CCCCD, 0x3E4CCCCD,
};
#endif

#if defined(VERSION_DE)
unsigned int rodata_unresolved_800C1AE4[3] = {
    0x00206BDC, 0x00206C9C, 0x00206B3C,
};
#endif

/* 800C1A14.CPP */
#if defined(VERSION_US)
const unsigned int D_auto_rodata_unresolved_800C1A14[3] = {
    0x076D5F41, 0x6C706861, 0x54000020,
};
#endif

/* 800C1D84.CPP */
#if defined(VERSION_EU)
const unsigned int D_auto_rodata_unresolved_800C1D84[3] = {
    0x02421024, 0x1040002D, 0x24030058,
};
#endif
