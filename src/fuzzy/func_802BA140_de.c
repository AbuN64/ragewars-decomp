
#include "TYPES.H"
#include "span_1000/code_802B9ED8.h"

s32 func_802BA140_de(void *arg0)
{
  OSTask_t *task = arg0;
  s32 temp_a0;
  u32 temp_v0;
  temp_v0 = func_802BA190_de();
  temp_a0 = temp_v0 >> 8;
  temp_a0 = temp_a0 & 1;
  if (temp_v0 & 0x80)
  {
    task->flags = (s32) (((task->flags) | temp_a0) & (~2));
  }
  return temp_a0;
}
