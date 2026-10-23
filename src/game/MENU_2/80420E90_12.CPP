#include "include_asm.h"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/NUMBERPADSCREEN.H"
#include "TYPES.H"
#include "MENU_2/80420E90_12.H"

/* Dispatches event arg1 through this file's 12-byte handler table, whose rows hold an event at D_800E4404, an actor kind at D_800E4408 and a handler at D_800E440C: the first row whose event equals arg1 and whose kind equals the actor's halfword kind at 0xC, or is the wildcard 0x7530, receives all five arguments and its result is returned; with no such row, or an empty table, the result is zero. Adapted from func_802A1B50_de. */



extern s32 D_800E4404;
extern s32 D_800E4408;
extern Handler802A2B50 D_800E440C;

s32 func_80421A58_de(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    char *entry;
    s32 offset;
    s32 wildcard;
    s32 actor_kind;
    s32 table_kind;

    if (D_800E440C != 0) {
        wildcard = 0x7530;
        entry = (char *)&D_800E440C;
        offset = 0;
        do {
            if (((struct Shape_typemap_3 *) (((char *) (&D_800E4404)) + offset))->field_0 == arg1) {
                actor_kind = ((struct ObjRecAtCV1 *) ((char *) arg0))->unkC;
                table_kind = ((struct Shape_typemap_3 *) (((char *) (&D_800E4408)) + offset))->field_0;
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
