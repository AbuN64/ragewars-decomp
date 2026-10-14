#include "common/types_1dc8418c21db.h"
#include "span_1000/code_8024BA6C.h"
#include "types.h"

extern char *func_8028FDB4_de(s32 *, s32);
extern void func_8026E5E0_de(void *arg0, s32 arg1, s32 arg2, void *arg3, void *arg4);





void func_8024C5D4_de(void *arg0, void *arg1, s32 arg2, s32 arg3)
{
    ObjRecAt17C *object = arg0;
  func_8024C5C4_S2 *temp_v0;
  s32 temp_s1;
  s32 mask = 1 << arg2;
  char *new_var;
  if ((object->unk17C) & mask)
  {
    temp_v0 = func_8028FDB4_de(arg1, 3);
    temp_s1 = temp_v0->unk4;
    if (temp_s1 != 0)
    {
      new_var = &temp_v0->unk8;
      func_8026E5E0_de(new_var, temp_s1, arg3, arg0, func_8028FDB4_de(arg1, 5));
    }
  }
}
