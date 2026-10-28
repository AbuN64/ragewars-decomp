#include "COMMON/ALPARAM_S.H"
#include "include_asm.h"
#include "sdk/libgultra.h"
#include "COMMON/ITEMRECAT20V1.H"
#include "sdk/VOICE_START_AND_PARAMETER_UPDATE_VIEWS.H"
#include "TYPES.H"
#include "sdk/libgultra/ALSYNSTARTVOICE.H"
#include "sdk/libultra/audio/synthesizer.h"

/* code_802B8370_4.c */
void alSynStartVoice(void *synth, void *voice, s32 waveTable) {
    s32 new_var;
    void *Shared_func_802B3540_de_v0;
    void *voiceFilter;
    SharedRecV3 fn;

    if ((((AudioVoiceStartView *)(voice))->pvoice.v0) != 0) {
        Shared_func_802B3540_de_v0 = Audio_AllocParam();
        if (Shared_func_802B3540_de_v0 != 0) {
            new_var = (((struct AudioSynthParamSamplesView *)(synth))->paramSamples) + (((struct AudioPhysicalVoiceOffsetView *) ((AudioVoiceStartView *) voice)->pvoice.v1)->offset);
            ((AudioStartVoiceUpdate *)(Shared_func_802B3540_de_v0))->type = AL_FILTER_START_VOICE;
            ((AudioStartVoiceUpdate *)(Shared_func_802B3540_de_v0))->wave = waveTable;
            ((AudioStartVoiceUpdate *)(Shared_func_802B3540_de_v0))->next = 0;
            ((AudioStartVoiceUpdate *)(Shared_func_802B3540_de_v0))->delta = new_var;
            ((AudioStartVoiceUpdate *)(Shared_func_802B3540_de_v0))->unity = ((AudioVoiceStartView *)(voice))->unityPitch;
            voiceFilter = ((struct Draw *) ((AudioVoiceStartView *) voice)->pvoice.v1)->model;
            fn = ((CallbackStateC_4 *)(voiceFilter))->callback;
            fn(voiceFilter, AL_FILTER_ADD_UPDATE, Shared_func_802B3540_de_v0);
        }
    }
}

/* 8025DE50_11.CPP */
#if defined(VERSION_DE)
unsigned char D_auto_func_802B35D4_de_padding_B41D4[12] = { 0xF7, 0xB4, 0x00, 0x38, 0x44, 0x87, 0xA0, 0x00, 0xAF, 0xB1, 0x00, 0x14 };
#endif

/* 8025DE50_19.CPP */
/* 8025DE50_19.CPP */
#if defined(VERSION_EU)
unsigned char D_auto_func_802B3874_eu_padding_B4474[12] = { 0xAF, 0xB4, 0x00, 0x20, 0x24, 0x14, 0x00, 0x01, 0xAF, 0xB1, 0x00, 0x14 };
#endif

#if defined(VERSION_EU_X) || defined(VERSION_US_REV1)
unsigned char D_auto_func_802B86A4_us_rev1_padding_B92A4[8] = { 0x03, 0xE0, 0x00, 0x08, 0x27, 0xBD, 0x00, 0x18 };
#endif

/* 8025DE50_9.CPP */
#if defined(VERSION_US)
unsigned char s_aternText[12] = { 0x61, 0x74, 0x65, 0x72, 0x6E, 0x5F, 0x74, 0x09, 0x6D, 0x5F, 0x71, 0x47 };
#endif
