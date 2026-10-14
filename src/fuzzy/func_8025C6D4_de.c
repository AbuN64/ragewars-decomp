#include "types.h"

typedef struct {
    u16 key;
    u16 start;
    u16 end;
    s16 duration;
    u32 remaining;
} Block12;

extern void *func_80258BF4_de(void *arg0, s32 arg1);
extern s32 func_80258D2C_de(void *arg0);
extern s16 func_80259B10_de(void *arg0, s32 arg1);
extern f32 func_802B2350(s32 arg0);

typedef struct func_8025C6F4_S1 func_8025C6F4_S1;
typedef struct func_8025C6F4_S2 func_8025C6F4_S2;
typedef struct func_8025C6F4_S3 func_8025C6F4_S3;
typedef struct func_8025C6F4_S4 func_8025C6F4_S4;
struct func_8025C6F4_S1 {
    char pad0[0x28];
    s16 unk28;
    char pad28[0x44 - 0x28 - sizeof(s16)];
    char unk44;
    char pad44[0x88 - 0x44 - sizeof(char)];
    s32 unk88;
    char pad88[0x8C - 0x88 - sizeof(s32)];
    Block12 unk8C;
    char pad8C[0x98 - 0x8C - sizeof(Block12)];
    f32 unk98;
    char pad98[0x9C - 0x98 - sizeof(f32)];
    f32 unk9C;
    char pad9C[0xA8 - 0x9C - sizeof(f32)];
    s32 unkA8;
    char padA8[0xB0 - 0xA8 - sizeof(s32)];
    func_8025C6F4_S4 *unkB0;
    char padB0[0xC0 - 0xB0 - sizeof(void*)];
    s32 unkC0;
};
struct func_8025C6F4_S2 {
    char pad0[0xC];
    s16 unkC;
};
struct func_8025C6F4_S3 {
    char pad0[0x8E];
    u16 unk8E;
    char pad8E[0x90 - 0x8E - sizeof(u16)];
    u16 unk90;
    char pad90[0x92 - 0x90 - sizeof(u16)];
    s16 unk92;
};
struct func_8025C6F4_S4 {
    char pad0[0x2B94];
    s8 unk2B94;
    char pad2B94[0x2B98 - 0x2B94 - sizeof(s8)];
    s32 unk2B98;
};

void func_8025C6D4_de(func_8025C6F4_S1 *arg0, func_8025C6F4_S2 *arg1) {
    f32 first;
    s16 index;
    s16 value;
    Block12 *record;

    arg0->unk28 = 0x40;
    index = arg1->unkC;
    if (index != -1) {
        record = func_80258BF4_de(arg0->unkB0, index);
        arg0->unk8C = *record;
        first = func_802B2350(arg0->unk8C.start);
        arg0->unk9C =
            (first - func_802B2350(arg0->unk8C.end)) /
            arg0->unk8C.duration;
        arg0->unk98 =
            func_802B2350(arg0->unk8C.start);
        arg0->unk28 =
            (s16)(s32)func_802B2350(arg0->unk8C.start);
        arg0->unk88 = 1;
        return;
    }

    arg0->unk88 = 0;
    if (arg0->unkA8 < 0x100) {
        if (arg0->unkC0 == 0 &&
            func_80258D2C_de(arg0->unkB0) != 0) {
            value = arg0->unkB0->unk2B94;
            goto store_value;
        }
    } else if (arg0->unkC0 == 0 &&
               func_80258D2C_de(arg0->unkB0) != 0) {
        value = func_80259B10_de(&arg0->unk44,
            arg0->unkB0->unk2B98);
store_value:
        arg0->unk28 = value;
    }
}
