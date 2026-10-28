#ifndef COMMON_OBJECTSTATE90_H
#define COMMON_OBJECTSTATE90_H
struct ScreenRectangle;
#ifndef SPAN_1000_CODE_8022BA90_H
#define SPAN_1000_CODE_8022BA90_H
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/OBJRECV5.H"
extern void *func_8022C454_de(void *arg0);


extern float D_800C2D30_de;

struct Shared_ActorView;
extern int func_8022BEDC_de(struct Shared_ActorView *arg0);

struct Rules_func_8022C110_de;
typedef struct Rules_func_8022C110_de Rules_func_8022C110_de;



extern float D_800C2D34_de;





extern void *func_8022C55C_de(void *arg0, u32 arg1);

extern void func_8022C0D0_de(void *arg0);

extern void func_8022C2B4_de(void *arg0, struct ScreenRectangle *arg1);


struct Rules_func_8022C110_de;
struct Rules_func_8022C110_de {
    char pad0[0xD];
    unsigned char mode;
    char padE[0x1D - 0xE];
    unsigned char started;
};

struct func_8022BD84_S2;
typedef struct func_8022BD84_S2 func_8022BD84_S2;





struct FloatState67C;
struct FloatState67C {
    unsigned char padding_0[1656];
    f32 unk_678;
};

extern float D_800C2D5C_de;

extern int func_8022BAC0_de(void);

extern float D_800C2D28_de;




extern float D_800C2D38_de;





struct FloatState67C;
typedef struct FloatState67C FloatState67C;

struct func_8022BD84_S2;
struct func_8022BD84_S2 {
    char pad0[0x840];
    s32 unk840;
};

extern float D_800C2D3C_de;

struct PlayerRecAt1450V2;
typedef struct PlayerRecAt1450V2 PlayerRecAt1450V2;


struct PlayerRecAt1450V2;
struct PlayerRecAt1450V2 {
    char pad0[0x5D4];
    int character;
    ObjRecAt80 *info;
    char pad5DC[0x5EA - 0x5DC];
    short state;
    char pad5EC[0x133C - 0x5EC];
    int lives;
    char pad1340[0x13C8 - 0x1340];
    int timer;
    char pad13CC[0x1450 - 0x13CC];
    int isBot;
};


struct Player;
extern void func_8022BC14_de(struct Player *arg0);



extern void func_8022C110_de(PlayerRecAt1450V2 *player);



extern float D_800C2D2C_de;


extern void func_8022C67C_de(void * arg0);

typedef struct ObjRecAtB8 {
    int unk0;
    int unk4;
    int unk8;
    char padC[0x90 - 0xC];
    float unk90;
    float unk94;
    float unk98;
    int unk9C;
    float unkA0;
    int unkA4;
    int unkA8;
    float unkAC;
    float unkB0;
    int unkB4;
    int unkB8;
} ObjRecAtB8;

extern void Playerai_ApplyDamageOverTime(struct Shared_ActorView *player, void *source);

extern s32 func_8022C460_de(void *);

extern int D_80140FC0;

#endif
#endif
