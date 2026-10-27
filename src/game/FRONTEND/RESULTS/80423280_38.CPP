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
#include "FRONTEND/RESULTS.H"

/* Hides every model named by the sixty-four 12-byte entries of D_800E4A84: for each entry it looks
   up the first and second identifier in the current screen's context at 0x970 through Frontend_FindWidgetByResourceId
   and disables the object with func_8040E8D8_de, and does the same for the third identifier unless it
   is -1. The identifiers are passed as their low halfword, and the loop walks a manual byte offset
   so the table address is not hoisted. */
/* Read the optional resource as the low half of its word value on every host. */
void Frontend_HideTrialCatalogueWidgets(void) {
    s32 absentResource;
    s32 byteOffset;
    s32 index;
    index = 0;
    absentResource = -1;
    byteOffset = index;
loop:
    Frontend_SetWidgetFlag08(Frontend_FindWidgetByResourceId(D_800E4690->root, ((struct Pair *)((u8 *)D_800E4A84 + (byteOffset)))->a & 0xFFFF), 0);
    Frontend_SetWidgetFlag08(Frontend_FindWidgetByResourceId(D_800E4690->root, ((struct Pair *)((u8 *)D_800E4A84 + (byteOffset)))->b & 0xFFFF), 0);
    if (((struct Pair *)((u8 *)D_800E4A84 + (byteOffset)))->c.id != absentResource) {
        Frontend_SetWidgetFlag08(Frontend_FindWidgetByResourceId(D_800E4690->root, (u16)*(u32 *)((u8 *)D_800E4A84 + byteOffset + 8)), 0);
    }
    index += 1;
    byteOffset += 0xC;
    if (index < 0x40) {
        goto loop;
    }
}

extern struct EntryRecAt0V1 D_800E4694[];
extern void Defs_SetBitValue(u8 *, s32, s32);
extern s32 Defs_TestBit(s32, s32);

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
        Defs_SetBitValue(availableFlags, entryIndex, 0);
    }
    Defs_SetBitValue(availableFlags, 0, 1);
    settings = &D_801462C8;
    if (settings->controllerMode == 1) {
        playerSettings = settings;
        for (entryIndex = 0; entryIndex < 36; entryIndex++) {
            unlockedPreset = Achieve_CopyPreset(entryIndex, 0, *(s8 *)((char *)playerSettings + D_800E4690->player * 0x96 + 0x150));
            unlockValue = unlockedPreset->bytes[1];
            if (unlockValue > 0) Defs_SetBitValue(availableFlags, unlockValue - 1, 1);
            for (unlockSlot = 0; unlockSlot < 3; unlockSlot++) {
                unlockValue = *((u8 *)unlockedPreset + unlockSlot + 2);
                if (unlockValue > 0) Defs_SetBitValue(availableFlags, unlockValue - 1, 1);
            }
        }
    } else {
        for (entryIndex = 0; entryIndex < 36; entryIndex++) {
            Defs_SetBitValue(availableFlags, entryIndex, 1);
        }
    }
    for (entryIndex = 0; entryIndex < 64; entryIndex++) {
        resourceKey = D_800E4A84[entryIndex].a;
        for (searchIndex = 0; searchIndex < 36; searchIndex++) {
            if (D_800E4694[searchIndex].value == resourceKey) { unlockIndex = searchIndex; goto found1; }
        }
        unlockIndex = 0;
found1:;
        if (Defs_TestBit((s32)availableFlags, unlockIndex) == 1) {
            widget = Frontend_FindWidgetByResourceId(D_800E4690->parent, (u16)D_800E4A84[entryIndex].a);
            Frontend_SetWidgetFlag08(widget, 1);
            widget->alpha = 20;
            resourceKey = D_800E4A84[entryIndex].b;
            for (searchIndex = 0; searchIndex < 36; searchIndex++) {
                if (D_800E4694[searchIndex].value == resourceKey) { unlockIndex = searchIndex; goto found2; }
            }
            unlockIndex = 0;
found2:;
            if (Defs_TestBit((s32)availableFlags, unlockIndex) == 1) {
                widget = Frontend_FindWidgetByResourceId(D_800E4690->parent, (u16)D_800E4A84[entryIndex].b);
                Frontend_SetWidgetFlag08(widget, 1);
                widget->alpha = 20;
                if (D_800E4A84[entryIndex].c.id != -1) {
                    widget = Frontend_FindWidgetByResourceId(D_800E4690->parent, (u16)D_800E4A84[entryIndex].c.id);
                    Frontend_SetWidgetFlag08(widget, 1);
                    widget->alpha = 20;
                }
            }
        }
    }
    for (entryIndex = 0; entryIndex < 36; entryIndex++) {
        if (Defs_TestBit((s32)D_800E4690->owned, entryIndex) == 1) ((void (*)(s32))Frontend_MarkLinkedTrialsAvailable)(entryIndex);
    }
    for (entryIndex = 0; entryIndex < 36; entryIndex++) {
        if (Defs_TestBit((s32)D_800E4690->pending, entryIndex) == 1) Defs_SetBitValue(D_800E4690->owned, entryIndex, 1);
    }
    for (entryIndex = 0; entryIndex < 64; entryIndex++) {
        opacity = 170;
        resourceKey = D_800E4A84[entryIndex].a;
        for (searchIndex = 0; searchIndex < 36; searchIndex++) {
            if (D_800E4694[searchIndex].value == resourceKey) { unlockIndex = searchIndex; goto found3; }
        }
        unlockIndex = 0;
found3:;
        if (Defs_TestBit((s32)D_800E4690->owned, unlockIndex) == 1) {
            widget = Frontend_FindWidgetByResourceId(D_800E4690->parent, (u16)D_800E4A84[entryIndex].a);
            if (Defs_TestBit((s32)D_800E4690->pending, unlockIndex) == 1) { widget->alpha = 70; opacity = 70; }
            else widget->alpha = 170;
            resourceKey = D_800E4A84[entryIndex].b;
            for (searchIndex = 0; searchIndex < 36; searchIndex++) {
                if (D_800E4694[searchIndex].value == resourceKey) { unlockIndex = searchIndex; goto found4; }
            }
            unlockIndex = 0;
found4:;
            if (Defs_TestBit((s32)D_800E4690->owned, unlockIndex) == 1) {
                widget = Frontend_FindWidgetByResourceId(D_800E4690->parent, (u16)D_800E4A84[entryIndex].b);
                if (Defs_TestBit((s32)D_800E4690->pending, unlockIndex) == 1) { widget->alpha = 70; opacity = 70; }
                else widget->alpha = 170;
                if (D_800E4A84[entryIndex].c.id != -1) {
                    widget = Frontend_FindWidgetByResourceId(D_800E4690->parent, (u16)D_800E4A84[entryIndex].c.id);
                    widget->alpha = opacity;
                }
            }
        }
    }
}

/* Updates the selected player's appearance and creates its results-screen model. */
#include "TYPES.H"
#include "FRONTEND/8041BEA8_6.H"

typedef struct PreviewSettings { char pad[13]; u8 mode; char padE[0xC2]; struct EntryFrontendRefreshTrialCharacterPreview entries[4]; } PreviewSettings;
typedef struct PreviewRecord { char pad[4]; u8 kind; } PreviewRecord;
extern void Frontend_FillTrialPresetWeaponRows(s32,PreviewSettings *);
extern PreviewRecord *Scene_GetBlLevelData(void *,s32);

void Frontend_RefreshTrialCharacterPreview(void) {
    CVector3 scale;
    s32 record;
    s32 index;
    u8 kind;
    struct EntryFrontendRefreshTrialCharacterPreview *entry;
    PreviewSettings *settings = (PreviewSettings *)&D_801462C8;
    if (settings->mode == 4) {
        record = (*(ResultsOptionsScreen **)&D_800E4690)->selection;
        entry = &((PreviewSettings *)&D_801462C8)->entries[(*(ResultsOptionsScreen **)&D_800E4690)->player];
        Frontend_FillTrialPresetWeaponRows(record, settings);
        kind = Scene_GetBlLevelData(&g_world, record)->kind;
        entry->kind = kind;
        index = Frontend_FindKeyIndex((s8)kind);
        scale.x = D_800E3A58[index].scale[0];
        scale.y = D_800E3A58[index].scale[0];
        scale.z = D_800E3A58[index].scale[0];
        Frontend_InitModelPreview((Obj8041CAD8 *)(*(ResultsOptionsScreen **)&D_800E4690)->panels, 9, entry->kind + 0x38F, 0x4B, 0x5DC0, scale,
                         D_800E3A58[index].position[0], D_800E3A58[index].distance[0],
                         D_800E3A58[index].light[0]);
    }
}
