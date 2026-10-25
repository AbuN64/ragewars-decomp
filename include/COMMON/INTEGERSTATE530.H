#ifndef COMMON_INTEGERSTATE530_H
#define COMMON_INTEGERSTATE530_H
#include "TYPES.H"
#include "COMMON/CALLBACK.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
typedef signed int ( *func_802995D4_de_Callback)(signed int, signed int, signed int, signed int);



extern void func_802998A8_de();


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

struct Entries;
struct Entries {
    void *object;
    s32 field4;
    s32 field8;
    StreamBuffer fieldC;
};

struct Entries;
typedef struct Entries Entries;


struct Element;
typedef struct Element Element;



struct Entry_func_80297EA4_de;
struct Entry_func_80297EA4_de {
    char pad[8];
    ObjRecAtCV1 *unk8;
    char rest[16];
};
struct Entry_func_80297EA4_de;

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


extern void func_80299778_de(s32 id, s32 mode, MenuElementHandler handler);


extern int D_80146E18;

struct Entry_func_80298170_de;
struct Entry_func_80298170_de {
    s32 id;
    struct Element *object;
    s32 context;
};
struct Entry_func_80298170_de;

extern void func_80299468_de();

struct Widget;
struct Widget {
    struct Widget *parent;
    struct Widget *next;
    struct Widget *child;
    s16 id;
    u16 kind;
    u16 field10;
    u16 flags;
    s16 x, y, width, height;
    s16 offsetX, offsetY;
    f32 scaleX, scaleY;
    s32 scaled;
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

extern int D_80146E08;



extern double D_800C5680_de;


struct ScreenManager;



struct ScreenManager;

extern s32 func_802998E0_de(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);

extern unsigned int func_802999E0_de(void);

extern int D_80146E0C;



extern void func_8029958C_de(s32 arg0);

struct ScreenManager;

extern double D_800C5668_de;

extern float D_800C5678_de;


struct EntryCode80296014;
struct ObjRecAt40V1;
struct EntryCode80296014 {
    struct ObjRecAt40V1 *unk0;
    s32 unk4;
    s32 unk8;
    StreamBuffer unkC;
};
struct EntryCode80296014;


extern MenuElementHandler FindKindHandler(s32 kind);

struct ArgsCode80296014;

extern int D_800CD8E0;

struct Entries;

struct Element;
struct Entry_func_802991D4_de;
struct Entry_func_802991D4_de {
    struct Element *primary;
    s32 owner;
    struct Element *focus;
    StreamBuffer data;
};
typedef struct Entry_func_802991D4_de ScreenEntry;
struct Entry_func_802991D4_de;
struct ScreenManager;



extern int D_8014D09C;

extern void func_80299874_de(s32 arg0, s32 arg1);


extern void func_80298FE8_de();

struct ScreenManager;
struct ScreenManager {
    s32 (*callback)(s32 event, s32, s32, s32);
    s32 current;
    s32 lowIndex;
    ScreenEntry *screens;
    s32 (*callback2)(s32);
    s32 limit;
    s32 screenCount;
    struct MenuHandlerEntry handlers[64];
    char pad51C[0x4];
    s32 handled;
    s32 frames;
    s32 focus;
    s32 paging;
    s32 field530;
    s32 field534;
    s32 field538;
    struct Entry_func_80298170_de *cache;
    s32 cacheCount;
};
extern ScreenManager *D_8014D080;

struct ArgsCode80296014;
typedef struct ArgsCode80296014 ArgsCode80296014;


struct Widget;
typedef struct Widget Widget;



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

extern s32 GetMenuScreenOwner(void);
#endif
