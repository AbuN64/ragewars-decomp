#include "common/types_8fd754e1e915.h"
#include "span_1000/code_8024D018.h"
#include "types.h"

s32 func_8024E0A0_de(void *arg0)
{
    Actor_u1 *actor = arg0;
  Resource_u1 *temp_a0;
  int new_var;
  temp_a0 = actor->resource;
  new_var = 1;
  if ((temp_a0->kind) != new_var)
  {
    return 0;
  }
  if (new_var)
  {
    return (temp_a0->flags4C) & 0x200;
  }
}
