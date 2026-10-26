#ifndef COMMON_EXTERNS_9_H
#define COMMON_EXTERNS_9_H
#include "COMMON/SHARED_GAMESLOT.H"
#include "TYPES.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/RESULTS.H"
#include "COMMON/SCENERECAT10C0.H"
struct Shared_Pickup;
#include "COMMON/WORLD.H"
#include "COMMON/MENU_UI_PROVIDERS.H"






#include "COMMON/UNUSED.H"
#include "COMMON/TRIPLE.H"

#include "COMMON/EXTERNS_6.H"
#include "COMMON/BALLISTICPARAMS.H"
#include "COMMON/SHARED_MENUREPLY.H"

extern s32 D_800CD3F4;


struct Shared_World;
extern void Scene_UpdateSelectionTransition(struct Shared_World *);
extern void Scene_ClearSceneObjectCounts(void *);

struct Node80253610;
extern void Cache_MarkResourceInUse(s32, struct Node80253610 *);
extern void Fx_ResetRibbonVertexPool(void *);
struct CPlayerPool_t;
extern void func_8022A170_de(struct CPlayerPool_t *);
extern void Scene_CollectVisibleEffects(void *);
extern void Fx_UpdateEffectLists(void *);
extern void Scene_UpdateActorsAndRoundState(void *);
extern void Scene_UpdateTriggerTimers(void *);
extern void Particle_UpdateSystem(void *);
extern void Camera_DrawActiveViews(void *, void *);
extern void Scene_UpdateStaticEventInstances(void *);
extern void Scene_UnlockActiveSectionResources(void *);
extern void Scene_DrawTransitionColorOverlay(Shared_World *);
#endif
