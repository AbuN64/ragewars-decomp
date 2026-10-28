#include "COMMON/ALPARAM_S.H"
#include "sdk/libgultra.h"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDRECV4.H"
#include "TYPES.H"
#include "sdk/libultra/audio/synthesizer.h"












void alSynSetFXMix(void *synth, void *voice, s8 effectMix) {
    s32 new_var;
    s32 mixMagnitude;
    void *Shared_func_802B32A0_de_v0;
    void *voiceFilter;
    SharedRecV4 fn;

    if ((((AudioVoicePhysicalLinkView *)(voice))->pvoice.v0) != 0) {
        Shared_func_802B32A0_de_v0 = Audio_AllocParam();
        if (Shared_func_802B32A0_de_v0 != 0) {
            new_var = (((struct AudioSynthParamSamplesView *)(synth))->paramSamples) + (((struct AudioPhysicalVoiceOffsetView *) ((AudioVoicePhysicalLinkView *) voice)->pvoice.v1)->offset);
            ((AudioIntegerControlUpdate *)(Shared_func_802B32A0_de_v0))->type = AL_FILTER_SET_FXAMT;
            ((AudioIntegerControlUpdate *)(Shared_func_802B32A0_de_v0))->delta = new_var;
            if (effectMix < 0) {
                mixMagnitude = -effectMix;
            } else {
                mixMagnitude = (u8) effectMix;
            }
            ((AudioIntegerControlUpdate *)(Shared_func_802B32A0_de_v0))->value = mixMagnitude;
            ((AudioIntegerControlUpdate *)(Shared_func_802B32A0_de_v0))->next = 0;
            voiceFilter = ((struct Draw *) ((AudioVoicePhysicalLinkView *) voice)->pvoice.v1)->model;
            fn = ((CallbackStateC_4 *)(voiceFilter))->callback;
            fn(voiceFilter, AL_FILTER_ADD_UPDATE, Shared_func_802B32A0_de_v0);
        }
    }
}












void alSynSetPan(void *synth, void *voice, u8 pan) {
    s32 new_var;
    void *Shared_func_802B3350_de_v0;
    void *voiceFilter;
    SharedRecV5 fn;

    if ((((AudioVoicePhysicalLinkView *)(voice))->pvoice.v0) != 0) {
        Shared_func_802B3350_de_v0 = Audio_AllocParam();
        if (Shared_func_802B3350_de_v0 != 0) {
            new_var = (((struct AudioSynthParamSamplesView *)(synth))->paramSamples) + (((struct AudioPhysicalVoiceOffsetView *) ((AudioVoicePhysicalLinkView *) voice)->pvoice.v1)->offset);
            ((AudioIntegerControlUpdate *)(Shared_func_802B3350_de_v0))->type = AL_FILTER_SET_PAN;
            ((AudioIntegerControlUpdate *)(Shared_func_802B3350_de_v0))->value = pan;
            ((AudioIntegerControlUpdate *)(Shared_func_802B3350_de_v0))->next = 0;
            ((AudioIntegerControlUpdate *)(Shared_func_802B3350_de_v0))->delta = new_var;
            voiceFilter = ((struct Draw *) ((AudioVoicePhysicalLinkView *) voice)->pvoice.v1)->model;
            fn = ((CallbackStateC_4 *)(voiceFilter))->callback;
            fn(voiceFilter, AL_FILTER_ADD_UPDATE, Shared_func_802B3350_de_v0);
        }
    }
}












void alSynSetPitch(void *synth, void *voice, f32 pitchRatio) {
    s32 new_var;
    void *Shared_func_802B33E0_de_v0;
    void *voiceFilter;
    SharedRecV7 fn;

    if ((((AudioVoicePhysicalLinkView *)(voice))->pvoice.v0) != 0) {
        Shared_func_802B33E0_de_v0 = Audio_AllocParam();
        if (Shared_func_802B33E0_de_v0 != 0) {
            new_var = (((struct AudioSynthParamSamplesView *)(synth))->paramSamples) + (((struct AudioPhysicalVoiceOffsetView *) ((AudioVoicePhysicalLinkView *) voice)->pvoice.v1)->offset);
            ((AudioPitchControlUpdate *)(Shared_func_802B33E0_de_v0))->type = AL_FILTER_SET_PITCH;
            ((AudioPitchControlUpdate *)(Shared_func_802B33E0_de_v0))->pitch = pitchRatio;
            ((AudioPitchControlUpdate *)(Shared_func_802B33E0_de_v0))->next = 0;
            ((AudioPitchControlUpdate *)(Shared_func_802B33E0_de_v0))->delta = new_var;
            voiceFilter = ((struct Draw *) ((AudioVoicePhysicalLinkView *) voice)->pvoice.v1)->model;
            fn = ((CallbackStateC_4 *)(voiceFilter))->callback;
            fn(voiceFilter, AL_FILTER_ADD_UPDATE, Shared_func_802B33E0_de_v0);
        }
    }
}
