#include "shared/gameplay_transition.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_8022AE90.h"
#include "types.h"


extern unsigned int func_802227F4_de(void *arg0, void *arg1, s32 arg2);



void func_8022B064_de(void *arg0, Vec3 *arg1)
{
  Shared_ActorView *player = arg0;
  void *new_var;
  player->resetPosition = *arg1;
  new_var = arg0;
  func_802227F4_de(new_var, new_var, 0x11);
}
