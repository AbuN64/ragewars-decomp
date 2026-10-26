#ifndef COMMON_SELF_H
#define COMMON_SELF_H
#include "TYPES.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/OBJECTLINKS14.H"
extern float D_800C1FD8_de;



struct Self;
struct Brain_func_802120A8_eu;
struct Self {
    char pad0[8];
    CVector3 pos;
    char pad14[0x24];
    s32 flags;
    char pad3C[0x30];
    f32 yaw;
    char pad70[0x168];
    struct Self *self;
    char pad1DC[0x3F8];
    s32 slot;
    char pad5D8[0xCC];
    f32 strafe;
    char pad6A8[0xDAC];
    struct Brain_func_802120A8_eu *brain;
};

struct Brain_func_802120A8_eu {
    struct Self *player;
    s32 route;
    char pad8[8];
    s32 node;
    s32 routeNodes[4]; /* 0x14 */
    char pad24[0x40];
    struct Self *target;
    struct Player *routeObject; /* 0x68 */
    char pad6C[0x50];
    s32 routeState; /* 0xBC */
    char padC0[0x130];
    f32 clearance[8]; /* 0x1F0 */
    char pad210[0x20];
    s32 combat;
    char pad234[0xA4];
    s32 timer;
    s32 pattern;
    char pad2E0[0x38];
    s32 frames;
    s32 visible;
};


struct CloseAttackActor;


struct CloseAttackBrain;
typedef struct CloseAttackBrain CloseAttackBrain;


extern float D_800C1FE8_de;

struct CloseAttackActor;
typedef struct CloseAttackActor CloseAttackActor;

struct CloseAttackActor;
struct CloseAttackBrain;
struct CloseAttackActor {
    char pad0[8];
    CVector3 pos;
    char pad14[0x24];
    s32 flags;
    char pad3C[0x30];
    f32 yaw;
    char pad70[0x168];
    struct CloseAttackActor *self;
    char pad1DC[0x3F8];
    s32 slot;
    char pad5D8[0xCC];
    f32 strafe;
    f32 forward;
    s32 w6AC;
    s32 buttons;
    char pad6B4[0xDA0];
    struct CloseAttackBrain *brain;
};

struct CloseAttackBrain {
    CloseAttackActor *player;
    s32 route;
    s32 w8;
    s32 destination;
    s32 node;
    s32 routeNodes[4]; /* 0x14 */
    char pad24[0x40];
    CloseAttackActor *target;
    struct Player *routeObject; /* 0x68 */
    char pad6C[0x50];
    s32 routeState; /* 0xBC */
    char padC0[0x130];
    f32 clearance[8]; /* 0x1F0 */
    char pad210[0x10];
    s32 state; /* 0x220 */
    char pad224[0xC];
    s32 combat;
    char pad234[0xA4];
    s32 timer;
    s32 pattern;
    s32 distance;
    char pad2E4[0x18];
    s32 reset2FC; /* 0x2FC: reset after route initialization */
    char pad300[0x18];
    s32 frames;
    s32 visible;
    s32 fireTimer;
};


struct Brain_func_802120A8_eu;
typedef struct Brain_func_802120A8_eu Brain_func_802120A8_eu;




struct PlayerRecAt288;
struct PlayerRecAt288 {
    s32 active;
    char pad4[0x1CC - 4];
    s32 timer;
    f32 first[8];
    f32 second[8];
    f32 level;
    char pad214[0x288 - 0x214];
    s32 ready;
};

struct SweepHit;
struct SweepHit {
    char pad0[0xE4];
    CVector3 pos;
    char padF0[0xC];
    s32 kind;
};


struct PlayerRecAt1CC;
struct PlayerRecAt1CC {
    void *clip;
    char pad4[0x1C8];
    int frame;
};

struct PlayerRecAt1CC;
typedef struct PlayerRecAt1CC PlayerRecAt1CC;



extern float D_800C1FF0_de;


extern float D_800C1FDC_de;

extern float D_800C1FE4_de;


struct Shared_Actor;







struct SweepHit;
typedef struct SweepHit SweepHit;




extern float D_800C1FEC_de;


struct Self;
typedef struct Self Self;


extern float D_800C1FE0_de;

struct LevelActor;







extern float D_800C70F4;

extern float D_800C70F0;






extern s32 Nav_NextRandom(void);

extern s32 Nav_CollectIncidentLinks(EntryList8020CCE8 *, s32, s32 *, s32 *);
#endif
