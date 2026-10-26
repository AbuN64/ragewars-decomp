#include "include_asm.h"
#include "COMMON/RECRECAT4.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/AIPROFILE.H"
#include "TYPES.H"
#include "FRONTEND/80423280_25.H"
#include "FRONTEND/80423280_3.H"
#include "SCENE/802508E0_13.H"

/* Releases the object D_800E4514 holds through Cache_FreeMemory, calls Tsmos_ActivateControllerState, clears
   D_800E4514 and returns zero. */



extern void Tsmos_ActivateControllerState();

/* Sets the word at offset 0xC of the object D_800E4514 points to and calls Tsmos_ActivateControllerState, once:
   nothing happens when the word is already set. Returns zero. */




/* Handles the menu message Smos_GetFocusedElementId reports after MarkMenuEventHandled: 0x1C3, 0x1BD, 0x1C2 and
   0x1C4 send codes -1, 13, 12 and 14 to Frontend_SetMenuChoiceResult; a handled message then runs Menu_CommitCompactOptionsPage
   and Smos_ReturnToPreviousScreen. Returns zero. */
extern void MarkMenuEventHandled(void);

extern s32 Smos_GetFocusedElementId(void);

extern void Frontend_SetMenuChoiceResult(s32);

extern void Smos_ReturnToPreviousScreen(void);

/* Calls MarkMenuEventHandled, Frontend_SetMenuChoiceResult with -1, Menu_CommitCompactOptionsPage and Smos_ReturnToPreviousScreen, and returns zero. */
extern void MarkMenuEventHandled();

extern void Smos_ReturnToPreviousScreen();

typedef s32 (*Handler80423930)(void *, s32, s32, s32, s32);

extern FieldRow D_800E4564[];

extern FieldRow D_800E4568[];

extern Handler80423930 D_800E456C;

/* Releases the object D_800E4518 holds through Cache_FreeMemory, calls Tsmos_ActivateControllerState, clears D_800E4518, calls
   func_80245B28_de and returns zero. */


extern void Cinema_ReleaseSequenceContext();

/* Handles the menu message Smos_GetFocusedElementId reports after MarkMenuEventHandled, for its MESSAGE_COUNT messages from
   FIRST_MESSAGE (0x377 to 0x380 on us) through jtbl_800E1668: one reopens screen D_800E4518 (marking it shown with timer -1 and
   refreshing its two windows at 0x44 and 0x4C) and calls func_80245B28_de; one tries ScenarioSetup_StartRandomCupStage
   and on failure sets the screen's modes 5 and 4 with timer 20, else reopens it with timer 0; the
   others pass codes 0x17, 13, 12 and 14 to Frontend_SetMenuChoiceResult. Any handled message then runs
   Menu_CommitTabOptionsPage. Returns zero. */
/* The first message this handles and how many it takes: eu-x numbers the messages 4 higher, de 4
   lower and takes only 8, as each cartridge's own bytes show; us, us-rev1 and eu share 0x377 and 10. */


extern void Tsmos_DeactivateControllerState(void);

/* The message screen D_800E4514; its word at 0xC marks the message handled. */
extern struct func_80205628_S3 *D_800E4514;
extern struct MessageScreen *D_800E4518;
extern void Frontend_StartMenuImageTransition(struct MessageScreen *);

extern void Frontend_SetWidgetFlag08(void *object, int enabled);

extern void Cinema_ReleaseSequenceContext(void);

extern s32 ScenarioSetup_StartRandomCupStage(void);

/* Dispatches event arg1 through this file's 12-byte handler table, whose rows hold an event at D_800E45AC, an actor kind at D_800E45B0 and a handler at D_800E45B4: the first row whose event equals arg1 and whose kind equals the actor's halfword kind at 0xC, or is the wildcard 0x7530, receives all five arguments and its result is returned; with no such row, or an empty table, the result is zero. Adapted from N64Eng_DispatchNumericWidgetEvent. */

typedef s32 (*Handler80423B88)(void *, s32, s32, s32, s32);

extern FieldRow D_800E45AC[];

extern FieldRow D_800E45B0[];

extern Handler80423B88 D_800E45B4;

s32 Frontend_DestroyCompactOptionsPage(void) {
    Cache_FreeMemory(D_800E4514);
    Tsmos_ActivateControllerState();
    D_800E4514 = 0;
    return 0;
}

s32 Frontend_ActivateCompactOptionsPage(void) {
    struct func_80205628_S3 *state = D_800E4514;

    if (state->unkC == 0) {
        state->unkC = 1;
        Tsmos_ActivateControllerState();
    }
    return 0;
}

s32 Frontend_HandleCompactOptionsShortcut(void) {
    s32 handled;
    MarkMenuEventHandled();
    handled = 1;
    switch (Smos_GetFocusedElementId()) {
#if defined(VERSION_DE)
    case 0x1BF:
#elif defined(VERSION_EU) || defined(VERSION_US) || defined(VERSION_US_REV1)
    case 0x1C3:
#elif defined(VERSION_EU_X)
    case 0x1C7:
#endif
        Frontend_SetMenuChoiceResult(-1);
        break;
#if defined(VERSION_DE)
    case 0x1B9:
#elif defined(VERSION_EU) || defined(VERSION_US) || defined(VERSION_US_REV1)
    case 0x1BD:
#elif defined(VERSION_EU_X)
    case 0x1C1:
#endif
        Frontend_SetMenuChoiceResult(13);
        break;
#if defined(VERSION_DE)
    case 0x1BE:
#elif defined(VERSION_EU) || defined(VERSION_US) || defined(VERSION_US_REV1)
    case 0x1C2:
#elif defined(VERSION_EU_X)
    case 0x1C6:
#endif
        Frontend_SetMenuChoiceResult(12);
        break;
#if defined(VERSION_DE)
    case 0x1C0:
#elif defined(VERSION_EU) || defined(VERSION_US) || defined(VERSION_US_REV1)
    case 0x1C4:
#elif defined(VERSION_EU_X)
    case 0x1C8:
#endif
        Frontend_SetMenuChoiceResult(14);
        break;
    default:
        handled = 0;
        break;
    }
    if (handled == 1) {
        Menu_CommitCompactOptionsPage();
        Smos_ReturnToPreviousScreen();
    }
    return 0;
}

s32 Frontend_CloseCompactOptionsPage(void) {
    MarkMenuEventHandled();
    Frontend_SetMenuChoiceResult(-1);
    Menu_CommitCompactOptionsPage();
    Smos_ReturnToPreviousScreen();
    return 0;
}

s32 Frontend_DispatchCompactOptionsEvent(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    Handler80423930 *entry;
    ObjRecAtCV1 *actor;
    s32 index;
    s32 wildcard;
    s32 actor_kind;
    s32 table_kind;

    if (D_800E456C != 0) {
        wildcard = 0x7530;
        entry = &D_800E456C;
        index = 0;
        do {
            if (D_800E4564[index].value == arg1) {
                actor = arg0;
                actor_kind = actor->unkC;
                table_kind = D_800E4568[index].value;
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

s32 Frontend_DestroyTabOptionsPage(void) {
    Cache_FreeMemory(D_800E4518);
    Tsmos_ActivateControllerState();
    D_800E4518 = 0;
    Cinema_ReleaseSequenceContext();
    return 0;
}

s32 Frontend_HandleTabOptionsShortcut(void) {
    s32 handled;
    u32 message;
    MarkMenuEventHandled();
    handled = 1;
    message = Smos_GetFocusedElementId() -
#if defined(VERSION_DE)
        0x373;
#elif defined(VERSION_EU_X)
        0x37B;
#else
        0x377;
#endif
    if (message >=
#if defined(VERSION_DE)
        8
#else
        10
#endif
    ) {
        goto other;
    }
    switch (message) {
#if defined(VERSION_DE)
        case 0: goto reopen;
        case 1: goto retry;
        case 2: goto code_14;
        case 3: goto code_17;
        case 4: goto other;
        case 5: goto other;
        case 6: goto code_13;
        case 7: goto code_12;
#else
        case 0: goto code_13;
        case 1: goto other;
        case 2: goto other;
        case 3: goto other;
        case 4: goto other;
        case 5: goto code_12;
        case 6: goto reopen;
        case 7: goto retry;
        case 8: goto code_14;
        case 9: goto code_17;
#endif
        }
reopen:
    Tsmos_DeactivateControllerState();
    Frontend_StartMenuImageTransition(D_800E4518);
    D_800E4518->shown = 1;
    D_800E4518->timer = -1;
    Frontend_SetWidgetFlag08(D_800E4518->window, 1);
    Frontend_SetWidgetFlag08(D_800E4518->second_window, 1);
    Cinema_ReleaseSequenceContext();
    goto done;
code_17:
    Frontend_SetMenuChoiceResult(0x17);
    goto done;
retry:
    Tsmos_DeactivateControllerState();
    if (ScenarioSetup_StartRandomCupStage() == 0) {
        D_800E4518->mode = 5;
        D_800E4518->next_mode = 4;
        D_800E4518->timer = 20;
    } else {
        Frontend_StartMenuImageTransition(D_800E4518);
        D_800E4518->shown = 1;
        D_800E4518->timer = 0;
    }
    goto done;
code_13:
    Frontend_SetMenuChoiceResult(13);
    goto done;
code_12:
    Frontend_SetMenuChoiceResult(12);
    goto done;
code_14:
    Frontend_SetMenuChoiceResult(14);
    goto done;
other:
    handled = 0;
done:
    if (handled == 1) {
        Menu_CommitTabOptionsPage();
    }
    return 0;
}

s32 Frontend_ConsumeTabOptionsEvent(void) {
    MarkMenuEventHandled();
    return 0;
}

s32 Frontend_DispatchTabOptionsEvent(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    Handler80423B88 *entry;
    s32 index;
    s32 wildcard;
    s32 actor_kind;
    s32 table_kind;
    ObjRecAtCV1 *actor;

    if (D_800E45B4 != 0) {
        wildcard = 0x7530;
        entry = &D_800E45B4;
        index = 0;
        do {
            if (D_800E45AC[index].value == arg1) {
                actor = arg0;
                actor_kind = actor->unkC;
                table_kind = D_800E45B0[index].value;
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

#if defined(VERSION_DE)
unsigned int rodata_unresolved_800DD658[2] = {
    0x00424034, 0x0042405C,
};
#endif
