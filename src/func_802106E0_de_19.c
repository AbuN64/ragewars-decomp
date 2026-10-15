#include "span_1000/code_802106E0.h"
#include "common/types_06e4f7ef1f9e.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "common/types_8fd754e1e915.h"
#include "shared/gameplay_transition.h"
#include "shared/level_actor.h"
#include "shared/navigation_graph.h"
#include "span_1000/code_80208000.h"
#include "types.h"

extern f32 D_800C20C0_de[];

extern void func_80211020_de(void *);

extern s32 func_8020D1CC_de(void *, s32, s32);

extern f32 func_802726BC_de(f32 *, f32 *);

extern void func_80208410_de(void *);

extern f32 D_800C20C8_de;

extern void func_80212670_de(void *arg0);

extern f32 func_802726BC_de(f32 *arg0, f32 *arg1);

extern f32 D_800C20CC_de;

extern void func_8020D014_de(void *arg0);

extern void func_8020D1FC_de(s32);

extern void *func_8020C994_de(void *arg0, s32 arg1);

extern void func_8020D220_de(void *, s32);

extern void func_8020D0CC_de(void *arg0, s32 arg1);

extern void func_8020D114_de(void *arg0, void *arg1, s32 arg2);

extern void func_80211020_de(void *arg0);

extern void func_80208AAC_de(void *arg0);

extern void func_8020FA10_de(void *arg0);

static inline u32 navigation_attributes(NavigationPoint *point) {
    u32 value;
    __builtin_memcpy(&value, &point->flags, sizeof(value));
    return value;
}

extern void *func_8022A83C_de(char *);

extern void func_80209948_de(s32 *, s32);

extern char D_80145040;

void func_802127F4_de(void *arg0) {
    void *temp_s0;
    temp_s0 = (((struct ObjRecAt1454V2 *) ((s8 *) ((struct ObjRecAt1D8V1 *) ((s8 *) arg0))->unk1D8))->unk1454);
    (((struct Brain_func_80212D78_eu_x *) ((s8 *) temp_s0))->unk220) = 0;
    func_80209988_de(temp_s0);
    (((struct Brain_func_80212D78_eu_x *) ((s8 *) temp_s0))->unk2FC) = 0;
}

void func_80212828_de(void *arg0)
{
    extern void func_80209874_de(void *, s32);
    extern void func_80208EB0_de(void *);
    extern char D_8013B364[];
    CloseAttackBrain *state;
    CloseAttackActor *peer;
    CloseAttackActor *peer_actor;
    CloseAttackBrain *peer_state;
    s32 value;

    state = ((CloseAttackActor *)arg0)->self->brain;
    peer = state->target;
    if (peer == 0) {
        func_80211020_de(state);
        return;
    }

    peer_actor = peer->self;
    peer_state = peer_actor->brain;
    value = peer_state->route;
    state->destination = value;
    if (value != state->node) {
        state->node = value;
        if (!func_8020D1CC_de(D_8013B364, state->route, value)) {
            func_80209874_de(state, 1);
            return;
        }
    }

    func_80211020_de(state);
    func_80208410_de(state);
    func_80208EB0_de(state);
    if (func_802726BC_de(&peer_actor->pos.x,
                       &state->player->pos.x) < D_800C20C0_de[1] ||
        state->route == state->destination) {
        func_80209874_de(state, state->combat);
    }
}

/** Reset the inner record via func_80209988_de, then override two of its fields. */
void func_8021290C_de(void *arg0) {
    Shared_ActorView *level1 = ((LevelActor *)arg0)->controller;
    CloseAttackBrain *inner = level1->owner;
    inner->state = 0;
    func_80209988_de(inner);
    inner->reset2FC = 0;
    inner->destination = -1;
}

void func_80212948_de(void *arg0)
{
    extern s32 func_80209874_de(void *, s32);
    extern void func_80208EB0_de(s32 *);
    CloseAttackBrain *state;
    CloseAttackActor *actor = arg0;
    s32 old_state;

    state = actor->self->brain;
    if (state->target == 0) {
        func_80211020_de(state);
        return;
    }

    old_state = state->destination;
    if (old_state == -1) {
        func_80212670_de(state);
        if (state->destination == old_state ||
            state->destination == state->route) {
            func_80209874_de(state, 4);
            return;
        }
    }

    if (D_800C20C8_de < func_802726BC_de(
            &state->target->self->pos.x,
            &state->player->pos.x)) {
        func_80209874_de(state, state->combat);
        return;
    }

    func_80211020_de(state);
    func_80208410_de(state);
    func_80208EB0_de(state);
    if (state->route == state->destination) {
        state->destination = -1;
    }
}

/** Reset the inner record's flag fields, then clear its state via func_80209988_de. */
void func_80212A40_de(void *arg0) {
    Shared_ActorView *level1 = ((LevelActor *)arg0)->controller;
    CloseAttackBrain *inner = level1->owner;
    inner->state = 0;
    inner->destination = -1;
    func_80209988_de(inner);
    inner->reset2FC = 0;
}

void func_80212A7C_de(void *arg0)
{
    extern char D_8013B364;
    AiController *state;
    NavigationGraph *table;
    NavigationPoint *entry;
    f32 threshold;
    s32 index;
    s32 value;
    u32 flags;

    state = ((Player *)((Shared_Actor *)arg0)->entity)->controller;
    table = (NavigationGraph *)&D_8013B364;
    if (state->mode == -1) {
        func_8020D014_de(table);
        func_8020D1FC_de((s32)table);
        threshold = D_800C20CC_de;
        index = 0;
        if (table->pointCount > 0) {
            do {
                entry = func_8020C994_de(table, index);
                if (func_802726BC_de(&state->player->pos.x, entry) < threshold &&
                    !(navigation_attributes(entry) & 0x04300000)) {
                    func_8020D220_de(table, index);
                }
                index++;
            } while (index < table->pointCount);
        }
        func_8020D0CC_de(table, state->current);
        func_8020D114_de(table, &state->queue, 4);
        value = table->result;
        state->mode = value;
        state->routeGoal = value;
    }
    func_80211020_de(state);
    func_80208410_de(state);
    func_80208AAC_de(state);
    flags = (state->player->movementFlags & 0x3000) != 0;
    if (state->current == state->mode &&
        !flags) {
        func_8020FA10_de(state);
    }
}

void func_80212BD0_de(void *arg0) {
    void *temp_s0;
    temp_s0 = (((struct ObjRecAt1454V2 *) ((s8 *) ((struct ObjRecAt1D8V1 *) ((s8 *) arg0))->unk1D8))->unk1454);
    (((struct Brain_func_80212D78_eu_x *) ((s8 *) temp_s0))->unk220) = 0;
    func_80209988_de(temp_s0);
    (((struct Brain_func_80212D78_eu_x *) ((s8 *) temp_s0))->unk2FC) = 0;
}

void func_80212C04_de(void *arg0) {
    extern s32 func_80209874_de(void *, s32);
    extern void func_80208EB0_de(s32 *);
    s32 *rec;
    void *v0;

    ObjRecAt1D8V1 *object = arg0;
    ObjRecAt1454V1 *actor = object->unk1D8;

    rec = actor->unk1454;
    v0 = func_8022A83C_de(&D_80145040);
    if (v0 == (void *) *rec) {
        func_80209874_de(rec, 10);
        return;
    }
    if (v0 != 0) {
        func_80209874_de(rec, 2);
        return;
    }
    func_80211020_de(rec);
    func_80209948_de(rec, rec[3]);
    func_80208410_de(rec);
    func_80208EB0_de(rec);
}
