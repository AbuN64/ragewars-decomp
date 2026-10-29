#include "COMMON/ACCESS_S8_10F.H"
#include "include_asm.h"
#include "COMMON/RUNTIME_DECLARATIONS.H"
#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/MENU_INITIALIZEOPTIONSSCENE.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/AIPROFILE.H"
#include "TYPES.H"
#include "MENU/MENU_DISPATCHOPTIONSTRANSITIONEVENT.H"
#include "SCENE/CACHE_FREEMEMORY.H"
#include "FRONTEND/MENUIMAGE.H"
#include "COMMON/NUMBERPADSCREEN.H"
#include "MENU/OPTIONTRANSITION.H"
extern s32 Frontend_GetMenuImageState(s32 *record);
extern void *Cache_AllocateMemory(s32 size);
extern void Frontend_InitMenuImage(s32 *, s32, s32, s32, s32);

s32 Menu_CreateOptionsImageTransition(void) {
    s32 *record = Cache_AllocateMemory(0x24);
    g_optionsImageTransition = record;
    record[7] = 0;
    record[8] = 0;
    Frontend_InitMenuImage(record, 0x67, 0, 0, 0);
    return 0;
}

/* Releases the object D_800E44A0 holds through Cache_FreeMemory, clears D_800E44A0 and returns zero. */



/* Event callback for screen D_800E44A0: on event 1 while Frontend_GetMenuImageState reports the screen in state
   1 it advances the screen through Frontend_DrawMenuImage and Frontend_AdvanceMenuImageTransition, and when that leaves it in
   state 2 it tears the match display down through Menu_ReleaseOptionsScene and Stage_StartConfiguredMatch and calls
   func_80264854_de(1). Returns zero. */


extern void Frontend_DrawMenuImage(void *);


#if defined(VERSION_EU) || defined(VERSION_EU_X) || defined(VERSION_US) || defined(VERSION_US_REV1)
#else
extern void func_8042201C_de(void);
#endif


extern void Stage_StartConfiguredMatch(void);

/* Unless Frontend_GetMenuImageState reports one for the object D_800E44A0 holds, calls Tsmos_ActivateControllerState and, when
   the object's word at 0x20 is one, calls Tsmos_DeactivateControllerState, then func_80245B28_de and ScenarioSetup_ResetSelectionIndicators unless
   the option byte D_801462D5 is set, and finally resets the object through Frontend_StartMenuImageTransition. Returns
   zero. */





extern void Tsmos_ActivateControllerState(void);

extern void Tsmos_DeactivateControllerState(void);


extern void ScenarioSetup_ResetSelectionIndicators(void);

extern void Frontend_StartMenuImageTransition(s32 *record);

/* On event 3 with value 0xB, calls MarkMenuEventHandled and sets the word at offset 0x20 of the object
   D_800E44A0 points to. Returns zero. */




extern void MarkMenuEventHandled();

/* Sets the word at offset 0x20 of the object D_800E44A0 points to and returns zero. */




/* Dispatches event arg1 through this file's 12-byte handler table, whose rows hold an event at g_optionsTransitionEventCodes, an actor kind at g_optionsTransitionActorKinds and a handler at g_optionsTransitionEventCallbacks: the first row whose event equals arg1 and whose kind equals the actor's halfword kind at 0xC, or is the wildcard 0x7530, receives all five arguments and its result is returned; with no such row, or an empty table, the result is zero. Adapted from N64Eng_DispatchNumericWidgetEvent. */






s32 Menu_DestroyOptionsImageTransition(void) {
    Cache_FreeMemory(g_optionsImageTransition);
    g_optionsImageTransition = 0;
    return 0;
}

s32 Menu_DrawOptionsImageTransition(s32 unused0, s32 unused1, s32 event) {
    if (event == 1) {
        if (Frontend_GetMenuImageState(g_optionsImageTransition) != 1) {
            return 0;
        }
        Frontend_DrawMenuImage(g_optionsImageTransition);
        Frontend_AdvanceMenuImageTransition(g_optionsImageTransition);
        if (Frontend_GetMenuImageState(g_optionsImageTransition) != 2) {
            return 0;
        }
#if defined(VERSION_DE)
        Menu_ReleaseOptionsScene();
#else

#if defined(VERSION_EU) || defined(VERSION_EU_X) || defined(VERSION_US) || defined(VERSION_US_REV1)
Menu_ReleaseOptionsScene
#else
func_8042201C_de
#endif
();
#endif
        Stage_StartConfiguredMatch();
        Control_SetControllerMode(1);
    }
    return 0;
}

s32 Menu_StartOptionsImageTransition(void) {
    s32 one = 1;

    if (Frontend_GetMenuImageState(g_optionsImageTransition) == one) {
        return 0;
    }
    Tsmos_ActivateControllerState();
    if (g_optionsImageTransition[8] != one) {
        return 0;
    }
    Tsmos_DeactivateControllerState();
    if (g_gameSettings.controllerMode == 0) {
        Cinema_ReleaseSequenceContext();
        ScenarioSetup_ResetSelectionIndicators();
    }
    Frontend_StartMenuImageTransition(g_optionsImageTransition);
    return 0;
}

s32 Menu_HandleOptionsTransitionRequest(void *first, void *second, u32 event, s32 value) {
    if ((event >> 16) == 3 && value == 0xB) {
        MarkMenuEventHandled();
        g_optionsImageTransition[8] = 1;
    }
    return 0;
}

s32 Menu_RequestOptionsImageTransition(void) {
    g_optionsImageTransition[8] = 1;
    return 0;
}

s32 Menu_ConsumeOptionsTransitionEvent(void) {
    MarkMenuEventHandled();
    return 0;
}

s32 Menu_DispatchOptionsTransitionEvent(void *object, s32 event, s32 eventData, s32 eventValue, s32 eventContext) {
    char *entry;
    s32 offset;
    s32 wildcard;
    s32 actor_kind;
    s32 table_kind;

    if (g_optionsTransitionEventCallbacks != 0) {
        wildcard = 0x7530;
        entry = (char *)&g_optionsTransitionEventCallbacks;
        offset = 0;
        do {
            if (((struct AnimationEventMaskView *) (((char *) (&g_optionsTransitionEventCodes)) + offset))->value == event) {
                actor_kind = ((struct MenuActorInputView *) ((char *) object))->input;
                table_kind = ((struct AnimationEventMaskView *) (((char *) (&g_optionsTransitionActorKinds)) + offset))->value;
                if ((table_kind == actor_kind) || (table_kind == wildcard)) {
                    return (*(Handler802A2B50 *)entry)(object, event, eventData, eventValue, eventContext);
                }
            }
            entry += 0xC;
            offset += 0xC;
        } while (*(Handler802A2B50 *)entry != 0);
    }
    return 0;
}

#if defined(VERSION_EU)
unsigned int func_804229DC_eu_padding_1989DC[1] = {
    0x02331021,
};
#endif

#if defined(VERSION_DE)
unsigned int func_804224DC_de_padding_1884DC[1] = {
    0x0C0978B5,
};
#endif
