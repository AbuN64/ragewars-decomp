#include "FRONTEND/OPTIONS.H"
#include "COMMON/AIPROFILE.H"
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"

#if defined(VERSION_US) || defined(VERSION_US_REV1)
/* Dispatches event arg1 through this file's 12-byte handler table, whose rows hold an event at D_800E4EC0, an actor kind at D_800E4EC4 and a handler at D_800E4EC8: the first row whose event equals arg1 and whose kind equals the actor's halfword kind at 0xC, or is the wildcard 0x7530, receives all five arguments and its result is returned; with no such row, or an empty table, the result is zero. Adapted from func_802A1B50_de. */

typedef s32 (*Handler8042931C)(void *, s32, s32, s32, s32);

extern FieldRow D_800E4EC0[];
extern FieldRow D_800E4EC4[];
extern Handler8042931C D_800E4EC8;


struct ObjRecAtCV1;

s32 func_8042931C_us_rev1(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    Handler8042931C *entry;
    s32 index;
    s32 wildcard;
    s32 actor_kind;
    s32 table_kind;
    ObjRecAtCV1 *actor;

    if (D_800E4EC8 != 0) {
        wildcard = 0x7530;
        entry = &D_800E4EC8;
        index = 0;
        do {
            if (D_800E4EC0[index].value == arg1) {
                actor = arg0;
                actor_kind = actor->unkC;
                table_kind = D_800E4EC4[index].value;
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
