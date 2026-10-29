#include "include_asm.h"
#include "COMMON/RUNTIME_DECLARATIONS.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/NUMBERPADSCREEN.H"
#include "TYPES.H"
#include "MENU/MENU_DISPATCHEXTRAOPTIONSEVENT.H"

/* Dispatches event event through this file's 12-byte handler table, whose rows hold an event at g_extraOptionsEventCodes, an actor kind at g_extraOptionsActorKinds and a handler at g_extraOptionsEventCallbacks: the first row whose event equals event and whose kind equals the actor's halfword kind at 0xC, or is the wildcard 0x7530, receives all five arguments and its result is returned; with no such row, or an empty table, the result is zero. Adapted from N64Eng_DispatchNumericWidgetEvent. */




s32 Menu_DispatchExtraOptionsEvent(void *object, s32 event, s32 eventData, s32 eventValue, s32 eventContext) {
    char *entry;
    s32 offset;
    s32 wildcard;
    s32 actor_kind;
    s32 table_kind;

    if (g_extraOptionsEventCallbacks != 0) {
        wildcard = 30000;
        entry = (char *)&g_extraOptionsEventCallbacks;
        offset = 0;
        do {
            if (((struct AnimationEventMaskView *) (((char *) (&g_extraOptionsEventCodes)) + offset))->value == event) {
                actor_kind = ((struct MenuActorInputView *) ((char *) object))->input;
                table_kind = ((struct AnimationEventMaskView *) (((char *) (&g_extraOptionsActorKinds)) + offset))->value;
                if ((table_kind == actor_kind) || (table_kind == wildcard)) {
                    return (*(WidgetEventHandler *)entry)(object, event, eventData, eventValue, eventContext);
                }
            }
            entry += 0xC;
            offset += 12;
        } while (*(WidgetEventHandler *)entry != 0);
    }
    return 0;
}

#if defined(VERSION_EU_X)
#if defined(VERSION_EU_X)
unsigned short func_80421AE8_de_padding_111FE8[4] = {
    0xA050, 0x0010, 0x0240, 0x2021,
};
#endif
#endif

#if defined(VERSION_DE)
unsigned int func_80421AE8_de_padding_187AE8[2] = {
    0x8C6303F0, 0x00402021,
};
#endif
