#ifndef RENDER_RECORD_OUTPUT_AND_TIMED_SESSION_VIEWS_H
#define RENDER_RECORD_OUTPUT_AND_TIMED_SESSION_VIEWS_H
#include "TYPES.H"
struct RecordOutputFieldsView {
    char pad0[0x8];
    float thirdScalar;
    char pad8[0xC - 0x8 - sizeof(float)];
    float fourthScalar;
    char padC[0x10 - 0xC - sizeof(float)];
    float secondScalar;
    char pad10[0x20 - 0x10 - sizeof(float)];
    int outputWord;
};
typedef struct TimedSessionTransitionView {
    char pad0[0x26DB0];
    f32 transitionTimer;
    char pad26DB4[0x26DBC - 0x26DB4];
    s32 transitionTarget;
    char pad26DC0[1];
    s8 transitionPhase;
} TimedSessionTransitionView;
#endif
