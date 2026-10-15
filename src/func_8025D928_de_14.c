#include "common/types_1dc8418c21db.h"
#include "span_1000/code_802B339C.h"
#include "types.h"
#include "audio_callbacks.h"
/* alSynStartVoiceParams, drafted from ultralib src/audio/synstartvoiceparam.c (2.0I branch, no
   fxmix clamp): posts a start-voice-alt update carrying pitch, volume, pan, fx mix, wave table and
   the ramp time in samples to the voice's channel filter. The fx mix is declared signed, since the
   cartridge keeps the reference's fxmix < 0 negation, which an unsigned type would fold away. */















extern Node_func_80239AF4_de *func_802B3BF8_de(void);          /* __allocParam */
extern s32 func_802B3CD0_de(ALSynth_func_802B3000_de *, s32);     /* _timeToSamples */

void func_802B35E0_de(ALSynth_func_802B3000_de *s, ALVoice_s_func_802B3000_de *v, void *w, f32 pitch, s16 vol, u8 pan, s8 fxmix, s32 t)
{
    ALStartParamAlt *update;
    ALFilter_s_func_802B3000_de *f;

    if (v->pvoice) {
        update = (ALStartParamAlt *)func_802B3BF8_de();
        if (update == 0) { return; };

        if (fxmix < 0) {
            fxmix = -fxmix;
        }

        update->delta = s->paramSamples + v->pvoice->offset;
        update->next = 0;
        update->type = 13; /* AL_FILTER_START_VOICE_ALT */
        update->unity = v->unityPitch;
        update->pan = pan;
        update->volume = vol;
        update->fxMix = fxmix;
        update->pitch = pitch;
        update->samples = func_802B3CD0_de(s, t);
        update->wave = w;

        f = v->pvoice->channelKnob;
        (*f->setParam)(f, 3, update); /* AL_FILTER_ADD_UPDATE */
    }
}
