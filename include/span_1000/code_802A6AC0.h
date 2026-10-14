#ifndef UNBAKE_SPAN_1000_CODE_802A6AC0_H
#define UNBAKE_SPAN_1000_CODE_802A6AC0_H
#include "types.h"
#include "common/types_1dc8418c21db.h"
struct Marker_func_802A71C0_de;
struct Marker_func_802A71C0_de {
    char text[15];
};

struct Marker_func_802A71C0_de;
typedef struct Marker_func_802A71C0_de Marker_func_802A71C0_de;

extern void func_802A7654_de(void);

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

struct func_802A7164_S4;
typedef struct func_802A7164_S4 func_802A7164_S4;

extern void func_802A6174_de(void *arg0, void *arg1);

struct func_802A72F4_S1;
typedef struct func_802A72F4_S1 func_802A72F4_S1;

struct func_802A72AC_S2;
typedef struct func_802A72AC_S2 func_802A72AC_S2;

struct ObjRecAt18V6;
struct ObjRecAt18V6 {
    char pad0[0x8];
    s32 unk8;
    char pad8[0xC - 0x8 - sizeof(s32)];
    f32 unkC;
    char padC[0x10 - 0xC - sizeof(f32)];
    s32 unk10;
    char pad10[0x14 - 0x10 - sizeof(s32)];
    s32 unk14;
    char pad14[0x18 - 0x14 - sizeof(s32)];
    s32 unk18;
};

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
    s32 label;
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

extern void func_802A7180_de(void *arg0, void *arg1);

struct Frame_func_802A7660_de;
struct Frame_func_802A7660_de {
    char pad0[0x2A0];
    f32 height;
};

extern void func_802A7168_de(void *arg0);

struct Lists802A6DF8;
typedef struct Lists802A6DF8 Lists802A6DF8;

struct Owner802A6DF8;
struct Owner802A6DF8 {
    u8 pad0[0x751C];
    Lists802A6DF8 lists;
};

struct func_802A72AC_S2;
struct func_802A72AC_S2 {
    char pad0[0x4];
    void * unk4;
    char pad4[0xA8 - 0x4 - sizeof(void*)];
    f32 unkA8;
    char padA8[0xAC - 0xA8 - sizeof(f32)];
    f32 unkAC;
};

extern void func_802A62BC_de(void *arg0);

struct func_802A6AC0_S2;
struct func_802A6AC0_S2 {
    char pad0[0x4];
    f32 unk4;
    char pad4[0x8 - 0x4 - sizeof(f32)];
    f32 unk8;
    char pad8[0xC - 0x8 - sizeof(f32)];
    f32 unkC;
    char padC[0x10 - 0xC - sizeof(f32)];
    f32 unk10;
};

struct EntryRecAt34;
typedef struct EntryRecAt34 EntryRecAt34;

struct State802A6DF8;
typedef struct State802A6DF8 State802A6DF8;

struct Input_func_802A65E0_de;
struct Input_func_802A65E0_de {
    char pad0[0x5DC];
    struct View *view; /* 0x5DC: viewport owner used by the toggle-menu renderer */
    char pad5E0[0x6AC - 0x5E0];
    s32 held;
    s32 pressed;
};

struct func_802A7FA8_S4;
typedef struct func_802A7FA8_S4 func_802A7FA8_S4;

struct ObjectState30_2;
typedef struct ObjectState30_2 ObjectState30_2;

struct func_802A7440_S2;
typedef struct func_802A7440_S2 func_802A7440_S2;

struct Sprite;
struct Sprite {
    s32 format;
    char *data;
    s32 field8;
    s32 fieldC;
    f32 width;
    f32 height;
    f32 extentX;
    f32 extentY;
    f32 step;
};

extern float D_800C5EB0_de;

struct func_802A7164_S1;
typedef struct func_802A7164_S1 func_802A7164_S1;

struct Owner802A6DF8;
typedef struct Owner802A6DF8 Owner802A6DF8;

struct EntryRecAt34;
struct EntryRecAt34 {
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

struct func_802A7FA8_S4;
struct func_802A7FA8_S4 {
    s32 unk0;
    char pad0[0x8 - 0x0 - sizeof(s32)];
    s32 unk8;
    char pad8[0xC - 0x8 - sizeof(s32)];
    u8 unkC;
    char padC[0xD - 0xC - sizeof(u8)];
    u8 unkD;
    char padD[0x10 - 0xD - sizeof(u8)];
    s32 unk10;
    char pad10[0x14 - 0x10 - sizeof(s32)];
    s32 unk14;
    char pad14[0x28 - 0x14 - sizeof(s32)];
    f32 unk28;
    char pad28[0x2C - 0x28 - sizeof(f32)];
    s32 unk2C;
    char pad2C[0x30 - 0x2C - sizeof(s32)];
    s32 unk30;
    char pad30[0x34 - 0x30 - sizeof(s32)];
    s32 unk34;
};

struct func_802A7FA8_S3;
typedef struct func_802A7FA8_S3 func_802A7FA8_S3;

struct func_802A8158_S1;
typedef struct func_802A8158_S1 func_802A8158_S1;

struct func_802A8158_S1;
struct func_802A8158_S1 {
    int unk0;
    char pad0[0x4 - 0x0 - sizeof(int)];
    int unk4;
    char pad4[0xD - 0x4 - sizeof(int)];
    char unkD;
    char padD[0x18 - 0xD - sizeof(char)];
    short unk18;
    char pad18[0x1C - 0x18 - sizeof(short)];
    int unk1C;
};

struct CallbackState1C;
typedef struct CallbackState1C CallbackState1C;

struct func_802A7164_S4;
struct func_802A7164_S4 {
    char pad0[0x8];
    void * unk8;
    char pad8[0x3C - 0x8 - sizeof(void*)];
    u32 unk3C;
};

struct ObjectLinks14_2;
typedef struct ObjectLinks14_2 ObjectLinks14_2;

struct ObjRecAt18V6;
typedef struct ObjRecAt18V6 ObjRecAt18V6;

struct func_802A7480_S2;
struct func_802A7480_S2 {
    char pad0[0x4];
    char * unk4;
    char pad4[0x34 - 0x4 - sizeof(char*)];
    s32 unk34;
    char pad34[0x3C - 0x34 - sizeof(s32)];
    s32 unk3C;
    char pad3C[0x48 - 0x3C - sizeof(s32)];
    s32 unk48;
};

struct func_802A7FA8_S1;
typedef struct func_802A7FA8_S1 func_802A7FA8_S1;

struct func_802A72AC_S1;
struct func_802A72AC_S1 {
    char pad0[0x40];
    void * unk40;
    char pad40[0x4C - 0x40 - sizeof(void*)];
    f32 unk4C;
};

struct func_802A72F4_S1;
struct func_802A72F4_S1 {
    char pad0[0x34];
    s32 unk34;
    char pad34[0x3C - 0x34 - sizeof(s32)];
    s32 unk3C;
    char pad3C[0x48 - 0x3C - sizeof(s32)];
    s32 unk48;
};

struct func_802A6D28_S2;
struct func_802A6D28_S2 {
    char pad0[0x4];
    void * unk4;
    char pad4[0x48 - 0x4 - sizeof(void*)];
    s32 unk48;
};

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
struct ToggleMenu {
    u8 state;
    u8 timer;
    MenuItem items[4];
    u16 selected;
    s16 blink;
    s32 frame;
};

struct ObjectLinks7598;
typedef struct ObjectLinks7598 ObjectLinks7598;

extern float D_800C5EA8_de;

struct ObjectLinks7598;
struct ObjectLinks7598 {
    char pad0[0x7588];
    char unk_7588;
    char pad7588[0x7594 - 0x7588 - sizeof(char)];
    void * unk_7594;
};

struct func_802A7FA8_S1;
struct func_802A7FA8_S1 {
    char pad0[0x4];
    s32 unk4;
    char pad4[0x10 - 0x4 - sizeof(s32)];
    u8 unk10;
};

struct ObjectState30_2;
struct ObjectState30_2 {
    unsigned char padding_0[4];
    s32 unk_4;
    unsigned char padding_8[16];
    s16 unk_18;
    unsigned char padding_1A[2];
    s32 unk_1C;
    f32 unk_20;
    s32 unk_24;
    f32 unk_28;
    s32 unk_2C;
};

struct Hud;
typedef struct Hud Hud;

struct ObjectLinks14_2;
struct ObjectLinks14_2 {
    char pad0[0x4];
    void * next;
    char pad4[0x8 - 0x4 - sizeof(void*)];
    f32 unk_8;
    char pad8[0xC - 0x8 - sizeof(f32)];
    f32 unk_C;
    char padC[0x10 - 0xC - sizeof(f32)];
    s32 unk_10;
};

struct Sprite;
typedef struct Sprite Sprite;

struct Image;
extern void func_802A6068_de(struct Image * image, struct Image * texture, Sprite * sprite);

struct func_802A6D28_S1;
struct func_802A6D28_S1 {
    char pad0[0x94E0];
    IntrusiveList slots[10];
    IntrusiveList free;
};

struct func_802A6F8C_S1;
struct func_802A6F8C_S1 {
    char pad0[0x14];
    s32 unk14;
    char pad14[0x34 - 0x14 - sizeof(s32)];
    s32 unk34;
};

struct func_802A6D28_S1;
typedef struct func_802A6D28_S1 func_802A6D28_S1;

struct func_802A6F8C_S1;
typedef struct func_802A6F8C_S1 func_802A6F8C_S1;

struct Frame_func_802A7660_de;
typedef struct Frame_func_802A7660_de Frame_func_802A7660_de;

struct func_802A6AC0_S2;
typedef struct func_802A6AC0_S2 func_802A6AC0_S2;

struct State802A6FE0;
typedef struct State802A6FE0 State802A6FE0;

struct func_802A7394_S1;
struct func_802A7394_S1 {
    char pad0[0x1C];
    void * unk1C;
    char pad1C[0x24 - 0x1C - sizeof(void*)];
    f32 unk24;
};

struct func_802A7394_S1;
typedef struct func_802A7394_S1 func_802A7394_S1;

struct Entry_func_802A70D4_de;
struct Entry_func_802A70D4_de {
    char pad0[0x4];
    s32 active;
    char pad8[0x38 - 0x8];
};

struct Entry_func_802A70D4_de;
typedef struct Entry_func_802A70D4_de Entry_func_802A70D4_de;

struct Menu_func_802A70D4_de;
struct Menu_func_802A70D4_de {
    Entry_func_802A70D4_de entries[4];
    char padE0[0xE4 - 0xE0];
    u16 cursor;
};

struct func_802A7440_S2;
struct func_802A7440_S2 {
    char pad0[0x4];
    void * unk4;
    char pad4[0x1C - 0x4 - sizeof(void*)];
    s32 unk1C;
    char pad1C[0x20 - 0x1C - sizeof(s32)];
    s32 unk20;
};

extern float D_800C5EC4_de;

extern float D_800C5EBC_de;

struct RecordRecAtE8;
typedef struct RecordRecAtE8 RecordRecAtE8;

struct State802A6FE0;
struct State802A6FE0 {
    u8 pad0[8];
    Node802A697C *node;
    u8 padC[0x10];
    void *object;
    u8 pad20[4];
    f32 value;
    u8 pad28[0x14];
    u32 flags;
};

extern void func_802A5AD0_de(void *arg0);

struct func_802A7480_S2;
typedef struct func_802A7480_S2 func_802A7480_S2;

struct func_802A6D28_S2;
typedef struct func_802A6D28_S2 func_802A6D28_S2;

extern void func_802A5B84_de(s32 arg0, s32 arg1, s32 arg2, s32 arg3, f32 arg4);

extern float D_800C5EB8_de;

struct func_802A72AC_S1;
typedef struct func_802A72AC_S1 func_802A72AC_S1;

struct CallbackState1C;
struct CallbackState1C {
    unsigned char padding_0[24];
    void (*callback)(void *);
};

extern void func_802A5B4C_de(f32 *arg0);

struct RecordRecAtE8;
struct RecordRecAtE8 {
    unsigned char unk0;
    unsigned char unk1;
    char pad2[2];
    EntryRecAt34 entries[4];
    short unkE4;
    short unkE6;
    int unkE8;
};

struct func_802A7164_S1;
struct func_802A7164_S1 {
    char pad0[0x8];
    f32 unk8;
    char pad8[0x10 - 0x8 - sizeof(f32)];
    f32 unk10;
    char pad10[0x1C - 0x10 - sizeof(f32)];
    f32 unk1C;
    char pad1C[0xB0 - 0x1C - sizeof(f32)];
    void * unkB0;
};

extern void func_802A754C_de(void);

extern float D_800C5EC0_de;

struct func_802A7480_S1;
struct func_802A7480_S1 {
    char pad0[0x7528];
    char * unk7528;
};

struct Menu_func_802A70D4_de;
typedef struct Menu_func_802A70D4_de Menu_func_802A70D4_de;

struct func_802A7480_S1;
typedef struct func_802A7480_S1 func_802A7480_S1;

struct func_802A7FA8_S3;
struct func_802A7FA8_S3 {
    char pad0[0xE4];
    s16 unkE4;
};

struct Input_func_802A65E0_de;
typedef struct Input_func_802A65E0_de Input_func_802A65E0_de;

#endif
