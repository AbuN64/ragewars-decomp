#include "include_asm.h"
#include "COMMON/EXTERNS_2.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/ALAUXBUS_S.H"
#include "COMMON/ALDELAY28.H"
#include "TYPES.H"


s32 func_802B6480_de(ALSave *saveFilter, s32 parameterId, ALFilter_s14 *parameterValue)
{
  switch (parameterId)
  {
    case 1:
      saveFilter->filter.source = parameterValue;
      goto ret0;

    case 6:
      saveFilter->dramout = parameterValue;

    default:
      ret0:
    return 0;

      return 0;

  }

}
