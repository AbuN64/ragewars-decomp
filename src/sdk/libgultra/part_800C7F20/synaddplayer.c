#include "sdk/libgultra.h"
#include "COMMON/AUDIO_CALLBACKS.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDRECV4.H"
#include "TYPES.H"

s32 func_802BD170_de(s32);

/* alSynAllocVoice, drafted from ultralib src/audio/synallocvoice.c: initialises a virtual voice from
   its config and binds it to a physical voice; a stolen physical voice is ramped to silence and
   stopped through two parameter updates on its channel filter. Returns whether one was bound. */















extern s32 func_802B3130_de(ALSynth_func_802B3000_de *, PVoice_s_func_802B3000_de **, s16);

 /* _allocatePVoice */
extern ALParam_s_func_802B3000_de *__allocParam(void);

void alSynAddPlayer(void *arg0, void *arg1) {
    s32 temp_v0;
    temp_v0 = func_802BD170_de(1);
    (((struct State_func_80421D94_de *) ((s8 *) arg1))->value) = (s32) (((struct State_func_804232AC_de *) ((s8 *) arg0))->value);
    (((struct State_func_80421D94_de *) ((s8 *) arg1))->first) = (void *) (((struct State_func_804232AC_de *) ((s8 *) arg0))->menu);
    (((struct State_func_804232AC_de *) ((s8 *) arg0))->menu) = arg1;
    func_802BD170_de(temp_v0);
}

                 /* __allocParam */

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

            update = __allocParam();
            update->delta = drvr->paramSamples;
            update->type = 11; /* AL_FILTER_SET_VOLUME */
            update->data.i = 0;
            update->moredata.i = pvoice->offset - 64;
            (*f->setParam)(f, 3, update); /* AL_FILTER_ADD_UPDATE */

            update = __allocParam();
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
