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
extern void func_8028D64C_de(void *);

struct Node80253610;
extern void Scene_MarkResourceInUse(s32, struct Node80253610 *);
extern void func_802A56FC_de(void *);
struct CPlayerPool_t;
extern void func_8022A170_de(struct CPlayerPool_t *);
extern void func_8028D61C_de(void *);
extern void func_802A5680_de(void *);
extern void func_80286284_de(void *);
extern void func_8028C60C_de(void *);
extern void Particle_UpdateSystem(void *);
extern void func_80236F1C_de(void *, void *);
extern void func_8028D67C_de(void *);
extern void func_8028D888_de(void *);
extern void func_8028D108_de(Shared_World *);
#endif
