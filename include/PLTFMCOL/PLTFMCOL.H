#ifndef PLTFMCOL_PLTFMCOL_H
#define PLTFMCOL_PLTFMCOL_H
#include "COMMON/UNUSED.H"
#include "ANIM/RAY180.H"
extern void CPlatformCollision_BuildWorldBounds(char *obj, CVector3 *corners, char *floor, s32 attachment);
extern void CPlatformCollision_PushActorFromBox(ActorCPlatformCollisionPushActorFromBox *actor, OwnerRecAt18 *owner, RayCornerBounds *bounds, SurfaceHit *query, CollisionProbe *input);
extern void CPlatformCollision_PushActorFromCylinder(ActorCPlatformCollisionPushActorFromBox *actor, OwnerRecAt18 *owner, RayCornerBounds *bounds, SurfaceHit *query, CollisionProbe *input);
extern void CPlatformCollision_TraceShape(ActorCPlatformCollisionTraceShape *actor, OwnerRecAt18 *owner);
extern void CPlatformCollision_ProcessRiderMotion(ActorCPlatformCollisionProcessRiderMotion *actor, SourceBarrelUpdateActorController *input);
extern void CPlatformCollision_LiftActorToSurface(ActorRecAtB0 *actor, void *owner, InputCPlatformCollisionLiftActorToSurface *input, SurfaceHit *query);
#endif
