#include "include_asm.h"
#include "COMMON/UNUSED.H"
#include "COMMON/SELECTIONSCREENSTATE.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "TYPES.H"
#include "COMMON/NUMBERPADSCREEN.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/ENTRYRECAT6C.H"
#include "FRONTEND/8042E080_42.H"
#include "MENU/80420E90_3.H"
#include "SCENE/802508E0_13.H"

/* 80420E90_14.CPP */
#if defined(VERSION_DE)
#define ID_SCREEN 0x398
#define ID_SCREEN_B 0x399
#define ID_ROW0 0x39F
#define ID_ROW1 0x39E
#define ID_ROW2 0x3A1
#define ID_ROW3 0x39D
#define ID_ROW4 0x39C
#define ID_ROW5 0x3A0
#define ID_WINDOW 0x39A
#define ID_LABEL 0x39B
#elif defined(VERSION_EU_X)
#define ID_SCREEN 0x3A2
#define ID_SCREEN_B 0x3A3
#define ID_ROW0 0x3AB
#define ID_ROW1 0x3A7
#define ID_ROW2 0x3AA
#define ID_ROW3 0x3A8
#define ID_ROW4 0x3A9
#define ID_ROW5 0x3A6
#define ID_WINDOW 0x3A4
#define ID_LABEL 0x3A5
#else
#define ID_SCREEN 0x39E
#define ID_SCREEN_B 0x39F
#define ID_ROW0 0x3A5
#define ID_ROW1 0x3A4
#define ID_ROW2 0x3A7
#define ID_ROW3 0x3A3
#define ID_ROW4 0x3A2
#define ID_ROW5 0x3A6
#define ID_WINDOW 0x3A0
#define ID_LABEL 0x3A1
#endif

extern void Tsmos_ActivateControllerState(void);
extern s32 SmpFlicker_CreateFlickerWidget(s32, s32);
extern s32 SmpFade_CreateFadeWidget(s32, s32);
extern void SmpSlider_EnableTransition(s32);
extern StateCode80420E90 *D_800E4450;

/* Builds the screen state D_800E4450: allocates it, opens screen 0x39E, registers six resources, opens window 0x3A0 and stores the 0x3A1 label. */
s32 Menu_CreateSixChoiceMenu(s32 root) {
    s32 screen;
    MenuWidget *window;

    D_800E4450 = (StateCode80420E90 *) Cache_AllocateMemory(0x14);
    Tsmos_ActivateControllerState();
    screen = SmpFade_CreateFadeWidget(ID_SCREEN, ID_SCREEN_B);
    D_800E4450->unk0 = (struct ObjMenuUpdateSixChoiceMenu *) screen;
    SmpSlider_EnableTransition(screen);
    SmpButton_WrapButtonWidget(ID_ROW0);
    SmpButton_WrapButtonWidget(ID_ROW1);
    SmpButton_WrapButtonWidget(ID_ROW2);
    SmpButton_WrapButtonWidget(ID_ROW3);
    SmpButton_WrapButtonWidget(ID_ROW4);
    SmpButton_WrapButtonWidget(ID_ROW5);
    window = Node_FindWidgetByResourceId(root, ID_WINDOW);
    D_800E4450->unk8 = (struct CellRecAt1A *) window;
    window->alpha = 0xF;
    D_800E4450->unk4 = SmpFlicker_CreateFlickerWidget(ID_LABEL, 0x6E);
    D_800E4450->unkC = 3;
    return 0;
}

/* 80420E90_3.CPP */
extern void SmpSlider_SetTransitionMode(void *, s32);

/* Releases the object D_800E4450 holds through Cache_FreeMemory, clears D_800E4450 and returns zero. */

/* Advances menu selection timing and dispatches the selected action. */

void SmXlate_SwitchScreen(s32);

                               /* extern */
void MarkMenuEventHandled();

                                  /* extern */

                                  /* extern */

                                  /* extern */
s32 SmpSlider_GetTransitionMode(void *);

                          /* extern */

                          

/* Handles the menu message Menu_GetFocusedElementId reports after MarkMenuEventHandled, for messages 0x3A2 to 0x3A7
   through jtbl_800E1610: five pick option 0, 1, 3, 4 or 2, pass it to PAKInterface_SetScreenPhase and set the
   result word at offset 0x10 of the screen D_800E4450 to 0x13; the sixth sets it to -1. Both then
   close the screen's first word through SmpSlider_SetTransitionMode with 2. Returns zero. */

extern s32 Menu_GetFocusedElementId(void);

/* Calls MarkMenuEventHandled, then sets the word at offset 0x10 of the object D_800E4450 points to to -1 and
   calls SmpSlider_SetTransitionMode on the object's first word with 2, returning zero. */

/* Dispatches event arg1 through this file's 12-byte handler table, whose rows hold an event at D_800E4454, an actor kind at D_800E4458 and a handler at D_800E445C: the first row whose event equals arg1 and whose kind equals the actor's halfword kind at 0xC, or is the wildcard 0x7530, receives all five arguments and its result is returned; with no such row, or an empty table, the result is zero. Adapted from N64Eng_DispatchNumericWidgetEvent. */

/* Advances a filling or draining bar by the step and writes its level byte at 0x10 of the bar at
   0xC: while rising it scales the amount for the display and, at or above the wrap point, stores
   the remainder with the high bit set, and it finishes at 1000 by storing 0xFF, marking 0x4 and
   calling Tsmos_ActivateControllerState; while falling it does the same from the other pair of constants and
   finishes at zero. Returns the finished flag. */

/* Resets a five-word record: clears the first three words, stores a value in the fourth and one
   in the fifth, then calls Tsmos_DeactivateControllerState. */

s32 Menu_DestroySixChoiceMenu(void) {
    Cache_FreeMemory(D_800E4450);
    D_800E4450 = 0;
    return 0;
}

                     

s32 Menu_UpdateSixChoiceMenu(void) {
    s32 temp_v0;
    s32 temp_v0_2;
    s32 var_a0;
    CellRecAt1A *temp_a0;
    CellRecAt1A *temp_v1;

    if (D_800E28E0 >= 2) {
        Tsmos_DeactivateControllerState();
        return 0;
    }
    Tsmos_ActivateControllerState();
    temp_v0 = SmpSlider_GetTransitionMode(D_800E4450->unk0);
    switch (temp_v0) {                              /* irregular */
    case 3:
        temp_v0_2 = D_800E4450->unkC - 1;
        D_800E4450->unkC = temp_v0_2;
        if (temp_v0_2 <= 0) {
            temp_v1 = D_800E4450->unk8;
            temp_v1->unk16 = (u16) (temp_v1->unk16 - 1);
            temp_a0 = D_800E4450->unk8;
            if (((s16) temp_a0->unk16 + temp_a0->unk1A) < 0) {
                temp_a0->unk16 = (u16) D_800E4450->unk0->unk44->unk1A;
            }
            D_800E4450->unkC = temp_v0;
        }
block_12:
        return 0;
    case 4:
        MarkMenuEventHandled();
        var_a0 = D_800E4450->unk10;
        if (var_a0 == -1) {
            var_a0 = 3;
        }
        SmXlate_SwitchScreen(var_a0);
        goto block_12;
    default:
        return 0;
    }
}

s32 Menu_ChooseSixChoiceOption(void) {
    s32 option;
    u32 message;
    MarkMenuEventHandled();
#if defined(VERSION_DE)
    message = Menu_GetFocusedElementId() - 0x39C;
#elif defined(VERSION_EU) || defined(VERSION_US) || defined(VERSION_US_REV1)
    message = Menu_GetFocusedElementId() - 0x3A2;
#elif defined(VERSION_EU_X)
    message = Menu_GetFocusedElementId() - 0x3A6;
#endif
    if (message >= 6) {
        return 0;
    }
    switch (message) {
#if defined(VERSION_EU_X)
        case 0: goto cancel;
        case 1: goto option_0;
        case 2: goto option_3;
        case 3: goto option_4;
        case 4: goto option_2;
        case 5: goto option_1;
#else
        case 0: goto option_4;
        case 1: goto option_3;
        case 2: goto option_0;
        case 3: goto option_1;
        case 4: goto cancel;
        case 5: goto option_2;
#endif
        }
option_0:
    option = 0;
    goto choose;
option_1:
    option = 1;
    goto choose;
option_3:
    option = 3;
    goto choose;
option_4:
    option = 4;
    goto choose;
option_2:
    option = 2;
choose:
    PAKInterface_SetScreenPhase(option);
    D_800E4450->unk10 = 0x13;
    goto close;
cancel:
    D_800E4450->unk10 = -1;
close:
    SmpSlider_SetTransitionMode(D_800E4450->unk0, 2);
done:
    return 0;
}

s32 Menu_CancelSixChoiceMenu(void) {
    StateCode80420E90 *state;

    MarkMenuEventHandled();
    state = D_800E4450;
    state->unk10 = -1;
    SmpSlider_SetTransitionMode(state->unk0, 2);
    return 0;
}

s32 Menu_DispatchSixChoiceEvent(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    char *entry;
    s32 offset;
    s32 wildcard;
    s32 actor_kind;
    s32 table_kind;

    if (D_800E445C != 0) {
        wildcard = 0x7530;
        entry = (char *)&D_800E445C;
        offset = 0;
        do {
            if (((struct Shape_typemap_3 *) (((char *) (&D_800E4454)) + offset))->field_0 == arg1) {
                actor_kind = ((struct ObjRecAtCV1 *) ((char *) arg0))->unkC;
                table_kind = ((struct Shape_typemap_3 *) (((char *) (&D_800E4458)) + offset))->field_0;
                if ((table_kind == actor_kind) || (table_kind == wildcard)) {
                    return (*(Handler802A2B50 *)entry)(arg0, arg1, arg2, arg3, arg4);
                }
            }
            entry += 0xC;
            offset += 0xC;
        } while (*(Handler802A2B50 *)entry != 0);
    }
    return 0;
}

/* Returns the word at offset 0x4 of a record. */
s32 Menu_GetFadeMeterDone(s32 *record) {
    return record[0x4 / 4];
}

/* Switches a timer record to a new mode: when the mode at offset 8 changes it stores the mode,
   loads the countdown at offset 0 with 1000 for a non-zero mode or zero otherwise, and clears the
   word at offset 4. */

void Menu_SetFadeMeterDirection(struct Triple *timer, s32 mode) {
    if (timer->z != mode) {
        timer->z = mode;
        if (mode == 0) {
            timer->x = 0;
        } else {
            timer->x = 1000;
        }
        timer->y = 0;
    }
}

s32 Menu_AdvanceFadeMeter(struct Meter *meter, s32 step) {
    struct ResourceSmpFlickerCreateFlickerWidget *bar;
    s32 level;
    f32 value;

    if (meter->done == 0) {
        if (meter->falling == 0) {
            if (meter->amount < 0x3E8) {
                value = (f32)meter->amount * D_800DD600;
                bar = meter->bar;
                if (!(value >= *(&D_800DD600 + 1))) {
                    level = (s32)value;
                } else {
                    level = (s32)(value - *(&D_800DD600 + 1)) | 0x80000000;
                }
                bar->value = level;
            } else {
                meter->bar->value = 0xFF;
                meter->done = 1;
                Tsmos_ActivateControllerState();
            }
            meter->amount = meter->amount + step;
        } else {
            if (meter->amount > 0) {
                value = (f32)meter->amount * D_800DD608;
                bar = meter->bar;
                if (!(value >= *(&D_800DD608 + 1))) {
                    level = (s32)value;
                } else {
                    level = (s32)(value - *(&D_800DD608 + 1)) | 0x80000000;
                }
                bar->value = level;
            } else {
                meter->bar->value = 0;
                meter->done = 1;
                Tsmos_ActivateControllerState();
            }
            meter->amount = meter->amount - step;
        }
    }
    return meter->done;
}

void Menu_InitializeFadeMeter(struct RecGobjinstSampleBoneTranslation *record, s32 value) {
    record->y = 0;
    record->x = 0;
    record->z = 0;
    record->pad0 = value;
    record->pad1 = 1;
    Tsmos_DeactivateControllerState();
}

#if defined(VERSION_US)
unsigned int rodata_unresolved_800DC2A8[2] = {
    0x000F000A, 0x00040000,
};
#endif

#if defined(VERSION_EU_X)
unsigned int rodata_unresolved_800E8E38[2] = {
    0x0044333C, 0x0044333C,
};
#endif

#if defined(VERSION_EU)
unsigned int rodata_unresolved_800EDC78[2] = {
    0x0800FFB6, 0x0800FFB7,
};
#endif

#if defined(VERSION_DE)
unsigned int rodata_unresolved_800DD5F8[2] = {
    0x3E828F5D, 0x4F000000,
};
#endif
