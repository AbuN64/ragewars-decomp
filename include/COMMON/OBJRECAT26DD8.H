#ifndef COMMON_OBJRECAT26DD8_H
#define COMMON_OBJRECAT26DD8_H
#include "TYPES.H"
/* Independent simulation-time scale, adjacent to the current time step. */
extern f32 g_roundTimerStep;
#include "COMMON/ITEMRECAT20V1.H"

struct Entry80294AC4;
struct RoundSessionItemStateView;
typedef struct RoundSessionItemStateView RoundSessionItemStateView;

struct Entry80294AC4 {
    void (*callback)(void *sessionContext);
    s32 field4;
    s32 field8;
};

struct Entry80294AC4;
typedef struct Entry80294AC4 Entry80294AC4;



struct SequencePromptStateView;
typedef struct SequencePromptStateView SequencePromptStateView;


struct Prompt;
typedef struct Prompt Prompt;

struct Prompt;

struct SequencePromptStateView;





extern float g_creditsInitialLineTimer;












extern float g_creditsLineTimer;







#endif
