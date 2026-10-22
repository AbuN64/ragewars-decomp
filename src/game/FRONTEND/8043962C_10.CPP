#include "include_asm.h"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/OBJECTRECAT28.H"
#include "TYPES.H"
#include "FRONTEND/8043962C_10.H"

/* Dispatches event arg1 through this file's 12-byte handler table, whose rows hold an event at D_800E58FC, an actor kind at D_800E5900 and a handler at D_800E5904: the first row whose event equals arg1 and whose kind equals the actor's halfword kind at 0xC, or is the wildcard 0x7530, receives all five arguments and its result is returned; with no such row, or an empty table, the result is zero. Adapted from func_802A1B50_de. */

typedef s32 (*Handler8043962C)(void *, s32, s32, s32, s32);


extern FieldRow D_800E58FC[];
extern FieldRow D_800E5900[];
extern Handler8043962C D_800E5904;




s32 func_8043944C_de(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    Handler8043962C *entry;
    s32 index;
    s32 wildcard;
    s32 actor_kind;
    s32 table_kind;
    ObjRecAtCV1 *actor;

    if (D_800E5904 != 0) {
        wildcard = 0x7530;
        entry = &D_800E5904;
        index = 0;
        do {
            if (D_800E58FC[index].value == arg1) {
                actor = arg0;
                actor_kind = actor->unkC;
                table_kind = D_800E5900[index].value;
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

#if defined(VERSION_EU_X)
INCLUDE_DATA("ovl_80400000", func_8043A4DC_eu_x_padding_12A4DC);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("ovl_80400000", func_804394DC_de_padding_19F4DC);
#endif
