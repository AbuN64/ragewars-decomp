#ifndef INSTCOL_2_INSTCOL_2_H
#define INSTCOL_2_INSTCOL_2_H
#include "COMMON/BOX_CONTACT.H"
extern s32 CInstanceCollision_TestBoxFaces(BoxContactRay *ray, void *unused, BoxContactActor *actor, CVector3 *origin, CVector3 *vertices, BoxContactTransform *transform, s32 index);
extern void CInstanceCollision_TraceActorBounds(BoxContactRay *ray, BoxContactActor *actor, CVector3 *origin, Box *bounds);
#endif
