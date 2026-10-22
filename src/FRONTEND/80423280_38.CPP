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
void func_804273D4_de(void) {
    s32 missing;
    s32 offset;
    s32 i;
    i = 0;
    missing = -1;
    offset = i;
loop:
    func_8040E8D8_de(func_8040EC30_de(D_800E4690->root, ((struct Pair *)((u8 *)D_800E4A84 + (offset)))->a & 0xFFFF), 0);
    func_8040E8D8_de(func_8040EC30_de(D_800E4690->root, ((struct Pair *)((u8 *)D_800E4A84 + (offset)))->b & 0xFFFF), 0);
    if (((struct Pair *)((u8 *)D_800E4A84 + (offset)))->c.id != missing) {
        func_8040E8D8_de(func_8040EC30_de(D_800E4690->root, ((struct Pair *)((u8 *)D_800E4A84 + (offset)))->c.half.low), 0);
    }
    i += 1;
    offset += 0xC;
    if (i < 0x40) {
        goto loop;
    }
}

extern struct EntryRecAt0V1 D_800E4694[];
extern struct Pair D_800E4A84[];
extern void func_80265688_de(u8 *, s32, s32);
extern s32 func_80265650_de(s32, s32);

void func_804274B0_de(void) {
    u8 bits[8];
    Preset *unlocks;
    func_8041F2A0_Item *widget;
    s32 i, j, index;
    s32 search;
    s32 value;
    s32 key;
    Shared_Game *game, *settings;
    u8 alpha;
    func_804273D4_de();
    for (i = 0; i < 36; i++) {
        func_80265688_de(bits, i, 0);
    }
    func_80265688_de(bits, 0, 1);
    settings = &D_801462C8;
    if (settings->controllerMode == 1) {
        game = settings;
        for (i = 0; i < 36; i++) {
            unlocks = func_80425C70_de(i, 0, *(s8 *)((char *)game + D_800E4690->player * 0x96 + 0x150));
            value = unlocks->bytes[1];
            if (value > 0) func_80265688_de(bits, value - 1, 1);
            for (j = 0; j < 3; j++) {
                value = *((u8 *)unlocks + j + 2);
                if (value > 0) func_80265688_de(bits, value - 1, 1);
            }
        }
    } else {
        for (i = 0; i < 36; i++) {
            func_80265688_de(bits, i, 1);
        }
    }
    for (i = 0; i < 64; i++) {
        key = D_800E4A84[i].a;
        for (search = 0; search < 36; search++) {
            if (D_800E4694[search].value == key) { index = search; goto found1; }
        }
        index = 0;
found1:;
        if (func_80265650_de((s32)bits, index) == 1) {
            widget = func_8040EC30_de(D_800E4690->parent, (u16)D_800E4A84[i].a);
            func_8040E8D8_de(widget, 1);
            widget->alpha = 20;
            key = D_800E4A84[i].b;
            for (search = 0; search < 36; search++) {
                if (D_800E4694[search].value == key) { index = search; goto found2; }
            }
            index = 0;
found2:;
            if (func_80265650_de((s32)bits, index) == 1) {
                widget = func_8040EC30_de(D_800E4690->parent, (u16)D_800E4A84[i].b);
                func_8040E8D8_de(widget, 1);
                widget->alpha = 20;
                if (D_800E4A84[i].c.id != -1) {
                    widget = func_8040EC30_de(D_800E4690->parent, D_800E4A84[i].c.half.low);
                    func_8040E8D8_de(widget, 1);
                    widget->alpha = 20;
                }
            }
        }
    }
    for (i = 0; i < 36; i++) {
        if (func_80265650_de((s32)D_800E4690->owned, i) == 1) ((void (*)(s32))func_80427D70_de)(i);
    }
    for (i = 0; i < 36; i++) {
        if (func_80265650_de((s32)D_800E4690->pending, i) == 1) func_80265688_de(D_800E4690->owned, i, 1);
    }
    for (i = 0; i < 64; i++) {
        alpha = 170;
        key = D_800E4A84[i].a;
        for (search = 0; search < 36; search++) {
            if (D_800E4694[search].value == key) { index = search; goto found3; }
        }
        index = 0;
found3:;
        if (func_80265650_de((s32)D_800E4690->owned, index) == 1) {
            widget = func_8040EC30_de(D_800E4690->parent, (u16)D_800E4A84[i].a);
            if (func_80265650_de((s32)D_800E4690->pending, index) == 1) { widget->alpha = 70; alpha = 70; }
            else widget->alpha = 170;
            key = D_800E4A84[i].b;
            for (search = 0; search < 36; search++) {
                if (D_800E4694[search].value == key) { index = search; goto found4; }
            }
            index = 0;
found4:;
            if (func_80265650_de((s32)D_800E4690->owned, index) == 1) {
                widget = func_8040EC30_de(D_800E4690->parent, (u16)D_800E4A84[i].b);
                if (func_80265650_de((s32)D_800E4690->pending, index) == 1) { widget->alpha = 70; alpha = 70; }
                else widget->alpha = 170;
                if (D_800E4A84[i].c.id != -1) {
                    widget = func_8040EC30_de(D_800E4690->parent, D_800E4A84[i].c.half.low);
                    widget->alpha = alpha;
                }
            }
        }
    }
}

#ifdef NON_MATCHING
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
 CVector3 scale; s32 record,index; u8 kind; Entry *entry; PreviewSettings *settings=(PreviewSettings *)&D_801462C8; PreviewScreen *screen=(PreviewScreen *)D_800E4690;
 if(settings->mode==4) {
 record=screen->record;
 entry = &settings->entries[screen->player];
 func_804284C0_de(record,settings);
 kind=func_8028D474_de(&D_8011FE88,record)->kind;
 entry->kind=kind;
 index=func_8041F140_de((s8)kind);
 scale.x=((PreviewRow *)D_800E3A58)[index].scale[0]; scale.y=((PreviewRow *)D_800E3A58)[index].scale[0]; scale.z=((PreviewRow *)D_800E3A58)[index].scale[0];
 func_8041CAD8_de(screen->preview,9,entry->kind+0x38F,0x4B,0x5DC0,scale,((PreviewRow *)D_800E3A58)[index].position[0],((PreviewRow *)D_800E3A58)[index].distance[0],((PreviewRow *)D_800E3A58)[index].light[0]);
 }
}
#else
INCLUDE_ASM("ovl_80400000", func_804279B8_de);
#endif
