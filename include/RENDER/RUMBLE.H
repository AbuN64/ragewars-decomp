#ifndef RENDER_RUMBLE_H
#define RENDER_RUMBLE_H
#include "RENDER/POOLRECAT28V1.H"

extern void Rumble_InitEffectNode(NodeCode8028469C *arg0, Clip *effectClip, CVector3 effectPosition, f32 valueStart, f32 valueEnd, void **ownerSlot);
extern s32 Rumble_TestEffectHandleCompletion(s32 arg0);
extern void Rumble_ClearEffectOwnerSlot(char *object);
extern f32 Rumble_EvaluateSpatialEffectNode(f32 *arg0, u32 arg1, u32 arg2, u32 arg3);
#endif
