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
extern s32 func_8025DF34_de(s32 arg0);

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

extern void Camera_PostTargetedScreenMessage(void *, void *, s32, void *, f32);
extern s32 func_804030E0_de(s32);
void Actors_DispatchTrigger(Trigger *trigger) {
    NavCallbackPair *table;
    void *fallback;
    u8 index;
    s32 callback;
    table = D_800CD668_de[trigger->table];
    if (table != 0) {
        if (D_801462E5 == 0) {
            fallback = D_80145088.cameras;
            if (fallback == 0) fallback = &D_80145088.fallbackCamera;
        } else {
            fallback = &D_80145088.fallbackCamera;
        }
        if (D_8011FE88.mode == 4) {
            index = trigger->sound;
            if (index != 0) {
                Camera_PostTargetedScreenMessage(&D_80145088, fallback, gameplaySoundValue(index), D_800CD730, triggerSoundWeight());
                callback = gameplaySoundHook(trigger->sound);
                if (callback != 0) func_8025E11C_de(callback);
            }
            if (trigger->action >= 2) func_804030E0_de(trigger->action);
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
INCLUDE_ASM("span_1000", Actors_DispatchTrigger);
#endif

extern s32 func_80279204_de(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, void *arg6);

extern s32 func_8028C26C_de(s8 *arg0, void *arg1, s32 *arg2, s32 *arg3);

extern s32 func_8028C1D4_de(s8 *arg0, s32 arg1, s32 *arg2, s32 *arg3);

extern s32 func_8028BB1C_de(void *arg0, void *arg1, s32 arg2);


extern void func_8028D90C_de(void);

extern void func_80402FB4_de(s32, s32);

extern void func_80217388_de(void);

extern void func_80262C88_de(struct Shared_Actor *arg0);



void func_80278D78_de(struct Shared_Actor *actor, s32 arg1, void *arg2) {
    s32 sp20;
    s32 sp24;

    if (!(actor->weaponFlags & 0x80000)) {
        func_8028C26C_de(&D_8011FE88, actor, &sp20, &sp24);
        if (sp24 != 0) {
            func_80279204_de(sp20, sp24, 0, arg1 & 0x3FC1FF, arg1 & 0x400000, 0x400000, arg2);
        }
    }
}

void func_80278E04_de(s32 arg0, s32 arg1, void *actor) {
    s32 sp20;
    s32 sp24;

    if (arg0 != 0) {
        func_8028C1D4_de(&D_8011FE88, arg0, &sp20, &sp24);
        if (sp24 != 0) {
            func_80279204_de(sp20, sp24, 0, arg1 & 0x7FF, arg1 & 0x3800, 0x3800, actor);
        }
    }
}

void func_80278E7C_de(void *trigger) {
    func_80278EEC_S1 *object = trigger;

    object->unkE |= 0x10;
    func_8028BB1C_de(&D_8011FE88, trigger, 1);
    if ((D_8011FE88.mode == 4) && (object->unkE & 2)) {
        func_8028C568_de(&D_8011FE88, trigger);
        return;
    }
    Actors_DispatchTrigger(trigger);
}

void func_80278F00_de(Record14 *trigger) {
    Record14 copy;
    u8 *bytes = (u8 *)trigger;

    bytes[0xE] |= 0x20;
    if (bytes[0x11] == 1) {
        copy = *trigger;
        ((u8 *)&copy)[0x12] = 2;
        ((u8 *)&copy)[0x10] = 0;
        Actors_DispatchTrigger(&copy);
    }
}

/* Clears bits 0x2000 and 0x100 of the flag word at offset 0x100 of an object. */


void func_80278F68_de(struct LevelActor *object) {
    object->flags &= ~0x2000;
    object->flags &= ~0x100;
}

void func_80278F84_de(LevelActor *actor) {
    func_802472F0_de(actor);
    actor->flags = (s32) (actor->flags | 0x2100);
}

void func_80278FB4_de(s32 arg0, s32 unused1, s32 arg2) {
    if (D_8011FE88.mode == 4) {
        func_8028D90C_de();
        func_80402FB4_de(arg0, arg2);
    }
}

void func_80279004_de(s32 arg0) {
    if (D_8011FE88.mode == 4) {
        func_8028D90C_de();
        func_80402FB4_de(0, arg0);
    }
}

void func_80279048_de(void *arg0, void *arg1) {
    (((struct ObjectState104 *) ((s8 *) arg0))->unk_100) = (s32) ((((struct ObjectState104 *) ((s8 *) arg0))->unk_100) | 0x40000000);
    (((struct FloatState64 *) ((s8 *) arg1))->unk_48) = (f32) (((struct ObjectState104 *) ((s8 *) arg0))->unk_8);
    (((struct FloatState64 *) ((s8 *) arg1))->unk_4C) = (f32) (((struct ObjectState104 *) ((s8 *) arg0))->unk_C);
    (((struct FloatState64 *) ((s8 *) arg1))->unk_50) = (f32) (((struct ObjectState104 *) ((s8 *) arg0))->unk_10);
    (((struct FloatState64 *) ((s8 *) arg1))->unk_60) = (f32) (((struct ObjectState104 *) ((s8 *) arg0))->unk_6C);
}

void func_8027907C_de(s32 arg0, s32 arg1, Trigger *trigger) {
    if (trigger->unk6 >= 0x100) {
        func_8025E11C_de(trigger->unk6);
        return;
    }
    func_8025E2D4_de(trigger->unk6);
}

void func_802790C0_de(struct Shared_Actor *actor, s32 *stateFlags) {
    s32 flags;

    func_80217388_de();
    *stateFlags |= 0x20;
    flags = actor->weaponFlags & 0xFFFEFFFF;
    flags = flags & ~0x2000;
    flags = flags & ~0x100;
    actor->weaponFlags = flags;
    if (flags & 0x80000) {
        func_80262C88_de(actor);
    }
}

void func_80279138_de(int unused0, int unused1, void *arg2) {
    ObjRecAt6V2 *arg2_record = arg2;
    func_8025DF34_de(arg2_record->unk6);
}

void func_80279158_de(void *arg0) {
    func_8025E2D4_de((s32) (((struct ObjRecAt6V1 *) ((s8 *) arg0))->unk6));
}

void func_80279178_de(void *arg0) {
    func_8025DF34_de((((struct ObjRecAt6V2 *) ((s8 *) arg0))->unk6));
}
