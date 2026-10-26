#include "include_asm.h"
#include "FRONTEND/PAKMENU.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/NAME.H"
#include "TYPES.H"
#include "RENDER_2/8025DE50_5.H"
#include "COMMON/WIDGETRECAT1A.H"

/* Cancels player arg2's pickup when the state at 0x58 of its 2920-byte record is 12 and arg3 asks:
   sets the word at 0xBA0 to 2, clears 0xBA4, drops one from the count at 0xB9C, stamps 0x41 on
   that count's two-byte slot at 0xB8C when the slot is free, silences the sound handle taken from
   the player's entry of the slot array at 4 of the block, and reports the cancel through
   SoundElement_PlayFlatSound. Records 13 and above are left alone; the function always returns zero. */









extern void *SmpOverlay_GetSlotValue(s32 root, s32 player);

s32 PAKInterface_MoveNameCursorBackward(s32 unused0, s32 unused1, s32 arg2, s32 arg3) {
    struct ResourceSmpFlickerCreateFlickerWidget *sound;
    struct RowRecAtBA4 *row;
    char *base;
    u8 *mark;
    s32 index;
    s32 offset;
    s32 state;
    s32 count;

    index = arg2 & 0xFFFF;
    offset = index * 0xB68;
    state = ((struct RowRecAtBA4 *)(offset + (char *)D_800E54A4))->state;
    if (state == 0xD) {
        return 0;
    }
    if (state >= 0xE) {
        return 0;
    }
    if (state == 0xC && arg3 == 1) {
        sound = SmpOverlay_GetSlotValue(D_800E54A4->root, index);
        row = (struct RowRecAtBA4 *)(index * 0xB68 + (char *)D_800E54A4);
        row->phase = 2;
        count = row->count;
        row->timer = 0;
        if (count > 0) {
            row->count = count - 1;
        }
        base = (char *)D_800E54A4;
        mark = (u8 *)(base + ((((struct RowRecAtBA4 *)(offset + base))->count * 2) +
                              index * 0xB68) + 0xB8C);
        if (*mark == 0) {
            *mark = 0x41;
        }
        sound->value = 0xFF;
        SoundElement_PlayFlatSound(0xE74);
    }
    return 0;
}

/* Handles Controller Pak menu confirmations for the active channel, clearing its status on a confirmed state-12 prompt and returning focus to an enabled widget in the list states. */
#include "COMMON/NAME.H"
s32 Smos_GetControlRepeatLimit();                                /* extern */
s32 Frontend_ListHasFlag100(void *);                          /* extern */
void SmpOverlay_ShowSlotNode(s32, s32, void *);                  /* extern */
void PAKInterface_RelabelSlotRows(s32);                               /* extern */
void PAKInterface_UpdatePlayerControlRows(s32);                               /* extern */
void PAKInterface_ScrollNoteList(s32, s32);                            /* extern */
void PAKInterface_DecrementNameCharacter(s32);                               /* extern */
extern PakMenuController *D_800E54A4;                    

s32 PAKInterface_HandleNextPanelSelection(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 temp_s0;
    s32 player;
    s32 playerState;
    MenuWidget *var_s0;
    MenuWidget *var_s0_2;
    MenuWidget *var_s0_3;

    player = arg2 & 0xFFFF;
    playerState = D_800E54A4->players[player].state;
    switch (playerState) {
    case 12:
        temp_s0 = XMath_AbsoluteInteger(arg4);
        if (temp_s0 < Smos_GetControlRepeatLimit()) {
            D_800E54A4->players[player].nameTimer = 0;
            D_800E54A4->players[player].namePhase = 2;
        }
        if (arg3 == 1) {
            MarkMenuEventHandled();
            PAKInterface_DecrementNameCharacter(player);
            D_800E54A4->players[player].namePhase = 0;
            SoundElement_PlayFlatSound(0xE81);
            return 0;
        }
        return 0;
    case 4:
        if (arg3 == 1) {
            MarkMenuEventHandled();
            PAKInterface_ScrollNoteList(player, 1);
            D_800E54A4->selected[player] = 0;
            SoundElement_PlayFlatSound(0xE74);
            return 0;
        }
        return 0;
    case 13:
        if ((D_800E54A4->players[player].sub == 6) && (arg3 == 1)) {
            MarkMenuEventHandled();
            var_s0 = ((MenuWidget *)SmpOverlay_GetSlotValue(D_800E54A4->root, player))->next;
loop_11:
            if (Frontend_ListHasFlag100(var_s0) != 0) {
                var_s0 = var_s0->next;
                goto loop_11;
            }
            SmpOverlay_ShowSlotNode((D_800E54A4->root), player, var_s0);
            SoundElement_PlayFlatSound(0xE74);
            return 0;
        }
        return 0;
    case 22:
        if (arg3 == 1) {
            var_s0_2 = ((MenuWidget *)SmpOverlay_GetSlotValue(D_800E54A4->root, player))->next;
loop_16:
            if (Frontend_ListHasFlag100(var_s0_2) != 0) {
                var_s0_2 = var_s0_2->next;
                goto loop_16;
            }
            SmpOverlay_ShowSlotNode((D_800E54A4->root), player, var_s0_2);
            PAKInterface_RelabelSlotRows(player);
        }
        goto block_24;
    case 27:
        if (arg3 == 1) {
            var_s0_3 = ((MenuWidget *)SmpOverlay_GetSlotValue(D_800E54A4->root, player))->next;
loop_21:
            if (Frontend_ListHasFlag100(var_s0_3) != 0) {
                var_s0_3 = var_s0_3->next;
                goto loop_21;
            }
            SmpOverlay_ShowSlotNode((D_800E54A4->root), player, var_s0_3);
            PAKInterface_UpdatePlayerControlRows(player);
        }
block_24:
        MarkMenuEventHandled();
        break;
    }
    return 0;
}

/* Handles Controller Pak menu confirmations and returns focus to an enabled widget for the active channel. */
extern s32 Smos_GetControlRepeatLimit(void);
extern void MarkMenuEventHandled(void);
extern s32 Frontend_ListHasFlag100(void *);
extern void SmpOverlay_ShowSlotNode(s32, s32, void *);
extern void PAKInterface_RelabelSlotRows(s32);
extern void PAKInterface_UpdatePlayerControlRows(s32);
extern void PAKInterface_ScrollNoteList(s32, s32);
extern void PAKInterface_IncrementNameCharacter(s32);
s32 PAKInterface_HandlePakMenuConfirm(s32 unused0, s32 unused1, s32 packedPlayerEvent, s32 pressState, s32 arg4) {
    NodeRecAt44 *node;
    s32 player;

    player = packedPlayerEvent & 0xFFFF;
    switch (D_800E54A4->players[player].state) {
    case 12:
        if (XMath_AbsoluteInteger(arg4) < Smos_GetControlRepeatLimit()) {
            D_800E54A4->players[player].nameTimer = 0;
            D_800E54A4->players[player].namePhase = 2;
        }
        if (pressState == 1) {
            MarkMenuEventHandled();
            D_800E54A4->players[player].namePhase = pressState;
            PAKInterface_IncrementNameCharacter(player);
            SoundElement_PlayFlatSound(0xE81);
        }
        return 0;
    case 4:
        if (pressState == 1) {
            MarkMenuEventHandled();
            PAKInterface_ScrollNoteList(player, 0);
            D_800E54A4->selected[player] = 0;
            SoundElement_PlayFlatSound(0xE74);
        }
        return 0;
    case 13:
        if (D_800E54A4->players[player].sub == 6 && pressState == 1) {
            MarkMenuEventHandled();
            node = SmpOverlay_GetSlotValue(D_800E54A4->root, player);
            node = node->ref2C;
            while (Frontend_ListHasFlag100(node) != 0) {
                node = node->ref2C;
            }
            SmpOverlay_ShowSlotNode(D_800E54A4->root, player, node);
            SoundElement_PlayFlatSound(0xE74);
        }
        return 0;
    case 22:
        if (pressState == 1) {
            node = SmpOverlay_GetSlotValue(D_800E54A4->root, player);
            node = node->ref2C;
            while (Frontend_ListHasFlag100(node) != 0) {
                node = node->ref2C;
            }
            SmpOverlay_ShowSlotNode(D_800E54A4->root, player, node);
            PAKInterface_RelabelSlotRows(player);
        }
        MarkMenuEventHandled();
        break;
    case 27:
        if (pressState == 1) {
            node = SmpOverlay_GetSlotValue(D_800E54A4->root, player);
            node = node->ref2C;
            while (Frontend_ListHasFlag100(node) != 0) {
                node = node->ref2C;
            }
            SmpOverlay_ShowSlotNode(D_800E54A4->root, player, node);
            PAKInterface_UpdatePlayerControlRows(player);
        }
        MarkMenuEventHandled();
        break;
    }
    return 0;
}
