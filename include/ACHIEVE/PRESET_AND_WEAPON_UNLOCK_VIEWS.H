#ifndef ACHIEVE_PRESET_AND_WEAPON_UNLOCK_VIEWS_H
#define ACHIEVE_PRESET_AND_WEAPON_UNLOCK_VIEWS_H
#include "TYPES.H"
#include "COMMON/STATERECAT91.H"
#include "COMMON/ITEMRECAT20V1.H"
struct PresetTable {
    char pad0[0x16];
    PresetRow rows[1];
};
struct Arg {
    char p[0x18];
    func_8024DED0_S2 *unk18;
    char p2[0x5bc];
    struct StateRecAt91 *unk5D8;
    char p3[0x26];
    InventorySlot slots[8];
};
#endif
