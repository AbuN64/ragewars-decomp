#ifndef UNBAKE_SPAN_16E000_CODE_804221A0_H
#define UNBAKE_SPAN_16E000_CODE_804221A0_H
#include "types.h"
struct func_80422C20_S1;
struct func_80422C20_S1 {
    char pad0[0x1240];
    u8 unk1240;
    char pad1240[0x180C - 0x1240 - sizeof(u8)];
    s32 unk180C;
};

struct func_80422C20_S1;
typedef struct func_80422C20_S1 func_80422C20_S1;

extern s32 func_8042244C_de(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);

extern void func_80422170_de();

extern void func_80422F9C_de();

extern void func_804221E8_de();

struct Screen_func_80422960_de;
struct Screen_func_80422960_de {
    char pad0[0x1C];
    s32 choice;
    char pad20[0x60 - 0x20];
    s32 mode;
    s32 arena;
};

struct Game_func_80422960_de;
struct Game_func_80422960_de {
    char pad0[0x3C];
    s32 next;
    char pad40[0xD8 - 0x40];
    s32 selection;
};

#endif
