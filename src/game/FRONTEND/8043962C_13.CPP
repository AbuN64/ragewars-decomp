#include "COMMON/WORLD.H"
#include "COMMON/INTEGERSTATEB0.H"
#include "include_asm.h"
#include "COMMON/PARTICLE_LIGHTING.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/UNUSED.H"
#include "COMMON/OBJECTSTATE18.H"
#include "COMMON/TEXTURE.H"
#include "COMMON/OBJECTRECAT28.H"
#include "abi.h"
#include "TYPES.H"
#include "gbi.h"
#include "MENU/GFX/80414430_19.H"
#include "particle/80271B18_3.H"

/* Draws a menu model with screen-scaled translation, animated and fixed rotations, restoring the render-state flag afterward; the unsigned offset-to-pointer cast preserves matrix-address scheduling. */
extern MenuModelScreen D_80141008[]; extern Gfx *g_displayListCursor;
extern s32 D_800D297C, D_800E28D0;
#if defined(VERSION_DE)
extern float D_800DDF50_de;
extern float D_800DDF58;
#elif defined(VERSION_EU)
extern float D_800DDF50_de;
extern float D_800DDF58;
#elif defined(VERSION_EU_X)
extern float D_800DDF50_de;
extern float D_800DDF58;
#elif defined(VERSION_US)
extern float D_800DDF50_de;
extern float D_800DDF58;
#elif defined(VERSION_US_REV1)
extern float D_800DDF50_de;
extern float D_800DDF58;
#endif
extern void PitchMatrixLocal(Matrix *,f32); extern void YawMatrixLocal(Matrix *,f32); extern void RollMatrixLocal(Matrix *,f32);
extern void ScaleMatrixLocal(Matrix *,f32,f32,f32); extern void SwapMatrixUpForward(Matrix *);
extern s32 func_802A1934_de(void); extern void GraphU64_ConvertMatrixToFixed(Matrix *,void *);
extern s32 Scene_GetIndexedModelResource(void *,s32);
extern void Geometry_QueueDirectModel(s32,void *,void *,s32,s32);
void func_804399D0(MenuModelItem *item) {
 Matrix matrix;
 CVector3 position, transformed, scale;
 s32 model;
 s32 saved;
 f32 time, ratio;
 saved=D_800CC380; D_800CC380=0;
 if (item->model != -1) {
  func_80417138_de(0x33335);
  gDPPipeSync(g_displayListCursor++);
  gDPSetCycleType(g_displayListCursor++, G_CYC_2CYCLE);
  gDPSetTexturePersp(g_displayListCursor++, G_TP_PERSP);
  gDPSetTextureFilter(g_displayListCursor++, G_TF_BILERP);
  Geometry_InitializeModelRenderState();
  {Gfx *g=g_displayListCursor++; char *address=(char *)(u32)(D_800D297C<<6); address+=0x380; address+=(u32)D_80141008; gSPMatrix(g, (u32)address, G_MTX_LOAD | G_MTX_PROJECTION);}
  position=item->position;
  GraphU64_TransformPoint(&D_80141008[0].camera,&position,&transformed);
  GraphU64_BuildTranslationMatrix(&matrix, transformed.x, transformed.y, transformed.z);
  time=func_802A1934_de();
  if(item->speed.x!=0.0f)PitchMatrixLocal(&matrix,time*item->speed.x*D_800DDF50_de);
#if defined(VERSION_DE)
  if(item->speed.y!=0.0f)YawMatrixLocal(&matrix,time*item->speed.y*(0.01745329424738884f));
#elif defined(VERSION_EU)
  if(item->speed.y!=0.0f)YawMatrixLocal(&matrix,time*item->speed.y*(0.01745329424738884f));
#elif defined(VERSION_EU_X)
  if(item->speed.y!=0.0f)YawMatrixLocal(&matrix,time*item->speed.y*(0.01745329424738884f));
#elif defined(VERSION_US)
  if(item->speed.y!=0.0f)YawMatrixLocal(&matrix,time*item->speed.y*(0.01745329424738884f));
#elif defined(VERSION_US_REV1)
  if(item->speed.y!=0.0f)YawMatrixLocal(&matrix,time*item->speed.y*D_800E1F84);
#endif
  if(item->speed.z!=0.0f)RollMatrixLocal(&matrix,time*item->speed.z*D_800DDF58);
  if(item->rotation.x!=0.0f)PitchMatrixLocal(&matrix,item->rotation.x*(*(&D_800DDF58+1)));
  if(item->rotation.y!=0.0f)YawMatrixLocal(&matrix,item->rotation.y*(*(&D_800DDF58+2)));
  if(item->rotation.z!=0.0f)RollMatrixLocal(&matrix,item->rotation.z*(*(&D_800DDF58+3)));
  ratio=D_80141008[0].width/(f32)D_800E28D0;
  scale.x=item->scale.x*ratio;
  scale.z=item->scale.z*ratio;
  scale.y=item->scale.y*(D_80141008[0].height/(f32)*(&D_800E28D0+1));
  ScaleMatrixLocal(&matrix,scale.x,scale.y,scale.z);SwapMatrixUpForward(&matrix);
  GraphU64_ConvertMatrixToFixed(&matrix,(char *)item+((D_800D297C<<6)+0x38));
  model=Scene_GetIndexedModelResource(&g_world,item->model);Geometry_BeginModelBatch();
  Geometry_QueueDirectModel(model,(char *)item+((D_800D297C<<6)+0x38),&D_800D0EF8,0,item->flags);
  Geometry_FlushModelBatch();
 }
 D_800CC380=saved;
}

#if !(defined(VERSION_US_REV1))
const unsigned int rodata_unresolved_800DDF58[4] = {
    0x3C8EFA36, 0x3C8EFA36, 0x3C8EFA36, 0x3C8EFA36,
};
#endif

#if defined(VERSION_US)
char rodata_unresolved_800DCC18[8] =
    "equR\000\000I\001";
#endif

#if defined(VERSION_EU_X)
unsigned int rodata_unresolved_800E97A8[2] = {
    0xFFFFFFF8, 0x00000017,
};
#endif

#if defined(VERSION_EU)
unsigned int rodata_unresolved_800EE5E8[2] = {
    0x02098024, 0x2251FFFA,
};
#endif

#if defined(VERSION_DE)
unsigned int rodata_unresolved_800DDF68[2] = {
    0x00439D80, 0x00439D88,
};
#endif
