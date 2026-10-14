#ifndef UNBAKE_SPAN_16E000_CODE_8041F1FC_H
#define UNBAKE_SPAN_16E000_CODE_8041F1FC_H
#include "types.h"
#include "common/types_8a8189af7b05.h"
#include "common/types_1dc8418c21db.h"
#include "resident_event_handler.h"
#include "span_16E000/code_8041BEA8.h"
struct Row_func_80420850_de;
typedef struct Row_func_80420850_de Row_func_80420850_de;

struct Row_func_80420850_de;
struct Row_func_80420850_de {
    s32 choice;
    s32 phase;
    s32 costume;
    char padC[4];
    char preview[0x4A8];
    char tail[0x10];
};

struct Selection_func_80420850_de;
struct Selection_func_80420850_de {
    void *screen;
    char pad4[0xC];
    Row_func_80420850_de rows[8];
};

struct Selection_func_80420850_de;
typedef struct Selection_func_80420850_de Selection_func_80420850_de;

struct CharacterSelectionRoot;
struct CharacterSelectionRoot {
    void *screen;
    s32 panel;
    char pad8[8];
    s32 choice;
    s32 phase;
};

extern void func_8041FF2C_de();

struct PanelRecord;
struct PanelRecord {
    char pad[0x14];
    s32 mode;
    char pad18[8];
    char target;
    char pad21[0x4A7];
};

struct EntryRecAt14V2;
struct EntryRecAt14V2 {
    char pad[0x14];
    s32 state;
    char pad18[0x4C8 - 0x18];
};

struct RosterSlot;
typedef struct RosterSlot RosterSlot;

struct EntryRecAt14V1;
struct EntryRecAt14V1 {
    char pad[0x10];
    int target;
    int active;
    char pad18[0x4C8 - 0x18];
};

struct SelectEntry;
struct SelectEntry {
    int choice;
    int state;
    unsigned char variant[4];
    char pad0C[4];
    char preview[0x4A8];
    int confirmed;
    char pad4BC[0xC];
};

struct SelectEntry;
typedef struct SelectEntry SelectEntry;

struct SelectMenu;
struct SelectMenu {
    void *screen;
    void *menu;
    char pad08[8];
    SelectEntry entries[8];
};


struct Entry_func_80420308_de;
struct Entry_func_80420308_de {
    void *window;
    char pad4[0x8 - 0x4];
    struct Node_func_8041D134_de *cursor;
    char padC[0x14 - 0xC];
    s32 state;
    char pad18[0x4C8 - 0x18];
};

struct Entry_func_80420308_de;
struct Screen_func_80420308_de;
struct Screen_func_80420308_de {
    struct Entry_func_80420308_de entries[4];
};

struct Match_func_80420618_de;
typedef struct Match_func_80420618_de Match_func_80420618_de;

struct Row;
struct StateFlags;
struct Row {
    char pad0[0xC];
    struct StateFlags cells[6];
};

extern void func_80420850_de(s32 player);

struct RowRecAt18;
struct StateFlags;
struct RowRecAt18 {
    char pad0[0xC];
    struct StateFlags cells[3];
    struct StateFlags options[3];
};

struct Choice;
typedef struct Choice Choice;

struct Panel_func_8041FC50_de;
struct Panel_func_8041FC50_de {
    char pad0[8];
    s32 player;
    s32 state;
    char pad10[8];
    char body[0x4A8];
    s32 flash;
    char pad4C4[4];
};

struct Panel_func_8041FC50_de;
struct FourPlayerScreen;
struct FourPlayerScreen {
    char pad0[8];
    struct Panel_func_8041FC50_de panels[4];
    char pad1328[0x10];
    s32 state;
};

struct Choice;
struct Choice {
    s32 id;
    char pad4[8];
    f32 scale[4];
    f32 angle[4];
    Vec3 position[4];
    s32 flags[4];
    char pad6C[4];
};

struct EntryRecAt14V1;
typedef struct EntryRecAt14V1 EntryRecAt14V1;

struct CharacterScreenCell;
struct CharacterScreenCell {
    u16 id;
    u16 pad;
};

struct CharacterSelectionRoot;
typedef struct CharacterSelectionRoot CharacterSelectionRoot;

struct SelectMenu;
typedef struct SelectMenu SelectMenu;

struct State_func_80420C10_de;
typedef struct State_func_80420C10_de State_func_80420C10_de;

struct PanelRecord;
typedef struct PanelRecord PanelRecord;

struct Entry_func_804201A4_de;
struct Entry_func_804201A4_de {
    void *window;
    char pad4[0x10 - 0x4];
    s32 kind;
    char pad14[0x18 - 0x14];
    s32 choice;
    char pad1C[0x4C8 - 0x1C];
};

struct Entry_func_804201A4_de;
struct Screen_func_804201A4_de;
struct Screen_func_804201A4_de {
    struct Entry_func_804201A4_de entries[4];
};

extern s32 func_8041F1D8_de(s32 key);

struct CharacterScreenCell;
typedef struct CharacterScreenCell CharacterScreenCell;

struct RosterSlot;
struct RosterSlot {
    char pad00[0x78];
    unsigned char active;
    char pad79[6];
    unsigned char player;
    unsigned char kind;
    unsigned char variant;
    char pad82[0xF];
    unsigned char locked;
    char pad92[4];
};

extern s32 func_80420D90_de(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);

struct SlotRecAt4;
struct SlotRecAt4 {
    s32 key;
    s32 value;
    char pad[0x70 - 8];
};

struct Match_func_80420618_de;
struct Match_func_80420618_de {
    char pad00[0xD];
    unsigned char mode;
    char pad0E[0xC2];
    RosterSlot slots[8];
};

struct State_func_80420C10_de;
struct State_func_80420C10_de {
    s32 a;
    s32 unk4;
    char p0[8];
    s32 unk10;
    s32 unk14;
    char p1[0x1320];
    s32 unk1338;
    s32 unk133C;
    char p2[0x14];
    s32 unk1354;
};

struct RowRecAtA;
struct RowRecAtA {
    s16 pad0;
    s16 frame;
    s16 pad4;
    u16 cursor;
    s16 pad8;
    u16 prompt;
    char padC[36 - 0xC];
};

extern s32 func_80420AD4_de(void);

extern void func_80420438_de(s32);

#endif
