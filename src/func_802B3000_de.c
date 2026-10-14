#include "common/types_1dc8418c21db.h"
#include "span_1000/code_802B2EF8.h"
#include "types.h"
#include "audio_callbacks.h"
/* alSynAllocVoice, drafted from ultralib src/audio/synallocvoice.c: initialises a virtual voice from
   its config and binds it to a physical voice; a stolen physical voice is ramped to silence and
   stopped through two parameter updates on its channel filter. Returns whether one was bound. */















extern s32 func_802B3130_de(ALSynth_func_802B3000_de *, PVoice_s_func_802B3000_de **, s16); /* _allocatePVoice */
extern ALParam_s_func_802B3000_de *func_802B3BF8_de(void);                 /* __allocParam */

s32 func_802B3000_de(ALSynth_func_802B3000_de *drvr, ALVoice_s_func_802B3000_de *voice, ALVoiceConfig_s *vc)
{
    PVoice_s_func_802B3000_de *pvoice = 0;
    ALFilter_s_func_802B3000_de *f;
    ALParam_s_func_802B3000_de *update;
    s32 stolen;

    voice->priority = vc->priority;
    voice->unityPitch = vc->unityPitch;
    voice->table = 0;
    voice->fxBus = vc->fxBus;
    voice->state = 0;
    voice->pvoice = 0;

    stolen = func_802B3130_de(drvr, &pvoice, vc->priority);

    if (pvoice) {
        f = pvoice->channelKnob;

        if (stolen) {
            pvoice->offset = 512;
            pvoice->vvoice->pvoice = 0;

            update = func_802B3BF8_de();
            update->delta = drvr->paramSamples;
            update->type = 11; /* AL_FILTER_SET_VOLUME */
            update->data.i = 0;
            update->moredata.i = pvoice->offset - 64;
            (*f->setParam)(f, 3, update); /* AL_FILTER_ADD_UPDATE */

            update = func_802B3BF8_de();
            if (update) {
                update->delta = drvr->paramSamples + pvoice->offset;
                update->type = 15; /* AL_FILTER_STOP_VOICE */
                update->next = 0;
                (*f->setParam)(f, 3, update);
            } else {
            }
        } else {
            pvoice->offset = 0;
        }

        pvoice->vvoice = voice;
        voice->pvoice = pvoice;
    }

    return (pvoice != 0);
}
