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
extern u8 *Resmgr_CopyString(u8 *, u8 *);
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
        Resmgr_CopyString((u8 *)name,
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

/* Seats the three join requests in free player settings slots, searching down from slot 7. */
extern struct RequestRecAt10 D_80153F80[];
extern u8 *Resmgr_CopyString(u8 *, u8 *);
void Frontend_SeatJoinRequests(void) {
    Shared_PlayerSettingsRecord *player;
    s32 slot = 7;
    s32 i = 0;
    Shared_Game *g = &D_801462C8;
    Shared_PlayerSettingsRecord *settings = g->playerSettings;
    do {
        if (slot <= 0) return;
        if (D_80153F80[i].id >= 0) {
            while (slot > 0 && g->playerSettings[slot].enabled == 1) {
                slot--;
            }
            if (slot >= 0) {
                player = &settings[slot];
                player->locked = 1;
                player->enabled = 1;
                player->slot = slot;
                player->character = D_80153F80[i].id;
                player->team = D_80153F80[i].variant;
                player->rank = D_80153F80[i].word8;
                player->variant = D_80153F80[i].variantC;
                Resmgr_CopyString(player->name, (u8 *)D_80153F80[i].name);
                slot--;
            }
        }
        i++;
    } while (i < 3);
}
