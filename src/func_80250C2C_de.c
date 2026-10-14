#include "common/types_1dc8418c21db.h"
#include "span_1000/code_802508E0.h"
#include "types.h"

void func_80250C2C_de(void *arg0, s32 **arg1)
{
  struct ResourceBinding *binding = arg0;
  s32 new_var;
  new_var = *(*arg1);
  func_80253E64_de(0, arg1, func_802784C0_de(new_var, *binding->resource, binding->runtimeState, (s32)binding->transform, 0, arg0));
}
