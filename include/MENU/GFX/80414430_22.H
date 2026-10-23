#ifndef MENU_GFX_80414430_22_H
#define MENU_GFX_80414430_22_H
#include "COMMON/TEXTURE.H"
extern void Gfx_EmitTextureRect(s32 left, s32 top, s32 right, s32 bottom, f32 u0, f32 v0, f32 u1, f32 v1);
extern void Gfx_SyncPipeline(void);
extern void Gfx_SetTextureMode(s32 mode);
extern void Gfx_ResetPipelineSync(void);
#endif
