#ifndef RENDER_RUMBLE_H
#define RENDER_RUMBLE_H
#include "RENDER/POOLRECAT28V1.H"

extern void Rumble_InitEffectNode(NodeCode8028469C *arg0, Clip *arg1, CVector3 arg2, f32 arg5, f32 arg6, void **arg7);
extern s32 Rumble_TestEffectHandleCompletion(s32 arg0);
extern void Rumble_ClearEffectOwnerSlot(char *object);
extern f32 Rumble_EvaluateSpatialEffectNode(f32 *arg0, u32 arg1, u32 arg2, u32 arg3);
#endif
