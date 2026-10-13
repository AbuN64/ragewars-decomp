#include "common/types_1dc8418c21db.h"
#include "span_1000/code_80297CD0.h"
#include "types.h"

extern s32 D_8014D080;



s32 func_80299838_de(s32 arg0)
{
  s32 count;
  struct MenuHandlerEntry *ptr;
  count = 0;
  ptr = (void *)(D_8014D080 + 0x1C);
  loop:
  if ((ptr->id) != arg0)
  {
    goto not_found;
  }

  return ptr->flags;
  not_found:
  count += 1;

  ptr += 1;
  if (count < 0x40)
  {
    if (ptr)
    {
      goto loop;
    }
    else
    {
      goto loop;
    }
  }
  return 0;
}
