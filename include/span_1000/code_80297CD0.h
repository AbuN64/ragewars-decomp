#ifndef UNBAKE_SPAN_1000_CODE_80297CD0_H
#define UNBAKE_SPAN_1000_CODE_80297CD0_H
#include "types.h"
#include "span_1000/code_80299DB4.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8fd754e1e915.h"
#include "resident_event_handler.h"
typedef signed int ( *func_802995D4_de_Callback)(signed int, signed int, signed int, signed int);

struct func_8029A9F4_S1;
struct func_8029A9F4_S1 {
    char pad0[0x528];
    unsigned int unk528;
};

struct IntegerState530;
typedef struct IntegerState530 IntegerState530;

extern void func_802998A8_de();

struct State_func_80297EA4_de;
typedef struct State_func_80297EA4_de State_func_80297EA4_de;

typedef s32 (*MenuElementHandler)(void *element, s32 event, s32 arg2, s32 arg3, s32 arg4);

struct Element;
struct NodeRecAt12;
struct Element {
    char pad0[4];
    struct NodeRecAt12 *left; /* 0x4 */
    struct NodeRecAt12 *right; /* 0x8 */
    s16 id;
    u16 kind;
    u16 field10;
    u16 flags;
    u8 unobserved14[0x3C - 0x14];
    s32 linked_id;
    MenuElementHandler handler;
};

struct ScreenManager;
typedef struct ScreenManager ScreenManager;

struct Entry_func_80298ECC_de;
struct Entry_func_80298ECC_de {
    void *object;
    s32 field4;
    s32 field8;
    StreamBuffer fieldC;
};

struct Entry_func_80298ECC_de;
typedef struct Entry_func_80298ECC_de Entry_func_80298ECC_de;

struct Manager_func_80298FE8_de;
struct Manager_func_80298FE8_de {
    s32 field0;
    s32 index;
    s32 lowIndex;
    Entry_func_80298ECC_de *entries;
    s8 pad10[0x524];
    s32 field534;
    s32 field538;
};

struct Element;
typedef struct Element Element;

struct func_8029A9F4_S1;
typedef struct func_8029A9F4_S1 func_8029A9F4_S1;

extern void func_80297DBC_de();

struct Entry_func_80297EA4_de;
struct Entry_func_80297EA4_de {
    char pad[8];
    ObjRecAtCV1 *unk8;
    char rest[16];
};
struct Entry_func_80297EA4_de;
struct State_func_80297EA4_de;
struct State_func_80297EA4_de {
    int (*unk0)(int,int,int,int);
    int unk4;
    int unk8;
    struct Entry_func_80297EA4_de *unkC;
    char pad[0x510];
    int unk520;
    char pad2[12];
    int unk530;
};

extern void func_80298ECC_de();

/* Draw providers use several existing aggregate declarations. Registration
 * stores these functions; this type does not prescribe a call signature. */
typedef void (*MenuDrawHandler)();

struct MenuHandlerEntry {
    s32 id;
    MenuElementHandler default_handler;
    MenuElementHandler override_handler;
    MenuDrawHandler draw_handler;
    s32 flags;
};

struct MenuHandlerTable;
struct MenuHandlerTable {
    u8 pad0[0x1C];
    struct MenuHandlerEntry handlers[64];
};

extern void func_80299778_de(s32 id, s32 mode, MenuElementHandler handler);

extern void func_80297FA0_de(s32 screenCount, s32 value);

extern int D_80146E18;

struct Entry_func_80298170_de;
struct Entry_func_80298170_de {
    s32 id;
    struct Element *object;
    s32 context;
};
struct CacheRecAt540;
struct Entry_func_80298170_de;
struct CacheRecAt540 {
    char pad0[0x53C];
    struct Entry_func_80298170_de *entries;
    s32 count;
};

extern void func_80299468_de();

struct Widget;
struct Widget {
    char pad0[0xC];
    s16 id;
    char padE[4];
    u16 flags;
    char pad14[0x2C - 0x14];
    struct Widget *links[4];
};

struct Screen;
struct Widget;
struct Screen {
    char pad0[8];
    struct Widget *focus;
    char padC[0x1C - 0xC];
};
struct Screen;
struct Ui;
struct Ui {
    s32 pad0;
    s32 current;
    s32 pad8;
    struct Screen *screens;
};

extern int D_80146E08;

struct Ui;
typedef struct Ui Ui;

struct Manager_func_802995D4_de;
struct Manager_func_802995D4_de {
    func_802995D4_de_Callback callback;
    s32 index;
    s32 lowIndex;
    Entry_func_80298ECC_de *entries;
    char pad10[0x510];
    s32 dispatching;
    s32 pad524;
    s32 blockedValue;
};

extern double D_800C5680_de;

typedef void ( *func_80299468_de_Callback)(signed int, signed int, signed int, signed int);

struct ScreenManager;

struct IntegerState530;
struct IntegerState530 {
    unsigned char padding_0[1324];
    s32 unk_52C;
};

struct CacheRecAt540;
typedef struct CacheRecAt540 CacheRecAt540;

struct ScreenManager;

extern s32 func_802998E0_de(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);

extern unsigned int func_802999E0_de(void);

extern int D_80146E0C;

struct Manager_func_80298FE8_de;
typedef struct Manager_func_80298FE8_de Manager_func_80298FE8_de;

struct func_8029A8E0_S1;
struct func_8029A8E0_S1 {
    char pad0[0xE];
    u16 unkE;
};

extern void func_8029958C_de(s32 arg0);

struct ScreenManager;

extern double D_800C5668_de;

extern float D_800C5678_de;

extern void func_80296CD0_de(s32 direction);

struct Entry_func_80297DBC_de;
struct ObjRecAt40V1;
struct Entry_func_80297DBC_de {
    struct ObjRecAt40V1 *unk0;
    s32 unk4;
    s32 unk8;
    StreamBuffer unkC;
};
struct Entry_func_80297DBC_de;
struct State_func_80297DBC_de;
struct State_func_80297DBC_de {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    struct Entry_func_80297DBC_de *unkC;
    s32 (*unk10)(s32);
};

struct MenuHandlerTable;
typedef struct MenuHandlerTable MenuHandlerTable;

extern void func_802982C4_de(s32 id, MenuElementHandler event_handler, MenuDrawHandler draw_handler, s32 flags);
extern MenuElementHandler func_802997E4_de(s32 kind);

struct Args_func_80298FE8_de;
struct Args_func_80298FE8_de {
    s32 word0;
    s32 word4;
    s32 word8;
    f32 wordC;
    f32 word10;
    u8 byte14;
    u8 pad15[3];
    s32 word18;
    s32 word1C;
    s32 word20;
    s32 word24;
};

extern int D_800CD8E0;

struct Entry_func_80298ECC_de;
struct Manager_func_80298ECC_de;
struct Manager_func_80298ECC_de {
    s32 field0;
    s32 index;
    s32 lowIndex;
    struct Entry_func_80298ECC_de *entries;
};

struct Element;
struct Entry_func_802991D4_de;
struct Entry_func_802991D4_de {
    struct Element *primary;
    s32 owner;
    struct Element *focus;
    char padC[0x10];
};
struct Entry_func_802991D4_de;
struct ScreenManager;

struct Manager_func_80298ECC_de;
typedef struct Manager_func_80298ECC_de Manager_func_80298ECC_de;

struct State_func_80297DBC_de;
typedef struct State_func_80297DBC_de State_func_80297DBC_de;

extern int D_8014D09C;

extern void func_80299874_de(s32 arg0, s32 arg1);

struct func_8029A7E4_S1;
struct func_8029A7E4_S1 {
    char pad0[0x1C];
    int unk1C;
    char pad1C[0x20 - 0x1C - sizeof(int)];
    Rec_func_8024C92C_de unk20;
};

extern void func_80298FE8_de();

struct ScreenManager;
struct ScreenManager {
    s32 (*callback)(s32 event, s32, s32, s32);
    s32 current;
    s32 lowIndex;
    struct Entry_func_802991D4_de *screens;
    s32 value;
    s32 limit;
    s32 screenCount;
    Rec_func_8024C92C_de slots[64];
    char pad51C[0x4];
    s32 handled;
    s32 frames;
    s32 focus;
    s32 paging;
    s32 field530;
    s32 field534;
    s32 field538;
    void *cache;
    s32 cacheCount;
};

struct Args_func_80298FE8_de;
typedef struct Args_func_80298FE8_de Args_func_80298FE8_de;

struct Manager_func_802995D4_de;
typedef struct Manager_func_802995D4_de Manager_func_802995D4_de;

struct Widget;
typedef struct Widget Widget;

struct func_8029A8E0_S1;
typedef struct func_8029A8E0_S1 func_8029A8E0_S1;

struct func_8029A7E4_S1;
typedef struct func_8029A7E4_S1 func_8029A7E4_S1;

/* Callable low-address aliases of the native code providers. The cartridge
 * registers these entry addresses, not overlay file ranges or data objects. */
/* D_002A1B50: func_802A1B50_de */
extern s32 D_002A1B50(void *, s32, s32, s32, s32);
/* D_002A1BE0: func_802A1BE0_de */
extern void D_002A1BE0();
/* D_0040C5C0: second return stub in func_8040C5B8_de (+8) */
extern s32 D_0040C5C0(void *, s32, s32, s32, s32);
/* D_0040C5C8: func_8040C5C8_de */
extern void D_0040C5C8();
/* D_004125A4: func_804125A4_de */
extern s32 D_004125A4(void *, s32, s32, s32, s32);
/* D_00412634: func_80412634_de */
extern void D_00412634();
/* D_00419A4C: func_80419A4C_de */
extern s32 D_00419A4C(void *, s32, s32, s32, s32);
/* D_00419ADC: func_80419ADC_de */
extern void D_00419ADC();
/* D_00419F9C: func_80419F9C_de */
extern s32 D_00419F9C(void *, s32, s32, s32, s32);
/* D_0041A02C: func_8041A02C_de */
extern void D_0041A02C();
/* D_0041A490: func_8041A490_de */
extern s32 D_0041A490(void *, s32, s32, s32, s32);
/* D_0041A520: func_8041A520_de */
extern void D_0041A520();
/* D_0041A724: func_8041A724_de */
extern s32 D_0041A724(void *, s32, s32, s32, s32);
/* D_0041A7B4: func_8041A7B4_de */
extern void D_0041A7B4();
/* D_0041AD7C: func_8041AD7C_de */
extern s32 D_0041AD7C(void *, s32, s32, s32, s32);
/* D_0041AE0C: func_8041AE0C_de */
extern void D_0041AE0C();
/* D_0041B340: func_8041B340_de */
extern s32 D_0041B340(void *, s32, s32, s32, s32);
/* D_0041B3D0: func_8041B3D0_de */
extern void D_0041B3D0();
/* D_0041B970: func_8041B970_de */
extern s32 D_0041B970(void *, s32, s32, s32, s32);
/* D_0041BA00: func_8041BA00_de */
extern void D_0041BA00();

extern s32 func_80299958_de(void);
extern void func_8029764C_de(s32,s32,s32,void *,s32);

#endif
