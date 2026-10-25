#include "COMMON/WORLD.H"
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
extern MenuModelScreen D_80141008[]; extern Gfx *D_80110634;
extern s32 D_800CC380, D_800D297C, D_800E28D0;
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
extern void func_80272C60_de(void *, f32, f32, f32);
extern void func_802737F0_de(Matrix *,f32); extern void func_802739C4_de(Matrix *,f32); extern void func_80273B98_de(Matrix *,f32);
extern void func_8027347C_de(Matrix *,f32,f32,f32); extern void func_80273D6C_de(Matrix *);
extern s32 func_802A1934_de(void); extern void func_8027027C_de(Matrix *,void *);
extern s32 func_8028C198_de(void *,s32);
extern void func_8026DF30_de(s32,void *,void *,s32,s32);
void func_804399D0(MenuModelItem *item) {
 Matrix matrix;
 CVector3 position, transformed, scale;
 s32 model;
 s32 saved;
 f32 time, ratio;
 saved=D_800CC380; D_800CC380=0;
 if (item->model != -1) {
  func_80417138_de(0x33335);
  gDPPipeSync(D_80110634++);
  gDPSetCycleType(D_80110634++, G_CYC_2CYCLE);
  gDPSetTexturePersp(D_80110634++, G_TP_PERSP);
  gDPSetTextureFilter(D_80110634++, G_TF_BILERP);
  func_8026D844_de();
  {Gfx *g=D_80110634++; char *address=(char *)(u32)(D_800D297C<<6); address+=0x380; address+=(u32)D_80141008; gSPMatrix(g, (u32)address, G_MTX_LOAD | G_MTX_PROJECTION);}
  position=item->position;
  Particle_TransformPoint(&D_80141008[0].camera,&position,&transformed);
  func_80272C60_de(&matrix, transformed.x, transformed.y, transformed.z);
  time=func_802A1934_de();
  if(item->speed.x!=0.0f)func_802737F0_de(&matrix,time*item->speed.x*D_800DDF50_de);
#if defined(VERSION_DE)
  if(item->speed.y!=0.0f)func_802739C4_de(&matrix,time*item->speed.y*(0.01745329424738884f));
#elif defined(VERSION_EU)
  if(item->speed.y!=0.0f)func_802739C4_de(&matrix,time*item->speed.y*(0.01745329424738884f));
#elif defined(VERSION_EU_X)
  if(item->speed.y!=0.0f)func_802739C4_de(&matrix,time*item->speed.y*(0.01745329424738884f));
#elif defined(VERSION_US)
  if(item->speed.y!=0.0f)func_802739C4_de(&matrix,time*item->speed.y*(0.01745329424738884f));
#elif defined(VERSION_US_REV1)
  if(item->speed.y!=0.0f)func_802739C4_de(&matrix,time*item->speed.y*D_800E1F84);
#endif
  if(item->speed.z!=0.0f)func_80273B98_de(&matrix,time*item->speed.z*D_800DDF58);
  if(item->rotation.x!=0.0f)func_802737F0_de(&matrix,item->rotation.x*(*(&D_800DDF58+1)));
  if(item->rotation.y!=0.0f)func_802739C4_de(&matrix,item->rotation.y*(*(&D_800DDF58+2)));
  if(item->rotation.z!=0.0f)func_80273B98_de(&matrix,item->rotation.z*(*(&D_800DDF58+3)));
  ratio=D_80141008[0].width/(f32)D_800E28D0;
  scale.x=item->scale.x*ratio;
  scale.z=item->scale.z*ratio;
  scale.y=item->scale.y*(D_80141008[0].height/(f32)*(&D_800E28D0+1));
  func_8027347C_de(&matrix,scale.x,scale.y,scale.z);func_80273D6C_de(&matrix);
  func_8027027C_de(&matrix,(char *)item+((D_800D297C<<6)+0x38));
  model=func_8028C198_de(&D_8011FE88,item->model);Render_BeginModelBatch();
  func_8026DF30_de(model,(char *)item+((D_800D297C<<6)+0x38),&D_800D0EF8,0,item->flags);
  Render_FlushModelBatch();
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
