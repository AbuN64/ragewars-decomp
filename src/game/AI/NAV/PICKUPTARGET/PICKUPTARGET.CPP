#include "COMMON/NAVIGATION_GRAPH.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/OBJECTLINKS1458.H"
#include "TYPES.H"
#include "COMMON/UNUSED.H"
#include "COMMON/OBJECTLINKS14.H"
#include "include_asm.h"
#include "COMMON/MEASURED_STORAGE.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/LEVEL_ACTOR.H"
#include "COMMON/ROUTE_CHASE_RECORDS.H"
#include "COMMON/REC.H"
#include "COMMON/SHAREDCALLBACK5.H"
#include "COMMON/SELF.H"
#include "AI/NAV/PICKUPTARGET.H"

/* Selects the nodes of D_8013B364's list whose flagged record matches one of thirty ids: every match
   whose owner at 0x34 is active at 0x294 is selected through Nav_AddGoalNode, and when none was, every
   matching node is selected regardless of owner. Returns the number of selections. Written from its
   own assembly in the style of Nav_AddPickupCategoryCosts. */



extern s32 D_8013B364;
extern void *Portal_GetGraphPoint(void *, s32);
struct ObjNavAddGoalNode;
extern void Nav_AddGoalNode(struct ObjNavAddGoalNode *, int);







s32 Nav_AddPickupGoalsByObjectIds(s32 *ids) {
    s32 *base;
    Node8020BC50 *node;
    void *record;
    s32 count;
    s32 i;

    base = &D_8013B364;
    count = 0;
    for (node = (Node8020BC50 *)((Obj8020BC50 *)base)->nodes; node != 0; node = node->next) {
        record = Portal_GetGraphPoint(base, node->key);
        if (navigation_point_flags((NavigationPoint *)record) & 1) {
            for (i = 0; i < 30; i++) {
                if (navigation_point_object_id((NavigationPoint *)record) == ids[i] && node->owner != 0
                    && ((Owner8020F150 *)node->owner)->active != 0) {
                    Nav_AddGoalNode(base, node->key);
                    count++;
                }
            }
        }
    }
    if (count == 0) {
        for (node = (Node8020BC50 *)((Obj8020BC50 *)base)->nodes; node != 0; node = node->next) {
            record = Portal_GetGraphPoint(base, node->key);
            if (navigation_point_flags((NavigationPoint *)record) & 1) {
                for (i = 0; i < 30; i++) {
                    if (navigation_point_object_id((NavigationPoint *)record) == ids[i]) {
                        Nav_AddGoalNode(base, node->key);
                        count++;
                    }
                }
            }
        }
    }
    return count;
}


extern void Portal_ResetSearchState(void *arg0);

extern void Route_ClearGoalList(s32);

s32 Nav_AddPickupGoalsByObjectIds(s32 *ids);

extern void Route_SearchPathByKey(void *arg0, s32 arg1);

extern void *Portal_FindSearchNode(char *, s32);

extern void Route_ReconstructSearchPath(void *arg0, void *arg1, s32 arg2);



extern s32 Playerai_GetWeaponClassId(Player *, s32);

s32 Nav_SelectCloseAttackPickupGoal(CloseAttackBrain *closeAttackBrain) {
    s32 data[30];
    s32 *cursor;
    s32 count;
    CNavData *global;
    s32 value;
    s32 current;
    NavigationSearchNode *entry;

    global = (CNavData *)&D_8013B364;
    Portal_ResetSearchState(global);
    Route_ClearGoalList((s32)global);
    count = 29;
    cursor = &data[29];
    do {
        *cursor = 0;
        count--;
        cursor--;
    } while (count >= 0);
    data[0] = 0xBD7;
    if (Nav_AddPickupGoalsByObjectIds(data) == 0) {
        closeAttackBrain->routeObject = 0;
        closeAttackBrain->routeState = -1;
        return 1;
    }
    value = -1;
    global->result = value;
    Route_SearchPathByKey(global, closeAttackBrain->route);
    current = global->result;
    if (current != value) {
        entry = Portal_FindSearchNode(global, current);
        closeAttackBrain->destination = global->result;
        closeAttackBrain->routeObject = entry->object;
        Route_ReconstructSearchPath(global, &closeAttackBrain->routeNodes[0], 4);
    } else {
        closeAttackBrain->routeObject = 0;
        closeAttackBrain->routeState = current;
    }
    return 1;
}

s32 Nav_SelectChaseObjectGoal(void *arg0) {
    s32 data[30];
    s32 *cursor;
    s32 count;
    char *global;
    s32 value;
    s32 current;

    global = &D_8013B364;
    Portal_ResetSearchState(global);
    Route_ClearGoalList((s32)global);
    count = 29;
    cursor = &data[29];
    do {
        *cursor = 0;
        count--;
        cursor--;
    } while (count >= 0);
    data[0] = 0x653;
    if (Nav_AddPickupGoalsByObjectIds(data) == 0) {
        ((RouteChaseBot *)arg0)->target = 0;
        ((RouteChaseBot *)arg0)->targetId = -1;
        return 1;
    }
    value = -1;
    ((CNavData *)global)->result = value;
    Route_SearchPathByKey(global, ((RouteChaseBot *)arg0)->node);
    current = ((CNavData *)global)->result;
    if (current != value) {
        ((RouteChaseBot *)arg0)->goal = current;
        Route_ReconstructSearchPath(global, &((AiController *)arg0)->queue[0], 4);
    }
    return 1;
}

s32 Nav_SelectStationaryObjectGoal(AiController *controller) {
    CNavData *global;
    CNavData *scanbase;
    NavigationSearchNode *node;
    NavigationPoint *result;
    s32 count;
    s32 type;
    s32 value;
    s32 current;

    global = (CNavData *)&D_8013B364;
    Portal_ResetSearchState(global);
    Route_ClearGoalList((s32)global);
    count = 0;
    node = D_801372C8;
    scanbase = global;
    if (node != 0) {
        type = 0x64E;
        do {
            result = Portal_GetGraphPoint(scanbase, node->key);
            if ((navigation_point_flags(result) & 1) &&
                navigation_point_object_id(result) == type &&
                ((ActorMotionState *)node->object->motion)->mode == 0) {
                Nav_AddGoalNode(scanbase, node->key);
                count += 1;
            }
            node = node->next;
        } while (node != 0);
    }
    if (count == 0) {
        controller->routeObject = 0;
        controller->routeState = -1;
        return 1;
    }
    value = -1;
    global->result = value;
    Route_SearchPathByKey(global, controller->current);
    current = global->result;
    if (current != value) {
        controller->mode = current;
        Route_ReconstructSearchPath(global, &controller->queue, 4);
    }
    return 1;
}

/** Return whether arg0 is within the range [0x6BA, 0x6BC). */
s32 func_8020F55C_de(s32 field0E) {
    if (field0E < 0x6BC) {
        if (field0E >= 0x6BA) {
            return 1;
        }
    }
    return 0;
}

/** Return whether arg0 is within the range [0xBC4, 0xBCA). */
s32 func_8020F57C_de(s32 objectId) {
    if (objectId < 0xBCA) {
        if (objectId >= 0xBC4) {
            return 1;
        }
    }
    return 0;
}

/** Return the empty result used by callers at VRAM 0x8020F59C. */
int func_8020F59C_de(void) {
    return 0;
}

s32 Nav_GetWeaponPickupGoalClass(void **arg0) {
    s32 temp_v0;
    void *temp_a0;

    temp_a0 = *arg0;
    temp_v0 = Playerai_GetWeaponClassId(temp_a0, (s32) ((struct MeasuredRecAt62EV1 *)(temp_a0))->value);
    switch (temp_v0) {
        case 0:
            return 5;
        case 1:
            return 6;
        case 2:
            return 7;
        default:
            return 4;
    }
}

s32 Nav_AddInactiveObjectGoals(void) {
    s32 *base;
    NavigationSearchNode *node;
    void *result;
    s32 count;

    base = &D_8013B364;
    node = ((CNavData *)base)->nodes;
    count = 0;
    if (node != 0) {
        do {
            result = Portal_GetGraphPoint(base, node->key);
            if ((navigation_point_flags((NavigationPoint *)result) & 1) &&
                navigation_point_object_id((NavigationPoint *)result) == 0x64E &&
                (s8)((LevelActor *)node->object)->pad1A4 == 0) {
                Nav_AddGoalNode(base, node->key);
                count += 1;
            }
            node = node->next;
        } while (node != 0);
    }
    return count;
}

#if defined(VERSION_DE)
unsigned int func_8020F6B8_de_padding_102B8[2] = {
    0x0ED090B3, 0x68328E00,
};
#endif
