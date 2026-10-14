#include "span_1000/code_802B0388.h"
#include "types.h"
s32 func_802B18A4_de(void *arg0, void *arg1) {
    ALVoiceState_s_func_802B1814_de *voice = arg0;
    ALSeqPlayer_func_802B1814_de *player = arg1;
    s32 pan;
    char center = 0x40;
    pan = player->chanState[voice->channel].pan + (voice->sound->samplePan - center);
    if (pan < 0) pan = 0;
    if (pan >= 0x80) pan = 0x7F;
    return pan & 0xFF;
}
