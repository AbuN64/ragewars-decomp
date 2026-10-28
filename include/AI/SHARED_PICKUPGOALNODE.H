#ifndef AI_SHARED_PICKUPGOALNODE_H
#define AI_SHARED_PICKUPGOALNODE_H
struct Obj8020BC50;
#ifndef FUNC_8020EF80_EU_X_CLOSED_H
#define FUNC_8020EF80_EU_X_CLOSED_H
#include "TYPES.H"
typedef struct Shared_PickupGoalNode Shared_PickupGoalNode;
struct Shared_PickupGoalNode {
    s32 id;
    u32 unknown4[3];
    Shared_PickupGoalNode *next;
    f32 radius;
    u32 unknown18[7];
    s32 goal;
};

#include "COMMON/UNUSED.H"

extern PickupGoalNodeList D_8013B364;

extern void Portal_ResetSearchState(struct Obj8020BC50 *graph);
extern void Route_ClearGoalList(PickupGoalNodeList *list);
extern s32 Nav_AddPickupGoalsByObjectIds(s32 *ids);
extern void Route_SearchPathByKey(PickupGoalNodeList *list, s32 key);
extern Shared_PickupGoalNode *Portal_FindSearchNode(PickupGoalNodeList *list, u32 key);
extern void Route_ReconstructSearchPath(PickupGoalNodeList *list, s32 *output, s32 count);


#endif
#endif
