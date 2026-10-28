#include "COMMON/SHAREDCALLBACK5.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/OBJECTLINKS14.H"
#include "COMMON/SELF.H"
#include "TYPES.H"
#include "AI/SHARED_PICKUPGOALNODE.H"
#include "AI/ROUTE_RELATION_GRID.H"
#include "COMMON/SHARED_WORLDFUNC.H"
#include "COMMON/GAMEPLAY_TRANSITION.H"
#include "COMMON/LEVEL_ACTOR.H"
#include "COMMON/NAVIGATION_GRAPH.H"
#include "AI/NAV/FARTHEST.H"
#include "include_asm.h"

/* 802106E0_17.CPP */
void *Portal_GetStridedTableEntry(struct EntryList8020CCE8 *object, int index);
extern void *Portal_GetGraphPoint(void *, s32);
extern f32 Graphu64_GetSquaredDistance(f32 *, f32 *);

/* Choose the farthest reachable neighbor linked by kinds 1, 2 or 7
 * from the actor that this state is following. */
void Nav_SelectFarthestReachableNeighbor(AiController *object)
{
    s32 neighbors[64];
    s32 links[64];
    s32 *linkCursor;
    CVector3 position;
    Player *actor;
    f32 *point;
    f32 distance;
    f32 farthest;
    s32 actor_node;
    register s32 best;
    s32 count;
    s32 i;
    Link *link;
    void *graph = &D_8013B364;

    actor = object->target->player;
    actor_node = actor->controller->current;
    position = actor->pos;
    for (i = 0; i < 64; i++) {
        neighbors[i] = -1;
        links[i] = -1;
    }
    linkCursor = links;
    farthest = D_800C20C0_de[0];
    count = Portal_CollectIncidentLinks(graph, object->current, neighbors, linkCursor);
    best = -1;
    for (i = 0; i < count; i++) {
        link = Portal_GetStridedTableEntry(graph, links[i]);
        if ((link->type >= 1 && link->type <= 2) || link->type == 7) {
            point = Portal_GetGraphPoint(graph, neighbors[i]);
            if (Route_GetRouteRelation(graph, actor_node, neighbors[i])) {
                distance = Graphu64_GetSquaredDistance(&position.x, point);
                if (farthest < distance) {
                    farthest = distance;
                    best = i;
                }
            }
        }
    }
    object->mode = best;
}

/* 802106E0_20.CPP */
extern s32 Scaled_SetBehaviourState(void *, s32);
extern void Nav_UpdateTargetSteering(void *);

extern void Nav_RunBehaviorHandler(void *);

extern void Nav_SteerAlongRoute(void *);

extern f32 D_800C20C8_de;

extern f32 D_800C20CC_de;



extern void Nav_AddGoalNode(void *, s32);



extern void Nav_UpdatePlayerSteering(void *controller);

extern void Nav_SelectPlayerState(void *controller);

extern f32 Scaled_DistanceToNode(s32 *, s32);

void func_802127F4_de(void *actor) {
    void *brain;
    brain = (((struct ObjRecAt1454V2 *) ((s8 *) ((struct ObjRecAt1D8V1 *) ((s8 *) actor))->unk1D8))->unk1454);
    (((struct Brain_func_80212D78_eu_x *) ((s8 *) brain))->unk220) = 0;
    Scaled_ResetBehaviorState(brain);
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
        if (!Route_GetRouteRelation(&D_8013B364, state->route, value)) {
            Scaled_SetBehaviourState(state, 1);
            return;
        }
    }

    Nav_RunBehaviorHandler(state);
    Nav_SteerAlongRoute(state);
    Nav_UpdateTargetSteering(state);
    if (Graphu64_GetSquaredDistance(&peer_actor->pos.x,
                       &state->player->pos.x) < D_800C20C0_de[1] ||
        state->route == state->destination) {
        Scaled_SetBehaviourState(state, state->combat);
    }
}

/** Reset the inner record via Scaled_ResetBehaviorState, then override two of its fields. */
void func_8021290C_de(LevelActor *actor) {
    Shared_ActorView *level1 = actor->controller;
    CloseAttackBrain *inner = level1->owner;
    inner->state = 0;
    Scaled_ResetBehaviorState(inner);
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
            Scaled_SetBehaviourState(brain, 4);
            return;
        }
    }

    if (D_800C20C8_de < Graphu64_GetSquaredDistance(
            &brain->target->self->pos.x,
            &brain->player->pos.x)) {
        Scaled_SetBehaviourState(brain, brain->combat);
        return;
    }

    Nav_RunBehaviorHandler(brain);
    Nav_SteerAlongRoute(brain);
    Nav_UpdateTargetSteering(brain);
    if (brain->route == brain->destination) {
        brain->destination = -1;
    }
}

/** Reset the inner record's flag fields, then clear its state via Scaled_ResetBehaviorState. */
void func_80212A40_de(LevelActor *actor) {
    Shared_ActorView *level1 = actor->controller;
    CloseAttackBrain *inner = level1->owner;
    inner->state = 0;
    inner->destination = -1;
    Scaled_ResetBehaviorState(inner);
    inner->reset2FC = 0;
}

void Nav_SeekNearbyUnrestrictedGoal(Shared_Actor *actor)
{
    AiController *state;
    CNavData *table;
    NavigationPoint *entry;
    f32 threshold;
    s32 index;
    s32 value;
    u32 flags;

    state = ((Player *)actor->entity)->controller;
    table = &D_8013B364;
    if (state->mode == -1) {
        Portal_ResetSearchState(table);
        Route_ClearGoalList(table);
        threshold = D_800C20CC_de;
        index = 0;
        if (table->m_nNavNodes > 0) {
            do {
                entry = Portal_GetGraphPoint(table, index);
                if (Graphu64_GetSquaredDistance(&state->player->pos.x, entry) < threshold &&
                    !(navigation_attributes(entry) & 0x04300000)) {
                    Nav_AddGoalNode(table, index);
                }
                index++;
            } while (index < table->m_nNavNodes);
        }
        Route_SearchPathByKey(table, state->current);
        Route_ReconstructSearchPath(table, &state->queue, 4);
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
    Scaled_ResetBehaviorState(brain);
    (((struct Brain_func_80212D78_eu_x *) ((s8 *) brain))->unk2FC) = 0;
}

void Nav_SeekUnclaimedMarker(void *arg0) {
    s32 *rec;
    void *v0;

    ObjRecAt1D8V1 *object = arg0;
    ObjRecAt1454V1 *actor = object->unk1D8;

    rec = actor->unk1454;
    v0 = Playerai_FindPlayerWithMarker((char *)&D_80145040);
    if (v0 == (void *) *rec) {
        Scaled_SetBehaviourState(rec, 10);
        return;
    }
    if (v0 != 0) {
        Scaled_SetBehaviourState(rec, 2);
        return;
    }
    Nav_RunBehaviorHandler(rec);
    Scaled_DistanceToNode(rec, rec[3]);
    Nav_SteerAlongRoute(rec);
    Nav_UpdateTargetSteering(rec);
}

/* 800C6E84_18.CPP */
#if !(defined(VERSION_US_REV1))
const unsigned int D_80212670_C7DB0[4] = {
    0xBF800000, 0x484F5C28, 0x494F5C28, 0x49800000,
};
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_80212670_C7DB0_us_rev1.c */
const unsigned int D_blob_4f2a75997c6fd431e04d[1] = {
    0xBF800000,
};

/* ROM-grounded data: src/rw_pool_80212828_C7DB4_us_rev1.c */
const unsigned int D_blob_9ef8a3e33b0bfbb47bad[1] = {
    0x484F5C28,
};

/* ROM-grounded data: src/rw_pool_80212948_C7DB8_us_rev1.c */
const unsigned int D_blob_14757aafdd33202e41ee[1] = {
    0x494F5C28,
};

/* ROM-grounded data: src/rw_pool_80212A7C_C7DBC_us_rev1.c */
const unsigned int D_blob_1ac807a6a6e118c751da[1] = {
    0x49800000,
};
#endif
