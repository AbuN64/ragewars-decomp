#ifndef RW_GAMEPLAY_CAMERA_H
#define RW_GAMEPLAY_CAMERA_H
#include "types.h"
#include "span_1000/code_80233920.h"
#include "common/types_06e4f7ef1f9e.h"
#include "span_16E000/code_8043F69C.h"
/* Complete camera records and callback ABI from origin/legacy func_80234FDC.c. */
typedef struct Shared_func_80234FDC_S5 Shared_func_80234FDC_S5;
struct Shared_func_80234FDC_S5 {
    s32 unk0; /* +0x0: src/func_80234FDC.c */
};
typedef char Shared_func_80234FDC_S5_size_check[(sizeof(Shared_func_80234FDC_S5) == 0x4) ? 1 : -1];


typedef struct Lights Lights;
struct Lights {
    s8 unk0; /* +0x0: src/func_80234FDC.c */
    s8 unk1; /* +0x1: src/func_80234FDC.c */
    s8 unk2; /* +0x2: src/func_80234FDC.c */
    s8 unk3; /* +0x3: src/func_80234FDC.c */
    s8 unk4; /* +0x4: src/func_80234FDC.c */
    s8 unk5; /* +0x5: src/func_80234FDC.c */
    s8 unk6; /* +0x6: src/func_80234FDC.c */
    s8 unk7; /* +0x7: src/func_80234FDC.c */
    s8 unk8; /* +0x8: src/func_80234FDC.c */
    s8 unk9; /* +0x9: src/func_80234FDC.c */
    s8 unkA; /* +0xA: src/func_80234FDC.c */
    char padB[0x5];
    s8 unk10; /* +0x10: src/func_80234FDC.c */
    u8 unk11; /* +0x11: src/func_80234FDC.c */
    s8 unk12; /* +0x12: src/func_80234FDC.c */
    s8 unk13; /* +0x13: src/func_80234FDC.c */
    s8 unk14; /* +0x14: src/func_80234FDC.c */
    u8 unk15; /* +0x15: src/func_80234FDC.c */
    s8 unk16; /* +0x16: src/func_80234FDC.c */
    s8 unk17; /* +0x17: src/func_80234FDC.c */
    s8 unk18; /* +0x18: src/func_80234FDC.c */
    s8 unk19; /* +0x19: src/func_80234FDC.c */
    s8 unk1A; /* +0x1A: src/func_80234FDC.c */
    char pad1B[0x5];
};
typedef char Shared_func_80234FDC_S6_size_check[(sizeof(Lights) == 0x20) ? 1 : -1];


typedef struct Shared_func_80234FDC_S1 Shared_func_80234FDC_S1;
struct Shared_func_80234FDC_S1 {
    char pad0[0x5DC];
    s32 unk5DC; /* +0x5DC: src/func_80234FDC.c */
    char pad5E0[0x84];
    s32 unk664; /* +0x664: src/func_80234FDC.c */
    char pad668[0x60];
    f32 unk6C8; /* +0x6C8: src/func_80234FDC.c */
    char pad6CC[0x1014];
    void * unk16E0; /* +0x16E0: src/func_80234FDC.c */
};
typedef char Shared_func_80234FDC_S1_size_check[(sizeof(Shared_func_80234FDC_S1) == 0x16E4) ? 1 : -1];


typedef struct GameplayCamera GameplayCamera;
struct GameplayCamera {
    char pad0[4];
    GameplayCamera *next; /* 0x04: camera list link */
    char pad8[0xC];
    s16 unk14; /* +0x14: src/func_80234FDC.c */
    char pad16[0x2];
    f32 unk18; /* +0x18: src/func_80234FDC.c */
    s16 state; /* 0x1C */
    u8 pad1E[2];
    s32 stateCounter; /* 0x20 */
    s32 unk24; /* +0x24: src/func_80234FDC.c */
    f32 unk28;
    f32 unk2C;
    f32 unk30;
    f32 unk34;
    f32 unk38; /* +0x38: src/func_80234FDC.c */
    f32 unk3C; /* +0x3C: src/func_80234FDC.c */
    f32 unk40; /* +0x40: src/func_80234FDC.c */
    f32 unk44; /* +0x44: src/func_80234FDC.c */
    Shared_Quad unk48;
    struct Shared_func_80234FDC_S8 *unk58; /* +0x58: src/func_80234FDC.c */
    f32 unk5C; /* +0x5C: src/func_80234FDC.c */
    f32 unk60; /* +0x60: src/func_80234FDC.c */
    s32 unk64; /* +0x64: src/func_80234FDC.c */
    u16 unk68; /* +0x68: src/func_80234FDC.c */
    char pad6A[0x2];
    f32 unk6C; /* +0x6C: src/func_80234FDC.c */
    f32 unk70; /* +0x70: src/func_80234FDC.c */
    f32 unk74; /* +0x74: src/func_80234FDC.c */
    f32 unk78; /* +0x78: src/func_80234FDC.c */
    s32 unk7C; /* +0x7C: src/func_80234FDC.c */
    f32 unk80; /* +0x80: src/func_80234FDC.c */
    f32 unk84; /* +0x84: src/func_80234FDC.c */
    f32 unk88; /* +0x88: src/func_80234FDC.c */
    f32 unk8C; /* +0x8C: src/func_80234FDC.c */
    f32 unk90; /* +0x90: src/func_80234FDC.c */
    f32 unk94; /* +0x94: src/func_80234FDC.c */
    f32 unk98; /* +0x98: src/func_80234FDC.c */
    f32 unk9C; /* +0x9C: src/func_80234FDC.c */
    char padA0[0x18];
    char unkB8[20]; /* +0xB8: src/func_80234FDC.c */
    char unkCC[20]; /* +0xCC: src/func_80234FDC.c */
    char unkE0[20]; /* 0xE0: third StateRecAt10 */
    f32 shakeHorizontal; /* 0xF4 */
    f32 shakeVertical; /* 0xF8 */
    char padFC[0x28];
    u16 unk124; /* +0x124: src/func_80234FDC.c */
    char pad126[0x2];
    Vec3 position; /* +0x128: camera position */
    char pad134[0x4];
    f32 unk138; /* +0x138: src/func_80234FDC.c */
    char pad13C[4];
    Vector4f orientation;
    f32 unk150; /* +0x150: src/func_80234FDC.c */
    char pad154[0xC];
    s8 unk160; /* +0x160: src/func_80234FDC.c */
    char pad161[0x3F];
    f32 unk1A0; /* +0x1A0: src/func_80234FDC.c */
    char pad1A4[0x3C];
    s8 unk1E0; /* +0x1E0: src/func_80234FDC.c */
    char pad1E1[0x3F];
    f32 unk220; /* +0x220: src/func_80234FDC.c */
    char pad224[0x3C];
    Vec3 corners[5];
    f32 unk29C; /* +0x29C: src/func_80234FDC.c */
    f32 unk2A0; /* +0x2A0: src/func_80234FDC.c */
    f32 unk2A4;
    f32 unk2A8;
    char pad2AC[0x44];
    Vector4f clipPlanes[6];
    Vec3 clipBounds[2];
    Vec3 volumeBounds[2];
    char unk380[2][64]; /* +0x380: double-buffered projection matrices */
    Lights lights[2]; /* +0x400: double-buffered lights */
    u16 unk440; /* +0x440: src/func_80234FDC.c */
    char pad442[0x6];
    char unk448[3][64]; /* +0x448: src/func_80234FDC.c */
    char pad508[0x20];
    f32 unk528; /* +0x528: src/func_80234FDC.c */
    f32 unk52C;
    f32 unk530;
    u8 pad534[4];
    s32 fadeCounter; /* 0x538 */
    u8 pad53C[8];
    s32 fadeEnabled; /* 0x544 */
    u8 pad548[2];
    s8 fadeMode; /* 0x54A */
    s8 fadeRed, fadeGreen, fadeBlue;
    s8 fadeStart, fadeEnd, fadeStep, fadeState;
    u8 pad552[2];
    MessageList messageList; /* 0x554 */
    u8 pad56C[4];
    s8 unk570; /* +0x570: src/func_80234FDC.c */
    char pad571[0xE40 - 0x571];
    IntrusiveList objects;
    f32 unkE54; /* +0xE54: src/func_80234FDC.c */
    char padE58[0x3C];
    s8 unkE94; /* +0xE94: src/func_80234FDC.c */
    char padE95[0x3];
};
typedef char Shared_func_80234FDC_S2_size_check[(sizeof(GameplayCamera) == 0xE98) ? 1 : -1];


typedef struct Shared_func_80234FDC_S3 Shared_func_80234FDC_S3;
struct Shared_func_80234FDC_S3 {
    char pad0[0x400];
    Lights unk400[2]; /* +0x400: src/func_80234FDC.c */
};
typedef char Shared_func_80234FDC_S3_size_check[(sizeof(Shared_func_80234FDC_S3) == 0x440) ? 1 : -1];


typedef struct Shared_func_80234FDC_S4 Shared_func_80234FDC_S4;
struct Shared_func_80234FDC_S4 {
    s32 unk0; /* +0x0: src/func_80234FDC.c */
    s32 unk4; /* +0x4: src/func_80234FDC.c */
    s32 unk8; /* +0x8: src/func_80234FDC.c */
    char padC[4];
    Racer view; /* +0x10: D_80141008, the render view embedded in D_80140FF8 */
    char padView[0x122F - 0x10 - sizeof(Racer)];
    u8 unk122F; /* +0x122F: src/func_80234FDC.c */
    char pad1230[0x590];
    Shared_func_80234FDC_S5 state; /* +0x17C0: src/func_80234FDC.c */
};
typedef char Shared_func_80234FDC_S4_size_check[(sizeof(Shared_func_80234FDC_S4) == 0x17C4) ? 1 : -1];


typedef struct Shared_func_80234FDC_S7 Shared_func_80234FDC_S7;
struct Shared_func_80234FDC_S7 {
    s32 unk0; /* +0x0: src/func_80234FDC.c */
    s32 unk4; /* +0x4: src/func_80234FDC.c */
};
typedef char Shared_func_80234FDC_S7_size_check[(sizeof(Shared_func_80234FDC_S7) == 0x8) ? 1 : -1];


typedef struct Shared_func_80234FDC_S8 Shared_func_80234FDC_S8;
struct Shared_func_80234FDC_S8 {
    char pad0[0x1C];
    s32 unk1C; /* +0x1C: src/func_80234FDC.c */
};
typedef char Shared_func_80234FDC_S8_size_check[(sizeof(Shared_func_80234FDC_S8) == 0x20) ? 1 : -1];


typedef struct Shared_Func_80234FDC_Callback Shared_Func_80234FDC_Callback;
struct Shared_Func_80234FDC_Callback {
    s32 (*fn)(s8 *); /* +0x0: src/func_80234FDC.c */
    s32 pad; /* +0x4: src/func_80234FDC.c */
};
typedef char Shared_Func_80234FDC_Callback_size_check[(sizeof(Shared_Func_80234FDC_Callback) == 0x8) ? 1 : -1];


/* The list header and complete primary camera, followed by the effect pools. */
typedef struct RaceViewportState {
    RaceHeader header;
    GameplayCamera self;
    char padAfterCamera[0x11D8 - sizeof(RaceHeader) - sizeof(GameplayCamera)];
    IntrusiveList freeEffects;
    IntrusiveList activeEffects;
} RaceViewportState;
typedef char RaceHeader_size_check[(sizeof(RaceHeader) == 0x40) ? 1 : -1];
typedef char RaceViewportState_size_check[(sizeof(RaceViewportState) == 0x1200) ? 1 : -1];
#endif
