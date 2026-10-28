#include "include_asm.h"
#include "COMMON/EXTERNS_6.H"
#include "COMMON/GAME_SESSION.H"
#include "COMMON/OBJECTSTATE90.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/GAMEPLAY_ROUND_RULES.H"
#include "COMMON/GAMEPLAY_TRANSITION.H"
#include "SCENE/802508E0_9.H"
#include "COMMON/LEVEL_ACTOR.H"
#include "COMMON/WORLD.H"
#include "COMMON/SHAREDCALLBACK5.H"
#include "COMMON/MULTIPLAYEROPTIONS.H"
#include "COMMON/ACTORRESOURCEHEADER.H"
#include "COMMON/OBJECTSTATE18.H"
#include "TYPES.H"
#include "COMMON/UNUSED.H"
#include "COMMON/RESOURCELOADSTATE.H"
#include "ENGINE/SCENE_6.H"
#include "SCENE/CACHE_REQUESTRESOURCE.H"
#include "RENDER/SETN64_GETPACKSECTION.H"
#include "GFX/TEXT/8022BA90_2.H"


extern void *Scene_FindActorDefinition(Shared_World *arg0, s32 arg1, s32 arg2);


extern s32 D_80140FF8;







extern void GameObject_DrawBlobShadow(void *arg0, CVector3 *arg1, s32 arg2);



extern void func_8022C060_de(void *arg0, void *arg1);

/** Report whether the nested pointer's word at 0x564 is nonzero. */
int func_8022BAA0_de(void *object) {
    func_80228774_S5 *object_record = object;
    View *nested = object_record->unk5DC;
    if (nested != 0) {
        return nested->unk564 != 0;
    }
    return 0;
}

/** Report whether the global state word is nonzero. */
int Player_IsClockPaused(void) {
    return D_8011FAC0.clockPaused != 0;
}

void Playerai_LoadActorModel(void *actor) {
    s32 modelKind;
    void *result;

    modelKind = ((Shared_ActorView *)actor)->state;
    if (D_801462C8.counters.m_bFragTagOn != 0 && ((Shared_ActorView *)actor)->controls->transientFlag == 1) {
        modelKind = 0x13;
    }
    result = Scene_FindActorDefinition(&g_world, 0xB, modelKind);
    if (result != 0) {
        ((Shared_ActorView *)actor)->model = result;
    } else {
        result = Scene_FindActorDefinition(&g_world, 0xB, -1);
        if (result != 0) {
            ((Shared_ActorView *)actor)->model = result;
        } else {
            result = Scene_FindActorDefinition(&g_world, -1, -1);
            ((Shared_ActorView *)actor)->model = result;
        }
    }
    ((LevelActor *)actor)->scale.x = ((ObjectState108 *)result)->unk_FC;
    ((LevelActor *)actor)->scale.y = ((ObjectState108 *)result)->unk_100;
    ((LevelActor *)actor)->scale.z = ((ObjectState108 *)result)->unk_104;
}

void func_8022BB80_de(void *actor) {
    s32 modelKind;
    Shared_Game *base;

    base = &D_801462C8;
    if (base->local == 0) {
        modelKind = 0x66;
    } else if (base->unk62C != 0 && ((Shared_ActorView *)actor)->controls->transientFlag != 0) {
        modelKind = D_800CE47C;
    } else {
        modelKind = D_800CE430[((LevelActor *)actor)->definition->character];
        ((Shared_ActorView *)actor)->id = ((Shared_ActorView *)actor)->controls->playerId;
    }
    ((void (*)(void *, void *, s32, s32))Scene_ChangeInstanceModel)(&g_world, actor, modelKind, ((Shared_ActorView *)actor)->effectId);
}

void func_8022BC14_de(Player *actor) {
    s32 modelOffset;

    if (actor->computer != 0) {
        if (D_801462C8.counters.transitionActive == 0) {
            modelOffset = 0x17;
            goto after;
        }
    }
    modelOffset = (D_80140FF8 == 1) ? 0 : 0x17;
after:
    ((void (*)(void *, void *, s32, s32))Scene_ChangeInstanceModel)(&g_world, &actor->weaponModel,
        ((WeaponInfo *)D_800D052C[actor->selectedAction])->model + modelOffset,
        actor->weaponAnimationTable->defaultAnimation);
}

void func_8022BC94_de(void *actorIn, s32 shadowMode) {
    CVector3 viewOffset;
    void *animationResource;
    Shared_ActorView *actor;
    SharedRecAt564V1 *message;
    ObjectLinks1DC_3 *object = actorIn;

    if (object->unk_100 & 0x40000) {
        animationResource = Cache_RequestResource(0, object->resource, object->resource, object->resourceFlags, 4, 0, 0, D_800C2BC0_de, 1);
        if (animationResource != 0) {
            actor = object->unk_1D8;
            Gobjinst_UpdateModelBounds(actorIn, (s32)SetN64_GetPackSection(*(void **)animationResource, 0));
            if (shadowMode != 0) {
                message = actor->message;
                if (message != 0) {
                    viewOffset.x = message->position.x - object->unk_8.x;
                    viewOffset.y = 0.0f;
                    viewOffset.z = ((SharedRecAt564V1 *)actor->message)->position.z - object->unk_8.z;
                    GameObject_DrawBlobShadow(actorIn, &viewOffset, shadowMode);
                }
            }
            Cache_UnlockResource(0, animationResource);
        }
    }
}

void func_8022BD94_de(void *player, void *source, s32 enabled) {
    func_8022BD84_S2 *object = player;
    func_8020D1FC_S1 *argument = source;
    s32 flags;
    s32 flag_1000;
    s32 flag_8000;
    s32 flag_10000;

    if (enabled != 0) {
        flags = argument->unk38;
        flag_1000 = flags & 0x1000;
        flag_8000 = flags & 0x8000;
        flag_10000 = flags & 0x10000;
        if (flag_1000 == 0) {
            object->unk840 = 0;
        } else {
            Playerai_ApplyDamageOverTime(player, source);
        }
        if (flag_8000) {
            func_8022BEFC_de(player, source);
        }
        if (flag_10000) {
            func_8022C060_de(player, source);
        }
    }
}

extern void Player_ApplyPlayerDamage(void *player, void *attacker, s32 amount, s32 arg3, s32 kind);
/* Damage over time while the source's effect flag 0x1000 is set (func_8022BD94_de): advances the player's
 * effect timer by the frame step; past 300 it marks the player and deals max(1, (150 - health / 256) / 15)
 * points (8.8 fixed) of kind 0x1F, then winds the timer back by 22.5 so the next tick follows sooner.
 * HONEST-FORM-OPEN: the step check stores the same value in both arms. jump2 cross-jumps the arms and
 * deletes the test, but its reads of `previous` and `step` keep both live past the sum, which puts the
 * sum in $f2 as in the ROM (REV1-ONE-65B RESULT.md). */
void Playerai_ApplyDamageOverTime(Shared_ActorView *player, void *source) {
    s32 missing;
    s32 amount;
    f32 elapsed;
    f32 previous;
    f32 step;
    previous = player->recoveryTime;
    step = D_800D2988;
    elapsed = previous + step;
    if (elapsed - previous != step) {
        player->recoveryTime = elapsed;
    } else {
        player->recoveryTime = elapsed;
    }
    if (300.0f < elapsed) {
        missing = 150 - (player->health >> 8);
        amount = 1;
        if (missing > 0) {
            missing /= 15;
            if (missing > 0) {
                amount = missing;
            }
        }
        player->collisionState = 1;
        Player_ApplyPlayerDamage(player, source, amount << 8, 0, 0x1F);
        player->recoveryTime -= 22.5f;
    }
}
