#include "COMMON/ALPARAM_S.H"
#include "sdk/libgultra.h"
#include "COMMON/AUDIO_CALLBACKS.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDRECV4.H"
#include "TYPES.H"
#include "sdk/libultra/audio/synthesizer.h"

s32 osSetIntMask(s32);

/* alSynAllocVoice, drafted from ultralib src/audio/synallocvoice.c: initialises a virtual voice from
   its config and binds it to a physical voice; a stolen physical voice is ramped to silence and
   stopped through two parameter updates on its channel filter. Returns whether one was bound. */















extern s32 _allocatePVoice(AudioSynthVoiceAllocatorView *, AudioAllocatedPhysicalVoiceView **, s16);

 /* _allocatePVoice */

void alSynAddPlayer(void *synth, void *audioPlayer) {
    s32 savedInterruptMask;
    savedInterruptMask = osSetIntMask(1);
    (((ALPlayer_s14 *)audioPlayer)->samplesLeft) = (s32) (((ALSynth4C *)synth)->curSamples);
    (((ALPlayer_s14 *)audioPlayer)->next) = (((ALSynth4C *)synth)->head);
    (((ALSynth4C *)synth)->head) = (ALPlayer_s14 *)audioPlayer;
    osSetIntMask(savedInterruptMask);
}

                 /* __allocParam */

s32 alSynAllocVoice(AudioSynthVoiceAllocatorView *drvr, ALVoice_s *voice, ALVoiceConfig_s *vc)
{
    AudioAllocatedPhysicalVoiceView *pvoice = 0;
    AudioVoiceChannelFilterView *f;
    AudioVoiceAllocationUpdate *update;
    s32 stolen;

    voice->priority = vc->priority;
    voice->unityPitch = vc->unityPitch;
    voice->table = 0;
    voice->fxBus = vc->fxBus;
    voice->state = 0;
    voice->pvoice = 0;

    stolen = _allocatePVoice(drvr, &pvoice, vc->priority);

    if (pvoice) {
        f = pvoice->channelKnob;

        if (stolen) {
            pvoice->offset = 512;
            pvoice->vvoice->pvoice = 0;

            update = Audio_AllocParam();
            update->delta = drvr->paramSamples;
            update->type = AL_FILTER_SET_VOLUME; /* AL_FILTER_SET_VOLUME */
            update->data.i = 0;
            update->moredata.i = pvoice->offset - 64;
            (*f->setParam)(f, AL_FILTER_ADD_UPDATE, update); /* AL_FILTER_ADD_UPDATE */

            update = Audio_AllocParam();
            if (update) {
                update->delta = drvr->paramSamples + pvoice->offset;
                update->type = AL_FILTER_STOP_VOICE; /* AL_FILTER_STOP_VOICE */
                update->next = 0;
                (*f->setParam)(f, AL_FILTER_ADD_UPDATE, update);
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
