#include "TYPES.H"

extern f32 D_800C62D8;
extern f32 D_800C62DC;
extern void D_002AD1B4(void);
extern void D_002AD264(void);
#include "shared/menu_match_globals.h"
extern void func_802A6FB8_de(void *arg0, s32 arg1, s32 arg2, s32 arg3,
                          s32 arg4, s32 arg5, s32 arg6, void (*arg7)(void), void (*arg8)(void));
extern void func_802391AC_de(void *, s32, s32, s32, s32, s32, s32, s32);
extern void func_80237E80_de(void *, void *, void *);
extern s32 func_8025DE54_de(s16 arg0, s32 arg1, s32 arg2, s32 arg3,
                         s32 arg4, s32 arg5);


typedef struct func_802ADE28_S1 func_802ADE28_S1;
typedef struct func_802ADE28_S2 func_802ADE28_S2;
typedef struct func_802ADE28_S3 func_802ADE28_S3;
typedef struct func_802ADE28_S4 func_802ADE28_S4;
typedef struct RecCode80213ED480216BF4 RecCode80213ED480216BF4;
struct func_802ADE28_S1 {
    char pad0[0x18];
    func_802ADE28_S2 *unk18;
};
typedef struct EffectAmount { char pad[0xC]; f32 amount; } EffectAmount;
struct func_802ADE28_S2 { char pad[0x14]; EffectAmount payload; };
struct func_802ADE28_S3 {
    void **resource;
    u16 unk4;
    char pad4[0x6 - 0x4 - sizeof(u16)];
    s16 unk6;
    char pad6[0x8 - 0x6 - sizeof(s16)];
    s16 unk8;
};
struct func_802ADE28_S4 {
    char pad0[0x8];
    s32 unk8;
    char pad8[0xC - 0x8 - sizeof(s32)];
    s32 unkC;
    char padC[0x10 - 0xC - sizeof(s32)];
    s32 unk10;
    char pad10[0x5DC - 0x10 - sizeof(s32)];
    void* unk5DC;
    char pad5DC[0x670 - 0x5DC - sizeof(void*)];
    f32 unk670;
    char pad670[0x674 - 0x670 - sizeof(f32)];
    f32 unk674;
    char pad674[0x678 - 0x674 - sizeof(f32)];
    f32 unk678;
    char pad678[0xD40 - 0x678 - sizeof(f32)];
    char unkD40;
};
struct RecCode80213ED480216BF4 {
    char pad0[0xC];
    f32 unkC;
};

/** Apply a scripted effect command and its optional sound callbacks. */
s32 func_802ACE38_de(func_802ADE28_S4 *arg0, func_802ADE28_S3 *arg1, func_802ADE28_S1 *arg2) {
    void **resource;
    EffectAmount *state_value;
    s32 sound;
    s32 callback;
    s16 command;

    state_value = &arg2->unk18->payload;
    command = arg1->unk4 - 0x708;
    switch (command) {
    case 0:
        arg0->unk670 = D_800C62D8;
        break;
    case 1:
        arg0->unk674 = D_800C62DC;
        break;
    case 2:
    case 3:
        arg0->unk678 += state_value->amount;
        break;
    case 7:
        func_802A6FB8_de(&arg0->unkD40, 1, 0, 0x7FD,
                       0, 0, 0, D_002AD1B4, D_002AD264);
        break;
    
    default: break;
    }

    resource = arg1->resource;
    sound = arg1->unk6;
    callback = arg1->unk8;
    if (arg0->unk5DC != 0) {
        func_802391AC_de(arg0->unk5DC,
                      0x80, 0x32, 0x32, 0x4B, 0, 0, 2);
        if (resource != 0) {
            func_80237E80_de(&D_80145088,
                          arg0->unk5DC,
                          *resource);
        }
    }
    if (sound != 0) {
        func_8025DE54_de(sound,
                      arg0->unk8,
                      arg0->unkC,
                      arg0->unk10, 0, -1);
    }
    if (callback != 0) {
        func_8025E11C_de(callback);
    }
    return 1;
}

