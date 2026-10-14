#include "shared/legacy_collision_actor.h"
#include "common/types_8fd754e1e915.h"
#include "shared/world.h"
#include "common/types_1dc8418c21db.h"
#include "span_1000/code_8023D370.h"
#include "types.h"


extern void *func_8028B2F8_de(void *, u16 *);





void func_8023ECBC_de(void *arg0, u16 *arg1)
{
  char *o = (char *) arg0;
  s32 temp_v1;
  s32 temp_v1_2;
  s32 var_v0;
  void *temp_v0;
  temp_v1 = ((Shared_Func80243A80Frame *)o)->sp54;
  if (temp_v1 & 0x1000)
  {
    ((Shared_Func80243A80Frame *)o)->sp54 = temp_v1 & (~0x2000);
  }
  temp_v1_2 = ((Shared_Func80243A80Frame *)o)->sp54;
  ((Shared_Func80243A80Frame *)o)->sp54 = temp_v1_2 & 0xFFFC7FFF;
  if (temp_v1_2 & 0x7000)
  {
    temp_v0 = func_8028B2F8_de(&D_8011FE88, arg1);
    if (temp_v0 != 0)
    {
      if ((((ModelBlend *)temp_v0)->collisionFlags) & 0x400000)
      {
        ;
        ((Shared_Func80243A80Frame *)o)->sp54 = (((Shared_Func80243A80Frame *)o)->sp54) | 0x8000;
      }
      else
        if ((((ModelBlend *)temp_v0)->materialFlags) & 0x80)
      {
        var_v0 = (((Shared_Func80243A80Frame *)o)->sp54) | 0x10000;
        ((Shared_Func80243A80Frame *)o)->sp54 = var_v0;
      }
    }
  }
}
