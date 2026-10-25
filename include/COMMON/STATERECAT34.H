#ifndef COMMON_STATERECAT34_H
#define COMMON_STATERECAT34_H
#include "TYPES.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/SHAREDPLAYER.H"
struct StateRecAt34;

extern void func_8025E19C_de(s32 arg0);


struct ObjectState40;
struct ObjectState40 {
    struct ContextRecAt2BC0 *context;
    char pad4[0x10];
    s32 unk_14;
    char pad18[4];
    s32 flags; /* 0x1C */
    s32 volume; /* 0x20 */
    s32 unk_24;
    char pad24[0x2C - 0x24 - sizeof(s32)];
    f32 unk_2C;
    char pad30[4];
    f32 fadeStep; /* 0x34 */
    s32 unk_38;
    char pad38[0x3C - 0x38 - sizeof(s32)];
    f32 unk_3C;
    f32 targetGain; /* 0x40 */
};

extern void func_8025E174_de(s32 arg0);

struct IntegerState2C_2;

extern void func_8025E23C_de();

struct func_8025DB64_S1;
struct func_8025DB64_S1 {
    char pad0[0x38];
    int unk38;
    char pad38[0x40 - 0x38 - sizeof(int)];
    float unk40;
};

extern float D_800C9108;

extern float D_800C4000_de;

struct func_8025DC54_S1;
struct func_8025DC54_S1 {
    char pad0[0x14];
    s32 unk14;
    char pad14[0x2C - 0x14 - sizeof(s32)];
    f32 unk2C;
};

struct StateRecAt34;
typedef struct StateRecAt34 StateRecAt34;

extern float D_800C4038_de;

struct Track;

struct IntegerState2C_2;
typedef struct IntegerState2C_2 IntegerState2C_2;


struct func_8025D948_S1;
typedef struct func_8025D948_S1 func_8025D948_S1;

struct func_8025D948_S1;
struct func_8025D948_S1 {
    char pad0[0x14];
    s32 unk14;
    char pad14[0x1C - 0x14 - sizeof(s32)];
    s32 unk1C;
    char pad1C[0x22 - 0x1C - sizeof(s32)];
    s16 unk22;
    char pad22[0x34 - 0x22 - sizeof(s16)];
    f32 unk34;
    char pad34[0x38 - 0x34 - sizeof(f32)];
    s32 unk38;
    char pad38[0x3C - 0x38 - sizeof(s32)];
    f32 unk3C;
    char pad3C[0x40 - 0x3C - sizeof(f32)];
    f32 unk40;
};

struct func_8025DB54_S1;
typedef struct func_8025DB54_S1 func_8025DB54_S1;

struct ObjectState2BBC;
typedef struct ObjectState2BBC ObjectState2BBC;

extern void func_8025DE30_de();


struct func_8025DB54_S1;
struct func_8025DB54_S1 {
    char pad0[0x38];
    int unk38;
    char pad38[0x40 - 0x38 - sizeof(int)];
    int unk40;
};

struct func_8025DD80_S1;
typedef struct func_8025DD80_S1 func_8025DD80_S1;


struct ObjectState2BBC;
struct ObjectState2BBC {
    char pad0[0x2BA4];
    f32 unk_2BA4;
    char pad2BA4[0x2BB8 - 0x2BA4 - sizeof(f32)];
    s32 unk_2BB8;
};

struct func_8025DB64_S1;
typedef struct func_8025DB64_S1 func_8025DB64_S1;

struct ObjectState40;
typedef struct ObjectState40 ObjectState40;

extern float D_800C4028_de;

extern float D_800C4020_de;
extern float D_800C4024_de;

struct func_8025DD80_S1;
struct func_8025DD80_S1 {
    char pad0[0x8];
    void * unk8;
    char pad8[0xC - 0x8 - sizeof(void*)];
    s32 unkC;
    char padC[0x10 - 0xC - sizeof(s32)];
    s32 unk10;
    char pad10[0x14 - 0x10 - sizeof(s32)];
    s32 unk14;
    char pad14[0x24 - 0x14 - sizeof(s32)];
    s32 unk24;
    char pad24[0x2C - 0x24 - sizeof(s32)];
    f32 unk2C;
};

extern int func_8025E04C_de(int arg0);

struct func_8025DC54_S1;
typedef struct func_8025DC54_S1 func_8025DC54_S1;


extern void func_8025E150_de(void);

extern void func_8025E1EC_de(s32 arg0);

struct ALWaveTable_s;
extern s32 func_802BEAA4_de(void *, s32, struct ALWaveTable_s *);
extern s32 func_802B51B8_de(void *, s32, void *);

struct ContextRecAt2BC0;
extern s32 Texture_PlaySoundAtPosition(struct ContextRecAt2BC0 *, s32, CVector3, s32, s32);
#endif
