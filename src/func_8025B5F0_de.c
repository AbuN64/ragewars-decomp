#include "span_1000/code_8025A3EC.h"
#include "types.h"
/* Releases occupied nonlocal slots unless their value equals the exclusion. */





extern void func_802B2F00_de(void *sound, s16 sample);
extern s32 func_802B2620_de(void *sound);
extern void func_802B2F60_de(void *sound);
void func_8025B5F0_de(RecordRecAt4V6 *record, s32 value)
{
  s32 i;
  s32 active;
  s32 absent;
  SlotRecAtB0 *slot = record->slots;
  i = 0;
  absent = -1;
  active = 1;
  for (; i < 16; slot++, i++)
  {
    if (((slot->used != absent) && (record->header->local != i)) && ((value == absent) || (slot->value != value)))
    {
      Owner_func_8025B5F0_de *owner = slot->owner;
      void *sound;
      slot->active = active;
      slot->flag = 0;
      if (slot->key != owner->key)
      {
        sound = owner->sound;
        func_802B2F00_de(sound, owner->samples[slot->index]);
        if (func_802B2620_de(sound) != 0)
        {
          if (active)
          {
            func_802B2F60_de(sound);
          }
          else
          {
            func_802B2F60_de(sound);
          }
        }
        slot->state = absent;
      }
    }
  }

}
