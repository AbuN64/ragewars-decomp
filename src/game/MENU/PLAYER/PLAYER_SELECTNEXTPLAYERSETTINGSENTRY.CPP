#include "COMMON/MENULISTSCREEN.H"
#include "COMMON/LONE/D_80152789.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/UNUSED.H"
#include "COMMON/MENU_TEXT.H"
#include "TYPES.H"
extern struct MenuStepState *D_800E5690;
#include "MENU/804366D0_2.H"
#include "MENU/804366D0_4.H"
#include "RENDER/SOUNDELEMENT_PLAYFLATSOUND.H"

/* Calls MarkMenuEventHandled, then sets the word at offset 0x20 of the object D_800E5690 points to to -1 and
   calls SmpSlider_SetTransitionMode on the object's first word with 2, returning zero. */




extern void MarkMenuEventHandled();

extern void SmpSlider_SetTransitionMode(void *, s32);


                                 /* extern */
void MarkMenuEventHandled();

                                  /* extern */
s32 XStdio_FormatBuffer(void *, s32, ...);

                  /* extern */

                               /* extern */

                               /* extern */
#if defined(VERSION_EU) || defined(VERSION_EU_X)
extern s32 D_800E1D54[];
#else
#endif

/* Native resident constant storage; absolute access symbols retain their addresses. */
#if defined(VERSION_US)

#elif defined(VERSION_US_REV1)

#elif defined(VERSION_DE)

#endif

/* Dispatches event arg1 through this file's 12-byte handler table, whose rows hold an event at D_800E5698, an actor kind at D_800E569C and a handler at D_800E56A0: the first row whose event equals arg1 and whose kind equals the actor's halfword kind at 0xC, or is the wildcard 0x7530, receives all five arguments and its result is returned; with no such row, or an empty table, the result is zero. Adapted from N64Eng_DispatchNumericWidgetEvent. */

typedef s32 (*Handler80436FE4)(void *, s32, s32, s32, s32);



extern Handler80436FE4 D_800E56A0;

s32 Player_CancelPlayerSettingsEntry(void) {
    struct MenuStepState *state;

    MarkMenuEventHandled();
    state = D_800E5690;
    state->value = -1;
    SmpSlider_SetTransitionMode(state->menu, 2);
    return 0;
}

s32 Player_SelectNextPlayerSettingsEntry(s32 unused0, s32 unused1, s32 unused2, s32 buttonState) {
    s32 nextItem;

    MarkMenuEventHandled();
    if (buttonState == 1) {
        Player_StorePlayerSettingsEntry(D_800E5690->item);
        nextItem = D_800E5690->item + 1;
        D_800E5690->item = nextItem;
        if (nextItem >= 4) {
            D_800E5690->item = 0;
        }
        Player_SelectPlayerSettingsEntry(D_800E5690->item);
        XStdio_FormatBuffer(D_800E5690->text, RW_LOCALIZED_TEXT(D_800D34C0_de, D_800E1D54, D_800E1D54, g_languageIndex), D_800E5690->item + 1);
        D_800E5690->label->text = (void *) (D_800E5690->text);
        SoundElement_PlayFlatSound(0xE81);
        return 0;
    }
    return 0;
}

s32 Player_SelectPreviousPlayerSettingsEntry(s32 unused0, s32 unused1, s32 unused2, s32 buttonState) {
    s32 previousItem;

    MarkMenuEventHandled();
    if (buttonState == 1) {
        Player_StorePlayerSettingsEntry(D_800E5690->item);
        previousItem = D_800E5690->item - 1;
        D_800E5690->item = previousItem;
        if (previousItem < 0) {
            D_800E5690->item = 3;
        }
        Player_SelectPlayerSettingsEntry(D_800E5690->item);
        XStdio_FormatBuffer(D_800E5690->text, RW_LOCALIZED_TEXT(D_800D34C0_de, D_800E1D54, D_800E1D54, g_languageIndex), D_800E5690->item + 1);
        D_800E5690->label->text = (void *) (D_800E5690->text);
        SoundElement_PlayFlatSound(0xE81);
        return 0;
    }
    return 0;
}

s32 Player_DispatchPlayerSettingsEvent(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    Handler80436FE4 *entry;
    s32 index;
    s32 wildcard;
    s32 actor_kind;
    s32 table_kind;
    ObjRecAtCV1 *actor;

    if (D_800E56A0 != 0) {
        wildcard = 0x7530;
        entry = &D_800E56A0;
        index = 0;
        do {
            if (D_800E5698[index].value == arg1) {
                actor = arg0;
                actor_kind = actor->unkC;
                table_kind = D_800E569C[index].value;
                if ((table_kind == actor_kind) || (table_kind == wildcard)) {
                    return (*entry)(arg0, arg1, arg2, arg3, arg4);
                }
            }
            entry += 3;
            index++;
        } while (*entry != 0);
    }
    return 0;
}
