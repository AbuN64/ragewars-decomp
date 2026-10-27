#ifndef PLTFMCOL_PLTFMCOL_H
#define PLTFMCOL_PLTFMCOL_H
#include "COMMON/UNUSED.H"
#include "ANIM/RAY180.H"
extern void func_80241950_de(char *obj, CVector3 *corners, char *floor, s32 attachment);
extern void func_80241BAC_de(Actor_func_80241BAC_de *actor, OwnerRecAt18 *owner, RayCornerBounds *bounds, SurfaceHit *query, CollisionProbe *input);
extern void func_80241F24_de(Actor_func_80241BAC_de *actor, OwnerRecAt18 *owner, RayCornerBounds *bounds, SurfaceHit *query, CollisionProbe *input);
extern void func_80242288_de(Actor_func_80242288_de *actor, OwnerRecAt18 *owner);
extern void func_80242550_de(Actor_func_80242550_de *actor, SourceBarrelUpdateActorController *input);
extern void func_802426CC_de(ActorRecAtB0 *actor, void *owner, Input_func_802426CC_de *input, SurfaceHit *query);
#endif
