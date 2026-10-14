#include "span_1000/code_802BB15C.h"
#include "span_1000/code_8023B9A0.h"
#include "types.h"

extern s32 D_800C3600_de;
extern s32 D_800FF254;
void func_802BAC60_de(void *arg0, s32 arg1, s32 arg2);
void **func_8025343C_de(s32 arg0, s32 arg1, s32 arg2, void *arg3);
void func_802BB420_de(void *arg0, void *arg1, s32 arg2);




s32 func_8023C78C_de(s32 arg0, s32 arg1_unused, s32 arg2)
{
  char sp10[0x18];
  int new_var2;
  Block10 blk;
  s32 sp38;
  u32 temp_s1;
  s32 sp3C;
  u32 rounded;
  void **temp_v0;
  Draw *temp_v1;
  int new_var;
  temp_s1 = ((u32) (arg0 + 0xFFF)) >> 0xC;
  new_var = (temp_s1 + 1) & (~1);
  if (1)
  {
    func_802BAC60_de(sp10, (s32) (&sp38), 1);
    blk.f28 = 3;
    blk.f2C = arg0;
    blk.f34 = (void **) sp10;
    new_var2 = temp_s1 * 4;
    rounded = new_var + 0x18;
    temp_v0 = func_8025343C_de(0, new_var2 + rounded, 3, &D_800C3600_de);
    temp_v1 = *temp_v0;
    blk.f30 = temp_v1;
    temp_v1->model = temp_v0;
  }
  ((Draw *)blk.f30)->allocationMode = arg2;
  func_802BB420_de(&D_800FF254, &blk.f28, 1);
  func_802BB2A0_de(sp10, &sp3C, 1);
  return sp3C;
}
