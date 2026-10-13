#include "common/types_1dc8418c21db.h"
#include "common/types_8fd754e1e915.h"
#include "span_1000/code_8024D018.h"
#include "types.h"

s32 func_8024E00C_de(void *arg0)
{
    Actor_u1 *actor = arg0;
  unsigned int new_var;
  Resource_u1 *temp_a0;
  temp_a0 = actor->resource;
  new_var = 0;
  if ((temp_a0->kind) != 1)
  {
    return new_var;
  }
  if (new_var)
  {
    return (temp_a0->flags4C) & 0x1000;
  }
  else
  {
    return (temp_a0->flags4C) & 0x1000;
  }
}
