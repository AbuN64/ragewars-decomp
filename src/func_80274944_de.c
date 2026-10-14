#include "span_1000/code_8027451C.h"
#include "types.h"

extern f32 D_800C4968_de[2];
extern f32 D_800C4970_de[2];
f32 func_80274944_de(f32 arg0)
{
  unsigned char new_var;
  f32 val;
  val = arg0;
  new_var = 0;
  if (val < D_800C4968_de[new_var])
  {
    do
    {
      val += D_800C4968_de[1];
    }
    while (val < D_800C4968_de[new_var]);
  }
  if (D_800C4970_de[new_var] < val)
  {
    do
    {
      val -= D_800C4970_de[1];
    }
    while (D_800C4970_de[new_var] < val);
  }
  return -val;
}
