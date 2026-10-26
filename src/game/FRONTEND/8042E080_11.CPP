
/* Updates the selected player's setup panel and its linked controls. */
#include "TYPES.H"
#include "FRONTEND/PAKMENU.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SELECTIONSCREENSTATE.H"
#include "COMMON/MENU_SETUP_VERSIONS.H"
#include "FRONTEND/8040B45C_32.H"
/* menu_setup_versions.h declares this scalar only cart-guarded; the slot-error scalar is real in every cart */
extern s32 D_800DF4C4;
#include "COMMON/UNUSED.H"
typedef struct SetupTextNode SetupTextNode;
typedef struct SetupRosterChoice SetupRosterChoice;
typedef struct SetupRosterSlot SetupRosterSlot;
typedef struct SetupCharacterState SetupCharacterState;
typedef struct SetupLinkedLabel SetupLinkedLabel;
typedef struct SetupRosterRecord SetupRosterRecord;
struct SetupTextNode {
    char pad0[0x34];
    s32 unk34;
    void* unk38;
};
struct SetupRosterChoice {
    char pad0[0x64];
    void* unk64;
    char pad64[0xADC];
    s32 unkB44;
};
struct SetupRosterSlot {
    char pad0[0x64];
    void* unk64;
    char pad64[0xAC8];
    s32 unkB30;
};
struct SetupCharacterState {
    char pad0[0xBA0];
    s32 unkBA0;
    s32 unkBA4;
};
struct SetupLinkedLabel {
    char pad0[0x8];
    MenuWidget * unk8;
    char pad8[0x4];
    u8 unk10;
    char pad10[0x27];
    void* unk38;
};
struct SetupRosterRecord {
    char pad0[0x64];
    void* unk64;
    char pad64[0xB1C];
    s32 unkB84;
};

typedef struct {
    char pad0[0x58];
    u32 state;
    char pad5C[0x8];
    void *panel;
    void *root;
    char pad6C[0x4];
    char slot70[0x668];
    char slot6D8[0x4B4];
    s8 chars[2];
    char padB8E[0xE];
    s32 valueB9C;
    char padBA0[0x8];
    char textBA8[1];
} SetupPlayerPanel;





int Control_IsControllerConnected(int);
u8 * XPlus_CopyString(u8 *, u8 *);
char * Frontend_GetStringByIndex(s32);
void SmpOverlay_SetSlotValue(void *, s32, s32);
s32 SmpOverlay_GetSlotValue(void *, s32);
void SmpOverlay_ShowSlotNode(void *, s32, void *);
void Frontend_ReplaceTextOccurrences(char *, char *, char *);
void PAKInterface_BuildProfileSlotList(s32);
void PAKInterface_RelabelSlotRows(s32);
void PAKInterface_LoadNoteList(s32);
void PAKInterface_LabelActiveProfileRows(s32);
s32 func_80435528_de(void);
void PAKInterface_BeginScreenExit(s32);
void func_8043C278_de(s32 *);
void PAKInterface_UpdatePlayerControlRows(s32);                    /* extern */


/* The slot-error scalar is real external storage in every ROM version. */
























void PAKInterface_RefreshPlayerPanel(s32 playerIndex) {



    s32 text_node; 

    s32 itemIndex; 

    s32 slot_active;

 
 
    s32 var_a0;
    s32 characterIndex;
    s32 slotLabelId;

    
    s32 selectionOrLabel; 
    s32 playerLinkOffset;

    s8 *temp_s1;
    s8 *temp_copy_source;
    u16 var_a1;
    u16 var_a1_2;
    u16 var_a1_3;
    u32 temp_v1;
    u32 temp_v1_2;
    u32 temp_v1_4;
    void *temp_a0;
    func_8041F2A0_Item *temp_v0;
    func_8041F2A0_Item *temp_v0_10;
    SetupRosterSlot *temp_v0_11;
    func_8041F2A0_Item *temp_v0_12;
    func_8041F2A0_Item *temp_v0_13;
    func_8041F2A0_Item *temp_v0_14;
    func_8041F2A0_Item *temp_v0_16;
    func_8041F2A0_Item *temp_v0_17;
    func_8041F2A0_Item *temp_v0_18;
    func_8041F2A0_Item *temp_v0_19;
    SetupRosterRecord *temp_v0_20;
    func_8041F2A0_Item *temp_v0_21;
    func_8041F2A0_Item *temp_v0_22;
    func_8041F2A0_Item *temp_v0_23;
    func_8041F2A0_Item *temp_v0_24;
    func_8041F2A0_Item *temp_v0_25;
    func_8041F2A0_Item *temp_v0_26;
    func_8041F2A0_Item *temp_v0_27;
    func_8041F2A0_Item *temp_v0_3;
    func_8041F2A0_Item *temp_v0_4;
    func_8041F2A0_Item *temp_v0_5;
    func_8041F2A0_Item *temp_v0_6;
    func_8041F2A0_Item *temp_v0_7;
    func_8041F2A0_Item *temp_v0_8;
    SetupRosterChoice *temp_v0_9;
    SetupCharacterState *temp_v1_3;
    void *var_a0_2;
    void *var_a0_3;
    void *var_a0_4;
    PakMenuController *var_v1;

    temp_a0 = D_800E54A4->players[playerIndex].menuWidget;
    if (temp_a0 != 0) {
        Frontend_SetWidgetFlag08((func_8041F2A0_Item *) temp_a0, 0);
    }
    Frontend_SetWidgetFlag40(SmpOverlay_GetSlotValue(D_800E54A4->root, playerIndex), 0);
    /* the published B6E8 takes the controller handle as a plain scalar */
    SmpOverlay_ShowSlotById((s32) D_800E54A4->field0, playerIndex, SETUP_LABEL_ID);
    temp_v1 = D_800E54A4->players[playerIndex].state;
    switch (temp_v1) {                              /* switch 1 */
    case 0:                                         /* switch 1 */

        temp_v0 = Frontend_FindWidgetByResourceId(D_800E54A4->players[playerIndex].sprite, PANEL_ROOT_ID);
        D_800E54A4->players[playerIndex].menuWidget = temp_v0;
        Frontend_SetWidgetFlag08(temp_v0, 1);
        text_node = (s32)Frontend_FindWidgetByResourceId(D_800E54A4->players[playerIndex].menuWidget, PANEL_TEXT_ID);
        ((SetupTextNode *)text_node)->unk38 = D_800E54A4->players[playerIndex].nameText;
        temp_v1_2 = D_800E54A4->phase;
        
        switch (temp_v1_2) {                        /* switch 2 */
        case 1:                                     /* switch 2 */
        case 7:                                     /* switch 2 */
            temp_s1 = Frontend_GetStringByIndex(MODE_17_ID);
            temp_copy_source = Frontend_GetStringByIndex(((SetupTextNode *)text_node)->unk34);
            break;
        case 2:                                     /* switch 2 */
            temp_s1 = Frontend_GetStringByIndex(MODE_2_ID);
            temp_copy_source = Frontend_GetStringByIndex(((SetupTextNode *)text_node)->unk34);
            break;
        case 3:                                     /* switch 2 */
            temp_s1 = Frontend_GetStringByIndex(MODE_3_ID);
            temp_copy_source = Frontend_GetStringByIndex(((SetupTextNode *)text_node)->unk34);
            break;
        case 4:                                     /* switch 2 */
        case 6:                                     /* switch 2 */
            temp_s1 = Frontend_GetStringByIndex(MODE_46_ID);
            temp_copy_source = Frontend_GetStringByIndex(((SetupTextNode *)text_node)->unk34);
            break;
        case 5:                                     /* switch 2 */
            temp_s1 = Frontend_GetStringByIndex(MODE_5_ID);
            temp_copy_source = Frontend_GetStringByIndex(((SetupTextNode *)text_node)->unk34);
            break;
        case 0:                                     /* switch 2 */
        default:                                    /* switch 2 */
            temp_s1 = Frontend_GetStringByIndex(MODE_DEFAULT_ID);
            temp_copy_source = Frontend_GetStringByIndex(((SetupTextNode *)text_node)->unk34);
            break;
        }


        XPlus_CopyString((&D_800E54A4->players[playerIndex])->nameText, temp_copy_source);
        Frontend_ReplaceTextOccurrences((&D_800E54A4->players[playerIndex])->nameText, g_modeToken, temp_s1);
        playerLinkOffset = playerIndex * 8;
        if (D_800E54A4->phase == 6) {
            Frontend_SetWidgetFlag08(Frontend_FindWidgetByResourceId(D_800E54A4->players[playerIndex].menuWidget, MODE_HIDE_ID), 0);
            playerLinkOffset = playerIndex * 8;
        }
        break;
    case 1:                                         /* switch 1 */

        temp_v0_3 = Frontend_FindWidgetByResourceId(D_800E54A4->players[playerIndex].sprite, UI_CASE_1_2EC);
        D_800E54A4->players[playerIndex].menuWidget = temp_v0_3;
        Frontend_SetWidgetFlag08(temp_v0_3, 1);
        SmpOverlay_ShowSlotNode(D_800E54A4->root, playerIndex, Frontend_FindWidgetByResourceId(D_800E54A4->players[playerIndex].menuWidget, UI_CASE_1_2EE));
        playerLinkOffset = playerIndex * 8;
        break;
    case 2:                                         /* switch 1 */

        var_a0_3 = D_800E54A4->players[playerIndex].sprite;
        var_a1_2 = UI_CASE_2_2D4;
block_36:
        temp_v0_4 = Frontend_FindWidgetByResourceId(var_a0_3, var_a1_2);
        D_800E54A4->players[playerIndex].menuWidget = temp_v0_4;
        Frontend_SetWidgetFlag08(temp_v0_4, 1);
        playerLinkOffset = playerIndex * 8;
        break;
    case 3:                                         /* switch 1 */

        temp_v0_5 = Frontend_FindWidgetByResourceId(D_800E54A4->players[playerIndex].sprite, UI_CASE_3_2BB);
        D_800E54A4->players[playerIndex].menuWidget = temp_v0_5;
        Frontend_SetWidgetFlag08(temp_v0_5, 1);
        SmpOverlay_ShowSlotNode(D_800E54A4->root, playerIndex, Frontend_FindWidgetByResourceId(D_800E54A4->players[playerIndex].menuWidget, UI_CASE_3_2BC));
        break;
    case 4:                                         /* switch 1 */

        temp_v0_6 = Frontend_FindWidgetByResourceId(D_800E54A4->players[playerIndex].sprite, UI_CASE_4_2D5);
        D_800E54A4->players[playerIndex].menuWidget = temp_v0_6;
        Frontend_SetWidgetFlag08(temp_v0_6, 1);
        SmpOverlay_ShowSlotNode(D_800E54A4->root, playerIndex, Frontend_FindWidgetByResourceId(D_800E54A4->players[playerIndex].menuWidget, UI_CASE_4_2DA));
        PAKInterface_LoadNoteList(playerIndex);
        playerLinkOffset = playerIndex * 8;
        break;
    case 22:                                        /* switch 1 */
        /* the panel slot is untyped storage; the hub types the E8D8 argument as the item */
        Frontend_SetWidgetFlag08((func_8041F2A0_Item *) D_800E54A4->players[playerIndex].menuWidget, 1);
        var_v1 = D_800E54A4;
        selectionOrLabel = 0;
        if (var_v1->links[0].state == 0) {
            do {
                var_v1 = (void *)((char *)var_v1 + sizeof(PakMenuLink));
                selectionOrLabel += 1;
            } while (var_v1->links[0].state == 0);
        }
        slotLabelId = SLOT_DEFAULT_ID;
        if (selectionOrLabel == 1) {
            goto case22_one;
        }
        if (selectionOrLabel >= 2) {
            goto case22_check_two;
        }
        if (selectionOrLabel == 0) {
            goto case22_selected;
        }
        goto case22_default;
case22_check_two:
        if (selectionOrLabel == 2) {
            goto case22_two;
        }
case22_check_three:
        if (selectionOrLabel == 3) {
            goto case22_three;
        }
case22_default:
        slotLabelId = SLOT_DEFAULT_ID;
        goto case22_selected;
case22_one:
        slotLabelId = SLOT_1_ID;
        goto case22_selected;
case22_two:
        slotLabelId = SLOT_2_ID;
        goto case22_selected;
case22_three:
        slotLabelId = SLOT_3_ID;
case22_selected:
        SmpOverlay_ShowSlotById((s32) D_800E54A4->field0, playerIndex, slotLabelId);
        PAKInterface_RelabelSlotRows(playerIndex);
        playerLinkOffset = playerIndex * 8;
        break;
    case 6:                                         /* switch 1 */

        temp_v0_7 = Frontend_FindWidgetByResourceId(D_800E54A4->players[playerIndex].sprite, UI_CASE_6_2E4);
        D_800E54A4->players[playerIndex].menuWidget = temp_v0_7;
        Frontend_SetWidgetFlag08(temp_v0_7, 1);
        SmpOverlay_ShowSlotNode(D_800E54A4->root, playerIndex, Frontend_FindWidgetByResourceId(D_800E54A4->players[playerIndex].menuWidget, UI_CASE_6_2E8));
        PAKInterface_LabelActiveProfileRows(playerIndex);
        playerLinkOffset = playerIndex * 8;
        break;
    case 7:                                         /* switch 1 */

        temp_v0_8 = Frontend_FindWidgetByResourceId(D_800E54A4->players[playerIndex].sprite, UI_CASE_7_2CA);
        D_800E54A4->players[playerIndex].menuWidget = temp_v0_8;
        Frontend_SetWidgetFlag08(temp_v0_8, 1);
        SmpOverlay_ShowSlotNode(D_800E54A4->root, playerIndex, Frontend_FindWidgetByResourceId(D_800E54A4->players[playerIndex].menuWidget, UI_CASE_7_2CC));

        var_a0_4 = D_800E54A4->players[playerIndex].menuWidget;
        selectionOrLabel = D_800E54A4->players[playerIndex].chosen;
        var_a1_3 = UI_CASE_7_2CB;

        (((MenuWidget *)(Frontend_FindWidgetByResourceId(var_a0_4, var_a1_3)))->text) = (&D_800E54A4->players[playerIndex])->slots[selectionOrLabel];
        goto block_84;
    case 8:                                         /* switch 1 */

        temp_v0_10 = Frontend_FindWidgetByResourceId(D_800E54A4->players[playerIndex].sprite, UI_CASE_8_2CE);
        D_800E54A4->players[playerIndex].menuWidget = temp_v0_10;
        Frontend_SetWidgetFlag08(temp_v0_10, 1);
        SmpOverlay_ShowSlotNode(D_800E54A4->root, playerIndex, Frontend_FindWidgetByResourceId(D_800E54A4->players[playerIndex].menuWidget, UI_CASE_8_2CF));

        selectionOrLabel = D_800E54A4->players[playerIndex].slot;
        temp_v0_10 = Frontend_FindWidgetByResourceId(D_800E54A4->players[playerIndex].menuWidget, UI_CASE_8_2CB);

        ((MenuWidget *)temp_v0_10)->text = D_800E54A4->players[playerIndex].names[selectionOrLabel].code;
        goto block_84;
    case 9:                                         /* switch 1 */

        temp_v0_12 = Frontend_FindWidgetByResourceId(D_800E54A4->players[playerIndex].sprite, UI_CASE_9_2C6);
        D_800E54A4->players[playerIndex].menuWidget = temp_v0_12;
        Frontend_SetWidgetFlag08(temp_v0_12, 1);
        SmpOverlay_ShowSlotNode(D_800E54A4->root, playerIndex, Frontend_FindWidgetByResourceId(D_800E54A4->players[playerIndex].menuWidget, UI_CASE_9_2C8));
        ((MenuWidget *)Frontend_FindWidgetByResourceId(D_800E54A4->players[playerIndex].menuWidget, UI_CASE_9_2C7))->text = D_800E54A4->players[D_800E54A4->links[0].player].slots[D_800E54A4->links[0].entry];
        goto block_84;
    case 10:                                        /* switch 1 */

        temp_v0_4 = Frontend_FindWidgetByResourceId(D_800E54A4->players[playerIndex].sprite, UI_CASE_10_2A4);
        D_800E54A4->players[playerIndex].menuWidget = temp_v0_4;
        Frontend_SetWidgetFlag08(temp_v0_4, 1);
        playerLinkOffset = playerIndex * 8;
        break;
    case 11:                                        /* switch 1 */

        temp_v0_13 = Frontend_FindWidgetByResourceId(D_800E54A4->players[playerIndex].sprite, UI_CASE_11_2D1);
        D_800E54A4->players[playerIndex].menuWidget = temp_v0_13;
        Frontend_SetWidgetFlag08(temp_v0_13, 1);
        SmpOverlay_ShowSlotNode(D_800E54A4->root, playerIndex, Frontend_FindWidgetByResourceId(D_800E54A4->players[playerIndex].menuWidget, UI_CASE_11_2D2));
        break;
    case 12:                                        /* switch 1 */

        temp_v0_14 = Frontend_FindWidgetByResourceId(D_800E54A4->players[playerIndex].sprite, UI_CASE_12_2F2);
        D_800E54A4->players[playerIndex].menuWidget = temp_v0_14;
        Frontend_SetWidgetFlag08(temp_v0_14, 1);
        itemIndex = 0;
        selectionOrLabel = (s32)Frontend_FindWidgetByResourceId(D_800E54A4->players[playerIndex].menuWidget, UI_CASE_12_2F3);
        SmpOverlay_ShowSlotNode(D_800E54A4->root, playerIndex, (void *)selectionOrLabel);
 

        D_800E54A4->players[playerIndex].nameCursor = 0;

        do {
            if (itemIndex == 0) {
                D_800E54A4->players[playerIndex].name[itemIndex].available = 0x41;
            } else {
                D_800E54A4->players[playerIndex].name[itemIndex].available = 0;
            }
            D_800E54A4->players[playerIndex].name[itemIndex].slot = 0;
            itemIndex++;
        } while (itemIndex < 7);

        D_800E54A4->players[playerIndex].nameTimer = 0;
        D_800E54A4->players[playerIndex].namePhase = 2;
        characterIndex = 0;
        do {
            ((SetupLinkedLabel *)selectionOrLabel)->unk10 = 0xFF;
            text_node = (s32)((SetupLinkedLabel *)selectionOrLabel)->unk8; 
            ((MenuWidget *)text_node)->text = &D_800E54A4->players[playerIndex].name[characterIndex].available;
            selectionOrLabel = (s32)((SetupLinkedLabel *)selectionOrLabel)->unk38;
            characterIndex += 1;
        } while (selectionOrLabel != 0);
        playerLinkOffset = playerIndex * 8;
        break;
    case 13:                                        /* switch 1 */

        temp_v0_16 = Frontend_FindWidgetByResourceId(D_800E54A4->players[playerIndex].sprite, UI_CASE_13_2AF);
        D_800E54A4->players[playerIndex].menuWidget = temp_v0_16;
        Frontend_SetWidgetFlag08(temp_v0_16, 1);
        SmpOverlay_ShowSlotNode(D_800E54A4->root, playerIndex, Frontend_FindWidgetByResourceId(D_800E54A4->players[playerIndex].menuWidget, UI_CASE_13_2B6));
        PAKInterface_BuildProfileSlotList(playerIndex);
        playerLinkOffset = playerIndex * 8;
        break;
    case 14:                                        /* switch 1 */
    case 17:                                        /* switch 1 */
        SmpOverlay_ShowSlotById((s32) D_800E54A4->field0, playerIndex, SETUP_LABEL_ID);
        SmpOverlay_SetSlotValue(D_800E54A4->root, playerIndex, 1);

        temp_v0_17 = Frontend_FindWidgetByResourceId(D_800E54A4->players[playerIndex].sprite, UI_CASE_17_2A5);
        D_800E54A4->players[playerIndex].menuWidget = temp_v0_17;
        Frontend_SetWidgetFlag08(temp_v0_17, 1);
        if (func_80435528_de() == 0) {
            temp_v1_4 = D_800E54A4->phase;
            if (temp_v1_4 == 4) {
                goto mode_default;
            }
            if ((s32)temp_v1_4 < 5) {
                goto mode_default;
            }
            if (temp_v1_4 == 5) {
                goto mode_five;
            }
            if (temp_v1_4 == 6) {
                goto mode_six;
            }
            goto mode_default;
mode_five:
            Tsmos_DeactivateControllerState();
            func_8043C278_de(D_800E54A4->menu);
            goto mode_end;
mode_six:
            {
                PAKInterface_BeginScreenExit(0x1D);
                if (D_800DF4C4 == 1) {
                    D_800DF4C0 -= 1;
                }
                if (D_800DF4C4 == 0) {
                    D_800DF4C0 = -1;
                }
                goto mode_end;
            }
mode_default:
            PAKInterface_BeginScreenExit(0x1B);
mode_end:;
        }
        playerLinkOffset = playerIndex * 8;
        break;
    case 15:                                        /* switch 1 */

        temp_v0_18 = Frontend_FindWidgetByResourceId(D_800E54A4->players[playerIndex].sprite, UI_CASE_15_2EF);
        D_800E54A4->players[playerIndex].menuWidget = temp_v0_18;
        Frontend_SetWidgetFlag08(temp_v0_18, 1);
        SmpOverlay_ShowSlotNode(D_800E54A4->root, playerIndex, Frontend_FindWidgetByResourceId(D_800E54A4->players[playerIndex].menuWidget, UI_CASE_15_2F1));
        break;
    case 16:                                        /* switch 1 */

        temp_v0_19 = Frontend_FindWidgetByResourceId(D_800E54A4->players[playerIndex].sprite, UI_CASE_16_2B7);
        D_800E54A4->players[playerIndex].menuWidget = temp_v0_19;
        Frontend_SetWidgetFlag08(temp_v0_19, 1);
        SmpOverlay_ShowSlotNode(D_800E54A4->root, playerIndex, Frontend_FindWidgetByResourceId(D_800E54A4->players[playerIndex].menuWidget, UI_CASE_16_2B9));
        var_a1_3 = UI_CASE_16_2BA;

        var_a0_4 = D_800E54A4->players[playerIndex].menuWidget;
        selectionOrLabel = D_800E54A4->players[playerIndex].record;
block_61:

        (((MenuWidget *)(Frontend_FindWidgetByResourceId(var_a0_4, var_a1_3)))->text) = (&D_800E54A4->players[playerIndex])->slots[selectionOrLabel];
        goto block_84;
    case 21:                                        /* switch 1 */

        temp_v0_21 = Frontend_FindWidgetByResourceId(D_800E54A4->players[playerIndex].sprite, UI_CASE_21_2E1);
        D_800E54A4->players[playerIndex].menuWidget = temp_v0_21;
        Frontend_SetWidgetFlag08(temp_v0_21, 1);
        SmpOverlay_ShowSlotNode(D_800E54A4->root, playerIndex, Frontend_FindWidgetByResourceId(D_800E54A4->players[playerIndex].menuWidget, UI_CASE_21_2E2));
        break;
    case 23:                                        /* switch 1 */

        temp_v0_22 = Frontend_FindWidgetByResourceId(D_800E54A4->players[playerIndex].sprite, UI_CASE_23_2AC);
        D_800E54A4->players[playerIndex].menuWidget = temp_v0_22;
        Frontend_SetWidgetFlag08(temp_v0_22, 1);
        SmpOverlay_ShowSlotNode(D_800E54A4->root, playerIndex, Frontend_FindWidgetByResourceId(D_800E54A4->players[playerIndex].menuWidget, UI_CASE_23_2AE));
        break;
    case 24:                                        /* switch 1 */

        temp_v0_23 = Frontend_FindWidgetByResourceId(D_800E54A4->players[playerIndex].sprite, UI_CASE_24_2A9);
        D_800E54A4->players[playerIndex].menuWidget = temp_v0_23;
        Frontend_SetWidgetFlag08(temp_v0_23, 1);
        SmpOverlay_ShowSlotNode(D_800E54A4->root, playerIndex, Frontend_FindWidgetByResourceId(D_800E54A4->players[playerIndex].menuWidget, UI_CASE_24_2AA));
        break;
    case 25:                                        /* switch 1 */

        temp_v0_24 = Frontend_FindWidgetByResourceId(D_800E54A4->players[playerIndex].sprite, UI_CASE_25_2EA);
        D_800E54A4->players[playerIndex].menuWidget = temp_v0_24;
        Frontend_SetWidgetFlag08(temp_v0_24, 1);
        SmpOverlay_ShowSlotNode(D_800E54A4->root, playerIndex, Frontend_FindWidgetByResourceId(D_800E54A4->players[playerIndex].menuWidget, UI_CASE_25_2EB));
        break;
    case 26:                                        /* switch 1 */

        temp_v0_25 = Frontend_FindWidgetByResourceId(D_800E54A4->players[playerIndex].sprite, UI_CASE_26_2A6);
        D_800E54A4->players[playerIndex].menuWidget = temp_v0_25;
        Frontend_SetWidgetFlag08(temp_v0_25, 1);
        SmpOverlay_ShowSlotNode(D_800E54A4->root, playerIndex, Frontend_FindWidgetByResourceId(D_800E54A4->players[playerIndex].menuWidget, UI_CASE_26_2A7));
        break;
case27_found:
        SmpOverlay_ShowSlotById((s32) D_800E54A4->field0, playerIndex, slotLabelId);
        goto case27_done;
    case 27:                                        /* switch 1 */
        Frontend_SetWidgetFlag08((func_8041F2A0_Item *) D_800E54A4->players[playerIndex].menuWidget, 1);
        itemIndex = 0;

        SmpOverlay_ShowSlotById((s32) D_800E54A4->field0, playerIndex, CHECK_0_ID);
        do {
loop_69:
        if (itemIndex == 1) {
            goto case27_one;
        }
        if (itemIndex >= 2) {
            goto case27_check_two;
        }
        if (itemIndex == 0) {
            goto case27_zero;
        }
        slotLabelId = CHECK_DEFAULT_ID;
        goto case27_selected;
case27_check_two:
        if (itemIndex == 2) {
            goto case27_two;
        }
        slotLabelId = CHECK_DEFAULT_ID;
        goto case27_selected;
case27_zero:
        slotLabelId = CHECK_0_ID;
        goto case27_selected;
case27_one:
        slotLabelId = CHECK_1_ID;
        goto case27_selected;
case27_two:
        slotLabelId = CHECK_2_ID;
case27_selected:
        slot_active = Control_IsControllerConnected(itemIndex);
        itemIndex += 1;
        if (slot_active == 1) {
            goto case27_found;
        }
        } while (itemIndex < 4);
case27_done:
        PAKInterface_UpdatePlayerControlRows(playerIndex);
        playerLinkOffset = playerIndex * 8;
        break;
    case 28:                                        /* switch 1 */

        temp_v0_26 = Frontend_FindWidgetByResourceId(D_800E54A4->players[playerIndex].sprite, UI_CASE_28_2DE);
        D_800E54A4->players[playerIndex].menuWidget = temp_v0_26;
        Frontend_SetWidgetFlag08(temp_v0_26, 1);
        SmpOverlay_ShowSlotNode(D_800E54A4->root, playerIndex, Frontend_FindWidgetByResourceId(D_800E54A4->players[playerIndex].menuWidget, UI_CASE_28_2DF));
        break;
    case 29:                                        /* switch 1 */

        temp_v0_27 = Frontend_FindWidgetByResourceId(D_800E54A4->players[playerIndex].sprite, UI_CASE_29_2BF);
        D_800E54A4->players[playerIndex].menuWidget = temp_v0_27;
        Frontend_SetWidgetFlag08(temp_v0_27, 1);
        SmpOverlay_ShowSlotNode(D_800E54A4->root, playerIndex, Frontend_FindWidgetByResourceId(D_800E54A4->players[playerIndex].menuWidget, UI_CASE_29_2C0));
        playerLinkOffset = playerIndex * 8;
        break;
    default:                                        /* switch 1 */
block_84:
        playerLinkOffset = playerIndex * 8;
        break;
    }
    ((SetupLinkedLabel *)D_800E54A4->players[playerIndex].menuWidget)->unk10 = 0x96;
}
