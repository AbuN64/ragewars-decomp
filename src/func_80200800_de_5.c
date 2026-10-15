#include "common/types_1dc8418c21db.h"
#include "resident_event_handler.h"
#include "span_1000/code_80200400.h"
#include "types.h"
void func_80200CA0_de(s32 arg0, unsigned char arg1)
{
  int new_var;
  s32 temp_s2;
  new_var = ((~arg0) & 3) * 8;
  arg0 = arg0 & (~3);
  temp_s2 = new_var;
  func_80200568_de(arg0, (func_802005A0_de(arg0) & (~(0xFF << temp_s2))) | (new_var = (arg1 & 0xFF) << temp_s2));
}
