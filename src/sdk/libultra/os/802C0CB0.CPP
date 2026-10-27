#include "COMMON/EXTERNS_18.H"
#include "COMMON/LONE/D_800D5268_de.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/NODERECAT1C.H"
#include "TYPES.H"
#include "sdk/OSINT/802C0CB0.H"
#include "sdk/os.h"

extern s32 func_802BD080_de(void);

s32 func_802BBBC0_de(s32 virtualAddress) {
    if (virtualAddress < 0 && (u32)virtualAddress <= 0x9FFFFFFFU) {
        return virtualAddress & 0x1FFFFFFF;
    }
    if ((u32)(virtualAddress + 0x60000000) > 0x1FFFFFFFU) {
        return func_802BD080_de();
    }
    return virtualAddress & 0x1FFFFFFF;
}

s32 func_802BC36C_de(s32 *, s32);
extern void *D_800D5270;


void osYieldThread(void)
{
  void *savedInterruptMask;
  s32 *new_var2;
  s8 *new_var;
  int new_var3;
  savedInterruptMask = __osDisableInt();
  ((OSThread_s *)(new_var = (s8 *) D_800D5270))->state = (new_var3 = 2);
  new_var2 = &D_800D5268_de;
  func_802BC36C_de(new_var2, new_var3);
  __osRestoreInt(savedInterruptMask);
}
