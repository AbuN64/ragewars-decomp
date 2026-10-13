#include "shared/level_actor.h"
#include "common/types_8fd754e1e915.h"
#include "span_1000/code_8022C894.h"
#include "types.h"

extern f32 D_800C2DB0_de;

void func_8022D164_de(void *arg0, void *arg1)
{
  f32 new_var3;
  f32 *new_var;
  s8 *new_var2;
  new_var2 = (s8 *) arg0;
  new_var3 = (f32) D_800C2DB0_de;
  ((Player *)new_var2)->stick = 0;
  new_var = &((Player *)arg0)->movementScale;
  ((Player *)arg0)->state6C4 = 0;
  *new_var = new_var3;
  ((Actor_func_8024A7A0_de *)arg1)->position1.x = 0;
  ((Actor_func_8024A7A0_de *)arg1)->position1.y = 0;
  ((Actor_func_8024A7A0_de *)arg1)->position1.z = 0;
}
