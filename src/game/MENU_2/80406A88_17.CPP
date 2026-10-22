#include "include_asm.h"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/S1_5.H"
#include "TYPES.H"
#include "MENU_2/EXTERNS.H"

#if defined(VERSION_EU_X)
/* Dispatches event arg1 through this file's 12-byte handler table, whose rows hold an event at D_800E57DC, an actor kind at D_800E57E0 and a handler at D_800E57E4: the first row whose event equals arg1 and whose kind equals the actor's halfword kind at 0xC, or is the wildcard 0x7530, receives all five arguments and its result is returned; with no such row, or an empty table, the result is zero. Adapted from func_8042244C_de. */




s32 func_80438918_eu_x(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    char *entry;
    s32 offset;
    s32 wildcard;
    s32 actor_kind;
    s32 table_kind;

    if (D_800E57E4 != 0) {
        wildcard = 0x7530;
        entry = (char *)&D_800E57E4;
        offset = 0;
        do {
            if (((struct Shape_typemap_3 *) (((char *) (&D_800E57DC)) + offset))->field_0 == arg1) {
                actor_kind = ((struct ObjRecAtCV1 *) ((char *) arg0))->unkC;
                table_kind = ((struct Shape_typemap_3 *) (((char *) (&D_800E57E0)) + offset))->field_0;
                if ((table_kind == actor_kind) || (table_kind == wildcard)) {
                    return (*(Handler802A2B50 *)entry)(arg0, arg1, arg2, arg3, arg4);
                }
            }
            entry += 0xC;
            offset += 0xC;
        } while (*(Handler802A2B50 *)entry != 0);
    }
    return 0;
}
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("ovl_80400000", func_804389A8_eu_x_padding_1289A8);
#endif
