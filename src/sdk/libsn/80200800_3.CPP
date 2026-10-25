#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#include "IO/EXTERNS.H"
#include "TYPES.H"
#include "IO/80200568.H"

void func_80200C28_de(s32 arg0, unsigned char arg1)
{
  s32 temp_s0;
  s32 temp_s2;
  temp_s2 = ((~arg0) & 3) * 8;
  arg0 &= ~3;
  Libsn_WritePortWord(arg0, (Libsn_ReadPortWord(arg0) & (~(0xFF << temp_s2))) | ((arg1 & 0xFF) << temp_s2));
}
