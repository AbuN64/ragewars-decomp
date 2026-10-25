#ifndef COMMON_OBJECTSTATE90_H
#define COMMON_OBJECTSTATE90_H
struct ScreenRectangle;
#ifndef SPAN_1000_CODE_8022BA90_H
#define SPAN_1000_CODE_8022BA90_H
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/OBJRECV5.H"
extern void *func_8022C454_de(void *arg0);

struct func_8022C54C_S3;
struct func_8022C54C_S3 {
    char pad0[0x90];
    u8 unk90;
};

extern float D_800C2D30_de;

struct Shared_ActorView;
extern int func_8022BEDC_de(struct Shared_ActorView *arg0);

struct Rules_func_8022C110_de;
typedef struct Rules_func_8022C110_de Rules_func_8022C110_de;

struct func_8022BAC0_S3;
struct func_8022BAC0_S3 {
    char pad0[0xFC];
    f32 unkFC;
    char padFC[0x100 - 0xFC - sizeof(f32)];
    f32 unk100;
    char pad100[0x104 - 0x100 - sizeof(f32)];
    f32 unk104;
};

struct func_8022C640_S2;
typedef struct func_8022C640_S2 func_8022C640_S2;

extern float D_800C2D34_de;

struct ObjectState90;
typedef struct ObjectState90 ObjectState90;

struct func_8022C070_S2;
struct func_8022C070_S2 {
    char pad0[0x780];
    f32 unk780;
};

struct func_8022BB70_S1;
typedef struct func_8022BB70_S1 func_8022BB70_S1;

struct func_8022C640_S2;
struct func_8022C640_S2 {
    char pad0[0x5D0];
    s32 unk5D0;
    char pad5D0[0x16E0 - 0x5D0 - sizeof(s32)];
    char * unk16E0;
};

extern void *func_8022C55C_de(void *arg0, u32 arg1);

extern void func_8022C0D0_de(void *arg0);

extern void func_8022C2B4_de(void *arg0, struct ScreenRectangle *arg1);

struct func_8022BAC0_S1;
struct func_8022BAC0_S1 {
    char pad0[0x18];
    void * unk18;
    char pad18[0x50 - 0x18 - sizeof(void*)];
    f32 unk50;
    char pad50[0x54 - 0x50 - sizeof(f32)];
    f32 unk54;
    char pad54[0x58 - 0x54 - sizeof(f32)];
    f32 unk58;
    char pad58[0x5D8 - 0x58 - sizeof(f32)];
    void * unk5D8;
    char pad5D8[0x5E0 - 0x5D8 - sizeof(void*)];
    s32 unk5E0;
};

struct Rules_func_8022C110_de;
struct Rules_func_8022C110_de {
    char pad0[0xD];
    unsigned char mode;
    char padE[0x1D - 0xE];
    unsigned char started;
};

struct func_8022BD84_S2;
typedef struct func_8022BD84_S2 func_8022BD84_S2;

struct ObjectState668;
typedef struct ObjectState668 ObjectState668;

struct func_8022BB70_S1;
struct func_8022BB70_S1 {
    char pad0[0x62C];
    s32 unk62C;
};

struct func_8022C070_S2;
typedef struct func_8022C070_S2 func_8022C070_S2;

struct func_8022C54C_S3;
typedef struct func_8022C54C_S3 func_8022C54C_S3;

struct FloatState67C;
struct FloatState67C {
    unsigned char padding_0[1656];
    f32 unk_678;
};

extern float D_800C2D5C_de;

extern int func_8022BAC0_de(void);

extern float D_800C2D28_de;

struct func_8022BAC0_S3;
typedef struct func_8022BAC0_S3 func_8022BAC0_S3;

struct func_8022C7E8_S1;
typedef struct func_8022C7E8_S1 func_8022C7E8_S1;

struct func_8022C7E8_S1;
struct func_8022C7E8_S1 {
    char pad0[0x6B0];
    s32 unk6B0;
    char pad6B0[0x6E4 - 0x6B0 - sizeof(s32)];
    f32 unk6E4;
    char pad6E4[0x7E8 - 0x6E4 - sizeof(f32)];
    s32 unk7E8;
    char pad7E8[0x11D8 - 0x7E8 - sizeof(s32)];
    f32 unk11D8;
};

extern float D_800C2D38_de;



struct func_8022BAC0_S1;
typedef struct func_8022BAC0_S1 func_8022BAC0_S1;

struct func_8022C444_S2;
typedef struct func_8022C444_S2 func_8022C444_S2;

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

struct func_8022BB70_S2;
typedef struct func_8022BB70_S2 func_8022BB70_S2;

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

struct ObjectState90;
struct ObjectState90 {
    unsigned char padding_0[143];
    s8 unk_8F;
};

struct Player;
extern void func_8022BC14_de(struct Player *arg0);

struct func_8022BB70_S2;
struct func_8022BB70_S2 {
    char pad0[0x3];
    u8 unk3;
    char pad3[0x18 - 0x3 - sizeof(u8)];
    void * unk18;
    char pad18[0x5D8 - 0x18 - sizeof(void*)];
    void * unk5D8;
    char pad5D8[0x86C - 0x5D8 - sizeof(void*)];
    s32 unk86C;
};

struct func_8022BC04_S1;
typedef struct func_8022BC04_S1 func_8022BC04_S1;

extern void func_8022C110_de(PlayerRecAt1450V2 *player);

struct ObjectState668;
struct ObjectState668 {
    char pad0[0x650];
    s16 unk_650;
    char pad650[0x664 - 0x650 - sizeof(s16)];
    s32 unk_664;
};

struct func_8022C444_S2;
struct func_8022C444_S2 {
    char pad0[0x90];
    char unk90;
};

extern float D_800C2D2C_de;

struct func_8022BC04_S1;
struct func_8022BC04_S1 {
    char pad0[0x2E8];
    char unk2E8;
    char pad2E8[0x484 - 0x2E8 - sizeof(char)];
    void * unk484;
    char pad484[0x62E - 0x484 - sizeof(void*)];
    s16 unk62E;
    char pad62E[0x1450 - 0x62E - sizeof(s16)];
    s32 unk1450;
};

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

extern void Text_ApplyDamageOverTime(struct Shared_ActorView *player, void *source);

extern s32 func_8022C460_de(void *);

extern int D_80140FC0;

#endif
#endif
