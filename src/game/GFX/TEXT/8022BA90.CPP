#include "include_asm.h"
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
#include "SCENE/802508E0_4.H"
#include "RENDER_4/8028FD2C_6.H"
#include "GFX/TEXT/8022BA90_2.H"

extern unsigned int D_80146894;

extern void *func_8028CFA0_de(Shared_World *arg0, s32 arg1, s32 arg2);

extern s32 D_801468F4;

extern s32 D_80140FF8;







extern void Instance_DrawBlobShadow(void *arg0, CVector3 *arg1, s32 arg2);



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
int func_8022BAC0_de(void) {
    return D_80146894 != 0;
}

void Text_LoadActorModel(void *actor) {
    s32 modelKind;
    void *result;

    modelKind = ((Shared_ActorView *)actor)->state;
    if (D_801468F4 != 0 && ((Shared_ActorView *)actor)->controls->transientFlag == 1) {
        modelKind = 0x13;
    }
    result = func_8028CFA0_de(&D_8011FE88, 0xB, modelKind);
    if (result != 0) {
        ((Shared_ActorView *)actor)->model = result;
    } else {
        result = func_8028CFA0_de(&D_8011FE88, 0xB, -1);
        if (result != 0) {
            ((Shared_ActorView *)actor)->model = result;
        } else {
            result = func_8028CFA0_de(&D_8011FE88, -1, -1);
            ((Shared_ActorView *)actor)->model = result;
        }
    }
    ((LevelActor *)actor)->scale.x = ((ObjectState108 *)result)->unk_FC;
    ((LevelActor *)actor)->scale.y = ((ObjectState108 *)result)->unk_100;
    ((LevelActor *)actor)->scale.z = ((ObjectState108 *)result)->unk_104;
}

void func_8022BB80_de(void *actor) {
    s32 var_a2;
    Shared_Game *base;

    base = &D_801462C8;
    if (base->local == 0) {
        var_a2 = 0x66;
    } else if (base->unk62C != 0 && ((Shared_ActorView *)actor)->controls->transientFlag != 0) {
        var_a2 = D_800CE47C;
    } else {
        var_a2 = D_800CE430[((LevelActor *)actor)->definition->character];
        ((Shared_ActorView *)actor)->id = ((Shared_ActorView *)actor)->controls->playerId;
    }
    ((void (*)(void *, void *, s32, s32))func_8028B274_de)(&D_8011FE88, actor, var_a2, ((Shared_ActorView *)actor)->effectId);
}

void func_8022BC14_de(Player *actor) {
    s32 var_t0;

    if (actor->computer != 0) {
        if (D_8014288C == 0) {
            var_t0 = 0x17;
            goto after;
        }
    }
    var_t0 = (D_80140FF8 == 1) ? 0 : 0x17;
after:
    ((void (*)(void *, void *, s32, s32))func_8028B274_de)(&D_8011FE88, &actor->weaponModel,
        ((WeaponInfo *)D_800D052C[actor->selectedAction])->model + var_t0,
        actor->weaponAnimationTable->defaultAnimation);
}

void func_8022BC94_de(void *actorIn, s32 arg1) {
    CVector3 sp28;
    void *temp_s1;
    Shared_ActorView *actor;
    SharedRecAt564V1 *message;
    ObjectLinks1DC_3 *object = actorIn;

    if (object->unk_100 & 0x40000) {
        temp_s1 = func_8025193C_de(0, object->resource, object->resource, object->resourceFlags, 4, 0, 0, &D_800C2BC0_de, 1);
        if (temp_s1 != 0) {
            actor = object->unk_1D8;
            func_8024B4F4_de(actorIn, (s32)func_8028FDB4_de(*(void **)temp_s1, 0));
            if (arg1 != 0) {
                message = actor->message;
                if (message != 0) {
                    sp28.x = message->position.x - object->unk_8.x;
                    sp28.y = 0.0f;
                    sp28.z = ((SharedRecAt564V1 *)actor->message)->position.z - object->unk_8.z;
                    Instance_DrawBlobShadow(actorIn, &sp28, arg1);
                }
            }
            func_80253754_de(0, temp_s1);
        }
    }
}

void func_8022BD94_de(void *arg0, void *source, s32 arg2) {
    func_8022BD84_S2 *object = arg0;
    func_8020D1FC_S1 *argument = source;
    s32 flags;
    s32 flag_1000;
    s32 flag_8000;
    s32 flag_10000;

    if (arg2 != 0) {
        flags = argument->unk38;
        flag_1000 = flags & 0x1000;
        flag_8000 = flags & 0x8000;
        flag_10000 = flags & 0x10000;
        if (flag_1000 == 0) {
            object->unk840 = 0;
        } else {
            func_8022BE20_de(arg0, source);
        }
        if (flag_8000) {
            func_8022BEFC_de(arg0, source);
        }
        if (flag_10000) {
            func_8022C060_de(arg0, source);
        }
    }
}

#ifdef NON_MATCHING
#include "TYPES.H"

typedef struct HealingActor {
    u8 pad[0x5E4];
    s32 health;
    u8 pad5E8[0x258];
    f32 recoveryTime;
    u8 pad844[4];
    s32 recovering;
} HealingActor;

extern f32 D_800D2988;
extern f32 D_800C2D20_de;
extern f32 D_800C2D24_de;
extern void Render_ApplyPlayerDamage(HealingActor *, void *, s32, s32, s32);

/* 43/47 words; remaining: the sum is tied to the recoveryTime load (add.s f0,f0,f1; limit in f1) where the target keeps
 * it untied in f2 (limit in f0); 12 source shapes (early return, +=, pointer, else-store, separate dt/limit locals) all tie. */
void func_8022BE20_de(void *healingActor, void *source) {
    HealingActor *actor = healingActor;
    f32 elapsed = actor->recoveryTime + D_800D2988;
    s32 missing;
    s32 amount;

    actor->recoveryTime = elapsed;
    if (D_800C2D20_de < elapsed) {
        missing = 150 - (actor->health >> 8);
        amount = 1;
        if (missing > 0) {
            missing /= 15;
            if (missing > 0) {
                amount = missing;
            }
        }
        actor->recovering = 1;
        Render_ApplyPlayerDamage(actor, source, amount << 8, 0, 0x1F);
        actor->recoveryTime = actor->recoveryTime - D_800C2D24_de;
    }
}
#else
INCLUDE_ASM("span_1000", func_8022BE20_de);
#endif
