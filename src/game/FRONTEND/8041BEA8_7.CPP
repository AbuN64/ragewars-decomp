
#if defined(VERSION_US_REV1)
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
#include "TYPES.H"

/* D_800E3590 and its 528-byte block layout are spelled once in the closed hub as
 * func_8041F2A0_MenuBlock, shared with the neighbouring menu units that keep their own views over
 * the same block. */

/* The hub spells func_8041DB30_de; these two stay here, matching how the landed units that own
 * them define them: SmpOverlay_SetObjectValue writes the word at +0x6C of the object it is handed, and
 * Frontend_ShowUnlockedEntries takes the style word this block keeps at +0x0FC. */

/* The pool and style helpers take a word, while this unit and the window lookups carry the menu
 * tree as a pointer; the cast carries that pointer through unchanged. */
s32 Frontend_CreateSlotSelectionMenu(void *arg0) {
    func_8041F2A0_Item *item;
    s32 shift;
    s32 adjust;

    D_800E3590 = (func_8041F2A0_MenuBlock *) Cache_AllocateMemory(528);
    D_800E3590->root = arg0;
    D_800E3590->list = SmpOverlay_CreateOverlayNode((s32) arg0, 4);
    SmpOverlay_ShowSlotById((s32) arg0, 0, 513);
    SmpOverlay_ShowSlotById((s32) arg0, 1, 513);
    SmpOverlay_ShowSlotById((s32) arg0, 2, 513);
    SmpOverlay_ShowSlotById((s32) arg0, 3, 513);
    /* func_8041B610_de is published to this unit as handing back a word while SmpOverlay_SetObjectValue is
     * published as taking the pool object that word names; the cast puts that object view back on
     * the pool stored at +0x004 and carries it through unchanged. */
    SmpOverlay_SetObjectValue((struct Object6C *) D_800E3590->list, 1);

    D_800E3590->unk216 = 1;
    D_800E3590->unk220 = 4;
    D_800E3590->item492 = func_8040EC30_de(arg0, 492);
    D_800E3590->item492->x = D_800E3590->item492->x - D_800E3590->item492->w;
    shift = D_800E3590->item492->w;
    if (shift < 0) {
        shift += 3;
    }
    D_800E3590->round492 = shift >> 2;
    adjust = D_800E3590->item492->w - ((shift >> 2) << 2);
    D_800E3590->item492->x = D_800E3590->item492->x + adjust;

    D_800E3590->item491 = func_8040EC30_de(arg0, 491);
    D_800E3590->item491->x = D_800E3590->item491->x + D_800E3590->item491->w;
    shift = D_800E3590->item491->w;
    if (shift < 0) {
        shift += 3;
    }
    D_800E3590->round491 = shift >> 2;
    adjust = D_800E3590->item491->w - ((shift >> 2) << 2);
    D_800E3590->item491->x = D_800E3590->item491->x - adjust;

    func_8040EC30_de(arg0, 488)->alpha = 110;
    D_800E3590->lookup486 = func_80419E54_de(486, 255);

    item = func_8040EC30_de(arg0, 486);
    D_800E3590->item486 = item;
    Frontend_SetWidgetFlag08(item, 0);

    item = func_8040EC30_de(arg0, 563);
    D_800E3590->item563 = item;
    Frontend_SetWidgetFlag08(item, 0);

    func_8040EC30_de(arg0, 496)->alpha = 110;
    func_8040EC30_de(arg0, 497)->alpha = 120;

    item = func_8040EC30_de(arg0, 512);
    D_800E3590->item512 = item;
    Frontend_SetWidgetFlag08(item, 0);

    D_800E3590->style = 0;
    D_800E3590->unk248 = 27;
    item = func_8040EC30_de(arg0, 511);
    D_800E3590->item511 = item;
    Frontend_SetWidgetFlag08(item, 0);

    D_800E3590->item511->alpha = 0;
    D_800E3590->unk260 = 25;
    item = func_8040EC30_de(arg0, 510);
    D_800E3590->item510 = item;

    D_800E3590->player = 0;
    D_800E3590->unk268 = -1;
    Frontend_AdvanceActiveSlot(&D_800E3590->unk268);
    Frontend_RefreshProfileStatistics();
    Frontend_ShowUnlockedEntries(D_800E3590->style);
    func_8040EC30_de(arg0, 493)->alpha = 110;
    D_800E3590->focus = 0;
    return 0;
}
#endif
