#ifndef COMMON_S1_3_H
#define COMMON_S1_3_H
#include "TYPES.H"
#include "COMMON/SHAREDPLAYER.H"
extern void Graphu64_BuildTranslationMatrix(void *matrix, f32 x, f32 y, f32 z);
extern void Graphu64_BuildScaleMatrix(void *matrix, f32 x, f32 y, f32 z);
extern float D_800C48D8_de;










extern f32 Graphu64_GetVerticalAngle(f32 *arg0);




extern f32 Graphu64_GetAngleDistance(f32 arg0, f32 arg1);

extern void Graphu64_MultiplyVectorComponents(CVector3 *result, CVector3 *left, CVector3 *right);

extern float D_800C48B0_de;

extern float D_800C48DC_de;

extern float D_800C48B8_de;


extern void *Graphu64_ReflectVector(CVector3 *arg0, CVector3 *arg1, CVector3 *arg2, f32 arg3);

extern void *Graphu64_ProjectVectorOntoPlane(CVector3 *arg0, CVector3 *arg1, CVector3 *arg2);





extern void Graphu64_InterpolateAtHeight(CVector3 *out, CVector3 *a, CVector3 *b, f32 y);





#endif
