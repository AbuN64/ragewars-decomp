#ifndef COMMON_STREAM_H
#define COMMON_STREAM_H
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"

struct Output8025EF54;
typedef struct Output8025EF54 Output8025EF54;

struct Output8025EF54;

extern void Polytrak2_DecodeScalarSamples(u32 *stream, Output8025EF54 *out, s32 count);



struct Stream;
typedef struct Stream Stream;

struct Segment8025FFD0;
typedef struct Segment8025FFD0 Segment8025FFD0;



extern float D_800C9208;

extern float D_800C4168_de;




struct Segment8025FFD0;

struct Stream;
struct Stream {
    s32 unk0;
    char pad4[8];
    s32 unkC;
    float coeff[4];
    u32 unk20;
    u32 unk24;
    s32 unk28;
};

struct Decode8025EF54;

struct Curve;
typedef struct Curve Curve;


extern double D_800C40F8_de;

extern float D_800C9200;

extern double D_800C4100_de;



struct Decode8025EF54;
typedef struct Decode8025EF54 Decode8025EF54;

struct Poly;

struct Poly;
typedef struct Poly Poly;

struct Curve;



/* Frame counts of the loaded motion, read by the stream decoder. */
extern s32 D_8010AC84;
extern s32 D_8010AC88;
#endif
