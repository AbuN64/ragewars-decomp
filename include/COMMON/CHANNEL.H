#ifndef COMMON_CHANNEL_H
#define COMMON_CHANNEL_H
struct Channel;
#ifndef SPAN_1000_CODE_802393F4_H
#define SPAN_1000_CODE_802393F4_H
#include "TYPES.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/AIPROFILE.H"
struct ScreenMessageOwner;
extern void func_8023A1F4_de(struct ScreenMessageOwner *arg0);

struct func_80239FCC_S1;
struct func_80239FCC_S1 {
    char pad0[0x38];
    f32 unk38;
    char pad38[0x3C - 0x38 - sizeof(f32)];
    f32 unk3C;
    char pad3C[0x40 - 0x3C - sizeof(f32)];
    f32 unk40;
    char pad40[0x44 - 0x40 - sizeof(f32)];
    f32 unk44;
    char pad44[0x58 - 0x44 - sizeof(f32)];
    s32 unk58;
    char pad58[0x5C - 0x58 - sizeof(s32)];
    f32 unk5C;
    char pad5C[0x64 - 0x5C - sizeof(f32)];
    s32 unk64;
};

extern float D_800C8664;

struct func_80239668_S2;
typedef struct func_80239668_S2 func_80239668_S2;

struct func_80239594_S1;
struct func_80239594_S1 {
    char pad0[0x20];
    void * unk20;
    char pad20[0x40 - 0x20 - sizeof(void*)];
    char unk40;
    char pad40[0x1200 - 0x40 - sizeof(char)];
    s32 unk1200;
};

extern float D_800C8658;

extern float D_800C3598_de;

extern void func_80239D00_de(struct Channel *arg0, float arg1, int arg2);

struct func_8023A1E4_S1;
struct func_8023A1E4_S1 {
    s32 unk0;
    char pad0[0x4 - 0x0 - sizeof(s32)];
    s32 unk4;
    char pad4[0x8 - 0x4 - sizeof(s32)];
    s32 unk8;
    char pad8[0x1200 - 0x8 - sizeof(s32)];
    s32 unk1200;
};

struct func_80239594_S2;
struct func_80239594_S2 {
    char pad0[0x4];
    void * unk4;
    char pad4[0x128 - 0x4 - sizeof(void*)];
    CVector3 unk128;
};

struct func_802393FC_S1;
typedef struct func_802393FC_S1 func_802393FC_S1;

extern void func_8023940C_de(char *object);

struct func_80239AE4_S2;
struct func_80239AE4_S2 {
    char pad0[0xF24];
    char unkF24;
};

struct Channel;
struct Channel {
    s32 mode;
    f32 level;
    s32 state[3]; /* 0x08..0x10 */
};

struct Channel;
struct RecordRecAt18;
struct RecordRecAt18 {
    char pad[8];
    Triple triple;
    f32 value;
    struct Channel channels[3];
};

struct func_802394AC_S1;
typedef struct func_802394AC_S1 func_802394AC_S1;

extern void func_80239D90_de(void *arg0);

struct func_802394AC_S2;
struct func_802394AC_S2 {
    char pad0[0x11D8];
    char * unk11D8;
    char pad11D8[0x11F0 - 0x11D8 - sizeof(char*)];
    char * unk11F0;
};

struct IntegerStateF24;
typedef struct IntegerStateF24 IntegerStateF24;

struct func_80239C2C_S1;
typedef struct func_80239C2C_S1 func_80239C2C_S1;

extern float D_800C3548_de;

struct func_80239594_S1;
typedef struct func_80239594_S1 func_80239594_S1;

extern float D_800C3570_de;

extern int func_8023941C_de(void *arg0);

struct func_80239668_S1;
typedef struct func_80239668_S1 func_80239668_S1;

struct func_80239E94_S1;
struct func_80239E94_S1 {
    char pad0[0x58];
    s32 unk58;
    char pad58[0xF4 - 0x58 - sizeof(s32)];
    f32 unkF4;
    char padF4[0xF8 - 0xF4 - sizeof(f32)];
    f32 unkF8;
};

struct ScreenMessagePool;
extern void func_80239AF4_de(struct ScreenMessageOwner *arg0, struct ScreenMessagePool *arg1);

extern void func_8023A24C_de(void *arg0);

extern s32 func_80239E48_de(s32 arg0);

struct func_80239B54_S2;
struct func_80239B54_S2 {
    char pad0[0x4];
    void * unk4;
    char pad4[0xE40 - 0x4 - sizeof(void*)];
    IntrusiveList unkE40;
};

struct func_802394AC_S1;
struct func_802394AC_S1 {
    char pad0[0x8];
    CVector3 unk8;
    char pad8[0x14 - 0x8 - sizeof(CVector3)];
    f32 unk14;
    char pad14[0x18 - 0x14 - sizeof(f32)];
    s32 unk18;
    char pad18[0x1C - 0x18 - sizeof(s32)];
    f32 unk1C;
    char pad1C[0x2C - 0x1C - sizeof(f32)];
    s32 unk2C;
    char pad2C[0x30 - 0x2C - sizeof(s32)];
    f32 unk30;
    char pad30[0x40 - 0x30 - sizeof(f32)];
    s32 unk40;
    char pad40[0x44 - 0x40 - sizeof(s32)];
    f32 unk44;
};

struct IntegerStateF24;
struct IntegerStateF24 {
    unsigned char padding_0[3864];
    s32 unk_F18;
    s32 unk_F1C;
    s32 unk_F20;
};

struct func_80239C2C_S1;
struct func_80239C2C_S1 {
    char pad0[0xF24];
    IntrusiveList unkF24;
};

struct func_80239D80_S1;
struct func_80239D80_S1 {
    char pad0[0x8];
    s32 unk8;
    char pad8[0xC - 0x8 - sizeof(s32)];
    s32 unkC;
    char padC[0x10 - 0xC - sizeof(s32)];
    s32 unk10;
    char pad10[0x14 - 0x10 - sizeof(s32)];
    f32 unk14;
};

struct func_8023A104_S1;
typedef struct func_8023A104_S1 func_8023A104_S1;

struct func_802394AC_S2;
typedef struct func_802394AC_S2 func_802394AC_S2;

struct Wave;
struct Wave {
    s32 kind;
    char pad4[0xC - 4];
    f32 amplitude;
    f32 phase;
};

extern float D_800C3590_de;

extern double D_800C3550_de;

struct func_8023A180_S1;
typedef struct func_8023A180_S1 func_8023A180_S1;

struct func_80239D80_S1;
typedef struct func_80239D80_S1 func_80239D80_S1;

struct func_80239594_S2;
typedef struct func_80239594_S2 func_80239594_S2;

extern void func_80239FCC_de(void);

struct func_80239FCC_S1;
typedef struct func_80239FCC_S1 func_80239FCC_S1;

extern void func_80239CEC_de(void *arg0);

struct func_8023A180_S1;
struct func_8023A180_S1 {
    char pad0[0xF18];
    void * unkF18;
    char padF18[0xF1C - 0xF18 - sizeof(void*)];
    int unkF1C;
    char padF1C[0xF20 - 0xF1C - sizeof(int)];
    int unkF20;
};

extern float D_800C865C;

struct func_8023A104_S1;
struct func_8023A104_S1 {
    void * unk0;
    char pad0[0x4 - 0x0 - sizeof(void*)];
    s32 unk4;
    char pad4[0x8 - 0x4 - sizeof(s32)];
    s32 unk8;
};

struct Wave;
extern f32 func_80239D1C_de(struct Wave *wave);

struct Node_func_80239AF4_de;
struct func_80239AE4_S1;
struct func_80239AE4_S1 {
    char pad0[0xE40];
    IntrusiveList unkE40;
};

extern float D_800C8668;

extern void func_8023A114_de(void *arg0, s32 arg1);

struct func_8023A1E4_S1;
typedef struct func_8023A1E4_S1 func_8023A1E4_S1;

struct func_80239668_S1;
struct func_80239668_S1 {
    char pad0[0x20];
    void * unk20;
    char pad20[0x30 - 0x20 - sizeof(void*)];
    s32 unk30;
};

struct func_80239AE4_S1;
typedef struct func_80239AE4_S1 func_80239AE4_S1;

struct RecordRecAt18;
extern void func_80239DE8_de(struct RecordRecAt18 *record, f32 first, f32 second, f32 third, f32 value, s32 mode, Triple triple);

struct func_80239B54_S2;
typedef struct func_80239B54_S2 func_80239B54_S2;

extern void func_8023A190_de(void *arg0, int arg1);

extern float D_800C3594_de;

extern void func_80239FDC_de(void *arg0);

extern void func_80239404_de(void);

struct func_80239E94_S1;
typedef struct func_80239E94_S1 func_80239E94_S1;

struct func_80239AE4_S2;
typedef struct func_80239AE4_S2 func_80239AE4_S2;

struct func_802393FC_S1;
struct func_802393FC_S1 {
    char pad0[0xFC];
    int unkFC;
    char padFC[0x100 - 0xFC - sizeof(int)];
    int unk100;
};

struct func_80239668_S2;
struct func_80239668_S2 {
    char pad0[0x4];
    void * unk4;
    char pad4[0x128 - 0x4 - sizeof(void*)];
    char unk128;
};


/* Allocation buffer used by message storage constructors. */
typedef struct MessageBuffer {
    s32 *allocation;
    s32 first;
    s32 count;
} MessageBuffer;

/* On-screen message recycling and distribution share these list owners. */
struct ScreenMessageOwner {
    s32 allocation; /* 0x00 */
    s32 allocationSize; /* 0x04 */
    s32 count; /* 0x08 */
    u8 padding00C[0x40 - 0xC];
    u8 rendering; /* 0x40 */
    u8 padding041[0xF18 - 0x41];
    MessageBuffer storage; /* 0xF18 */
    IntrusiveList activeMessages; /* 0xF24 */
    u8 paddingF38[0x1200 - 0xF38];
    s32 state; /* 0x1200 */
    s32 field1204; /* the owner initialized by func_8044A62C_de is0x1208 */
};
struct ScreenMessagePool {
    u8 padding000[4];
    struct ScreenMessagePool *next; /* 0x04, D_80140FE8 chain */
    u8 padding008[0xE38];
    IntrusiveList freeMessages; /* 0xE40 */
};

struct Message;
extern Message *Camera_PostScreenMessage(struct ScreenMessageOwner *owner, struct ScreenMessagePool *pool, u8 *text);

#endif
#endif
