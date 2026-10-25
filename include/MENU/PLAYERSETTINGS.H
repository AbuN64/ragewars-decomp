#ifndef MENU_PLAYERSETTINGS_H
#define MENU_PLAYERSETTINGS_H
#include "TYPES.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/ITEMRECAT20V1.H"
struct PlayerSettings;
struct PlayerSettings {
    char pad0[0x78];
    s8 active;
    char pad79[6];
    s8 selected;
    char pad80[150 - 0x80];
};

struct StatusView;
struct StatusView {
    char pad[336];
    s8 active;
};

struct Body;
struct Character;
struct Controller;
struct Controls;
struct Ctrl;
struct Held;
struct Mode;
struct Model;
struct Mount;
struct Profile;
struct Record;
struct Rider;
struct Shared_Body;
struct Shared_Hud;
struct Shared_Model;
struct Shared_Profile;
struct Shared_StateInfo;
struct Shared_Voice;
struct StateInfo;
struct TeamInfo;
struct View;
struct ObjRecAt80;

struct Menu_func_8043F37C_eu;
struct Menu_func_8043F37C_eu {
    char pad[0x1C];
    SharedPlayer *player;
    s32 input;
};



struct MenuRecAt20V2;
typedef struct MenuRecAt20V2 MenuRecAt20V2;


struct MenuRecAt20V2;
struct OwnerCode8043DF84;
struct MenuRecAt20V2 {
    char pad0[0x1C];
    struct OwnerCode8043DF84 *owner;
    PakMenuSlot *widget;
};


struct Shape_typemap_114;
struct Shape_typemap_114 {
    unsigned char padding_0[32];
    int field_20;
};

struct Obj1C;
struct Obj1C {
    char pad0[0x5D4];
    s32 unk5D4;
    ObjRecAt80 *unk5D8;
    s32 unk5DC;
    char pad5E0[0x698 - 0x5E0];
    s32 unk698;
    char pad69C[0x858 - 0x69C];
    s32 unk858;
};

struct Handle8043E788;
struct Obj1C;
struct Handle8043E788 {
    char pad0[0x1C];
    struct Obj1C *unk1C;
};



extern float D_800DE330_de;

struct Outer8043E458;
typedef struct Outer8043E458 Outer8043E458;

struct Handle8043E788;
typedef struct Handle8043E788 Handle8043E788;


struct Shared_PakMenu;

struct PlayerSettings;
typedef struct PlayerSettings PlayerSettings;

struct func_8043E5BC_S1;
struct func_8043E5BC_S1 {
    char pad0[0x1C];
    s32 unk1C;
    char pad1C[0x20 - 0x1C - sizeof(s32)];
    s32 unk20;
    char pad20[0x28 - 0x20 - sizeof(s32)];
    s32 unk28;
};

struct StatusView;
typedef struct StatusView StatusView;


struct func_8043E5BC_S1;
typedef struct func_8043E5BC_S1 func_8043E5BC_S1;

struct Target8043E458;
struct Target8043E458 {
    u8 pad0[0x7B];
    s8 unk7B;
};

struct Other8043E458;
struct Target8043E458;
struct Other8043E458 {
    u8 pad0[0x5D8];
    struct Target8043E458 *unk5D8;
};
struct Other8043E458;
struct Outer8043E458;
struct Outer8043E458 {
    u8 pad0[0x1C];
    struct Other8043E458 *unk1C;
};

struct StatusStep;
typedef struct StatusStep StatusStep;

struct StatusStep;
struct StatusStep {
    char pad[150];
};

struct func_8043E318_S2;
struct func_8043E318_S2 {
    char pad0[0x5D8];
    u8 * unk5D8;
};

struct Obj1C;
typedef struct Obj1C Obj1C;

struct FlaggedRosterView;
struct FlaggedRosterView {
    char pad0[0x148];
    u8 flag;
};




struct FlaggedRosterView;
typedef struct FlaggedRosterView FlaggedRosterView;

struct Menu_func_8043F37C_eu;
typedef struct Menu_func_8043F37C_eu Menu_func_8043F37C_eu;





struct Target8043E458;
typedef struct Target8043E458 Target8043E458;

struct func_8043E318_S2;
typedef struct func_8043E318_S2 func_8043E318_S2;
#endif
