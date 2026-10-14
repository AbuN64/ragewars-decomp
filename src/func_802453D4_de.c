#include "span_1000/code_80243A80.h"
#include "shared/func_802453D4_de_closed.h"

void func_802453D4_de(void)
{
  f32 var_f20;
  f32 temp_f12;
  int new_var2;
  f32 temp_f1;
  f32 temp_f21;
  f32 temp_f22;
  f32 var_f0;
  f32 var_f12;
  s32 var_s0;
  s32 var_s1;
  s32 new_var;
  s32 temp_height;
  void *temp_a0;
  if ((D_800E2830->messageCount) > 0)
  {
    s32 temp_s7;
    s32 temp_s6;
    temp_s7 = 0x1A;
    temp_s6 = D_800E28D0 / 2;
    func_802A84F8_de();
    temp_f12 = (f32) (D_800E28D0 / 284);
    var_f20 = (f32) (D_800E28D4 / 222);
    temp_height = D_800E28D4;
    if (temp_height >= 0xDF)
    {
      var_s1 = 0xB4;
      var_f0 = D_800C37C0_de;
      var_f12 = temp_f12 * var_f0;
      var_f20 *= var_f0;
    }
    else
    {
      var_s1 = 0x6E;
      var_f0 = D_800C37C4_de;
      var_f12 = temp_f12 * var_f0;
      var_f20 *= var_f0;
    }
    new_var = 0;
    func_802AAB68_de(var_f12, var_f20);
    temp_a0 = D_800E2830;
    D_801377B8[0] = 1;
    D_801377B8[1] = 1;
    var_s0 = new_var;
    if ((((Shared_MenuContext *)(temp_a0))->messageCount) > new_var)
    {
      new_var2 = 0;
      temp_f22 = D_800C37C8_de;
      temp_f21 = D_800C37CC_de;
      do
      {
        func_802A8F28_de(((Shared_MenuContext *)temp_a0)->messages[var_s0], temp_s6, var_s1, 0xFF, 1, 1, temp_f22, temp_f22);
        temp_f1 = ((f32) temp_s7) * var_f20;
        temp_f12 = (f32) (D_800E28D0 / 284);
        var_f20 = ((f32) (D_800E28D4 / 222)) * temp_f21;
        var_s1 = (s32) (((f32) var_s1) + temp_f1);
        func_802AAB68_de(temp_f12 * temp_f21, var_f20);
        var_s0 += 1;
      }
      while (var_s0 < ((Shared_MenuContext *)(temp_a0 = D_800E2830))->messageCount);
    }
  }
}
