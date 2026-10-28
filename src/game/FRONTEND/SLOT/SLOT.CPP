#include "include_asm.h"
#include "COMMON/SCREEN.H"
#include "COMMON/SELECTIONSCREENSTATE.H"
#include "COMMON/LABEL.H"
#include "RENDER/SOUNDELEMENT_PLAYFLATSOUND.H"
#include "TYPES.H"

/* 8041BEA8_7.CPP */
#if defined(VERSION_US_REV1) || defined(VERSION_US) || defined(VERSION_EU) || defined(VERSION_DE) || defined(VERSION_EU_X)
/* Builds the player-selection menu block at 0x800E3590 for one menu tree: it allocates the block
 * with a 528-byte window request, remembers the tree and the pool func_8041B610_de returns for it,
 * arms the tree's four option groups with id 513, hands the pool back to SmpOverlay_SetObjectValue, and
 * keeps the windows 492, 491, 486, 563, 510, 512, 511 and their lookup results in the block. The
 * window geometry is nudged by whole groups of four pixels so each window snaps to a 4-pixel grid;
 * the menu item window 488 and the two label windows 496/497 get fixed alpha bytes 110/120, window
 * 493 gets 110, and window 511 is cleared before the block is handed to func_8041DB30_de. */
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SELECTIONSCREENSTATE.H"
#include "COMMON/LABEL.H"
#include "COMMON/ANIMATION.H"
#include "TYPES.H"

/* D_800E3590 and its 528-byte block layout are spelled once in the closed hub as
 * func_8041F2A0_MenuBlock, shared with the neighbouring menu units that keep their own views over
 * the same block. */

/* The hub spells func_8041DB30_de; these two stay here, matching how the landed units that own
 * them define them: SmpOverlay_SetObjectValue writes the word at +0x6C of the object it is handed, and
 * Focus_ShowUnlockedEntries takes the style word this block keeps at +0x0FC. */

/* The pool and style helpers take a word, while this unit and the window lookups carry the menu
 * tree as a pointer; the cast carries that pointer through unchanged. */
/* Resource ids of this screen are numbered per version: de -4, eu-x 4 relative to us. */
static inline s32 slotRes(s32 id) {
#if defined(VERSION_DE)
    return id - 4;
#elif defined(VERSION_EU_X)
    return id + 4;
#else
    return id;
#endif
}

s32 Frontend_CreateSlotSelectionMenu(void *arg0) {
    func_8041F2A0_Item *item;
    s32 shift;
    s32 adjust;

    D_800E3590 = (func_8041F2A0_MenuBlock *) Cache_AllocateMemory(528);
    D_800E3590->root = arg0;
    D_800E3590->list = SmpOverlay_CreateOverlayNode((s32) arg0, 4);
    SmpOverlay_ShowSlotById((s32) arg0, 0, slotRes(513));
    SmpOverlay_ShowSlotById((s32) arg0, 1, slotRes(513));
    SmpOverlay_ShowSlotById((s32) arg0, 2, slotRes(513));
    SmpOverlay_ShowSlotById((s32) arg0, 3, slotRes(513));
    /* func_8041B610_de is published to this unit as handing back a word while SmpOverlay_SetObjectValue is
     * published as taking the pool object that word names; the cast puts that object view back on
     * the pool stored at +0x004 and carries it through unchanged. */
    SmpOverlay_SetObjectValue((struct Object6C *) D_800E3590->list, 1);

    D_800E3590->unk216 = 1;
    D_800E3590->unk220 = 4;
    D_800E3590->item492 = Node_FindWidgetByResourceId(arg0, slotRes(492));
    D_800E3590->item492->x = D_800E3590->item492->x - D_800E3590->item492->w;
    shift = D_800E3590->item492->w;
    if (shift < 0) {
        shift += 3;
    }
    D_800E3590->round492 = shift >> 2;
    adjust = D_800E3590->item492->w - ((shift >> 2) << 2);
    D_800E3590->item492->x = D_800E3590->item492->x + adjust;

    D_800E3590->item491 = Node_FindWidgetByResourceId(arg0, slotRes(491));
    D_800E3590->item491->x = D_800E3590->item491->x + D_800E3590->item491->w;
    shift = D_800E3590->item491->w;
    if (shift < 0) {
        shift += 3;
    }
    D_800E3590->round491 = shift >> 2;
    adjust = D_800E3590->item491->w - ((shift >> 2) << 2);
    D_800E3590->item491->x = D_800E3590->item491->x - adjust;

    Node_FindWidgetByResourceId(arg0, slotRes(488))->alpha = 110;
    D_800E3590->lookup486 = SmpFlicker_CreateFlickerWidget((s32)slotRes(486), 255);

    item = Node_FindWidgetByResourceId(arg0, slotRes(486));
    D_800E3590->item486 = item;
    Widget_SetWidgetFlag08(item, 0);

    item = Node_FindWidgetByResourceId(arg0, slotRes(563));
    D_800E3590->item563 = item;
    Widget_SetWidgetFlag08(item, 0);

    Node_FindWidgetByResourceId(arg0, slotRes(496))->alpha = 110;
    Node_FindWidgetByResourceId(arg0, slotRes(497))->alpha = 120;

    item = Node_FindWidgetByResourceId(arg0, slotRes(512));
    D_800E3590->item512 = item;
    Widget_SetWidgetFlag08(item, 0);

    D_800E3590->style = 0;
    D_800E3590->unk248 = 27;
    item = Node_FindWidgetByResourceId(arg0, slotRes(511));
    D_800E3590->item511 = item;
    Widget_SetWidgetFlag08(item, 0);

    D_800E3590->item511->alpha = 0;
    D_800E3590->unk260 = 25;
    item = Node_FindWidgetByResourceId(arg0, slotRes(510));
    D_800E3590->item510 = item;

    D_800E3590->player = 0;
    D_800E3590->unk268 = -1;
    Focus_AdvanceActiveSlot(&D_800E3590->unk268);
    Focus_RefreshProfileStatistics();
    Focus_ShowUnlockedEntries(D_800E3590->style);
    Node_FindWidgetByResourceId(arg0, slotRes(493))->alpha = 110;
    D_800E3590->focus = 0;
    return 0;
}
#endif

/* 8041BEA8.CPP */
/* Steps the record screen's transition state machine: slides the two panels in or out, swaps the
   visible item groups as each phase's timer runs out, and while idle (state 3) pulses the cursor's
   style from the elapsed time and moves the cursor to the node now under focus. */

/* The hub spells D_800E3590 as the padded menu block; this unit's view of it is the published
   MenuRecAt108 struct, so each member use casts D_800E3590 to that view. */

extern void Menu_ReturnToPreviousScreen(void);

extern void SmpFlicker_StartFlicker(s32 fade, s32 speed);
extern NodeFrontendAnimateSlotSelectionMenu *SmpOverlay_GetSlotValue(void *handle, s32 index);

/* Focus_ShowUnlockedEntries is declared by span code_8041BEA8.h; no local extern needed. */

s32 Frontend_AnimateSlotSelectionMenu(s32 unused0, s32 unused1, s32 arg2) {
    NodeFrontendAnimateSlotSelectionMenu *node;

    switch (((MenuRecAt108 *) D_800E3590)->state) {
    case 1:
        ((MenuRecAt108 *) D_800E3590)->left->x += ((MenuRecAt108 *) D_800E3590)->leftStep;
        ((MenuRecAt108 *) D_800E3590)->right->x -= ((MenuRecAt108 *) D_800E3590)->rightStep;
        if (--((MenuRecAt108 *) D_800E3590)->timer <= 0) {
            SoundElement_PlayFlatSound(0xE79);
            /* NodeFrontendAnimateSlotSelectionMenu is the hub Item view's twin (style at 0x10, x/y at 0x14/0x16);
               E8D8 speaks Item, so the node slots cast to it here. */
            Widget_SetWidgetFlag08((func_8041F2A0_Item *) ((MenuRecAt108 *) D_800E3590)->groupA, 1);
            SmpFlicker_StartFlicker(((MenuRecAt108 *) D_800E3590)->fade, 4);
            ((MenuRecAt108 *) D_800E3590)->state = 4;
            ((MenuRecAt108 *) D_800E3590)->timer = 4;
        }
        break;
    case 2:
        ((MenuRecAt108 *) D_800E3590)->left->x -= ((MenuRecAt108 *) D_800E3590)->leftStep;
        ((MenuRecAt108 *) D_800E3590)->right->x += ((MenuRecAt108 *) D_800E3590)->rightStep;
        if (--((MenuRecAt108 *) D_800E3590)->timer <= 0) {
            ((MenuRecAt108 *) D_800E3590)->state = 3;
            MarkMenuEventHandled();
            Menu_ReturnToPreviousScreen();
            return 0;
        }
        break;
    case 4:
        if (SmpFlicker_IsFlickerIdle(((MenuRecAt108 *) D_800E3590)->fade) != 0) {
            SmpFlicker_RestoreFlickerValue(((MenuRecAt108 *) D_800E3590)->fade);
            ((MenuRecAt108 *) D_800E3590)->state = 6;
            ((MenuRecAt108 *) D_800E3590)->timer = 4;
            Widget_SetWidgetFlag08((func_8041F2A0_Item *) ((MenuRecAt108 *) D_800E3590)->groupB, 1);
            Widget_SetWidgetFlag08((func_8041F2A0_Item *) ((MenuRecAt108 *) D_800E3590)->groupC, 1);
        }
        break;
    case 5:
        SoundElement_PlayFlatSound(0xE78);
        ((MenuRecAt108 *) D_800E3590)->state = 2;
        ((MenuRecAt108 *) D_800E3590)->timer = 4;
        Widget_SetWidgetFlag08((func_8041F2A0_Item *) ((MenuRecAt108 *) D_800E3590)->groupB, 0);
        Widget_SetWidgetFlag08((func_8041F2A0_Item *) ((MenuRecAt108 *) D_800E3590)->groupC, 0);
        Widget_SetWidgetFlag08((func_8041F2A0_Item *) ((MenuRecAt108 *) D_800E3590)->groupA, 0);
        break;
    case 6:
        ((MenuRecAt108 *) D_800E3590)->styleValue += ((MenuRecAt108 *) D_800E3590)->styleStep;
        ((MenuRecAt108 *) D_800E3590)->groupC->style += ((MenuRecAt108 *) D_800E3590)->alphaStep;
        Focus_ShowUnlockedEntries(((MenuRecAt108 *) D_800E3590)->styleValue);
        if (--((MenuRecAt108 *) D_800E3590)->timer <= 0) {
            ((MenuRecAt108 *) D_800E3590)->groupC->style = 100;
            Focus_ShowUnlockedEntries(0x6E);
            ((MenuRecAt108 *) D_800E3590)->state = 3;
            Widget_SetWidgetFlag08((func_8041F2A0_Item *) ((MenuRecAt108 *) D_800E3590)->cursor, 1);
        }
        break;
    case 7:
        break;
    }

    if (((MenuRecAt108 *) D_800E3590)->state == 3) {
        ((MenuRecAt108 *) D_800E3590)->clock += arg2;
        ((MenuRecAt108 *) D_800E3590)->cursor->style = Math_Cosf((f32) ((MenuRecAt108 *) D_800E3590)->clock * 0.0033333334f) * 30.0f + 220.0f;
        node = SmpOverlay_GetSlotValue(((MenuRecAt108 *) D_800E3590)->handle, 0);
        if (node != ((MenuRecAt108 *) D_800E3590)->focus) {
            SoundElement_PlayFlatSound(0xE7E);
            if (((MenuRecAt108 *) D_800E3590)->focus != 0) {
                ((MenuRecAt108 *) D_800E3590)->focus->style = 0x6E;
            }
            ((MenuRecAt108 *) D_800E3590)->focus = node;
            node->style = 0xE1;
            Focus_RefreshUnlockedFocusLabel();
            Focus_UpdateFocusCaption();
            ((MenuRecAt108 *) D_800E3590)->cursor->x = node->x - 2;
            ((MenuRecAt108 *) D_800E3590)->cursor->y = node->y;
        }
    }
    return 0;
}

#if !(defined(VERSION_EU) || defined(VERSION_US))
unsigned int rodata_unresolved_800E14FC[1] = {
    0x00000000,
};
#endif
#if defined(VERSION_EU) || defined(VERSION_US)
const unsigned int rodata_unresolved_800E14FC[1] = {
    0x00000000,
};
#endif

/* 80406A88_2.CPP */

/* 80408AC4_19.CPP */
