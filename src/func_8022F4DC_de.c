#include "span_1000/code_8022F3E8.h"
#include "types.h"

extern s32 func_80265650_de(s32, s32);
s32 func_8022F4DC_de(s32 arg0, s32 arg1)
{
  if (arg1 == 0x10)
  {
    return 1;
  }
  if (arg1 == 0x11)
  {
    if (arg1 || arg0)
    {
      return 1;
    }
    else
    {
      return 1;
    }
  }
  return func_80265650_de(arg0 + 0x79, arg1);
}
