#ifndef MENU_PICKUP_APPLYPOWERUP_H
#define MENU_PICKUP_APPLYPOWERUP_H
#include "TYPES.H"
/* Timed pickup family: common effect payload followed by a word amount. */
typedef struct TimedItemEffect {
    void *resource;
    s16 id;
    s16 sound;
    s16 callback;
    s16 reservedA;
    s32 amount;
} TimedItemEffect;
#endif
