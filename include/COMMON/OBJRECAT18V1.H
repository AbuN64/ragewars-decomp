#ifndef COMMON_OBJRECAT18V1_H
#define COMMON_OBJRECAT18V1_H
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"


struct SequenceTicksPerQuarterView;
typedef struct SequenceTicksPerQuarterView SequenceTicksPerQuarterView;


extern double g_sequenceTicksToSecondsUnsignedBias;

struct ALEndEvent;

struct ALTempoEvent;



struct ALEvent;




struct ALSeq_s;
typedef struct ALSeq_s ALSeq_s;


extern float g_sequenceQuarterNoteUnit;



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



extern s16 read16(ALSeq_s *sequenceObject);
extern s32 read32(ALSeq_s *sequenceObject);

#endif
