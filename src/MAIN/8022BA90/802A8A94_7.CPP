#include "span_1000/code_802A8A94.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "gbi.h"
#include "gfx.h"
#include "math_helpers.h"
#include "n64sdk.h"
#include "shared/world.h"
#include "span_1000/code_8028DF6C.h"
#include "TYPES.H"

extern s32 D_800CD764_de;

extern s32 func_8028BEAC_de(void *arg0, s32 arg1, s32 arg2, s32 arg3);

extern void func_802AA8EC_de(s32 arg0, s32 arg1, void **arg2, s32 *arg3);

extern void func_80253754_de(s32 arg0, s32 arg1);

/* Appends a pipe synchronisation and an other-mode setting to the display list D_80110634 points
   into, then calls func_8026925C_de with 0x15 and func_80268CE0_de with 0x19. */



extern void func_8026925C_de(u32);

extern void func_80268CE0_de(u32);

/* Emits pipe sync, primitive color and a rectangle with nonnegative coordinates. */


extern int D_80137798[6];

extern float D_801377B0[2];

extern func_802ABC18_S1 *D_8011BDC0;

extern void func_802AA1AC_de(s32 arg0, s32 arg1, s16 arg2, s16 arg3, f32 arg4, f32 arg5, s32 arg6);

void func_802AA950_de(s32 arg0, s32 arg1, s32 *arg2, s32 *arg3)
{
  void *sp10;
  s32 sp14;
  void *new_var;
  s32 temp_v0;
  if (D_800CD764_de != 0)
  {
    temp_v0 = func_8028BEAC_de(&D_8011FE88, arg0, 0, 1);
    if (temp_v0 != 0)
    {
      func_802AA8EC_de(temp_v0, arg1, &sp10, &sp14);
      new_var = sp10;
      *arg2 = ((ImageSet *)sp10)->width;
      *arg3 = ((ImageSet *)new_var)->height;
      func_80253754_de(0, temp_v0);
    }
  }
}

void func_802AA9F4_de(void) {
    extern Gfx *D_80110634;
    Gfx *gfx;

    gfx = D_80110634++;
    gDPPipeSync(gfx);
    gfx = D_80110634++;
    gDPSetCycleType(gfx, G_CYC_1CYCLE);
    func_8026925C_de(0x15);
    func_80268CE0_de(0x19);
}

void func_802AAA54_de(s32 x0,s32 y0,s32 x1,s32 y1,u8 r,u8 g,u8 b,u8 a) {
    extern Gfx *D_80110634;
 gDPPipeSync(D_80110634++);
 gDPSetPrimColor(D_80110634++, 255, 255, r, g, b, a);
 gDPFillRectangle(D_80110634++, ((x0))>((0))?((x0)):((0)), ((y0))>((0))?((y0)):((0)), ((x1))>((0))?((x1)):((0)), ((y1))>((0))?((y1)):((0)));
}

/** Store six words into the global record. */
void func_802AAB3C_de(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5) {
    D_80137798[0] = arg0;
    D_80137798[1] = arg1;
    D_80137798[2] = arg2;
    D_80137798[3] = arg3;
    D_80137798[4] = arg4;
    D_80137798[5] = arg5;
}

void func_802AAB68_de(float arg0, float arg1) {
    D_801377B0[0] = arg0;
    D_801377B0[1] = arg1;
}

void func_802AAB7C_de(s32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, s32 arg5, s32 arg6, s32 arg7) {
    if (arg5 != 0) {
        func_802A88F0_de(arg0, arg1, arg2, arg3, arg4, 1, arg6, arg7);
    }
    func_802A88F0_de(arg0, arg1, arg2, arg3, arg4, 0, arg6, arg7);
}

s32 func_802AAC28_de(s32 arg0, s32 arg1, s16 arg2, s16 arg3, f32 arg4, f32 arg5, s32 arg6) {
    extern GfxRec *D_80110634;
    s32 temp_v0;

    if ((u32)(D_800E28A4 - ((u32)((s32)D_80110634 - D_8011BDC0->unk114) >> 3)) < 0x3E8
        || D_800CD764_de == 0
        || (temp_v0 = func_8028BEAC_de(&D_8011FE88, arg0, 0, 1), temp_v0 == 0)) {
        return 0;
    }
    func_802AA1AC_de(temp_v0, arg1, arg2, arg3, arg4, arg5, arg6);
    func_80253754_de(0, temp_v0);
    return 1;
}
