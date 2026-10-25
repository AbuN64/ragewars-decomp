#ifndef COMMON_CHARACTERSELECTIONROOT_H
#define COMMON_CHARACTERSELECTIONROOT_H
#include "TYPES.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#include "COMMON/LABEL.H"
struct RowMenuRandomizeCharacterPreview;
typedef struct RowMenuRandomizeCharacterPreview RowMenuRandomizeCharacterPreview;

struct RowMenuRandomizeCharacterPreview;
struct RowMenuRandomizeCharacterPreview {
    s32 choice;
    s32 phase;
    s32 costume;
    char padC[4];
    char preview[0x4A8];
    char tail[0x10];
};



struct CharacterSelectionRoot;
struct CharacterSelectionRoot {
    void *screen;
    s32 panel;
    char pad8[8];
    s32 choice;
    s32 phase;
};

extern void Menu_RefreshCharacterUnlocks();

struct PanelRecord;
struct PanelRecord {
    char pad[0x14];
    s32 mode;
    char pad18[8];
    char target;
    char pad21[0x4A7];
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



struct EntryCode8041F1FC;
struct EntryCode8041F1FC {
    void *window;
    char pad4[0x8 - 0x4];
    struct Node_func_8041D134_de *cursor;
    char padC[0x14 - 0xC];
    s32 state;
    char pad18[0x4C8 - 0x18];
};

struct EntryCode8041F1FC;

struct MatchMenuApplySlotValueGfx;
typedef struct MatchMenuApplySlotValueGfx MatchMenuApplySlotValueGfx;

struct StateFlags;

extern void Menu_RandomizeCharacterPreview(s32 player);

struct StateFlags;

struct CharacterData_t;
typedef struct CharacterData_t s_CharacterData;

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

struct CharacterData_t;
struct CharacterData_t {
    s32 id;
    s32 value; /* +0x4: second word of the slot, func_8041F1D8_de */
    char pad8[4];
    f32 scale[4];
    f32 m_fRotY[4];
    CVector3 m_vPos[4];
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
    unsigned char m_IsBot;
    char pad92[4];
};



struct MatchMenuApplySlotValueGfx;

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


extern s32 func_80420AD4_de(void);

extern void func_80420438_de(s32);
#endif
