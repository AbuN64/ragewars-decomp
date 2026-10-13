#include "common/types_8fd754e1e915.h"
#include "shared/level_actor.h"
#include "common/types_06e4f7ef1f9e.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_802661FC.h"
#include "types.h"


extern void func_80232744_de(void *arg0, s32 arg1, s32 arg2);





void func_80267D70_de(s32 arg0, void *arg1, s32 arg2, Vec3 arg3, s32 arg6)
{
  s32 t6 = arg6;
  void *temp = ((Actor_func_8024A7A0_de *)arg1)->controller;
  ((Player *)temp)->requestedPosition = arg3;
 /* FAKEMATCH: preserve instruction scheduling between the copied triple and the following call. */
 do { } while (0);
  func_80232744_de(arg1, (s32) ((char *)arg1 + 0x170), t6);
}
