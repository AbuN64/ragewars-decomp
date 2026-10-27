#include "include_asm.h"
#include "COMMON/VECTOR4F.H"
#include "sdk/BUF16B.H"
#include "TYPES.H"

#if !(defined(VERSION_US_REV1))
const unsigned int D_802AFE30_CD280[2] = {
    0x3F800000, 0x3F8012EF,
};
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_802AFE30_CD280_us_rev1.c */
const unsigned int D_blob_5d5e9c19015825e88044[2] = {
    0x3F800000, 0x3F8012EF,
};
#endif

extern f32 D_800C7430_de[];



f32 func_802AFE30_de(s32 arg0)
{
  f32 result;
  f32 base;
  s32 n;
  int new_var;
  new_var = 0;
  result = D_800C7430_de[new_var];
  base = D_800C7430_de[1];
  n = arg0;
  if (n < 0)
  {
    base = (0.999422550201416f);
    n = -n;
  }
  if (n != 0)
  {
    do
    {
      if (n & 1)
      {
        result *= base;
      }
      n >>= 1;
      base *= base;
    }
    while (n != 0);
  }
  return result;
}

extern s32 func_802B00D4_de(void *, s16 *, s32);

void func_802AFE80_de(s32 arg0) {
    s16 sp10[8];

    sp10[0] = 0xF;
    func_802B00D4_de(arg0 + 0x48, sp10, 0);
}

#if defined(VERSION_US)
unsigned int rodata_unresolved_802AFDDC[1] = {
    0x5F745400,
};
#endif

#if defined(VERSION_EU)
unsigned int rodata_unresolved_800C802C[1] = {
    0x43999999,
};
#endif

#if defined(VERSION_DE)
unsigned int rodata_unresolved_800C743C[1] = {
    0x71706C61,
};
#endif
