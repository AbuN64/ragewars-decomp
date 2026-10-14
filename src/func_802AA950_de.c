#include "span_1000/code_8028DF6C.h"
#include "shared/world.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_802A8A94.h"
#include "types.h"

extern s32 D_800CD764_de;

extern s32 func_8028BEAC_de(void *arg0, s32 arg1, s32 arg2, s32 arg3);
extern void func_802AA8EC_de(s32 arg0, s32 arg1, void **arg2, s32 *arg3);
extern void func_80253754_de(s32 arg0, s32 arg1);





void func_802AA950_de(s32 arg0, s32 arg1, s32 *arg2, s32 *arg3)
{
  void *sp10;
  s32 sp14;
  void *new_var;
  s32 temp_v0;
  if (D_800CD764_de != 0)
  {
    temp_v0 = func_8028BEAC_de(&D_8011FE88, arg0, 0, 1);
    if (temp_v0 != 0)
    {
      func_802AA8EC_de(temp_v0, arg1, &sp10, &sp14);
      new_var = sp10;
      *arg2 = ((ImageSet *)sp10)->width;
      *arg3 = ((ImageSet *)new_var)->height;
      func_80253754_de(0, temp_v0);
    }
  }
}
