#include "span_1000/code_802A8A94.h"
#include "types.h"

void func_802AA6D0_de(void *arg0, s16 arg1, s16 arg2)
{
  Mover *mover = arg0;
  mover->handle = -1;
  mover->active = 0;
  mover->state = 0;
  mover->x = (f32) arg1;
  mover->y = (f32) arg2;
}
