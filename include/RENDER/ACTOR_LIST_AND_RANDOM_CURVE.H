#ifndef RENDER_ACTOR_LIST_AND_RANDOM_CURVE_H
#define RENDER_ACTOR_LIST_AND_RANDOM_CURVE_H
#include "TYPES.H"
struct ActorList {
    s32 pad0;
    struct ActorRecAt5E0 *actors;
    s32 count;
};
/* Type 1 curves choose a new random value each period. */
typedef struct RandomCurve {
    s32 type;
    f32 period;
    u8 minimum;
    u8 maximum;
} RandomCurve;
#endif
