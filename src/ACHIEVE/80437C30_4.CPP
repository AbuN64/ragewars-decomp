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

/* Calls func_8029973C_de with the arguments it was given and returns zero. */
extern void func_8029973C_de();

s32 func_80438E5C_de(void) {
    func_8029973C_de();
    return 0;
}

/* Dispatches event arg1 through this file's 12-byte handler table, whose rows hold an event at D_800E5834, an actor kind at D_800E5838 and a handler at D_800E583C: the first row whose event equals arg1 and whose kind equals the actor's halfword kind at 0xC, or is the wildcard 0x7530, receives all five arguments and its result is returned; with no such row, or an empty table, the result is zero. Adapted from func_802A1B50_de. */

typedef s32 (*Handler8043905C)(void *, s32, s32, s32, s32);


extern Handler8043905C D_800E583C;




s32 func_80438E7C_de(ActorDefinitionHeader *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
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
            if (D_800E5834[index].value == arg1) {
                actor_kind = arg0->character;
                table_kind = D_800E5838[index].value;
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

#if defined(VERSION_US)
INCLUDE_DATA("ovl_80400000", func_80438F0C_de_padding_19D0EC);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("ovl_80400000", func_80438F0C_de_padding_19EF0C);
#endif
