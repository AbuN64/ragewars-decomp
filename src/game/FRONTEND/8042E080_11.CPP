
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
s32 PAKInterface_CountPendingPlayerPanels(void);
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
    s8 *panelTemplate;
    u16 var_a1;
    u16 var_a1_2;
    u16 var_a1_3;
    u32 panelState;
    u32 screenPhase;
    u32 exitPhase;
    void *previousPanel;
    func_8041F2A0_Item *idlePanel;
    func_8041F2A0_Item *notePanelOrLabel;
    SetupRosterSlot *temp_v0_11;
    func_8041F2A0_Item *linkedProfilePanel;
    func_8041F2A0_Item *stateElevenPanel;
    func_8041F2A0_Item *nameEntryPanel;
    func_8041F2A0_Item *profileListPanel;
    func_8041F2A0_Item *readyPanel;
    func_8041F2A0_Item *createProfilePanel;
    func_8041F2A0_Item *recordPanel;
    SetupRosterRecord *temp_v0_20;
    func_8041F2A0_Item *missingSavePanel;
    func_8041F2A0_Item *stateTwentyThreePanel;
    func_8041F2A0_Item *fullProfilesPanel;
    func_8041F2A0_Item *unavailableProfilesPanel;
    func_8041F2A0_Item *stateTwentySixPanel;
    func_8041F2A0_Item *stateTwentyEightPanel;
    func_8041F2A0_Item *stateTwentyNinePanel;
    func_8041F2A0_Item *pakErrorPanel;
    func_8041F2A0_Item *statusPanel;
    func_8041F2A0_Item *pakUnavailablePanel;
    func_8041F2A0_Item *noteListPanel;
    func_8041F2A0_Item *activeProfilesPanel;
    func_8041F2A0_Item *chosenProfilePanel;
    SetupRosterChoice *temp_v0_9;
    SetupCharacterState *temp_v1_3;
    void *var_a0_2;
    void *var_a0_3;
    void *var_a0_4;
    PakMenuController *linkScan;

    previousPanel = D_800E54A4->players[playerIndex].menuWidget;
    if (previousPanel != 0) {
        Frontend_SetWidgetFlag08((func_8041F2A0_Item *) previousPanel, 0);
    }
    Frontend_SetWidgetFlag40(SmpOverlay_GetSlotValue(D_800E54A4->root, playerIndex), 0);
    /* the published B6E8 takes the controller handle as a plain scalar */
    SmpOverlay_ShowSlotById((s32) D_800E54A4->field0, playerIndex, SETUP_LABEL_ID);
    panelState = D_800E54A4->players[playerIndex].state;
    switch (panelState) {                              /* switch 1 */
    case 0:                                         /* switch 1 */

        idlePanel = Frontend_FindWidgetByResourceId(D_800E54A4->players[playerIndex].sprite, PANEL_ROOT_ID);
        D_800E54A4->players[playerIndex].menuWidget = idlePanel;
        Frontend_SetWidgetFlag08(idlePanel, 1);
        text_node = (s32)Frontend_FindWidgetByResourceId(D_800E54A4->players[playerIndex].menuWidget, PANEL_TEXT_ID);
        ((SetupTextNode *)text_node)->unk38 = D_800E54A4->players[playerIndex].nameText;
        screenPhase = D_800E54A4->phase;
        
        switch (screenPhase) {                        /* switch 2 */
        case 1:                                     /* switch 2 */
        case 7:                                     /* switch 2 */
            temp_s1 = Frontend_GetStringByIndex(MODE_17_ID);
            panelTemplate = Frontend_GetStringByIndex(((SetupTextNode *)text_node)->unk34);
            break;
        case 2:                                     /* switch 2 */
            temp_s1 = Frontend_GetStringByIndex(MODE_2_ID);
            panelTemplate = Frontend_GetStringByIndex(((SetupTextNode *)text_node)->unk34);
            break;
        case 3:                                     /* switch 2 */
            temp_s1 = Frontend_GetStringByIndex(MODE_3_ID);
            panelTemplate = Frontend_GetStringByIndex(((SetupTextNode *)text_node)->unk34);
            break;
        case 4:                                     /* switch 2 */
        case 6:                                     /* switch 2 */
            temp_s1 = Frontend_GetStringByIndex(MODE_46_ID);
            panelTemplate = Frontend_GetStringByIndex(((SetupTextNode *)text_node)->unk34);
            break;
        case 5:                                     /* switch 2 */
            temp_s1 = Frontend_GetStringByIndex(MODE_5_ID);
            panelTemplate = Frontend_GetStringByIndex(((SetupTextNode *)text_node)->unk34);
            break;
        case 0:                                     /* switch 2 */
        default:                                    /* switch 2 */
            temp_s1 = Frontend_GetStringByIndex(MODE_DEFAULT_ID);
            panelTemplate = Frontend_GetStringByIndex(((SetupTextNode *)text_node)->unk34);
            break;
        }


        XPlus_CopyString((&D_800E54A4->players[playerIndex])->nameText, panelTemplate);
        Frontend_ReplaceTextOccurrences((&D_800E54A4->players[playerIndex])->nameText, g_modeToken, temp_s1);
        playerLinkOffset = playerIndex * 8;
        if (D_800E54A4->phase == 6) {
            Frontend_SetWidgetFlag08(Frontend_FindWidgetByResourceId(D_800E54A4->players[playerIndex].menuWidget, MODE_HIDE_ID), 0);
            playerLinkOffset = playerIndex * 8;
        }
        break;
    case 1:                                         /* switch 1 */

        pakErrorPanel = Frontend_FindWidgetByResourceId(D_800E54A4->players[playerIndex].sprite, UI_CASE_1_2EC);
        D_800E54A4->players[playerIndex].menuWidget = pakErrorPanel;
        Frontend_SetWidgetFlag08(pakErrorPanel, 1);
        SmpOverlay_ShowSlotNode(D_800E54A4->root, playerIndex, Frontend_FindWidgetByResourceId(D_800E54A4->players[playerIndex].menuWidget, UI_CASE_1_2EE));
        playerLinkOffset = playerIndex * 8;
        break;
    case 2:                                         /* switch 1 */

        var_a0_3 = D_800E54A4->players[playerIndex].sprite;
        var_a1_2 = UI_CASE_2_2D4;
block_36:
        statusPanel = Frontend_FindWidgetByResourceId(var_a0_3, var_a1_2);
        D_800E54A4->players[playerIndex].menuWidget = statusPanel;
        Frontend_SetWidgetFlag08(statusPanel, 1);
        playerLinkOffset = playerIndex * 8;
        break;
    case 3:                                         /* switch 1 */

        pakUnavailablePanel = Frontend_FindWidgetByResourceId(D_800E54A4->players[playerIndex].sprite, UI_CASE_3_2BB);
        D_800E54A4->players[playerIndex].menuWidget = pakUnavailablePanel;
        Frontend_SetWidgetFlag08(pakUnavailablePanel, 1);
        SmpOverlay_ShowSlotNode(D_800E54A4->root, playerIndex, Frontend_FindWidgetByResourceId(D_800E54A4->players[playerIndex].menuWidget, UI_CASE_3_2BC));
        break;
    case 4:                                         /* switch 1 */

        noteListPanel = Frontend_FindWidgetByResourceId(D_800E54A4->players[playerIndex].sprite, UI_CASE_4_2D5);
        D_800E54A4->players[playerIndex].menuWidget = noteListPanel;
        Frontend_SetWidgetFlag08(noteListPanel, 1);
        SmpOverlay_ShowSlotNode(D_800E54A4->root, playerIndex, Frontend_FindWidgetByResourceId(D_800E54A4->players[playerIndex].menuWidget, UI_CASE_4_2DA));
        PAKInterface_LoadNoteList(playerIndex);
        playerLinkOffset = playerIndex * 8;
        break;
    case 22:                                        /* switch 1 */
        /* the panel slot is untyped storage; the hub types the E8D8 argument as the item */
        Frontend_SetWidgetFlag08((func_8041F2A0_Item *) D_800E54A4->players[playerIndex].menuWidget, 1);
        linkScan = D_800E54A4;
        selectionOrLabel = 0;
        if (linkScan->links[0].state == 0) {
            do {
                linkScan = (void *)((char *)linkScan + sizeof(PakMenuLink));
                selectionOrLabel += 1;
            } while (linkScan->links[0].state == 0);
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

        activeProfilesPanel = Frontend_FindWidgetByResourceId(D_800E54A4->players[playerIndex].sprite, UI_CASE_6_2E4);
        D_800E54A4->players[playerIndex].menuWidget = activeProfilesPanel;
        Frontend_SetWidgetFlag08(activeProfilesPanel, 1);
        SmpOverlay_ShowSlotNode(D_800E54A4->root, playerIndex, Frontend_FindWidgetByResourceId(D_800E54A4->players[playerIndex].menuWidget, UI_CASE_6_2E8));
        PAKInterface_LabelActiveProfileRows(playerIndex);
        playerLinkOffset = playerIndex * 8;
        break;
    case 7:                                         /* switch 1 */

        chosenProfilePanel = Frontend_FindWidgetByResourceId(D_800E54A4->players[playerIndex].sprite, UI_CASE_7_2CA);
        D_800E54A4->players[playerIndex].menuWidget = chosenProfilePanel;
        Frontend_SetWidgetFlag08(chosenProfilePanel, 1);
        SmpOverlay_ShowSlotNode(D_800E54A4->root, playerIndex, Frontend_FindWidgetByResourceId(D_800E54A4->players[playerIndex].menuWidget, UI_CASE_7_2CC));

        var_a0_4 = D_800E54A4->players[playerIndex].menuWidget;
        selectionOrLabel = D_800E54A4->players[playerIndex].chosen;
        var_a1_3 = UI_CASE_7_2CB;

        (((MenuWidget *)(Frontend_FindWidgetByResourceId(var_a0_4, var_a1_3)))->text) = (&D_800E54A4->players[playerIndex])->slots[selectionOrLabel];
        goto block_84;
    case 8:                                         /* switch 1 */

        notePanelOrLabel = Frontend_FindWidgetByResourceId(D_800E54A4->players[playerIndex].sprite, UI_CASE_8_2CE);
        D_800E54A4->players[playerIndex].menuWidget = notePanelOrLabel;
        Frontend_SetWidgetFlag08(notePanelOrLabel, 1);
        SmpOverlay_ShowSlotNode(D_800E54A4->root, playerIndex, Frontend_FindWidgetByResourceId(D_800E54A4->players[playerIndex].menuWidget, UI_CASE_8_2CF));

        selectionOrLabel = D_800E54A4->players[playerIndex].slot;
        notePanelOrLabel = Frontend_FindWidgetByResourceId(D_800E54A4->players[playerIndex].menuWidget, UI_CASE_8_2CB);

        ((MenuWidget *)notePanelOrLabel)->text = D_800E54A4->players[playerIndex].names[selectionOrLabel].code;
        goto block_84;
    case 9:                                         /* switch 1 */

        linkedProfilePanel = Frontend_FindWidgetByResourceId(D_800E54A4->players[playerIndex].sprite, UI_CASE_9_2C6);
        D_800E54A4->players[playerIndex].menuWidget = linkedProfilePanel;
        Frontend_SetWidgetFlag08(linkedProfilePanel, 1);
        SmpOverlay_ShowSlotNode(D_800E54A4->root, playerIndex, Frontend_FindWidgetByResourceId(D_800E54A4->players[playerIndex].menuWidget, UI_CASE_9_2C8));
        ((MenuWidget *)Frontend_FindWidgetByResourceId(D_800E54A4->players[playerIndex].menuWidget, UI_CASE_9_2C7))->text = D_800E54A4->players[D_800E54A4->links[0].player].slots[D_800E54A4->links[0].entry];
        goto block_84;
    case 10:                                        /* switch 1 */

        statusPanel = Frontend_FindWidgetByResourceId(D_800E54A4->players[playerIndex].sprite, UI_CASE_10_2A4);
        D_800E54A4->players[playerIndex].menuWidget = statusPanel;
        Frontend_SetWidgetFlag08(statusPanel, 1);
        playerLinkOffset = playerIndex * 8;
        break;
    case 11:                                        /* switch 1 */

        stateElevenPanel = Frontend_FindWidgetByResourceId(D_800E54A4->players[playerIndex].sprite, UI_CASE_11_2D1);
        D_800E54A4->players[playerIndex].menuWidget = stateElevenPanel;
        Frontend_SetWidgetFlag08(stateElevenPanel, 1);
        SmpOverlay_ShowSlotNode(D_800E54A4->root, playerIndex, Frontend_FindWidgetByResourceId(D_800E54A4->players[playerIndex].menuWidget, UI_CASE_11_2D2));
        break;
    case 12:                                        /* switch 1 */

        nameEntryPanel = Frontend_FindWidgetByResourceId(D_800E54A4->players[playerIndex].sprite, UI_CASE_12_2F2);
        D_800E54A4->players[playerIndex].menuWidget = nameEntryPanel;
        Frontend_SetWidgetFlag08(nameEntryPanel, 1);
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

        profileListPanel = Frontend_FindWidgetByResourceId(D_800E54A4->players[playerIndex].sprite, UI_CASE_13_2AF);
        D_800E54A4->players[playerIndex].menuWidget = profileListPanel;
        Frontend_SetWidgetFlag08(profileListPanel, 1);
        SmpOverlay_ShowSlotNode(D_800E54A4->root, playerIndex, Frontend_FindWidgetByResourceId(D_800E54A4->players[playerIndex].menuWidget, UI_CASE_13_2B6));
        PAKInterface_BuildProfileSlotList(playerIndex);
        playerLinkOffset = playerIndex * 8;
        break;
    case 14:                                        /* switch 1 */
    case 17:                                        /* switch 1 */
        SmpOverlay_ShowSlotById((s32) D_800E54A4->field0, playerIndex, SETUP_LABEL_ID);
        SmpOverlay_SetSlotValue(D_800E54A4->root, playerIndex, 1);

        readyPanel = Frontend_FindWidgetByResourceId(D_800E54A4->players[playerIndex].sprite, UI_CASE_17_2A5);
        D_800E54A4->players[playerIndex].menuWidget = readyPanel;
        Frontend_SetWidgetFlag08(readyPanel, 1);
        if (PAKInterface_CountPendingPlayerPanels() == 0) {
            exitPhase = D_800E54A4->phase;
            if (exitPhase == 4) {
                goto mode_default;
            }
            if ((s32)exitPhase < 5) {
                goto mode_default;
            }
            if (exitPhase == 5) {
                goto mode_five;
            }
            if (exitPhase == 6) {
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

        createProfilePanel = Frontend_FindWidgetByResourceId(D_800E54A4->players[playerIndex].sprite, UI_CASE_15_2EF);
        D_800E54A4->players[playerIndex].menuWidget = createProfilePanel;
        Frontend_SetWidgetFlag08(createProfilePanel, 1);
        SmpOverlay_ShowSlotNode(D_800E54A4->root, playerIndex, Frontend_FindWidgetByResourceId(D_800E54A4->players[playerIndex].menuWidget, UI_CASE_15_2F1));
        break;
    case 16:                                        /* switch 1 */

        recordPanel = Frontend_FindWidgetByResourceId(D_800E54A4->players[playerIndex].sprite, UI_CASE_16_2B7);
        D_800E54A4->players[playerIndex].menuWidget = recordPanel;
        Frontend_SetWidgetFlag08(recordPanel, 1);
        SmpOverlay_ShowSlotNode(D_800E54A4->root, playerIndex, Frontend_FindWidgetByResourceId(D_800E54A4->players[playerIndex].menuWidget, UI_CASE_16_2B9));
        var_a1_3 = UI_CASE_16_2BA;

        var_a0_4 = D_800E54A4->players[playerIndex].menuWidget;
        selectionOrLabel = D_800E54A4->players[playerIndex].record;
block_61:

        (((MenuWidget *)(Frontend_FindWidgetByResourceId(var_a0_4, var_a1_3)))->text) = (&D_800E54A4->players[playerIndex])->slots[selectionOrLabel];
        goto block_84;
    case 21:                                        /* switch 1 */

        missingSavePanel = Frontend_FindWidgetByResourceId(D_800E54A4->players[playerIndex].sprite, UI_CASE_21_2E1);
        D_800E54A4->players[playerIndex].menuWidget = missingSavePanel;
        Frontend_SetWidgetFlag08(missingSavePanel, 1);
        SmpOverlay_ShowSlotNode(D_800E54A4->root, playerIndex, Frontend_FindWidgetByResourceId(D_800E54A4->players[playerIndex].menuWidget, UI_CASE_21_2E2));
        break;
    case 23:                                        /* switch 1 */

        stateTwentyThreePanel = Frontend_FindWidgetByResourceId(D_800E54A4->players[playerIndex].sprite, UI_CASE_23_2AC);
        D_800E54A4->players[playerIndex].menuWidget = stateTwentyThreePanel;
        Frontend_SetWidgetFlag08(stateTwentyThreePanel, 1);
        SmpOverlay_ShowSlotNode(D_800E54A4->root, playerIndex, Frontend_FindWidgetByResourceId(D_800E54A4->players[playerIndex].menuWidget, UI_CASE_23_2AE));
        break;
    case 24:                                        /* switch 1 */

        fullProfilesPanel = Frontend_FindWidgetByResourceId(D_800E54A4->players[playerIndex].sprite, UI_CASE_24_2A9);
        D_800E54A4->players[playerIndex].menuWidget = fullProfilesPanel;
        Frontend_SetWidgetFlag08(fullProfilesPanel, 1);
        SmpOverlay_ShowSlotNode(D_800E54A4->root, playerIndex, Frontend_FindWidgetByResourceId(D_800E54A4->players[playerIndex].menuWidget, UI_CASE_24_2AA));
        break;
    case 25:                                        /* switch 1 */

        unavailableProfilesPanel = Frontend_FindWidgetByResourceId(D_800E54A4->players[playerIndex].sprite, UI_CASE_25_2EA);
        D_800E54A4->players[playerIndex].menuWidget = unavailableProfilesPanel;
        Frontend_SetWidgetFlag08(unavailableProfilesPanel, 1);
        SmpOverlay_ShowSlotNode(D_800E54A4->root, playerIndex, Frontend_FindWidgetByResourceId(D_800E54A4->players[playerIndex].menuWidget, UI_CASE_25_2EB));
        break;
    case 26:                                        /* switch 1 */

        stateTwentySixPanel = Frontend_FindWidgetByResourceId(D_800E54A4->players[playerIndex].sprite, UI_CASE_26_2A6);
        D_800E54A4->players[playerIndex].menuWidget = stateTwentySixPanel;
        Frontend_SetWidgetFlag08(stateTwentySixPanel, 1);
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

        stateTwentyEightPanel = Frontend_FindWidgetByResourceId(D_800E54A4->players[playerIndex].sprite, UI_CASE_28_2DE);
        D_800E54A4->players[playerIndex].menuWidget = stateTwentyEightPanel;
        Frontend_SetWidgetFlag08(stateTwentyEightPanel, 1);
        SmpOverlay_ShowSlotNode(D_800E54A4->root, playerIndex, Frontend_FindWidgetByResourceId(D_800E54A4->players[playerIndex].menuWidget, UI_CASE_28_2DF));
        break;
    case 29:                                        /* switch 1 */

        stateTwentyNinePanel = Frontend_FindWidgetByResourceId(D_800E54A4->players[playerIndex].sprite, UI_CASE_29_2BF);
        D_800E54A4->players[playerIndex].menuWidget = stateTwentyNinePanel;
        Frontend_SetWidgetFlag08(stateTwentyNinePanel, 1);
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
