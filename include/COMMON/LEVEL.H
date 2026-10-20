#ifndef COMMON_LEVEL_H
#define COMMON_LEVEL_H
#include "TYPES.H"
struct Item_func_8044D668_de;
typedef struct Item_func_8044D668_de Item_func_8044D668_de;

struct func_8044E9A0_S1;
typedef struct func_8044E9A0_S1 func_8044E9A0_S1;

struct func_8044E9A0_S1;
struct func_8044E9A0_S1 {
    char pad0[0x26DBC];
    s32 unk26DBC;
    char pad26DBC[0x26DC1 - 0x26DBC - sizeof(s32)];
    u8 unk26DC1;
};

struct Item_func_8044D668_de;
struct Item_func_8044D668_de {
    char pad0[0x11];
    u8 kind;
    char pad12[2];
};

struct Level;
struct Level {
    char pad0[0x11C0];
    s32 counts[2];
    char pad11C8[8];
    Item_func_8044D668_de *items[2];
};

struct Level;
typedef struct Level Level;

struct State_func_8044DD50_de;
struct State_func_8044DD50_de {
    char pad0[0x24];
    s32 a;
    char pad28[0x54 - 0x28];
    s32 b;
    char pad58[0x78 - 0x58];
    s32 c;
    char pad7C[0x88 - 0x7C];
    s32 d;
    char pad8C[0xAC - 0x8C];
    s32 e;
};
#endif
