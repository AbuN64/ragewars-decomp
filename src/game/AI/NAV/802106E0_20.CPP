#include "COMMON/SELF.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHARED_WORLDFUNC.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/GAMEPLAY_TRANSITION.H"
#include "COMMON/LEVEL_ACTOR.H"
#include "COMMON/NAVIGATION_GRAPH.H"
#include "COMMON/SHAREDCALLBACK5.H"
#include "TYPES.H"
#include "AI/NAV/802106E0_20.H"

extern f32 D_800C20C0_de[];
extern s32 func_80209874_de(void *, s32);
extern void func_80208EB0_de(void *);
extern CNavData D_8013B364;

extern void func_80211020_de(void *);

extern s32 func_8020D1CC_de(void *, s32, s32);

extern f32 func_802726BC_de(f32 *, f32 *);

extern void Nav_SteerAlongRoute(void *);

extern f32 D_800C20C8_de;

extern void Nav_SelectFarthestReachableNeighbor(AiController *controller);

extern f32 func_802726BC_de(f32 *arg0, f32 *arg1);

extern f32 D_800C20CC_de;

extern void func_8020D014_de(void *arg0);

extern void func_8020D1FC_de(s32);

extern void *func_8020C994_de(void *arg0, s32 arg1);

extern void func_8020D220_de(void *, s32);

extern void func_8020D0CC_de(void *arg0, s32 arg1);

extern void func_8020D114_de(void *arg0, void *arg1, s32 arg2);

extern void func_80211020_de(void *arg0);

extern void Nav_UpdatePlayerSteering(void *arg0);

extern void Nav_SelectPlayerState(void *arg0);


extern void *func_8022A83C_de(char *);

extern void func_80209948_de(s32 *, s32);


void func_802127F4_de(void *actor) {
    void *brain;
    brain = (((struct ObjRecAt1454V2 *) ((s8 *) ((struct ObjRecAt1D8V1 *) ((s8 *) actor))->unk1D8))->unk1454);
    (((struct Brain_func_80212D78_eu_x *) ((s8 *) brain))->unk220) = 0;
    func_80209988_de(brain);
    (((struct Brain_func_80212D78_eu_x *) ((s8 *) brain))->unk2FC) = 0;
}

void func_80212828_de(CloseAttackActor *arg0)
{
    CloseAttackBrain *state;
    CloseAttackActor *peer;
    CloseAttackActor *peer_actor;
    CloseAttackBrain *peer_state;
    s32 value;

    state = arg0->self->brain;
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
        if (!func_8020D1CC_de(&D_8013B364, state->route, value)) {
            func_80209874_de(state, 1);
            return;
        }
    }

    func_80211020_de(state);
    Nav_SteerAlongRoute(state);
    func_80208EB0_de(state);
    if (func_802726BC_de(&peer_actor->pos.x,
                       &state->player->pos.x) < D_800C20C0_de[1] ||
        state->route == state->destination) {
        func_80209874_de(state, state->combat);
    }
}

/** Reset the inner record via func_80209988_de, then override two of its fields. */
void func_8021290C_de(LevelActor *actor) {
    Shared_ActorView *level1 = actor->controller;
    CloseAttackBrain *inner = level1->owner;
    inner->state = 0;
    func_80209988_de(inner);
    inner->reset2FC = 0;
    inner->destination = -1;
}

void Nav_UpdateRetreatMovement(void *actorObject)
{
    CloseAttackBrain *brain;
    CloseAttackActor *actor = actorObject;
    s32 previousDestination;

    brain = actor->self->brain;
    if (brain->target == 0) {
        func_80211020_de(brain);
        return;
    }

    previousDestination = brain->destination;
    if (previousDestination == -1) {
        Nav_SelectFarthestReachableNeighbor((AiController *)brain);
        if (brain->destination == previousDestination ||
            brain->destination == brain->route) {
            func_80209874_de(brain, 4);
            return;
        }
    }

    if (D_800C20C8_de < func_802726BC_de(
            &brain->target->self->pos.x,
            &brain->player->pos.x)) {
        func_80209874_de(brain, brain->combat);
        return;
    }

    func_80211020_de(brain);
    Nav_SteerAlongRoute(brain);
    func_80208EB0_de(brain);
    if (brain->route == brain->destination) {
        brain->destination = -1;
    }
}

/** Reset the inner record's flag fields, then clear its state via func_80209988_de. */
void func_80212A40_de(LevelActor *actor) {
    Shared_ActorView *level1 = actor->controller;
    CloseAttackBrain *inner = level1->owner;
    inner->state = 0;
    inner->destination = -1;
    func_80209988_de(inner);
    inner->reset2FC = 0;
}

void func_80212A7C_de(Shared_Actor *arg0)
{
    AiController *state;
    CNavData *table;
    NavigationPoint *entry;
    f32 threshold;
    s32 index;
    s32 value;
    u32 flags;

    state = ((Player *)arg0->entity)->controller;
    table = &D_8013B364;
    if (state->mode == -1) {
        func_8020D014_de(table);
        func_8020D1FC_de((s32)table);
        threshold = D_800C20CC_de;
        index = 0;
        if (table->m_nNavNodes > 0) {
            do {
                entry = func_8020C994_de(table, index);
                if (func_802726BC_de(&state->player->pos.x, entry) < threshold &&
                    !(navigation_attributes(entry) & 0x04300000)) {
                    func_8020D220_de(table, index);
                }
                index++;
            } while (index < table->m_nNavNodes);
        }
        func_8020D0CC_de(table, state->current);
        func_8020D114_de(table, &state->queue, 4);
        value = table->result;
        state->mode = value;
        state->routeGoal = value;
    }
    func_80211020_de(state);
    Nav_SteerAlongRoute(state);
    Nav_UpdatePlayerSteering(state);
    flags = (state->player->movementFlags & 0x3000) != 0;
    if (state->current == state->mode &&
        !flags) {
        Nav_SelectPlayerState(state);
    }
}

void func_80212BD0_de(void *actor) {
    void *brain;
    brain = (((struct ObjRecAt1454V2 *) ((s8 *) ((struct ObjRecAt1D8V1 *) ((s8 *) actor))->unk1D8))->unk1454);
    (((struct Brain_func_80212D78_eu_x *) ((s8 *) brain))->unk220) = 0;
    func_80209988_de(brain);
    (((struct Brain_func_80212D78_eu_x *) ((s8 *) brain))->unk2FC) = 0;
}

void func_80212C04_de(void *arg0) {
    s32 *rec;
    void *v0;

    ObjRecAt1D8V1 *object = arg0;
    ObjRecAt1454V1 *actor = object->unk1D8;

    rec = actor->unk1454;
    v0 = func_8022A83C_de((char *)&D_80145040);
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
    Nav_SteerAlongRoute(rec);
    func_80208EB0_de(rec);
}
