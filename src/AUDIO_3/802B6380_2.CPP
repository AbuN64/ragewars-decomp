#include "include_asm.h"
#include "COMMON/EXTERNS_2.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/ALAUXBUS_S.H"
#include "COMMON/ALDELAY28.H"
#include "TYPES.H"

#if defined(VERSION_DE)
INCLUDE_ASM("span_1000", func_802B6380_de);
#endif

s32 func_802B6480_de(ALSave *arg0, s32 arg1, ALFilter_s14 *arg2)
{
  switch (arg1)
  {
    case 1:
      arg0->filter.source = arg2;
      goto ret0;

    case 6:
      arg0->dramout = arg2;

    default:
      ret0:
    return 0;

      return 0;

  }

}
