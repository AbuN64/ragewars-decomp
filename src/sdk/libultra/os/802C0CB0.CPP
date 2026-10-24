#include "COMMON/EXTERNS_18.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/NODERECAT1C.H"
#include "TYPES.H"
#include "sdk/OSINT/802C0CB0.H"
#include "sdk/os.h"

extern s32 func_802BD080_de(void);

s32 func_802BBBC0_de(s32 arg0) {
    if (arg0 < 0 && (u32)arg0 <= 0x9FFFFFFFU) {
        return arg0 & 0x1FFFFFFF;
    }
    if ((u32)(arg0 + 0x60000000) > 0x1FFFFFFFU) {
        return func_802BD080_de();
    }
    return arg0 & 0x1FFFFFFF;
}

s32 func_802BC36C_de(s32 *, s32);
extern s32 D_800D5268_de;
extern void *D_800D5270;


void func_802BBC20_de(void)
{
  void *temp_s0;
  s32 *new_var2;
  s8 *new_var;
  int new_var3;
  temp_s0 = func_802BCF30_de();
  ((OSThread_s *)(new_var = (s8 *) D_800D5270))->state = (new_var3 = 2);
  new_var2 = &D_800D5268_de;
  func_802BC36C_de(new_var2, new_var3);
  __osRestoreInt(temp_s0);
}
