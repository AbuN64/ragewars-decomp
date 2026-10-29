#include "include_asm.h"
#include "COMMON/VECTOR4F.H"
#include "sdk/BUF16B.H"
#include "TYPES.H"

/* ROM-grounded data: src/rw_pool_802AFE30_CD280_us_rev1.c */
const unsigned int g_audio_CentsToPitchRatioConstantWords[2] = {
    0x3F800000, 0x3F8012EF,
};

extern f32 g_centsToPitchRatioConstants[];

f32 Audio_CentsToPitchRatio(s32 cents)
{
  f32 result;
  f32 base;
  s32 n;
  int unitRatioIndex;
  unitRatioIndex = 0;
  result = g_centsToPitchRatioConstants[unitRatioIndex];
  base = g_centsToPitchRatioConstants[1];
  n = cents;
  if (n < 0)
  {
    base = (0.999422550201416f);
    n = -n;
  }
  if (n != 0)
  {
    do
    {
      if (n & 1)
      {
        result *= base;
      }
      n >>= 1;
      base *= base;
    }
    while (n != 0);
  }
  return result;
}

extern s32 alEvtqPostEvent(void *, s16 *, s32);

void Audio_PostPlayerStopEvent(s32 playerAddress) {
    s16 stopEvent[8];

    stopEvent[0] = 0xF;
    alEvtqPostEvent(playerAddress + 0x48, stopEvent, 0);
}

#if defined(VERSION_US)
unsigned int k_EventEncodedWordsBlock2[1] = {
    0x5F745400,
};
#endif

#if defined(VERSION_EU)
unsigned int k_EventEncodedWordsBlock1[1] = {
    0x43999999,
};
#endif

#if defined(VERSION_DE)
unsigned int k_EventEncodedWords[1] = {
    0x71706C61,
};
#endif
