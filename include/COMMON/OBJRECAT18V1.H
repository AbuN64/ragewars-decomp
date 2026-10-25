#ifndef COMMON_OBJRECAT18V1_H
#define COMMON_OBJRECAT18V1_H
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"

struct MidiState802B70B8;
struct MidiState802B70B8 {
    s32 start;
    s32 track_start;
    s32 current;
    s32 unkC;
    s32 end;
    f32 tick_scale;
    s16 division;
    s16 unk1A;
};


struct ObjRecAt18V1;
typedef struct ObjRecAt18V1 ObjRecAt18V1;


extern double D_800C74E8_de;

struct ALEndEvent;

struct ALTempoEvent;



struct ALEvent;




struct ALSeq_s;
typedef struct ALSeq_s ALSeq_s;

struct MidiState802B70B8;
typedef struct MidiState802B70B8 MidiState802B70B8;

extern float D_800C74E0_de;



struct ALSeqMarker;
struct ALSeqMarker {
    u8 *curPtr;
    s32 lastTicks;
    s32 curTicks;
    s16 lastStatus;
};


struct ALSeq_s;
struct ALSeq_s {
    u8 *base;
    u8 *trackStart;
    u8 *curPtr;
    s32 lastTicks;
    s32 len;
    f32 qnpt;
    s16 division;
    s16 lastStatus;
};

struct ALSeqMarker;
typedef struct ALSeqMarker ALSeqMarker;



#endif
