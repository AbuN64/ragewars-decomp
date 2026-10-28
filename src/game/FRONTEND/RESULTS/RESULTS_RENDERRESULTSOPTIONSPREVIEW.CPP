#include "include_asm.h"
#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/VIDEO_DIMENSIONS.H"
#include "COMMON/LONE/D_800E28D4.H"
#include "RENDER/8026AC38.H"
#include "COMMON/RECRECAT4.H"
#include "TYPES.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "gbi.h"
#include "COMMON/GFX.H"
#include "COMMON/SESSIONHANDLERROW.H"
#include "COMMON/INTEGERSTATE530.H"
#include "COMMON/RESULTSOPTIONSSCREEN.H"
#include "FRONTEND/80423280_38.H"
#include "FRONTEND/CODE_80426EC4.H"
#include "FRONTEND/RESULTS.H"
extern ResultsOptionsScreen *D_800E4690;

/* Draw callback of the results screen D_800E4690: on draw event 1 in states 3, 8 or 9 it resets
   the fill colour D_800D15E0 to opaque white, and for each of the one or two viewports clips the
   display list to its rectangle in g_menuPlayerScissorRects (0, then 2 for the lower view), draws the player's panel through Preview_DrawModelPreview and restores the
   full-screen clip. Outside two-player mode (and unless GetMenuScreenOwner reports 0x19) it plays sound
   0x259 past the base at 0xA44 on the twentieth frame, raises the banner blink after six more
   frames, and fades the two banner sprites out by 30 per frame before hiding them. Returns zero. */












extern struct Shape_typemap_6 g_menuPlayerScissorRects[];

extern s32 D_800E28D0;



extern void Preview_DrawModelPreview(char *);

extern void Widget_SetWidgetFlag08(struct Shape_typemap_21 *, s32);

/* Loads the stage list of the results screen D_800E4690: clears its two 36-bit sets at 0xA74 and
   0xA79, copies into the first the 36 cleared-stage bits that the player record D_80102B00[index at
   0xA5C] keeps for the current mode D_801462D5 (at 0x7E, 0x83, 0x88 or 0x8D for modes 1 to 4), and
   refreshes the list through Results_RefreshTrialCatalogueWidgets. */







extern struct RecordRecAt8D D_80102B00[];

extern void Defs_SetBitValue(u8 *, s32, s32);

extern s32 Defs_TestBit(u8 *, s32);

s32 Results_RenderResultsOptionsPreview(void *unused0, void *unused1, s32 event) {
    s32 views;
    s32 i;
    s32 alpha;
    s32 k;

    if (event == 1 && (D_800E4690->state == 3 || D_800E4690->state == 8 || D_800E4690->state == 9)) {
        D_800D15E0 = 0;
        D_800D15E4[0] = 255.0f;
        D_800D15E4[1] = 255.0f;
        D_800D15E4[2] = 255.0f;
        D_800D15E4[3] = 255.0f;
        views = 1;
        if (D_801462C8.controllerMode == 2) {
            views = 2;
        }
        for (i = 0, k = 0; i < views; i++, k = 2) {
            gDPSetScissor(g_displayListCursor++, G_SC_NON_INTERLACE, g_menuPlayerScissorRects[k].field_0, g_menuPlayerScissorRects[k].field_4, g_menuPlayerScissorRects[k].field_8, g_menuPlayerScissorRects[k].field_C);
            Preview_DrawModelPreview(D_800E4690->panels[i]);
            gDPSetScissor(g_displayListCursor++, G_SC_NON_INTERLACE, 0, 0, SCREEN_WD - 1, SCREEN_HT - 1);
        }
        if (D_801462C8.controllerMode != 2 && GetMenuScreenOwner() != 0x19) {
            if (D_800E4690->frames < 20) {
                if (++D_800E4690->frames == 20) {
                    k = D_800E4690->selection;
                    Menu_SetOptionsSceneSelection(k + 0x259);
                    D_800E4690->blinkDelay = 0;
                }
            }
            if (D_800E4690->blinkDelay != -1) {
                if (++D_800E4690->blinkDelay >= 6) {
                    D_800E4690->blinking = 1;
                    D_800E4690->blinkDelay = -1;
                }
            }
            if (D_800E4690->blinking == 1) {
                alpha = D_800E4690->banner->alpha;
                alpha -= 30;
                if (alpha <= 0) {
                    D_800E4690->blinking = 0;
                    Widget_SetWidgetFlag08(D_800E4690->bannerShadow, 0);
                    Widget_SetWidgetFlag08(D_800E4690->banner, 0);
                    alpha = 0xFF;
                }
                D_800E4690->banner->alpha = alpha;
                D_800E4690->bannerShadow->alpha = alpha;
            }
        }
    }
    return 0;
}

void Results_LoadTrialCompletionFlags(void) {
    s32 i;

    i = 0;
    do {
        Defs_SetBitValue(D_800E4690->owned, i, 0);
        Defs_SetBitValue(D_800E4690->pending, i, 0);
        i++;
    } while (i < 36);
    switch (D_801462C8.controllerMode) {
    case 1:
        i = 0;
        do {
            Defs_SetBitValue(D_800E4690->owned, i, Defs_TestBit(D_80102B00[D_800E4690->player].single, i));
            i++;
        } while (i < 36);
        break;
    case 2:
        i = 0;
        do {
            Defs_SetBitValue(D_800E4690->owned, i, Defs_TestBit(D_80102B00[D_800E4690->player].versus, i));
            i++;
        } while (i < 36);
        break;
    case 3:
        i = 0;
        do {
            Defs_SetBitValue(D_800E4690->owned, i, Defs_TestBit(D_80102B00[D_800E4690->player].three, i));
            i++;
        } while (i < 36);
        break;
    case 4:
        i = 0;
        do {
            Defs_SetBitValue(D_800E4690->owned, i, Defs_TestBit(D_80102B00[D_800E4690->player].four, i));
            i++;
        } while (i < 36);
        break;
    }
    Results_RefreshTrialCatalogueWidgets();
}

extern struct EntryRecAt0V1 D_800E4694[];

/* Backtracking search over the 36 unlock nodes of D_800E4694: while any node is still set in the
   remaining bit set, appends to the -1-terminated path the first remaining node linked to the
   path's last node, clears its bit and recurses, undoing the step when the recursion fails. Every
   exit returns one, so the first linked choice at each depth is always kept. */
s32 Results_FindUnlockPath(u8 *remaining, s32 *path) {
    s32 anyLeft;
    s32 node;
    s32 last;
    s32 linked;

    anyLeft = 0;
    node = 0;
    do {
        if (Defs_TestBit(remaining, node) == 1) {
            anyLeft = 1;
        }
        node++;
    } while (node < 36 && anyLeft == 0);
    if (anyLeft != 0) {
        last = 0;
        while (path[last] != -1) {
            last++;
        }
        last--;
        node = 0;
        while (node < 36) {
            if (Defs_TestBit(remaining, node) == 0) {
                node++;
            } else {
                linked = Results_IsUnlockLinked(D_800E4694[path[last]].value, D_800E4694[node].value);
                if (linked == 1) {
                    last++;
                    path[last] = node;
                    path[last + 1] = -1;
                    Defs_SetBitValue(remaining, node, 0);
                    if (Results_FindUnlockPath(remaining, path) == linked) {
                        return 1;
                    }
                    Defs_SetBitValue(remaining, node, 1);
                    path[last] = -1;
                    last--;
                }
                node++;
            }
        }
    }
    return 1;
}
