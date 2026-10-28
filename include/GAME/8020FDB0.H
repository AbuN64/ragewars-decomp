#ifndef GAME_2_8020FDB0_H
#define GAME_2_8020FDB0_H
#include "TYPES.H"
#include "COMMON/S2.H"
struct BrainCode8020EAE0 {
    SharedPlayer *player;
    char pad4[0x2E0];
    s32 switchTimer;
};
#endif
