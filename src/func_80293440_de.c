#include "span_1000/code_80291054.h"
#include "types.h"

/* Compares two byte strings lexicographically, returning -1 for either null pointer. */
int func_80293440_de(u8 *a, u8 *b) {
 if (!a || !b) return -1;
 while (*a && *b) {
  if (*a < *b) return -1;
  if (*a > *b) return 1;
  a++; b++;
 }
 if (*a) return 1;
 if (*b) return -1;
 return 0;
}

u8 *func_802934C0_de(u8 *arg0, u8 *arg1)
{
  u8 *var_a1;
  u8 *var_v1;
  u8 temp_v0;
  u8 temp_v0_2;
 do { temp_v0 = *arg1; var_a1 = arg1 + 1; } while (0);
  *arg0 = temp_v0;
  var_v1 = arg0 - -1;
  if (temp_v0 & 0xFF)
  {
    do
    {
      temp_v0_2 = *var_a1;
      var_a1 += 1;
      *var_v1 = temp_v0_2;
      var_v1 += 1;
    }
    while (temp_v0_2 & 0xFF);
  }
  return arg0;
}

extern int D_80146878;
int func_802934F8_de(void) {
    return D_80146878 == 0xD;
}

s32 func_80292FC0_de(s32 *, s32);
extern s32 D_8011FAC0;
void func_8029350C_de(s32 arg0) {
    func_80292FC0_de(&D_8011FAC0, arg0);
}
