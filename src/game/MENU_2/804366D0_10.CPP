#include "COMMON/MENULISTSCREEN.H"
#include "COMMON/CHEATCODE.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/TRIPLE.H"
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"

#if !(defined(VERSION_DE) || defined(VERSION_EU_X))
/* Dispatches event arg1 through this file's 12-byte handler table, whose rows hold an event at D_800F1DA8, an actor kind at D_800F1DAC and a handler at D_800F1DB0: the first row whose event equals arg1 and whose kind equals the actor's halfword kind at 0xC, or is the wildcard 0x7530, receives all five arguments and its result is returned; with no such row, or an empty table, the result is zero. Adapted from N64Eng_DispatchNumericWidgetEvent. */







struct ObjRecAtCV1;

s32 func_804384B8_eu(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    Handler80437868 *entry;
    s32 index;
    s32 wildcard;
    s32 actor_kind;
    s32 table_kind;
    ObjRecAtCV1 *actor;

    if (D_800F1DB0 != 0) {
        wildcard = 0x7530;
        entry = &D_800F1DB0;
        index = 0;
        do {
            if (D_800F1DA8[index].value == arg1) {
                actor = arg0;
                actor_kind = actor->unkC;
                table_kind = D_800F1DAC[index].value;
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
#endif
