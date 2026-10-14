#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "common/types_8fd754e1e915.h"
#include "span_16E000/code_8041DF04.h"
#include "types.h"

/* Calls func_8029973C_de with the arguments it was given and returns zero. */
extern void func_8029973C_de();

s32 func_8041DE94_de(void) {
    func_8029973C_de();
    return 0;
}

/* Dispatches event arg1 through this file's 12-byte handler table, whose rows hold an event at D_800E3724, an actor kind at D_800E3728 and a handler at D_800E372C: the first row whose event equals arg1 and whose kind equals the actor's halfword kind at 0xC, or is the wildcard 0x7530, receives all five arguments and its result is returned; with no such row, or an empty table, the result is zero. Adapted from func_802A1B50_de. */



extern s32 D_800E3724;
extern s32 D_800E3728;
extern Handler802A2B50 D_800E372C;

s32 func_8041DEB4_de(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    char *entry;
    s32 offset;
    s32 wildcard;
    s32 actor_kind;
    s32 table_kind;

    if (D_800E372C != 0) {
        wildcard = 0x7530;
        entry = (char *)&D_800E372C;
        offset = 0;
        do {
            if (((struct Shape_typemap_3 *) (((char *) (&D_800E3724)) + offset))->field_0 == arg1) {
                actor_kind = ((struct ObjRecAtCV1 *) ((char *) arg0))->unkC;
                table_kind = ((struct Shape_typemap_3 *) (((char *) (&D_800E3728)) + offset))->field_0;
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
