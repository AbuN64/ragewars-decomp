
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





int func_80264614_de(int);
u8 * Resmgr_CopyString(u8 *, u8 *);
char * func_80411D78_de(s32);
void Menu_SetSlotValue(void *, s32, s32);
s32 Menu_GetSlotValue(void *, s32);
void Menu_ShowSlotNode(void *, s32, void *);
void func_8042E9B4_de(char *, char *, char *);
void func_80433914_de(s32);
void func_80433BCC_de(s32);
void func_80433EA0_de(s32);
void func_80434C2C_de(s32);
s32 func_80435528_de(void);
void func_8043577C_de(s32);
void func_8043C278_de(s32 *);
void func_80433D38_de(s32);                    /* extern */


/* The slot-error scalar is real external storage in every ROM version. */
























void Frontend_RefreshPlayerPanel(s32 arg0) {



    s32 text_node; 

    s32 temp_s2; 

    s32 slot_active;

 
 
    s32 var_a0;
    s32 var_a0_5;
    s32 var_s0;

    
    s32 var_s1; 
    s32 var_v0;

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

    temp_a0 = D_800E54A4->players[arg0].menuWidget;
    if (temp_a0 != 0) {
        Frontend_SetWidgetFlag08((func_8041F2A0_Item *) temp_a0, 0);
    }
    Frontend_SetWidgetFlag40(Menu_GetSlotValue(D_800E54A4->root, arg0), 0);
    /* the published B6E8 takes the controller handle as a plain scalar */
    func_8041B6E8_de((s32) D_800E54A4->field0, arg0, SETUP_LABEL_ID);
    temp_v1 = D_800E54A4->players[arg0].state;
    switch (temp_v1) {                              /* switch 1 */
    case 0:                                         /* switch 1 */

        temp_v0 = func_8040EC30_de(D_800E54A4->players[arg0].sprite, PANEL_ROOT_ID);
        D_800E54A4->players[arg0].menuWidget = temp_v0;
        Frontend_SetWidgetFlag08(temp_v0, 1);
        text_node = (s32)func_8040EC30_de(D_800E54A4->players[arg0].menuWidget, PANEL_TEXT_ID);
        ((SetupTextNode *)text_node)->unk38 = D_800E54A4->players[arg0].nameText;
        temp_v1_2 = D_800E54A4->phase;
        
        switch (temp_v1_2) {                        /* switch 2 */
        case 1:                                     /* switch 2 */
        case 7:                                     /* switch 2 */
            temp_s1 = func_80411D78_de(MODE_17_ID);
            temp_copy_source = func_80411D78_de(((SetupTextNode *)text_node)->unk34);
            break;
        case 2:                                     /* switch 2 */
            temp_s1 = func_80411D78_de(MODE_2_ID);
            temp_copy_source = func_80411D78_de(((SetupTextNode *)text_node)->unk34);
            break;
        case 3:                                     /* switch 2 */
            temp_s1 = func_80411D78_de(MODE_3_ID);
            temp_copy_source = func_80411D78_de(((SetupTextNode *)text_node)->unk34);
            break;
        case 4:                                     /* switch 2 */
        case 6:                                     /* switch 2 */
            temp_s1 = func_80411D78_de(MODE_46_ID);
            temp_copy_source = func_80411D78_de(((SetupTextNode *)text_node)->unk34);
            break;
        case 5:                                     /* switch 2 */
            temp_s1 = func_80411D78_de(MODE_5_ID);
            temp_copy_source = func_80411D78_de(((SetupTextNode *)text_node)->unk34);
            break;
        case 0:                                     /* switch 2 */
        default:                                    /* switch 2 */
            temp_s1 = func_80411D78_de(MODE_DEFAULT_ID);
            temp_copy_source = func_80411D78_de(((SetupTextNode *)text_node)->unk34);
            break;
        }


        Resmgr_CopyString((&D_800E54A4->players[arg0])->nameText, temp_copy_source);
        func_8042E9B4_de((&D_800E54A4->players[arg0])->nameText, D_800DDDC8, temp_s1);
        var_v0 = arg0 * 8;
        if (D_800E54A4->phase == 6) {
            Frontend_SetWidgetFlag08(func_8040EC30_de(D_800E54A4->players[arg0].menuWidget, MODE_HIDE_ID), 0);
            var_v0 = arg0 * 8;
        }
        break;
    case 1:                                         /* switch 1 */

        temp_v0_3 = func_8040EC30_de(D_800E54A4->players[arg0].sprite, UI_CASE_1_2EC);
        D_800E54A4->players[arg0].menuWidget = temp_v0_3;
        Frontend_SetWidgetFlag08(temp_v0_3, 1);
        Menu_ShowSlotNode(D_800E54A4->root, arg0, func_8040EC30_de(D_800E54A4->players[arg0].menuWidget, UI_CASE_1_2EE));
        var_v0 = arg0 * 8;
        break;
    case 2:                                         /* switch 1 */

        var_a0_3 = D_800E54A4->players[arg0].sprite;
        var_a1_2 = UI_CASE_2_2D4;
block_36:
        temp_v0_4 = func_8040EC30_de(var_a0_3, var_a1_2);
        D_800E54A4->players[arg0].menuWidget = temp_v0_4;
        Frontend_SetWidgetFlag08(temp_v0_4, 1);
        var_v0 = arg0 * 8;
        break;
    case 3:                                         /* switch 1 */

        temp_v0_5 = func_8040EC30_de(D_800E54A4->players[arg0].sprite, UI_CASE_3_2BB);
        D_800E54A4->players[arg0].menuWidget = temp_v0_5;
        Frontend_SetWidgetFlag08(temp_v0_5, 1);
        Menu_ShowSlotNode(D_800E54A4->root, arg0, func_8040EC30_de(D_800E54A4->players[arg0].menuWidget, UI_CASE_3_2BC));
        break;
    case 4:                                         /* switch 1 */

        temp_v0_6 = func_8040EC30_de(D_800E54A4->players[arg0].sprite, UI_CASE_4_2D5);
        D_800E54A4->players[arg0].menuWidget = temp_v0_6;
        Frontend_SetWidgetFlag08(temp_v0_6, 1);
        Menu_ShowSlotNode(D_800E54A4->root, arg0, func_8040EC30_de(D_800E54A4->players[arg0].menuWidget, UI_CASE_4_2DA));
        func_80433EA0_de(arg0);
        var_v0 = arg0 * 8;
        break;
    case 22:                                        /* switch 1 */
        /* the panel slot is untyped storage; the hub types the E8D8 argument as the item */
        Frontend_SetWidgetFlag08((func_8041F2A0_Item *) D_800E54A4->players[arg0].menuWidget, 1);
        var_v1 = D_800E54A4;
        var_s1 = 0;
        if (var_v1->links[0].state == 0) {
            do {
                var_v1 = (void *)((char *)var_v1 + sizeof(PakMenuLink));
                var_s1 += 1;
            } while (var_v1->links[0].state == 0);
        }
        var_s0 = SLOT_DEFAULT_ID;
        if (var_s1 == 1) {
            goto case22_one;
        }
        if (var_s1 >= 2) {
            goto case22_check_two;
        }
        if (var_s1 == 0) {
            goto case22_selected;
        }
        goto case22_default;
case22_check_two:
        if (var_s1 == 2) {
            goto case22_two;
        }
case22_check_three:
        if (var_s1 == 3) {
            goto case22_three;
        }
case22_default:
        var_s0 = SLOT_DEFAULT_ID;
        goto case22_selected;
case22_one:
        var_s0 = SLOT_1_ID;
        goto case22_selected;
case22_two:
        var_s0 = SLOT_2_ID;
        goto case22_selected;
case22_three:
        var_s0 = SLOT_3_ID;
case22_selected:
        func_8041B6E8_de((s32) D_800E54A4->field0, arg0, var_s0);
        func_80433BCC_de(arg0);
        var_v0 = arg0 * 8;
        break;
    case 6:                                         /* switch 1 */

        temp_v0_7 = func_8040EC30_de(D_800E54A4->players[arg0].sprite, UI_CASE_6_2E4);
        D_800E54A4->players[arg0].menuWidget = temp_v0_7;
        Frontend_SetWidgetFlag08(temp_v0_7, 1);
        Menu_ShowSlotNode(D_800E54A4->root, arg0, func_8040EC30_de(D_800E54A4->players[arg0].menuWidget, UI_CASE_6_2E8));
        func_80434C2C_de(arg0);
        var_v0 = arg0 * 8;
        break;
    case 7:                                         /* switch 1 */

        temp_v0_8 = func_8040EC30_de(D_800E54A4->players[arg0].sprite, UI_CASE_7_2CA);
        D_800E54A4->players[arg0].menuWidget = temp_v0_8;
        Frontend_SetWidgetFlag08(temp_v0_8, 1);
        Menu_ShowSlotNode(D_800E54A4->root, arg0, func_8040EC30_de(D_800E54A4->players[arg0].menuWidget, UI_CASE_7_2CC));

        var_a0_4 = D_800E54A4->players[arg0].menuWidget;
        var_s1 = D_800E54A4->players[arg0].chosen;
        var_a1_3 = UI_CASE_7_2CB;

        (((MenuWidget *)(func_8040EC30_de(var_a0_4, var_a1_3)))->text) = (&D_800E54A4->players[arg0])->slots[var_s1];
        goto block_84;
    case 8:                                         /* switch 1 */

        temp_v0_10 = func_8040EC30_de(D_800E54A4->players[arg0].sprite, UI_CASE_8_2CE);
        D_800E54A4->players[arg0].menuWidget = temp_v0_10;
        Frontend_SetWidgetFlag08(temp_v0_10, 1);
        Menu_ShowSlotNode(D_800E54A4->root, arg0, func_8040EC30_de(D_800E54A4->players[arg0].menuWidget, UI_CASE_8_2CF));

        var_s1 = D_800E54A4->players[arg0].slot;
        temp_v0_10 = func_8040EC30_de(D_800E54A4->players[arg0].menuWidget, UI_CASE_8_2CB);

        ((MenuWidget *)temp_v0_10)->text = D_800E54A4->players[arg0].names[var_s1].code;
        goto block_84;
    case 9:                                         /* switch 1 */

        temp_v0_12 = func_8040EC30_de(D_800E54A4->players[arg0].sprite, UI_CASE_9_2C6);
        D_800E54A4->players[arg0].menuWidget = temp_v0_12;
        Frontend_SetWidgetFlag08(temp_v0_12, 1);
        Menu_ShowSlotNode(D_800E54A4->root, arg0, func_8040EC30_de(D_800E54A4->players[arg0].menuWidget, UI_CASE_9_2C8));
        ((MenuWidget *)func_8040EC30_de(D_800E54A4->players[arg0].menuWidget, UI_CASE_9_2C7))->text = D_800E54A4->players[D_800E54A4->links[0].player].slots[D_800E54A4->links[0].entry];
        goto block_84;
    case 10:                                        /* switch 1 */

        temp_v0_4 = func_8040EC30_de(D_800E54A4->players[arg0].sprite, UI_CASE_10_2A4);
        D_800E54A4->players[arg0].menuWidget = temp_v0_4;
        Frontend_SetWidgetFlag08(temp_v0_4, 1);
        var_v0 = arg0 * 8;
        break;
    case 11:                                        /* switch 1 */

        temp_v0_13 = func_8040EC30_de(D_800E54A4->players[arg0].sprite, UI_CASE_11_2D1);
        D_800E54A4->players[arg0].menuWidget = temp_v0_13;
        Frontend_SetWidgetFlag08(temp_v0_13, 1);
        Menu_ShowSlotNode(D_800E54A4->root, arg0, func_8040EC30_de(D_800E54A4->players[arg0].menuWidget, UI_CASE_11_2D2));
        break;
    case 12:                                        /* switch 1 */

        temp_v0_14 = func_8040EC30_de(D_800E54A4->players[arg0].sprite, UI_CASE_12_2F2);
        D_800E54A4->players[arg0].menuWidget = temp_v0_14;
        Frontend_SetWidgetFlag08(temp_v0_14, 1);
        temp_s2 = 0;
        var_s1 = (s32)func_8040EC30_de(D_800E54A4->players[arg0].menuWidget, UI_CASE_12_2F3);
        Menu_ShowSlotNode(D_800E54A4->root, arg0, (void *)var_s1);
 

        D_800E54A4->players[arg0].nameCursor = 0;

        do {
            if (temp_s2 == 0) {
                D_800E54A4->players[arg0].name[temp_s2].available = 0x41;
            } else {
                D_800E54A4->players[arg0].name[temp_s2].available = 0;
            }
            D_800E54A4->players[arg0].name[temp_s2].slot = 0;
            temp_s2++;
        } while (temp_s2 < 7);

        D_800E54A4->players[arg0].nameTimer = 0;
        D_800E54A4->players[arg0].namePhase = 2;
        var_a0_5 = 0;
        do {
            ((SetupLinkedLabel *)var_s1)->unk10 = 0xFF;
            text_node = (s32)((SetupLinkedLabel *)var_s1)->unk8; 
            ((MenuWidget *)text_node)->text = &D_800E54A4->players[arg0].name[var_a0_5].available;
            var_s1 = (s32)((SetupLinkedLabel *)var_s1)->unk38;
            var_a0_5 += 1;
        } while (var_s1 != 0);
        var_v0 = arg0 * 8;
        break;
    case 13:                                        /* switch 1 */

        temp_v0_16 = func_8040EC30_de(D_800E54A4->players[arg0].sprite, UI_CASE_13_2AF);
        D_800E54A4->players[arg0].menuWidget = temp_v0_16;
        Frontend_SetWidgetFlag08(temp_v0_16, 1);
        Menu_ShowSlotNode(D_800E54A4->root, arg0, func_8040EC30_de(D_800E54A4->players[arg0].menuWidget, UI_CASE_13_2B6));
        func_80433914_de(arg0);
        var_v0 = arg0 * 8;
        break;
    case 14:                                        /* switch 1 */
    case 17:                                        /* switch 1 */
        func_8041B6E8_de((s32) D_800E54A4->field0, arg0, SETUP_LABEL_ID);
        Menu_SetSlotValue(D_800E54A4->root, arg0, 1);

        temp_v0_17 = func_8040EC30_de(D_800E54A4->players[arg0].sprite, UI_CASE_17_2A5);
        D_800E54A4->players[arg0].menuWidget = temp_v0_17;
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
            func_802A2394_de();
            func_8043C278_de(D_800E54A4->menu);
            goto mode_end;
mode_six:
            {
                func_8043577C_de(0x1D);
                if (D_800DF4C4 == 1) {
                    D_800DF4C0 -= 1;
                }
                if (D_800DF4C4 == 0) {
                    D_800DF4C0 = -1;
                }
                goto mode_end;
            }
mode_default:
            func_8043577C_de(0x1B);
mode_end:;
        }
        var_v0 = arg0 * 8;
        break;
    case 15:                                        /* switch 1 */

        temp_v0_18 = func_8040EC30_de(D_800E54A4->players[arg0].sprite, UI_CASE_15_2EF);
        D_800E54A4->players[arg0].menuWidget = temp_v0_18;
        Frontend_SetWidgetFlag08(temp_v0_18, 1);
        Menu_ShowSlotNode(D_800E54A4->root, arg0, func_8040EC30_de(D_800E54A4->players[arg0].menuWidget, UI_CASE_15_2F1));
        break;
    case 16:                                        /* switch 1 */

        temp_v0_19 = func_8040EC30_de(D_800E54A4->players[arg0].sprite, UI_CASE_16_2B7);
        D_800E54A4->players[arg0].menuWidget = temp_v0_19;
        Frontend_SetWidgetFlag08(temp_v0_19, 1);
        Menu_ShowSlotNode(D_800E54A4->root, arg0, func_8040EC30_de(D_800E54A4->players[arg0].menuWidget, UI_CASE_16_2B9));
        var_a1_3 = UI_CASE_16_2BA;

        var_a0_4 = D_800E54A4->players[arg0].menuWidget;
        var_s1 = D_800E54A4->players[arg0].record;
block_61:

        (((MenuWidget *)(func_8040EC30_de(var_a0_4, var_a1_3)))->text) = (&D_800E54A4->players[arg0])->slots[var_s1];
        goto block_84;
    case 21:                                        /* switch 1 */

        temp_v0_21 = func_8040EC30_de(D_800E54A4->players[arg0].sprite, UI_CASE_21_2E1);
        D_800E54A4->players[arg0].menuWidget = temp_v0_21;
        Frontend_SetWidgetFlag08(temp_v0_21, 1);
        Menu_ShowSlotNode(D_800E54A4->root, arg0, func_8040EC30_de(D_800E54A4->players[arg0].menuWidget, UI_CASE_21_2E2));
        break;
    case 23:                                        /* switch 1 */

        temp_v0_22 = func_8040EC30_de(D_800E54A4->players[arg0].sprite, UI_CASE_23_2AC);
        D_800E54A4->players[arg0].menuWidget = temp_v0_22;
        Frontend_SetWidgetFlag08(temp_v0_22, 1);
        Menu_ShowSlotNode(D_800E54A4->root, arg0, func_8040EC30_de(D_800E54A4->players[arg0].menuWidget, UI_CASE_23_2AE));
        break;
    case 24:                                        /* switch 1 */

        temp_v0_23 = func_8040EC30_de(D_800E54A4->players[arg0].sprite, UI_CASE_24_2A9);
        D_800E54A4->players[arg0].menuWidget = temp_v0_23;
        Frontend_SetWidgetFlag08(temp_v0_23, 1);
        Menu_ShowSlotNode(D_800E54A4->root, arg0, func_8040EC30_de(D_800E54A4->players[arg0].menuWidget, UI_CASE_24_2AA));
        break;
    case 25:                                        /* switch 1 */

        temp_v0_24 = func_8040EC30_de(D_800E54A4->players[arg0].sprite, UI_CASE_25_2EA);
        D_800E54A4->players[arg0].menuWidget = temp_v0_24;
        Frontend_SetWidgetFlag08(temp_v0_24, 1);
        Menu_ShowSlotNode(D_800E54A4->root, arg0, func_8040EC30_de(D_800E54A4->players[arg0].menuWidget, UI_CASE_25_2EB));
        break;
    case 26:                                        /* switch 1 */

        temp_v0_25 = func_8040EC30_de(D_800E54A4->players[arg0].sprite, UI_CASE_26_2A6);
        D_800E54A4->players[arg0].menuWidget = temp_v0_25;
        Frontend_SetWidgetFlag08(temp_v0_25, 1);
        Menu_ShowSlotNode(D_800E54A4->root, arg0, func_8040EC30_de(D_800E54A4->players[arg0].menuWidget, UI_CASE_26_2A7));
        break;
case27_found:
        func_8041B6E8_de((s32) D_800E54A4->field0, arg0, var_s0);
        goto case27_done;
    case 27:                                        /* switch 1 */
        Frontend_SetWidgetFlag08((func_8041F2A0_Item *) D_800E54A4->players[arg0].menuWidget, 1);
        temp_s2 = 0;

        func_8041B6E8_de((s32) D_800E54A4->field0, arg0, CHECK_0_ID);
        do {
loop_69:
        if (temp_s2 == 1) {
            goto case27_one;
        }
        if (temp_s2 >= 2) {
            goto case27_check_two;
        }
        if (temp_s2 == 0) {
            goto case27_zero;
        }
        var_s0 = CHECK_DEFAULT_ID;
        goto case27_selected;
case27_check_two:
        if (temp_s2 == 2) {
            goto case27_two;
        }
        var_s0 = CHECK_DEFAULT_ID;
        goto case27_selected;
case27_zero:
        var_s0 = CHECK_0_ID;
        goto case27_selected;
case27_one:
        var_s0 = CHECK_1_ID;
        goto case27_selected;
case27_two:
        var_s0 = CHECK_2_ID;
case27_selected:
        slot_active = func_80264614_de(temp_s2);
        temp_s2 += 1;
        if (slot_active == 1) {
            goto case27_found;
        }
        } while (temp_s2 < 4);
case27_done:
        func_80433D38_de(arg0);
        var_v0 = arg0 * 8;
        break;
    case 28:                                        /* switch 1 */

        temp_v0_26 = func_8040EC30_de(D_800E54A4->players[arg0].sprite, UI_CASE_28_2DE);
        D_800E54A4->players[arg0].menuWidget = temp_v0_26;
        Frontend_SetWidgetFlag08(temp_v0_26, 1);
        Menu_ShowSlotNode(D_800E54A4->root, arg0, func_8040EC30_de(D_800E54A4->players[arg0].menuWidget, UI_CASE_28_2DF));
        break;
    case 29:                                        /* switch 1 */

        temp_v0_27 = func_8040EC30_de(D_800E54A4->players[arg0].sprite, UI_CASE_29_2BF);
        D_800E54A4->players[arg0].menuWidget = temp_v0_27;
        Frontend_SetWidgetFlag08(temp_v0_27, 1);
        Menu_ShowSlotNode(D_800E54A4->root, arg0, func_8040EC30_de(D_800E54A4->players[arg0].menuWidget, UI_CASE_29_2C0));
        var_v0 = arg0 * 8;
        break;
    default:                                        /* switch 1 */
block_84:
        var_v0 = arg0 * 8;
        break;
    }
    ((SetupLinkedLabel *)D_800E54A4->players[arg0].menuWidget)->unk10 = 0x96;
}
