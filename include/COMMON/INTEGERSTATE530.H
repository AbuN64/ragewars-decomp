#ifndef COMMON_INTEGERSTATE530_H
#define COMMON_INTEGERSTATE530_H
#include "TYPES.H"
#include "COMMON/CALLBACK.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"



extern void Smos_ReturnToPreviousScreen();


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




struct Element;
typedef struct Element Element;




extern void Smos_PopScreen();

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


extern void Smos_SetKindEventHandler(s32 id, s32 mode, MenuElementHandler handler);


extern int D_80146E18;

struct Entry_func_80298170_de;
struct Entry_func_80298170_de {
    s32 id;
    struct Element *object;
    s32 context;
};
struct Entry_func_80298170_de;

extern void Smos_DestroyScreenManager();

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

extern s32 Smos_InvokeKindEventHandler(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);

extern unsigned int Smos_GetScreenStackDepth(void);

extern int D_80146E0C;



extern void Smos_SetPagingEnabled(s32 arg0);

struct ScreenManager;

extern double D_800C5668_de;

extern float D_800C5678_de;


struct ObjRecAt40V1;


extern MenuElementHandler FindKindHandler(s32 kind);

struct ArgsCode80296014;

extern int s_smackFormat;


struct Element;
struct EntrySmosSetFocusedElement;
struct EntrySmosSetFocusedElement {
    struct Element *primary;
    s32 owner;
    struct Element *focus;
    StreamBuffer data;
};
typedef struct EntrySmosSetFocusedElement ScreenEntry;
struct EntrySmosSetFocusedElement;
struct ScreenManager;



extern int D_8014D09C;

extern void Smos_SetKindHandlerFlags(s32 arg0, s32 arg1);


extern void Smos_DrawScreenStack();

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
/* D_002A1B50: N64Eng_DispatchNumericWidgetEvent */
extern s32 D_002A1B50(void *, s32, s32, s32, s32);
/* D_002A1BE0: N64Eng_DrawNumericWidgetChildren */
extern void D_002A1BE0();
/* D_0040C5C0: second return stub in func_8040C5B8_de (+8) */
extern s32 D_0040C5C0(void *, s32, s32, s32, s32);
/* D_0040C5C8: func_8040C5C8_de */
extern void D_0040C5C8();
/* D_004125A4: Frontend_DispatchTypedWidgetEvent */
extern s32 D_004125A4(void *, s32, s32, s32, s32);
/* D_00412634: Frontend_DrawGridListCells */
extern void D_00412634();
/* D_00419A4C: SmpFrameAnim_DispatchEvent */
extern s32 D_00419A4C(void *, s32, s32, s32, s32);
/* D_00419ADC: SmpFrameAnim_IgnoreEvent */
extern void D_00419ADC();
/* D_00419F9C: SmpFlicker_DispatchEvent */
extern s32 D_00419F9C(void *, s32, s32, s32, s32);
/* D_0041A02C: SmpFlicker_IgnoreEvent */
extern void D_0041A02C();
/* D_0041A490: SmpSlider_DispatchTransitionEvent */
extern s32 D_0041A490(void *, s32, s32, s32, s32);
/* D_0041A520: SmpSlider_IgnoreFormattedMessage */
extern void D_0041A520();
/* D_0041A724: SmpSlider_DispatchSliderEvent */
extern s32 D_0041A724(void *, s32, s32, s32, s32);
/* D_0041A7B4: func_8041A7B4_de */
extern void D_0041A7B4();
/* D_0041AD7C: SmpButton_DispatchListEvent */
extern s32 D_0041AD7C(void *, s32, s32, s32, s32);
/* D_0041AE0C: func_8041AE0C_de */
extern void D_0041AE0C();
/* D_0041B340: SmpButton_DispatchButtonEvent */
extern s32 D_0041B340(void *, s32, s32, s32, s32);
/* D_0041B3D0: func_8041B3D0_de */
extern void D_0041B3D0();
/* D_0041B970: SmpOverlay_DispatchSlotEvent */
extern s32 D_0041B970(void *, s32, s32, s32, s32);
/* D_0041BA00: func_8041BA00_de */
extern void D_0041BA00();

extern s32 GetMenuScreenOwner(void);
#endif
