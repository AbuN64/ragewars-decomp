#include "shared/world.h"
#include "types.h"
#include "span_1000/code_8028DF6C.h"

extern Actor_func_8028E284_de *D_800F3CF8[4];
extern Actor_func_8028E284_de *D_800F3D08;

extern s32 func_8028B25C_de(s32, s32);

void func_8028E108_de(void *arg0)
{
  Scene_func_8028E284_de *scene = arg0;
  Actor_func_8028E284_de *actor = scene->actors;
  s32 i;
  s32 count;
  s32 result;
  Actor_func_8028E284_de **slot = D_800F3CF8 + 4;
  D_800F3D08 = 0;
  for (i = 3; i >= 0; i--)
  {
    *--slot = 0;
  }

  count = scene->count;
  if (count <= 0)
  {
    return;
  }
  i = 0;
  do
  {
    if (actor->def->type == 3)
    {
      result = func_8028B25C_de((s32) (&D_8011FE88), actor->def->id);
      if (result == 0xBD7)
      {
        D_800F3D08 = actor;
        return;
      }
    }
    else
      if (actor->def->type == 10)
    {
      switch (actor->id)
      {
        case 0x653:
          D_800F3CF8[0] = actor;
          break;

        case 0x654:
          D_800F3CF8[1] = actor;
          break;

        case 0x655:
          D_800F3CF8[2] = actor;
          break;

        case 0x656:
          D_800F3CF8[3] = actor;
          break;

      }

    }
    actor++;
    i++;
  }
  while (i < scene->count);
  return;
}
