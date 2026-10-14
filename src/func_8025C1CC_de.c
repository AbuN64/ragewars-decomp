#include "span_1000/code_8025A3EC.h"
#include "types.h"


extern f32 D_800C3F90_de;

f32 func_8025C1CC_de(f32 arg0)
{
  f32 temp_f0;
  f32 temp_f1;
  f32 temp_f2;
  s32 temp_f3;
  s16 temp_s16;
  s32 temp_plus;
  temp_f0 = (arg0 + (&D_800C3F88_de)[1]) * D_800C3F90_de;
  temp_f3 = (s32) temp_f0;
  temp_s16 = (s16) temp_f3;
  temp_f1 = (f32) temp_s16;
  if (temp_f1 != temp_f0)
  {
    temp_plus = temp_f3 + 1;
    temp_f2 = (&D_800CB8E8)[1 + temp_s16];
    return temp_f2 + ((temp_f0 - temp_f1) * ((&D_800CB8E8)[1 + ((s16) temp_plus)] - temp_f2));
  }
  return (&D_800CB8E8)[1 + temp_s16];
}
