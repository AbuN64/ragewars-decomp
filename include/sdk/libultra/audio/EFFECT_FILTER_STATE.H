#ifndef sdk_libultra_audio_save_3_H
#define sdk_libultra_audio_save_3_H
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"
struct EffectFilterState {
    ALFilter_s14 filter;
    s16 *base;
    s16 *input;
    u32 length;
    struct ALDelayAudioSetEffectParameter *delay;
    u8 section_count;
    void *paramHdl;
};
#endif
