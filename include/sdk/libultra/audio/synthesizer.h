#ifndef SDK_LIBULTRA_AUDIO_SYNTHESIZER_H
#define SDK_LIBULTRA_AUDIO_SYNTHESIZER_H
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/ALAUXBUS_S.H"

struct ALEnvMixer4C {
    char pad[0x4C];
};
struct PVoice_s {
    ListLink node;
    struct Opaque_ALVoice_s *vvoice;
    ALFilter_s14 *channelKnob;
    ALLoadFilter decoder;
    ALResampler resampler;
    ALEnvMixer4C envmixer;
    s32 offset;
};
struct ALSynth {
    void *head;
    ListLink pFreeList;
    ListLink pAllocList;
    ListLink pLameList;
    s32 paramSamples;
    s32 curSamples;
    ALDMANew dma;
    ALHeap *heap;
    ALParam_s1C *paramList;
    ALMainBus_s *mainBus;
    ALAuxBus_s *auxBus;
    ALFilter_s14 *outputFilter;
    s32 numPVoices;
    s32 maxAuxBusses;
    s32 outputRate;
    s32 maxOutSamples;
};
extern void*Audio_AllocParam(void);
extern void Audio_FreeParam(void*arg0);
extern void _freePVoice(s32 arg0, s32 listLink);
extern s32 _timeToSamples(func_8022E694_S1*arg0, s32 arg1);
#endif
