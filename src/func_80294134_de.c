#include "span_1000/code_80293A04.h"
#include "types.h"

extern void func_80293904_de(s32 arg0, u32 arg1, s32 arg2, s32 arg3);
void func_80294134_de(s32 arg0)
{
  s32 five;
  u32 bits;
  five = 5;
  bits = 0x41600000;
  func_80293904_de(arg0, (double) bits, five, five);
}
