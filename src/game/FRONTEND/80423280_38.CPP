#include "COMMON/WORLD.H"
#include "include_asm.h"
#include "COMMON/RESULTSOPTIONSSCREEN.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/UNUSED.H"
#include "COMMON/ARGB_COLOR.H"
#include "FRONTEND/RESULTSOPTIONSSCREEN.H"
#include "COMMON/MULTIPLAYEROPTIONS.H"
#include "COMMON/LOADOUT.H"
#include "COMMON/OWNERRECAT8V2.H"
#include "COMMON/GROUP.H"
#include "COMMON/OBJECTLINKS180_2.H"
#include "COMMON/MANAGER.H"
#include "COMMON/CARTRIDGEREADWORKER.H"
#include "COMMON/OBJRECAT4V6.H"
#include "COMMON/SOUNDVOICEPOOL.H"
#include "COMMON/LIGHTDATA.H"
#include "COMMON/OBJECTSTATE18.H"
#include "COMMON/MTX.H"
#include "COMMON/OBJECTLINKS1E8.H"
#include "COMMON/COLORENTRY.H"
#include "COMMON/WORLDSORTENTRY.H"
#include "COMMON/RESULTS.H"
#include "COMMON/OBJRECAT26DD8.H"
#include "COMMON/INTEGERSTATE530.H"
#include "COMMON/OBJRECAT18V6.H"
#include "COMMON/ALBANK_S.H"
#include "COMMON/OBJRECAT18V1.H"
#include "COMMON/ALPARAM_S.H"
#include "COMMON/ALDELAY28.H"
#include "COMMON/OSPIHANDLE_S.H"
#include "COMMON/OSTASK_T.H"
#include "COMMON/OSVISCALE.H"
#include "COMMON/CTX.H"
#include "COMMON/ALLOADFILTER48_2.H"
#include "COMMON/CHEATCODE.H"
#include "COMMON/ENTRYRECAT0V3.H"
#include "COMMON/NODERECAT2A8.H"
#include "COMMON/SLOTRECATCV1.H"
#include "COMMON/TEXTURE.H"
#include "COMMON/LABEL.H"
#include "COMMON/REQUESTRECAT10.H"
#include "COMMON/CHARACTERSELECTIONROOT.H"
#include "COMMON/S1_5.H"
#include "COMMON/STATERECAT91.H"
#include "COMMON/SETTINGSRECAT24.H"
#include "COMMON/OBJECTRECAT28.H"
#include "COMMON/PLAYERRECAT64E.H"
#include "COMMON/OBJB.H"
#include "TYPES.H"
#include "COMMON/MEASUREDRECAT0V1.H"
#include "COMMON/MEASURED.H"
#include "COMMON/MEASUREDRECAT14V4.H"
#include "COMMON/MEASUREDRECAT14V2.H"
#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/SELECTIONSCREENSTATE.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#include "COMMON/EXTERNS_9.H"
#include "FRONTEND/80423280_38.H"
#include "FRONTEND/80423280_40.H"
#include "ACHIEVE/80424E30_3.H"

/* Hides every model named by the sixty-four 12-byte entries of D_800E4A84: for each entry it looks
   up the first and second identifier in the current screen's context at 0x970 through func_8040EC30_de
   and disables the object with func_8040E8D8_de, and does the same for the third identifier unless it
   is -1. The identifiers are passed as their low halfword, and the loop walks a manual byte offset
   so the table address is not hoisted. */
extern struct Pair D_800E4A84[];
/* Read the optional resource as the low half of its word value on every host. */
void Frontend_HideTrialCatalogueWidgets(void) {
    s32 absentResource;
    s32 byteOffset;
    s32 index;
    index = 0;
    absentResource = -1;
    byteOffset = index;
loop:
    func_8040E8D8_de(func_8040EC30_de(D_800E4690->root, ((struct Pair *)((u8 *)D_800E4A84 + (byteOffset)))->a & 0xFFFF), 0);
    func_8040E8D8_de(func_8040EC30_de(D_800E4690->root, ((struct Pair *)((u8 *)D_800E4A84 + (byteOffset)))->b & 0xFFFF), 0);
    if (((struct Pair *)((u8 *)D_800E4A84 + (byteOffset)))->c.id != absentResource) {
        func_8040E8D8_de(func_8040EC30_de(D_800E4690->root, (u16)*(u32 *)((u8 *)D_800E4A84 + byteOffset + 8)), 0);
    }
    index += 1;
    byteOffset += 0xC;
    if (index < 0x40) {
        goto loop;
    }
}

extern struct EntryRecAt0V1 D_800E4694[];
extern struct Pair D_800E4A84[];
extern void func_80265688_de(u8 *, s32, s32);
extern s32 func_80265650_de(s32, s32);

void Frontend_RefreshTrialCatalogueWidgets(void) {
    u8 availableFlags[8];
    Preset *unlockedPreset;
    func_8041F2A0_Item *widget;
    s32 entryIndex, unlockSlot, unlockIndex;
    s32 searchIndex;
    s32 unlockValue;
    s32 resourceKey;
    Shared_Game *playerSettings, *settings;
    u8 opacity;
    Frontend_HideTrialCatalogueWidgets();
    for (entryIndex = 0; entryIndex < 36; entryIndex++) {
        func_80265688_de(availableFlags, entryIndex, 0);
    }
    func_80265688_de(availableFlags, 0, 1);
    settings = &D_801462C8;
    if (settings->controllerMode == 1) {
        playerSettings = settings;
        for (entryIndex = 0; entryIndex < 36; entryIndex++) {
            unlockedPreset = func_80425C70_de(entryIndex, 0, *(s8 *)((char *)playerSettings + D_800E4690->player * 0x96 + 0x150));
            unlockValue = unlockedPreset->bytes[1];
            if (unlockValue > 0) func_80265688_de(availableFlags, unlockValue - 1, 1);
            for (unlockSlot = 0; unlockSlot < 3; unlockSlot++) {
                unlockValue = *((u8 *)unlockedPreset + unlockSlot + 2);
                if (unlockValue > 0) func_80265688_de(availableFlags, unlockValue - 1, 1);
            }
        }
    } else {
        for (entryIndex = 0; entryIndex < 36; entryIndex++) {
            func_80265688_de(availableFlags, entryIndex, 1);
        }
    }
    for (entryIndex = 0; entryIndex < 64; entryIndex++) {
        resourceKey = D_800E4A84[entryIndex].a;
        for (searchIndex = 0; searchIndex < 36; searchIndex++) {
            if (D_800E4694[searchIndex].value == resourceKey) { unlockIndex = searchIndex; goto found1; }
        }
        unlockIndex = 0;
found1:;
        if (func_80265650_de((s32)availableFlags, unlockIndex) == 1) {
            widget = func_8040EC30_de(D_800E4690->parent, (u16)D_800E4A84[entryIndex].a);
            func_8040E8D8_de(widget, 1);
            widget->alpha = 20;
            resourceKey = D_800E4A84[entryIndex].b;
            for (searchIndex = 0; searchIndex < 36; searchIndex++) {
                if (D_800E4694[searchIndex].value == resourceKey) { unlockIndex = searchIndex; goto found2; }
            }
            unlockIndex = 0;
found2:;
            if (func_80265650_de((s32)availableFlags, unlockIndex) == 1) {
                widget = func_8040EC30_de(D_800E4690->parent, (u16)D_800E4A84[entryIndex].b);
                func_8040E8D8_de(widget, 1);
                widget->alpha = 20;
                if (D_800E4A84[entryIndex].c.id != -1) {
                    widget = func_8040EC30_de(D_800E4690->parent, (u16)D_800E4A84[entryIndex].c.id);
                    func_8040E8D8_de(widget, 1);
                    widget->alpha = 20;
                }
            }
        }
    }
    for (entryIndex = 0; entryIndex < 36; entryIndex++) {
        if (func_80265650_de((s32)D_800E4690->owned, entryIndex) == 1) ((void (*)(s32))func_80427D70_de)(entryIndex);
    }
    for (entryIndex = 0; entryIndex < 36; entryIndex++) {
        if (func_80265650_de((s32)D_800E4690->pending, entryIndex) == 1) func_80265688_de(D_800E4690->owned, entryIndex, 1);
    }
    for (entryIndex = 0; entryIndex < 64; entryIndex++) {
        opacity = 170;
        resourceKey = D_800E4A84[entryIndex].a;
        for (searchIndex = 0; searchIndex < 36; searchIndex++) {
            if (D_800E4694[searchIndex].value == resourceKey) { unlockIndex = searchIndex; goto found3; }
        }
        unlockIndex = 0;
found3:;
        if (func_80265650_de((s32)D_800E4690->owned, unlockIndex) == 1) {
            widget = func_8040EC30_de(D_800E4690->parent, (u16)D_800E4A84[entryIndex].a);
            if (func_80265650_de((s32)D_800E4690->pending, unlockIndex) == 1) { widget->alpha = 70; opacity = 70; }
            else widget->alpha = 170;
            resourceKey = D_800E4A84[entryIndex].b;
            for (searchIndex = 0; searchIndex < 36; searchIndex++) {
                if (D_800E4694[searchIndex].value == resourceKey) { unlockIndex = searchIndex; goto found4; }
            }
            unlockIndex = 0;
found4:;
            if (func_80265650_de((s32)D_800E4690->owned, unlockIndex) == 1) {
                widget = func_8040EC30_de(D_800E4690->parent, (u16)D_800E4A84[entryIndex].b);
                if (func_80265650_de((s32)D_800E4690->pending, unlockIndex) == 1) { widget->alpha = 70; opacity = 70; }
                else widget->alpha = 170;
                if (D_800E4A84[entryIndex].c.id != -1) {
                    widget = func_8040EC30_de(D_800E4690->parent, (u16)D_800E4A84[entryIndex].c.id);
                    widget->alpha = opacity;
                }
            }
        }
    }
}

/* Updates the selected player's appearance and creates its results-screen model. */
#include "TYPES.H"
#include "FRONTEND/8041BEA8_6.H"
typedef struct Entry { char pad[0x80]; s8 kind; char tail[0x15]; } Entry;
typedef struct PreviewSettings { char pad[13]; u8 mode; char padE[0xC2]; Entry entries[4]; } PreviewSettings;
typedef struct PreviewScreen { char pad[0x20]; char preview[0xA24]; s32 record; char padA48[0x14]; s32 player; } PreviewScreen;
typedef struct PreviewRecord { char pad[4]; u8 kind; } PreviewRecord;
typedef struct PreviewRow { s32 pad; f32 scale[4],distance[4]; CVector3 position[4]; s32 light[4]; char tail[12]; } PreviewRow;
extern void func_804284C0_de(s32,PreviewSettings *);
extern PreviewRecord *func_8028D474_de(void *,s32);
typedef struct func_80427B98_S1 func_80427B98_S1;
struct func_80427B98_S1 {
    char pad0[0x20];
    char unk20;
};

void func_804279B8_de(void) {
    CVector3 scale;
    s32 record;
    s32 index;
    u8 kind;
    Entry *entry;
    PreviewSettings *settings = (PreviewSettings *)&D_801462C8;
    if (settings->mode == 4) {
        record = (*(ResultsOptionsScreen **)&D_800E4690)->selection;
        entry = &((PreviewSettings *)&D_801462C8)->entries[(*(ResultsOptionsScreen **)&D_800E4690)->player];
        func_804284C0_de(record, settings);
        kind = func_8028D474_de(&D_8011FE88, record)->kind;
        entry->kind = kind;
        index = func_8041F140_de((s8)kind);
        scale.x = D_800E3A58[index].scale[0];
        scale.y = D_800E3A58[index].scale[0];
        scale.z = D_800E3A58[index].scale[0];
        Frontend_InitModelPreview((Obj8041CAD8 *)(*(ResultsOptionsScreen **)&D_800E4690)->panels, 9, entry->kind + 0x38F, 0x4B, 0x5DC0, scale,
                         D_800E3A58[index].position[0], D_800E3A58[index].distance[0],
                         D_800E3A58[index].light[0]);
    }
}
