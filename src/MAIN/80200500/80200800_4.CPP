#include "common/types_1dc8418c21db.h"
#include "resident_event_handler.h"
#include "span_1000/code_80200400.h"
#include "TYPES.H"
void func_80200C28_de(s32 arg0, unsigned char arg1)
{
  s32 temp_s0;
  s32 temp_s2;
  temp_s2 = ((~arg0) & 3) * 8;
  arg0 &= ~3;
  func_80200568_de(arg0, (func_802005A0_de(arg0) & (~(0xFF << temp_s2))) | ((arg1 & 0xFF) << temp_s2));
}
