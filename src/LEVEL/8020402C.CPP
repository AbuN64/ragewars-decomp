#include "include_asm.h"
#include "COMMON/OBJRECAT30.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/UNUSED.H"
#include "COMMON/LEVEL_ACTOR.H"
#include "COMMON/WORLD.H"
#include "COMMON/REC.H"
#include "COMMON/OBJECTLINKS180_2.H"
#include "COMMON/LISTHEADER.H"
#include "COMMON/TRIPLE.H"
#include "TYPES.H"
#include "LEVEL/8020402C.H"
#include "WEAPONS/80213ED4.H"

#if defined(VERSION_US)
INCLUDE_ASM("span_1000", func_8020402C_us);
#endif

#if defined(VERSION_EU_X)
INCLUDE_ASM("span_1000", func_80204030_eu_x);
#endif

#if defined(VERSION_EU)
INCLUDE_ASM("span_1000", func_80204030_eu);
#endif

#if defined(VERSION_DE)
INCLUDE_ASM("span_1000", func_80204030_de);
#endif

#if defined(VERSION_US_REV1)
#ifdef NON_MATCHING
#define LV_FIELD(base, type, offset) (*(type *)((u8 *)(base) + (offset)))
extern s32 D_auto_800D70DC;
extern f32 D_800C6B40;
extern u8 *func_8022A420_de(u8 *);
extern f32 func_802B72B0_de(f32);
extern void func_8022E17C_de(void *, void *, s32);
extern void func_80237E80_de(u8 *, void *, s32);
void func_80204030_us_rev1(u8 *self, u8 *hit) {
    u8 *state = LV_FIELD(self, u8 *, 0x18) + 0x14;
    u16 kind = LV_FIELD(self, u16, 0xE4);
    u8 *player;
    u8 *table;
    u8 *record;
    u8 *node;
    f32 dx, dy, dz;
    f32 distance;
    s32 sound;
    if (kind == 0x64E) {
        player = func_8022A420_de((u8 *)&D_80145040);
        if (player != 0 && LV_FIELD(player, s32, 0x5E4) != 0 && LV_FIELD(hit, s8, 0x36) != LV_FIELD(hit, s8, 0x34)) {
            table = (u8 *)&D_80145040 + 0x1860;
            if (LV_FIELD(table, s32, 0x68) == 0 && LV_FIELD(hit, s32, 0x12C) == 0) {
                record = LV_FIELD(player, u8 *, 0x5D8);
                if (LV_FIELD(record, u8, 0x8F) == 1) {
                    LV_FIELD(record, u8, 0x8F) = 0;
                    LV_FIELD(LV_FIELD(player, u8 *, 0x5D8), u8, 0x90) = 1;
                    LV_FIELD(table, s32, 0x74) = 1;
                    LV_FIELD(hit, s32, 0x12C) = 1;
                    func_8025DF34_de(0xE0D);
                }
            }
        }
    } else if (kind >= 0x653 && kind < 0x657) {
        if (LV_FIELD(hit, s8, 0x36) == LV_FIELD(hit, s8, 0x34)) {
            return;
        }
        player = func_8022A420_de((u8 *)&D_80145040);
        if (player == 0 || LV_FIELD(LV_FIELD(player, u8 *, 0x5D8), u8, 0x8F) == 0) {
            return;
        }
        dx = LV_FIELD(player, f32, 8) - LV_FIELD(self, f32, 8);
        dy = LV_FIELD(player, f32, 0xC) - LV_FIELD(self, f32, 0xC);
        dz = LV_FIELD(player, f32, 0x10) - LV_FIELD(self, f32, 0x10);
        distance = func_802B72B0_de(dx * dx + dy * dy + dz * dz);
        if ((f32)(s32)distance >= D_800C6B40) {
            return;
        }
        record = LV_FIELD(player, u8 *, 0x5D8);
        LV_FIELD(record, u8, 0x8F) = 0;
        LV_FIELD(LV_FIELD(player, u8 *, 0x5D8), u8, 0x90) = 1;
        LV_FIELD(LV_FIELD(player, u8 *, 0x5D8), u16, 8) += 1;
        func_8022E17C_de(player, player, 3);
        table = (u8 *)&D_80145040 + 0x1860;
        LV_FIELD(table, s32, 0x84) = 0;
        LV_FIELD(table, s32, 0x80) = 0;
        switch (LV_FIELD(LV_FIELD(player, u8 *, 0x5D8), u8, 0x92)) {
        case 0:
            sound = 0x2E6;
            break;
        case 1:
            sound = 0x2E4;
            break;
        case 2:
            sound = 0x2E8;
            break;
        case 3:
            sound = 0x2EC;
            break;
        case 4:
            sound = 0x2EA;
            break;
        default:
            sound = -1;
            break;
        }
        if (sound != -1) {
            func_8025DF34_de(sound);
        }
        for (node = *(u8 **)&D_80145060; node != 0; node = LV_FIELD(node, u8 *, 0x16E0)) {
            if (LV_FIELD(node, void *, 0x5DC) != 0) {
                func_80237E80_de((u8 *)&D_80145088, LV_FIELD(node, void *, 0x5DC), D_auto_800D70DC);
            }
        }
    }
    if (LV_FIELD(hit, s8, 0xCB) != 0) {
        if (LV_FIELD(state, u32, 0) & 2) {
            LV_FIELD(self, u32, 0x100) = LV_FIELD(self, u32, 0x100) & ~0x2000 & ~0x100;
        }
        if (LV_FIELD(hit, s32, 0x128) != 0) {
            func_80214178_de(self, hit, 0);
        }
        if (LV_FIELD(self, u16, 0xE4) == 0x64C) {
            func_80214178_de(self, hit, 2);
        }
    }
}
#else
INCLUDE_ASM("span_1000", func_80204030_us_rev1);
#endif
#endif

#include "COMMON/GAMEPLAY_SOUND_TABLE.H"
#include "TYPES.H"
typedef struct SoundParent { char pad0[0x5DC]; void *emitter; } SoundParent;
typedef struct SoundActor {
    u8 kind; char pad1[0xFF]; s32 flags;
    char pad104[0x1D8 - 0x104]; SoundParent *parent;
} SoundActor;
#include "COMMON/MENU_MATCH_GLOBALS.H"
extern char D_80141008;
extern void func_80239908_de(void *, void *, s32, void *, f32);
#include "COMMON/OBJECTLINKS14.H"
/* EU/EU-X: this body is 56/57 words; reorg picks beqz (target beql) for the flags check, so those versions
 * keep their asm. */
#if !defined(VERSION_EU) && !defined(VERSION_EU_X)
s32 func_80204308_de(struct NavigationPlatform *object, ActorMotionState *guard, struct Player *player) {
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
    fallback = &D_80141008;
    if (emitter != 0) fallback = emitter;
    func_80239908_de(&D_80145088, fallback, gameplaySoundValue(index), object, gameplaySoundWeight());
    index = record->soundIndex;
    callback = gameplaySoundHook(index);
    if (callback != 0) func_8025E11C_de(callback);
    return 0;
}
#else
INCLUDE_ASM("span_1000", func_80204308_de);
#endif

typedef struct Owner Owner;




extern s32 func_80285F58_de(void *, void *);

extern void func_80285DB0_de(Shared_World *, void *, s32);

extern void func_80278D78_de(void *arg0, s32 arg1, void *arg2);

struct SceneRecAt95A8;
extern void func_802A5D38_de(struct SceneRecAt95A8 *, s32);

extern void func_8028B670_de(void *a, unsigned short b, unsigned short c, int d);

/* Supplies the nonnegative blend remaining after the incoming strength is
 * scaled, then applies the actor animation using the original lookup. */
struct InputRecAt40 {
    char pad0[0x40];
    f32 strength;
};



extern s32 D_800D15E0;

extern f32 D_800D15F0;

extern void func_8024A1D0_de(Actor_func_8024A1D0_de *, void *, Lookup *);

/** Run the object's optional update hook, then copy one of two byte pairs into the record header. */







void func_802043E0_de(char *arg0, char *arg1) {
    Owner *owner = (void *)arg0;
    ObjRecAt30 *event = (void *)arg1;
    char *base = owner->track + 0x14;
    Hook *hook = event->unk30;

    if (hook != 0 && hook->fn != 0) {
        hook->fn(arg0, arg1);
    }
    if (arg1[0x34] == 0) {
        arg0[1] = base[0xE];
        arg0[3] = base[0xF];
    } else {
        arg0[1] = base[0x1A];
        arg0[3] = base[0x1B];
    }
}

void func_80204468_de(LevelActor *arg0, ActorMotionState *arg1) {
    arg1->table = &D_800C8274;
    arg1->update = &D_002043E0;
    arg1->unk124 = 0;
    arg1->unk128 = 0;
    arg1->unk12C = 0;
    if (((BreakableDefinition *)arg0->definition)->flags & 1) {
        arg0->flags = arg0->flags | 0x10000;
        return;
    }
    arg0->flags = arg0->flags & 0xFFFEFFFF;
}

/** Update actor state and clear flags for the relevant actor classes. */
void func_802044C8_de(SharedPlayer *actor, void *state) {
    s32 flags;

    if (func_80285F58_de(&D_8011FE88, actor) == 1) {
        func_80214178_de(actor, state, 1);
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
        D_800C8270_de = 1;
        func_80214178_de(actor, state, 0);
        D_800C8270_de = 0;
    }
}

/* The kind-10 actor initializer installs the state table containing this callback. */
s32 func_8020459C_de(LevelActor *actor) {
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

void func_802045CC_de(void *arg0, void *arg1) {
    ActorMotionState *state = arg1;
    func_80285DB0_de(&D_8011FE88, arg0, 0);
    func_80278D78_de(arg0, 0x200000, arg0);
    state->unk12C = 0;
}

s32 func_80204620_de(LevelActor *arg0) {
    s32 val;

    val = ((BreakableDefinition *)arg0->definition)->health;
    if (val != 0) {
        arg0->flags = arg0->flags | 0x2000;
    } else {
        s32 flags = arg0->flags & ~0x2000;
        flags &= ~0x100;
        arg0->flags = flags;
    }
    return val;
}

void func_80204658_de(void *arg0) {
    BreakableDefinition *temp_s1;
    s32 temp_v1;
    s32 masked;
    Shared_World *pFlag;

    temp_s1 = (BreakableDefinition *)((LevelActor *)arg0)->definition;
    pFlag = &D_8011FE88;
    func_80285DB0_de(pFlag, arg0, 1);
    if (D_800C8270_de == 0) {
        func_80278D78_de(arg0, 0x80000, arg0);
    }
    func_802A5D38_de(&D_801379C0, arg0);
    if (pFlag->mode != 4) {
        temp_v1 = ((LevelActor *)arg0)->flags | 0x08000000;
        ((LevelActor *)arg0)->flags = temp_v1;
        if (temp_s1->flags & 2) {
            masked = temp_v1 & ~0x2000;
            masked = masked & ~0x100;
            ((LevelActor *)arg0)->flags = masked;
        }
        if (((BreakableDefinition *)((LevelActor *)arg0)->definition)->health == 0) {
            ((LevelActor *)arg0)->flags = ((LevelActor *)arg0)->flags & ~0x100;
        }
    }
}

void func_80204728_de(void *arg0, void *arg1) {
    Dest *state = arg1;
    state->draw = &D_00204808;
}

/** Clear two flag groups when the object's 0x1B0 field exceeds a tunable. */
void func_80204738_de(LevelActor *object) {
    if (object->motionThreshold > D_800C1A70_de) {
        int flags = object->flags;
        flags &= ~0x2000;
        flags &= ~0x100;
        object->flags = flags;
    }
}

void func_80204770_de(void *a, void *b) {
    func_80214178_de(a, b, 0x1); }

void func_8020478C_de(Trigger *arg0) {
    func_8028B670_de(&D_8011FE88, arg0->owner, arg0->actor, 1);
}

void func_802047BC_de(void *a, void *b) {
    func_80214178_de(a, b, 0x0); }

void func_802047D8_de(Trigger *arg0) {
    func_8028B670_de(&D_8011FE88, arg0->owner, arg0->actor, 0);
}

void func_80204808_de(Actor_func_8024A1D0_de *actor, struct InputRecAt40 *input, Lookup *lookup) {
    f32 remaining = D_800C1A78_de - input->strength * D_800C1A74_de;
    D_800D15E0 = 1;
    if (remaining < 0.0f) {
        remaining = 0.0f;
    }
    D_800D15F0 = remaining;
    func_8024A1D0_de(actor, input, lookup);
}

#if defined(VERSION_EU)
INCLUDE_DATA("span_1000", func_80204808_de_padding_548C);
#endif

#if defined(VERSION_DE) || defined(VERSION_US)
INCLUDE_DATA("span_1000", func_80204868_de_padding_5468);
#endif
