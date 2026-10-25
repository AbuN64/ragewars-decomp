#ifndef COMMON_ALDELAY28_H
#define COMMON_ALDELAY28_H
#include "COMMON/AUDIO_CALLBACKS.H"
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
extern float D_800C788C_de;

struct ALDelay28;
typedef struct ALDelay28 ALDelay28;

struct CallbackStateC;



struct ALResampler_s28;
struct ALResampler_s28 {
    ALFilter_s14 filter;
    void *state;
    f32 ratio;
    s32 upitch;
    f32 delta;
    s32 first;
};

struct ALFilter_s14_2;
typedef struct ALFilter_s14_2 ALFilter_s14_2;

struct ALFilter_s14_2;
struct ALFilter_s14_2 {
    struct ALFilter_s14_2 *source;
    ALCmdHandler handler;
    void *setParam;
    s16 inp;
    s16 outp;
    s32 type;
};

struct ALResampler_s;
struct ALResampler_s {
    ALFilter_s14_2 filter;
    void *state;
    f32 ratio;
    s32 upitch;
    f32 delta;
    s32 first;
    void *ctrlList;
    void *ctrlTail;
    s32 motion;
};



struct ALResampler_s28;
typedef struct ALResampler_s28 ALResampler_s28;

struct ALDelay28;
struct ALDelay28 {
    u32 input;
    u32 output;
    s16 ffcoef;
    s16 fbcoef;
    s16 gain;
    f32 rsinc;
    f32 rsval;
    s32 rsdelta;
    f32 rsgain;
    void *lp;
    ALResampler_s28 *rs;
};


struct ALResampler_s;
typedef struct ALResampler_s ALResampler_s;

struct IntegerState34;
typedef struct IntegerState34 IntegerState34;

struct ALFx;
typedef struct ALFx ALFx;





extern float D_800C7748_de;

extern float D_800C7880_de;


extern float D_800C7888_de;

extern float D_800C7884_de;

struct IntegerState34;


struct CallbackStateC;
typedef struct CallbackStateC CallbackStateC;

struct ALFx;
struct ALFx {
    ALFilter_s14 filter;
    s16 *base;
    s16 *input;
    u32 length;
    ALDelay28 *delay;
    u8 section_count;
    void *paramHdl;
};

extern float D_800C7740_de;

typedef struct ALFilter_u1 {
    struct ALFilter_u1 *source;
    ALCmdHandler handler;
    void *setParam;
    s16 inp;
    s16 outp;
    s32 type;
} ALFilter_u1;
extern char D_800C8DB0_eu_x[];
extern char D_800C8DB4_eu_x[];
#endif
