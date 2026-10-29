#ifndef RENDER_RUMBLE_H
#define RENDER_RUMBLE_H
#include "RENDER/POOLRECAT28V1.H"

extern void Rumble_InitEffectNode(RumbleEffectNode *effectNode, Clip *effectClip, CVector3 effectPosition, f32 valueStart, f32 valueEnd, void **ownerSlot);
extern s32 Rumble_TestEffectHandleCompletion(RumbleEffectNode *effectNode);
extern void Rumble_ClearEffectOwnerSlot(char *object);
extern f32 Rumble_EvaluateSpatialEffectNode(f32 *effectNode, u32 positionXBits, u32 positionYBits, u32 positionZBits);
#endif
