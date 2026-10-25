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
   Render_PlayFlatSound. Records 13 and above are left alone; the function always returns zero. */









extern void *Menu_GetSlotValue(s32 root, s32 player);

s32 func_80430028_de(s32 unused0, s32 unused1, s32 arg2, s32 arg3) {
    struct Resource_func_80419E54_de *sound;
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
        sound = Menu_GetSlotValue(D_800E54A4->root, index);
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
        Render_PlayFlatSound(0xE74);
    }
    return 0;
}

/* Handles Controller Pak menu confirmations for the active channel, clearing its status on a confirmed state-12 prompt and returning focus to an enabled widget in the list states. */
#include "COMMON/NAME.H"
s32 func_80299B4C_de();                                /* extern */
s32 Frontend_ListHasFlag100(void *);                          /* extern */
void Menu_ShowSlotNode(s32, s32, void *);                  /* extern */
void Frontend_RelabelSlotRows(s32);                               /* extern */
void Frontend_UpdatePlayerControlRows(s32);                               /* extern */
void func_80434250_de(s32, s32);                            /* extern */
void func_80434EF4_de(s32);                               /* extern */
extern PakMenuController *D_800E54A4;                    

s32 func_80430118_de(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 temp_s0;
    s32 temp_s1;
    s32 temp_v0;
    MenuWidget *var_s0;
    MenuWidget *var_s0_2;
    MenuWidget *var_s0_3;

    temp_s1 = arg2 & 0xFFFF;
    temp_v0 = D_800E54A4->players[temp_s1].state;
    switch (temp_v0) {
    case 12:
        temp_s0 = func_8029DB58_de(arg4);
        if (temp_s0 < func_80299B4C_de()) {
            D_800E54A4->players[temp_s1].nameTimer = 0;
            D_800E54A4->players[temp_s1].namePhase = 2;
        }
        if (arg3 == 1) {
            MarkMenuEventHandled();
            func_80434EF4_de(temp_s1);
            D_800E54A4->players[temp_s1].namePhase = 0;
            Render_PlayFlatSound(0xE81);
            return 0;
        }
        return 0;
    case 4:
        if (arg3 == 1) {
            MarkMenuEventHandled();
            func_80434250_de(temp_s1, 1);
            D_800E54A4->selected[temp_s1] = 0;
            Render_PlayFlatSound(0xE74);
            return 0;
        }
        return 0;
    case 13:
        if ((D_800E54A4->players[temp_s1].sub == 6) && (arg3 == 1)) {
            MarkMenuEventHandled();
            var_s0 = ((MenuWidget *)Menu_GetSlotValue(D_800E54A4->root, temp_s1))->next;
loop_11:
            if (Frontend_ListHasFlag100(var_s0) != 0) {
                var_s0 = var_s0->next;
                goto loop_11;
            }
            Menu_ShowSlotNode((D_800E54A4->root), temp_s1, var_s0);
            Render_PlayFlatSound(0xE74);
            return 0;
        }
        return 0;
    case 22:
        if (arg3 == 1) {
            var_s0_2 = ((MenuWidget *)Menu_GetSlotValue(D_800E54A4->root, temp_s1))->next;
loop_16:
            if (Frontend_ListHasFlag100(var_s0_2) != 0) {
                var_s0_2 = var_s0_2->next;
                goto loop_16;
            }
            Menu_ShowSlotNode((D_800E54A4->root), temp_s1, var_s0_2);
            Frontend_RelabelSlotRows(temp_s1);
        }
        goto block_24;
    case 27:
        if (arg3 == 1) {
            var_s0_3 = ((MenuWidget *)Menu_GetSlotValue(D_800E54A4->root, temp_s1))->next;
loop_21:
            if (Frontend_ListHasFlag100(var_s0_3) != 0) {
                var_s0_3 = var_s0_3->next;
                goto loop_21;
            }
            Menu_ShowSlotNode((D_800E54A4->root), temp_s1, var_s0_3);
            Frontend_UpdatePlayerControlRows(temp_s1);
        }
block_24:
        MarkMenuEventHandled();
        break;
    }
    return 0;
}

/* Handles Controller Pak menu confirmations and returns focus to an enabled widget for the active channel. */
extern s32 func_80299B4C_de(void);
extern s32 func_8029DB58_de(s32);
extern void MarkMenuEventHandled(void);
extern s32 Frontend_ListHasFlag100(void *);
extern void Menu_ShowSlotNode(s32, s32, void *);
extern void Frontend_RelabelSlotRows(s32);
extern void Frontend_UpdatePlayerControlRows(s32);
extern void func_80434250_de(s32, s32);
extern void func_80434E34_de(s32);
s32 Frontend_HandlePakMenuConfirm(s32 unused0, s32 unused1, s32 arg2, s32 arg3, s32 arg4) {
    NodeRecAt44 *node;
    s32 player;

    player = arg2 & 0xFFFF;
    switch (D_800E54A4->players[player].state) {
    case 12:
        if (func_8029DB58_de(arg4) < func_80299B4C_de()) {
            D_800E54A4->players[player].nameTimer = 0;
            D_800E54A4->players[player].namePhase = 2;
        }
        if (arg3 == 1) {
            MarkMenuEventHandled();
            D_800E54A4->players[player].namePhase = arg3;
            func_80434E34_de(player);
            Render_PlayFlatSound(0xE81);
        }
        return 0;
    case 4:
        if (arg3 == 1) {
            MarkMenuEventHandled();
            func_80434250_de(player, 0);
            D_800E54A4->selected[player] = 0;
            Render_PlayFlatSound(0xE74);
        }
        return 0;
    case 13:
        if (D_800E54A4->players[player].sub == 6 && arg3 == 1) {
            MarkMenuEventHandled();
            node = Menu_GetSlotValue(D_800E54A4->root, player);
            node = node->ref2C;
            while (Frontend_ListHasFlag100(node) != 0) {
                node = node->ref2C;
            }
            Menu_ShowSlotNode(D_800E54A4->root, player, node);
            Render_PlayFlatSound(0xE74);
        }
        return 0;
    case 22:
        if (arg3 == 1) {
            node = Menu_GetSlotValue(D_800E54A4->root, player);
            node = node->ref2C;
            while (Frontend_ListHasFlag100(node) != 0) {
                node = node->ref2C;
            }
            Menu_ShowSlotNode(D_800E54A4->root, player, node);
            Frontend_RelabelSlotRows(player);
        }
        MarkMenuEventHandled();
        break;
    case 27:
        if (arg3 == 1) {
            node = Menu_GetSlotValue(D_800E54A4->root, player);
            node = node->ref2C;
            while (Frontend_ListHasFlag100(node) != 0) {
                node = node->ref2C;
            }
            Menu_ShowSlotNode(D_800E54A4->root, player, node);
            Frontend_UpdatePlayerControlRows(player);
        }
        MarkMenuEventHandled();
        break;
    }
    return 0;
}
