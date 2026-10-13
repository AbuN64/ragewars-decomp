#include "span_1000/code_8028CCB8.h"
#include "types.h"
/* Advances the fractional animation clock and updates every active object with the resulting tick flag. */


extern void func_80250624_de(s32, s32);



void func_8028D67C_de(State_func_8028D67C_de *arg0)
{
  f32 temp_f1;
  s32 temp_a0;
  int first_index;
  s32 var_s0;
  s32 var_s3;
  
  temp_f1 = arg0->unk1B31C + 1.0f;
  arg0->unk1B31C = temp_f1;
  var_s3 = 1;
  if (!(temp_f1 > 0.0f))
  {
    var_s3 = 0;
  }
  if (var_s3 != 0)
  {
    arg0->unk1B31C = (f32) (temp_f1 - ((f32) (((s32) temp_f1) + 1)));
  }
  var_s0 = (first_index = 0);
  if (arg0->unkC4C > first_index)
  {
    do
    {
      temp_a0 = arg0->values[var_s0];
      func_80250624_de(temp_a0, var_s3);
      var_s0 += 1;
    }
    while (var_s0 < arg0->unkC4C);
  }
}
