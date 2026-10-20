#ifndef COMMON_PAKQUEUESTATE_H
#define COMMON_PAKQUEUESTATE_H
struct ControllerProfile;
#ifndef SPAN_1000_CODE_802636D0_H
#define SPAN_1000_CODE_802636D0_H
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"

/* Status and message queue for controller-pak operations. */
typedef struct PakQueueState {
    s8 status;
    char reserved1[7];
    OSMesgQueue queue;
} PakQueueState;

/* The controller-pak message queue: the queue member of the PakQueueState that starts 8 bytes lower. */
extern OSMesgQueue D_8010FBC0;

/* The four controller profiles, one per port. */
extern struct ControllerProfile D_8010F328[4];
struct func_80264268_S1;
struct func_80264268_S1 {
    char pad0[0xC8];
    s32 unkC8;
    char padC8[0xCC - 0xC8 - sizeof(s32)];
    s32 unkCC;
    char padCC[0xD0 - 0xCC - sizeof(s32)];
    s32 unkD0;
    char padD0[0xD4 - 0xD0 - sizeof(s32)];
    s32 unkD4;
};

struct func_802636D0_S1;
struct func_802636D0_S1 {
    int unk0;
    char pad0[0x4 - 0x0 - sizeof(int)];
    int unk4;
    char pad4[0x8 - 0x4 - sizeof(int)];
    int unk8;
    char pad8[0xC - 0x8 - sizeof(int)];
    int unkC;
    char padC[0x14 - 0xC - sizeof(int)];
    int unk14;
    char pad14[0x18 - 0x14 - sizeof(int)];
    int unk18;
    char pad18[0x1C - 0x18 - sizeof(int)];
    int unk1C;
    char pad1C[0x20 - 0x1C - sizeof(int)];
    int unk20;
    char pad20[0x24 - 0x20 - sizeof(int)];
    int unk24;
    char pad24[0x28 - 0x24 - sizeof(int)];
    int unk28;
    char pad28[0x2C - 0x28 - sizeof(int)];
    int unk2C;
    char pad2C[0x30 - 0x2C - sizeof(int)];
    int unk30;
    char pad30[0x34 - 0x30 - sizeof(int)];
    int unk34;
};


struct func_802643D8_S1;
struct func_802643D8_S1 {
    char pad0[0xC0];
    int unkC0;
};

struct ObjectState30;
typedef struct ObjectState30 ObjectState30;

struct func_802643D8_S1;
typedef struct func_802643D8_S1 func_802643D8_S1;

struct Obj80264124;
struct Obj80264124 {
    s32 flags;
    s8 enabled;
    char pad05[3];
    s32 x;
    s32 y;
    s32 z;
    char pad14[0xB4];
    s32 active;
    s32 state;
    f32 amount;
    f32 timer;
    char status[0x68];
    char object[1];
};

extern void func_80263CF0_de(void *arg0);

extern int func_8026436C_de(Shared_Effect *arg0);




struct ObjectState224;
typedef struct ObjectState224 ObjectState224;

extern int func_80264690_de();

struct func_802644C8_S1;
typedef struct func_802644C8_S1 func_802644C8_S1;

extern void func_8026454C_de();

struct func_80264268_S1;
typedef struct func_80264268_S1 func_80264268_S1;




extern int func_802643E8_de(Shared_Effect *arg0);

extern float D_800C4308_de;

struct func_802636D0_S1;
typedef struct func_802636D0_S1 func_802636D0_S1;

struct ObjectState30;
struct ObjectState30 {
    unsigned char padding_0[44];
    s8 unk_2C;
    s8 unk_2D;
    s8 unk_2E;
    s8 unk_2F;
};

extern void func_80263C24_de();




extern void func_80263AF4_de();




struct func_802644C8_S1;
struct func_802644C8_S1 {
    char pad0[0x18];
    s32 unk18;
    char pad18[0x1C - 0x18 - sizeof(s32)];
    s32 unk1C;
    char pad1C[0x20 - 0x1C - sizeof(s32)];
    s32 unk20;
    char pad20[0x24 - 0x20 - sizeof(s32)];
    s32 unk24;
    char pad24[0x28 - 0x24 - sizeof(s32)];
    s32 unk28;
    char pad28[0xAC - 0x28 - sizeof(s32)];
    s32 unkAC;
    char padAC[0xB0 - 0xAC - sizeof(s32)];
    s32 unkB0;
    char padB0[0xB4 - 0xB0 - sizeof(s32)];
    s32 unkB4;
    char padB4[0xB8 - 0xB4 - sizeof(s32)];
    s32 unkB8;
    char padB8[0xBC - 0xB8 - sizeof(s32)];
    s32 unkBC;
    char padBC[0xC0 - 0xBC - sizeof(s32)];
    s32 unkC0;
    char padC0[0xC4 - 0xC0 - sizeof(s32)];
    u8 unkC4;
    char padC4[0xC5 - 0xC4 - sizeof(u8)];
    u8 unkC5;
    char padC5[0xC6 - 0xC5 - sizeof(u8)];
    u8 unkC6;
    char padC6[0xC7 - 0xC6 - sizeof(u8)];
    u8 unkC7;
};

extern int func_802643F8_de(struct ControllerProfile *arg0);
extern void func_80264248_de(struct ControllerProfile *arg0);

extern int func_80264634_de(int arg0);

struct Obj80264124;
typedef struct Obj80264124 Obj80264124;

struct ObjectState224;
struct ObjectState224 {
    s32 unk_0;
    char pad0[0x4 - 0x0 - sizeof(s32)];
    s8 unk_4;
    char pad4[0x8 - 0x4 - sizeof(s8)];
    s32 unk_8;
    char pad8[0xC - 0x8 - sizeof(s32)];
    s32 unk_C;
    char padC[0x10 - 0xC - sizeof(s32)];
    s32 unk_10;
    char pad10[0x14 - 0x10 - sizeof(s32)];
    s32 unk_14;
    char pad14[0x18 - 0x14 - sizeof(s32)];
    s32 unk_18;
    char pad18[0x1C - 0x18 - sizeof(s32)];
    s32 unk_1C;
    char pad1C[0x20 - 0x1C - sizeof(s32)];
    s32 unk_20;
    char pad20[0x24 - 0x20 - sizeof(s32)];
    s32 unk_24;
    char pad24[0x28 - 0x24 - sizeof(s32)];
    s32 unk_28;
    char pad28[0xC4 - 0x28 - sizeof(s32)];
    s8 unk_C4;
    char padC4[0xC5 - 0xC4 - sizeof(s8)];
    s8 unk_C5;
    char padC5[0xC6 - 0xC5 - sizeof(s8)];
    s8 unk_C6;
    char padC6[0xC7 - 0xC6 - sizeof(s8)];
    s8 unk_C7;
    char padC7[0xC8 - 0xC7 - sizeof(s8)];
    s32 unk_C8;
    char padC8[0xCC - 0xC8 - sizeof(s32)];
    s32 unk_CC;
    char padCC[0xD0 - 0xCC - sizeof(s32)];
    s32 unk_D0;
    char padD0[0xD4 - 0xD0 - sizeof(s32)];
    s32 unk_D4;
    char padD4[0x220 - 0xD4 - sizeof(s32)];
    s32 unk_220;
};

extern void func_80264404_de();

extern f32 func_802856E0_de(void *arg0, s32 arg1, s32 arg2, s32 arg3);

extern void func_80263740_de(void);
extern void func_802644A8_de(void *arg0);
extern s32 func_802A23A4_de(void);

extern s32 func_80264728_de(void);

#endif
#endif
