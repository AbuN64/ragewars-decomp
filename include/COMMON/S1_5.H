#ifndef COMMON_S1_5_H
#define COMMON_S1_5_H
#include "TYPES.H"
#include "COMMON/LEVEL_ACTOR.H"



extern void func_80422170_de();


extern void func_804221E8_de();

struct Screen_func_80422960_de;
struct Screen_func_80422960_de {
    char pad0[0x1C];
    s32 choice;
    char pad20[0x60 - 0x20];
    s32 mode;
    s32 arena;
};

struct LevelActor;
#endif
