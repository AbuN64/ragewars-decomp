#include "span_1000/code_802B0388.h"
#include "types.h"
/* __vsVol, drafted from ultralib src/audio/seqplayer.c: combine a voice's tremolo, velocity and
   envelope gain with its sound's sample volume, the player volume and the channel volume. */









s16 func_802B1814_de(ALVoiceState_s_func_802B1814_de *vs, ALSeqPlayer_func_802B1814_de *seqp)
{
    u32 t1, t2;

    t1 = (vs->tremelo * vs->velocity * vs->envGain) >> 6;
    t2 = (vs->sound->sampleVolume * seqp->vol *
          seqp->chanState[vs->channel].vol) >> 14;

    t1 *= t2;
    t1 >>= 15;

    return (s16)t1;
}
