#ifndef COMMON_FRUSTUM_H
#define COMMON_FRUSTUM_H
#include "TYPES.H"

extern f32 Visdata_EvaluatePlaneAtPoint(f32 *a, f32 *b);

struct Frustum;

extern f32 VisData_GetPlaneSegmentFraction(f32 *arg0, f32 *arg1, f32 *arg2);

struct Frustum;
typedef struct Frustum Frustum;

extern float D_800C5510_de;

extern s32 VisData_TestBoxAgainstPlane(f32 *arg0, f32 *arg1);

extern void *Node_GetScreenData(s32 index);

s32 Node_IsValidScreenIndex(s32);
#endif
