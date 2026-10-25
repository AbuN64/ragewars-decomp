#ifndef sdk_libultra_audio_save_3_H
#define sdk_libultra_audio_save_3_H
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"
struct ALFxCode802BAC64 {
    ALFilter_s14 filter;
    s16 *base;
    s16 *input;
    u32 length;
    struct ALDelay_func_802B5B94_de *delay;
    u8 section_count;
    void *paramHdl;
};
#endif
