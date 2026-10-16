#include "span_1000/code_80200610.h"
#include "TYPES.H"
#include "span_1000/code_80200400.h"


void func_80200F98_de(s32 address, s32 value, u32 count)
{
  u32 new_var;
  u32 byte;
  unsigned char new_var2;
  u32 word;
  new_var2 = value & 0xFF;
  while ((count != 0) && ((address & 3) != 0))
  {
    func_80200C28_de(address++, new_var2);
    count--;
  }

  if (count >= 4)
  {
    byte = new_var2;
    new_var = byte;
    word = (((byte << 24) | (byte << 16)) | (new_var << 8)) | new_var;
    do
    {
      func_80200568_de(address, word);
      count -= 4;
      address += 4;
    }
    while (count >= 4);
  }
  while (count)
  {
    func_80200C28_de(address++, new_var2);
    count--;
  }

}
