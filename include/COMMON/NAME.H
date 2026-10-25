#ifndef COMMON_NAME_H
#define COMMON_NAME_H
#include "TYPES.H"
#include "COMMON/ENTRYRECAT6C.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/MENU_ABBDC_VERSIONS.H"

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
        Profile records[4];
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
/* One pak transfer link: a player's record slot picked as a copy source and its state. */
typedef struct PakMenuLink {
    s32 player;
    s32 entry;
    s32 state;
} PakMenuLink;
/* The 0x648-byte save packet: four profile records, the chosen profile and a CRC over the records. */
typedef struct PakSavePacket {
    Profile saved[4];
    s32 savedProfile; /* 0x640 */
    u32 checksum; /* 0x644 */
} PakSavePacket;
/* The pak and name-entry menu block (Scene memory) D_800E54A4 points to. */
struct PakMenuController {
    union {
        s32 field0;
        void *window;
    };
    union {
        s32 root;
        void *list;
    };
    union {
        u8 menu[0x4C - 0x8]; /* 0x08: the menu panel, passed by address */
        struct {
            char pad8[0x24 - 0x8];
            void *music; /* 0x24 */
            MenuWidget *title; /* 0x28 */
            s32 selected[4]; /* 0x2C */
            MenuWidget *top; /* 0x3C */
            s32 topStep;
            MenuWidget *bottom;
            s32 bottomStep; /* 0x48 */
        };
    };
    s32 ready; /* 0x4C */
    s32 timer; /* 0x50 */
    s32 phase; /* 0x54 */
    Shared_Player_func_80433F14 players[4]; /* 0x58 */
    PakMenuLink links[4]; /* 0x2DF8 */
    PakSavePacket packet; /* 0x2E28 */
    s32 focus; /* 0x3470 */
};
typedef char PakMenuController_links_check[(((u32)&((struct PakMenuController *)0)->links) == 0x2DF8) ? 1 : -1];
typedef char PakMenuController_size_check[(sizeof(struct PakMenuController) == 0x3474) ? 1 : -1];

struct Char;
struct Char {
    char c;
    char pad;
};

struct Char;
struct PlayerCode8042E080;
struct PlayerCode8042E080 {
    s32 state;
    char pad4[0xB34 - 0x4];
    struct Char name[8];
    s32 cursor;
    char padB48[0xB68 - 0xB48];
};

struct Block_func_80432158_de;
struct PlayerCode8042E080;
struct Block_func_80432158_de {
    char pad0[0x54];
    s32 phase;
    struct PlayerCode8042E080 players[4];
};

struct Record_func_804347CC_de;
struct Record_func_804347CC_de {
    char pad0[0xD];
    s8 owner;
    char padE[400 - 0xE];
};

struct PlayerCode8042E080804347CC;
struct PlayerCode8042E080804347CC {
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
struct PlayerCode8042E080804347CC;
struct Record_func_804347CC_de;
struct Block_func_804347CC_de {
    char pad0[0x58];
    struct PlayerCode8042E080804347CC players[4];
    char pad2DF8[0x2E28 - 0x2DF8];
    struct Record_func_804347CC_de saved[4];
    s32 savedProfile; /* 0x3468 */
    u32 checksum; /* 0x346C */
};

extern char *D_800E25A4[];

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


struct PlayerCode8042E0808043497C;
struct PlayerCode8042E0808043497C {
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


struct MatchSetupGlobals;
struct MatchSetupGlobals {
    char pad0[0xD0];
    ListScreenRecord status[8];
};


struct PlayerSlotTable;
struct Player_func_804356BC_de;

struct Player_func_8042F7A8_de;
struct Player_func_8042F7A8_de {
    char pad0[0x14];
    s32 timer;
    char pad18[0xB68 - 0x18];
};


struct PakMenuController;
typedef struct PakMenuController PakMenuController;

struct Data800E54A4Ptr;
struct Player_func_8042F7A8_de;
struct Data800E54A4Ptr {
    char pad0[0x8];
    char menu[0x4C - 0x8];
    s32 phase4C;
    char pad50[0x54 - 0x50];
    s32 phase54;
    struct Player_func_8042F7A8_de players[4];
};

struct MatchSetupGlobals;
typedef struct MatchSetupGlobals MatchSetupGlobals;


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
struct SlotsCode804196C0;
struct Block_func_80430028_de {
    char pad0[4];
    struct SlotsCode804196C0 *slots;
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

struct PlayerCode8042E08080433BCC;
struct PlayerCode8042E08080433BCC {
    char pad0[0x18];
    char slots[4][400];
    char pad658[0xAEC - 0x658];
    s32 chosen;
    char padAF0[0xB68 - 0xAF0];
};


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

struct PlayerCode8042E08080434638;
struct PlayerCode8042E08080434638 {
    s32 first;
    char pad4[0x14 - 0x4];
    s32 second;
    char data[0x640];
    char pad658[0xB64 - 0x658];
    s32 tail;
};


struct Block_func_80434638_de;
struct Packet;
struct PlayerCode8042E08080434638;
struct Block_func_80434638_de {
    char pad0[0x58];
    struct PlayerCode8042E08080434638 players[4];
    char pad2DF8[0x2E28 - 0x2DF8];
    struct Packet packet;
};

struct Block_func_80433BCC_de;
struct PlayerCode8042E08080433BCC;
struct Block_func_80433BCC_de {
    void *window;
    void *list;
    char pad8[0x58 - 0x8];
    struct PlayerCode8042E08080433BCC players[4];
};

struct Block_func_8043497C_de;
struct PlayerCode8042E0808043497C;
struct Triple;
struct Block_func_8043497C_de {
    char pad0[0x58];
    struct PlayerCode8042E0808043497C players[4];
    struct Triple places[4];
};

#endif
