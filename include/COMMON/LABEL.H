#ifndef COMMON_LABEL_H
#define COMMON_LABEL_H
#include "TYPES.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#include "COMMON/OBJECTRECAT28.H"
struct Label;
typedef struct Label Label;





struct MenuFrontendRefreshUnlockedFocusLabel;
typedef struct MenuFrontendRefreshUnlockedFocusLabel MenuFrontendRefreshUnlockedFocusLabel;

struct ObjRecAt480;
struct ObjRecAt480 {
    char pad[0x480];
    CVector3 unk480;
};

struct ProfileStatisticsScreen;
typedef struct ProfileStatisticsScreen ProfileStatisticsScreen;

extern void Focus_RefreshUnlockedFocusLabel();

extern void Focus_RefreshProfileStatistics();

struct Object49C;
struct Object49C {
    char pad[0x49C];
    s32 value;
};

struct ObjRecAt48C;
struct ObjRecAt48C {
    char pad[0x48C];
    CVector3 unk48C;
};

struct ObjRecAt48C;
typedef struct ObjRecAt48C ObjRecAt48C;



struct MenuRecAt108;
typedef struct MenuRecAt108 MenuRecAt108;

struct ObjRecAt480;
typedef struct ObjRecAt480 ObjRecAt480;





struct ObjRecAt498;
struct ObjRecAt498 {
    char pad[0x498];
    s32 unk498;
};




struct ObjRecAt498;
typedef struct ObjRecAt498 ObjRecAt498;



struct NodeFrontendAnimateSlotSelectionMenu;
typedef struct NodeFrontendAnimateSlotSelectionMenu NodeFrontendAnimateSlotSelectionMenu;

struct MenuRecAt8;
struct MenuRecAt8 {
    char pad0[8];
    char model[1];
};

struct ProfileStatisticsScreen;
struct ProfileStatisticsScreen {
    void *handle;
    char pad4[0x10C - 4];
    s32 index;
    char kills[0x32];
    char wins[0x32];
    char deaths[0x32];
    char score[0x32];
    char count[0x32];
};



struct NodeFrontendAnimateSlotSelectionMenu;
struct NodeFrontendAnimateSlotSelectionMenu {
    char pad0[0x10];
    u8 style;
    char pad11[0x14 - 0x11];
    u16 x;
    u16 y;
};

struct Label;
struct MenuFrontendRefreshUnlockedFocusLabel;
struct MenuFrontendRefreshUnlockedFocusLabel {
    char pad0[0xEC];
    ObjRecAtCV1 *focus;
    struct Label *label;
    char padF4[0x18];
    s32 player;
};

struct ListRecAt4C;
typedef struct ListRecAt4C ListRecAt4C;

struct MenuRecAt8;
typedef struct MenuRecAt8 MenuRecAt8;


struct ListRecAt4C;
struct ListRecAt4C {
    char pad[0x48];
    int count;
    void *items[1];
};




struct MenuRecAt108;
struct NodeFrontendAnimateSlotSelectionMenu;
struct MenuRecAt108 {
    char pad0[4];
    void *handle;
    char pad8[0xC8 - 8];
    struct NodeFrontendAnimateSlotSelectionMenu *left;
    char padCC[2];
    u16 leftStep;
    struct NodeFrontendAnimateSlotSelectionMenu *right;
    char padD4[2];
    u16 rightStep;
    s32 state;
    s32 timer;
    s32 fade;
    struct NodeFrontendAnimateSlotSelectionMenu *groupA;
    struct NodeFrontendAnimateSlotSelectionMenu *cursor;
    struct NodeFrontendAnimateSlotSelectionMenu *focus;
    char padF0[4];
    struct NodeFrontendAnimateSlotSelectionMenu *groupB;
    s32 styleStep;
    s32 styleValue;
    struct NodeFrontendAnimateSlotSelectionMenu *groupC;
    char pad104[3];
    u8 alphaStep;
    s32 clock;
};

extern void Focus_UpdateFocusCaption();

extern void SmpOverlay_SetObjectValue(struct Object6C *object, s32 value);
extern void Focus_ShowUnlockedEntries(s32 style);

extern void Model_SetPreviewRenderFlags(struct ObjectB8 *, s32);
#endif
