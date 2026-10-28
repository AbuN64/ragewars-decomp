#ifndef ANIM_CPLATFORMCOLLISION_APPLYMOVEMENT_H
#define ANIM_CPLATFORMCOLLISION_APPLYMOVEMENT_H
#include "ANIM/RAY180.H"
extern void CPlatformCollision_MarkBlocked(void *first, void *second);
extern void CPlatformCollision_ApplyMovement(void *platformMotion, void *levelActor);
#endif
