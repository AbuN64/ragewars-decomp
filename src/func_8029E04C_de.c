#include "span_1000/code_8029EB74.h"
#include "types.h"



extern f32 D_800C5C58_de[2];
extern f64 func_8029B278_de(f64 arg0, f64 arg1);
f32 func_8029E04C_de(f32 arg0)
{
  f32 new_var3;
  f32 value;
  f32 *new_var;
  f32 new_var2;
  value = arg0;
  new_var2 = value;
  if (1)
  {
    if (((long long) (D_800C5C48_de < new_var2)) || (new_var2 < (-25.13274383544922f)))
    {
      value = (f32) func_8029B278_de((f64) value, D_800C5C50_de);
    }
    else
    {
      if (D_800C5C58_de[0] < value)
      {
        new_var3 = D_800C5C58_de[0];
        do
        {
          value -= new_var3;
          if (1)
          {
          }
        }
        while (new_var3 < value);
      }
      if (value < 0.0f)
      {
        do
        {
          new_var = D_800C5C58_de;
          value += new_var[1];
        }
        while (value < (new_var3 = 0.0f));
      }
    }
  }
  return value;
}
