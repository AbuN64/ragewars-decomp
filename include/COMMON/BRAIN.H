#ifndef COMMON_BRAIN_H
#define COMMON_BRAIN_H
#include "TYPES.H"

struct SharedPlayer;
struct Actor;
struct Behaviour;

/* Computer-player state shared by the frame, pursuit and close-attack updates. */
typedef struct Brain {
    struct SharedPlayer *player;
    s32 start; /* 0x4 */
    s32 route; /* 0x8 */
    s32 destination; /* 0xC */
    s32 node; /* 0x10 */
    s32 w14;
    char pad18[0x64 - 0x18];
    struct Actor *target; /* 0x64 */
    char pad68[0x1F0 - 0x68];
    f32 clearance[8];
    char pad210[8];
    struct Behaviour *behaviour; /* 0x218 */
    char pad21C[0x230 - 0x21C];
    s32 combat;
    char pad234[8];
    s32 w23C;
    s32 w240;
    char pad244[0x2D8 - 0x244];
    s32 timer;
    s32 pattern;
    s32 distance;
    char pad2E4[0x318 - 0x2E4];
    s32 frames;
    s32 visible;
    s32 fireTimer;
    s32 cooldown; /* 0x324 */
} Brain;
#endif
