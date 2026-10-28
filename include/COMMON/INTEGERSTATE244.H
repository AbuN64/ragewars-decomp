#ifndef COMMON_INTEGERSTATE244_H
#define COMMON_INTEGERSTATE244_H
struct SharedPlayer;
#ifndef SPAN_1000_CODE_8022C894_H
#define SPAN_1000_CODE_8022C894_H
#include "TYPES.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/GAMEPLAY_TRANSITION.H"
#include "COMMON/EXTERNS_15.H"
struct IntegerState244;
typedef struct IntegerState244 IntegerState244;



extern void func_8022D420_de(void);

extern void func_8022D4AC_de(struct SharedPlayer *arg0);

struct ObjectLinks1458_2;
typedef struct ObjectLinks1458_2 ObjectLinks1458_2;

extern void Player_AimPreviousPositionAtReset(void *arg0);

extern void func_8022D254_de(void);


extern float D_800C2D90_de;





extern float D_800C2DBC_de;


extern void func_8022D49C_de(void);

extern float D_800C2DB8_de;

extern float D_800C7E9C;






extern float D_800C7E90;

extern float D_800C2D88_de;

extern float D_800C7E94;

extern float D_800C2D8C_de;





struct IntegerState244;
struct IntegerState244 {
    unsigned char padding_0[572];
    s32 unk_23C;
    s32 unk_240;
};

extern float D_800C2D80_de;

extern void Player_ClearGlobalFlagBit(void);


extern void func_8022D20C_de(void);


extern void func_8022D3F4_de(void);




extern float D_800C2DC0_de;


extern void func_8022D288_de(void);

extern void func_8022D4A4_de(void);



extern void func_8022C8EC_de(void);


extern float D_800C2D84_de;

struct FloatState6C8;
typedef struct FloatState6C8 FloatState6C8;


extern void func_8022C8F4_de(void);

extern void Player_ResetStunFlags(void *arg0);




extern void func_8022D1A0_de(void);

struct ObjectLinks1458_2;
struct ObjectLinks1458_2 {
    char pad0[0x50];
    f32 unk_50;
    char pad50[0x54 - 0x50 - sizeof(f32)];
    f32 unk_54;
    char pad54[0x58 - 0x54 - sizeof(f32)];
    f32 unk_58;
    char pad58[0x658 - 0x58 - sizeof(f32)];
    f32 unk_658;
    char pad658[0x122C - 0x658 - sizeof(f32)];
    s32 unk_122C;
    char pad122C[0x1230 - 0x122C - sizeof(s32)];
    s32 unk_1230;
    char pad1230[0x1238 - 0x1230 - sizeof(s32)];
    s32 unk_1238;
    char pad1238[0x13C8 - 0x1238 - sizeof(s32)];
    s32 unk_13C8;
    char pad13C8[0x1454 - 0x13C8 - sizeof(s32)];
    void * unk_1454;
};


extern float D_800C7E98;


struct FloatState6C8;
struct FloatState6C8 {
    unsigned char padding_0[1700];
    f32 unk_6A4;
    unsigned char padding_6A8[28];
    f32 unk_6C4;
};









extern float D_800C2D60_de;

extern void func_8022D198_de(void);

extern void func_8022D3EC_de(void);

extern void Graphu64_EaseValueToward(f32 *value, f32 target, f32 rate);
extern void Player_UpdateLeapMotion(s32 arg0, s32 arg1);

extern void Player_UpdateRunEndPlayer(void *);
struct ObjectLinks854;
extern void Playerai_TryStartPlayerSequence(struct ObjectLinks854 *a, void *b, int c);

s32 func_8021C45C_de(s32, void *, s32, s32);


#endif
#endif
