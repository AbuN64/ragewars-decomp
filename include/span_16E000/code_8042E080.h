#ifndef UNBAKE_SPAN_16E000_CODE_8042E080_H
#define UNBAKE_SPAN_16E000_CODE_8042E080_H
#include "types.h"
struct Active;
typedef struct Active Active;

struct Settings_func_8042EB10_de;
struct Settings_func_8042EB10_de {
    char pad0[0xD];
    u8 trialKind;
    char padE[0x16];
    s8 time;
    s8 limit;
    s8 other;
    s8 score;
};

struct Match_func_8042DEA0_de;
struct Match_func_8042DEA0_de {
    char pad0[0x90];
    s32 kills;
    char pad94[4];
    s32 deaths;
};

struct RecordRecAt189;
struct RecordRecAt189 {
    char name[0x189];
    u8 profile[5];
    char pad18E[2];
};

extern void func_8042EBA4_de();

extern void func_8042E5EC_de();

extern void func_8042EC38_de();

struct Settings_func_8042EB10_de;
typedef struct Settings_func_8042EB10_de Settings_func_8042EB10_de;

struct Active;
struct Active {
    char pad0[0x21];
    u8 score;
    u8 limit;
    u8 other;
    u8 time;
};

extern void func_8042EB10_de();

extern void func_8042ECD8_de();

extern void func_8042E1F0_de();

extern s32 func_8042EE94_de();

struct StatusRecAt95;
struct StatusRecAt95 {
    char pad0[0x78];
    u8 joined;
    u8 unk79;
    u8 unk7A;
    u8 unk7B;
    char pad7C;
    u8 unk7D;
    char pad7E[2];
    s8 kind;
    char pad81;
    u8 unk82;
    char pad83;
    char name[0x91 - 0x84];
    u8 computer;
    u8 team;
    char pad93;
    u8 lives;
    u8 score;
};

#endif
