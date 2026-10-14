#include "shared/gameplay_transition.h"
#include "span_1000/code_8022C894.h"
#include "types.h"

extern void func_80449870_de(void *);
extern void func_802636B0_de(void *arg0);





void func_8022D4BC_de(void *arg0)
{
  f32 new_var;
  new_var = ((ObjectLinks1458_2 *)(arg0))->unk_658;
  if (D_800C2DBC_de < new_var)
  {
    ((ObjectLinks1458_2 *)(arg0))->unk_13C8 = 1;
    ((ObjectLinks1458_2 *)(arg0))->unk_1238 = -1;
    ((ObjectLinks1458_2 *)(arg0))->unk_1230 = 0;
    ((ObjectLinks1458_2 *)(arg0))->unk_122C = (((ObjectLinks1458_2 *)(arg0))->unk_122C) & (~0x20);
    func_80449870_de(arg0);
    ((ObjectLinks1458_2 *)(arg0))->unk_50 = D_800C2DC0_de;
    ((ObjectLinks1458_2 *)(arg0))->unk_54 = D_800C2DC0_de;
    ((ObjectLinks1458_2 *)(arg0))->unk_58 = D_800C2DC0_de;
    return;
  }
  func_802636B0_de(((Shared_ActorView *)arg0)->profile);
  ((struct IntegerState244 *) ((char *) ((ObjectLinks1458_2 *) arg0)->unk_1454))->unk_23C = 0;
  ((struct IntegerState244 *) ((char *) ((ObjectLinks1458_2 *) arg0)->unk_1454))->unk_240 = 0;
}
