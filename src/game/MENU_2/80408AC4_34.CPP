#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/CHEATCODE.H"
#include "TYPES.H"
#include "MENU_2/80408AC4_34.H"

#if defined(VERSION_DE)
#if defined(VERSION_DE)
/* Dispatches event arg1 through this file's 12-byte handler table, whose rows hold an event at D_800E1738, an actor kind at D_800E173C and a handler at D_800F1DB0_de: the first row whose event equals arg1 and whose kind equals the actor's halfword kind at 0xC, or is the wildcard 0x7530, receives all five arguments and its result is returned; with no such row, or an empty table, the result is zero. Adapted from N64Eng_DispatchNumericWidgetEvent. */
#else
/* Dispatches event arg1 through this file's 12-byte handler table, whose rows hold an event at D_800F1DA8, an actor kind at D_800F1DAC and a handler at D_800F1DB0_de: the first row whose event equals arg1 and whose kind equals the actor's halfword kind at 0xC, or is the wildcard 0x7530, receives all five arguments and its result is returned; with no such row, or an empty table, the result is zero. Adapted from N64Eng_DispatchNumericWidgetEvent. */
#endif




#if defined(VERSION_DE)
extern FieldRow D_800E1738[];
#else
extern FieldRow D_800F1DA8[];
#endif
#if defined(VERSION_DE)
extern FieldRow D_800E173C[];
#else
extern FieldRow D_800F1DAC[];
#endif
extern Handler80437868 D_800F1DB0_de;




s32 func_80437688_de(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    Handler80437868 *entry;
    ObjRecAtCV1 *actor;
    s32 index;
    s32 wildcard;
    s32 actor_kind;
    s32 table_kind;

    if (D_800F1DB0_de != 0) {
        wildcard = 0x7530;
        entry = &D_800F1DB0_de;
        index = 0;
        do {
#if defined(VERSION_DE)
            if (D_800E1738[index].value == arg1) {
#else
            if (D_800F1DA8[index].value == arg1) {
#endif
                actor = arg0;
                actor_kind = actor->unkC;
#if defined(VERSION_DE)
                table_kind = D_800E173C[index].value;
#else
                table_kind = D_800F1DAC[index].value;
#endif
                if ((table_kind == actor_kind) || (table_kind == wildcard)) {
                    return (*entry)(arg0, arg1, arg2, arg3, arg4);
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
