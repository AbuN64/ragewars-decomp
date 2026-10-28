#include "COMMON/ALPARAM_S.H"
#include "sdk/libgultra.h"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDRECV4.H"
#include "TYPES.H"
#include "sdk/libultra/audio/synthesizer.h"












void alSynFreeVoice(void *synth, void *voice) {
    void *Shared_func_802B3200_de_v0;
    void *voiceFilter;
    SharedRecV8 fn;
    s32 new_var;

    if ((((AudioVoicePhysicalLinkView *)(voice))->pvoice.v0) != 0) {
        if ((((struct AudioPhysicalVoiceOffsetView *) ((AudioVoicePhysicalLinkView *) voice)->pvoice.v1)->offset) != 0) {
            Shared_func_802B3200_de_v0 = Audio_AllocParam();
            if (Shared_func_802B3200_de_v0 != 0) {
                new_var = (((struct AudioSynthParamSamplesView *)(synth))->paramSamples) + (((struct AudioPhysicalVoiceOffsetView *) ((AudioVoicePhysicalLinkView *) voice)->pvoice.v1)->offset);
                ((AudioFreeVoiceUpdateView *)(Shared_func_802B3200_de_v0))->type = AL_FILTER_FREE_VOICE;
                ((AudioFreeVoiceUpdateView *)(Shared_func_802B3200_de_v0))->delta = new_var;
                ((AudioFreeVoiceUpdateView *)(Shared_func_802B3200_de_v0))->pvoice = ((AudioVoicePhysicalLinkView *)(voice))->pvoice.v0;
                voiceFilter = ((struct Draw *) ((AudioVoicePhysicalLinkView *) voice)->pvoice.v1)->model;
                fn = ((CallbackStateC_4 *)(voiceFilter))->callback;
                fn(voiceFilter, AL_FILTER_ADD_UPDATE, Shared_func_802B3200_de_v0);
                ((AudioVoicePhysicalLinkView *)(voice))->pvoice.v0 = 0;
            }
        } else {
            _freePVoice((s32) synth, ((AudioVoicePhysicalLinkView *)(voice))->pvoice.v0);
            ((AudioVoicePhysicalLinkView *)(voice))->pvoice.v0 = 0;
        }
    }
}
