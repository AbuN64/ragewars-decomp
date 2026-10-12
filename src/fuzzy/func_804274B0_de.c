#include "types.h"

typedef union DraftMenuId { s32 value; struct { u16 group, id; } halves; } DraftMenuId;
typedef struct DraftOptionEntry { s32 value; char pad4[0x18]; } DraftOptionEntry;
typedef struct DraftOptionPair { DraftMenuId first, second, third; } DraftOptionPair;
typedef struct DraftOptionWidget { char pad0[0x10]; u8 alpha; } DraftOptionWidget;
typedef struct DraftOptionScreen {
    char pad0[0x970]; void *root;
    char pad974[0xE8]; s32 selection;
    char padA60[0x14]; u8 enabled[5], pending[5];
} DraftOptionScreen;
typedef struct DraftOptionPlayer { char pad0[0x80]; s8 selection; char pad81[0x15]; } DraftOptionPlayer;
typedef struct DraftOptionGame { char pad0[0xD]; u8 mode; char padE[0xC2]; DraftOptionPlayer players[8]; } DraftOptionGame;
typedef struct DraftOptionUnlock { u8 unused, first, extra[3]; } DraftOptionUnlock;
extern DraftOptionScreen *D_800E4690;
extern DraftOptionEntry D_800E4694[36];
extern DraftOptionPair D_800E4A84[64];
extern DraftOptionGame D_801462C8;
extern void func_804273D4_de(void);
extern void func_80265688_de(u8 *, s32, s32);
extern s32 func_80265650_de(u8 *, s32);
extern DraftOptionUnlock *func_80425C70_de(s32, s32, s32);
extern DraftOptionWidget *func_8040EC30_de(void *, u16);
extern void func_8040E8D8_de(void *, s32);
extern void func_80427D70_de(s32);

void func_804274B0_de(void) {
    u8 bits[8];
    DraftOptionUnlock *unlocks;
    DraftOptionWidget *widget;
    s32 i, j, index;
    u8 alpha;
    func_804273D4_de();
    for (i = 0; i < 36; i++) {
        func_80265688_de(bits, i, 0);
    }
    func_80265688_de(bits, 0, 1);
    if (D_801462C8.mode == 1) {
        for (i = 0; i < 36; i++) {
            unlocks = func_80425C70_de(i, 0, D_801462C8.players[D_800E4690->selection].selection);
            if (unlocks->first) func_80265688_de(bits, unlocks->first - 1, 1);
            for (j = 0; j < 3; j++) {
                if (unlocks->extra[j]) func_80265688_de(bits, unlocks->extra[j] - 1, 1);
            }
        }
    } else {
        for (i = 0; i < 36; i++) {
            func_80265688_de(bits, i, 1);
        }
    }
    for (i = 0; i < 64; i++) {
        for (index = 0; index < 36; index++) {
            if (D_800E4694[index].value == D_800E4A84[i].first.value) break;
        }
        if (index == 36) index = 0;
        if (func_80265650_de(bits, index) == 1) {
            widget = func_8040EC30_de(D_800E4690->root, D_800E4A84[i].first.halves.id);
            func_8040E8D8_de(widget, 1);
            widget->alpha = 20;
            for (index = 0; index < 36; index++) {
                if (D_800E4694[index].value == D_800E4A84[i].second.value) break;
            }
            if (index == 36) index = 0;
            if (func_80265650_de(bits, index) == 1) {
                widget = func_8040EC30_de(D_800E4690->root, D_800E4A84[i].second.halves.id);
                func_8040E8D8_de(widget, 1);
                widget->alpha = 20;
                if (D_800E4A84[i].third.value != -1) {
                    widget = func_8040EC30_de(D_800E4690->root, D_800E4A84[i].third.halves.id);
                    func_8040E8D8_de(widget, 1);
                    widget->alpha = 20;
                }
            }
        }
    }
    for (i = 0; i < 36; i++) {
        if (func_80265650_de(D_800E4690->enabled, i) == 1) func_80427D70_de(i);
    }
    for (i = 0; i < 36; i++) {
        if (func_80265650_de(D_800E4690->pending, i) == 1) func_80265688_de(D_800E4690->enabled, i, 1);
    }
    for (i = 0; i < 64; i++) {
        alpha = 170;
        for (index = 0; index < 36; index++) {
            if (D_800E4694[index].value == D_800E4A84[i].first.value) break;
        }
        if (index == 36) index = 0;
        if (func_80265650_de(D_800E4690->enabled, index) == 1) {
            widget = func_8040EC30_de(D_800E4690->root, D_800E4A84[i].first.halves.id);
            if (func_80265650_de(D_800E4690->pending, index) == 1) { widget->alpha = 70; alpha = 70; }
            else widget->alpha = 170;
            for (index = 0; index < 36; index++) {
                if (D_800E4694[index].value == D_800E4A84[i].second.value) break;
            }
            if (index == 36) index = 0;
            if (func_80265650_de(D_800E4690->enabled, index) == 1) {
                widget = func_8040EC30_de(D_800E4690->root, D_800E4A84[i].second.halves.id);
                if (func_80265650_de(D_800E4690->pending, index) == 1) { widget->alpha = 70; alpha = 70; }
                else widget->alpha = 170;
                if (D_800E4A84[i].third.value != -1) {
                    widget = func_8040EC30_de(D_800E4690->root, D_800E4A84[i].third.halves.id);
                    widget->alpha = alpha;
                }
            }
        }
    }
}
