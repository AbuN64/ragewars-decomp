#include "COMMON/ALPARAM_S.H"
#include "include_asm.h"
#include "sdk/libgultra.h"
#include "COMMON/ITEMRECAT20V1.H"
#include "sdk/VOICE_START_AND_PARAMETER_UPDATE_VIEWS.H"
#include "TYPES.H"
#include "sdk/libultra/audio/synthesizer.h"












void alSynSetVol(void *synth, void *voice, s16 targetVolume, s32 rampTime) {
    s32 new_var;
    void *Shared_func_802B3480_de_v0;
    void *voiceFilter;
    SharedRecV10 fn;

    if ((((AudioVoicePhysicalLinkView *)(voice))->pvoice.v0) != 0) {
        Shared_func_802B3480_de_v0 = Audio_AllocParam();
        if (Shared_func_802B3480_de_v0 != 0) {
            new_var = (((struct AudioSynthParamSamplesView *)(synth))->paramSamples) + (((struct AudioPhysicalVoiceOffsetView *) ((AudioVoicePhysicalLinkView *) voice)->pvoice.v1)->offset);
            ((AudioVolumeControlUpdate *)(Shared_func_802B3480_de_v0))->type = AL_FILTER_SET_VOLUME;
            ((AudioVolumeControlUpdate *)(Shared_func_802B3480_de_v0))->volume = (s32) targetVolume;
            ((AudioVolumeControlUpdate *)(Shared_func_802B3480_de_v0))->delta = new_var;
            ((AudioVolumeControlUpdate *)(Shared_func_802B3480_de_v0))->samples = _timeToSamples(synth, rampTime);
            ((AudioVolumeControlUpdate *)(Shared_func_802B3480_de_v0))->next = 0;
            voiceFilter = ((struct Draw *) ((AudioVoicePhysicalLinkView *) voice)->pvoice.v1)->model;
            fn = ((CallbackStateC_4 *)(voiceFilter))->callback;
            fn(voiceFilter, AL_FILTER_ADD_UPDATE, Shared_func_802B3480_de_v0);
        }
    }
}

#if defined(VERSION_US)
char rodata_unresolved_802B3468[8] =
    "e_t\022CROM";
#endif
