#include "COMMON/STATEPAIR.H"
#include "COMMON/OBJRECAT3CV2.H"
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHARED_MENUREPLY.H"
#include "COMMON/RECORD.H"
#include "RESMGR/802A2230_4.H"

extern void N64Eng_SetNumericWidgetValue(void *arg0, s32 arg1);


void N64Eng_DecrementNumericWidget(void *arg0)
{
    RecordN64EngCreateNumericWidget *object = arg0;
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
    N64Eng_SetNumericWidgetValue(object, var_a1);

  }
}
