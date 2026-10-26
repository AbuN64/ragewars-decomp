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


extern float D_800C9108;

extern float D_800C4000_de;


struct StateRecAt34;
typedef struct StateRecAt34 StateRecAt34;

extern float D_800C4038_de;

struct Track;

struct IntegerState2C_2;
typedef struct IntegerState2C_2 IntegerState2C_2;






extern void func_8025DE30_de();







struct ObjectState40;
typedef struct ObjectState40 ObjectState40;

extern float D_800C4028_de;

extern float D_800C4020_de;
extern float D_800C4024_de;


extern int func_8025E04C_de(int arg0);



extern void func_8025E150_de(void);

extern void func_8025E1EC_de(s32 arg0);

struct ALWaveTable_s;
extern s32 func_802BEAA4_de(void *, s32, struct ALWaveTable_s *);
extern s32 func_802B51B8_de(void *, s32, void *);

struct ContextRecAt2BC0;
extern s32 Audio_PlaySoundAtPosition(struct ContextRecAt2BC0 *, s32, CVector3, s32, s32);
#endif
