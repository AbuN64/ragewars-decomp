#include "include_asm.h"
#include "RENDER/MATERIAL_COLOR_AND_FOG_VIEWS.H"
#include "COMMON/OBJRECAT30.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/RUNTIME_DECLARATIONS.H"
#include "COMMON/LEVEL_ACTOR.H"
#include "COMMON/WORLD.H"
#include "COMMON/REC.H"
#include "COMMON/OBJECT_INSTANCE_TRANSFORM_AND_RENDER_VIEWS.H"
#include "COMMON/LISTHEADER.H"
#include "COMMON/TRIPLE.H"
#include "TYPES.H"
#include "LEVEL/ACTION_UPDATEBREAKABLEPROXIMITY.H"
#include "WEAPONS/ACTOR_REQUESTACTORSTATE.H"
#include "COMMON/GAMEPLAY_SOUND_TABLE.H"
#include "COMMON/MENU_MATCH_GLOBALS.H"
#include "COMMON/NAVIGATION_NODE_AND_ROUTE_VIEWS.H"

/* 8020402C.CPP */
#if defined(VERSION_EU_X) && !defined(NON_MATCHING)
INCLUDE_ASM("span_1000", Action_UpdateBreakableProximityEuropeanExtended);
#endif

#if defined(VERSION_EU) && !defined(NON_MATCHING)
INCLUDE_ASM("span_1000", Action_UpdateBreakableProximityEuropean);
#endif

#if defined(VERSION_US_REV1) || defined(VERSION_DE) || defined(VERSION_US)
#define LV_FIELD(base, type, offset) (*(type *)((u8 *)(base) + (offset)))
extern s32 g_breakableNotificationText;
extern u8 *Playerai_FindTransientPlayer(u8 *);
extern void Playerai_UpdateTeamScore(void *, void *, s32);
extern void Camera_PostScreenMessage(u8 *, void *, s32);
/* 182/182 words in us-rev1 and de (local j targets aside); not exact on the ROM path only because the switch jump table (D_auto_rodata_func_8020402C_us_rev1_800C6B48) still lives in a separate rodata file; us/eu/eu-x differ in prologue size */
typedef struct LvDelta {
    f32 x, y, z;
} LvDelta;
void Action_UpdateBreakableProximity(u8 *self, u8 *hit) {
    u8 *state = LV_FIELD(self, u8 *, 0x18) + 0x14;
    u16 kind = LV_FIELD(self, u16, 0xE4);
    u8 *player;
    u8 *table;
    u8 *table2;
    u8 *record;
    u8 *node;
    LvDelta d;
    f32 distance;
    u32 t1;
    switch (kind) {
    case 0x64E:
        player = Playerai_FindTransientPlayer((u8 *)&g_playerViewRenderContext);
        if (player != 0 && LV_FIELD(player, s32, 0x5E4) != 0 && LV_FIELD(hit, s8, 0x36) != LV_FIELD(hit, s8, 0x34)) {
            table = (u8 *)&g_playerViewRenderContext + 0x1860;
            if (LV_FIELD(table, s32, 0x68) == 0 && LV_FIELD(hit, s32, 0x12C) == 0) {
                if (LV_FIELD(LV_FIELD(player, u8 *, 0x5D8), u8, 0x8F) == 1) {
                    LV_FIELD(LV_FIELD(player, u8 *, 0x5D8), u8, 0x8F) = 0;
                    LV_FIELD(LV_FIELD(player, u8 *, 0x5D8), u8, 0x90) = 1;
                    LV_FIELD(table, s32, 0x74) = 1;
                    LV_FIELD(hit, s32, 0x12C) = 1;
                    SoundElement_PlayFlatSound(0xE0D);
                }
            }
        }
        break;
    case 0x653:
    case 0x654:
    case 0x655:
    case 0x656:
        if (LV_FIELD(hit, s8, 0x36) == LV_FIELD(hit, s8, 0x34)) {
            return;
        }
        player = Playerai_FindTransientPlayer((u8 *)&g_playerViewRenderContext);
        if (player == 0 || LV_FIELD(LV_FIELD(player, u8 *, 0x5D8), u8, 0x8F) == 0) {
            return;
        }
        d.x = LV_FIELD(player, f32, 8) - LV_FIELD(self, f32, 8);
        d.y = LV_FIELD(player, f32, 0xC) - LV_FIELD(self, f32, 0xC);
        d.z = LV_FIELD(player, f32, 0x10) - LV_FIELD(self, f32, 0x10);
        distance = Gu_Sqrtf(d.x * d.x + d.y * d.y + d.z * d.z);
        if ((f32)(s32)distance < 122.88f) {
            LV_FIELD(LV_FIELD(player, u8 *, 0x5D8), u8, 0x8F) = 0;
            LV_FIELD(LV_FIELD(player, u8 *, 0x5D8), u8, 0x90) = 1;
            LV_FIELD(LV_FIELD(player, u8 *, 0x5D8), u16, 8) += 1;
            Playerai_UpdateTeamScore(player, player, 3);
            table2 = (u8 *)&g_playerViewRenderContext + 0x1860;
            LV_FIELD(table2, s32, 0x84) = 0;
            LV_FIELD(table2, s32, 0x80) = 0;
            switch (LV_FIELD(LV_FIELD(player, u8 *, 0x5D8), u8, 0x92)) {
            case 0:
                SoundElement_PlayFlatSound(0x2E6);
                break;
            case 1:
                SoundElement_PlayFlatSound(0x2E4);
                break;
            case 2:
                SoundElement_PlayFlatSound(0x2E8);
                break;
            case 3:
                SoundElement_PlayFlatSound(0x2EC);
                break;
            case 4:
                SoundElement_PlayFlatSound(0x2EA);
                break;
            }
            for (node = *(u8 **)&g_transientPlayerList; node != 0; node = LV_FIELD(node, u8 *, 0x16E0)) {
                if (LV_FIELD(node, void *, 0x5DC) != 0) {
                    Camera_PostScreenMessage((u8 *)&g_frontendScreenStatus, LV_FIELD(node, void *, 0x5DC), g_breakableNotificationText);
                }
            }
        } else {
            return;
        }
        break;
    }
    if (LV_FIELD(hit, s8, 0xCB) != 0) {
        if (LV_FIELD(state, u32, 0) & 2) {
            t1 = LV_FIELD(self, u32, 0x100) & ~0x2000;
            LV_FIELD(self, u32, 0x100) = t1 & ~0x100;
        }
        if (LV_FIELD(hit, s32, 0x128) != 0) {
            Actor_RequestActorState(self, hit, 0);
        }
        if (LV_FIELD(self, u16, 0xE4) == 0x64C) {
            Actor_RequestActorState(self, hit, 2);
        }
    }
}
#endif

typedef struct SoundParent { char pad0[0x5DC]; void *emitter; } SoundParent;
typedef struct SoundActor {
    u8 kind; char pad1[0xFF]; s32 flags;
    char pad104[0x1D8 - 0x104]; SoundParent *parent;
} SoundActor;
extern char g_fallbackScreenMessageEmitter;
extern void Gsky_PostTargetedScreenMessage(void *, void *, s32, void *, f32);
/* EU/EU-X: this body is 56/57 words; reorg picks beqz (target beql) for the flags check, so those versions
 * keep their asm. */
#if (!defined(VERSION_EU) && !defined(VERSION_EU_X)) || defined(NON_MATCHING)
s32 Action_ShowTriggerMessage(struct NavigationPlatform *object, ActorMotionState *guard, struct Player *player) {
    ActorMotionDefinition *record;
    SoundParent *parent;
    void *emitter, *fallback;
    s16 index;
    s32 callback;
    record = &object->resource->motion;
    if (record->soundEnabled == 0) return 1;
    if (guard->mode != 0) return 1;
    if (((SoundActor *)player)->kind != 1) return 1;
    if ((((SoundActor *)player)->flags & 0x300000) == 0) return 1;
    index = record->soundIndex;
    parent = ((SoundActor *)player)->parent;
    if (index == 0) return 0;
    emitter = parent->emitter;
    fallback = &g_fallbackScreenMessageEmitter;
    if (emitter != 0) fallback = emitter;
    Gsky_PostTargetedScreenMessage(&g_frontendScreenStatus, fallback, gameplaySoundValue(index), object, gameplaySoundWeight());
    index = record->soundIndex;
    callback = gameplaySoundHook(index);
    if (callback != 0) SoundElement_PlayDialogGroup(callback);
    return 0;
}
#else
INCLUDE_ASM("span_1000", Action_ShowTriggerMessage);
#endif

typedef struct Owner Owner;

extern s32 Rumble_TestActorStateBit(void *, void *);

extern void Rumble_SetActorStateBit(Shared_World *, void *, s32);

extern void Link_DispatchActorLinks(void *actor, s32 eventMask, void *eventSource);

struct ParticleQuadPoolScene;
extern void Fx_RecycleOwnerParticles(struct ParticleQuadPoolScene *, s32);

extern void Scene_SetLevelActorStateBit(void *a, unsigned short b, unsigned short c, int d);

/* Supplies the nonnegative blend remaining after the incoming strength is
 * scaled, then applies the actor animation using the original lookup. */
struct ActionFadeInput {
    char pad0[0x40];
    f32 strength;
};

extern void Gobjinst_DrawActorModelWithViewEffects(FadedActorRenderView *, void *, Lookup *);

/** Run the object's optional update hook, then copy one of two byte pairs into the record header. */

void Actionai_CopyTrackBytes(char *ownerRecord, char *eventRecord) {
    Owner *owner = (void *)ownerRecord;
    ActionTrackCallbackRecord *event = (void *)eventRecord;
    char *base = owner->track + 0x14;
    Hook *hook = event->callbackHook;

    if (hook != 0 && hook->fn != 0) {
        hook->fn(ownerRecord, eventRecord);
    }
    if (eventRecord[0x34] == 0) {
        ownerRecord[1] = base[0xE];
        ownerRecord[3] = base[0xF];
    } else {
        ownerRecord[1] = base[0x1A];
        ownerRecord[3] = base[0x1B];
    }
}

void Actionai_InitBreakableMotion(LevelActor *actor, ActorMotionState *motionState) {
    motionState->table = &g_actionMotionDispatchTable;
    motionState->update = &g_actionUpdateRomEntry;
    motionState->animation = 0;
    motionState->remainingCount = 0;
    motionState->unk12C = 0;
    if (((BreakableDefinition *)actor->definition)->flags & 1) {
        actor->flags = actor->flags | 0x10000;
        return;
    }
    actor->flags = actor->flags & 0xFFFEFFFF;
}

/** Update actor state and clear flags for the relevant actor classes. */
void Action_ActivateBreakableState(SharedPlayer *actor, void *state) {
    s32 flags;

    if (Rumble_TestActorStateBit(&g_world, actor) == 1) {
        Actor_RequestActorState(actor, state, 1);
        switch (actor->views1C.viewE4_7.kind) {
        case 0x64C:
            flags = actor->views1C.view100_9.flags & ~0x2000;
            actor->views1C.view100_9.flags = flags & ~0x100;
            break;
        case 0x64B:
        case 0x64E:
            actor->views1C.view100_9.flags &= 0xF7FFFFFF;
            break;
        }
    } else {
        g_actionStateTransitionPending = 1;
        Actor_RequestActorState(actor, state, 0);
        g_actionStateTransitionPending = 0;
    }
}

/* The kind-10 actor initializer installs the state table containing this callback. */
s32 Actionai_UpdateTriggerFlag(LevelActor *actor) {
    void *resource = actor->definition;
    BreakableDefinition *definition = resource;
    s32 val;

    val = definition->triggerValue;
    if (val != 0) {
        actor->flags = actor->flags | 0x2000;
    } else {
        actor->flags = actor->flags & ~0x2000;
    }
    return val;
}

void Action_ClearBreakableState(void *actor, void *actorMotionState) {
    ActorMotionState *state = actorMotionState;
    Rumble_SetActorStateBit(&g_world, actor, 0);
    Link_DispatchActorLinks(actor, 0x200000, actor);
    state->unk12C = 0;
}

s32 Actionai_UpdateHealthFlag(LevelActor *actor) {
    s32 val;

    val = ((BreakableDefinition *)actor->definition)->health;
    if (val != 0) {
        actor->flags = actor->flags | 0x2000;
    } else {
        s32 flags = actor->flags & ~0x2000;
        flags &= ~0x100;
        actor->flags = flags;
    }
    return val;
}

void Action_SetBreakableState(void *actor) {
    BreakableDefinition *breakableDefinition;
    s32 hitFlags;
    s32 masked;
    Shared_World *pFlag;

    breakableDefinition = (BreakableDefinition *)((LevelActor *)actor)->definition;
    pFlag = &g_world;
    Rumble_SetActorStateBit(pFlag, actor, 1);
    if (g_actionStateTransitionPending == 0) {
        Link_DispatchActorLinks(actor, 0x80000, actor);
    }
    Fx_RecycleOwnerParticles(&g_actorParticleScene, actor);
    if (pFlag->mode != 4) {
        hitFlags = ((LevelActor *)actor)->flags | 0x08000000;
        ((LevelActor *)actor)->flags = hitFlags;
        if (breakableDefinition->flags & 2) {
            masked = hitFlags & ~0x2000;
            masked = masked & ~0x100;
            ((LevelActor *)actor)->flags = masked;
        }
        if (((BreakableDefinition *)((LevelActor *)actor)->definition)->health == 0) {
            ((LevelActor *)actor)->flags = ((LevelActor *)actor)->flags & ~0x100;
        }
    }
}

void Actionai_SetDrawHandler(void *unused0, void *motionState) {
    Dest *state = motionState;
    state->draw = &g_actionDrawRomEntry;
}

/** Clear two flag groups when the object's 0x1B0 field exceeds a tunable. */
void Actionai_ClearMotionFlags(LevelActor *object) {
    if (object->motionThreshold > k_actionMotionThreshold) {
        int flags = object->flags;
        flags &= ~0x2000;
        flags &= ~0x100;
        object->flags = flags;
    }
}

void Action_RequestStateOn(void *a, void *b) {
    Actor_RequestActorState(a, b, 0x1); }

void Actionai_EnableTrigger(Trigger *trigger) {
    Scene_SetLevelActorStateBit(&g_world, trigger->owner, trigger->actor, 1);
}

void Action_RequestStateOff(void *a, void *b) {
    Actor_RequestActorState(a, b, 0x0); }

void Actionai_DisableTrigger(Trigger *trigger) {
    Scene_SetLevelActorStateBit(&g_world, trigger->owner, trigger->actor, 0);
}

void Actionai_DrawFadedActor(FadedActorRenderView *actor, struct ActionFadeInput *input, Lookup *lookup) {
    f32 remaining = k_actionFadeMaximum - input->strength * k_actionFadeStrengthScale;
    g_menuModelFillEnabled = 1;
    if (remaining < 0.0f) {
        remaining = 0.0f;
    }
    g_menuModelFillColor[3] = remaining;
    Gobjinst_DrawActorModelWithViewEffects(actor, input, lookup);
}

#if defined(VERSION_EU)
unsigned int func_80204808_de_padding_548C[1] = {
    0x00000000,
};
#endif

#if defined(VERSION_DE) || defined(VERSION_US)
#if defined(VERSION_DE)
unsigned int func_80204868_de_padding_5468[2] = {
    0xF041C0A8, 0xC1C218FD,
};
#endif
#if defined(VERSION_US)
char func_80204868_de_padding_5468[8] =
    "ES\004.eosR";
#endif
#endif

/* 800C6B5C.CPP */
#if defined(VERSION_DE) || defined(VERSION_US) || defined(VERSION_US_REV1)
/* ROM-grounded data: src/k_ActionUpdatebreakableproximityFourWords_ActionUpdatebreakableproximity.c */
const unsigned int k_ActionUpdatebreakableproximityFourWords[1] = {
    0x40800000,
};
#endif
