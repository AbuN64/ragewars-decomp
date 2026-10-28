#ifndef COMMON_RECRECAT4_H
#define COMMON_RECRECAT4_H
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
struct RecRecAt4;
typedef struct RecRecAt4 RecRecAt4;


struct RecRecAt4;
struct RecRecAt4 {
    char pad0[2];
    s16 unk2;
    s16 unk4;
    char pad6[0x96 - 6];
};

struct CompactOptionsCommitContext;
typedef struct CompactOptionsCommitContext CompactOptionsCommitContext;

struct StateFrontendHandlePlayModeShortcut;
struct StateFrontendHandlePlayModeShortcut {
    void *first;
    char pad4[0x18 - 4];
    s32 value;
};



struct OptionsCommitContext;
struct OptionsCommitContext {
    void *menu;
    void *title;
    void * unk_8;
    void * unk_C;
    void * unk_10;
    void * unk_14;
    s32 reserved18[2];
    s32 value;
    s32 state;
};







struct CellRecAt1A;
struct MenuFrontendUpdatePlayModeMenu;
struct StateFrontendUpdatePlayModeMenu;
struct StateFrontendUpdatePlayModeMenu {
    struct MenuFrontendUpdatePlayModeMenu *menu;
    char pad4[0x8 - 0x4];
    struct CellRecAt1A *list;
    s32 opening;
    char pad10[0x14 - 0x10];
    s32 delay;
    s32 target;
};


struct TabOptionsCommitContext;
struct TabOptionsCommitContext {
    char pad0[0x50];
    void * unk_50;
    void * unk_54;
    void * unk_58;
};

struct TabOptionsCommitContext;
typedef struct TabOptionsCommitContext TabOptionsCommitContext;

struct MessageScreen;
struct MessageScreen {
    char pad0[0x1C];
    s32 shown;
    char pad20[0x30 - 0x20];
    s32 mode;
    s32 next_mode;
    char pad38[0x44 - 0x38];
    void *window;
    char pad48[0x4C - 0x48];
    void *second_window;
    char pad50[0x60 - 0x50];
    s32 timer;
};


struct CompactOptionsCommitContext;
struct CompactOptionsCommitContext {
    void * unk_0;
    void * unk_4;
    void * unk_8;
};


struct OptionsCommitContext;
typedef struct OptionsCommitContext OptionsCommitContext;


extern int D_800E1AFC_de[];
extern int D_800E1B7C[];
extern int D_800E1ACC_de[];




extern void func_8042201C_de();

extern s32 ScenarioSetup_IsCupSelected(void);
enum MatchEnd {
    MATCH_END_TIME_UP,
    MATCH_END_SCORE_LIMIT,
    MATCH_END_TAG_LIMIT,
    MATCH_END_POINT_TARGET
};
extern f32 D_800DDB08_de[];
extern f32 D_800DDB10;
extern void Frontend_DrawResultSelectionPreview(void);

extern void Menu_SetOptionsSceneSelection(s32);

extern char g_characterAndTimeFormatText[];
extern char D_800DD9C8[];
extern char D_800DD9D0_de[];
extern void Random_ReplaceTextOccurrences(char *, char *, char *);


extern s32 Control_IsControllerConnected(s32);
#endif
