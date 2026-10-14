#include "common/types_1dc8418c21db.h"
#include "resident_event_handler.h"
#include "span_1000/code_80200610.h"
void func_80200C28_de(s32 arg0, s32 arg1);
void func_80201064_de(s32 arg0, s32 arg1, s32 arg2)
{
  int new_var2;
  int new_var;
  s32 temp_a0;
  s32 var_a0;
  s32 var_s0;
  s32 var_s1;
  s32 var_s2;
  var_s1 = arg0;
  var_s2 = arg1;
  var_s0 = arg2;
  var_s0 = var_s0 - 1;
  if (arg2 != 0)
  {
    new_var = -1;
    var_a0 = var_s2;
    do
    {
      var_s2 += 1;
      new_var2 = func_80200800_de(var_a0);
      temp_a0 = var_s1;
      var_s1 += 1;
      func_80200C28_de(temp_a0, new_var2 & 0xFF);
      var_s0 -= 1;
      var_a0 = var_s2;
    }
    while (var_s0 != new_var);
  }
}
