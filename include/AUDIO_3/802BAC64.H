#ifndef AUDIO_3_802BAC64_H
#define AUDIO_3_802BAC64_H
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
struct ALGlobals_func_802B5B94_de {
    func_8022E694_S1 drvr;
};
#endif
