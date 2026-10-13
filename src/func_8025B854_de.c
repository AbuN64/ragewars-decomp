#include "common/types_1dc8418c21db.h"
#include "span_1000/code_8025A3EC.h"
#include "types.h"

extern void func_802B2F00_de(void *arg0, s16 arg1);
extern s32 func_802B2620_de(void *arg0);



s32 func_8025B854_de(s32 arg0, s16 arg1)
{
  s32 temp_v0;
  s32 temp_v1;
  void *temp_s0;
  Record_func_8025B758_de *slot;
  Owner_func_8025B5F0_de *owner;
  temp_v0 = (arg1 * 0xCC) + arg0;
  temp_v0 = temp_v0 + 4;
  slot = (Record_func_8025B758_de *)temp_v0;
  temp_v1 = slot->owner;
  owner = (Owner_func_8025B5F0_de *)temp_v1;
  temp_s0 = owner->sound;
  func_802B2F00_de(temp_s0, owner->samples[slot->index]);
  func_802B2620_de(temp_s0);
}
