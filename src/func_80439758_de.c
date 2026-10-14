#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "span_16E000/code_8043962C.h"
#include "types.h"
#include "common/unused.h"








/* Dispatches event arg1 through this file's 12-byte handler table, whose rows hold an event at D_800E5954, an actor kind at D_800E5958 and a handler at D_800E595C: the first row whose event equals arg1 and whose kind equals the actor's halfword kind at 0xC, or is the wildcard 0x7530, receives all five arguments and its result is returned; with no such row, or an empty table, the result is zero. Adapted from func_802A1B50_de. */


s32 func_80439758_de(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    char *entry;
    s32 index;
    s32 wildcard;
    s32 actor_kind;
    s32 table_kind;

    if (D_800E595C != 0) {
        wildcard = 0x7530;
        entry = (char *)&D_800E595C;
        index = 0;
        do {
#if defined(VERSION_EU)
            if (D_800F1F74[index].value == arg1) {
#else
            if (D_800E5954[index].value == arg1) {
#endif
                actor_kind = ((Shared_Body *)(arg0))->kind;
                table_kind = D_800E5958[index].value;
                if ((table_kind == actor_kind) || (table_kind == wildcard)) {
                    return (*(MenuEventHandler *)entry)(arg0, arg1, arg2, arg3, arg4);
                }
            }
            entry += 0xC;
            index++;
        } while (*(MenuEventHandler *)entry != 0);
    }
    return 0;
}
