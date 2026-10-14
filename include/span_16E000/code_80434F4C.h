#ifndef UNBAKE_SPAN_16E000_CODE_80434F4C_H
#define UNBAKE_SPAN_16E000_CODE_80434F4C_H
#include "types.h"
#include "common/types_8a8189af7b05.h"
#include "common/types_1dc8418c21db.h"
extern void func_8043577C_de(int arg0);

extern s32 func_8043590C_de(s32 arg0);

extern int func_80435184_de(int player);

extern void func_80435844_de(s32 index);

struct EntryRecAt6C;
struct EntryRecAt6C {
    char pad0[0x58];
    s32 first;
    char pad5C[0x6C - 0x5C];
    s32 second;
    char pad70[2920 - 0x70];
};

struct Player_func_8043590C_de;
struct Player_func_8043590C_de {
    char a[0xB64];
    s32 value;
};

struct ObjectState71;
struct ObjectState71 {
    char pad0[0x70];
    char unk_70;
};

struct Entry_func_80434EF4_de;
typedef struct Entry_func_80434EF4_de Entry_func_80434EF4_de;

extern void func_80434FB4_de(s32 value);

struct PlayerSlotTable;
struct Player_func_804356BC_de;
struct Triple;
struct PlayerSlotTable {
    char pad0[0x58];
    struct Player_func_804356BC_de players[4];
    struct Triple places[4];
};
typedef struct PlayerSlotTable PlayerSlotTable;

struct Player_func_8043590C_de;
typedef struct Player_func_8043590C_de Player_func_8043590C_de;

struct State_func_8043590C_de;
struct State_func_8043590C_de {
    char a[0x58];
    Player_func_8043590C_de players[1];
};

struct IntegerState346C;
typedef struct IntegerState346C IntegerState346C;

extern int func_80435270_de(int id, int value);

extern s32 func_80435A78_de(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);

struct RecordRecAtD;
struct RecordRecAtD {
    s32 id;
    signed char kind;
    char pad5[7];
    s8 slot; /* 0xC */
    s8 place; /* 0xD */
    char padE[400 - 14];
};

extern int func_80435424_de();

extern int func_80435224_de(int id, int value);

struct Entry_func_80434FC4_de;
struct Entry_func_80434FC4_de {
    char pad0[0x2C];
    s32 phases[1];
    char pad30[0x68 - 0x30];
    void *window;
    char pad6C[2920 - 0x6C];
};

struct PlayerRecAtBA4;
struct PlayerRecAtBA4 {
    char pad[0x58];
    int state;
    char pad5C[0xBA0 - 0x5C];
    int phase;
    int timer;
};

struct Table_func_804352C8_de;
struct Triple;
struct Table_func_804352C8_de {
    char pad[0x2DF8];
    struct Triple slots[1];
};

struct Game_func_80435128_de;
typedef struct Game_func_80435128_de Game_func_80435128_de;

struct IntegerStateBC0;
typedef struct IntegerStateBC0 IntegerStateBC0;

struct Base;
typedef struct Base Base;

extern int func_804351E4_de();

extern s32 func_80435574_de(void);

struct Base;
struct Base {
    char pad[0x2DF0];
    Triple slots[4];
};

extern void func_80434FC4_de(s32 index);

struct func_80435898_S1;
struct func_80435898_S1 {
    char pad0[0xC];
    s8 unkC;
    char padC[0xD - 0xC - sizeof(s8)];
    s8 unkD;
};

extern int D_800E54A0;

struct Entry_func_80435128_de;
typedef struct Entry_func_80435128_de Entry_func_80435128_de;

extern void func_8043542C_de(s32 index);

struct Entry_func_80434EF4_de;
struct Entry_func_80434EF4_de {
    u8 pad0[0xB4C];
    InventorySlot name[8];
    s32 cursor;
    u8 padB60[0x8];
};

extern s32 func_804352C8_de(s32 first, s32 second);

extern int func_80435340_de(void);

struct Player_func_80435128_de;
typedef struct Player_func_80435128_de Player_func_80435128_de;

struct Entry_func_80435128_de;
struct Entry_func_80435128_de {
    char pad[0x7D];
    signed char state;
    char pad7E[0x190 - 0x7E];
};

struct Player_func_80435128_de;
struct Player_func_80435128_de {
    Entry_func_80435128_de entries[4];
    char pad[0xB68 - 0x640];
};

struct Game_func_80435128_de;
struct Game_func_80435128_de {
    Player_func_80435128_de players[4];
};

extern void func_804354C0_de(s32 index);

struct IntegerState346C;
struct IntegerState346C {
    char pad0[0x3468];
    s32 unk_3468;
};

struct State_func_8043590C_de;
typedef struct State_func_8043590C_de State_func_8043590C_de;

extern void func_804356BC_de(s32 arg0);

struct IntegerStateBC0;
struct IntegerStateBC0 {
    unsigned char padding_0[3004];
    s32 unk_BBC;
};

extern float D_800DDED0;

struct Table_func_804351E4_de;
struct Triple;
struct Table_func_804351E4_de {
    char pad[0x2DF8];
    struct Triple slots[4];
};

extern void func_8043599C_de(s32 first, s32 second, s32 index);

extern int func_804355B4_de();

struct State_func_80434D70_de;
struct State_func_80434D70_de {
    char pad0[4];
    s32 window;
    char pad8[0x50];
    s32 state;
    s32 step;
    s32 next;
    char pad64[8];
    s32 display;
    char pad70[0xB18];
    s32 reset;
    char padb8c[0x226C];
    s32 selected;
};

struct IntegerState3470;
struct IntegerState3470 {
    char pad0[0x3468];
    s32 unk_3468;
    char pad3468[0x346C - 0x3468 - sizeof(s32)];
    s32 unk_346C;
};

struct func_80435898_S1;
typedef struct func_80435898_S1 func_80435898_S1;

extern float D_800E1EF8;

struct PlayerRecAtBA4;
typedef struct PlayerRecAtBA4 PlayerRecAtBA4;

struct State_func_80434D70_de;
typedef struct State_func_80434D70_de State_func_80434D70_de;

extern int func_80435128_de(int player);

extern void func_8043583C_de(void);

struct NameEntryMenu;
struct NameEntryMenu {
    s32 unk0;
    s32 unk4;
    u8 pad8[0x24];
    s32 flags[5];
    Entry_func_80434EF4_de entries[1];
};

struct ObjectState71;
typedef struct ObjectState71 ObjectState71;

struct NameEntryMenu;
typedef struct NameEntryMenu NameEntryMenu;

extern s32 func_80435528_de(void);

extern void func_804350CC_de(s32 index);

struct IntegerState3470;
typedef struct IntegerState3470 IntegerState3470;

extern void func_80434D70_de(s32 player);

extern int func_804355E8_de(void);
#endif
