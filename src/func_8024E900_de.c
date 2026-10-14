#include "common/types_8a8189af7b05.h"
#include "span_1000/code_8024E130.h"
#include "shared/level_actor.h"
#include "types.h"

s32 func_8024E900_de(void *arg0)
{
    LevelActor *actor = arg0;
  int new_var;
  new_var = 1;
  if ((actor->kind) != 1)
  {
    if (new_var)
    {
      return 0;
    }
  }
  return (actor->flags) & 1;
}
