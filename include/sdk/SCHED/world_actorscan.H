#ifndef SDK_SCHED_8028DF6C_H
#define SDK_SCHED_8028DF6C_H
#include "COMMON/WORLDSORTENTRY.H"
extern s32 Scene_CompareDistanceDescending(WorldSortEntry *arg0, WorldSortEntry *arg1);
extern void Scene_SwapDistanceSortEntries(WorldSortEntry *arg0, WorldSortEntry *arg1);
extern s32 Scene_CompareDistanceAscending(WorldSortEntry *arg0, WorldSortEntry *arg1);
extern void Scene_CollectTypeFourteenActors(struct Shared_World *arg0);
extern s32 Scene_GetTriggerCounterAddress(struct Shared_World *arg0, s32 arg1);
#endif
