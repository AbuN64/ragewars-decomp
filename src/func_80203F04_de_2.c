#include "span_1000/code_80203F04.h"
#include "common/types_06e4f7ef1f9e.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "common/types_8fd754e1e915.h"
#include "common/unused.h"
#include "shared/level_actor.h"
#include "shared/world.h"
#include "span_1000/code_80206258.h"
#include "span_1000/code_80246E34.h"
#include "span_1000/code_80279208.h"
#include "span_C76B0/data.h"
#include "types.h"

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
    extern s32 func_80214178_de(void *, void *, s32);
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
    extern void func_80214178_de(void *a, void *b, int c); func_80214178_de(a, b, 0x1); }

void func_8020478C_de(Trigger *arg0) {
    func_8028B670_de(&D_8011FE88, (u16)arg0->unk8, (u32)arg0->unk4 >> 16, 1);
}

void func_802047BC_de(void *a, void *b) {
    extern void func_80214178_de(void *a, void *b, int c); func_80214178_de(a, b, 0x0); }

void func_802047D8_de(Trigger *arg0) {
    func_8028B670_de(&D_8011FE88, (u16)arg0->unk8, (u32)arg0->unk4 >> 16, 0);
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
