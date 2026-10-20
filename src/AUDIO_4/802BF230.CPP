#include "include_asm.h"
#include "COMMON/EXTERNS_17.H"
#include "COMMON/AIPROFILE.H"
#include "AUDIO_4/802BF230.H"
#include "AUDIO_4/802BF280.H"

#if defined(VERSION_DE)
#ifdef NON_MATCHING

#include "TYPES.H"
#include "COMMON/OSTASK_T.H"

s32 func_802BA140_de(void *arg0)
{
  OSTask_t *task = arg0;
  s32 temp_a0;
  u32 temp_v0;
  temp_v0 = func_802BA190_de();
  temp_a0 = temp_v0 >> 8;
  temp_a0 = temp_a0 & 1;
  if (temp_v0 & 0x80)
  {
    task->flags = (s32) (((task->flags) | temp_a0) & (~2));
  }
  return temp_a0;
}
#else
INCLUDE_ASM("span_1000", func_802BA144);
#endif
#endif

#if !(defined(VERSION_DE))
s32 func_802BA140_de(void *arg0)
{
    s32 selected_bit;
    u32 status;
    func_80203E78_S1 *state = arg0;

    status = func_802BA190_de();
    selected_bit = status >> 8;
    selected_bit = selected_bit & 1;
    if (status & 0x80) {
        state->unk4 = (state->unk4 | selected_bit) & ~2;
    }
    return selected_bit;
}
#endif

#if defined(VERSION_US)
INCLUDE_DATA("span_1000", rodata_unresolved_802BA0BC);
#endif
