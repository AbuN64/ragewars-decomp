#ifndef COMMON_OBJRECAT18V6_H
#define COMMON_OBJRECAT18V6_H
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"
struct MarkerItemMenuRestoreBootMemory;
struct MarkerItemMenuRestoreBootMemory {
    char text[15];
};

struct MarkerItemMenuRestoreBootMemory;
typedef struct MarkerItemMenuRestoreBootMemory MarkerItemMenuRestoreBootMemory;


struct Node802A697C;
typedef struct Node802A697C Node802A697C;

struct State802A6DF8;
struct State802A6DF8 {
    struct State802A6DF8 *prev;
    struct State802A6DF8 *next;
    Node802A697C *node;
    u8 padC[0x10];
    void *object;
    s32 contextId; /* 0x20: companion identifier used by inactive-list lookup */
    f32 value;
    u8 pad28[0xC];
    s32 renderMode; /* 0x34 */
    u8 pad38[4];
    u32 flags;
    struct Node438C *vertices; /* 0x40 */
    u8 pad44[4];
    s32 vertexCount; /* 0x48 */
};

struct List802A6DF8;
struct State802A6DF8;
struct List802A6DF8 {
    struct State802A6DF8 *head;
    struct State802A6DF8 *tail;
    s32 count;
};

struct List802A6DF8;
typedef struct List802A6DF8 List802A6DF8;

struct Lists802A6DF8;
struct Lists802A6DF8 {
    List802A6DF8 active;
    List802A6DF8 inactive;
};


struct Node44;



struct ObjRecAt18V6;

struct Bar;
struct Bar {
    s32 unk0;
    s32 *script;
    s32 state;
    s32 wait;
    f32 x;
    f32 y;
    char pad18[0x20];
    s32 fill;
    void *label;
    s32 enabled; /* 0x40 */
    s32 target;
};

struct Bar;
typedef struct Bar Bar;

struct Hud;
struct Hud {
    Bar bars[2];
};

struct ToggleMenu;
typedef struct ToggleMenu ToggleMenu;



struct CItem;

struct Lists802A6DF8;
typedef struct Lists802A6DF8 Lists802A6DF8;

struct Owner802A6DF8;
struct Owner802A6DF8 {
    u8 pad0[0x751C];
    Lists802A6DF8 lists;
};



struct CItem;
typedef struct CItem CItem;

struct State802A6DF8;
typedef struct State802A6DF8 State802A6DF8;

struct Input_func_802A65E0_de;


struct ObjectState30_2;
typedef struct ObjectState30_2 ObjectState30_2;


struct Sprite;

extern float D_800C5EB0_de;


struct Owner802A6DF8;
typedef struct Owner802A6DF8 Owner802A6DF8;

struct CItem;
struct CItem {
    int unk0;
    int unk4;
    s32 unk8;
    u8 unkC;
    unsigned char unkD;
    char padE[2];
    s32 unk10;
    s32 unk14;
    short unk18;
    int unk1C;
    f32 unk20;
    s32 unk24;
    f32 unk28;
    s32 unk2C;
    s32 unk30;
    s32 unk34;
};





struct CallbackState1C;
typedef struct CallbackState1C CallbackState1C;


struct ObjectLinks14_2;
typedef struct ObjectLinks14_2 ObjectLinks14_2;

struct ObjRecAt18V6;
typedef struct ObjRecAt18V6 ObjRecAt18V6;






struct MenuItem;
typedef struct MenuItem MenuItem;

struct MenuItem;
struct MenuItem {
    s32 active;
    s32 on;
    char pad8[0x10 - 0x8];
    s32 image; /* 0x10: toggle-menu sprite resource */
    s32 imageFrame; /* 0x14: sprite frame */
    s16 bounce;
    s32 startFrame;
    f32 value;
    s32 extra;
    f32 restoreValue;
    s32 restoreExtra;
    s32 (*select)(void *input, struct MenuItem *item);
    s32 (*update)(void *input, struct MenuItem *item);
};

struct ToggleMenu;

struct ObjectLinks7598;
typedef struct ObjectLinks7598 ObjectLinks7598;

extern float D_800C5EA8_de;

struct ObjectLinks7598;


struct ObjectState30_2;

struct Hud;
typedef struct Hud Hud;

struct ObjectLinks14_2;

struct Sprite;
typedef struct Sprite Sprite;

struct Image;






struct State802A6FE0;
typedef struct State802A6FE0 State802A6FE0;



struct EntryItemMenuAdvanceSelection;
struct EntryItemMenuAdvanceSelection {
    char pad0[0x4];
    s32 active;
    char pad8[0x38 - 0x8];
};

struct EntryItemMenuAdvanceSelection;
typedef struct EntryItemMenuAdvanceSelection EntryItemMenuAdvanceSelection;

struct MenuCode802A6AC0;


extern float D_800C5EC4_de;

extern float D_800C5EBC_de;

struct CItemMenu_t;
typedef struct CItemMenu_t CItemMenu;

struct State802A6FE0;





extern float D_800C5EB8_de;


struct CallbackState1C;


struct CItemMenu_t;
struct CItemMenu_t {
    unsigned char unk0;
    unsigned char m_ModePos;
    char pad2[2];
    CItem entries[4];
    short m_LastItemPos;
    short m_ItemAlphaFade;
    int m_FrameCount;
};



extern float D_800C5EC0_de;


struct MenuCode802A6AC0;
typedef struct MenuCode802A6AC0 MenuCode802A6AC0;



struct Input_func_802A65E0_de;
typedef struct Input_func_802A65E0_de Input_func_802A65E0_de;
#endif
