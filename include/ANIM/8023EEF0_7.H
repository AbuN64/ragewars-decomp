#ifndef ANIM_8023EEF0_7_H
#define ANIM_8023EEF0_7_H
#include "COMMON/RENDERSORTRECORD.H"
extern int CRenderSortRecord_CompareDepth(RenderSortRecord *left, RenderSortRecord *right);
extern void CCollision_ExpandBoxCoordinates(float *s, float *d);
extern void CRenderSortRecord_Swap(RenderSortRecord *left, RenderSortRecord *right);
#endif
