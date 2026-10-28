#ifndef COMMON_ACTIVE_H
#define COMMON_ACTIVE_H
#include "TYPES.H"
struct Active;
typedef struct Active Active;



struct RecordRecAt189;
struct RecordRecAt189 {
    char name[0x189];
    u8 profile[5];
    char pad18E[2];
};

extern void Random_StartCaptureTheFlagMatch();


extern void Random_StartTeamMatch();


struct Active;
struct Active {
    u8 recorded; /* +0x00: nonzero when finishing the level is recorded per save slot */
    char pad1[0x21 - 1];
    u8 score;
    u8 limit;
    u8 other;
    u8 time;
};

extern void Random_StartFragTagMatch();

extern void Random_StartIndividualMatch();



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
