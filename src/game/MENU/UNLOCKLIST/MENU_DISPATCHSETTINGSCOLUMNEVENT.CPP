#include "COMMON/MENULISTSCREEN.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/CHEATCODE.H"
#include "TYPES.H"
#include "MENU/MENU_DISPATCHSETTINGSCOLUMNEVENT.H"

#if defined(VERSION_DE)
#if defined(VERSION_DE)
/* Dispatches event arg1 through this file's 12-byte handler table, whose rows hold an event at g_settingsColumnEventIds, an actor kind at g_settingsColumnEventKinds and a handler at g_settingsColumnEventHandlers: the first row whose event equals arg1 and whose kind equals the actor's halfword kind at 0xC, or is the wildcard 0x7530, receives all five arguments and its result is returned; with no such row, or an empty table, the result is zero. Adapted from N64Eng_DispatchNumericWidgetEvent. */
#else
/* Dispatches event arg1 through this file's 12-byte handler table, whose rows hold an event at g_scrollingChoiceEventIds, an actor kind at g_scrollingChoiceEventKinds and a handler at g_settingsColumnEventHandlers: the first row whose event equals arg1 and whose kind equals the actor's halfword kind at 0xC, or is the wildcard 0x7530, receives all five arguments and its result is returned; with no such row, or an empty table, the result is zero. Adapted from N64Eng_DispatchNumericWidgetEvent. */
#endif




#if defined(VERSION_DE)
extern FieldRow g_settingsColumnEventIds[];
#else
#endif
#if defined(VERSION_DE)
extern FieldRow g_settingsColumnEventKinds[];
#else
#endif
extern Handler80437868 g_settingsColumnEventHandlers;




s32 Menu_DispatchSettingsColumnEvent(void *eventObject, s32 eventId, s32 eventPayload, s32 eventValue, s32 eventExtra) {
    Handler80437868 *entry;
    MenuActorInputView *actor;
    s32 index;
    s32 wildcard;
    s32 actor_kind;
    s32 table_kind;

    if (g_settingsColumnEventHandlers != 0) {
        wildcard = 0x7530;
        entry = &g_settingsColumnEventHandlers;
        index = 0;
        do {
#if defined(VERSION_DE)
            if (g_settingsColumnEventIds[index].value == eventId) {
#else
            if (g_scrollingChoiceEventIds[index].value == eventId) {
#endif
                actor = eventObject;
                actor_kind = actor->input;
#if defined(VERSION_DE)
                table_kind = g_settingsColumnEventKinds[index].value;
#else
                table_kind = g_scrollingChoiceEventKinds[index].value;
#endif
                if ((table_kind == actor_kind) || (table_kind == wildcard)) {
                    return (*entry)(eventObject, eventId, eventPayload, eventValue, eventExtra);
                }
            }
            entry += 3;
            index++;
        /* FAKEMATCH: retain the original 12-byte handler-column scan and dispatch order. */
        } while (*entry != 0);
    }
    return 0;
}
#endif
