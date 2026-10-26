#include "COMMON/MENUSELECTIONMESSAGE.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "stddef.h"
#include "TYPES.H"
extern StateCode80420E90 *D_800E5784;
#include "RESMGR/802A0888.H"

/* Advances a menu selection on its countdown and dispatches the exit action. */
void SmXlate_SwitchScreen(s32);

 /* extern */
void MarkMenuEventHandled();

 /* extern */
void Smos_ReturnToPreviousScreen(void);

 /* extern */
s32 SmpSlider_GetTransitionMode(void *);

 /* extern */


/* Calls MarkMenuEventHandled, then sets the word at offset 0x10 of the object D_800E5784 points to to -1 and
   calls SmpSlider_SetTransitionMode on the object's first word with 2, returning zero. */




extern void MarkMenuEventHandled();

extern void SmpSlider_SetTransitionMode(void *, s32);

/* Calls MarkMenuEventHandled; when Smos_GetFocusedElementId reports 0x3D0 it sets the word at 0x10 of the menu block
   D_800E5784 points to to 7 and clears five bytes at D_80102B7E through XPlus_FillMemory, for 0x3D1 it
   sets that word to -1; then it calls SmpSlider_SetTransitionMode on the block's first word with 2. Returns
   zero. */


extern char D_80102B7E[];

extern s32 Smos_GetFocusedElementId();


#if defined(VERSION_DE)
enum { MENU_80437B10_976 = 970, MENU_80437B10_977 = 971 };
#elif defined(VERSION_EU_X)
enum { MENU_80437B10_976 = 980, MENU_80437B10_977 = 981 };
#else
enum { MENU_80437B10_976 = 976, MENU_80437B10_977 = 977 };
#endif

 /* const */
s32 Menu_UpdateTitleButtonScreen(void) {
    s32 temp_a0_2;
    s32 temp_v0;
    s32 temp_v0_2;
    CellRecAt1A *temp_a0;
    CellRecAt1A *temp_v1;
    temp_v0 = SmpSlider_GetTransitionMode(D_800E5784->unk0);
    switch (temp_v0) { /* irregular */
    case 3:
        temp_v0_2 = D_800E5784->unkC - 1;
        D_800E5784->unkC = temp_v0_2;
        if (temp_v0_2 <= 0) {
            temp_v1 = D_800E5784->unk8;
            temp_v1->unk16 = (u16) (temp_v1->unk16 - 1);
            temp_a0 = D_800E5784->unk8;
            if (((s16) temp_a0->unk16 + temp_a0->unk1A) < 0) {
                temp_a0->unk16 = (u16) D_800E5784->unk0->unk44->unk1A;
            }
            D_800E5784->unkC = temp_v0;
        }
block_10:
        return 0;
    case 4:
        MarkMenuEventHandled();
        temp_a0_2 = D_800E5784->unk10;
        if (temp_a0_2 == -1) {
            Smos_ReturnToPreviousScreen();
            return 0;
        }
        SmXlate_SwitchScreen(temp_a0_2);
        goto block_10;
    default:
        return 0;
    }
}

s32 Menu_CancelTitleButtonScreen(void) {
    StateCode80420E90 *state;

    MarkMenuEventHandled();
    state = D_800E5784;
    state->unk10 = -1;
    SmpSlider_SetTransitionMode(state->unk0, 2);
    return 0;
}

s32 Menu_HandleTitleButtonChoice(void) {
    s32 choice;

    MarkMenuEventHandled();
    choice = Smos_GetFocusedElementId();
    switch (choice) {
    case MENU_80437B10_977:
        D_800E5784->unk10 = -1;
        break;
    case MENU_80437B10_976:
        D_800E5784->unk10 = 7;
        XPlus_FillMemory(D_80102B7E, 0, 5);
        break;
    }
    SmpSlider_SetTransitionMode(D_800E5784->unk0, 2);
    return 0;
}
