#include "span_16E000/code_80400000.h"
#include "common/types_8fd754e1e915.h"
#include "span_1000/code_8022BA90.h"
#include "types.h"

extern u8 D_801462DE;


extern s32 D_800E28D0;
extern s32 D_800E28D4;
void func_802A9234_de(u8 arg0);
void func_802AAC28_de(s32 arg0, s32 arg1, s16 arg2, s16 arg3, f32 arg4, f32 arg5, s32 arg6);



void func_8022C2B4_de(void *arg0, struct ScreenRectangle *arg1)
{
  f32 x;
  f32 y;
  f32 ax;
  f32 ay;
  f32 sx;
  f32 sy;
  f32 bx;
  f32 by;
  f32 screenX;
  f32 screenY;
  func_802A9234_de(D_801462DE);
  x = arg1->x;
  ax = x * D_800C2D30_de;
  y = arg1->y;
  ay = y * D_800C2D30_de;
  sx = x / ((f32) D_800E28D0);
  bx = sx * D_800C2D34_de;
  sy = y / ((f32) D_800E28D4);
  by = sy * D_800C2D34_de;
  screenX = ((arg1->width) + ax) - bx;
  screenY = ((arg1->height) + ay) - by;
  func_802AAC28_de(0x1FB, 0, (s16) ((s32) (((arg1->width) + ax) - bx)), (s16) ((s32) screenY), sx, sy, 1);
}
