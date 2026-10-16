#include "span_1000/code_80200610.h"
#include "TYPES.H"

extern void func_80200C28_de(s32 address, s32 value);
extern void func_80200568_de(s32 address, s32 value);

/* Copy an arbitrary byte buffer to a PI range, packing big-endian words. */
void func_80200D18_de(s32 address, const u8 *source, u32 length)
{
  u32 word;
  while ((length != 0) && ((address & 3) != 0))
  {
    func_80200C28_de(address++, *(source++));
 do { } while (0);
    length--;
  }

  if (length >= 4)
  {
    do
    {
      word = (((((u32) source[0]) << 24) | (((u32) source[1]) << 16)) | (((u32) source[2]) << 8)) | source[3];
      func_80200568_de(address, word);
      address += 4;
      source += 4;
      length -= 4;
    }
    while (length >= 4);
  }
  while (length != 0)
  {
    func_80200C28_de(address++, *(source++));
    length--;
  }

}
