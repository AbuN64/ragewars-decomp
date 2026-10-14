#ifndef UNBAKE_SPAN_16E000_CODE_8042F988_H
#define UNBAKE_SPAN_16E000_CODE_8042F988_H
#include "types.h"
#include "common/types_8a8189af7b05.h"
#include "common/types_1dc8418c21db.h"
#include "span_1000/menu_ABBDC_versions.h"
extern int func_80434750_de(void);

struct Name;
struct Name {
    u8 flags[2];
    u8 code[0x14];
    u8 text[0x46 - 0x16];
};

struct PakDisplayName;
typedef struct PakDisplayName PakDisplayName;

struct PakDisplayName;
struct PakDisplayName {
    char text[0x3C];
    char code[70 - 0x3C];
};

struct Name;
typedef struct Name Name;

struct Shared_Player_func_80433F14;
struct Shared_Player_func_80433F14 {
    s32 state;
    s32 sub;
    s32 next;
    union { s32 menu; MenuWidget *menuWidget; };
    char pad10[0x14 - 0x10];
    s32 back;
    union {
        char slots[4][400];
        Record_func_80433914_de records[4];
    };
    union {
        struct { char pad658[0x67E - 0x658]; Name names[15]; };
        PakDisplayName displayNames[15];
    };
    char padA98[0xAD8 - 0xA98];
    s32 slot;
    union {
        char padADC[0xAEC - 0xADC];
        struct { s32 scroll; MenuWidget *labels[3]; };
    };
    union {
        s32 chosen;
        s32 choice;
    };
    s32 used[4];
    union { s32 notes[4]; MenuWidget *nodes[4]; };
    char padB10[0xB28 - 0xB10];
    s32 port;
    s32 record;
    s32 host;
    InventorySlot name[8]; /* 0xB34 */
    s32 nameCursor; /* 0xB44 */
    s32 namePhase; /* 0xB48 */
    s32 nameTimer; /* 0xB4C */
    char padB50[0xB64 - 0xB50];
    s32 profile;
};

struct Shared_Player_func_80433F14;
typedef struct Shared_Player_func_80433F14 Shared_Player_func_80433F14;

struct PakMenuController;
struct PakMenuController {
    s32 field0;
    s32 root;
    char pad8[0x2C - 8];
    s32 selected[4]; /* 0x2C */
    char pad3C[0x54 - 0x3C];
    s32 phase;
    Shared_Player_func_80433F14 players[4];
};

struct Char;
struct Char {
    char c;
    char pad;
};

struct Char;
struct Player_func_80432158_de;
struct Player_func_80432158_de {
    s32 state;
    char pad4[0xB34 - 0x4];
    struct Char name[8];
    s32 cursor;
    char padB48[0xB68 - 0xB48];
};

struct Block_func_80432158_de;
struct Player_func_80432158_de;
struct Block_func_80432158_de {
    char pad0[0x54];
    s32 phase;
    struct Player_func_80432158_de players[4];
};

struct Record_func_804347CC_de;
struct Record_func_804347CC_de {
    char pad0[0xD];
    s8 owner;
    char padE[400 - 0xE];
};

struct Player_func_804347CC_de;
struct Player_func_804347CC_de {
    s32 state; /* 0x0 */
    char pad4[0x10];
    s32 back; /* 0x14 */
    struct Record_func_804347CC_de records[4]; /* 0x18 */
    char pad658[0xB28 - 0x658];
    s32 chosen;
    char padB2C[0xB64 - 0xB2C];
    s32 profile; /* 0xB64 */
};

struct Block_func_804347CC_de;
struct Player_func_804347CC_de;
struct Record_func_804347CC_de;
struct Block_func_804347CC_de {
    char pad0[0x58];
    struct Player_func_804347CC_de players[4];
    char pad2DF8[0x2E28 - 0x2DF8];
    struct Record_func_804347CC_de saved[4];
    s32 savedProfile; /* 0x3468 */
    u32 checksum; /* 0x346C */
};

extern s32 D_800E25A4[];

struct Shared_Item;
struct func_8028469C_S2;
struct Shared_Item {
    char pad0[0x8];
    struct func_8028469C_S2 * label;
    char padC[0x6];
    u16 flags;
    char pad14[0x24];
    struct Shared_Item *next;
};

extern void func_80434B08_de(s32 player);

struct Player_func_8043497C_de;
struct Player_func_8043497C_de {
    char pad0[0x4];
    s32 word4;
    char pad8[0x18 - 0x8];
    char slots[4][400];
    char pad658[0xAEC - 0x658];
    s32 chosen;
    s32 flags[4];
    char padB00[0xB68 - 0xB00];
};

struct Player_func_80434C2C_de;
struct Player_func_80434C2C_de {
    char pad0[0xC];
    void *window;
    char pad10[0xB68 - 0x10];
};

extern void func_80434C2C_de(s32 player);

struct MatchSetupGlobals;
struct MatchSetupGlobals {
    char pad0[0xD0];
    ListScreenRecord status[8];
};

struct Item_func_80434C2C_de;
struct Item_func_80434C2C_de {
    char pad[0x38];
    u8 *text;
};

struct Block_func_80434B08_de;
struct Player_func_804356BC_de;
struct Block_func_80434B08_de {
    char pad0[0x58];
    struct Player_func_804356BC_de players[4];
};

struct Player_func_8042F7A8_de;
struct Player_func_8042F7A8_de {
    char pad0[0x14];
    s32 timer;
    char pad18[0xB68 - 0x18];
};


struct PakMenuController;
typedef struct PakMenuController PakMenuController;

struct Block_func_8042F7A8_de;
struct Player_func_8042F7A8_de;
struct Block_func_8042F7A8_de {
    char pad0[0x8];
    char menu[0x4C - 0x8];
    s32 phase4C;
    char pad50[0x54 - 0x50];
    s32 phase54;
    struct Player_func_8042F7A8_de players[4];
};

struct MatchSetupGlobals;
typedef struct MatchSetupGlobals MatchSetupGlobals;

extern void func_804347CC_de(void);

struct Block_func_80434C2C_de;
struct Player_func_80434C2C_de;
struct Block_func_80434C2C_de {
    char pad0[0x58];
    struct Player_func_80434C2C_de players[4];
};

struct Blk;
typedef struct Blk Blk;

struct RowRecAtBA4;
struct RowRecAtBA4 {
    char pad0[0x58];
    s32 state;
    char pad5C[0xB9C - 0x5C];
    s32 count;
    s32 phase;
    s32 timer;
};

struct Shared_Block;
typedef struct Shared_Block Shared_Block;

struct Shared_Item;
typedef struct Shared_Item Shared_Item;

struct Block_func_80430028_de;
struct Slots_func_8041B7FC_de;
struct Block_func_80430028_de {
    char pad0[4];
    struct Slots_func_8041B7FC_de *slots;
};

struct Shared_Block;
struct Shared_Block {
    void *window;
    union {
        void *list;
        s32 menu;
    };
    char pad8[0x54 - 0x8];
    s32 mode;
    Shared_Player_func_80433F14 players[4];
    s32 source;
    s32 sourceRecord;
    Triple ports[4];
};

struct Item_func_80433BCC_de;
struct func_8028469C_S2;
struct Item_func_80433BCC_de {
    char pad[0x8];
    struct func_8028469C_S2 *label;
};

struct Player_func_80433BCC_de;
struct Player_func_80433BCC_de {
    char pad0[0x18];
    char slots[4][400];
    char pad658[0xAEC - 0x658];
    s32 chosen;
    char padAF0[0xB68 - 0xAF0];
};

extern s32 func_8043497C_de(s32 player);

struct Packet;
struct Packet {
    char data[0x640];
    s32 tail;
    s32 checksum;
    char pad648[0x648 - 0x648];
};

struct Blk;
struct Blk {
    char p0[4];
    s32 unk4;
    char p1[0x24];
    s32 unk2C;
    char p2[0x28];
    s32 unk58;
    char p3[0xAD4];
    s32 unkB30;
    s32 unkB34;
    Resource_func_80419E54_de *unkB38;
    char p4[0x64];
    s32 unkBA0;
    s32 unkBA4;
};

struct Player_func_80434638_de;
struct Player_func_80434638_de {
    s32 first;
    char pad4[0x14 - 0x4];
    s32 second;
    char data[0x640];
    char pad658[0xB64 - 0x658];
    s32 tail;
};

extern void func_80433398_de(s32 arg0);

struct Block_func_80434638_de;
struct Packet;
struct Player_func_80434638_de;
struct Block_func_80434638_de {
    char pad0[0x58];
    struct Player_func_80434638_de players[4];
    char pad2DF8[0x2E28 - 0x2DF8];
    struct Packet packet;
};

struct Block_func_80433BCC_de;
struct Player_func_80433BCC_de;
struct Block_func_80433BCC_de {
    void *window;
    void *list;
    char pad8[0x58 - 0x8];
    struct Player_func_80433BCC_de players[4];
};

struct Block_func_8043497C_de;
struct Player_func_8043497C_de;
struct Triple;
struct Block_func_8043497C_de {
    char pad0[0x58];
    struct Player_func_8043497C_de players[4];
    struct Triple places[4];
};

struct PakMenuTail;
struct Triple;
struct PakMenuTail {
    s32 source;
    s32 sourceRecord;
    struct Triple ports[4];
};

#endif
