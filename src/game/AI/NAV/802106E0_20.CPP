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
extern s32 Nav_SetBehaviourState(void *, s32);
extern void Nav_UpdateTargetSteering(void *);
extern CNavData D_8013B364;

extern void Nav_RunBehaviorHandler(void *);

extern s32 Nav_GetRouteRelation(void *, s32, s32);

extern f32 GraphU64_GetSquaredDistance(f32 *, f32 *);

extern void Nav_SteerAlongRoute(void *);

extern f32 D_800C20C8_de;

extern void Nav_SelectFarthestReachableNeighbor(AiController *controller);

extern f32 GraphU64_GetSquaredDistance(f32 *arg0, f32 *arg1);

extern f32 D_800C20CC_de;

extern void Nav_ResetSearchState(void *arg0);

extern void Nav_ClearGoalList(s32);

extern void *Nav_GetGraphPoint(void *arg0, s32 arg1);

extern void Nav_AddGoalNode(void *, s32);

extern void Nav_SearchPathByKey(void *arg0, s32 arg1);

extern void Nav_ReconstructSearchPath(void *arg0, void *arg1, s32 arg2);

extern void Nav_RunBehaviorHandler(void *arg0);

extern void Nav_UpdatePlayerSteering(void *arg0);

extern void Nav_SelectPlayerState(void *arg0);



extern f32 Nav_DistanceToNode(s32 *, s32);


void func_802127F4_de(void *actor) {
    void *brain;
    brain = (((struct ObjRecAt1454V2 *) ((s8 *) ((struct ObjRecAt1D8V1 *) ((s8 *) actor))->unk1D8))->unk1454);
    (((struct Brain_func_80212D78_eu_x *) ((s8 *) brain))->unk220) = 0;
    Nav_ResetBehaviorState(brain);
    (((struct Brain_func_80212D78_eu_x *) ((s8 *) brain))->unk2FC) = 0;
}

void Nav_ApproachCombatTargetAlongRoute(CloseAttackActor *arg0)
{
    CloseAttackBrain *state;
    CloseAttackActor *peer;
    CloseAttackActor *peer_actor;
    CloseAttackBrain *peer_state;
    s32 value;

    state = arg0->self->brain;
    peer = state->target;
    if (peer == 0) {
        Nav_RunBehaviorHandler(state);
        return;
    }

    peer_actor = peer->self;
    peer_state = peer_actor->brain;
    value = peer_state->route;
    state->destination = value;
    if (value != state->node) {
        state->node = value;
        if (!Nav_GetRouteRelation(&D_8013B364, state->route, value)) {
            Nav_SetBehaviourState(state, 1);
            return;
        }
    }

    Nav_RunBehaviorHandler(state);
    Nav_SteerAlongRoute(state);
    Nav_UpdateTargetSteering(state);
    if (GraphU64_GetSquaredDistance(&peer_actor->pos.x,
                       &state->player->pos.x) < D_800C20C0_de[1] ||
        state->route == state->destination) {
        Nav_SetBehaviourState(state, state->combat);
    }
}

/** Reset the inner record via Nav_ResetBehaviorState, then override two of its fields. */
void func_8021290C_de(LevelActor *actor) {
    Shared_ActorView *level1 = actor->controller;
    CloseAttackBrain *inner = level1->owner;
    inner->state = 0;
    Nav_ResetBehaviorState(inner);
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
        Nav_RunBehaviorHandler(brain);
        return;
    }

    previousDestination = brain->destination;
    if (previousDestination == -1) {
        Nav_SelectFarthestReachableNeighbor((AiController *)brain);
        if (brain->destination == previousDestination ||
            brain->destination == brain->route) {
            Nav_SetBehaviourState(brain, 4);
            return;
        }
    }

    if (D_800C20C8_de < GraphU64_GetSquaredDistance(
            &brain->target->self->pos.x,
            &brain->player->pos.x)) {
        Nav_SetBehaviourState(brain, brain->combat);
        return;
    }

    Nav_RunBehaviorHandler(brain);
    Nav_SteerAlongRoute(brain);
    Nav_UpdateTargetSteering(brain);
    if (brain->route == brain->destination) {
        brain->destination = -1;
    }
}

/** Reset the inner record's flag fields, then clear its state via Nav_ResetBehaviorState. */
void func_80212A40_de(LevelActor *actor) {
    Shared_ActorView *level1 = actor->controller;
    CloseAttackBrain *inner = level1->owner;
    inner->state = 0;
    inner->destination = -1;
    Nav_ResetBehaviorState(inner);
    inner->reset2FC = 0;
}

void Nav_SeekNearbyUnrestrictedGoal(Shared_Actor *arg0)
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
        Nav_ResetSearchState(table);
        Nav_ClearGoalList((s32)table);
        threshold = D_800C20CC_de;
        index = 0;
        if (table->m_nNavNodes > 0) {
            do {
                entry = Nav_GetGraphPoint(table, index);
                if (GraphU64_GetSquaredDistance(&state->player->pos.x, entry) < threshold &&
                    !(navigation_attributes(entry) & 0x04300000)) {
                    Nav_AddGoalNode(table, index);
                }
                index++;
            } while (index < table->m_nNavNodes);
        }
        Nav_SearchPathByKey(table, state->current);
        Nav_ReconstructSearchPath(table, &state->queue, 4);
        value = table->result;
        state->mode = value;
        state->routeGoal = value;
    }
    Nav_RunBehaviorHandler(state);
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
    Nav_ResetBehaviorState(brain);
    (((struct Brain_func_80212D78_eu_x *) ((s8 *) brain))->unk2FC) = 0;
}

void Nav_SeekUnclaimedMarker(void *arg0) {
    s32 *rec;
    void *v0;

    ObjRecAt1D8V1 *object = arg0;
    ObjRecAt1454V1 *actor = object->unk1D8;

    rec = actor->unk1454;
    v0 = Player_FindPlayerWithMarker((char *)&D_80145040);
    if (v0 == (void *) *rec) {
        Nav_SetBehaviourState(rec, 10);
        return;
    }
    if (v0 != 0) {
        Nav_SetBehaviourState(rec, 2);
        return;
    }
    Nav_RunBehaviorHandler(rec);
    Nav_DistanceToNode(rec, rec[3]);
    Nav_SteerAlongRoute(rec);
    Nav_UpdateTargetSteering(rec);
}
