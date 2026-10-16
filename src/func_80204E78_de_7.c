#include "span_1000/code_80204E78.h"
#include "audio_callbacks.h"
#include "common/types_06e4f7ef1f9e.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "common/unused.h"
#include "resident_event_handler.h"
#include "shared/func_8027AD4C_de_closed.h"
#include "shared/func_80425674_de_layout.h"
#include "shared/level_actor.h"
#include "shared/world.h"
#include "span_1000/code_80203F04.h"
#include "span_1000/code_80206258.h"
#include "span_1000/code_802624A0.h"
#include "span_1000/code_80279208.h"
#include "span_1000/code_8028FC98.h"
#include "types.h"

/* Dispatch configured object, particle, or weighted-choice spawns and update the owner count. */


extern f32 func_80275DD4_de(Node75 *node, f32 x, f32 z);

extern void *func_8028CF6C_de(void *arg0, s32 arg1);

extern int func_8028B25C_de(void *arg0, int arg1);

struct Context;
extern s32 func_8022A8F0_de(struct Context *arg0);

extern int func_8022A414_de(void *arg0);

extern void func_8027985C_de(WeightedTable *object);

extern s32 func_80279864_de(WeightedTable *arg0, s16 arg1, s16 arg2);

extern s16 func_802798A8_de(WeightedTable *arg0);

extern SceneEffect *func_80262CE0_de(void *scene, s32 id, s32 variant, s32 count, s32 owner, Vec3 position, f32 scale, Vec3 direction, Vec3 color, s32 *ref);

extern s32 func_802800C0_de(EffectSystem *sys, EffectActor *source, EffectActor *owner, s32 *refCount, s32 arg4, s32 kind, Vec3 arg6, Vector4f rotation, Vec3 pos, Vec3 *aim, s32 arg10, s32 arg11);

extern void *func_8028FFD0_de(char *arg0, s32 *arg1, s32 arg2, Vec3 rotation, Vec3 position, s32 arg9, f32 arg10);

extern char D_8011D8D0[];


extern u8 *D_800E4680;


static __inline__ SpawnChoice *spawnTable0(void) {
    extern SpawnChoice D_800C8510_de[];
    return D_800C8510_de;
}

static __inline__ SpawnChoice *spawnTable1(void) {
    extern SpawnChoice D_800C8510_de[];
    return D_800C8510_de + 1;
}

static __inline__ SpawnChoice *spawnTable2(void) {
    extern SpawnChoice D_800C8518_de[];
    return D_800C8518_de;
}

static __inline__ SpawnChoice *spawnTable3(void) {
    extern SpawnChoice D_800C8528_de[];
    return D_800C8528_de;
}

static __inline__ SpawnChoice *spawnTable4(void) {
    extern SpawnChoice D_800C8534_de[];
    return D_800C8534_de;
}

static __inline__ SpawnChoice *spawnTable5(void) {
    extern SpawnChoice D_800C8544_de[];
    return D_800C8544_de;
}

static __inline__ SpawnChoice *spawnTable6(void) {
    extern SpawnChoice D_800C8548[];
    return D_800C8548;
}

static __inline__ s32 spawnBlocked(void) {
    extern s32 D_80142860;
    return D_80142860;
}

static __inline__ s32 available(s32 id) {
    SpawnDispatchActor *actor;
    if (id == 0x84F) {
        actor = D_80137064.head;
        while (actor) {
            if (*actor->definition == 4) {
                return 0;
            }
            actor = actor->next;
        }
        return func_8022A8F0_de(&D_80145040) == 0;
    }
    return 1;
}

static __inline__ s32 availableChoice(s32 id) {
    SpawnDispatchActor *actor;
    if (id != 0x84F) {
        id = 1;
        goto done;
    }
    actor = D_80137064.head;
    while (actor) {
        if (*actor->definition == 4) {
            return id = 0;
        }
        actor = actor->next;
    }
    return id = func_8022A8F0_de(&D_80145040) == 0;
done:
    return id;
}

static __inline__ s32 copySpawnId(s32 id) {
    if (id < 0) {
        return id;
    }
    return id;
}

static __inline__ void spawn(SpawnDispatchObject *object, s32 id,
        Vec3 position, SpawnDispatchOwner *owner, void *world) {
    SpawnDispatchActor *actor;
    id = copySpawnId(id);
    if (id == 0xBD7 && D_80146918 && spawnBlocked()) {
        return;
    }
    if (id == 0x1388 && D_801462D5 == 1) {
        id = *D_800E4680 + 0x1388;
        if (id == 0x1388) {
            return;
        }
    }
    actor = func_8028FFD0_de(&D_80131600, &owner->spawn, id,
        object->rotation, position, (s32)world, 0);
    if (actor) {
        actor->state = 0;
        owner->remaining--;
        func_80216288_de(actor, 0x11D, actor->position, 0);
    }
}

static __inline__ void spawnSelected(SpawnDispatchObject *object, SpawnDispatchOwner *owner, s32 id,
        void *world, Vec3 position) {
    SpawnDispatchActor *actor;
    if (id == 0xBD7 && D_80146918 && spawnBlocked()) {
        return;
    }
    if (id == 0x1388 && D_801462D5 == 1) {
        id = *D_800E4680 + 0x1388;
        if (id == 0x1388) {
            return;
        }
    }
    actor = func_8028FFD0_de(&D_80131600, &owner->spawn, id,
        object->rotation, position, (s32)world, 0);
    if (actor) {
        actor->state = 0;
        owner->remaining--;
        func_80216288_de(actor, 0x11D, actor->position, 0);
    }
}

static __inline__ void spawnParticles(SpawnDispatchObject *object, SpawnDispatchOwner *owner,
        Vec3 position, Vec3 velocity, s32 type, s32 *entry, void *world) {
    if (func_80262CE0_de(&D_80131150, type, 0, (s32)entry, (s32)world, position,
            object->scale, object->rotation, velocity, &owner->spawn)) {
        owner->remaining--;
    }
}

static __inline__ void spawnGroup(SpawnDispatchObject *object, SpawnDispatchOwner *owner,
        Vec3 position, s32 count) {
    owner->remaining -= func_802800C0_de((EffectSystem *)D_8011D8D0, (EffectActor *)object, (EffectActor *)object, &owner->spawn,
            0, count, object->rotation, object->motion, position, 0, -1, 0);
}



extern u8 D_801462E5[];



extern void func_80214178_de(Actor_func_80205F18_de *actor, Action *action, s32 arg2);

extern s32 func_80285F58_de(void *, void *);

/* Retained ROM words preceding this unit's generated jump table. */
#if defined(VERSION_EU)
const u32 D_auto_rodata_unresolved_800C1D38[2] = {
    0x00031880, 0x96230004,
};
#endif

void func_80205720_de(SpawnDispatchObject *object, SpawnDispatchOwner *owner) {
    Vec3 position;
    Vec3 velocity;
    WeightedTable picker;
    WeightedTable otherPicker;
    void *world;
    SpawnDefinition *definition;
    s32 *entry;
    SpawnChoice *choice;
    SpawnDispatchActor *actor;
    s32 first, second;
    s32 third;
    s32 id;
    s32 context;
    f32 height;

    definition = &object->definition->spawn;
    position = object->position;
    world = object->world;
    if (world) {
        height = func_80275DD4_de(world, object->position.x, object->position.z);
        if (position.y < height) {
            position.y = height;
        }
    }
    switch (definition->kind) {
    case 0:
        entry = func_8028CF6C_de(&D_8011FE88, definition->selector);
        switch (*entry) {
        case 8:
            id = func_8028B25C_de(&D_8011FE88, definition->id);
            if (!available(id)) {
                return;
            }
            spawn(object, id, position, owner, world);
            return;
        case 1: case 2: case 3: case 4: case 5:
        case 6: case 7: case 9: case 10:
            velocity.x = definition->velocity.x;
            velocity.y = definition->velocity.y;
            velocity.z = definition->velocity.z;
            spawnParticles(object, owner, position, velocity, definition->id, entry, world);
            break;
        }
        return;
    case 1:
        spawnGroup(object, owner, position, definition->count);
        return;
    case 2:
        first = -1;
        second = -1;
        third = -1;
        if (((SpawnDispatchConfig *)&D_801462C8)->enabled) {
            if (definition->flags & 0x20) {
                first = (s16)func_80279798_de((s16 *)spawnTable1());
            }
            if (definition->flags & 0x40) {
                second = (s16)func_80279798_de((s16 *)spawnTable4());
            }
            if (definition->flags & 0x80) {
                func_8027985C_de(&otherPicker);
                choice = spawnTable6();
                while (choice->id != -1) {
                    if (availableChoice(choice->id)) {
                        func_80279864_de(&otherPicker, choice->id, choice->weight);
                    }
                    choice++;
                }
                third = (s16)func_802798A8_de(&otherPicker);
            }
        } else {
            /* Configuration lies 0x1288 bytes into the shared runtime block. */
            context = func_8022A414_de((u8 *)&D_801462C8 - 0x1288);
            if (!context) {
                return;
            }
            if (definition->flags & 0x20) {
                func_8027985C_de(&picker);
                choice = spawnTable0();
                while (choice->id != -1) {
                    if (func_80222D64_de((void *)context, choice->id)) {
                        func_80279864_de(&picker, choice->id, choice->weight);
                    }
                    choice++;
                }
                first = (s16)func_802798A8_de(&picker);
            }
            if (definition->flags & 0x40) {
                func_8027985C_de(&picker);
                choice = spawnTable2();
                if (D_8013B290) {
                    choice = spawnTable3();
                }
                while (choice->id != -1) {
                    if (func_8022ADB0_de((void *)context, choice->id)) {
                        func_80279864_de(&picker, choice->id, choice->weight);
                    }
                    choice++;
                }
                second = (s16)func_802798A8_de(&picker);
            }
            if (definition->flags & 0x80) {
                third = (s16)func_80279798_de((s16 *)spawnTable5());
            }
        }
        func_8027985C_de(&picker);
        if (first != -1) {
            func_80279864_de(&picker, first, 100);
        }
        if (second != -1) {
            func_80279864_de(&picker, second, 100);
        }
        if (third != -1) {
            func_80279864_de(&picker, third, 100);
        }
        if (!picker.count) {
            return;
        }
        id = (s16)func_802798A8_de(&picker);
        spawnSelected(object, owner, id, world, position);
        return;
    }
}

void func_80205EC4_de(void *arg0, void *arg1) {
    LevelActor *actor = arg0;
    ActorMotionState *state = arg1;
    BreakableDefinition *inner = (BreakableDefinition *)actor->definition;

    state->table = &D_800C854C;
    state->update = &D_00206018;
    if ((actor->type == 0x644) ||
        (inner->flags & 8)) {
        actor->flags &= ~0x2000;
    }
}

/* Starts an eligible actor action with a random delay and descriptor duration, applies its flags and callback, then clears the pending flag when required. */
void func_80205F18_de(Actor_func_80205F18_de *actor, Action *action) {
    ActionInfo *info = &actor->desc->info;
    if ((info->flags & 0x10) && (D_801462E5[0] == 0 || D_801462E5[1] != 1)) {
        actor->flags &= ~0x100;
        return;
    }
    action->delay = func_80274A90_de(D_800C1AC8_de, D_800C1ACC_de);
    action->timer = 0;
    action->duration = info->duration;
    if (actor->model == 0x644 || (info->flags & 8)) actor->flags &= ~0x2000;
    func_80214178_de(actor, action, 0);
    if (!(info->flags & 0x10) || D_80142226 == 1) return;
    actor->flags &= ~0x100;
}

void func_80206018_de(void *arg0, EventRecAt30 *arg1) {
    CallbackHolder *holder;
    s32 different;

    different = func_80285F58_de(&D_8011FE88, arg0) != 1;
    if (different == 0) {
        holder = arg1->holder;
        if ((holder != 0) && (holder->callback != 0)) {
            holder->callback(arg0, arg1);
        }
    }
}
