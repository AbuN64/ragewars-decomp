#ifndef COMMON_VIEWFLAGS_H
#define COMMON_VIEWFLAGS_H
#include "TYPES.H"
#include "COMMON/STATERECAT10.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
/* The camera view fade timer, the word after the view flags D_80103220 (its own global: read with its own lui). */
extern f32 D_800FF224_de;
struct Triple;
struct ObjRecAt260;


struct Racer;
typedef struct Racer Racer;

struct Overlay;
typedef struct Overlay Overlay;

typedef StateRecAt10 AxisWave;

struct func_8023919C_S1;
typedef struct func_8023919C_S1 func_8023919C_S1;

extern float D_800C3090_de;

struct func_802393C8_S1;
typedef struct func_802393C8_S1 func_802393C8_S1;

struct func_80234DD0_S1;
typedef struct func_80234DD0_S1 func_80234DD0_S1;

struct ObjRecAtE4V1;
typedef struct ObjRecAtE4V1 ObjRecAtE4V1;

struct func_802390E4_S1;
struct func_802390E4_S1 {
    char pad0[0x14];
    s16 unk14;
    char pad14[0x18 - 0x14 - sizeof(s16)];
    s32 unk18;
    char pad18[0x1C - 0x18 - sizeof(s32)];
    s16 unk1C;
    char pad1C[0x20 - 0x1C - sizeof(s16)];
    s32 unk20;
};


struct ObjRecAt260;
typedef struct ObjRecAt260 ObjRecAt260;

extern float D_800C3530_de;

struct func_8023912C_S2;
typedef struct func_8023912C_S2 func_8023912C_S2;

struct Overlay;


struct ObjRecAtE4V1;

struct Effect33920;
typedef struct Effect33920 Effect33920;

struct Effect33920;
struct Effect33920 {
    s32 unk00;
    Effect33920 *next;
    CVector3 origin;
    f32 radius;
    AxisWave x;
    AxisWave y;
    AxisWave z;
};


struct ThreeChannels;
typedef struct ThreeChannels ThreeChannels;

extern float D_800C352C_de;

struct State44;
typedef struct State44 State44;

struct Race;
typedef struct Race Race;

struct func_80238F14_S1;
struct func_80238F14_S1 {
    char pad0[0x24];
    s32 unk24;
    char pad24[0x28 - 0x24 - sizeof(s32)];
    f32 unk28;
    char pad28[0x2C - 0x28 - sizeof(f32)];
    f32 unk2C;
    char pad2C[0x30 - 0x2C - sizeof(f32)];
    f32 unk30;
    char pad30[0x34 - 0x30 - sizeof(f32)];
    f32 unk34;
    char pad34[0x38 - 0x34 - sizeof(f32)];
    f32 unk38;
    char pad38[0x3C - 0x38 - sizeof(f32)];
    f32 unk3C;
    char pad3C[0x40 - 0x3C - sizeof(f32)];
    f32 unk40;
    char pad40[0x44 - 0x40 - sizeof(f32)];
    f32 unk44;
    char pad44[0x48 - 0x44 - sizeof(f32)];
    Shared_Quad unk48;
    char pad48[0x58 - 0x48 - sizeof(Shared_Quad)];
    s32 unk58;
    char pad58[0x5C - 0x58 - sizeof(s32)];
    f32 unk5C;
    char pad5C[0x60 - 0x5C - sizeof(f32)];
    f32 unk60;
    char pad60[0x64 - 0x60 - sizeof(f32)];
    s32 unk64;
};

struct UnitVp;
struct UnitVp {
    s16 vscale[4];
    s16 vtrans[4];
};

struct func_802392DC_S1;
typedef struct func_802392DC_S1 func_802392DC_S1;

struct func_802390E4_S1;
typedef struct func_802390E4_S1 func_802390E4_S1;

struct World_func_80236F1C_de;
typedef struct World_func_80236F1C_de World_func_80236F1C_de;

struct func_80234DD0_S2;
struct func_80234DD0_S2 {
    char pad0[0x264];
    f32 unk264;
    char pad264[0x268 - 0x264 - sizeof(f32)];
    f32 unk268;
};

struct func_80239184_S1;
typedef struct func_80239184_S1 func_80239184_S1;

struct UnitVp;
typedef struct UnitVp UnitVp;

struct Racer;
struct Racer {
    char pad0[4];
    struct Racer *next;
    char pad8[4];
    f32 screenScaleX; /* 0xC */
    f32 screenScaleY; /* 0x10 */
    char pad14[0x50];
    s32 visibilityFlags; /* 0x64 */
    u16 perspectiveNorm; /* 0x68 */
    char pad6A[0xA6];
    f32 viewportScaleX; /* 0x110 */
    f32 viewportScaleY; /* 0x114 */
    char pad118[8];
    s32 effect;
    u16 pad124;
    u16 effectArg;
    char pad128[0x174];
    f32 viewportWidth; /* 0x29C */
    f32 viewportHeight;
    f32 viewportX;
    f32 viewportY;
    char pad2AC[4];
    UnitVp viewports[2];
    char pad2D0[0x80];
    CVector3 clipBounds[2]; /* 0x350 */
    CVector3 volumeBounds[2]; /* 0x368 */
    u32 projectionMatrices[2][16]; /* 0x380 */
    u32 lights[2][8]; /* 0x400 */
    char pad440[0xE0];
    u8 hit;
    u8 boost;
    u8 spin;
    char pad523[0x19];
    s32 fogNear; /* 0x53C: word storage; fog command uses its low 16 bits. */
    char pad540[8];
    s8 mode548; /* 0x548 */
    s8 mode549; /* 0x549 */
    char pad54A[0xA];
    char sound[0x40];
    char pad594[0xE40 - 0x594];
    IntrusiveList activeMessages; /* 0xE40 */
};

struct World_func_80236F1C_de;
struct World_func_80236F1C_de {
    char pad0[0x12A5];
    u8 replay;
};

struct Race;
struct Racer;
typedef struct RaceHeader {
    s32 music;
    char pad4[0x1C];
    IntrusiveList views;
    u32 lastMode;
    s32 layoutTimer;
    char pad3C[4];
} RaceHeader;
struct Race {
    RaceHeader header;
    Racer self;
    char padRaceTail[0xF24 - 0x40 - sizeof(Racer)];
    IntrusiveList freeMessages; /* 0xF24 */
};




extern float D_800C3098_de;

extern float D_800C8610;

struct func_8023912C_S2;
struct func_8023912C_S2 {
    char pad0[0x88];
    f32 unk88;
    char pad88[0x8C - 0x88 - sizeof(f32)];
    f32 unk8C;
    char pad8C[0x90 - 0x8C - sizeof(f32)];
    s32 unk90;
    char pad90[0x94 - 0x90 - sizeof(s32)];
    s32 unk94;
    char pad94[0x98 - 0x94 - sizeof(s32)];
    f32 unk98;
    char pad98[0x9C - 0x98 - sizeof(f32)];
    f32 unk9C;
};


struct func_80238F14_S1;
typedef struct func_80238F14_S1 func_80238F14_S1;

struct State44;

struct func_80239184_S1;
struct func_80239184_S1 {
    char pad0[0x548];
    signed char unk548;
    char pad548[0x549 - 0x548 - sizeof(signed char)];
    signed char unk549;
};

struct func_80234DD0_S2;
typedef struct func_80234DD0_S2 func_80234DD0_S2;


extern float D_800C3094_de;

extern float D_800C309C_de;

struct func_80234DD0_S1;
struct func_80234DD0_S1 {
    char pad0[0x70];
    f32 unk70;
    char pad70[0x74 - 0x70 - sizeof(f32)];
    f32 unk74;
    char pad74[0x78 - 0x74 - sizeof(f32)];
    f32 unk78;
    char pad78[0x7C - 0x78 - sizeof(f32)];
    s32 unk7C;
    char pad7C[0x260 - 0x7C - sizeof(s32)];
    func_80234DD0_S1_U260 unk260;
    char pad260[0x368 - 0x260 - sizeof(func_80234DD0_S1_U260)];
    f32 unk368;
    char pad368[0x36C - 0x368 - sizeof(f32)];
    f32 unk36C;
    char pad36C[0x370 - 0x36C - sizeof(f32)];
    f32 unk370;
    char pad370[0x374 - 0x370 - sizeof(f32)];
    f32 unk374;
    char pad374[0x378 - 0x374 - sizeof(f32)];
    f32 unk378;
    char pad378[0x37C - 0x378 - sizeof(f32)];
    f32 unk37C;
    char pad37C[0x528 - 0x37C - sizeof(f32)];
    f32 unk528;
    char pad528[0x530 - 0x528 - sizeof(f32)];
    f32 unk530;
};

struct ThreeChannels;

struct GameplayCamera;


struct func_8023919C_S1;
struct func_8023919C_S1 {
    char pad0[0x538];
    s32 unk538;
    char pad538[0x544 - 0x538 - sizeof(s32)];
    s32 unk544;
    char pad544[0x54A - 0x544 - sizeof(s32)];
    s8 unk54A;
    char pad54A[0x54B - 0x54A - sizeof(s8)];
    s8 unk54B;
    char pad54B[0x54C - 0x54B - sizeof(s8)];
    s8 unk54C;
    char pad54C[0x54D - 0x54C - sizeof(s8)];
    s8 unk54D;
    char pad54D[0x54E - 0x54D - sizeof(s8)];
    s8 unk54E;
    char pad54E[0x54F - 0x54E - sizeof(s8)];
    s8 unk54F;
    char pad54F[0x550 - 0x54F - sizeof(s8)];
    s8 unk550;
    char pad550[0x551 - 0x550 - sizeof(s8)];
    s8 unk551;
};

struct func_802392DC_S1;
struct func_802392DC_S1 {
    char pad0[0x5DC];
    int unk5DC;
    char pad5DC[0x16E0 - 0x5DC - sizeof(int)];
    void * unk16E0;
};

extern float D_800C3528_de;

struct func_802393C8_S1;
struct func_802393C8_S1 {
    char pad0[0xFC];
    int unkFC;
    char padFC[0x100 - 0xFC - sizeof(int)];
    int unk100;
    char pad100[0x104 - 0x100 - sizeof(int)];
    int unk104;
    char pad104[0x108 - 0x104 - sizeof(int)];
    int unk108;
    char pad108[0x10C - 0x108 - sizeof(int)];
    int unk10C;
    char pad10C[0x110 - 0x10C - sizeof(int)];
    float unk110;
    char pad110[0x114 - 0x110 - sizeof(float)];
    float unk114;
    char pad114[0x118 - 0x114 - sizeof(float)];
    int unk118;
};

extern float D_800C3524_de;

extern void func_802391AC_de(void *view, s32 red, s32 green, s32 blue, s32 mode, s32 alpha, s32 duration, s32 delay);


typedef char AxisWave_size_check[(sizeof(AxisWave) == 0x14) ? 1 : -1];
typedef char Effect33920_size_check[(sizeof(Effect33920) == 0x54) ? 1 : -1];
typedef char Racer_size_check[(sizeof(Racer) == 0xE54) ? 1 : -1];
typedef char Race_size_check[(sizeof(Race) == 0xF38) ? 1 : -1];
extern f32 D_800D05D0;

extern Box D_800FF208;

extern s32 func_80245784_de(void);
#endif
