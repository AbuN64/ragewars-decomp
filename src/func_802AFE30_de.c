#include "common/types_06e4f7ef1f9e.h"
#include "span_1000/code_802AFEAC.h"
#include "types.h"

extern f32 D_800C7430_de[];



f32 func_802AFE30_de(s32 arg0)
{
  f32 result;
  f32 base;
  s32 n;
  int new_var;
  new_var = 0;
  result = D_800C7430_de[new_var];
  base = D_800C7430_de[1];
  n = arg0;
  if (n < 0)
  {
    base = (0.999422550201416f);
    n = -n;
  }
  if (n != 0)
  {
    do
    {
      if (n & 1)
      {
        result *= base;
      }
      n >>= 1;
      base *= base;
    }
    while (n != 0);
  }
  return result;
}

extern s32 func_802B00D4_de(void *, s16 *, s32);

void func_802AFE80_de(s32 arg0) {
    s16 sp10[8];

    sp10[0] = 0xF;
    func_802B00D4_de(arg0 + 0x48, sp10, 0);
}
