#ifndef COMMON_STATERECAT91_H
#define COMMON_STATERECAT91_H
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"
struct WeaponUnlockProfileView;
struct WeaponUnlockProfileView {
    char p[0x78];
    u8 unk78;
    char p2[6];
    s8 profileIndex;
    char p3[17];
    u8 unk91;
};

struct PresetRow;
typedef struct PresetRow PresetRow;

struct Preset;
struct Preset {
    u8 bytes[0x2A];
};

struct Preset;
typedef struct Preset Preset;

struct PresetRow;
struct PresetRow {
    Preset presets[20];
};

struct PresetTable;

struct WeaponUnlockPlayerView;
struct WeaponUnlockProfileView;



struct PresetTable;
typedef struct PresetTable PresetTable;

struct WeaponUnlockProfileView;
typedef struct WeaponUnlockProfileView WeaponUnlockProfileView;

struct InfoCode80423280;
struct InfoCode80423280 {
    char pad[0x4C];
    unsigned char enabled[22];
    unsigned char values[22];
    unsigned char present;
    char pad79[0x18];
    unsigned char locked;
};
struct InfoCode80423280;
struct PlayerRecAt602;

struct WeaponUnlockPlayerView;
typedef struct WeaponUnlockPlayerView WeaponUnlockPlayerView;

struct PlayerRecAt602;
typedef struct PlayerRecAt602 PlayerRecAt602;


#include "WEAPONS/PLAYER_INVENTORY.H"
#endif
