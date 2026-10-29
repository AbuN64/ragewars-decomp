#ifndef COMMON_PLAYERRECAT64E_H
#define COMMON_PLAYERRECAT64E_H
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/AIPROFILE.H"


struct PlayerItemInventoryView;
struct PlayerItemInventoryView {
    char pad[0x644];
    u8 flags[9];
    u8 count64D;
    u8 count64E;
};

struct HolderMultiIsPlayerItemAvailable;
struct PlayerItemInventoryView;

struct Flagged;
struct Flagged {
    u8 pad0[0x58];
    u32 unk58;
};
struct Flagged;
struct Obj8043ECE8;


struct ItemDef;
struct ItemDef {
    char pad[0x20];
    s16 type;
    s16 index;
};

struct ItemDef;
struct MultiplayerItemAvailabilityView;


struct Obj8043EB20;
typedef struct Obj8043EB20 Obj8043EB20;

struct GamePlayerListView;

struct PlayerFrontendCountOpenPlayerSlots;

struct Inner8043E56C;
typedef struct Inner8043E56C Inner8043E56C;

struct Obj8043EB20;

struct Obj8043ECE8;
typedef struct Obj8043ECE8 Obj8043ECE8;


struct Shared_PakMenu;




extern f32 g_playerItemAlphaScale[2];
extern f32 g_playerItemDisabledAlphaScale;

extern char g_debugVariableValueFormat[];
extern char g_debugVariableNamedFormat[];
extern char g_debugVariableUnnamedFormat[];
extern char g_debugVariableValueBuffer[];
extern char g_debugVariableLabelBuffer[];
#endif
