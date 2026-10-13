#include "span_1000/code_802536F4.h"
#include "types.h"

extern char D_801051A0;
extern void *func_80255A34_de(void *arg0, s32 arg1);
extern void *func_80255920_de(void *, s32);

void *func_80254B8C_de(s32 arg0, u32 arg1, s32 arg2, u32 arg3)
{
  void *result;
  s32 value;
  if (arg2 != 0)
  {
    result = func_80255A34_de(&D_801051A0, arg1);
  }
  else
    if (value)
  {
    result = func_80255920_de(&D_801051A0, arg1);
  }
  else
  {
    result = func_80255920_de(&D_801051A0, arg1);
  }
  if (result == 0)
  {
    arg3 &= 0x10;
    do
    {
      value = func_80251328_de(0, 2, arg3 == 0);
    }
    while ((value != 0) && (value < arg1));
    if (value >= arg1)
    {
      if (arg2 != 0)
      {
        result = func_80255A34_de(&D_801051A0, arg1);
      }
      else
      {
        result = func_80255920_de(&D_801051A0, arg1);
      }
    }
  }
  return result;
}
