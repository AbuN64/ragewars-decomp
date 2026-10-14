#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_8042BD40.h"
#include "types.h"











/* For each of the 8 occupied slots without the pending-remove flag, runs its two release callbacks. */







extern Shared_BigObj *D_800E53C0;
extern Shared_Rec3 D_80146398[8];

extern void func_804243E0_de(s32 a0, struct IntPair *a1);
extern void func_804259E0_de(s32 a0);

void func_8042D118_de(void)
{
  s32 i;
  Shared_BigObj *obj;
  int temp_1;
  Shared_Rec3 *recs;
  for (i = 0; i < 8; i++)
  {
    s32 val;
    temp_1 = -1;
    obj = D_800E53C0;
    recs = D_80146398;
    val = obj->slot[i];
    if (val == temp_1)
    {
      continue;
    }
    if ((recs + val)->flag != 0)
    {
      continue;
    }
    func_804243E0_de(val, &obj->arr2[val]);
    recs = D_80146398;
    func_804259E0_de(val);
  }

}
