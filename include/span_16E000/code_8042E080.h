#ifndef UNBAKE_SPAN_16E000_CODE_8042E080_H
#define UNBAKE_SPAN_16E000_CODE_8042E080_H
#include "TYPES.H"
struct Active;
typedef struct Active Active;

struct TrialSettings;
struct TrialSettings {
    char pad0[0xD];
    u8 trialKind;
    char padE[0x16];
    s8 time;
    s8 limit;
    s8 other;
    s8 score;
};

struct MatchState;
struct MatchState {
    char pad0[0x1C];
    int armed;
    int active;
    char pad24[0x30];
    s32 first;
    char pad58[0x20];
    s32 second;
    char pad7C[0x14];
    s32 kills;
    char pad94[4];
    s32 deaths;
};
typedef struct MatchState MatchState;

struct RecordRecAt189;
struct RecordRecAt189 {
    char name[0x189];
    u8 profile[5];
    char pad18E[2];
};

extern void func_8042EBA4_de();

extern void func_8042E5EC_de();

extern void func_8042EC38_de();

struct TrialSettings;
typedef struct TrialSettings TrialSettings;

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
