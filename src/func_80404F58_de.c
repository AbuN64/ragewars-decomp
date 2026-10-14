#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_80403BCC.h"
#include "types.h"
/* Loads a page-aligned resource into the selected device slot and reports the result. */




extern Device D_8014D280[];
extern s8 D_8010BBB8;
extern char D_800DCCD0[];
extern s32 *func_8025343C_de(s32, s32, s32, void *);
extern void func_80253838_de(s32, s32 *);
extern void func_80253908_de(s32);
extern void func_8025476C_de(s32);
extern s32 func_8025477C_de(void);
extern void func_80263740_de(void);

extern void func_8026454C_de(void);
extern void func_802BD3A0_de(s32, s32, s32);
extern s32 func_80447AF0_de(Device *, s32, s32, s32, s32, s32);
s32 func_80404F58_de(s32 slot, s32 arg1, s32 arg2, s32 length)
{
  s32 size;
  s32 *buf;
  s32 zero;
  s32 one;
  s32 addr;
  s32 result;
  size = (length + 0xFF) & (~0xFF);
  one = 1;
  zero = 0;
  if (D_801534F0[slot] != 3)
  {
    return -2;
  }
  if (func_8025477C_de() == 0)
  {
    func_8025476C_de(one);
  }
  buf = func_8025343C_de(0, size, 0x23, D_800DCCD0);
  addr = *buf;
  ((void (*)(s32))func_802644FC_de)(1);
  func_80263740_de();
  result = D_80153500[slot];
  D_8010BBB8 = 2;
  if (result == 0)
  {
    result = func_80447AF0_de(&D_8014D280[slot], arg1, zero, zero, size, addr);
    if (result != zero)
    {
      result = -1;
    }
    if (result == 0)
    {
      func_802BD3A0_de(arg2, addr, length);
    }
  }
  func_8026454C_de();
  func_80253908_de(zero);
  if (buf != ((void *) 0))
  {
    func_80253838_de(0, buf);
  }
  return result;
}
