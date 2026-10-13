#include "span_1000/code_802A1264.h"
#include "span_1000/code_802A208C.h"
#include "types.h"

extern void func_802A1B24_de(void *arg0, s32 arg1);



void func_802A1D14_de(void *arg0)
{
    Record_func_802A1990_de *object = arg0;
  s32 temp_a1;
  s32 temp_v1;
  s32 var_a1;
  if ((object->field_54) == 0)
  {
    temp_a1 = object->field_58;
    if ((object->field_50) < temp_a1)
    {
      var_a1 = temp_a1 - 1;
      goto block_7;
    }
  }
  else
  {
    temp_v1 = object->field_58;
    if (temp_v1 == (object->field_50))
    {
      object->field_58 = object->field_4C;
    }
    else
    {
      object->field_58 = temp_v1 - 1;
    }
    var_a1 = object->field_58;
    block_7:
    func_802A1B24_de(object, var_a1);

  }
}
