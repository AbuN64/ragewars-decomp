#include "include_asm.h"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SELECTIONSCREENSTATE.H"
#include "COMMON/REQUESTRECAT10.H"
#include "COMMON/RESULTSOPTIONSSCREEN.H"
#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/EFFECTRENDER.H"
#include "COMMON/UNUSED.H"
#include "TYPES.H"

#if (defined(VERSION_EU) || defined(VERSION_EU_X)) && !defined(NON_MATCHING)
INCLUDE_ASM("ovl_80400000", func_8041E408_de);
#endif

#if !(defined(VERSION_EU) || defined(VERSION_EU_X)) || defined(NON_MATCHING)
/* Fuzzy draft in EU and EU-X: their body differs (134 words). */
extern void *D_800E39C0;
extern struct RequestRecAt10 D_80153F80[];
extern struct TextEntry D_800E381C[][17];
extern u8 *func_802A025C_de(u8 *, u8 *);
#if defined(VERSION_DE)
enum { DRAW_ICON=903, DRAW_NAME=905, DRAW_VARIANT=904, DRAW_FIRST=906, DRAW_SECOND=907 };
#else
enum { DRAW_ICON=909, DRAW_NAME=911, DRAW_VARIANT=910, DRAW_FIRST=912, DRAW_SECOND=913 };
#endif
void func_8041E408_de(s32 index) {
    void *window;
    RequestDrawScreen *screen;
    MenuWidget *widget;
    s32 model;
    char *name;
    void *widgetObject;
    void *variantObject;
    char ***variantSlot;
    screen = D_800E39C0;
    window = screen->roots[index];
    if (screen->count < index || D_80153F80[index].id < 0) {
        func_8040E8D8_de(window, 0);
    } else {
        widgetObject = func_8040EC30_de(window, DRAW_ICON);
        widget = widgetObject;
        widget->alpha = 125;
        model = func_8041F140_de(D_80153F80[index].id);
        widget->value = D_800E3A58[model].portrait;
        widgetObject = func_8040EC30_de(window, DRAW_NAME);
        widget = widgetObject;
        widget->alpha = 125;
        model = func_8041EC44_de(D_80153F80[index].variant, D_80153F80[index].id);
    name = D_80153F80[index].name;
        func_802A025C_de((u8 *)name,
          (u8 *)*D_800E381C[D_80153F80[index].variant][model].text
        );
        widget->text = name;
        widgetObject = func_8040EC30_de(window, DRAW_VARIANT);
        widget = widgetObject;
        widget->alpha = 125;
        variantObject = &D_800DF964[D_80153F80[index].variant];
        variantSlot = variantObject;
        widget->text = **variantSlot;
        widgetObject = func_8040EC30_de(window, DRAW_FIRST);
        widget = widgetObject;
        widget->alpha = 125;
        widget->value = D_800DF740[D_80153F80[index].word8].first;
        widgetObject = func_8040EC30_de(window, DRAW_SECOND);
        widget = widgetObject;
        widget->alpha = 125;
        widget->value = D_800DF740[D_80153F80[index].word8].second;
    }
}
#endif

#ifdef NON_MATCHING
/* NON_MATCHING: 81 words vs 74. Loop optimisation strength-reduces slot*150 and the name pointer, where the target
 * recomputes slot*150 each pass and keeps i and i*28 as separate counters. */
extern struct RequestRecAt10 D_80153F80[];
extern u8 *func_802A025C_de(u8 *, u8 *);
void func_8041E5F8_de(void) {
    Shared_PlayerSettingsRecord *player;
    Shared_PlayerSettingsRecord *probe;
    s32 slot = 7;
    s32 i = 0;
    player = &D_801462C8.playerSettings[7];
    do {
        if (slot <= 0) return;
        if (D_80153F80[i].id >= 0) {
            probe = &D_801462C8.playerSettings[slot];
            while (probe->enabled == 1) {
                probe--;
                slot--;
                player--;
                if (slot <= 0) break;
            }
            if (slot >= 0) {
                player->locked = 1;
                player->enabled = 1;
                player->slot = slot;
                slot--;
                player->character = D_80153F80[i].id;
                player->pad92[1] = D_80153F80[i].variant;
                player->pad92[0] = D_80153F80[i].word8;
                player->variant = D_80153F80[i].variantC;
                func_802A025C_de(player->name, (u8 *)D_80153F80[i].name);
                player--;
            }
        }
        i++;
    } while (i < 3);
}
#else
INCLUDE_ASM("ovl_80400000", func_8041E5F8_de);
#endif
