#include "include_asm.h"
#include "COMMON/OBJECTLINKS150C.H"
#include "ACTORS/80277444.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/LEVEL_ACTOR.H"
#include "COMMON/WORLD.H"
#include "COMMON/LISTHEADER.H"
#include "TYPES.H"
#include "ACTORS/80277444_8.H"
#include "COMMON/EXTERNS_10.H"
extern s32 SoundElement_PlayFlatSound(s32 arg0);

#if defined(VERSION_US_REV1) || defined(NON_MATCHING)
#include "COMMON/GAMEPLAY_SOUND_TABLE.H"
#include "TYPES.H"
#include "RENDER_2/8025DE50_5.H"
#include "COMMON/OBJECTLINKS14.H"
typedef void (*NavPrimaryFn)(NavigationPlatform *, void *, Trigger *);
typedef void (*NavSecondaryFn)(Trigger *);
typedef struct NavCallbackPair { NavPrimaryFn primary; NavSecondaryFn secondary; } NavCallbackPair;

extern NavCallbackPair *D_800CD668_de[];

extern void *D_800CD730;

#include "COMMON/MENU_MATCH_GLOBALS.H"
extern s32 D_801371D4;

extern void Sky_PostTargetedScreenMessage(void *, void *, s32, void *, f32);
extern s32 Menu_RequestTrackByKey(s32);
void Link_DispatchTrigger(Trigger *trigger) {
    NavCallbackPair *table;
    void *fallback;
    u8 index;
    s32 callback;
    table = D_800CD668_de[trigger->table];
    if (table != 0) {
        if (D_80145088.settings.local == 0) {
            fallback = D_80145088.cameras;
            if (fallback == 0) fallback = &D_80145088.fallbackCamera;
        } else {
            fallback = &D_80145088.fallbackCamera;
        }
        if (g_world.mode == 4) {
            index = trigger->sound;
            if (index != 0) {
                Sky_PostTargetedScreenMessage(&D_80145088, fallback, gameplaySoundValue(index), D_800CD730, triggerSoundWeight());
                callback = gameplaySoundHook(trigger->sound);
                if (callback != 0) func_8025E11C_de(callback);
            }
            if (trigger->action >= 2) Menu_RequestTrackByKey(trigger->action);
        }
        table += trigger->entry;
        if (trigger->owner == D_801371D4) {
            NavPrimaryFn fn;
            NavigationPlatform *actor;
            fn = table->primary;
            actor = &D_8011BF00[trigger->actor];
            if (fn != 0) fn(actor, &actor->motion, trigger);
        } else {
            NavSecondaryFn fn;
            fn = table->secondary;
            if (fn != 0) fn(trigger);
        }
    }
}
#else
INCLUDE_ASM("span_1000", Link_DispatchTrigger);
#endif

extern s32 Link_DispatchMatchingTriggers(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, void *arg6);

extern s32 Scene_FindActorTriggerRange(s8 *arg0, void *arg1, s32 *arg2, s32 *arg3);

extern s32 Scene_FindAlternateTriggerRange(s8 *arg0, s32 arg1, s32 *arg2, s32 *arg3);

extern s32 Scene_SetTriggerStateBit(void *arg0, void *arg1, s32 arg2);


extern void Scene_ResetTransitionViewport(void);

extern void Menu_RequestTrackByIds(s32, s32);

extern void Barrel_StopActorLoopingSound(void);

extern void AnimPool_ReleaseSceneEffect(struct Shared_Actor *arg0);



void Link_DispatchActorLinks(struct Shared_Actor *actor, s32 arg1, void *arg2) {
    s32 sp20;
    s32 sp24;

    if (!(actor->weaponFlags & 0x80000)) {
        Scene_FindActorTriggerRange(&g_world, actor, &sp20, &sp24);
        if (sp24 != 0) {
            Link_DispatchMatchingTriggers(sp20, sp24, 0, arg1 & 0x3FC1FF, arg1 & 0x400000, 0x400000, arg2);
        }
    }
}

void Link_DispatchObjectLinks(s32 arg0, s32 arg1, void *actor) {
    s32 sp20;
    s32 sp24;

    if (arg0 != 0) {
        Scene_FindAlternateTriggerRange(&g_world, arg0, &sp20, &sp24);
        if (sp24 != 0) {
            Link_DispatchMatchingTriggers(sp20, sp24, 0, arg1 & 0x7FF, arg1 & 0x3800, 0x3800, actor);
        }
    }
}

void Link_ActivateTrigger(void *trigger) {
    func_80278EEC_S1 *object = trigger;

    object->unkE |= 0x10;
    Scene_SetTriggerStateBit(&g_world, trigger, 1);
    if ((g_world.mode == 4) && (object->unkE & 2)) {
        Scene_QueueTriggerTimer(&g_world, trigger);
        return;
    }
    Link_DispatchTrigger(trigger);
}

void Link_DispatchTriggerExit(Record14 *trigger) {
    Record14 copy;
    u8 *bytes = (u8 *)trigger;

    bytes[0xE] |= 0x20;
    if (bytes[0x11] == 1) {
        copy = *trigger;
        ((u8 *)&copy)[0x12] = 2;
        ((u8 *)&copy)[0x10] = 0;
        Link_DispatchTrigger(&copy);
    }
}

/* Clears bits 0x2000 and 0x100 of the flag word at offset 0x100 of an object. */


void Link_ClearActorFlagMask(struct LevelActor *object) {
    object->flags &= ~0x2000;
    object->flags &= ~0x100;
}

void Link_SetActorFlagMask(LevelActor *actor) {
    func_802472F0_de(actor);
    actor->flags = (s32) (actor->flags | 0x2100);
}

void Link_RequestOwnerTrack(s32 arg0, s32 unused1, s32 arg2) {
    if (g_world.mode == 4) {
        Scene_ResetTransitionViewport();
        Menu_RequestTrackByIds(arg0, arg2);
    }
}

void Link_RequestGlobalTrack(s32 arg0) {
    if (g_world.mode == 4) {
        Scene_ResetTransitionViewport();
        Menu_RequestTrackByIds(0, arg0);
    }
}

void Link_CaptureActorTransform(void *arg0, void *arg1) {
    (((struct ObjectState104 *) ((s8 *) arg0))->unk_100) = (s32) ((((struct ObjectState104 *) ((s8 *) arg0))->unk_100) | 0x40000000);
    (((struct FloatState64 *) ((s8 *) arg1))->unk_48) = (f32) (((struct ObjectState104 *) ((s8 *) arg0))->unk_8);
    (((struct FloatState64 *) ((s8 *) arg1))->unk_4C) = (f32) (((struct ObjectState104 *) ((s8 *) arg0))->unk_C);
    (((struct FloatState64 *) ((s8 *) arg1))->unk_50) = (f32) (((struct ObjectState104 *) ((s8 *) arg0))->unk_10);
    (((struct FloatState64 *) ((s8 *) arg1))->unk_60) = (f32) (((struct ObjectState104 *) ((s8 *) arg0))->unk_6C);
}

void Link_DispatchTriggerAudio(s32 arg0, s32 arg1, Trigger *trigger) {
    if (trigger->unk6 >= 0x100) {
        func_8025E11C_de(trigger->unk6);
        return;
    }
    func_8025E2D4_de(trigger->unk6);
}

void Link_DeactivateActorState(struct Shared_Actor *actor, s32 *stateFlags) {
    s32 flags;

    Barrel_StopActorLoopingSound();
    *stateFlags |= 0x20;
    flags = actor->weaponFlags & 0xFFFEFFFF;
    flags = flags & ~0x2000;
    flags = flags & ~0x100;
    actor->weaponFlags = flags;
    if (flags & 0x80000) {
        AnimPool_ReleaseSceneEffect(actor);
    }
}

void Link_PlayTriggerSoundCallback(int unused0, int unused1, void *arg2) {
    ObjRecAt6V2 *arg2_record = arg2;
    SoundElement_PlayFlatSound(arg2_record->unk6);
}

void Link_SelectTriggerMusic(void *arg0) {
    func_8025E2D4_de((s32) (((struct ObjRecAt6V1 *) ((s8 *) arg0))->unk6));
}

void Link_PlayTriggerSound(void *arg0) {
    SoundElement_PlayFlatSound((((struct ObjRecAt6V2 *) ((s8 *) arg0))->unk6));
}
