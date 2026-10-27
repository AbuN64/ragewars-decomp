#ifndef FX_2_FX_2_H
#define FX_2_FX_2_H
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/OBJRECAT18V6.H"
#include "COMMON/EFFECTCONTRIBUTION.H"
#include "SYSTEM_3/802A6AC0.H"
extern void Fx_AccumulateEffectComponents(ObjRecAt3CV1 *);
extern void Fx_ClampScalarRange(f32 *);
extern void Fx_AddTimedCallback(s32, s32, s32, s32, f32);
extern void Fx_ResolveEntryResource(void *unused, void *, void *);
extern void Fx_UpdateChildTransform(Node44 *, void *);
extern void Fx_UpdateNodeFractions(void *);
extern void Fx_DrawEffectGeometry(s32 pool, void *, s32 camera);
extern void Fx_AppendAttachedTransform(void *, void *, void *, s32);
extern void *Fx_FindAttachedEffect(Owner802A6DF8 *, s32, s32);
extern void Fx_DrawEffectPasses(void *pool, void *camera);
#endif
