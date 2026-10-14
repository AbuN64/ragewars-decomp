#include "span_1000/code_802609CC.h"
#include "types.h"

extern s32 func_802607B8_de(s32 arg0, s32 arg1);
void func_80261238_de(s32 arg0, void *arg1, s32 arg2)
{
  int new_var;
  s32 sp10;
  s32 var_s0;
  u8 *var_s1;
  new_var = 0;
  var_s0 = new_var;
  if (arg2 > new_var)
  {
    var_s1 = (u8 *) arg1;
    do
    {
      var_s0 += 1;
      sp10 = func_802607B8_de(arg0, 0x20);
      *((f32 *) var_s1) = *((f32 *) (&sp10));
      var_s1 += 0x10;
    }
    while (var_s0 < arg2);
  }
}
