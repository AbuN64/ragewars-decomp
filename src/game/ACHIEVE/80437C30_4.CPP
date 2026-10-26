#include "include_asm.h"
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#include "COMMON/INTEGERSTATEB0.H"
#include "COMMON/MENULISTSCREEN.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/UNUSED.H"
#include "COMMON/MULTIPLAYEROPTIONS.H"
#include "COMMON/MENUSELECTIONMESSAGE.H"
#include "TYPES.H"
#include "ACHIEVE/80437C30_4.H"

/* Calls MarkMenuEventHandled with the arguments it was given and returns zero. */
extern void MarkMenuEventHandled();

s32 func_80438E5C_de(void) {
    MarkMenuEventHandled();
    return 0;
}

/* Dispatches event arg1 through this file's 12-byte handler table, whose rows hold an event at D_800E5834, an actor kind at D_800E5838 and a handler at D_800E583C: the first row whose event equals arg1 and whose kind equals the actor's halfword kind at 0xC, or is the wildcard 0x7530, receives all five arguments and its result is returned; with no such row, or an empty table, the result is zero. Adapted from N64Eng_DispatchNumericWidgetEvent. */

typedef s32 (*Handler8043905C)(void *, s32, s32, s32, s32);


extern Handler8043905C D_800E583C;




s32 func_80438E7C_de(ActorDefinitionHeader *actor, s32 event, s32 arg2, s32 arg3, s32 arg4) {
    Handler8043905C *entry;
    s32 index;
    s32 wildcard;
    s32 actor_kind;
    s32 table_kind;

    if (D_800E583C != 0) {
        wildcard = 0x7530;
        entry = &D_800E583C;
        index = 0;
        do {
            if (D_800E5834[index].value == event) {
                actor_kind = actor->character;
                table_kind = D_800E5838[index].value;
                if ((table_kind == actor_kind) || (table_kind == wildcard)) {
                    return (*entry)(actor, event, arg2, arg3, arg4);
                }
            }
            entry += 3;
            index++;
        } while (*entry != 0);
    }
    return 0;
}

#if defined(VERSION_US)
unsigned int s_nterText[1] = {
    0x6E746572,
};
#endif

#if defined(VERSION_DE)
unsigned int func_80438F0C_de_padding_19EF0C[1] = {
    0x0C106960,
};
#endif
