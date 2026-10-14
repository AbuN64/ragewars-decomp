#include "common/types_8fd754e1e915.h"
#include "span_1000/code_80209AE8.h"
#include "types.h"

f32 func_80209AE8_de(AiController *arg0)
{
  Player *object;
    AiCharacterDefinition *definition;
  u8 state;
  f32 var_f0;
  f32 var_f1;
  object = arg0->player;
    definition = object->definition;
  state = object->profile->difficulty;
  var_f1 = definition->unk2C;
  var_f1 = var_f1 * D_800C1C90_de;
  switch (state)
  {
    case 1:
      goto done;

    default:
      arg0->player->profile->difficulty = 0;

    case 0:
      var_f0 = D_800C1C94_de;
      break;

    case 2:
      var_f0 = D_800C1C98_de;
      break;

  }

  var_f1 *= var_f0;
  done:
  return var_f1;

}
