
#include "types.h"
#include "span_C76B0/data.h"
#include "common/unused.h"
#include "span_1000/code_80254CE4.h"
void func_80254D44_de(s32 arg0, s32 arg1)
{
  s32 mask;
  u32 count;
  int new_var;
  u32 new_var2;
  s32 offset;
  u32 limit;
  mask = -0x201;
  if (arg1 != 0)
  {
    mask = -0x401;
  }
 do { count = 0; limit = D_800CB6E0; } while (0);
  new_var2 = limit;
  if (limit != 0)
  {
    offset = count;
    do
    {
      new_var = offset + D_80100560;
      count += 1;
      *((s32 *) (new_var + 0xC)) &= mask;
      offset += 0x28;
    }
    while (count < new_var2);
  }
  D_80101134[arg1] = 0;
}

