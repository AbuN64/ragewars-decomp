#include "span_1000/code_802B0388.h"
#include "types.h"
/* __lookupVoice, drafted from ultralib src/audio/seqplayer.c: walk the sequence player's allocated
   voice list for the voice playing a key on a channel that is not being released. */









ALVoiceState_s *func_802B1680_de(ALSeqPlayer *seqp, u8 key, u8 channel)
{
    ALVoiceState_s *vs;

    for (vs = seqp->vAllocHead; vs != 0; vs = vs->next) {
        if ((vs->key == key) && (vs->channel == channel) &&
            (vs->phase != 3) && (vs->phase != 4))
            return vs;
    }
    return 0;
}
