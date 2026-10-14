#include "span_1000/code_802646F4.h"
#include "types.h"

extern s8 D_8010B30B;
void func_8026479C_de(void)
{
  int new_var2;
  s8 *new_var;
  s32 var_v1;
  s8 *var_v0;
  new_var2 = 1;
  var_v1 = 3;
  new_var = &D_8010B30B;
  var_v0 = new_var;
  do
  {
    *var_v0 = new_var2;
    var_v1 -= 1;
    var_v0 -= 1;
  }
  while (var_v1 >= 0);
}
