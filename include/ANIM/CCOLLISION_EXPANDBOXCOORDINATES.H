#ifndef ANIM_CCOLLISION_EXPANDBOXCOORDINATES_H
#define ANIM_CCOLLISION_EXPANDBOXCOORDINATES_H
#include "COMMON/RENDERSORTRECORD.H"
extern int CRenderSortRecord_CompareDepth(RenderSortRecord *left, RenderSortRecord *right);
extern void CCollision_ExpandBoxCoordinates(float *s, float *d);
extern void CRenderSortRecord_Swap(RenderSortRecord *left, RenderSortRecord *right);
#endif
