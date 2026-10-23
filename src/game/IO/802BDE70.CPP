#include "include_asm.h"
#include "COMMON/S1_4.H"
#include "TYPES.H"
#include "COMMON/UNUSED.H"
#include "IO/802BDE70.H"

s32 func_802B8DA0_de(void)
{
  int new_var;
  s32 *new_var2;
  new_var = (*((s32 *) (((s8 *) (&D_800D4360)) + 0))) != 0;
  if (new_var)
  {
    if (new_var2)
    {
      new_var2 = (s32 *) (((s8 *) (&D_800D4360)) + 8);
      return *new_var2;
    }
    else
    {
      new_var2 = (s32 *) (((s8 *) (&D_800D4360)) + 8);
      return *new_var2;
    }
  }
  return 0;
}

#if defined(VERSION_EU)
unsigned int func_802B8DC8_de_padding_B9C68[2] = {
    0x46010002, 0x3C01800D,
};
#endif

#if defined(VERSION_DE)
unsigned int func_802B8DC8_de_padding_B99C8[2] = {
    0x0080A021, 0xAFB5002C,
};
#endif
