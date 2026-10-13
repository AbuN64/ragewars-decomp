#include "common/types_1dc8418c21db.h"
#include "common/types_8fd754e1e915.h"
#include "span_1000/code_8024D018.h"
#include "types.h"

s32 func_8024E0F0_de(void *arg0)
{
    Actor_u1 *actor = arg0;
  Resource_u1 *new_var2;
  int new_var;
  Resource_u1 *temp_a0;
  temp_a0 = actor->resource;
  new_var2 = temp_a0;
  if ((new_var2->kind) != 1)
  {
    if (temp_a0 || new_var)
    {
      return 0;
    }
    else
    {
      return 0;
    }
  }
  new_var = 0x4C;
  return (temp_a0->flags4C) & 0x2000;
}
