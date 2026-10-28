#ifndef AI_NAV_FARTHEST_H
#define AI_NAV_FARTHEST_H
#include "COMMON/SELF.H"
extern void Nav_UpdateRetreatMovement(void *actorObject);
extern void func_802127F4_de(void *actor);
extern void Nav_SeekUnclaimedMarker(void *arg0);
extern void Nav_SeekNearbyUnrestrictedGoal(struct Shared_Actor *actor);
extern void Nav_ApproachCombatTargetAlongRoute(CloseAttackActor *arg0);
extern void func_8021290C_de(struct LevelActor *actor);
extern void func_80212A40_de(struct LevelActor *actor);
extern void func_80212BD0_de(void *actor);
#endif
