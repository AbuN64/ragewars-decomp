#include "span_16E000/code_80429C10.h"
#include "types.h"

s32 func_8042AF3C_de(void)
{
  s32 complete = 1;
  if (D_80154010.index >= 0)
  {
 do { } while (0);
    switch (D_80154010.index)
    {
      case 0:
        complete = 5;
        break;

      case 1:
        complete = 7;
        break;

      case 3:
        complete = 11;
        break;

      case 2:
        complete = 17;
        break;

      default:
        complete = 0;
        break;

    }

    complete = (D_80154010.stages + 1) == complete;
  }
  return complete;
}
