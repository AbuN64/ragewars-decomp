#include "COMMON/RESERVED_SHARED_DECLARATIONS.H"
#include "TYPES.H"
#include "COMMON/SCREEN.H"
#include "COMMON/GAME_SESSION.H"
#include "FRONTEND/SCREEN.H"
#include "include_asm.h"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/AIPROFILE.H"
#include "FRONTEND/FRONTEND_DISPATCHRESIDENTACTOREVENT.H"

/* 8042E080_91.CPP */
/* Returns zero. Nothing in the cartridge image calls it or stores its address as a word, so it is
   either reached through a pointer built at run time or never used. */
s32 Frontend_IgnorePage67Event(void) {
    return 0;
}

/* 8042E080_92.CPP */
/* Calls MarkMenuEventHandled with the arguments it was given and returns zero. */

s32 Frontend_AcknowledgePage67Event(void) {
    MarkMenuEventHandled();
    return 0;
}

/* 8042E080_93.CPP */
/* Handles the menu message Menu_GetFocusedElementId reports after MarkMenuEventHandled: 0x3D8 clears g_simpleObjectPauseState, calls Tsmos_DeactivateControllerState, then calls Frontend_StartMenuImageTransition on g_residentChoiceScreen when ScenarioSetup_StartRandomCupStage reports non-zero or else func_8040C428_de with zero and SmXlate_SwitchScreen with 0x14; 0x3D9 calls SmXlate_SwitchScreen with one. Returns zero.
   Adapted from Frontend_ActivatePauseMenuAction with the message numbers and the arms changed. */
extern s32 g_residentChoiceScreen;
extern void Tsmos_DeactivateControllerState(void);
extern s32 ScenarioSetup_StartRandomCupStage(void);
extern void Frontend_StartMenuImageTransition(s32);
extern void SmXlate_SwitchScreen(s32);

#if defined(VERSION_DE)
enum { MENU_8043659C_984 = 978, MENU_8043659C_985 = 979 };
#elif defined(VERSION_EU_X)
enum { MENU_8043659C_984 = 988, MENU_8043659C_985 = 989 };
#else
enum { MENU_8043659C_984 = 984, MENU_8043659C_985 = 985 };
#endif

s32 Frontend_HandlePage67Choice(void) {
    MarkMenuEventHandled();
    switch (Menu_GetFocusedElementId()) {
    case MENU_8043659C_985:
        SmXlate_SwitchScreen(1);
        return 0;
    case MENU_8043659C_984:
        g_gameSession.clockPaused = 0;
        Tsmos_DeactivateControllerState();
        if (ScenarioSetup_StartRandomCupStage() == 0) {
            Frontend_RequestScreenMode(0);
            SmXlate_SwitchScreen(0x14);
        } else {
            Frontend_StartMenuImageTransition(g_residentChoiceScreen);
        }
        return 0;
    }
    return 0;
}

/* 8042E080_94.CPP */
#if !(defined(VERSION_US))
/* Dispatches event arg1 through this file's 12-byte handler table, whose rows hold an event at g_residentEventEntries, an actor kind at g_residentActorEventKinds and a handler at g_residentActorEventHandlers: the first row whose event equals arg1 and whose kind equals the actor's halfword kind at 0xC, or is the wildcard 0x7530, receives all five arguments and its result is returned; with no such row, or an empty table, the result is zero. Adapted from N64Eng_DispatchNumericWidgetEvent. */

typedef s32 (*Handler80436634)(void *, s32, s32, s32, s32);

extern FieldRow g_residentEventEntries[];
extern FieldRow g_residentActorEventKinds[];
extern Handler80436634 g_residentActorEventHandlers;

s32 Frontend_DispatchResidentActorEvent(void *menuActor, s32 eventKind, s32 eventDataOne, s32 eventDataTwo, s32 eventDataThree) {
    Handler80436634 *entry;
    s32 index;
    s32 wildcard;
    s32 actor_kind;
    s32 table_kind;
    MenuActorInputView *actor;

    if (g_residentActorEventHandlers != 0) {
        wildcard = 0x7530;
        entry = &g_residentActorEventHandlers;
        index = 0;
        do {
            if (g_residentEventEntries[index].value == eventKind) {
                actor = menuActor;
                actor_kind = actor->input;
                table_kind = g_residentActorEventKinds[index].value;
                if ((table_kind == actor_kind) || (table_kind == wildcard)) {
                    return (*entry)(menuActor, eventKind, eventDataOne, eventDataTwo, eventDataThree);
                }
            }
            entry += 3;
            index++;
        } while (*entry != 0);
    }
    return 0;
}
#endif

#if defined(VERSION_EU_X)
unsigned int func_804364E4_de_padding_12734C[1] = {
    0x27BDFFE8,
};
#endif

#if defined(VERSION_EU)
unsigned int func_804364E4_de_padding_1AD214[3] = {
    0x000210C0, 0x00521021, 0x00021880,
};
#endif
