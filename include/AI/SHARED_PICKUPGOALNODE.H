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

extern void func_8020D014_de(struct Obj8020BC50 *arg0);
extern void func_8020D1FC_de(PickupGoalNodeList *list);
extern s32 func_8020F150_de(s32 *ids);
extern void func_8020D0CC_de(PickupGoalNodeList *list, s32 key);
extern Shared_PickupGoalNode *func_8020CFE0_de(PickupGoalNodeList *list, u32 key);
extern void func_8020D114_de(PickupGoalNodeList *list, s32 *output, s32 count);


#endif
#endif
