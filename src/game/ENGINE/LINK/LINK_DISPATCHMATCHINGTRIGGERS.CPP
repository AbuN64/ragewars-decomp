#include "include_asm.h"
#include "COMMON/OBJECTLINKS150C.H"
#include "ACTORS/80277444.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/LEVEL_ACTOR.H"
#include "COMMON/WORLD.H"
#include "COMMON/LISTHEADER.H"
#include "TYPES.H"
#include "LINK/LINK_2.H"
#include "COMMON/EXTERNS_10.H"
#include "SYSTEM/8025E280.H"
#include "COMMON/OBJECTLINKS14.H"

/* 80277444_8.CPP */

#include "COMMON/LONE/D_80152789.H"
#include "COMMON/GAMEPLAY_SOUND_TABLE.H"
#include "TYPES.H"
#include "RENDER/8025DE50_5.H"
#include "COMMON/OBJECTLINKS14.H"
#include "T2SOUNDELEMENT/T2SOUNDELEMENT.H"
typedef void (*NavPrimaryFn)(NavigationPlatform *, void *, Trigger *);
typedef void (*NavSecondaryFn)(Trigger *);
typedef struct NavCallbackPair { NavPrimaryFn primary; NavSecondaryFn secondary; } NavCallbackPair;

extern NavCallbackPair *D_800CD668_de[];

extern void *D_800CD730;

#include "COMMON/MENU_MATCH_GLOBALS.H"
extern s32 D_801371D4;

extern void Gsky_PostTargetedScreenMessage(void *, void *, s32, void *, f32);
extern s32 Track_RequestTrackByKey(s32);
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
                Gsky_PostTargetedScreenMessage(&D_80145088, fallback,
#if defined(VERSION_EU) || defined(VERSION_EU_X)
                                             D_800E45D4[trigger->sound].sound[g_languageIndex],
#else
                                             gameplaySoundValue(index),
#endif
                                             D_800CD730, triggerSoundWeight());
                callback = gameplaySoundHook(trigger->sound);
                if (callback != 0) func_8025E11C_de(callback);
            }
            if (trigger->action >= 2) Track_RequestTrackByKey(trigger->action);
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


extern s32 Scene_FindActorTriggerRange(s8 *arg0, void *arg1, s32 *arg2, s32 *arg3);

extern s32 Scene_FindAlternateTriggerRange(s8 *arg0, s32 arg1, s32 *arg2, s32 *arg3);

extern void Scene_ResetTransitionViewport(void);

extern void Track_RequestTrackByIds(s32, s32);

extern void Barrel_StopActorLoopingSound(void);

extern void Animpool_ReleaseSceneEffect(struct Shared_Actor *arg0);

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
        Track_RequestTrackByIds(arg0, arg2);
    }
}

void Link_RequestGlobalTrack(s32 arg0) {
    if (g_world.mode == 4) {
        Scene_ResetTransitionViewport();
        Track_RequestTrackByIds(0, arg0);
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
        Animpool_ReleaseSceneEffect(actor);
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

/* 80279208.CPP */
/* Updates a table of triggers against masks: for each trigger the world accepts (always in world mode 4, otherwise when Scene_TestTriggerStateBit refuses it), a trigger not yet entered whose mask meets the enter mask is marked entered and runs its enter action (the id's action through Scene_TestTriggerKindFlags and Scene_DispatchSecondaryTriggersOfKind, or Link_DispatchTriggerExit without an id); it then counts as active when its mask meets the require mask, meets the enter mask, passes the paired exclude masks, is not flagged 0x1000 without 0x100 and passes Link_CheckTriggerMessage, and an active trigger runs its fire action once (through Scene_SetTriggerStateBit, Scene_DecrementTriggerCounter, Scene_TestTriggerCounterZero and Scene_ActivateTriggersOfKind for an id, or Link_ActivateTrigger without one). */

extern s32 Scene_TestTriggerStateBit(Shared_World *world, Trigger *trigger);

extern s32 Scene_TestTriggerKindFlags(Shared_World *world, s32 id);

extern void Scene_DispatchSecondaryTriggersOfKind(Shared_World *world, s32 id);

extern void Scene_SetTriggerStateBit(Shared_World *world, Trigger *trigger, s32 arg);

extern void Scene_DecrementTriggerCounter(Shared_World *world, s32 id);

extern s32 Scene_TestTriggerCounterZero(Shared_World *world, s32 id);

extern void Scene_ActivateTriggersOfKind(Shared_World *world, s32 id);

void Link_SetTriggerTrackCallback(int unused0, int unused1, void *arg2) {
    ObjRecAt6V1 *arg2_record = arg2;
    func_8025E260_de(arg2_record->unk6);
}

void Link_SetTriggerTrack(void *arg0) {
    func_8025E260_de((((struct ObjRecAt6V1 *) ((s8 *) arg0))->unk6));
}

void Link_ClearActorStateBit(struct Shared_Actor *actor) {
    actor->weaponFlags &= ~0x10000;
}

/** Set flag 0x10000 in the word at offset 0x100. */
void Link_SetActorStateBit(void *object) {
    Shared_Actor *actor = object;
    actor->weaponFlags |= 0x10000;
}

void Link_DispatchMatchingTriggers(Trigger *triggers, s32 count, s32 require, s32 enter, s32 exclude, s32 group, struct Player *arg) {
    s32 i;
    s32 active;
    s32 usable;
    Shared_World *world;
    Trigger *trigger;

    for (trigger = triggers, i = 0; i < count; trigger++, i++) {
        world = &g_world;
        usable = 1;
        if (world->mode != 4) {
            usable = Scene_TestTriggerStateBit(world, trigger) == 0;
        }
        if (!usable) {
            continue;
        }
        active = 1;
        if (!(trigger->flags.bytes.state & 0x20) && enter != 0 && (trigger->mask & enter)) {
            trigger->flags.bytes.state |= 0x40;
            if (trigger->flags.bytes.id != 0) {
                if (Scene_TestTriggerKindFlags(world, trigger->flags.bytes.id) != 0) {
                    Scene_DispatchSecondaryTriggersOfKind(world, trigger->flags.bytes.id);
                }
            } else {
                Link_DispatchTriggerExit(trigger);
            }
            active = 1;
        }
        if (require != 0) {
            active = 0;
            if (trigger->mask & require) {
                active = 1;
            }
        }
        if (enter != 0 && !(trigger->mask & enter)) {
            active = 0;
        }
        if ((trigger->mask & group) && !(trigger->mask & group & exclude)) {
            active = 0;
        }
        if ((trigger->flags.word & 0x1100) == 0x1000) {
            active = 0;
        }
        if (Link_CheckTriggerMessage(trigger, arg) == 0) {
            active = 0;
        }
        if (!active) {
            continue;
        }
        if (trigger->flags.bytes.id != 0) {
            if (!(trigger->flags.bytes.state & 0x80)) {
                Scene_SetTriggerStateBit(world, trigger, 1);
                trigger->flags.bytes.state |= 0x80;
                Scene_DecrementTriggerCounter(world, trigger->flags.bytes.id);
                if (Scene_TestTriggerCounterZero(world, trigger->flags.bytes.id) != 0) {
                    Scene_ActivateTriggersOfKind(world, trigger->flags.bytes.id);
                }
            }
        } else {
            Link_ActivateTrigger(trigger);
        }
    }
}

/* 80279208_2.CPP */
extern s32 D_801371D4;

s32 Link_CheckTriggerMessage(void *trigger, struct Player *player) {
    func_80279490_S1 *object = trigger;
    NavigationPlatform *platform;

    if (object->unkA == D_801371D4) {
        if (player != 0) {
            platform = &D_8011BF00[object->unk4];
            if ((object->unk11 == 0xA) && (object->unk12 == 1)) {
                return Action_ShowTriggerMessage(platform, &platform->motion, player);
            }
        }
        return 1;
    }
    return 1;
}

/* 800C9C20.CPP */
/* ROM-grounded data: src/rw_pool_80278C10_CA820_us_rev1.c */
const unsigned int D_blob_68c3074edad0ea851da3[1] = {
    0x40800000,
};

#if defined(VERSION_DE)
unsigned int rodata_unresolved_800C4B34[3] = {
    0x3F800000, 0x3F800000, 0x40E00000,
};
#endif

/* 800C9C0C.CPP */

#if defined(VERSION_EU_X)
unsigned int rodata_unresolved_800C4E24[3] = {
    0x00000000, 0x43300000, 0x00000000,
};
#endif

#if defined(VERSION_EU)
unsigned int rodata_unresolved_800C4DE4[3] = {
    0xC4400000, 0x24A20001, 0x00402821,
};
#endif
