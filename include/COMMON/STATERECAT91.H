#ifndef COMMON_STATERECAT91_H
#define COMMON_STATERECAT91_H
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"
struct StateRecAt91;
struct StateRecAt91 {
    char p[0x78];
    u8 unk78;
    char p2[6];
    s8 unk7F;
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
struct PresetTable {
    char pad0[0x16];
    PresetRow rows[1];
};

struct Arg;
struct StateRecAt91;
struct Arg {
    char p[0x18];
    func_8024DED0_S2 *unk18;
    char p2[0x5bc];
    struct StateRecAt91 *unk5D8;
    char p3[0x26];
    InventorySlot slots[8];
};

struct func_80426270_S1;
struct func_80426270_S1 {
    char pad0[0x4];
    func_8024DED0_S2 unk4;
};

struct Player_func_80425014_de;
struct Player_func_80425014_de {
    char pad0[0xF];
    u8 slot;
    char pad10[0x17 - 0x10];
    u8 count;
    char pad18[0x125 - 0x18];
    u8 flags[4][5];
    char pad139[0x190 - 0x139];
};

struct PresetTable;
typedef struct PresetTable PresetTable;

struct StateRecAt91;
typedef struct StateRecAt91 StateRecAt91;

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
struct PlayerRecAt602 {
    char pad[0x5D8];
    struct InfoCode80423280 *info;
    char pad5DC[0x26];
    struct {
        unsigned char flag;
        unsigned char value;
    } options[22];
};

struct Arg;
typedef struct Arg Arg;

struct PlayerRecAt602;
typedef struct PlayerRecAt602 PlayerRecAt602;

struct func_80426270_S1;
typedef struct func_80426270_S1 func_80426270_S1;

typedef struct WeaponStatus {
    u8 pad[0x78];
    u8 active;
    u8 pad79[0x18];
    u8 out;
} WeaponStatus;
typedef struct WeaponPlayer {
    u8 pad[0x5D8];
    WeaponStatus *status;
    u8 pad5DC[0x26];
    u8 weapons[22][2];
} WeaponPlayer;
#endif
