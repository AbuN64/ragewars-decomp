#ifndef ANIM_CCOLLISION_TESTSEGMENTPOLYGON_H
#define ANIM_CCOLLISION_TESTSEGMENTPOLYGON_H
#include "COMMON/DESCRIPTORRECAT29.H"
#include "COMMON/OUTPUT.H"
extern void CCollision_ClearContactNormal(void *contactStorage);
extern s32 CCollision_HasMatchingNormal(struct Input *input, PolygonCCollisionTestSegmentPolygon *polygon);
extern void CCollision_CopyPolygonNormal(void *contactStorage, void *polygonStorage);
#endif
