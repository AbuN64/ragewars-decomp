#include "COMMON/ALPARAM_S.H"
#include "include_asm.h"
#include "../../../include/libgultra.h"
#include "COMMON/ITEMRECAT20V1.H"
#include "../../../include/VOICE_START_AND_PARAMETER_UPDATE_VIEWS.H"
#include "TYPES.H"
#include "../../../include/libgultra/ALSYNSTARTVOICE.H"
#include "../../../include/libultra/audio/synthesizer.h"

/* alSynStartVoice_Alsynstartvoice.c */
void alSynStartVoice(void *synth, void *voice, s32 waveTable) {
    s32 updateSampleTime;
    void *controlUpdate;
    void *voiceFilter;
    SharedRecV3 fn;

    if ((((AudioVoiceStartView *)(voice))->pvoice.v0) != 0) {
        controlUpdate = __allocParam();
        if (controlUpdate != 0) {
            updateSampleTime = (((struct AudioSynthParamSamplesView *)(synth))->paramSamples) + (((struct AudioPhysicalVoiceOffsetView *) ((AudioVoiceStartView *) voice)->pvoice.v1)->offset);
            ((AudioStartVoiceUpdate *)(controlUpdate))->type = AL_FILTER_START_VOICE;
            ((AudioStartVoiceUpdate *)(controlUpdate))->wave = waveTable;
            ((AudioStartVoiceUpdate *)(controlUpdate))->next = 0;
            ((AudioStartVoiceUpdate *)(controlUpdate))->delta = updateSampleTime;
            ((AudioStartVoiceUpdate *)(controlUpdate))->unity = ((AudioVoiceStartView *)(voice))->unityPitch;
            voiceFilter = ((struct Draw *) ((AudioVoiceStartView *) voice)->pvoice.v1)->model;
            fn = ((CallbackStateC_4 *)(voiceFilter))->callback;
            fn(voiceFilter, AL_FILTER_ADD_UPDATE, controlUpdate);
        }
    }
}

/* 8025DE50_11.CPP */
#if defined(VERSION_DE)
unsigned char g_AlsynstartvoiceTrailingBytes[12] = { 0xF7, 0xB4, 0x00, 0x38, 0x44, 0x87, 0xA0, 0x00, 0xAF, 0xB1, 0x00, 0x14 };
#endif

/* 8025DE50_19.CPP */
/* 8025DE50_19.CPP */
#if defined(VERSION_EU)
unsigned char g_AlsynstartvoiceTrailingBytesBlock1[12] = { 0xAF, 0xB4, 0x00, 0x20, 0x24, 0x14, 0x00, 0x01, 0xAF, 0xB1, 0x00, 0x14 };
#endif

#if defined(VERSION_EU_X) || defined(VERSION_US_REV1)
unsigned char g_AlsynstartvoiceTrailingBytesBlock2[8] = { 0x03, 0xE0, 0x00, 0x08, 0x27, 0xBD, 0x00, 0x18 };
#endif

/* 8025DE50_9.CPP */
#if defined(VERSION_US)
unsigned char s_aternText[12] = { 0x61, 0x74, 0x65, 0x72, 0x6E, 0x5F, 0x74, 0x09, 0x6D, 0x5F, 0x71, 0x47 };
#endif
